#include <stdio.h>
#include <cs50.h>

// Calculating Water consumption based on minutes to bottles of water
int main(void) {
    // ask for length of shower in minutes
    int time_minutes = get_int("Minutes: ");

    // where each minute is equal to 12 bottles of water
    int time_to_bottle = time_minutes * 12;

    // print bottles
    printf("Bottles: %i\n", time_to_bottle);

}