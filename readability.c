#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/*Prototyping for my function named ColemanLiau*/
float ColemanLiau (float letter, float sentence);


int main (void)
{
    /*Asking for user input in a string format*/
    string text = get_string("Text: ");

    /*initializing letter, sentence and word variables and assigning zero*/
    int l=0;
    int s=0;
    int w=0;

    /*The for loop is gonna go through all the chars in a given text. If checks if it's a letter and
      adds to letter*/
    for (int i=0; i<= strlen(text); i++)
    {
        if (((int)text[i] > 64 && (int)text[i] <91) || ((int)text[i] > 96 && (int)text[i] <123))
        {
            l++;
        }

        /* first else if checks if it's a punctiation that marks the end of sentence, adds
        to sentence.*/
        else if ((int)text[i] == 33 || (int)text[i] == 46 || (int)text[i] == 63 )
        {
            if (i == strlen(text)-1)
            {
                s++;
                w++;
            }
            else
            {
                s++;
            }
        }
        else if ((int)text[i] == 32)
        {
            w++;
        }

    }


    float fl = (l*100)/w;
    float fs = (s*100)/w;

    int grade = ColemanLiau(fl, fs);


    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);

    }



}

float ColemanLiau (float letter, float sentence)
{
    float index = 0.0588 * letter - 0.296 * sentence - 15.8;
    index = roundf(index);
    return index;
}
