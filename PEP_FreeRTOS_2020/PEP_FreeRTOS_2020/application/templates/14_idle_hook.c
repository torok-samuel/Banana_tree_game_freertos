/*
 * Name:
 *     Using idle hook to put CPU into sleep
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A).
 *     - There is only one task blinking LEDs (only for "heart beat" purposes).
 *     - By implementing the idle hook function in such a way that we put the
 *       CPU into a sleep mode we can significantly reduce power consumption.
 *
 * Extra:
 *     - It is also worth to try out the tickless idle mode (see
 *       configUSE_TICKLESS_IDLE).
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
#include <bsp.h>
// TODO: include "em_emu.h"


// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"

/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_HEART_BEAT_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_HEART_BEAT_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskHeartBeat(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {

    // Initialize starter kit
    BSP_LedsInit();
    BSP_LedSet(1);

    // Initialize FreeRTOS

        // Create a "heart beat" task
        xTaskCreate(prvTaskHeartBeat, "", mainTASK_HEART_BEAT_STACK_SIZE, NULL, mainTASK_HEART_BEAT_PRIORITY, NULL);

        // Start the scheduler --> vTaskStartScheduler()
        vTaskStartScheduler();

    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
   FUNCTION DEFINITIONS
-------------------------------------------------------------------------- */

static void prvTaskHeartBeat(void *pvParam) {
    while (1) {
        vTaskDelay(configTICK_RATE_HZ);
        BSP_LedToggle(0);
        BSP_LedToggle(1);
    }
}

// TODO: implement vApplicationIdleHook() and put the MCU into sleep mode EM1!
