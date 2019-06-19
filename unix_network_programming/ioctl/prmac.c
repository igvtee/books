#include	"unpifi.h"
#include	<net/if_arp.h>

int
main(int argc, char **argv)
{
	int					sockfd;
	struct ifi_info			*ifi;
	unsigned char		*ptr;
	struct arpreq		arpreq;
	struct sockaddr_in	*sin;

	if (argc != 2)
		err_quit("usage: prmac <ip address>");

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
	for (ifi = get_ifi_info(AF_INET, 0); ifi != NULL; ifi = ifi->ifi_next) {
		printf("%s %s: ", ifi->ifi_name, Sock_ntop(ifi->ifi_addr,
							   sizeof(struct sockaddr_in)));

		bzero(&arpreq, sizeof(arpreq));
		sin = (struct sockaddr_in *) &arpreq.arp_pa;
		sin->sin_family = ifi->ifi_addr->sa_family;
		Inet_pton(ifi->ifi_addr->sa_family, argv[1], &sin->sin_addr);
		strncpy(arpreq.arp_dev, ifi->ifi_name, IFNAMSIZ-1);

		if (ioctl(sockfd, SIOCGARP, &arpreq) < 0) {
			err_ret("ioctl SIOCGARP");
			continue;
		}

		ptr = (unsigned char *) &arpreq.arp_ha.sa_data[0];
		printf("%x:%x:%x:%x:%x:%x\n", *ptr, *(ptr+1),
			   *(ptr+2), *(ptr+3), *(ptr+4), *(ptr+5));
	}
	exit(0);
}
