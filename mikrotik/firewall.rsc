# remove all firewall rules
/ip firewall filter remove [/ip firewall filter find where !dynamic]
/ip firewall nat remove [/ip firewall nat find where !dynamic]
/ip firewall mangle remove [/ip firewall mangle find where !dynamic]
/ip firewall raw remove [/ip firewall raw find where !dynamic]

# remove all address rules
/ip firewall address-list remove [/ip firewall address-list find]

# iptable nat table
/ip firewall nat add chain=srcnat out-interface-list=WAN ipsec-policy=out,none action=masquerade comment="defconf: masquerade"

# iptable filter table
/ip firewall filter {
	# input 
	add chain=input action=accept comment="defconf: accept ICMP after RAW" protocol=icmp
	add chain=input action=accept connection-state=established,related,untracked comment="defconf: accept established,related,untracked"
	add chain=input action=drop connection-state=invalid comment="defconf: drop invalid"
	add chain=input action=accept dst-address=127.0.0.1 comment="defconf: accept to local loopback (for CAPsMAN)"
	add chain=input action=jump jump-target=input_rule comment="jump input_rule" disabled=yes
	add chain=input action=jump in-interface-list=LAN jump-target=zone_lan_input comment="jump zone_lan_input"
	add chain=input action=jump in-interface-list=WAN jump-target=zone_wan_input comment="jump zone_wan_input"
	add chain=input action=drop comment="default drop input" log-prefix="default drop input"

	# zone_lan_input
	add action=jump chain=zone_lan_input jump-target=input_lan_rule comment="jump input_lan_rule" disabled=yes
	add action=jump chain=zone_lan_input jump-target=lan_service_broadcast comment="jump lan_service_broadcast" dst-address-type=broadcast
	add action=jump chain=zone_lan_input jump-target=lan_service_multicast comment="jump lan_service_multicast" dst-address-type=multicast
	add action=jump chain=zone_lan_input jump-target=lan_service_tcp comment="jump lan_service_tcp" protocol=tcp dst-address-type=local
	add action=jump chain=zone_lan_input jump-target=lan_service_udp comment="jump lan_service_udp" protocol=udp dst-address-type=local
	add action=accept chain=zone_lan_input comment="allow LAN IGMP" protocol=igmp
	add action=drop chain=zone_lan_input comment="drop LAN input" log=yes

	# zone_wan_input
	add action=jump chain=zone_wan_input jump-target=input_wan_rule comment="jump input_wan_rule" disabled=yes
	add action=jump chain=zone_wan_input jump-target=wan_service_broadcast comment="jump wan_service_broadcast" dst-address-type=broadcast
	add action=jump chain=zone_wan_input jump-target=wan_service_multicast comment="jump wan_service_multicast" dst-address-type=multicast
	add action=jump chain=zone_wan_input jump-target=wan_service_tcp comment="jump wan_service_tcp" protocol=tcp dst-address-type=local
	add action=jump chain=zone_wan_input jump-target=wan_service_udp comment="jump wan_service_udp" protocol=udp dst-address-type=local
	add action=jump chain=zone_wan_input jump-target=wan_protocol comment="jump wan_protocol" dst-address-type=local
	add action=drop chain=zone_wan_input comment="drop WAN input" log=yes
}

/ip firewall filter {
	# output 
	add chain=output action=accept connection-state=established,related,untracked comment="defconf: accept established,related,untracked"
	add chain=output action=accept dst-address=127.0.0.1 comment="defconf: accept to local loopback"
	add chain=output action=jump jump-target=output_rule comment="jump output_rule" disabled=yes
	add chain=output action=jump out-interface-list=LAN jump-target=zone_lan_output comment="jump zone_lan_output"
	add chain=output action=jump out-interface-list=WAN jump-target=zone_wan_output comment="jump zone_wan_output"
	add chain=output action=drop comment="default drop output" log-prefix="default drop output"

	# zone_lan_output
	add action=jump chain=zone_lan_output jump-target=output_lan_rule comment="jump output_lan_rule"
	add action=accept chain=zone_lan_output comment="accept output LAN"

	# zone_wan_output
	add action=jump chain=zone_wan_output jump-target=output_wan_rule comment="jump output_wan_rule"
	add action=accept chain=zone_wan_output comment="accept output WAN"
}

