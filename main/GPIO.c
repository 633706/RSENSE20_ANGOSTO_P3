#include "GPIO.h"
void LED_init(void){
	gpio_config_t LED_config = {
		.pin_bit_mask = GPIO_SEL_33,
		.intr_type = GPIO_INTR_DISABLE,
		.mode = GPIO_MODE_OUTPUT,
		.pull_up_en = GPIO_PULLUP_DISABLE,
		.pull_down_en = GPIO_PULLDOWN_DISABLE,
	};
	
	gpio_config(&LED_config);
	LED_OFF();
}

void LED_ON(void){
	gpio_set_level(GPIO_NUM_33,1);
}
void LED_OFF(void){
	gpio_set_level(GPIO_NUM_33,0);
}
