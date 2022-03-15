/*
 * Name:
 *     Hello World!
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A).
 *     - There is only one task (having "single-shot" structure). It prints out
 *       the famous "Hello World!" message then deletes itself (as no task is
 *       allowed to return from the function implementing the task).
 *     - The aim is to test if FreeRTOS works at all (proof of concept).
 *
 * Variants:
 *     - It is worth to investigate what happens if we forget to start the
 *       scheduler.
 *     - It is worth to investigate also what happens if the task does not
 *       delete itself.
 *     - Finally it is advised to check what happens if we use the simplest heap
 *       implementation --> "heap_1.c".
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
// TODO: include general FreeRTOS header --> "FreeRTOS.h"

// TODO: include FreeRTOS header for task API --> "task.h"


/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_HELLO_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_HELLO_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskHello(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {

    // Initialize starter kit
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);

    // Initialize FreeRTOS

        /*
         * TODO: create a task --> xTaskCreate()
         *
         * The parameters (in order):
         *     - a function pointer to the task's code
         *     - a debug string (optional, can be "")
         *     - stack size (in words)
         *     - a parameter passed to the task (optional, can be NULL)
         *     - task priority (a greater value represents higher priority)
         *     - a pointer to store a handle for the task (now can be NULL)
        */


        /*
         * TODO: start the scheduler --> vTaskStartScheduler()
         *
         * This function is not expected to return and does the followings:
         *     - create the idle task
         *     - create the timer task for software timer services (optional)
         *     - configure a timer for run-time statistics (optional)
         *     - setup the SysTick timer interrupt
         *     - start highest priority task ready to run
        */


    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
   FUNCTION DEFINITIONS
-------------------------------------------------------------------------- */

/*
 * TODO: implement the "hello world" task
 *     - Print out the message
 *     - The task should be a "single-shot" task (a task running to completion,
 *       and not in an endless-loop) --> call vTaskDelete() at the end. A NULL
 *       pointer as the parameter indicates that the task to be deleted is the
 *       calling one
*/
static void prvTaskHello(void *pvParam) {
}