/ip firewall filter {
	# forward 
	add chain=forward action=accept ipsec-policy=in,ipsec comment="defconf: accept in ipsec policy"
	add chain=forward action=accept ipsec-policy=out,ipsec comment="defconf: accept out ipsec policy"
	add chain=forward action=fasttrack-connection connection-state=established,related comment="defconf: fasttrack"
	add chain=forward action=accept connection-state=established,related,untracked comment="defconf: accept established,related,untracked"
	add chain=forward action=drop connection-state=invalid comment="defconf: drop invalid"
	add chain=forward action=drop src-address-list=no_forward_ipv4 comment="defconf: drop bad src forward IPs"
	add chain=forward action=drop dst-address-list=no_forward_ipv4 comment="defconf: drop bad dst forward IPs"
	add chain=forward action=jump jump-target=forward_rule comment="jump forward_rule" disabled=yes
	add chain=forward action=jump in-interface-list=LAN jump-target=zone_lan_forward comment="jump zone_lan_forward"
	add chain=forward action=jump in-interface-list=WAN jump-target=zone_wan_forward comment="jump zone_wan_forward"
	add chain=forward action=drop comment="default drop forward" log-prefix="default drop"

	# zone_lan_forward
	add action=jump chain=zone_lan_forward jump-target=forward_lan_rule comment="jump forward_lan_rule" disabled=yes
	add action=accept chain=zone_lan_forward out-interface-list=WAN comment="accept LAN forward to WAN"
	add action=accept chain=zone_lan_forward connection-nat-state=dstnat comment="accept port forwards"
	add action=drop chain=zone_lan_forward out-interface-list=LAN comment="drop LAN forward to LAN"
	add action=drop chain=zone_lan_forward comment="drop LAN forward" log=yes

	# zone_wan_forward
	add action=jump chain=zone_wan_forward jump-target=forward_wan_rule comment="jump forward_wan_rule" disabled=yes
	add action=drop chain=zone_wan_forward out-interface-list=WAN comment="drop WAN forward to WAN"
	add action=accept chain=zone_wan_forward connection-nat-state=dstnat comment="accept port forwards"
	add action=drop chain=zone_wan_forward out-interface-list=LAN comment="drop WAN forward to LAN"
	add action=drop chain=zone_wan_forward comment="drop WAN forward"
}

/ip firewall filter {
add action=accept chain="lan_service_broadcast" comment="DHCP Server" src-port=68 dst-port=67 protocol=udp
add action=drop chain="lan_service_broadcast" comment="NetBIOS Name Service" dst-port=137 protocol=udp
add action=drop chain="lan_service_broadcast" comment="NetBIOS Datagram Service" dst-port=138 protocol=udp
add action=accept chain="lan_service_broadcast" comment="MNDP" dst-port=5678 protocol=udp
add action=accept chain="lan_service_broadcast" comment="MAC Winbox" dst-port=20561 protocol=udp
add action=drop chain="lan_service_broadcast" comment="spotify p2p" dst-port=57621 protocol=udp
add action=drop chain="lan_service_broadcast" comment="drop lan broadcast" log=yes
}

/ip firewall filter {
add action=accept chain="lan_service_multicast" comment="SSDP" dst-address=239.255.255.250 dst-port=1900 protocol=udp disabled=no
add action=drop chain="lan_service_multicast" comment="WS-Discovery" dst-address=239.255.255.250 dst-port=3702 protocol=udp
add action=drop chain="lan_service_multicast" comment="mDNS" dst-address=224.0.0.251 dst-port=5353 protocol=udp
add action=drop chain="lan_service_multicast" comment="drop lan multicast" log=yes
}

