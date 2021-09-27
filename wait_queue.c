#include <linux/kernel.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include "wait_queue.h"

extern wait_queue_head_t project2_queue_1;
extern wait_queue_head_t project2_queue_2;
extern wait_queue_head_t project2_queue_3;

asmlinkage int enter_wait_queue(int x){
    switch(x){
        case 1:
            interruptible_sleep_on(project2_queue_1);
            break;
        case 2:
            interruptible_sleep_on(project2_queue_2);
            break;
        case 3:
            interruptible_sleep_on(project2_queue_3);
            break;
        default:
            return 1;
            break;
    }
    printk("Process added to project2_queue_%d", x);
    return 0;

}
asmlinkage int clean_wait_queue(int x){
    switch(x){
        case 1:
            wake_up_all(&project2_queue_1);
            break;
        case 2:
            wake_up_all(&project2_queue_2);
            break;
        case 3:
            wake_up_all(&project2_queue_3);
            break;
        default:
            return 1;
            break;
    }
    printk("Process removed from project2_queue_%d", x);
    return 0;
}



