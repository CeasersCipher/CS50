#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
    string s = get_string("S: ");

    string t = s;

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);

    }

    printf("S: %s\n", s);
    printf("T: %s\n", t);
}