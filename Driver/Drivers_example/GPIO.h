/** @GPIO.h */

/*! \brief
 *   GPIO.h
 *
 *   Created on: 4 juil. 2018
 *      Author: Administrator
 */

#ifndef GPIO_H_
#define GPIO_H_

#define __IO       volatile
typedef  unsigned int uint32_t;
typedef  unsigned short uint16_t;
typedef  unsigned char uint8_t;

typedef enum  BitAction {
	Bit_RESET = 0,
	Bit_SET
} BitAction;
#define 	IS_GPIO_BIT_ACTION(ACTION)  (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))

typedef enum {
	DISABLE = 0,
	ENABLE  = 1
} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE)   (((STATE) == DISABLE) || ((STATE) == ENABLE))

/** struct of gpio register */
typedef struct
{
	__IO uint32_t CRL; //端口配置低寄存器
	__IO uint32_t CRH; //端口配置高寄存器
	__IO uint32_t IDR; //端口输入寄存器
	__IO uint32_t ODR; //端口输出寄存器
	__IO uint32_t BSRR; //端口位设置/清除寄存器
	__IO uint32_t BRR; //端口位清除寄存器
	__IO uint32_t LCKR; //端口配置锁存寄存器
} GPIO_TypeDef;

//复用功能寄存器结构：
typedef struct
{
	__IO uint32_t EVCR;
	__IO uint32_t MAPR;
	__IO uint32_t EXTICR[4];
}AFIO_TypeDef;

#define PERIPH_BASE         ((uint32_t)0x40000000) /* 外设基地址 */

/* 总线基地址 */
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE      (PERIPH_BASE + 0x20000)

/*寄存器组基地址*/
#define GPIOA_BASE          (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE          (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE          (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE          (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE          (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE          (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE          (APB2PERIPH_BASE + 0x2000)

#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *) GPIOG_BASE)

#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
                                    ((PERIPH) == GPIOB) || \
                                    ((PERIPH) == GPIOC) || \
                                    ((PERIPH) == GPIOD) || \
                                    ((PERIPH) == GPIOE) || \
                                    ((PERIPH) == GPIOF))




#define GPIO_Pin_0 ((uint16_t)0x0001) //!< Pin 0 selected /
#define GPIO_Pin_1 ((uint16_t)0x0002) //!< Pin 1 selected /
#define GPIO_Pin_2 ((uint16_t)0x0004) //!< Pin 2 selected /
#define GPIO_Pin_3 ((uint16_t)0x0008) //!< Pin 3 selected /
#define GPIO_Pin_4 ((uint16_t)0x0010) //!< Pin 4 selected /
#define GPIO_Pin_5 ((uint16_t)0x0020) //!< Pin 5 selected /
#define GPIO_Pin_6 ((uint16_t)0x0040) //!< Pin 6 selected /
#define GPIO_Pin_7 ((uint16_t)0x0080) //!< Pin 7 selected /
#define GPIO_Pin_8 ((uint16_t)0x0100) //!< Pin 8 selected /
#define GPIO_Pin_9 ((uint16_t)0x0200) //!< Pin 9 selected /
#define GPIO_Pin_10 ((uint16_t)0x0400) //!< Pin 10 selected /
#define GPIO_Pin_11 ((uint16_t)0x0800) //!< Pin 11 selected /
#define GPIO_Pin_12 ((uint16_t)0x1000) //!< Pin 12 selected /
#define GPIO_Pin_13 ((uint16_t)0x2000) //!< Pin 13 selected /
#define GPIO_Pin_14 ((uint16_t)0x4000) //!< Pin 14 selected /
#define GPIO_Pin_15 ((uint16_t)0x8000) //!< Pin 15 selected /
#define GPIO_Pin_All ((uint16_t)0xFFFF) //!< All pins selected /