/ip firewall filter {
add action=accept chain="lan_service_tcp" comment="ftp data" dst-port=20 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="ftp control" dst-port=21 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="ssh" dst-port=22 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="telnet" dst-port=23 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="dns" dst-port=53 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="http" dst-port=80 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="BGP" dst-port=179 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="https" dst-port=443 protocol=tcp disabled=yes
add action=accept chain="lan_service_tcp" comment="SMB" dst-port=445 protocol=tcp disabled=yes
add action=accept chain="lan_service_tcp" comment="LDP transport" dst-port=646 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="SOCKS proxy" dst-port=1080 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="PPTP" dst-port=1723 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="MME gateway" dst-port=1966 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="bandwidth test" dst-port=2000 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="uPnP" dst-port=2828 protocol=tcp disabled=yes
add action=accept chain="lan_service_tcp" comment="OpenFlow" dst-port=6343 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="http proxy" dst-port=8080 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="winbox" dst-port=8291 protocol=tcp
add action=accept chain="lan_service_tcp" comment="api" dst-port=8728 protocol=tcp disabled=yes 
add action=accept chain="lan_service_tcp" comment="api-ssl" dst-port=8729 protocol=tcp disabled=yes 
add action=drop chain="lan_service_tcp" comment="drop lan tcp" log=yes
}

/ip firewall filter {
add action=accept chain="lan_service_udp" comment="DNS" dst-port=53 protocol=udp
add action=accept chain="lan_service_udp" comment="DHCP Server" src-port=68 dst-port=67 protocol=udp
add action=accept chain="lan_service_udp" comment="DHCP Client" src-port=67 dst-port=68 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="TFTP" dst-port=69 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="NTP" dst-port=123 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="SNMP" dst-port=161 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="IKE" dst-port=500 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="RIP" dst-port=520,521 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="LDP Hello" dst-port=646 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="RSVP TE" dst-port=1698,1699 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="L2TP" dst-port=1701 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="MME" dst-port=1966 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="bandwidth test" dst-port=2000-3000 protocol=udp disabled=yes
add action=accept chain="lan_service_udp" comment="CAPsMAN" dst-port=5246,5247 protocol=udp disabled=yes
add action=drop chain="lan_service_udp" comment="drop lan udp" log=yes
}

/ip firewall filter {
add action=drop chain="wan_service_broadcast" comment="drop DHCP discover" src-port=68 dst-port=67 protocol=udp
add action=accept chain="wan_service_broadcast" comment="allow DHCP renew" src-port=67 dst-port=68 protocol=udp
add action=drop chain="wan_service_broadcast" comment="drop NetBIOS Name Service" dst-port=137 protocol=udp
add action=drop chain="wan_service_broadcast" comment="drop NetBIOS Datagram Service" dst-port=138 protocol=udp
add action=drop chain="wan_service_broadcast" comment="drop MNDP" dst-port=5678 protocol=udp
add action=drop chain="wan_service_broadcast" comment="drop spotify p2p" dst-port=57621 protocol=udp
add action=drop chain="wan_service_broadcast" comment="drop broadcast" log=yes
}

/ip firewall filter {
add action=accept chain="wan_service_multicast" protocol=igmp dst-address=224.0.0.1 comment="all hosts"
add action=drop chain="wan_service_multicast" comment="drop multicast" log=yes
}

/ip firewall filter {
add action=accept chain="wan_service_udp" comment="DHCP renew" src-port=67 dst-port=68 protocol=udp
add action=accept chain="wan_service_udp" comment="WireGuard" src-port=13231 dst-port=13231 protocol=udp disabled=yes
add action=drop chain="wan_service_udp" comment="drop udp" log=yes
}

/ip firewall filter {
add action=accept chain="wan_protocol" comment="allow IGMP" protocol=igmp
add action=accept chain="wan_protocol" comment="allow IPIP" protocol=ip-encap
add action=accept chain="wan_protocol" comment="allow GRE" protocol=gre disabled=yes
add action=accept chain="wan_protocol" comment="allow IPSEC ESP" protocol=ipsec-esp disabled=yes
add action=drop chain="wan_protocol" comment="drop other protocol" log=yes
}

