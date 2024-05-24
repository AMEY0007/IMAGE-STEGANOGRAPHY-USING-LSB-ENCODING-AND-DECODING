#include<stdio.h>
#include "decode.h"
#include "types.h"
#include<string.h>
#include "common.h"
#include<stdlib.h>
#include<unistd.h>

/* Function definition */

// Function to perform decoding
Status do_decoding(DecodeInfo *decInfo)
{
    // Open required files
    if (Open_files(decInfo) == d_success)
    {
        printf("INFO: Opening required files\n");
        printf("INFO: Opening stego_beautiful.bmp\n");
	int i;
        const int total = 20; // Total number of iterations
        for (i = 0; i <= total; ++i) {
        printf("%d%% ", i * 5);
        fflush(stdout); // Flush the output buffer to ensure the text is printed immediately
        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
        printf("\r");   // Move the cursor back to the beginning of the line
    }

	printf("DONE\n");
        printf("\n");
    }
    else
    {
        printf("ERROR: Opening File Unsuccessfully\n");
        printf("\n");
        return d_failure;
    }

    // Decode magic string
    if (decode_magic_string(MAGIC_STRING , decInfo) == d_success)
    {
        printf("INFO:Decoding Magic String Signature\n");
	int i;
        const int total = 20; // Total number of iterations
        for (i = 0; i <= total; ++i) {
        printf("%d%% ", i * 5);
        fflush(stdout); // Flush the output buffer to ensure the text is printed immediately
        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
        printf("\r");   // Move the cursor back to the beginning of the line
    }

	printf("DONE\n");
        printf("\n");
    }
    else
    {
        printf("ERROR: Decoded Magic String Signature Un-successfully\n");
        printf("\n");
        return d_failure;
    }

    // Decode secret file extension size
    if (decode_secret_file_extn_size(strlen(".txt"), decInfo->fptr_src_image))
    {
        printf("INFO:Decoding Output File Extension\n");
	int i;
        const int total = 20; // Total number of iterations
        for (i = 0; i <= total; ++i) {
        printf("%d%% ", i * 5);
        fflush(stdout); // Flush the output buffer to ensure the text is printed immediately
        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
        printf("\r");   // Move the cursor back to the beginning of the line
    }

	printf("DONE\n");
        printf("\n");
    }
    else
    {
        printf("ERROR: Decoding File Extn Size Unsuccessfully\n");
        printf("\n");
        return d_failure;
    }

    // Decode secret file extension
    if (decode_secret_file_extn(decInfo->extn_secret_file, decInfo) == d_success)
    {
        printf("INFO:Decoding Decoded.c File Extension\n");
	int i;
        const int total = 20; // Total number of iterations
        for (i = 0; i <= total; ++i) {
        printf("%d%% ", i * 5);
        fflush(stdout); // Flush the output buffer to ensure the text is printed immediately
        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
        printf("\r");   // Move the cursor back to the beginning of the line
    }

	printf("DONE\n");
        printf("\n");
    }
    else
    {
        printf("ERROR: Decoding Decoded.c File Extension Un-successfully\n");
        printf("\n");
        return d_failure;
    }

    // Decode secret file size
    if (decode_secret_file_size(decInfo->size_secret_file, decInfo) == d_success)
    {
        printf("INFO-Decoding Decoded.c File Size\n");
	int i;
        const int total = 20; // Total number of iterations
        for (i = 0; i <= total; ++i) {
        printf("%d%% ", i * 5);
        fflush(stdout); // Flush the output buffer to ensure the text is printed immediately
        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
        printf("\r");   // Move the cursor back to the beginning of the line
    }

	printf("DONE\n");
        printf("\n");
    }
    else
    {
        printf("ERROR: Decoding Decoded.c File Size Unsuccessful\n");
        printf("\n");
        return d_failure;
    }

    // Decode secret file data
    if (decode_secret_file_data(decInfo) == d_success)
    {
        printf("INFO:Decoding decoded.txt File Data\n");
	int i;
        const int total = 20; // Total number of iterations
        for (i = 0; i <= total; ++i) {
        printf("%d%% ", i * 5);
        fflush(stdout); // Flush the output buffer to ensure the text is printed immediately
        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
        printf("\r");   // Move the cursor back to the beginning of the line
    }

	printf("DONE\n");
        printf("\n");
    }
    else
    {
        printf("ERROR: Decoding decoded.txt File Data\n");
        printf("\n");
        return d_failure;
    }

    return d_success;
}

