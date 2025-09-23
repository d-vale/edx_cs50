from cs50 import get_string

# Call functions


def main():
    card_number = get_string("Number: ")
    card_type = validate_card(card_number)
    print(card_type)

# Luhn algo


def luhn_check(digits):
    total = 0
    for i in range(len(digits)):
        if (len(digits) - i) % 2 == 0:
            doubled = digits[i] * 2
            if doubled >= 10:
                total += doubled // 10 + doubled % 10
            else:
                total += doubled
        else:
            total += digits[i]
    return total % 10 == 0

# Check validity


def validate_card(card_number):
    if not card_number.isdigit():
        return "INVALID"

    digits = [int(d) for d in card_number]
    length = len(digits)

    if length not in [13, 15, 16]:
        return "INVALID"

    if not luhn_check(digits):
        return "INVALID"

    return set_card_type(digits, length)

# Set type of card


def set_card_type(digits, length):
    first_digit = digits[0]
    first_two = digits[0] * 10 + digits[1] if length >= 2 else 0

    if length == 15 and (first_two == 34 or first_two == 37):
        return "AMEX"

    if length == 16 and (51 <= first_two <= 55):
        return "MASTERCARD"

    if (length == 13 or length == 16) and first_digit == 4:
        return "VISA"

    return "INVALID"


main()
