#include <linux/module.h>
#include <linux/kernel.h>
int init_module(void)
{
	printk(KERN_INFO "Dhairya Dhondiyal: Loading Hello1 module - Hello World 1\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Dhairya Dhondiyal: Exiting Hello1 module - Goodbye World 1\n");
}