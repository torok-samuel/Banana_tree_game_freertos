/*
 * Name:
 *     Event flags
 *
 * Description:
 *     - a FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A)
 *     - There are three tasks. One is receiving either of two event flags and
 *       the other tasks signal these flags.
 *     - This example needs the "event_groups.c" FreeRTOS source file too.
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
// TODO: include "event_groups.h"

/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_FLAG_SENDER_1_PRIORITY    ( tskIDLE_PRIORITY + 3 )
#define  mainTASK_FLAG_SENDER_1_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_FLAG_SENDER_2_PRIORITY    ( tskIDLE_PRIORITY + 2 )
#define  mainTASK_FLAG_SENDER_2_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_FLAG_RECEIVER_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_FLAG_RECEIVER_STACK_SIZE  configMINIMAL_STACK_SIZE

// TODO: define FLAG0 (and FLAG1) as a value having bit0 (bit1) set as 1 and all
// other bits as 0. Hint: use binary shift operator!

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

/*
 * TODO: define a variable for the event group
 * Use type EventGroupHandle_t
*/

/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskFlagSender1(void *pvParam);
static void prvTaskFlagSender2(void *pvParam);
static void prvTaskFlagReceiver(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {

    // Initialize starter kit
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);

    // Initialize FreeRTOS

        /*
         * TODO: create the event group
         * Use function xEventGroupCreate().
        */

        // Create the flag sender 1 task
        xTaskCreate(
                prvTaskFlagSender1,
                "Flag Sender 1",
                mainTASK_FLAG_SENDER_1_STACK_SIZE,
                NULL,
                mainTASK_FLAG_SENDER_1_PRIORITY,
                NULL);

        // Create the flag sender 2 task
        xTaskCreate(
                prvTaskFlagSender2,
                "Flag Sender 2",
                mainTASK_FLAG_SENDER_2_STACK_SIZE,
                NULL,
                mainTASK_FLAG_SENDER_2_PRIORITY,
                NULL);

        // Create the flag receiver task
        xTaskCreate(
                prvTaskFlagReceiver,
                "Flag Receiver",
                mainTASK_FLAG_RECEIVER_STACK_SIZE,
                NULL,
                mainTASK_FLAG_RECEIVER_PRIORITY,
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
 * This task sends one of the flags.
 * The flag is set once in every 600 ms.
*/
static void prvTaskFlagSender1(void *pvParam) {

    while (1) {
        // Wait 600 ms
        vTaskDelay( 600 * configTICK_RATE_HZ / 1000 );

        /*
         * TODO: set one of the flags (for example bit 0)
         * Use function xEventGroupSetBits().
        */
    }
}

/*
 * This task sends the other flag.
 * The flag is set once in every 400 ms.
*/
static void prvTaskFlagSender2(void *pvParam) {

    while (1) {
        // Wait 400 ms
        vTaskDelay( 400 * configTICK_RATE_HZ / 1000 );

        /*
         * TODO: set an other flag (for example bit 1)
         * Use function xEventGroupSetBits().
        */
    }
}

/*
 * This task receives the event flags.
*/
static void prvTaskFlagReceiver(void *pvParam) {

	EventBits_t  received_flags;

    while (1) {

        /*
         * TODO: receive either of the flags (e.g. logical 'OR' wait on both
         * flags). Flags should be cleared upon reception. And there should be
         * no timeout (use portMAX_DELAY).
         *
         * Use function xEventGroupWaitBits()
        */

        /*
         * TODO: after reception print a message which flag(s) has(have) been
         * received.
         *
         * The expression inside the 'switch' statement should be TRUE if, and
         * only if, FLAG1 or FLAG0 is set. Hint: use binary AND and OR
         * operations.
        */
    	switch ( /* TODO */ ) {
    	case /* TODO: case for FLAG0 */:
    		printf("Flag0 has been received.\n");
    		break;

    	case /* TODO: case for FLAG1 */:
    		printf("Flag1 has been received.\n");
    		break;

    	case /* TODO: case for FLAG0 or FLAG1 */:
    		printf("Flag0 and Flag1 have been received.\n");
    		break;

    	default:
            /*
             * This should normally never happen if timeout is set to
             * portMAX_DELAY and INCLUDE_vTaskSuspend is 1.
            */
			printf("Timeout!\n");
    	}

        // Wait 300 ms
        vTaskDelay( 300 * configTICK_RATE_HZ / 1000 );
    }
}
