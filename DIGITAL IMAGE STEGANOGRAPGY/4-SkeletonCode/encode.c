#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include <unistd.h>

/* Function Definitions */

       
// Function to perform encoding
Status do_encoding(EncodeInfo *encInfo)
{
    //function to  Open required files
    if (open_files(encInfo) == e_success)
    {
	printf("INFO: Open beautiful.bmp\n");
	printf("INfo: Open secret.txt\n");
	printf("INFO: Open Stego_img.bmp\n");
	int i;
        const int total = 20; // Total number of iterations
        for (i = 0; i <= total; ++i) {
        printf("%d%% ", i * 5);
        fflush(stdout); // Flush the output buffer to ensure the text is printed immediately
        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
        printf("\r");   // Move the cursor back to the beginning of the line
    }

	printf("DONE\n");
    }

    else
    {
	printf("ERROR: File Opening Failure");
	printf("\n");
	return e_failure;
    }

    // function Check capacity of beautiful.bmp
    if (check_capacity(encInfo) == e_success)
    {
	printf("INFO: Checking for beautiful.bmp capacity to store secret file data\n");
	printf("INFO: Capacity matched sucessfully\n");
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
	printf("check capacity failure\n");
	printf("\n");
	return e_failure;
    }

    // function to Copy BMP header
    if (copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
    {
	printf("INFO: Copying Image Header\n");
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
	printf("ERROR: Copying Image Header Unsuccessful\n");
	printf("\n");
	return e_failure;
    }

    // function Encode magic string
    if (encode_magic_string(MAGIC_STRING, encInfo) == e_success)
    {
	printf("INFO: Encoding Magic String Signature \n");
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
	printf("ERROR: Encoding Magic String Signature Unsuccessful\n");
	printf("\n");
	return e_failure;
    }

    // function to check Encode secret file extension size
    if (encode_secret_file_extn_size(strlen(encInfo->extn_secret_file), encInfo) == e_success)
    {
	printf("INFO: Encoding secret.txt File Extension Size\n");
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
	printf("ERROR: Encoding secret.txt File Extension Size Unsuccessful\n");
	printf("\n");
	return e_failure;
    }

    // function Encode secret file extension
    if (encode_secret_file_extn(encInfo->extn_secret_file, encInfo) == e_success)
    {
	printf("INFO: Encoding secret.txt File Extension \n");
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
	printf("ERROR: Encoding secret.txt File Extension Unsuccessful\n");
	printf("\n");
	return e_failure;
    }

    // Encode secret file size
    if (encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success)
    {
	printf("INFO: Encoding secret.txt File Size\n");
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
	printf("ERROR: Encoding secret.txt File Size Unsuccessful\n");
	printf("\n");
	return e_failure;
    }

    // Encode secret file data
    if (encode_secret_file_data(encInfo) == e_success)
    {
	printf("INFO: Encoding secret.txt File Data\n");
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
	printf("ERROR: Encoding secret.txt File Data Unsuccessful\n");
	printf("\n");
	return e_failure;
    }

    // Copy remaining image data
    if (copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
    {
	printf("INFO: Copying Left Over Data\n");
	printf("INFO: Done\n");
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
	printf("ERROR: Copying Left Over Data Unsuccessful\n");
	printf("\n");
	return e_failure;
    }

    return e_success;
}

// Function to read and validate encoding arguments
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    // Validate source image file extension
    if (!(strcmp(strstr(argv[2], "."), ".bmp")))
    {
	encInfo->src_image_fname = argv[2];
    }
    else
    {
	return e_failure;
    }

    // Validate secret file extension
    if (strcmp(strstr(argv[3], "."), ".txt") == 0)
    {
	encInfo->secret_fname = argv[3];
	strcpy(encInfo->extn_secret_file, strstr(argv[3], "."));
    }
    else
    {
	return e_failure;
    }

    // Validate stego image file extension
    if (argv[4] != NULL)
    {
	if (strcmp(strstr(argv[4], "."), ".bmp") == 0)
	    encInfo->stego_image_fname = argv[4];
	else
	{
	    printf("OUTPUT FILE IS NOT A .BMP FILE");
	    printf("\n");
	    return e_failure;
	}
    }
    else
    {
	printf("\n");
	encInfo->stego_image_fname = "default_stego.bmp";
	printf("INFO: Output File not mentioned. Creating steged_img.bmp as default\n");
	printf("\n");
    }

    return e_success;
}

// Function to check capacity of BMP file
Status check_capacity(EncodeInfo *encInfo)
{
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);

    if (encInfo->image_capacity >= (strlen(MAGIC_STRING) * 8) + 32 + (strlen(encInfo->extn_secret_file) * 8) + 32 + (encInfo->size_secret_file * 8))
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }
}

