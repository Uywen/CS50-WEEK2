#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// function declaration
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void) 
{
    // gets the text entered by the user
    string text = get_string("Text: ");

    // gets the return value for the total letters
   int letter = count_letters(text);

//    gets the return value for the total words
   int word = count_words(text);

//    gets return value for total number of sentences
   int sentence = count_sentences(text);


// calculates the average for letters
    float AverageLetters = (float)letter / (float)word * 100;

   
// calculates the average for sentences
    float AverageSentences = (float)sentence / (float)word * 100;

//    Does the Coleman-Liau index calculation
    int index = 0.0588 * AverageLetters - 0.296 * AverageSentences - 15.8;

// rounds off the index value
// Needs math.h header folder for "round" to work
    int Grade = round(index);


// if the grade is higher than 16 then Grade16+ will be printed
    if(Grade > 16)
    {
        printf("Grade 16+\n");
    }

    // if the grade is lower than 1 Before Grade1 will be printed
    else if(Grade < 1)
    {
        printf("Before Grade 1\n");
    }
    // Any value between those will be printed
    else
    {
         printf("Grade %d\n", Grade);
    }
   
}


// function counts the number of letters
int count_letters(string text)
{

    int letters = 0;

    /*
    "strlen" checks the length of the text entered by the user.
    */
    for(int letterslength = 0 ; letterslength < strlen(text); letterslength++)
    {
        if(isalpha(text[letterslength]) )     

        letters++;
    }
    return letters;
}

// function counts the number of words
int count_words(string text)
{
    int words = 1;

    for(int wordslength = 0 ; wordslength < strlen(text); wordslength++)
    {
        if(isspace(text[wordslength]))

        words++;
    }
    return words;
}


// function counts the number of sentences

int count_sentences(string text)
{
    int sentences = 0;

    // using acii values.

    // assigned each of them their ascii values

    char exclamation = 33;

    char point =  46;

    char question = 63;

    for(int sentencesLength = 0 ; sentencesLength < strlen(text); sentencesLength++)
    {

        // checks if the value in the length of the text has the exact ascii number
        if(text[sentencesLength] == exclamation || text[sentencesLength] == point || text[sentencesLength] == question ) 

        sentences++;
    }
   return sentences;
}

