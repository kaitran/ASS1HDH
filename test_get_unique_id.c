#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

#define IS_32_BIT 0
#if IS_32_BIT
	#define __NR_get_unique_id 383
#else
	#define __NR_get_unique_id 548
#endif

long get_unique_id(int *uuid){
	return syscall(__NR_get_unique_id,uuid)?errno:0;
}
int main(){
	int uuid;
	int res;
	res = get_unique_id(&uuid);
	printf(" Syscall returne %d, uuid is %d\n",res, uuid);
	res = get_unique_id(&uuid);
	printf(" Syscall returne %d, uuid is %d\n",res, uuid);
	res = get_unique_id(47424742);
	printf(" Syscall returne %d\n",res);
	return 0;
}
