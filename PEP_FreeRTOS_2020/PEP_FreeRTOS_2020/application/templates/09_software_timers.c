/*
 * Name:
 *     Using software timers
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A).
 *     - In this example we are using a software timer to toggle an LED
 *       periodically.
 *     - Note: we do not even create a task! The callback function associated
 *       with the timer will be executed by the timer task created by the OS
 *       upon starting the scheduler.
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
// Include header for the Board Support Package (BSP)
#include <bsp.h>

// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"
// TODO: include header for software timers --> "timers.h"


/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

/*
 * TODO: define a variable storing the handle to the timer created.
 * Use type TimerHandle_t
*/


/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

/*
 * TODO: declare a function which is called when the timer expires.
 * Use the following prototype:
 * void function_name(TimerHandle_t t)
*/



/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {
    // Initialize outputs to the LEDs
    BSP_LedsInit();

    // Initialize FreeRTOS

        /*
         * TODO: create a _periodic_ timer:
         *    - The callback function should be the one declared above.
         *    - The period should be in the order of one second.
         * Use function xTimerCreate().
        */


        /*
         * TODO: start the timer!
         * Use function xTimerStart()!
         */


        // Start the scheduler
        vTaskStartScheduler();

    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
   FUNCTION DEFINITIONS
-------------------------------------------------------------------------- */

// TODO: implement callback timer function by toggling a LED.
void toggleLED(TimerHandle_t t) {

}
