#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/pid.h>

#include <linux/mount.h>
#include <linux/sched.h>

#include <linux/fs.h>
#include <linux/path.h>
#include <linux/mm_types.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("scarletshroud");
MODULE_DESCRIPTION("A kernel module which collects info about vfsmount struct and signal struct");
MODULE_VERSION("0.01"); 

static struct vfsmount *vfs; 
static struct signal_struct *sig; 

static int __init kernel_module_init(void) {
	printk(KERN_INFO, "Hello!\n");

	struct task_struct *tsl = get_pid_task(find_get_pid(1), PIDTYPE_PID);
	sig = tsl->signal;
       
	struct mm_struct *mm = tsl->mm;
	struct file *f = mm->exe_file;
	struct path *p = &f->f_path;
	vfs = p->mnt; 
	
	printk(KERN_INFO, "It's okay!");
		
	return 0;
}

static void __exit kernel_module_exit(void) {
	printk(KERN_INFO, "Bye!\n");
}

module_init(kernel_module_init);
module_exit(kernel_module_exit);

