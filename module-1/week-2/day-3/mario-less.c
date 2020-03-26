#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);//at least 1, at most 8
    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < h; i++)
        {
            if (h - i < j + 2)//from left to right, descendent values
            {
                printf("#");//add #
            }
            else
            {
                printf(" ");// add espace
            };
        };
        printf("\n");
    };
}