/ip firewall filter {
add action=return chain="service_status" comment=\
    "\"All hosts on this subnet\" Broadcast" src-address=224.0.0.1
add action=return chain="service_status" comment=\
    "\"All routers on this subnet\" Broadcast" src-address=224.0.0.2
add action=return chain="service_status" comment=\
    "DVMRP (Distance Vector Multicast Routing Protocol)" src-address=\
    224.0.0.4
add action=return chain="service_status" comment=\
    "OSPF - All OSPF Routers Broadcast" src-address=224.0.0.5
add action=return chain="service_status" comment=\
    "OSPF - OSPF DR Routers Broadcast" src-address=224.0.0.6
add action=return chain="service_status" comment="RIP Broadcast" \
    src-address=224.0.0.9
add action=return chain="service_status" comment="EIGRP Broadcast" \
    src-address=224.0.0.10
add action=return chain="service_status" comment="PIM Broadcast" \
    src-address=224.0.0.13
add action=return chain="service_status" comment="VRRP Broadcast" \
    src-address=224.0.0.18
add action=return chain="service_status" comment="IS-IS Broadcast" \
    src-address=224.0.0.19
add action=return chain="service_status" comment="IS-IS Broadcast" \
    src-address=224.0.0.20
add action=return chain="service_status" comment="IS-IS Broadcast" \
    src-address=224.0.0.21
add action=return chain="service_status" comment="IGMP Broadcast" \
    src-address=224.0.0.22

add action=return chain="service_status" comment=\
    "GRE Protocol (Local Management)" protocol=gre
add action=return chain="service_status" comment="FTPdata transfer" \
    port=20 protocol=tcp
add action=return chain="service_status" comment="FTPdata transfer  " \
    port=20 protocol=udp
add action=return chain="service_status" comment="FTPcontrol (command)" \
    port=21 protocol=tcp
add action=return chain="service_status" comment="Secure Shell(SSH)" \
    port=22 protocol=tcp
add action=return chain="service_status" comment="Secure Shell(SSH)   " \
    port=22 protocol=udp
add action=return chain="service_status" comment=Telnet port=23 \
    protocol=tcp
add action=return chain="service_status" comment=Telnet port=23 \
    protocol=udp
add action=return chain="service_status" comment=\
    "Priv-mail: any privatemailsystem." port=24 protocol=tcp
add action=return chain="service_status" comment=\
    "Priv-mail: any privatemailsystem.  " port=24 protocol=udp
add action=return chain="service_status" comment=\
    "Simple Mail Transfer Protocol(SMTP)" port=25 protocol=tcp
add action=return chain="service_status" comment=\
    "Simple Mail Transfer Protocol(SMTP)  " port=25 protocol=udp
add action=return chain="service_status" comment="TIME protocol" port=37 \
    protocol=tcp
add action=return chain="service_status" comment="TIME protocol  " port=\
    37 protocol=udp
add action=return chain="service_status" comment=\
    "ARPA Host Name Server Protocol & WINS" port=42 protocol=tcp
add action=return chain="service_status" comment=\
    "ARPA Host Name Server Protocol  & WINS  " port=42 protocol=udp
add action=return chain="service_status" comment="WHOIS protocol" port=\
    43 protocol=tcp
add action=return chain="service_status" comment="WHOIS protocol" port=\
    43 protocol=udp
add action=return chain="service_status" comment=\
    "Domain Name System (DNS)" port=53 protocol=tcp
add action=return chain="service_status" comment=\
    "Domain Name System (DNS)" port=53 protocol=udp
add action=return chain="service_status" comment=\
    "Mail Transfer Protocol(RFC 780)" port=57 protocol=tcp
add action=return chain="service_status" comment=\
    "(BOOTP) Server & (DHCP)  " port=67 protocol=udp
add action=return chain="service_status" comment=\
    "(BOOTP) Client & (DHCP)  " port=68 protocol=udp
add action=return chain="service_status" comment=\
    "Trivial File Transfer Protocol (TFTP)  " port=69 protocol=udp
add action=return chain="service_status" comment="Gopher protocol" port=\
    70 protocol=tcp
add action=return chain="service_status" comment="Finger protocol" port=\
    79 protocol=tcp
add action=return chain="service_status" comment=\
    "Hypertext Transfer Protocol (HTTP)" port=80 protocol=tcp
add action=return chain="service_status" comment=\
    "RemoteTELNETService protocol" port=107 protocol=tcp
add action=return chain="service_status" comment=\
    "Post Office Protocolv2 (POP2)" port=109 protocol=tcp
add action=return chain="service_status" comment=\
    "Post Office Protocolv3 (POP3)" port=110 protocol=tcp
add action=return chain="service_status" comment=\
    "IdentAuthentication Service/Identification Protocol" port=113 protocol=\
    tcp
add action=return chain="service_status" comment=\
    "Authentication Service (auth)  " port=113 protocol=udp
add action=return chain="service_status" comment=\
    "Simple File Transfer Protocol (SFTP)" port=115 protocol=tcp
add action=return chain="service_status" comment=\
    "Network Time Protocol(NTP)" port=123 protocol=udp
add action=return chain="service_status" comment=\
    "NetBIOS Name Service" port=137 protocol=tcp
add action=return chain="service_status" comment=\
    "NetBIOS Name Service  " port=137 protocol=udp
add action=return chain="service_status" comment=\
    "NetBIOS Datagram Service" port=138 protocol=tcp
add action=return chain="service_status" comment=\
    "NetBIOS Datagram Service  " port=138 protocol=udp
add action=return chain="service_status" comment=\
    "NetBIOS Session Service" port=139 protocol=tcp
add action=return chain="service_status" comment=\
    "NetBIOS Session Service  " port=139 protocol=udp
add action=return chain="service_status" comment=\
    "Internet Message Access Protocol (IMAP)" port=143 protocol=tcp
add action=return chain="service_status" comment=\
    "Background File Transfer Program (BFTP)" port=152 protocol=tcp
add action=return chain="service_status" comment=\
    "Background File Transfer Program (BFTP)  " port=152 protocol=udp
add action=return chain="service_status" comment=\
    "SGMP,Simple Gateway Monitoring Protocol" port=153 protocol=tcp
add action=return chain="service_status" comment=\
    "SGMP,Simple Gateway Monitoring Protocol  " port=153 protocol=udp
add action=return chain="service_status" comment=\
    "DMSP, Distributed Mail Service Protocol" port=158 protocol=tcp
add action=return chain="service_status" comment=\
    "DMSP, Distributed Mail Service Protocol  " port=158 protocol=udp
add action=return chain="service_status" comment=\
    "Simple Network Management Protocol(SNMP)  " port=161 protocol=udp
add action=return chain="service_status" comment=\
    "Simple Network Management ProtocolTrap (SNMPTRAP)" port=162 protocol=tcp
add action=return chain="service_status" comment=\
    "Simple Network Management ProtocolTrap (SNMPTRAP)  " port=162 protocol=\
    udp
add action=return chain="service_status" comment=\
    "BGP (Border Gateway Protocol)" port=179 protocol=tcp
add action=return chain="service_status" comment=\
    "Internet Message Access Protocol (IMAP), version 3" port=220 protocol=\
    tcp
add action=return chain="service_status" comment=\
    "Internet Message Access Protocol (IMAP), version 3" port=220 protocol=\
    udp
add action=return chain="service_status" comment=\
    "BGMP, Border Gateway Multicast Protocol" port=264 protocol=tcp
add action=return chain="service_status" comment=\
    "BGMP, Border Gateway Multicast Protocol  " port=264 protocol=udp
add action=return chain="service_status" comment=\
    "Lightweight Directory Access Protocol (LDAP)" port=389 protocol=tcp
add action=return chain="service_status" comment=\
    "Lightweight Directory Access Protocol (LDAP)" port=389 protocol=udp
add action=return chain="service_status" comment=\
    "SSTP TCP Port 443 (Local Management) & HTTPS" port=443 protocol=tcp
add action=return chain="service_status" comment=\
    "Microsoft-DSActive Directory, Windows shares" port=445 protocol=tcp
add action=return chain="service_status" comment=\
    "L2TP/ IPSEC UDP Port 500 (Local Management)" port=500 protocol=udp
add action=return chain="service_status" comment="Modbus, Protocol" \
    port=502 protocol=tcp
add action=return chain="service_status" comment="Modbus, Protocol  " \
    port=502 protocol=udp
add action=return chain="service_status" comment=\
    "Shell (Remote Shell, rsh, remsh)" port=514 protocol=tcp
add action=return chain="service_status" comment=\
    "Syslog - used for system logging  " port=514 protocol=udp
add action=return chain="service_status" comment=\
    "Routing Information Protocol (RIP)  " port=520 protocol=udp
add action=return chain="service_status" comment=\
    "e-mail message submission (SMTP)" port=587 protocol=tcp
add action=return chain="service_status" comment=\
    "LDP,Label Distribution Protocol" port=646 protocol=tcp
add action=return chain="service_status" comment=\
    "LDP,Label Distribution Protocol" port=646 protocol=udp
add action=return chain="service_status" comment=\
    "FTPS Protocol (data):FTP over TLS/SSL" port=989 protocol=tcp
add action=return chain="service_status" comment=\
    "FTPS Protocol (data):FTP over TLS/SSL" port=989 protocol=udp
add action=return chain="service_status" comment=\
    "FTPS Protocol (control):FTP over TLS/SSL" port=990 protocol=tcp
add action=return chain="service_status" comment=\
    "FTPS Protocol (control):FTP over TLS/SSL" port=990 protocol=udp
add action=return chain="service_status" comment=\
    "TELNET protocol overTLS/SSL" port=992 protocol=tcp
add action=return chain="service_status" comment=\
    "TELNET protocol overTLS/SSL" port=992 protocol=udp
add action=return chain="service_status" comment=\
    "Internet Message Access Protocol over TLS/SSL (IMAPS)" port=993 \
    protocol=tcp
add action=return chain="service_status" comment=\
    "Post Office Protocol3 over TLS/SSL (POP3S)" port=995 protocol=tcp
add action=return chain="service_status" comment=\
    "OVPN TCP Port 1194 (Local Management)" port=1194 protocol=tcp
add action=return chain="service_status" comment=\
    "PPTP Port 1723 (Local Management)" port=1723 protocol=tcp
add action=return chain="service_status" comment=\
    "L2TP UDP Port 1701 (Local Management)" port=1701 protocol=udp
add action=return chain="service_status" comment=\
    "L2TP UDP Port 4500 (Local Management)" port=4500 protocol=udp
}

