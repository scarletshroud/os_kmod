#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE1(vfsmount_struct_get, size_t pid) {
	char buf[256];
	int char_copied = strncpy_from_user(buf, arg, sizeof(buf));
	if (char_copied < 0 || char_copied == sizeof(buf)) {
		return -EFAULT; 
	}

	return 0;
}

