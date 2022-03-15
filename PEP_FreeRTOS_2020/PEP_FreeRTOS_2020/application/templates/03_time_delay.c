/*
 * Name:
 *     Two independent threads (on separate priority levels)
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A).
 *     - There are two independent tasks periodically printing out something.
 *     - The aim is to test if FreeRTOS is able to switch context from a task
 *       NOT willing to give up CPU time if a higher priority task awakes
 *       (preemption).
 *
 * Variant:
 *     - Try out this exercise also with preemption disabled!
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
#include <udelay.h>

// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"

/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_HI_PRIORITY    ( tskIDLE_PRIORITY + 2 )
#define  mainTASK_HI_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_LO_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_LO_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskHi(void *pvParam);
static void prvTaskLo(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {

    // Initialize starter kit
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);
    UDELAY_Calibrate();       // Calibrate software delay loops

    // Initialize FreeRTOS

        // TODO: create the high priority task --> xTaskCreate()


        // TODO: create the low priority task --> xTaskCreate()


        vTaskStartScheduler();

    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
   FUNCTION DEFINITIONS
-------------------------------------------------------------------------- */

/*
 * TODO: implement the high priority task as an endless loop
 *     - Print a short message in every second
 *     - vTaskDelay() should be used to wait a second
*/
static void prvTaskHi(void *pvParam) {
}

/*
 * TODO: implement the low priority task as an endless loop
 *     - Print '.' characters periodically (at about 10Hz)
 *     - Use software delay loops for delaying the task (like a long enough
 *       for() loop or UDELAY_Delay() from <udelay.h>)
 *     - Note: this is a greedy task from the execution point of view. It never
 *       tries to put itself into the BLOCKED state. Generally it is not a good
 *       design pattern. We chose this structure to show that the OS is able to
 *       take the right of execution from the RUNNING task if a higher
 *       priority task has been awaken (even if the current task is greedy).
*/
static void prvTaskLo(void *pvParam) {
}
