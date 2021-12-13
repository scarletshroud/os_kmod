#include <mount.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

void print_signal_struct_info(struct signal_struct *sig);
void print_vfsmount_struct_info(struct vfsmount *vfs);

int main(int argc, char *argv[]) {
	
	if (argc != 1) {
		printf("%s", "Program takes 1 argument. Example: ./user [PID]");
		return 0; 
	}

	const size_t pid = atoi(argv[0]);	

	const struct signal_struct sig = syscall(SYS_signal_struct_get, pid);
	const struct vfsmount vfs = syscall(SYS_vfsmount_struct_get, pid); 

	if (sig != null) {
		print_signal_struct_info(&sig); 	
	}

	if (vfs != null) {
		print_vfsmount_struct_info(&vfs); 	
	}

	return 0;
}

void print_signal_struct_info(struct signal_struct *sig) {
	printf("%s", "SIGNAL STRUCT INFO");
}

void print_vfsmount_struct_info(struct vfsmount *vfs) {
	printf("%s", "VFSMOUNT STRUCT INFO");
}
