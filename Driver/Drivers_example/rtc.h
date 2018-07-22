
/*!	\file rtc.h
	 RTC driver APIs

     \author  Yuan SUN
     \version 1.0
     \date    2018-07-15
     \copyright DxO Labs
*/

#ifndef RTC_H_
#define RTC_H_

typedef unsigned char uint8_t;

typedef struct _clock_calender_regs_t_ {
	uint8_t	sec;      //!< second
	uint8_t min;      //!< minute
	uint8_t hour;     //!< hour
	uint8_t week;     //!< week
	uint8_t day;      //!< day
	uint8_t month;    //!< month
	uint8_t year;     //!< year
} clock_calender_regs_t;

typedef struct _timer_counter_regs_t_ {
	uint8_t counter_0;
	uint8_t counter_1;
} timer_counter_regs_t;

typedef struct extension_reg_bits_t {
	uint8_t TSEL : 3;  //!< timer select
	uint8_t WADA : 1;
	uint8_t TE   : 1;  //!< timer enable
	uint8_t USEL : 1;  //!< update enable
	uint8_t FSEL : 2;  //!< Fout enable
} extension_reg_bits;

typedef union _extension_reg_t_{
	uint8_t all;
	extension_reg_bits bits;
} extension_reg_t;

typedef struct _flags_reg_bits_t_ {
	uint8_t RSV1 : 1;
	uint8_t VLF  : 1;
	uint8_t RSV2 : 1;
	uint8_t AF   : 1;
	uint8_t TF   : 1;
	uint8_t UF   : 1;
	uint8_t RSV3 : 2;
} flags_reg_bits_t;

typedef union _flags_reg_t_{
	uint8_t all;
	flags_reg_bits_t bits;
} flags_reg_t;

typedef struct _control_reg_bits_t_{
	uint8_t RSV1 : 2;
	uint8_t TSTP : 1;
	uint8_t AIE  : 1;
	uint8_t TIE  : 1;
	uint8_t UIE  : 1;
	uint8_t STOP : 1;
	uint8_t TEST : 1;
} control_reg_bits_t;

typedef union _control_reg_t_{
	uint8_t all;
	control_reg_bits_t bits;
} control_reg_t;


typedef union _week_day_t_{
	uint8_t week;
	uint8_t day;
} week_day_t;

typedef struct _alarm_reg_bits_t_{
	uint8_t min;
	uint8_t hour;
	week_day_t week_day;
} alarm_reg_bits_t;

typedef union _alarm_reg_t_{
	uint8_t all;
	alarm_reg_bits_t bits;
} alarm_reg_t;


typedef struct _irq_control_reg_bits_t_{
	uint8_t FOPIN : 2;
	uint8_t TMPIN : 1;
	uint8_t RSV   : 5;
} irq_control_reg_bits_t;

typedef union _irq_control_reg_t_{
	uint8_t all;
	irq_control_reg_bits_t bits;
} irq_control_reg_t;


#define USER_RAM_SIZE 16
typedef struct _user_ram_reg_t_ {
	uint8_t _user_ram[USER_RAM_SIZE];
} user_ram_reg_t;


//! \addtogroup RTC driver APIs list.
//! @{

//! \brief  config the rtc when power on.
//! \param  none.
//! \retval none.
void rtc_power_on_config(void);

void rtc_init(void);

//! \brief  set rtc when date and time.
//! \param  clock_calender_regs_t.
//! \retval none.
//! \note it is a very import API to learn
void rtc_set_clock_calender(clock_calender_regs_t reg);

void rtc_get_clock_calender(clock_calender_regs_t& reg);

void rtc_set_timer(clock_calender_regs_t reg);

void rtc_get_timer(clock_calender_regs_t reg);

void rtc_set_alarm(clock_calender_regs_t reg);

void rtc_get_alarm(clock_calender_regs_t reg);

void rtc_get_flags(flags_reg_t& flags_reg);

void rtc_set_flags(flags_reg_t flags_reg);

//! @}

#endif /* RTC_H_ */
