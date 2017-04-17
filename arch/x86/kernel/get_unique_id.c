#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>

asmlinkage long sys_get_unique_id(int *uuid){
	static int id_ASS = 99;
	id_ASS = id_ASS+1;
	if(put_user(id_ASS, uuid))
		return -EFAULT;
	return 0;
}
