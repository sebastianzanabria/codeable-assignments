#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float float_ch;//original change
    int ch;
    int qty_coins = 0;
    do
    {
        float_ch = get_float("Change owed: ");
        ch = round(float_ch * 100); //change in cents
    }
    while (ch < 1);//at least 1 cent
    if (ch >= 25)
    {
        qty_coins += ch / 25;
        ch %= 25;
    }
    if (ch >= 10)
    {
        qty_coins += ch / 10;        
        ch %= 10;
    }
    if (ch >= 5)
    {
        qty_coins += ch / 5;        
        ch %= 5;
    }
    qty_coins += ch;//remainder coins
    printf("%i\n", qty_coins);
}