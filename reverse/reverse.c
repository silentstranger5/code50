#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Couldn't open %s.\n", argv[1]);
        return 1;
    }

    // Read header
    // TODO #3
    const int HEADER_SIZE = 44;
    WAVHEADER header;
    fread(&header, sizeof(BYTE), HEADER_SIZE, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!(check_format(header)))
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Couldn't open %s.\n", argv[2]);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(BYTE), HEADER_SIZE, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    const int BLOCK_SIZE = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[BLOCK_SIZE];
    fseek(input, -BLOCK_SIZE, SEEK_END);
    while (ftell(input) >= HEADER_SIZE)
    {
        fread(buffer, sizeof(BYTE), BLOCK_SIZE, input);
        fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
        fseek(input, -2 * BLOCK_SIZE, SEEK_CUR);
    }

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    unsigned char *format = header.format;
    char *signature = "WAVE";
    for (int i = 0; i < 4; i++)
    {
        if (format[i] != signature[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * (header.bitsPerSample / 8);
}
