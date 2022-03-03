# wireless
/interface wireless {
	:local ifcId [/interface wireless find where default-name=wlan1]
	:local currentName [/interface wireless get $ifcId name]
	:local wlanMac  [/interface wireless get $ifcId mac-address];
	:local ssid "MikroTik-$[:pick $wlanMac 9 11]$[:pick $wlanMac 12 14]$[:pick $wlanMac 15 17]"
	set $ifcId ssid=$ssid
	set $ifcId adaptive-noise-immunity=ap-and-client-mode channel-width=20mhz \
	band=2ghz-b/g/n basic-rates-a/g=12Mbps basic-rates-b="" country=taiwan \
	disabled=yes distance=indoors frequency=auto guard-interval=long \
	hw-protection-mode=rts-cts installation=indoor keepalive-frames=disabled \
	mode=ap-bridge rate-set=configured scan-list=2412,2437,2462 \
	skip-dfs-channels=all supported-rates-a/g=\
	12Mbps,18Mbps,24Mbps,36Mbps,48Mbps,54Mbps supported-rates-b="" \
	wireless-protocol=802.11 wmm-support=enabled wps-mode=disabled
}
/interface wireless {
	:local ifcId [/interface wireless find where default-name=wlan2]
	:local currentName [/interface wireless get $ifcId name]
	:local wlanMac  [/interface wireless get $ifcId mac-address];
	:local ssid "MikroTik-$[:pick $wlanMac 9 11]$[:pick $wlanMac 12 14]$[:pick $wlanMac 15 17]"
	set $ifcId ssid=$ssid
	set $ifcId band=5ghz-onlyac channel-width=\
	20/40/80mhz-Ceee country=taiwan disabled=yes distance=indoors frequency=\
	auto installation=indoor keepalive-frames=disabled mode=ap-bridge \
	skip-dfs-channels=all wireless-protocol=802.11 wmm-support=enabled \
	wps-mode=disabled
}
/interface wireless security-profiles
set [ find default=yes ] authentication-types=wpa2-psk disable-pmkid=yes \
		   eap-methods="" group-key-update=1h mode=dynamic-keys \
		   wpa-pre-shared-key="12345678" wpa2-pre-shared-key="12345678"
/interface bridge
set [ find name=bridge ] protocol-mode=none

/ip service
set telnet disabled=yes
set ftp disabled=yes
set www disabled=yes
set ssh disabled=yes
set api disabled=yes
set api-ssl disabled=yes

/ip proxy set enabled=no
/ip socks set enabled=no
/ip cloud set ddns-enabled=no update-time=yes
/ip upnp set enabled=no
/ip upnp interfaces {
add interface=bridge type=internal
add interface=ether1 type=external
}

/ip ssh set strong-crypto=yes

# This section can left alone for most situations, however, if you are multi-homing, this could cause a
# problem. In a multi-homed network, setting the rp-filter to no or loose may be the better choice.
/ip settings
set rp-filter=strict secure-redirects=no send-redirects=no tcp-syncookies=yes

/ip firewall connection tracking
set enabled=yes loose-tcp-tracking=no

/ip neighbor discovery-settings set discover-interface-list=none

/system clock
set time-zone-autodetect=no time-zone-name=Asia/Taipei

:local o [/system routerboard settings get cpu-frequency]
:if ([:len $o] != 0) do={ /system routerboard settings set cpu-frequency=auto }

/tool bandwidth-server set enabled=no
/tool bandwidth-server set authenticate=yes
/tool mac-server set allowed-interface-list=none
/tool mac-server mac-winbox set allowed-interface-list=none
/tool mac-server ping set enabled=no

