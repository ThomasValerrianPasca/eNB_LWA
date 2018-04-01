#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xfe467665, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x93fea7d0, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x6c09c2a4, __VMLINUX_SYMBOL_STR(del_timer) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xf6d9b936, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xaac8f441, __VMLINUX_SYMBOL_STR(netif_rx) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x444ab1ff, __VMLINUX_SYMBOL_STR(netif_tx_wake_queue) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x6f90e497, __VMLINUX_SYMBOL_STR(netlink_kernel_release) },
	{ 0x5c084f7, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0xcee93615, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0xae251339, __VMLINUX_SYMBOL_STR(netlink_unicast) },
	{ 0x8163d496, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0xf6c47f32, __VMLINUX_SYMBOL_STR(__alloc_skb) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xd234aa50, __VMLINUX_SYMBOL_STR(alloc_netdev_mqs) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x7323c706, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xefb87178, __VMLINUX_SYMBOL_STR(__netlink_kernel_create) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x7664db86, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x7200ed11, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0x9eb7ccd, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0xe39e2f4f, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x226c32c1, __VMLINUX_SYMBOL_STR(param_ops_uint) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "533BB7E5866E52F63B9ACCB");
