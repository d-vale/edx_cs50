#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

long get_cardnumber(void);
bool check_validity(long cardnumber);
int get_cardnumber_length(long cardNumber);
string check_brand(long cardnumber);

int main(void)
{
    long cardNumber = get_cardnumber();
    bool validity = check_validity(cardNumber);

    if (validity)
    {
        string brand = check_brand(cardNumber);
        printf("%s", brand);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Return the brand of a cardnumber
string check_brand(long cardnumber)
{

    int length = get_cardnumber_length(cardnumber);

    // Take only two first digits
    for (int i = 2; i < length; i++)
    {
        cardnumber /= 10;
    }

    if (length == 15 && (cardnumber == 34 || cardnumber == 37))
    {
        return "AMEX\n";
    }
    else if (length == 16 && (cardnumber >= 51 && cardnumber <= 55))
    {
        return "MASTERCARD\n";
    }
    else if ((length == 13 || length == 16) && cardnumber / 10 == 4)
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }
}

// Checking card's number validity with Luhn algorithm
bool check_validity(long cardnumber)
{
    bool validity = false;
    int sum = 0;
    int position = 1; // Digit position (1 = last, 2 = second-to-last, etc.)

    while (cardnumber > 0)
    {
        int digit = cardnumber % 10;

        // Double digits in even positions (2, 4, 6, ...)
        if (position % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9; // Equivalent to adding the digits of the number ex : 12 - 9 = 3 AND 1 +
                            // 2 = 3
            }
        }
        sum += digit;
        position++;
        cardnumber /= 10;
    }

    if (sum % 10 == 0)
    {
        validity = true;
    }

    return validity;
}

// Return length of cardnumber
int get_cardnumber_length(long cardnumber)
{
    int length = 0;
    bool countingComplete = false;

    while (!countingComplete)
    {
        cardnumber /= 10;
        if (cardnumber != 0)
        {
            length++;
        }
        else
        {
            length++;
            countingComplete = true;
        }
    }
    return length;
}

// Function that asks the user for a cardnumber
long get_cardnumber(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    } while (number < 0);
    return number;
}
