#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/cred.h>
#include <linux/sched/user.h>

asmlinkage uid_t sys_getuserweight(int user_id) {
	struct user_struct *user_to_get;
	kuid_t kuser_id;
	if (user_id == -1){
		kuser_id.val = current_uid().val;
	}else if (user_id < -1){
		return -EINVAL;
	}else{
		kuser_id.val = user_id;
	}
	user_to_get = find_user(kuser_id);
	if (user_to_get ==  NULL){
		return -EINVAL;
	}
	return user_to_get->user_weight;
}