// Function to read and validate decoding arguments
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    // Validate source image file extension
    if (!(strcmp(strstr(argv[2], "."), ".bmp")))
    {
        decInfo->src_image_fname = argv[2];
    }
    else
    {
        return d_failure;
    }

    // Validate output image file extension
    if (argv[3] != NULL)
    {
        decInfo->output_image_fname = strtok(argv[3], ".");
    }
    else
    {
        decInfo->output_image_fname = "default_decoded.txt";
        printf("Output File not mentioned. Creating decoded.txt as default\n");
    }

    return d_success;
}

// Function to open input files
Status Open_files(DecodeInfo *decInfo)
{
    decInfo->fptr_src_image = fopen(decInfo->src_image_fname , "r");

    if(decInfo->fptr_src_image == NULL)
    {
        perror("fopen");
        fprintf(stderr,"ERROR : Unable to open file %s\n", decInfo->src_image_fname);
        return d_failure;
    }

    return d_success;
}

// Function to decode magic string
Status decode_magic_string(char *magic_string, DecodeInfo *decInfo)
{
    fseek(decInfo->fptr_src_image, 54, SEEK_SET);
    decInfo->image_data = malloc(strlen(magic_string) + 1);
    decode_data_from_image(strlen(magic_string), decInfo->fptr_src_image, decInfo);

    if (!(strcmp(MAGIC_STRING, decInfo->image_data)))
    {
        return d_success;
    }
    else
    {
        return d_failure;
    }
}

// Function to decode data from image
Status decode_data_from_image(int size, FILE *fptr_src_image, DecodeInfo *decInfo)
{
    int i;
    char str[8];
    for (i = 0; i < size ; i++)
    {
        fread(str, 8, sizeof(char), decInfo->fptr_src_image);
        decode_byte_from_lsb(&decInfo->image_data[i], str);
    }
    decInfo->image_data[i] = '\0';
}

// Function to decode byte from LSB
Status decode_byte_from_lsb(char *data, char *image_buffer)
{
    unsigned char ch = 0x00;
    for (int i = 0; i < 8; i++)
    {
        ch = ((image_buffer[i] & 0x01 ) << (7 - i)) | ch;
    }
    *data = ch;
    static int i = 0;
    printf("charecter is[%d] = %c\n", i++, *data);
    
}

// Function to decode secret file extension size
Status decode_secret_file_extn_size(int size, FILE *fptr_src_image)
{
    int length = 0;
    char str[32];
    for (int i = 0; i < size; i++)
    {
        fread(str, 8, sizeof(char), fptr_src_image);
        decode_size_from_lsb(str, &length);
    }

    if (size == length)
    {
        return d_success;
    }
    else
    {
        return d_failure;
    }
}

// Function to decode size from LSB
Status decode_size_from_lsb(char *buffer, int *length)
{
    int num = 0x00;
    for (int i = 0; i < 32; i++)
    {
        num = ((buffer[i] & 0x01) << (31 - i)) | num;
    }
    *length = num;
    printf("size is = %d\n", *length);
}

// Function to decode secret file extension
Status decode_secret_file_extn(char *file_extn, DecodeInfo *decInfo)
{
    file_extn = ".txt";
    decInfo->extn_secret_file = malloc(strlen(file_extn) + 1);
    decode_extn_data_from_image(strlen(file_extn), decInfo->fptr_src_image, decInfo);
    decInfo->extn_secret_file[strlen(file_extn)] = '\0';

    if (!(strcmp(decInfo->extn_secret_file, file_extn)))
    {
        return d_success;
    }
    else
    {
        return d_failure;
    }
}

// Function to decode extension data from image
Status decode_extn_data_from_image(int size, FILE *fptr_src_image, DecodeInfo *decInfo)
{
    for (int i = 0; i < size; i++)
    {
        fread(decInfo->src_image_fname, 8, 1, fptr_src_image);
        decode_byte_from_lsb(&decInfo->extn_secret_file[i], decInfo->src_image_fname);
    }
    printf("size = %d\n", size);
    return d_success;
}

// Function to decode secret file size
Status decode_secret_file_size(int file_size, DecodeInfo *decInfo)
{
    char str[32];
    fread(str, 32, sizeof(char), decInfo->fptr_src_image);
    decode_size_from_lsb(str, &file_size);
    decInfo->size_secret_file = file_size;
    return d_success;
}

// Function to decode secret file data
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    char ch;
    decInfo->fptr_secret = fopen(decInfo->output_image_fname, "w");

    if (decInfo->fptr_secret == NULL)
    {
        fprintf(stderr, "can't open decode.txt file\n");
        return d_failure;
    }
    else
    {
        for (int i = 0; i < decInfo->size_secret_file; i++)
        {
            fread(decInfo->src_image_fname, 8, sizeof(char), decInfo->fptr_src_image);
            decode_byte_from_lsb(&ch, decInfo->src_image_fname);
            fputc(ch, decInfo->fptr_secret);
        }
        return d_success;
    }
}















