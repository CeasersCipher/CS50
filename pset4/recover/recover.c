// recovering JPEG

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

#define BLOCKSIZE 512

int main(void)
{
    FILE *fp = fopen("card.raw", "r");
    // open memory
    if (fp == NULL)
    {
        printf("Could not open file. \n");
        return 1;
    }

    FILE *outfile;
    outfile = NULL;

    int jpgnum = 0;

    while (1)
    {
        BYTE block[BLOCKSIZE] = {};

        for (int i = 0; i < BLOCKSIZE; i++)
        {
            if (feof(fp))
            {
                fclose(fp);

                if (outfile != NULL)
                {
                    fclose(outfile);
                }
                return 0;
            }

            fread(&block[i], sizeof(BYTE), 1, fp);
        }

        if ((block[0] == 0xff) && (block[1] == 0xd8) && (block[2] == 0xff) && (block[3] == 0xe0 || block[3] == 0xe1))
        {
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            char filename[4];

            sprintf(filename, "%03d.jpg", jpgnum);
            jpgnum++;

            if ((outfile = fopen(filename, "w")) == NULL)
            {
                printf("Could not write to image. \n");
                return 1;
            }

            fwrite(&block[0], BLOCKSIZE * sizeof(BYTE), 1, outfile);
        }

        else if (outfile != NULL)
        {
            fwrite(&block[0], BLOCKSIZE * sizeof(BYTE), 1, outfile);
        }
    }

    fclose(fp);

    return 0;
}