/ip firewall address-list {
  add address=0.0.0.0/8 comment="defconf: RFC6890" list=no_forward_ipv4
  add address=169.254.0.0/16 comment="defconf: RFC6890" list=no_forward_ipv4
  add address=224.0.0.0/4 comment="defconf: multicast" list=no_forward_ipv4
  add address=255.255.255.255/32 comment="defconf: RFC6890" list=no_forward_ipv4
}

/ip firewall address-list {
  add address=127.0.0.0/8 comment="defconf: RFC6890" list=bad_ipv4
  add address=192.0.0.0/24 comment="defconf: RFC6890" list=bad_ipv4
  add address=192.0.2.0/24 comment="defconf: RFC6890 documentation" list=bad_ipv4
  add address=198.51.100.0/24 comment="defconf: RFC6890 documentation" list=bad_ipv4
  add address=203.0.113.0/24 comment="defconf: RFC6890 documentation" list=bad_ipv4
  add address=240.0.0.0/4 comment="defconf: RFC6890 reserved" list=bad_ipv4
}

/ip firewall address-list {
  add address=0.0.0.0/8 comment="defconf: RFC6890" list=not_global_ipv4
  add address=10.0.0.0/8 comment="defconf: RFC6890" list=not_global_ipv4
  add address=100.64.0.0/10 comment="defconf: RFC6890" list=not_global_ipv4
  add address=169.254.0.0/16 comment="defconf: RFC6890" list=not_global_ipv4
  add address=172.16.0.0/12 comment="defconf: RFC6890" list=not_global_ipv4
  add address=192.0.0.0/29 comment="defconf: RFC6890" list=not_global_ipv4
  add address=192.168.0.0/16 comment="defconf: RFC6890" list=not_global_ipv4 disabled=yes
  add address=198.18.0.0/15 comment="defconf: RFC6890 benchmark" list=not_global_ipv4
  add address=255.255.255.255/32 comment="defconf: RFC6890" list=not_global_ipv4
}

