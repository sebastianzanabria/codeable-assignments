#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int index, W = 1, L = 0, S = 0;
    float Lpercent, Spercent;

    string text = get_string("Text: ");
    int length =  strlen(text); //length of text

    for (int i = 0; i < length; i++)
    {
        L += (bool) isalpha(text[i]);
        W += (bool) isspace(text[i]) && !(bool) isspace(text[i + 1]);// in case double space 
        S += text[i] == '.' || text[i] == '!' || text[i] == '?' ;
    }

    Lpercent = L * 100 / (float) W; //letters percent

    Spercent = S * 100 / (float) W; //sentences percent

    index = round(0.0588 * Lpercent - 0.296 * Spercent - 15.8); // Coleman-Liau index

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}