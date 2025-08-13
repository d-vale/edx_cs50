#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points in the order of the letters of the alphabet
const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int count_points(string word);
void print_winner(int userpoints[]);

int main(void)
{
    // Get users's words
    string words[] = {get_string("Player 1: "), get_string("Player 2: ")};

    // Count points for each words
    int scores[] = {count_points(words[0]), count_points(words[1])};

    // Print the winner
    print_winner(scores);
}

int count_points(string word)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        // Different conditions if letter is uppercase or lowercase
        if (islower(word[i]))
        {
            // Because on ASCII d = 68 so 68 - 65 = 3 -> true position on array points
            sum += POINTS[word[i] - 'a'];
        }
        else if (isupper(word[i]))
        {
            sum += POINTS[word[i] - 'A'];
        }
    }
    return sum;
}

void print_winner(int userpoints[])
{

    // Points of each users
    int player1 = userpoints[0];
    int player2 = userpoints[1];

    if (player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2 > player1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
