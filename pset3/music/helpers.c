// Helper functions for music
// convert length of notes | convert frequency of notes | determine rests

#include <cs50.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (fraction[0] == '1')
    {
        // whole note
        if (fraction[2] == '8')
        {
            return 1;
        }
        // 1/2 note
        else if (fraction[2] == '4')
        {
            return 2;
        }
        // 1/4 note
        else if (fraction[2] == '2')
        {
            return 4;
        }
        // 1/8th note
        else if (fraction[2] == '1')
        {
            return 8;
        }
    }
    // 3/8th
    else if (fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        return 0;
    }

    return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int octave = note[strlen(note) - 1];
    octave -= 48;

    //determine freq of note
    double freq = 0.0;

    //note letter & associated frequency
    switch (note[0])
    {
        case 'C' :
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D' :
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E' :
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F' :
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G' :
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A' :
            freq = 440.0;
            break;
        case 'B' :
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;

        default :
            return 0;
    }

    // to shift octave
    if (octave > 4)
    {
        // up octave for notes
        for (int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if (octave < 4)
    {
        // down octave for notes
        for (int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }
    }

    // flat or sharp
    if (note[1] == 'b')
    {
        // flatten
        freq /= (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[1] == '#')
    {
        // sharpen
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    // return int value of frequency
    int ret = round(freq);
    return ret;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // when false represents rest, else return true

    if (strncmp(s, "", 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}