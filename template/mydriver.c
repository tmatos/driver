#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

static int __init mydriver_init(void)
{
    pr_info("mydriver registrado");
    return 0;
}

static void __exit mydriver_exit(void)
{
    pr_info("mydriver desregistrado");
}

module_init(mydriver_init);
module_exit(mydriver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tiago Matos");
MODULE_DESCRIPTION("mydriver - Template para Device Driver");
