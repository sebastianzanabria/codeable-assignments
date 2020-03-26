#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n"); //ask for name
    printf("hello, %s\n", name); //print name
}
