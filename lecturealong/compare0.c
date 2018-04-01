// doesnt work

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("S: ");
    string t = get_string("T: ");

    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}