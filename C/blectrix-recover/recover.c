#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Eliminate magic numbers
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check that argument count is two
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file for reading
    FILE *file = fopen(argv[1], "r");

    // Check that the input_file is valid
    if (file == NULL)
    {
        fclose(file);
        printf("Could not open file");
        return 1;
    }

    // Declarering variables

    // File pointer for recovered images
    FILE *rec_file = NULL;
    // char filename[8]
    char *filename = malloc(8 * sizeof(char));

    // Store blocks of 512 bytes in an array
    BYTE buffer[BLOCK_SIZE];
    // Tracks number of images generated
    int count = 0;
    // End of declarering

    // Read the blocks of 512 bytes
    while (fread(&buffer, BLOCK_SIZE, 1, file))
    {
        // Check if byte indicate start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            /** Close previous jpeg before processing a new one */
            if (count > 0)
            {
                fclose(rec_file);
            }

            // Write the JPEG filenames
            sprintf(filename, "%03i.jpg", count);

            // Open rec_file for writting
            rec_file = fopen(filename, "w");

            // Count number of images found
            count++;

        }
        /** Keep writing after you find first jpeg block */
        if (count > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, rec_file);
        }
    }
    free(filename);
    fclose(rec_file);
    fclose(file);

    return 0;
}
// End of program