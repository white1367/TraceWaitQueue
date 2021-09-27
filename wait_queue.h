#include <linux/kernel.h>
#include <linux/wait.h>
#include <linux/sched.h>

DECLARE_WAIT_QUEUE_HEAD(project2_queue_1);
DECLARE_WAIT_QUEUE_HEAD(project2_queue_2);
DECLARE_WAIT_QUEUE_HEAD(project2_queue_3);
asmlinkage int enter_wait_queue(int x);
asmlinkage int clean_wait_queue(int x);
