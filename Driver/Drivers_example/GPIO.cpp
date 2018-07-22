/*
 * GPIO.cpp
 *
 *  Created on: 4 juil. 2018
 *      Author: Administrator
 */
#include "GPIO.h"
#include "assert.h"
RCC_TypeDef RCC_reg;
RCC_TypeDef* RCC = &RCC_reg;

void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{
	assert(IS_RCC_APB2_PERIPH(RCC_APB2Periph));
	assert(IS_FUNCTIONAL_STATE(NewState));
	if (NewState != DISABLE){
		RCC->APB2ENR |= RCC_APB2Periph;
	}
	else{
		RCC->APB2ENR &= ~RCC_APB2Periph;
	}
}

void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct){

}


void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	/* Check the parameters */
	assert(IS_GPIO_ALL_PERIPH(GPIOx));
	assert(IS_GPIO_PIN(GPIO_Pin));
	GPIOx->BSRR = GPIO_Pin;
}

void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	/* Check the parameters */
	assert(IS_GPIO_ALL_PERIPH(GPIOx));
	assert(IS_GPIO_PIN(GPIO_Pin));

	GPIOx->BRR = GPIO_Pin;
}

uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
{
	/* Check the parameters */
	assert(IS_GPIO_ALL_PERIPH(GPIOx));

	return ((uint16_t)GPIOx->IDR);
}

uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	uint8_t bitstatus = 0x00;
	/* Check the parameters */
	assert(IS_GPIO_ALL_PERIPH(GPIOx));
	assert(IS_GET_GPIO_PIN(GPIO_Pin));

	if ((GPIOx->ODR & GPIO_Pin) != (uint32_t)Bit_RESET)
	{
		bitstatus = (uint8_t)Bit_SET;
	}
	else
	{
		bitstatus = (uint8_t)Bit_RESET;
	}
	return bitstatus;
}

uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
{
	/* Check the parameters */
	assert(IS_GPIO_ALL_PERIPH(GPIOx));

	return ((uint16_t)GPIOx->ODR);
}

void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{
	/* Check the parameters */
	assert(IS_GPIO_ALL_PERIPH(GPIOx));
	assert(IS_GET_GPIO_PIN(GPIO_Pin));
	assert(IS_GPIO_BIT_ACTION(BitVal));

	if (BitVal != Bit_RESET)
	{
		GPIOx->BSRR = GPIO_Pin;
	}
	else
	{
		GPIOx->BRR = GPIO_Pin;
	}
}

void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal)
{
	/* Check the parameters */
	assert(IS_GPIO_ALL_PERIPH(GPIOx));

	GPIOx->ODR = PortVal;
}

void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	uint32_t tmp = 0x00010000;

	/* Check the parameters */
	assert(IS_GPIO_ALL_PERIPH(GPIOx));
	assert(IS_GPIO_PIN(GPIO_Pin));

	tmp |= GPIO_Pin;
	/* Set LCKK bit */
	GPIOx->LCKR = tmp;
	/* Reset LCKK bit */
	GPIOx->LCKR = GPIO_Pin;
	/* Set LCKK bit */
	GPIOx->LCKR = tmp;
	/* Read LCKK bit*/
	tmp = GPIOx->LCKR;
	/* Read LCKK bit*/
	tmp = GPIOx->LCKR;
}

void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource)
{
	uint32_t tmpreg = 0x00;
	/* Check the parameters */
	assert(IS_GPIO_EVENTOUT_PORT_SOURCE(GPIO_PortSource));
	assert(IS_GPIO_PIN_SOURCE(GPIO_PinSource));

	tmpreg = AFIO->EVCR;
	/* Clear the PORT[6:4] and PIN[3:0] bits */
	tmpreg &= EVCR_PORTPINCONFIG_MASK;
	tmpreg |= (uint32_t)GPIO_PortSource << 0x04;
	tmpreg |= GPIO_PinSource;
	AFIO->EVCR = tmpreg;
}
