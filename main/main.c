#include "main.h"

static void pcCOM_task(void *arg)
{
	UART_init();
    while (1) {
		UART_send(msgTx_PC);
		sprintf(msgTx_PC,"sent");
		vTaskSuspend(UARTHandle);
    }
}
static void IMU_task (void *arg){
	MPU9250_init();
	MPU9250_WhoAmI(&WhoAmI_);
	if (WhoAmI_ == 0x71){
		sprintf(msgTx_PC,"NO ERROR\r\n");
		vTaskResume(UARTHandle);		
	}else{
		sprintf(msgTx_PC,"ERROR, not running");		
		vTaskResume(UARTHandle);
	}

	while(1){
		MPU9250_get_acc(&accX,&accY,&accZ);
		sprintf(msgTx_PC,"AccX:%d\tAccY:%d\tAccZ:%d\t\r\n",accX,accY,accZ);
		vTaskResume(UARTHandle);
		vTaskDelay(pdMS_TO_TICKS(50));
	}
	
}
void app_main(void)
{

    xTaskCreate(pcCOM_task, "pcCOM", 1024, NULL, 3, &UARTHandle);
	xTaskCreate(IMU_task, "IMU", 2048, NULL, 5, &IMUHandle);
}
