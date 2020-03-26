#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < 2 * h + 2; i++)
        {
            if (i - h > j + 2) //after the last #
            {
                break;//no more #
            }
            else if ((i < h || i > h + 1) && -j - 2 < i - h)//hole criteria & left spaces
            {
                printf("#");
            }
            else
            {
                printf(" ");
            };
        };
        printf("\n");
    };
}
