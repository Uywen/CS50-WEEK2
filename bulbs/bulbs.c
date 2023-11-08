#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{

    int bit;

    // Prompt for user to enter a message
    string message = get_string("Enter a message: ");

    /*
    Iterates the the message the user entered 
    and extracts their char values.
    */
    for(int i = 0 ; i < strlen(message); i++)
    {
         char a = message[i];

        for(int j = BITS_IN_BYTE - 1 ; j >= 0 ; j--)
        {
            // Shifts through each letters binary value.
            // second argument is the amount that it needs to shift.
            bit =  (a >> j) & 1;

            // calls print bulb function with the bit value
            print_bulb(bit);
        }
         
         printf("\n");
    }   
}

// function used to print the emojis depending on the 1s and 0s.
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