#define IS_GET_GPIO_PIN(PIN)  (((PIN) == GPIO_Pin_0) || \
        						((PIN) == GPIO_Pin_1) || \
								((PIN) == GPIO_Pin_2) || \
								((PIN) == GPIO_Pin_3) || \
								((PIN) == GPIO_Pin_4) || \
								((PIN) == GPIO_Pin_5) || \
								((PIN) == GPIO_Pin_6) || \
								((PIN) == GPIO_Pin_7) || \
								((PIN) == GPIO_Pin_8) || \
								((PIN) == GPIO_Pin_9) || \
								((PIN) == GPIO_Pin_10) || \
								((PIN) == GPIO_Pin_11) || \
								((PIN) == GPIO_Pin_12) || \
								((PIN) == GPIO_Pin_13) || \
								((PIN) == GPIO_Pin_14) || \
								((PIN) == GPIO_Pin_15))
#define IS_GPIO_PIN(PIN)   ((((PIN) & (uint16_t)0x00) == 0x00) && ((PIN) != (uint16_t)0x00))


//AHB1 periph enable clock
#define RCC_AHB1Periph_GPIOA             ((uint32_t)0x00000001)
#define RCC_AHB1Periph_GPIOB             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOC             ((uint32_t)0x00000004)
#define RCC_AHB1Periph_GPIOD             ((uint32_t)0x00000008)
#define RCC_AHB1Periph_GPIOE             ((uint32_t)0x00000010)
#define RCC_AHB1Periph_GPIOF             ((uint32_t)0x00000020)
#define RCC_AHB1Periph_GPIOG             ((uint32_t)0x00000040)
#define RCC_AHB1Periph_GPIOH             ((uint32_t)0x00000080)
#define RCC_AHB1Periph_GPIOI             ((uint32_t)0x00000100)
#define RCC_AHB1Periph_GPIOJ             ((uint32_t)0x00000200)
#define RCC_AHB1Periph_GPIOK             ((uint32_t)0x00000400)
#define RCC_AHB1Periph_CRC               ((uint32_t)0x00001000)
#define RCC_AHB1Periph_FLITF             ((uint32_t)0x00008000)
#define RCC_AHB1Periph_SRAM1             ((uint32_t)0x00010000)
#define RCC_AHB1Periph_SRAM2             ((uint32_t)0x00020000)
#define RCC_AHB1Periph_BKPSRAM           ((uint32_t)0x00040000)
#define RCC_AHB1Periph_SRAM3             ((uint32_t)0x00080000)
#define RCC_AHB1Periph_CCMDATARAMEN      ((uint32_t)0x00100000)
#define RCC_AHB1Periph_DMA1              ((uint32_t)0x00200000)
#define RCC_AHB1Periph_DMA2              ((uint32_t)0x00400000)
#define RCC_AHB1Periph_DMA2D             ((uint32_t)0x00800000)
#define RCC_AHB1Periph_ETH_MAC           ((uint32_t)0x02000000)
#define RCC_AHB1Periph_ETH_MAC_Tx        ((uint32_t)0x04000000)
#define RCC_AHB1Periph_ETH_MAC_Rx        ((uint32_t)0x08000000)
#define RCC_AHB1Periph_ETH_MAC_PTP       ((uint32_t)0x10000000)
#define RCC_AHB1Periph_OTG_HS            ((uint32_t)0x20000000)
#define RCC_AHB1Periph_OTG_HS_ULPI       ((uint32_t)0x40000000)

