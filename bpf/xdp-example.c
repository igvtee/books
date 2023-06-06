#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

SEC("prog")
int xdp_drop(struct xdp_md *ctx)
{
	return XDP_DROP;
}

char _license[] SEC("license") = "GPL";
