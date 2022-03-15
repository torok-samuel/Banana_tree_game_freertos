/*
 * Name:
 *     Shared resources
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A)
 *     - There are two tasks. Both of them are writing to the standard output
 *       periodically.
 *     - The lower priority task writes a relatively long string in every
 *       second, while the higher priority task prints only a carriage return
 *       (\r) but with a much lower period (which should be not an integer
 *       divisor of one second).
 *     - These timing conditions have been artificially made to make
 *       the observation of the problem with shared resources possible.
 *     - It is important to note that these artificial conditions make only
 *       the probability of this problem greater but the problem is still there
 *       (with less probability) without these conditions.
 *     - The problem can be solved by using semaphores.
 *     - Note: although a traditional binary semaphore is able to solve the
 *       problem the usage of these semaphores has an unwanted side effect:
 *       priority inversion. This effect can be mitigated by using mutexes
 *       instead of binary semaphores (see next exercise).
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
#include "semphr.h"

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

SemaphoreHandle_t guardian;

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
    // Now we do not use RETARGET_SerialCrLf(1) as we want to send '\r' only
    // (without the addition of a '\n').

    // Initialize FreeRTOS

        // Create a semaphore
        guardian = xSemaphoreCreateBinary();
        xSemaphoreGive(guardian);

        // Create the high priority task
        xTaskCreate(
                prvTaskHi,
                "High",
                mainTASK_HI_STACK_SIZE,
                NULL,
                mainTASK_HI_PRIORITY,
                NULL);

        // Create the low priority task
        xTaskCreate(
                prvTaskLo,
                "Low",
                mainTASK_LO_STACK_SIZE,
                NULL,
                mainTASK_LO_PRIORITY,
                NULL);

        // Start the scheduler
        vTaskStartScheduler();

    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
   FUNCTION DEFINITIONS
-------------------------------------------------------------------------- */

// High priority task
static void prvTaskHi(void *pvParam) {

    while (1) {
        // TODO: wait a much smaller time than a second (and preferably not
        // an integer divisor to it)


        // TODO: print a carriage return character only

    }
}

// Low priority task
static void prvTaskLo(void *pvParam) {

    while (1) {
        // TODO: wait about one second


        // TODO: print a relatively long string to the standard output

    }
}
