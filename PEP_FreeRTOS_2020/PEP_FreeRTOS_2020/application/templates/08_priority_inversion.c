/*
 * Name:
 *     Priority inversion
 *
 * Description:
 *     - a FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A)
 *     - This example demonstrates the priority inversion with three tasks.
 *     - This problem arises when semaphores are used.
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
#include <udelay.h>                 // For UDELAY_Calibrate() and UDELAY_Delay()

// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_H_PRIORITY    ( tskIDLE_PRIORITY + 3 )
#define  mainTASK_H_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_M_PRIORITY    ( tskIDLE_PRIORITY + 2 )
#define  mainTASK_M_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_L_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_L_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
  VARIABLES
-------------------------------------------------------------------------- */

// The binary semaphore guarding the shared resource
SemaphoreHandle_t semaphore;

/* --------------------------------------------------------------------------
  FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskH(void *pvParam);                  // High priority task
static void prvTaskM(void *pvParam);                  // Medium priority task
static void prvTaskL(void *pvParam);                  // Low priority task

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {
    // Initialize starter kit
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);
    UDELAY_Calibrate();

    // Initialize FreeRTOS

        // Create a semaphore and initialize it as free
        semaphore = xSemaphoreCreateBinary();
        xSemaphoreGive(semaphore);

        /*
         * TODO: create a mutex instead of a binary semaphore!
         *    - Use function "xSemaphoreCreateMutex()".
         *    - Note: a mutex is created as free by default.
         */


        // Create the high priority task
        xTaskCreate(
                prvTaskH,
                "High",
                mainTASK_H_STACK_SIZE,
                NULL,
                mainTASK_H_PRIORITY,
                NULL);

        // Create the medium priority task
        xTaskCreate(
                prvTaskM,
                "Medium",
                mainTASK_M_STACK_SIZE,
                NULL,
                mainTASK_M_PRIORITY,
                NULL);

        // Create the low priority task
        xTaskCreate(
                prvTaskL,
                "Low",
                mainTASK_L_STACK_SIZE,
                NULL,
                mainTASK_L_PRIORITY,
                NULL);

        printf("-------------------------------------------------------------------------------\n");
        printf("|    Low priority task    |  Medium priority task   |    High priority task   |\n");
        printf("--------------------------+-------------------------+--------------------------\n");

        // Start the scheduler
        vTaskStartScheduler();

    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
 * FUNCTION DEFINITIONS
 * -------------------------------------------------------------------------- */

static void prvTaskH(void *pvParam) {
    printf("|                         |                         |         Started         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("|                         |                         |  Going to sleep (200ms) |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    vTaskDelay( (200 * configTICK_RATE_HZ) / 1000 );
    printf("|                         |                         |         Waked up        |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("|                         |                         |   Acquiring semaphore   |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    xSemaphoreTake(semaphore, portMAX_DELAY);
    printf("|                         |                         |    Semaphore acquired   |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("|                         |                         |         Exiting         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    vTaskDelete(NULL);

}

static void prvTaskM(void *pvParam) {
    printf("|                         |        Started          |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("|                         |  Going to sleep (100ms) |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    vTaskDelay( (100 * configTICK_RATE_HZ) / 1000 );
    printf("|                         |         Waked up        |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("|                         |Doing something (1000 ms)|                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    // Wait about 1000 ms
    for (uint16_t ms = 0; ms < 1000; ms++) {
        UDELAY_Delay(1000);
    }
    printf("|                         |       Job done          |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("|                         |        Exiting          |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    vTaskDelete(NULL);
}

static void prvTaskL(void *pvParam) {
    printf("|        Started          |                         |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("|   Acquiring semaphore   |                         |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    xSemaphoreTake(semaphore, portMAX_DELAY);
    printf("|   Semaphore acquired    |                         |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("| Doing something (400ms) |                         |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    // Wait about 400 ms
    for (uint16_t ms = 0; ms < 400; ms++) {
        UDELAY_Delay(1000);
    }
    printf("|       Job done          |                         |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");

    printf("|   Releasing semaphore   |                         |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    xSemaphoreGive(semaphore);

    printf("|        Exiting          |                         |                         |\n");
    printf("--------------------------+-------------------------+--------------------------\n");
    vTaskDelete(NULL);
}