// Function to copy BMP header
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    rewind(fptr_src_image);
    char str[54];
    fread(str, sizeof(char), 54, fptr_src_image);
    fwrite(str, sizeof(char), 54, fptr_dest_image);

    return e_success;
}

// Function to get image size for BMP file
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    fseek(fptr_image, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fptr_image);
    fread(&height, sizeof(int), 1, fptr_image);

    return width * height * 3;
}

// Function to get file size
uint get_file_size(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);
    return ftell(fptr);
}

// Function to open input and output files
Status open_files(EncodeInfo *encInfo)
{
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");

    if (encInfo->fptr_src_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);
	printf("\n");
	return e_failure;
    }

    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");

    if (encInfo->fptr_secret == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n",encInfo -> secret_fname);
	printf("\n");

	return e_failure;
    }

    // Stego Image file
    encInfo -> fptr_stego_image = fopen(encInfo -> stego_image_fname, "w");
    // Do Error handling
    if (encInfo -> fptr_stego_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo -> stego_image_fname);
	printf("\n");

	return e_failure;
    }

    // No failure return e_success
    return e_success;
}

Status encode_byte_to_lsb(char data, char *image_buffer)
{
    for(int i=0;i<8;i++)
    {
	image_buffer[i] = (image_buffer[i] & 0xfe ) | ((data & (1 << ( 7 - i ))) >> ( 7 - i));
    }

}

Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image, EncodeInfo *encInfo)
{
    for(int i=0; i<size; i++)
    {
	fread(encInfo -> image_data, 8, sizeof(char), fptr_src_image);
	encode_byte_to_lsb(data[i],encInfo -> image_data);
	fwrite(encInfo->image_data, 8, sizeof(char), fptr_stego_image);
    }
}

Status encode_magic_string(char *magic_string, EncodeInfo *encInfo)

{
    encode_data_to_image(magic_string, strlen(magic_string), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
    return e_success;
}

Status encode_secret_file_extn_size(int size, EncodeInfo *encInfo)
{
    char str[32];
    fread(str, 32, sizeof(char), encInfo -> fptr_src_image);
    encode_size_to_lsb(size, str);
    fwrite(str, 32, sizeof(char), encInfo -> fptr_stego_image);
    return e_success;
}
Status encode_size_to_lsb(int size, char*image_buffer)
{
    for(int i=0;i<32;i++)
    {
	image_buffer[i] = (image_buffer[i] & 0xfffffffe ) | (( size & ( 1 << ( 31 - i ))) >> ( 31 - i ));
    }

}

Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo)
{
    encode_data_to_image(file_extn, strlen(encInfo -> extn_secret_file), encInfo -> fptr_src_image, encInfo -> fptr_stego_image, encInfo);

    return e_success;

}
Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{
    encode_secret_file_extn_size(file_size, encInfo);
    return e_success;
}
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    fseek(encInfo -> fptr_secret,0,SEEK_SET);

    char str[encInfo -> size_secret_file];

    fread(str,encInfo -> size_secret_file, sizeof(char), encInfo -> fptr_secret);

    encode_data_to_image(str, encInfo -> size_secret_file, encInfo -> fptr_src_image, encInfo -> fptr_stego_image, encInfo);

    return e_success;
}
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char str;

    while(fread(&str, 1, 1, fptr_src ) > 0)

	fwrite(&str, 1, 1,fptr_dest);

    return e_success;


}



