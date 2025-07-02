#include <cs50.h>
#include <stdio.h>

int get_positive_height(void);
void print_right_rows(int rows);
void print_left_rows(int rows, int height);

int main(void)
{
    // Ask height to user
    int height = get_positive_height();

    // Loop that calls the display functions and sends the column number according to the height
    for (int i = 0; i < height; i++)
    {
        print_left_rows(i + 1, height);
        printf("  ");
        print_right_rows(i + 1);
        printf("\n");
    }
}

void print_left_rows(int rows, int height)
{
    // As long as the row is not less than the height I put spaces
    for (int i = rows; i < height; i++)
    {
        printf(" ");
    }

    // Then I put the number of ## according to the column ex: column 2 = ##
    for (int j = 0; j < rows; j++)
    {
        printf("#");
    }
}

void print_right_rows(int rows)
{
    // Put the number of # according to the column ex: column 3 = ###
    for (int i = 0; i < rows; i++)
    {
        printf("#");
    }
}

// Function that asks the user for a positive height
int get_positive_height(void)
{
    int n;
    do
    {
        n = get_int("Height : ");
    }
    while (n < 1);
    return n;
}
