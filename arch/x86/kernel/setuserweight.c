#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/cred.h>
#include <linux/sched/user.h>

asmlinkage uid_t sys_setuserweight(uid_t user_id, unsigned long weight) {
	struct user_struct *user_to_change_weight;
	kuid_t kuser_id;
	kuser_id.val = user_id;
	if (current_uid().val){
		return EACCES;
	}
	if (weight<0){
		return -EINVAL;
	}
	user_to_change_weight = find_user(kuser_id);
	if (user_to_change_weight == NULL){
		return -EINVAL;
	}
	user_to_change_weight->user_weight = weight;
	return 0;
}
