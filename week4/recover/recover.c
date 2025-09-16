#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define block size constant
#define BLOCK_SIZE 512

int is_jpeg_start(uint8_t buffer[])
{
    // Check JPEG signature: 0xff 0xd8 0xff 0xe*
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char *argv[])
{
    // Check that user provided exactly one argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the forensic image file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Variables for recovery
    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;
    int jpeg_count = 0;
    char filename[8]; // "000.jpg\0" = 8 characters

    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        // Check if this block starts a new JPEG
        if (is_jpeg_start(buffer))
        {
            // If a JPEG file was already open, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create the new JPEG filename
            sprintf(filename, "%03i.jpg", jpeg_count);

            // Open a new file for writing
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create %s.\n", filename);
                fclose(card);
                return 1;
            }
            // Increment JPEG counter
            jpeg_count++;
        }

        // If a JPEG file is open, write current block to it
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
    // Close all open files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
