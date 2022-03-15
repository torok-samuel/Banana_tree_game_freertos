/*
 * Name:
 *     Synchronizing tasks with a semaphore (signal an event)
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A)
 *     - There are two tasks. One is signaling an event by using a semaphore and
 *       the other is waiting for this event.
 *     - The signaling task is supposed to signal the event once in every second
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
// TODO: include header for semaphore API --> "semphr.h"


/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_SIGNAL_PRODUCER_PRIORITY    ( tskIDLE_PRIORITY + 2 )
#define  mainTASK_SIGNAL_PRODUCER_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_SIGNAL_CONSUMER_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_SIGNAL_CONSUMER_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

/* TODO: Create a variable to store the handle for the binary semaphore used
 * to signal the event. Type should be "SemaphoreHandle_t".
 */


/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskSignalProducer(void *pvParam);
static void prvTaskSignalConsumer(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {

    // Initialize starter kit
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);

    // Initialize FreeRTOS

        /* TODO: create the binary semaphore for signaling the event.
         * Use API function xSemaphoreCreateBinary().
         */


        // Create the signal producer task
        xTaskCreate(
                prvTaskSignalProducer,
                "Signal Producer",
                mainTASK_SIGNAL_PRODUCER_STACK_SIZE,
                NULL,
                mainTASK_SIGNAL_PRODUCER_PRIORITY,
                NULL);

        // Create the signal consumer task
        xTaskCreate(
                prvTaskSignalConsumer,
                "Signal Consumer",
                mainTASK_SIGNAL_CONSUMER_STACK_SIZE,
                NULL,
                mainTASK_SIGNAL_CONSUMER_PRIORITY,
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
 * This task produces the events
 *
 * TODO:
 *    - Implement the task as an endless loop.
 *    - Produce the events periodically in every second.
 */
static void prvTaskSignalProducer(void *pvParam) {
}

/*
 * This task consumes the events
 *
 * TODO:
 *    - Implement the task as an endless loop.
 *    - Try to take the semaphore.
 *    - Print a message if the semaphore has been successfully taken.
 */
static void prvTaskSignalConsumer(void *pvParam) {
}
