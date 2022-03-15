#define EXERCISE 1

#ifndef EXERCISE
#error "EXERCISE should be defined!"
#else

#define TEMPLATES 1
#define SOLUTIONS 2
#define BRANCH    TEMPLATES
//#define BRANCH    SOLUTIONS

#ifndef BRANCH
#error "BRANCH should be defined!"
#else


#if BRANCH == TEMPLATES

#if   (EXERCISE == 1)
#include "templates/01_hello_world.c"
#elif (EXERCISE == 2)
#include "templates/02_suspend-resume.c"
#elif (EXERCISE == 3)
#include "templates/03_time_delay.c"
#elif (EXERCISE == 4)
#include "templates/04_time-slicing.c"
#elif (EXERCISE == 5)
#include "templates/05_semaphore.c"
#elif (EXERCISE == 6)
#include "templates/06_queue.c"
#elif (EXERCISE == 7)
#include "templates/07_shared_resources.c"
#elif (EXERCISE == 8)
#include "templates/08_priority_inversion.c"
#elif (EXERCISE == 9)
#include "templates/09_software_timers.c"
#elif (EXERCISE == 10)
#include "templates/10_interrupts.c"
#elif (EXERCISE == 11)
#include "templates/11_event_flags.c"
#elif (EXERCISE == 12)
#include "templates/12_task_notifications.c"
#elif (EXERCISE == 13)
#include "templates/13_stack_overflow.c"
#elif (EXERCISE == 14)
#include "templates/14_idle_hook.c"
#else
#error "Unknown exercise!"
#endif


#elif BRANCH == SOLUTIONS

#if   (EXERCISE == 1)
#include "solutions/01_hello_world.c"
#elif (EXERCISE == 2)
#include "solutions/02_suspend-resume.c"
#elif (EXERCISE == 3)
#include "solutions/03_time_delay.c"
#elif (EXERCISE == 4)
#include "solutions/04_time-slicing.c"
#elif (EXERCISE == 5)
#include "solutions/05_semaphore.c"
#elif (EXERCISE == 6)
#include "solutions/06_queue.c"
#elif (EXERCISE == 7)
#include "solutions/07_shared_resources.c"
#elif (EXERCISE == 8)
#include "solutions/08_priority_inversion.c"
#elif (EXERCISE == 9)
#include "solutions/09_software_timers.c"
#elif (EXERCISE == 10)
#include "solutions/10_interrupts.c"
#elif (EXERCISE == 11)
#include "solutions/11_event_flags.c"
#elif (EXERCISE == 12)
#include "solutions/12_task_notifications.c"
#elif (EXERCISE == 13)
#include "solutions/13_stack_overflow.c"
#elif (EXERCISE == 14)
#include "solutions/14_idle_hook.c"
#else
#error "Unknown exercise!"
#endif

#else

#error "Unknown branch!"

#endif

#endif // #ifndef BRANCH

#endif // #ifndef EXERCISE