//APB2 periph enable clock
#define 	RCC_APB2Periph_AFIO    ((uint32_t)0x00000001)
#define 	RCC_APB2Periph_GPIOA   ((uint32_t)0x00000004)
#define 	RCC_APB2Periph_GPIOB   ((uint32_t)0x00000008)
#define 	RCC_APB2Periph_GPIOC   ((uint32_t)0x00000010)
#define 	RCC_APB2Periph_GPIOD   ((uint32_t)0x00000020)
#define 	RCC_APB2Periph_GPIOE   ((uint32_t)0x00000040)
#define 	RCC_APB2Periph_GPIOF   ((uint32_t)0x00000080)
#define 	RCC_APB2Periph_GPIOG   ((uint32_t)0x00000100)
#define 	RCC_APB2Periph_ADC1    ((uint32_t)0x00000200)
#define 	RCC_APB2Periph_ADC2    ((uint32_t)0x00000400)
#define 	RCC_APB2Periph_TIM1    ((uint32_t)0x00000800)
#define 	RCC_APB2Periph_SPI1    ((uint32_t)0x00001000)
#define 	RCC_APB2Periph_TIM8    ((uint32_t)0x00002000)
#define 	RCC_APB2Periph_USART1  ((uint32_t)0x00004000)
#define 	RCC_APB2Periph_ADC3    ((uint32_t)0x00008000)
#define 	RCC_APB2Periph_TIM15   ((uint32_t)0x00010000)
#define 	RCC_APB2Periph_TIM16   ((uint32_t)0x00020000)
#define 	RCC_APB2Periph_TIM17   ((uint32_t)0x00040000)
#define 	RCC_APB2Periph_TIM9    ((uint32_t)0x00080000)
#define 	RCC_APB2Periph_TIM10   ((uint32_t)0x00100000)
#define 	RCC_APB2Periph_TIM11   ((uint32_t)0x00200000)
#define 	IS_RCC_APB2_PERIPH(PERIPH)   ((((PERIPH) & 0xFFC00002) == 0x00) && ((PERIPH) != 0x00))


/**
* @brief Configuration Mode enumeration
*/
typedef enum
{
	GPIO_Mode_AIN = 0x0, /* 模拟输入 */
	GPIO_Mode_IN_FLOATING = 0x04, /* 输入浮空 */
	GPIO_Mode_IPD = 0x28, /* 输入下拉 */
	GPIO_Mode_IPU = 0x48, /* 输入上拉 */
	GPIO_Mode_Out_OD = 0x14, /* 开漏输出 */
	GPIO_Mode_Out_PP = 0x10, /* 推挽式输出 */
	GPIO_Mode_AF_OD = 0x1C, /* 开漏复用 输出 */
	GPIO_Mode_AF_PP = 0x18 /* 推挽式复用 输出 */
}GPIOMode_TypeDef;

/**
举个栗子：
①　USART串口，若最大波特率只需115.2k，那用2M的速度就够了，既省电也噪声小。
②　I2C接口，若使用400k波特率，若想把余量留大些，可以选用10M的GPIO引脚速度。
③　SPI接口，若使用18M或9M波特率，需要选用50M的GPIO的引脚速度
*/
typedef enum
{
	GPIO_Speed_10MHz = 1, //最高输出速率10MHz
	GPIO_Speed_2MHz,      //最高输出速率2MHz
	GPIO_Speed_50MHz      //最高输出速率50MHz
}GPIOSpeed_TypeDef;

typedef struct
{
	uint16_t GPIO_Pin; /*!< Specifies the GPIO pins to be configured. This parameter can be any value of @ref GPIO_pins_define */
	GPIOSpeed_TypeDef GPIO_Speed; /*!< Specifies the speed for the selected pins. This parameter can be a value of @ref GPIOSpeed_TypeDef */
	GPIOMode_TypeDef GPIO_Mode; /*!< Specifies the operating mode for the selected pins. This parameter can be a value of @ref GPIOMode_TypeDef */
}GPIO_InitTypeDef;


/** RCC reset clock config 复位时钟控制 */
typedef struct
{

  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  __IO uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
  __IO uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */

} RCC_TypeDef;

