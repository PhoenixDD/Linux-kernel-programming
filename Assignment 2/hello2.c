#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
static int number __initdata=2;
static int __init hello2(void)
{
	printk(KERN_INFO "Dhairya Dhondiyal: Loading Hello%d module - Hello World %d\n",number,number);
	return 0;
}

static void __exit hello2_exit(void)
{
	printk(KERN_INFO "Dhairya Dhondiyal: Exiting Hello2 module - Goodbye World 2\n");
}

module_init(hello2);
module_exit(hello2_exit);
