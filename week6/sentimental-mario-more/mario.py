from cs50 import get_int


def main():
    height = get_height()
    build_pyramids(height)

# Ask height


def get_height():
    while True:
        height = get_int("Height: ")
        if 1 <= height <= 8:
            return height

# Print pyramids


def build_pyramids(height):
    for i in range(height):
        spaces = height - i - 1
        blocks = i + 1
        print(" " * spaces + "#" * blocks + "  " + "#" * blocks)


# Call main function
main()
