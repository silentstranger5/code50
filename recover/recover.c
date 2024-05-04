#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Check for correctness of file content
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Couldn't open %s\n", argv[1]);
        return 1;
    }

    // Declare variables
    typedef uint8_t BYTE;
    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];
    int counter = 0;
    char file_name[8];
    FILE *jpg_file = NULL;

    // Read contents of a RAW file block by block
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // If block starts with JPG signature, create a new JPG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // Close previous one if it exists
            if (counter > 0)
            {
                fclose(jpg_file);
            }
            sprintf(file_name, "%03i.jpg", counter);
            jpg_file = fopen(file_name, "w");
            counter++;
        }

        // Write block content to JPG file if it exists and is open
        if (jpg_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpg_file);
        }
    }

    // Close files
    fclose(jpg_file);
    fclose(raw_file);
}