/ip firewall address-list {
  add address=224.0.0.0/4 comment="defconf: multicast" list=bad_src_ipv4
  add address=255.255.255.255/32 comment="defconf: RFC6890" list=bad_src_ipv4
  add address=0.0.0.0/8 comment="defconf: RFC6890" list=bad_dst_ipv4
  add address=224.0.0.0/4 comment="defconf: RFC6890 multicast uPnP" list=bad_dst_ipv4 disabled=yes
}

/ip firewall raw {
add action=accept chain=prerouting comment="defconf: enable for transparent firewall" disabled=yes
add action=drop chain=prerouting comment="defconf: drop ddos IP's" dst-address-list=ddos-target src-address-list=ddos-attackers
add action=accept chain=prerouting comment="defconf: accept DHCP discover" dst-address=255.255.255.255 dst-port=67 in-interface-list=LAN protocol=udp src-address=0.0.0.0 src-port=68
add action=drop chain=prerouting comment="defconf: drop bogon IP's" src-address-list=bad_ipv4
add action=drop chain=prerouting comment="defconf: drop bogon IP's" dst-address-list=bad_ipv4
add action=drop chain=prerouting comment="defconf: drop bogon IP's" src-address-list=bad_src_ipv4
add action=drop chain=prerouting comment="defconf: drop bogon IP's" dst-address-list=bad_dst_ipv4
add action=drop chain=prerouting comment="defconf: drop non global from WAN" src-address-list=not_global_ipv4 in-interface-list=WAN
add action=drop chain=prerouting comment="defconf: drop forward to local lan from WAN" in-interface-list=WAN dst-address=192.168.88.0/24 disabled=yes
add action=drop chain=prerouting comment="defconf: drop local if not from default IP range" in-interface-list=LAN src-address=!192.168.88.0/24 disabled=yes
add action=drop chain=prerouting comment="defconf: drop bad UDP" port=0 protocol=udp
add action=jump chain=prerouting comment="defconf: jump to ICMP chain" jump-target=icmp4 protocol=icmp
add action=jump chain=prerouting comment="defconf: jump to TCP chain" jump-target=bad_tcp protocol=tcp
add action=accept chain=prerouting comment="defconf: accept everything else from LAN" in-interface-list=LAN
add action=accept chain=prerouting comment="defconf: accept everything else from WAN" in-interface-list=WAN
add action=drop chain=prerouting comment="defconf: drop the rest"
}

