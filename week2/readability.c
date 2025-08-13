#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int index_ColemanLiau(int letters, int words, int sentences);
void print_level(int grade);

int main(void)
{
    // Prompt the user for text
    string text = get_string("Text: ");

    // Count the number of letters, words and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the Coleman-Liau index
    int grade = index_ColemanLiau(letters, words, sentences);

    // Print the grade level
    print_level(grade);
}

void print_level(int grade)
{
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

int index_ColemanLiau(int letters, int words, int sentences)
{
    // The Coleman-Liau index = 0.0588 * x - 0.296 * y - 15.8
    int roundIndex = 0;

    float x = ((float)letters / (float)words) * 100;
    float y = ((float)sentences / (float)words) * 100;

    // Calculate and round to the nearest
    float index = 0.0588 * x - 0.296 * y - 15.8;
    roundIndex = round(index);

    return roundIndex;
}

int count_letters(string text)
{
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Count only letters a-z and A-Z
        if (isalpha(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string text)
{
    int counter = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        // Count only spaces
        if (isspace(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_sentences(string text)
{
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Count sentences when it's a "." or "?" or "!"
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            counter++;
        }
    }
    return counter;
}
