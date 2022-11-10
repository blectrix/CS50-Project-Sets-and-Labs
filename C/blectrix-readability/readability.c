#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt user text
    string text = get_string("Text: ");
    // Print out enter text
    printf("%s\n", text);

    // Calculating the number of letters in the text
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }
    printf("%i letters\n", letters);
    // End of letter calculation

    // Calculating the number of words
    int words = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    printf("%i words\n", words);
    // End of word calculation

    // Calculating the number of sentences
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    printf("%i sentences\n", sentences);
    // End of sentence calculation

    // Using the Coleman-Liau index formula to determine the grade level
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }
    // End of grade level determation
}