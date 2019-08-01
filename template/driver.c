#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

static int __init mydrv_init(void)
{
    pr_info("mydrv registrado");
    return 0;
}

static void __exit mydrv_exit(void)
{
    pr_info("mydrv desregistrado");
}

module_init(mydrv_init);
module_exit(mydrv_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tiago Matos");
MODULE_DESCRIPTION("mydrv - Template para Device Driver");