/ip firewall raw {
add action=drop chain=bad_tcp comment="defconf: TCP flag filter" protocol=tcp tcp-flags=!fin,!syn,!rst,!ack
add action=drop chain=bad_tcp comment=defconf protocol=tcp tcp-flags=fin,syn
add action=drop chain=bad_tcp comment=defconf protocol=tcp tcp-flags=fin,rst
add action=drop chain=bad_tcp comment=defconf protocol=tcp tcp-flags=fin,!ack
add action=drop chain=bad_tcp comment=defconf protocol=tcp tcp-flags=fin,urg
add action=drop chain=bad_tcp comment=defconf protocol=tcp tcp-flags=syn,rst
add action=drop chain=bad_tcp comment=defconf protocol=tcp tcp-flags=rst,urg
add action=drop chain=bad_tcp comment="defconf: TCP port 0 drop" port=0 protocol=tcp
}

/ip firewall raw {
add action=accept chain=icmp4 comment="defconf: echo reply" icmp-options=0:0 limit=5,10:packet protocol=icmp
add action=accept chain=icmp4 comment="defconf: net unreachable" icmp-options=3:0 protocol=icmp
add action=accept chain=icmp4 comment="defconf: host unreachable" icmp-options=3:1 protocol=icmp
add action=accept chain=icmp4 comment="defconf: protocol unreachable" icmp-options=3:2 protocol=icmp
add action=accept chain=icmp4 comment="defconf: port unreachable" icmp-options=3:3 protocol=icmp
add action=accept chain=icmp4 comment="defconf: fragmentation needed" icmp-options=3:4 protocol=icmp
add action=accept chain=icmp4 comment="defconf: echo request" icmp-options=8:0 limit=5,10:packet protocol=icmp
add action=accept chain=icmp4 comment="defconf: time exceeded " icmp-options=11:0-255 protocol=icmp
add action=drop chain=icmp4 comment="defconf: drop other icmp" protocol=icmp
}
