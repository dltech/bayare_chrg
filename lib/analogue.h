
#include "gpio.h"

#define ADC_PORT    GPIOD
#define AMP_PIN     GPIO2
#define VOLT_PIN    GPIO3
#define RV1_PIN     GPIO5
#define RV2_PIN     GPIO6

#define AMP_CH      3
#define VOLT_CH     4
#define RV1_CH      5
#define RV2_CH      6

void analogueInit(void);
