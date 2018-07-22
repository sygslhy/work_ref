
typedef enum {
	LED_OFF = 0,
	LED_ON  = 1
} E_LED_STATUS;

void led_power_on_config(void);

void led_init();

void led_turn_on(int number);

void led_turn_off(int number);

int led_get_status(int number);

int add(int a, int b);

int sub(int a, int b);
