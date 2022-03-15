/*
 * Name:
 *     Synchronizing tasks with a queue (sending a message)
 *
 * Description:
 *     - a FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A)
 *     - There are two tasks. One is sending a message via a queue and the other
 *       is waiting for this message.
 *     - The sender task is supposed to send a message (a value incremented by
 *       one) once in every second
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
// TODO: include header for queue API --> "queue.h"


/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_MESSAGE_SENDER_PRIORITY    ( tskIDLE_PRIORITY + 2 )
#define  mainTASK_MESSAGE_SENDER_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_MESSAGE_RECEIVER_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_MESSAGE_RECEIVER_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

/*
 * TODO: define a variable for the queue used to convey the message.
 * Use type "QueueHandle_t".
*/


/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskMessageSender(void *pvParam);
static void prvTaskMessageReceiver(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {
    // Initialize starter kit
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);

    // Initialize FreeRTOS

        /*
         * TODO: create the queue used to convey the messages.
         * Use function "xQueueCreate()".
        */


        // Create the message sender task
        xTaskCreate(
                prvTaskMessageSender,
                "Message Sender",
                mainTASK_MESSAGE_SENDER_STACK_SIZE,
                NULL,
                mainTASK_MESSAGE_SENDER_PRIORITY,
                NULL);

        // Create the message receiver task
        xTaskCreate(
                prvTaskMessageReceiver,
                "Message Receiver",
                mainTASK_MESSAGE_RECEIVER_STACK_SIZE,
                NULL,
                mainTASK_MESSAGE_RECEIVER_PRIORITY,
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
 * This task sends the messages (a number incremented by one each second).
 */
static void prvTaskMessageSender(void *pvParam) {

uint32_t cntr = 0;

    while (1) {

        vTaskDelay(configTICK_RATE_HZ);
        /*
         * TODO: send the message via the queue.
         * Use function "xQueueSend()".
        */

        cntr++;
    }
}

/*
 * This task receives the messages.
 */
static void prvTaskMessageReceiver(void *pvParam) {
uint32_t cntr;

    while (1) {
        /*
         * TODO: receive the message from queue.
         * Use function "xQueueReceive()".
        */

        printf("Received number: %lu\n", cntr);
    }
}
