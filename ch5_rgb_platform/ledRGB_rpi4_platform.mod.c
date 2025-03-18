#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x122c3a7e, "_printk" },
	{ 0xd86aae26, "misc_deregister" },
	{ 0xf61c822d, "devm_kmalloc" },
	{ 0x9e5116f0, "of_property_read_string" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x59c3686c, "misc_register" },
	{ 0xedc03953, "iounmap" },
	{ 0x1a704aed, "platform_driver_unregister" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0xdcb764ad, "memset" },
	{ 0xfd69799a, "__platform_driver_register" },
	{ 0xaf56600a, "arm64_use_ng_mappings" },
	{ 0x40863ba1, "ioremap_prot" },
	{ 0x6cbbfc54, "__arch_copy_to_user" },
	{ 0x773354b7, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Carrow,RGBleds");
MODULE_ALIAS("of:N*T*Carrow,RGBledsC*");

MODULE_INFO(srcversion, "978A342EE0A92A52ADA0C5B");
