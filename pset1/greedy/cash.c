#include <stdio.h>
#include <cs50.h>
#include <math.h>


// Constants for change
#define NICKEL 5;
#define DIME 10;
#define QUARTER 25;

int main(void) {
    // variables for amount give, amount of coins to return & coin count
    float given_amount = 0;
    int cent_count = 0;
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int leftover = 0;
    int coin_count;

    // checking for valid input
    do
    {
        given_amount = get_float("You gave me: ");

        //check if given amount is ero or less
        if(given_amount == 0 || given_amount <= 0)
        printf("Number Should be Greater than Zero (such as 10)\n");
    }
    while(given_amount <= 0);

    // convert to cents for remainders
    cent_count = (int)round(given_amount*100);

    // calculate remainder for quarters
    quarter_count = cent_count / QUARTER;
    leftover = cent_count % QUARTER;

    // calculate remainder for dimes
    dime_count = leftover / DIME;
    leftover = leftover % DIME;

    // calculate remainder for nickels
    nickel_count = leftover / NICKEL;
    leftover = leftover % NICKEL;


    // add up total amount of coins
    coin_count = nickel_count + dime_count + quarter_count + leftover;

    // print coin_count
    printf("%d\n", coin_count);
    return 0;
}