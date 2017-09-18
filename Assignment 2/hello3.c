#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
MODULE_LICENSE("GPL");
int number=0;
module_param(number,int,0);
static int __init hello3(void)
{
	printk(KERN_INFO "Loading Hello %d: Hello World %d\n",number,number);
	return 0;
}

static void __exit hello3_exit(void)
{
	printk(KERN_INFO "=====================\nName : Dhairya Dhondiyal\nStreet : Summit\nCity : Jersey City\nZIP code : 300056\n");
}

module_init(hello3);
module_exit(hello3_exit);
