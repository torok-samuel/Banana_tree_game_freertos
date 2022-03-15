 /*
 * Name:
 *     Using direct to task notifications in FreeRTOS
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A).
 *     - This application consists of five tasks: one is producing notifications
 *       and the other four receives them.
 *     - The difference between the consumers is the way they treat these
 *       notifications. The possibilities are:
 *        - binary semaphore
 *        - counting semaphore
 *        - event flags
 *        - mailbox
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
#include <bsp.h>
#include <bsp_stk_buttons.h>
#include <em_gpio.h>

// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_PRODUCER_PRIORITY             ( tskIDLE_PRIORITY + 5 )
#define  mainTASK_PRODUCER_STACK_SIZE           configMINIMAL_STACK_SIZE

#define  mainTASK_CONSUMER_BINARY_PRIORITY      ( tskIDLE_PRIORITY + 4 )
#define  mainTASK_CONSUMER_BINARY_STACK_SIZE    configMINIMAL_STACK_SIZE

#define  mainTASK_CONSUMER_COUNTING_PRIORITY    ( tskIDLE_PRIORITY + 3 )
#define  mainTASK_CONSUMER_COUNTING_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_CONSUMER_FLAGS_PRIORITY       ( tskIDLE_PRIORITY + 2 )
#define  mainTASK_CONSUMER_FLAGS_STACK_SIZE     configMINIMAL_STACK_SIZE

#define  mainTASK_CONSUMER_MBOX_PRIORITY        ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_CONSUMER_MBOX_STACK_SIZE      configMINIMAL_STACK_SIZE

// TODO: define bit masks for push buttons (for example LSB could refer to PB0
// and the bit next to LSB to PB1).

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

TaskHandle_t handleBinary;
TaskHandle_t handleCounting;
TaskHandle_t handleFlags;
TaskHandle_t handleMBox;

/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskProducer(void *pvParam);
static void prvTaskConsumerBinary(void *pvParam);
static void prvTaskConsumerCounting(void *pvParam);
static void prvTaskConsumerFlags(void *pvParam);
static void prvTaskConsumerMBox(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {
    // Starter kit initialization -->

        // Initialize standard I/O
        RETARGET_SerialInit();
        RETARGET_SerialCrLf(1);

        // Initialize LEDs
        BSP_LedsInit();

        // Initialize buttons
        BSP_ButtonsInit();

    // <-- Starter kit initialization


    // FreeRTOS initialization -->

        // Create tasks
        xTaskCreate(
                prvTaskProducer,
                "",
                mainTASK_PRODUCER_STACK_SIZE,
                NULL,
                mainTASK_PRODUCER_PRIORITY,
                NULL
        );

        xTaskCreate(
                prvTaskConsumerBinary,
                "",
                mainTASK_CONSUMER_BINARY_STACK_SIZE,
                NULL,
                mainTASK_CONSUMER_BINARY_PRIORITY,
                &handleBinary
        );

        xTaskCreate(
                prvTaskConsumerCounting,
                "",
                mainTASK_CONSUMER_COUNTING_STACK_SIZE,
                NULL,
                mainTASK_CONSUMER_COUNTING_PRIORITY,
                &handleCounting
        );

        xTaskCreate(
                prvTaskConsumerFlags,
                "",
                mainTASK_CONSUMER_FLAGS_STACK_SIZE,
                NULL,
                mainTASK_CONSUMER_FLAGS_PRIORITY,
                &handleFlags
        );

        xTaskCreate(
                prvTaskConsumerMBox,
                "",
                mainTASK_CONSUMER_MBOX_STACK_SIZE,
                NULL,
                mainTASK_CONSUMER_MBOX_PRIORITY,
                &handleMBox
        );

        // Start the scheduler
        vTaskStartScheduler();

    // <-- FreeRTOS initialization

    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
   FUNCTION DEFINITIONS
-------------------------------------------------------------------------- */

/*
 * Task producing notifications
 */
static void prvTaskProducer(void *pvParam) {

    uint32_t cnt = 0;

    while (1) {
        printf("-------------------------------\n");

        // TODO: make a binary semaphore like notification to TaskConsumerBinary
        // (use function xTaskNotifyGive()).
        // Variant: see what happens if the notification is made twice!

        // TODO: make a counting semaphore like notification _twice_ to
        // TaskConsumerCounting (use function xTaskNotifyGive()).

        // TODO: make an event flags like notification to TaskConsumerFlags
        // (use function xTaskNotify()). Set a bit if PB0 is pressed.
        if (BSP_ButtonGet(0) == 0) {

        }

        // TODO: make an event flags like notification to TaskConsumerFlags
        // (use function xTaskNotify()). Set an other bit if PB1 is pressed.
        if (BSP_ButtonGet(1) == 0) {

        }

        // TODO: make a mail box like notification to TaskConsumerMBox
        // (use function xTaskNotify). Put a counter variable as the
        // notification value (then increment the variable).

        vTaskDelay(configTICK_RATE_HZ);
    }
}

/*
 * Task consuming notifications treated as a binary semaphore
 */
static void prvTaskConsumerBinary(void *pvParam) {

    while (1) {
        // TODO: wait for a notification (use function ulTaskNotifyTake()).

        printf("Binary: taken\n");
    }
}

/*
 * Task consuming notifications treated as a counting semaphore
 */
static void prvTaskConsumerCounting(void *pvParam) {

    while (1) {
        // TODO: wait for a notification (use function ulTaskNotifyTake()).
        // Decrement counter on exit!

        printf("Counting: taken\n");
    }
}

/*
 * Task consuming notifications treated as event flags
 */
static void prvTaskConsumerFlags(void *pvParam) {

    uint32_t notificationValue;

    while (1) {
        // TODO: wait for a notification (use function xTaskNotifyWait()).
        // Do _not_ clear the value upon entry but _do_ clear all bits upon
        // exit!


        if ( /* Test for bit referring to PB0 */  ) {
            printf("Flags: PB0 is pressed\n");
        }

        if ( /* Test for bit referring to PB1 */  ) {
            printf("Flags: PB1 is pressed\n");
        }
    }
}

/*
 * Task consuming notifications treated as a mailbox
 */
static void prvTaskConsumerMBox(void *pvParam) {

    uint32_t notificationValue;

    while (1) {
        // TODO: wait for a notification (use function xTaskNotifyWait()).
        // Do _not_ clear the value upon entry but _do_ clear all bits upon
        // exit!

        printf("MBox: received value is %lu\n", notificationValue);
    }
}
