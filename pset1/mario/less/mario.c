#include <cs50.h>
#include <stdio.h>

int main(void) {

    // declare variables
    int space = 0;
    int hashtag = 0;
    int height = 0;
    int hash;

	// Grab user input, check it and ask for retry if not within bounds
	do {
		height = get_int("Height:");
        if (height == 0)
        {
            return 0;
        }
	} while (height < 1 || height > 23);
        for (hash = height; hash > 0; hash--) {
            // difference between hashtags & spaces
            hashtag = height - (hash - 1);
            space = height - hashtag;

            int i; // for looping

            // print leading spaces
            for (i = 0; i <= space-1; i++){
                printf(" ");
            }
            // print hash(s)
            for (i = 0; i <= hashtag; i++){
                printf("#");
            }

            // new line
            printf("\n");

        }
        return 0;

    }
