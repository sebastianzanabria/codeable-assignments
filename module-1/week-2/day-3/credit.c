#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n;
    int digitMul2, nTEN12, nTEN13, nTEN14, nTEN15;
    bool isAE, isMC, isVisa;

    long TEN12 = pow(10, 12); // Twelve zeros
    int sumLast = 0, sumSecondLast = 0, c = 0; 
    
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

    nTEN12 = n / TEN12;
    nTEN13 = n / (TEN12 * 10);
    nTEN14 = n / (TEN12 * 10 * 10);
    nTEN15 = n / (TEN12 * 10 * 10 * 10);
    isAE = nTEN13 == 34 || nTEN13 == 37; //Looks like American Express?
    isMC = nTEN14 >= 51 && nTEN14 <= 55; //Looks like Mastercard?
    isVisa = nTEN12 == 4 || nTEN15 == 4; //Looks like Visa?

    if (isAE || isMC || isVisa) //Looks like a Credit Card?
    {
        while (n != 0) // Here begins sum of numbers
        {
            if (c % 2 == 0) 
            {
                sumLast += n % 10; //not need multiply by 2
            } 
            else
            {
                digitMul2 = 2 * (n % 10); // Biggest number: 18
                if (digitMul2 > 9) //Warning: it is two-digit number
                {
                    sumSecondLast += digitMul2 % 10 + 1; // IMPORTANT: first digit always one 
                }
                else
                {
                    sumSecondLast += digitMul2;
                }
            } 
            n /= 10; //chunk number
            c++; // next number
        }
        if ((sumLast + sumSecondLast) % 10 == 0) // Is it valid?
        {
            if (isAE)
            {
                printf("AMEX\n");
            }
            else if (isMC)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("VISA\n");
            }

        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
