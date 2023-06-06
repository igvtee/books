#include <linux/bpf.h>
#include <linux/pkt_cls.h>
#include <stdint.h>
#include <iproute2/bpf_elf.h>
#include <bpf/bpf_helpers.h>

#if 0
#ifndef SEC
# define SEC(NAME)                  \
	__attribute__((section(NAME), used))
#endif

#ifndef __inline
# define __inline                         \
	inline __attribute__((always_inline))
#endif
#endif

#ifndef lock_xadd
# define lock_xadd(ptr, val)              \
	((void)__sync_fetch_and_add(ptr, val))
#endif

#ifndef BPF_FUNC
# define BPF_FUNC(NAME, ...)              \
	(*NAME)(__VA_ARGS__) = (void *)BPF_FUNC_##NAME
#endif

static void *BPF_FUNC(map_lookup_elem, void *map, const void *key);

struct bpf_elf_map acc_map SEC("maps") = {
	.type           = BPF_MAP_TYPE_ARRAY,
	.size_key       = sizeof(uint32_t),
	.size_value     = sizeof(uint32_t),
	.pinning        = PIN_GLOBAL_NS,
	.max_elem       = 2,
};

static __inline int account_data(struct __sk_buff *skb, uint32_t dir)
{
	uint32_t *bytes;

	bytes = map_lookup_elem(&acc_map, &dir);
	if (bytes)
		lock_xadd(bytes, skb->len);

	return TC_ACT_OK;
}

SEC("ingress")
int tc_ingress(struct __sk_buff *skb)
{
	return account_data(skb, 0);
}

SEC("egress")
int tc_egress(struct __sk_buff *skb)
{
	return account_data(skb, 1);
}

char __license[] SEC("license") = "GPL";

