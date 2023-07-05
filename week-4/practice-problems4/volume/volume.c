// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    // COPY THE HEADER FROM THE INPUT FILE TO THE OUTPUT FILE
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    // Stores 16 bits or 2 bytes each - representing samples
    int16_t buffer;
    // REPEAT FOR EACH SAMPLE:
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Update the volume
        int volume = buffer * factor;
        // Write the updated sample to the output file
        //fwrite()
        fwrite(&volume, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
