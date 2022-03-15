/*
 * Name:
 *     Using interrupts with FreeRTOS
 *
 * Description:
 *     - A FreeRTOS example application for the Silicon Labs
 *       EFM32 Giant Gecko Starter Kit (STK3700A).
 *     - This application consists of an ISR and two tasks.
 *        - ISR
 *            Configured for an external IT (caused by pressing PB0).
 *            After acknowledgment of the IT a semaphore is given.
 *        - TaskPB0
 *            Waits for the semaphore. If received increments a counter.
 *            The value of the counter is then printed to the standard output.
 *        - TaskLED
 *            Blinks a LED periodically for heartbeat purposes.
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
// TODO: include em_gpio.h


// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* --------------------------------------------------------------------------
   DEFINES
-------------------------------------------------------------------------- */

#define  mainTASK_PB0_PRIORITY    ( tskIDLE_PRIORITY + 2 )
#define  mainTASK_PB0_STACK_SIZE  configMINIMAL_STACK_SIZE

#define  mainTASK_LED_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define  mainTASK_LED_STACK_SIZE  configMINIMAL_STACK_SIZE

/* --------------------------------------------------------------------------
   VARIABLES
-------------------------------------------------------------------------- */

SemaphoreHandle_t semPB0;

/* --------------------------------------------------------------------------
   FUNCTION DECLARATIONS
-------------------------------------------------------------------------- */

static void prvTaskPB0(void *pvParam);
static void prvTaskLED(void *pvParam);

/* --------------------------------------------------------------------------
   MAIN
-------------------------------------------------------------------------- */

int main(void) {
    // Initialize starter kit

        // Initialize standard I/O
        RETARGET_SerialInit();
        RETARGET_SerialCrLf(1);

        // Initialize LEDs
        BSP_LedsInit();

        // Initialize GPIO

        /*
         * TODO: set pin 9 of port B to input with no pull-up/down or filter
         *    - Use function GPIO_PinModeSet()
         *    - For possible port names and modes see "em_gpio.h"
         */


        /*
         * TODO: enable falling-edge interrupt for pin 9 of port B
         *    - Use function GPIO_ExtIntConfig()
         *    - IT number should be the same as the pin number
         */


        // Initialize NVIC

        /*
         * TODO: enable odd GPIO IRQ
         *    - Use function NVIC_EnableIRQ()
         *    - See "efm32gg990f1024.h" for possible IRQ number definitions
         */


        /*
         * TODO: set priority for odd GPIO IRQ
         *    - Use function NVIC_SetPriority()
         *    - The highest possible priority level (equals to the lowest
         *      possible number) for interrupts from which FreeRTOS API calls
         *      are permitted is defined by configMAX_SYSCALL_INTERRUPT_PRIORITY
         */
        NVIC_SetPriority(GPIO_ODD_IRQn, configMAX_SYSCALL_INTERRUPT_PRIORITY);

        /*
         * TODO: assign all the priority bits to be preempt priority bits,
         * leaving no priority bits as subpriority bits.
         *    - Use function NVIC_SetPriorityGrouping()
         *    - Pass 0 as the parameter
         * NOTE: this step is optional as currently subpriority bits are
         * disabled by default.
         */
        NVIC_SetPriorityGrouping(0);

    // End of starter kit initialization


    // Initialize FreeRTOS

        // Create semaphore
        semPB0 = xSemaphoreCreateBinary();

        // Create tasks
        xTaskCreate(prvTaskPB0, "", mainTASK_PB0_STACK_SIZE, NULL, mainTASK_PB0_PRIORITY, NULL);
        xTaskCreate(prvTaskLED, "", mainTASK_LED_STACK_SIZE, NULL, mainTASK_LED_PRIORITY, NULL);

        // Start the scheduler
        vTaskStartScheduler();

    // Prevent compiler warning
    return 0;
}

/* --------------------------------------------------------------------------
   FUNCTION DEFINITIONS
-------------------------------------------------------------------------- */

/*
 * Task counting button presses
 */
static void prvTaskPB0(void *pvParam) {

static uint32_t cntr = 0;

    while (1) {
        /*
         * TODO: take the semaphore
         */

        printf("Button presses: %lu\n", ++cntr);
    }
}

/*
 * Task blinking a LED
 */
static void prvTaskLED(void *pvParam) {

    while (1) {
        vTaskDelay(configTICK_RATE_HZ / 2);
        BSP_LedToggle(0);
    }
}

/*
 * GPIO (odd) IRQ handler
 */
void GPIO_ODD_IRQHandler(void) {
/*
 * TODO: create a variable with type "BaseType_t" to store if a higher priority
 * task should be woken. Initial value should be "pdFALSE".
 *
 * Note: this is needed only if we want to trigger an immediate context switch
 * at the end of the ISR by invoking portYIELD_FROM_ISR(). Otherwise the context
 * switch will occur at the next systick ISR.
 */
BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /*
     * TODO: clear the interrupt
     *    - Use function GPIO_IntClear()
     *    - As the parameter create a mask with the 9th bit set
     */


    /*
     * TODO: give the semaphore
     *    - Use the interrupt safe API call xSemaphoreGiveFromISR()
     *    - Pass a pointer to the variable created above (optional, can be NULL)
     */


    /*
     * TODO: initiate an immediate context switch
     *    - Use macro portYIELD_FROM_ISR()
     *    - Pass the variable as the argument
     *
     * Note: this step is needed only if the variable has been created and the
     * pointer to it has been passed to the function giving the semaphore.
     */

}
