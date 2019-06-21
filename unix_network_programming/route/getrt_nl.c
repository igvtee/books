#include	"unproute.h"

#define	SEQ		9999
#define BUFSIZE		8192

static void rtnl_print_route(struct nlmsghdr * nh)
{
	struct rtmsg *rt = NLMSG_DATA(nh);
	struct rtattr *attr = RTM_RTA(rt);
	int len = RTM_PAYLOAD(nh);
	char buf[32];
	int ifindex;

	if (rt->rtm_table != RT_TABLE_MAIN)
		return;

	for (; RTA_OK(attr, len); attr = RTA_NEXT(attr, len)) {
		switch (attr->rta_type) {
		case RTA_DST:
			Inet_ntop(AF_INET, RTA_DATA(attr), buf, sizeof(buf));
			printf("dest: %s\n", buf);
			break;
		case RTA_GATEWAY:
			Inet_ntop(AF_INET, RTA_DATA(attr), buf, sizeof(buf));
			printf("gateway: %s\n", buf);
			break;
		case RTA_OIF:
			ifindex = *(int *) RTA_DATA(attr);
			printf("out ifindex: %d\n", ifindex);
			break;
		case RTA_PREFSRC:
			Inet_ntop(AF_INET, RTA_DATA(attr), buf, sizeof(buf));
			printf("prefer src: %s\n", buf);
			break;
		default:
			break;
		}
	}
}

int main(int argc, char **argv)
{
	int sockfd, len;
	struct sockaddr_nl sa;
	const int on = 1;
	struct msghdr msg;
	struct iovec iov;
	in_addr_t addr;
	void *buf;
	int pid = getpid();
	struct nlmsghdr *nh;
	struct rtmsg *rt;
	struct rtattr *attr;

	if (argc != 2)
		err_quit("usage: getrt <IPaddress>");

	sockfd = Socket(AF_NETLINK, SOCK_RAW|SOCK_CLOEXEC, NETLINK_ROUTE);
	Setsockopt(sockfd, SOL_NETLINK, NETLINK_EXT_ACK, &on, sizeof(on));

	memset(&sa, 0, sizeof(sa));
	sa.nl_family = AF_NETLINK;
	Bind(sockfd, (SA *) &sa, sizeof(sa));

	nh = buf = Calloc(1, BUFSIZE);	/* and initialized to 0 */
	rt = NLMSG_DATA(nh);
	nh->nlmsg_len = NLMSG_LENGTH(sizeof(*rt));
	nh->nlmsg_type = RTM_GETROUTE;
	nh->nlmsg_flags = NLM_F_REQUEST;
	nh->nlmsg_seq = SEQ;
	nh->nlmsg_pid = pid;
	rt->rtm_family = AF_INET;
	rt->rtm_dst_len = 32;
	rt->rtm_flags = RTM_F_LOOKUP_TABLE;

	/* add rt attr */
	attr = RTM_RTA(rt);
	attr->rta_type = RTA_DST;
	attr->rta_len = RTA_LENGTH(sizeof(addr));
	nh->nlmsg_len = NLMSG_ALIGN(nh->nlmsg_len) +
		attr->rta_len;
	Inet_pton(AF_INET, argv[1], &addr);
	memcpy(RTA_DATA(attr), &addr, sizeof(addr));

	iov.iov_base = (void *)nh;
	iov.iov_len = nh->nlmsg_len;

	msg = (struct msghdr) { &sa, sizeof(sa), &iov, 1, NULL, 0, 0 };
	Sendmsg(sockfd, &msg, 0);

	iov.iov_len = BUFSIZE;
	len = Recvmsg(sockfd, &msg, 0);
	for (nh = (struct nlmsghdr *) buf; NLMSG_OK (nh, len);
	     nh = NLMSG_NEXT (nh, len)) {
		switch (nh->nlmsg_type) {
		case NLMSG_DONE:
			break;
		case NLMSG_ERROR:
			err_sys("message error");
			break;
		case RTM_NEWROUTE:
			if (nh->nlmsg_seq != SEQ)
				err_sys("message sequence error: %u", nh->nlmsg_seq);
			if (nh->nlmsg_pid != pid)
				err_sys("message pid error: %u", nh->nlmsg_pid);
			rtnl_print_route(nh);
			break;
		default:
			printf("Ignored msg: type=%d, len=%d\n", nh->nlmsg_type,
			       nh->nlmsg_len);
			break;
		}
	}

	free(buf);
	close(sockfd);

	return 0;
}
