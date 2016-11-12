#include "stm32f4xx_conf.h"
#include "GPIO.h"


int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	SystemInit();
	initPortB(GPIO_InitStructure);

    while(1)
    {

    }
}
