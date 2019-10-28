#include"Delay.h"


void Delay_ms(uint16_t T)
{
    uint16_t i,j;
    for(i=T;i>0;i--)
    for(j=257;j>0;j--);
}
void Delay_us(uint16_t T)
{

}
