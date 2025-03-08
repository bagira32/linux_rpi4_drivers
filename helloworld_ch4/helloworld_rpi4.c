#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>

#define MY_MAJOR_NUM 202

static struct cdev my_dev;

static int my_dev_open(struct inode *inode, struct file *file)
{
	pr_info("my_dev_open() is called.\n");
	return 0;
}


static int my_dev_close(struct inode *inode, struct file *file)
{
	pr_info("my_dev_close() is called.\n");
	return 0;
}


static long my_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{	
	pr_info("my_dev_ioctl() is called. cmd = %d, arg = %ld\n", cmd, arg);
	return 0;
}

static const struct file_operations my_dev_fops = {
	.owner = THIS_MODULE,
	.open = my_dev_open,
	.release = my_dev_close,
	.unlocked_ioctl = my_dev_ioctl,
};

static int __init hello_init(void)
{
	int ret;
        pr_info("Hello world Mod_ch4 init\n");
        dev_t dev = MKDEV(MY_MAJOR_NUM, 0); /* get first device identifier */
        /*
        * Allocates all the character device identifiers,
        * only one in this case, the one obtained with the MKDEV macro
        */
        ret = register_chrdev_region(dev, 1, "my_char_device");
	if (ret < 0) {
		pr_info("Unable to allocate mayor number %d\n", MY_MAJOR_NUM);
		return ret;
	}

	/* Initialize the cdev structure and add it to kernel space */
	cdev_init(&my_dev, &my_dev_fops);
	ret= cdev_add(&my_dev, dev, 1);
	if (ret < 0) {
		unregister_chrdev_region(dev, 1);
		pr_info("Unable to add cdev\n");
		return ret;
	}
        return 0;
}

static void __exit hello_exit(void)
{
	pr_info("Hello world Mod exit\n");
	cdev_del(&my_dev);
	unregister_chrdev_region(MKDEV(MY_MAJOR_NUM, 0), 1);
}
module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bagira <bagir32@gmail.com>");
MODULE_DESCRIPTION("This is a print out Hello World module");
