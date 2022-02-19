#include "charger.h"
#include "system.h"

int main(void)
{
    clockTo16Hsi();
    chrgInit();
    while(1);
}
