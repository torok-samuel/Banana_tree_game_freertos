/*
 * Name:
 *     Stack Overflow
 *
 * Description:
 *     - a FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A)
 *     - This example demonstrates how can FreeRTOS detect a stack overflow
 *       situation.
 *     - There is a task called "StackEater" that recursively tries to consume
 *       memory.
 *     - While there is an other task called "GoodBoy" which behaves well and in
 *       case of a stack overflow situation tries to save the system by deleting
 *       the "StackEater" task.
 *     - The function vApplicationStackOverflowHook() is entered if the kernel
 *       catch a stack overflow condition. This hook function is enabled only if
 *       configCHECK_FOR_STACK_OVERFLOW is not 0 (currently valid values are 1
 *       and 2).
 *     - The kernel checks for a stack overflow situation only when it has just
 *       swapped out a task. This is because when a task just has been swapped
 *       out its stack shall contain also the saved context. So it is most
 *       likely (but not guaranteed) that this is the time when the stack has
 *       reached its most extent.
 *     - The kernel stack overflow checking capabilities are not guaranteed to
 *       catch all stack overflow events.
 *     - If a given processor architecture generates a fault exception in case of
 *       a stack overflow situation, then this exception is generated before the
 *       kernel can check for the overflow condition.
 *
 * Created by:
 *     NASZALY Gabor <naszaly@mit.bme.hu>
 *
 * Last modified on:
 *     2020-03-02
*/

/* --------------------------------------------------------------------------
   INCLUDES
-------------------------------------------------------------------------- */

// Application specific includes
#include <stdio.h>
#include <retargetserial.h>

// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"

/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_STACK_EATER_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_STACK_EATER_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_GOOD_BOY_PRIORITY    ( tskIDLE_PRIORITY + 2 )
#define  mainTASK_GOOD_BOY_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

TaskHandle_t  task_caused_stack_overflow = NULL;

/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvEatStack(void);
static void prvTaskStackEater(void *pvParam);
static void prvTaskGoodBoy(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {
    // Initialize starter kit
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);

    // Initialize FreeRTOS

        // Create the stack eater task
        xTaskCreate(
                prvTaskStackEater,
                "Stack Eater",
                mainTASK_STACK_EATER_STACK_SIZE,
                NULL,
                mainTASK_STACK_EATER_PRIORITY,
                NULL);

        // Create the good boy task
        xTaskCreate(
                prvTaskGoodBoy,
                "Good Boy",
                mainTASK_GOOD_BOY_STACK_SIZE,
                NULL,
                mainTASK_GOOD_BOY_PRIORITY,
                NULL);

        // Start the scheduler
        vTaskStartScheduler();

    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
   FUNCTION DEFINITIONS
-------------------------------------------------------------------------- */

/*
 * This hook function is called if configCHECK_FOR_STACK_OVERFLOW is enabled
 * (has a value of 1 or 2), and upon swapping a task out the kernel observed a
 * stack overflow situation.
 *
 * This function is called from an interrupt context. So only those FreeRTOS API
 * functions are allowed that have a ...FromISR() variant (vTaskDelete() has
 * not).
*/
void vApplicationStackOverflowHook(TaskHandle_t xTask, signed char *pcTaskName){
    printf("(ApplicationStackOverflowHook): entered\n");
    printf("(ApplicationStackOverflowHook): caused by task %s\n", pcTaskName);
    task_caused_stack_overflow = xTask;
}

/*
 * A recursive function.
 * As recursion is done unconditionally at some point this will consume the
 * whole stack.
*/
static void prvEatStack(void) {
    static uint8_t level = 0;

    level++;
    printf("(EatStack): is at level %d\n", level);
    vTaskDelay(configTICK_RATE_HZ);
    prvEatStack();
}

/*
 * The stack eater task.
 * Calls the recursive stack eater function.
*/
static void prvTaskStackEater(void *pvParam) {
    printf("<Stack Eater>: entered\n");
    while (1) {
        printf("<Stack Eater>: started to eat\n");
        prvEatStack();
    }
}

/*
 * The good boy task basically does nothing.
 * But if the stack overflow hook function identified a task that has consumed
 * its stack then tries to delete that task.
*/
static void prvTaskGoodBoy(void *pvParam) {
    printf("<Good Boy>: entered\n");
    while (1) {
        printf("<Good Boy>: doing something\n");
        vTaskDelay(configTICK_RATE_HZ*4);
        if (task_caused_stack_overflow) {
            printf("<Good Boy>: try to save the world by killing task <Stack Eater>\n");
            vTaskDelete(task_caused_stack_overflow);
            task_caused_stack_overflow = NULL;
        }
    }
}
