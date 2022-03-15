/*
 * Name:
 *     Two independent threads (on the same priority level)
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A).
 *     - There are two independent tasks periodically printing out something.
 *     - The aim is to test if FreeRTOS is able to switch context from a task
 *       NOT willing to give up CPU time if the time-slice is elapsed
 *       (time-slicing scheduling).
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

#define  mainTASK_A_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_A_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_B_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_B_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskA(void *pvParam);
static void prvTaskB(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {

    // Initialize starter kit
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);
    UDELAY_Calibrate();      // Calibrate software delay loops

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
 * TODO: implement task A as an endless loop
 *     - Print '0' characters periodically (at the maximum possible rate)
 *     - No delays are used
 *     - Note: this is a greedy task from the execution point of view. It never
 *       tries to put itself into the BLOCKED state. Generally it is not a good
 *       design pattern. We chose this structure to show the time-slicing
 *       capabilities of the OS.
*/
static void prvTaskA(void *pvParam) {
}

/*
 * TODO: implement task B as an endless loop
 *     - Print '.' characters periodically (at the maximum possible rate)
 *     - No delays are used
 *     - Note: this is a greedy task from the execution point of view. It never
 *       tries to put itself into the BLOCKED state. Generally it is not a good
 *       design pattern. We chose this structure to show the time-slicing
 *       capabilities of the OS.
*/
static void prvTaskB(void *pvParam) {
}
