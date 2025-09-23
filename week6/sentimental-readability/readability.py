from cs50 import get_string


def main():
    #  Prompt the user for text
    text = get_string("Text : ")

    # Count the number of letters, words and sentences in the text
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Calculate the Coleman-Liau index
    grade = index_coleman_liau(letters, words, sentences)

    # Print the grade level
    print_level(grade)


def print_level(grade):
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def index_coleman_liau(letters, words, sentences):
    # The Coleman-Liau index = 0.0588 * x - 0.296 * y - 15.8
    x = (letters / words) * 100
    y = (sentences / words) * 100

    # Calculate and round to the nearest integer
    index = 0.0588 * x - 0.296 * y - 15.8
    round_index = round(index)

    return round_index


def count_letters(text):
    counter = 0
    for char in text:
        # Count only letters a-z and A-Z
        if char.isalpha():
            counter += 1
    return counter


def count_words(text):
    counter = 1
    for char in text:
        # Count only spaces
        if char.isspace():
            counter += 1
    return counter


def count_sentences(text):
    counter = 0
    for char in text:
        # Count sentences when it's a "." or "?" or "!"
        if char in ".?!":
            counter += 1
    return counter


main()