#define 	GPIO_PortSourceGPIOA   ((uint8_t)0x00)
#define 	GPIO_PortSourceGPIOB   ((uint8_t)0x01)
#define 	GPIO_PortSourceGPIOC   ((uint8_t)0x02)
#define 	GPIO_PortSourceGPIOD   ((uint8_t)0x03)
#define 	GPIO_PortSourceGPIOE   ((uint8_t)0x04)
#define 	GPIO_PortSourceGPIOF   ((uint8_t)0x05)
#define 	GPIO_PortSourceGPIOG   ((uint8_t)0x06)
#define IS_GPIO_EVENTOUT_PORT_SOURCE(PORTSOURCE) (((PORTSOURCE) == GPIO_PortSourceGPIOA) || \
        										  ((PORTSOURCE) == GPIO_PortSourceGPIOB) || \
												  ((PORTSOURCE) == GPIO_PortSourceGPIOC) || \
												  ((PORTSOURCE) == GPIO_PortSourceGPIOD) || \
												  ((PORTSOURCE) == GPIO_PortSourceGPIOE))

#define 	GPIO_PinSource0   ((uint8_t)0x00)
#define 	GPIO_PinSource1   ((uint8_t)0x01)
#define 	GPIO_PinSource2   ((uint8_t)0x02)
#define 	GPIO_PinSource3   ((uint8_t)0x03)
#define 	GPIO_PinSource4   ((uint8_t)0x04)
#define 	GPIO_PinSource5   ((uint8_t)0x05)
#define 	GPIO_PinSource6   ((uint8_t)0x06)
#define 	GPIO_PinSource7   ((uint8_t)0x07)
#define 	GPIO_PinSource8   ((uint8_t)0x08)
#define 	GPIO_PinSource9   ((uint8_t)0x09)
#define 	GPIO_PinSource10   ((uint8_t)0x0A)
#define 	GPIO_PinSource11   ((uint8_t)0x0B)
#define 	GPIO_PinSource12   ((uint8_t)0x0C)
#define 	GPIO_PinSource13   ((uint8_t)0x0D)
#define 	GPIO_PinSource14   ((uint8_t)0x0E)
#define 	GPIO_PinSource15   ((uint8_t)0x0F)

#define 	IS_GPIO_PIN_SOURCE(PINSOURCE)  (((PINSOURCE) == GPIO_PinSource0) || \
    										((PINSOURCE) == GPIO_PinSource1) || \
    										((PINSOURCE) == GPIO_PinSource2) || \
    										((PINSOURCE) == GPIO_PinSource3) || \
    										((PINSOURCE) == GPIO_PinSource4) || \
    										((PINSOURCE) == GPIO_PinSource5) || \
    										((PINSOURCE) == GPIO_PinSource6) || \
    										((PINSOURCE) == GPIO_PinSource7) || \
    										((PINSOURCE) == GPIO_PinSource8) || \
    										((PINSOURCE) == GPIO_PinSource9) || \
    										((PINSOURCE) == GPIO_PinSource10) || \
    										((PINSOURCE) == GPIO_PinSource11) || \
    										((PINSOURCE) == GPIO_PinSource12) || \
    										((PINSOURCE) == GPIO_PinSource13) || \
    										((PINSOURCE) == GPIO_PinSource14) || \
											((PINSOURCE) == GPIO_PinSource15))

#define AFIO_BASE   (APB2PERIPH_BASE + 0x0000)
#define AFIO   ((AFIO_TypeDef *) AFIO_BASE)

#define AFIO_OFFSET                 (AFIO_BASE - PERIPH_BASE)
#define EVCR_OFFSET                 (AFIO_OFFSET + 0x00)
#define EVOE_BitNumber              ((uint8_t)0x07)
#define PERIPH_BB_BASE   ((uint32_t)0x42000000)
#define EVCR_EVOE_BB   (PERIPH_BB_BASE + (EVCR_OFFSET * 32) + (EVOE_BitNumber * 4))

#define EVCR_PORTPINCONFIG_MASK     ((uint16_t)0xFF80)



void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

void GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);

void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* GPIO_H_ */
