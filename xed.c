/*
 * Student: Thi Tran
 * RedID: 825223653
 * Class Account: cssc0434
 * CS 530 - Systems Programming, Spring 2022
 * Prof: G. Leonard
 * Project #1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 99999  /* Char limit as infinity */
#define hexLine 16  /* Read 16 characters per line in hex format */
#define binLine 6   /* Read 6 characters per line in binary format */



/* Function to print output in hexadecimal format
 * 'text' is the content read
 * 'size' is the length of text
 */
void hexDump(void *text, int size)
{
    int i;
    char line[17];
    char *printedChar = (char*)text;


    if (size == 0)
    {   // Check if the file has length 0
        printf("Empty file!");
        exit(0);   //EXIT
    }

    for (i = 0; i < size; i++)
    {
        if((i % hexLine) == 0)
        {   //Separate lines every 16 characters read
            if(i != 0)
            {
                printf(" %s\n", line);   // Print the current line
            }

            printf("%07x: ", i);   // Print the corresponding address, format "XXXXXXX"

        }

        // Print hex format of printed character, format "XX"
        // The syntax is retrieved from:
        // https://www.includehelp.com/code-snippets/printing-value-in-decimal-octal-hexadecimal-using-printf-in-c.aspx
        printf("%02x", printedChar[i]);


        if((i%2) == 1)
        {   // Print SPACE every 2 characters read
            printf(" ");
        }

        // Consider printable ASCII characters, which is in range [" " (32) to "~" (126)]
        // According to ASCII table
        if((printedChar[i] >= 32 && printedChar[i] <= 126))
        {
            line[i % hexLine] = printedChar[i];   // Printable characters
        }
        else
        {
            line[i % hexLine] = '.';   // Print '.' for non-printable characters
        }

        line[(i % hexLine) + 1] = '\0';   // Clear the next array line


    }

    while((i % hexLine) != 0)
    {
        printf("  ");
        i++;
    }

    printf(" %s\n", line);


}



/* Function to convert text to binary format
 * This function is retrieved from:
 * https://www.youtube.com/watch?v=eKGkRWQzdx4
 */
int toBin(char c)
{
    int i;
    for(i = 7; i > 0; i--)
    {
        putchar((c & ( 1 << i)) ? '1' : '0');
    }
    return 0;
}


/* Function to print output in binary format
 * 'text' is the content read
 * 'size' is the length of text
 */
void binDump(void *text, int size)
{
    int i;
    char line[7];
    char *printedChar = (char*)text;


    if(size == 0)
    {
        // Check if the file has length 0
        printf("Empty file");
        exit(0);   // EXIT
    }

    for (i = 0; i < size; i++)
    {
        if((i % binLine) == 0)
        {   //Separate lines every 6 characters read
            if(i != 0)
            {
                printf(" %s\n", line);   // Print the current line
            }

            printf("%07x: ", i);   // Print the corresponding address, format "XXXXXXX"
        }

        int x = toBin(printedChar[i]);// Call toBin to print binary format of printed character, format "XXXXXXXX"

        printf("%d ", x);




        // Consider printable ASCII character, which is in range [" " (32) to "~" (126)]
        // According to ASCII table
        if((printedChar[i] >= 32 && printedChar[i] <= 126))
        {
            line[i % binLine] = printedChar[i];  // Printable characters
        }
        else
        {
            line[i % binLine] = '.';   // Print '.' for non-printable characters
        }

        line[(i % binLine) + 1] = '\0';   // Clear the next array line

    }

    while((i % binLine) != 0)
    {   // Complete last line if it does not have exactly 6 characters
        printf("   ");
        i++;
    }

    printf(" %s\n", line);
}





// Main function
int main (int argc, char *argv[])
{
    if(argc != 2)
    {   // Require 2 command line arguments: [./xed] [input file]. Otherwise, invalid command line arguments
        printf("Invalid command line arguments");
    }
    else
    {   // Valid command line arguments. Keep executing the program...
        FILE *inFile = fopen(argv[1], "rb");   // Open argv[1] as input file

        if(inFile == NULL)
        {   // Check if the file exists
            printf("Cannot open the file!\n");
            return 0;
        }

        do
        {
            char text[SIZE];
            int n = fread(&text, 1, sizeof(text), inFile);   // Read fixed size line from the file


            if(n > 0)
            {
                printf("Enter 1 for hexadecimal, 2 for binary: ");   // User's option for output
                int x;   // Inout user;s option
                scanf("%d", &x);

                if(x == 1)   // For hexadecimal option
                    hexDump(text, n);   // Call hexDump

                else if(x == 2)   // For binary option
                    binDump(text, n);   // Call binDump

                else
                    exit(0);   // exit if user chooses neither of them
            }

            if(feof(inFile))   // Check for end of file
                break;

        } while(1);

        fclose(inFile);
    }


return 0;
}
