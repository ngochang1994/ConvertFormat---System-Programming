Student: Thi Tran
RedID: 825223653
Class Account: cssc0434
Class: CS 530, Spring 2022
Prof: G. Leonard
Project #1
Filename: README.txt


FILE MANIFEST:
- xed.c   // Executable file
- text.txt   // Included text file for user input
- README.txt   // README
- Makefile   // For 'make' to use to compile the project

REQUIREMENTS:
- Command lines to run the program:
    make   
    ./xed text.txt

OPERATING INSTRUCTIONS:
- This program shall develop, test, and deliver a program which will print content of a regular file in hexadecimal or binary format. Basically, it will open and read every byte in the file specified by the user and will write the output in either ASCII hex value or binary value representation for each byte. 
- When running the program, the user will have two options to get the output. Enter "1" for hexadecimal, "2" for binary. Otherwise, exit the program.
- The output is supposed to be similar to the output of command line "xxd text.txt" or "xxd -b text.txt" on edoras.
- All functions used in "xed.c" file:
	hexDump(void *, int *);   // print output as hexadecimal format
	toBin(char *);   // convert text to binary format
	binDump(void *, int *);   // print output as binary format
	main(int argc, char *argv[]);   // executable function


DEFICIENCIES/BUGS:
- Cannot handle the last line of output as expected

LESSONS LEARNED:
- Experience with xxd command line
- Learn functions for converting byte to hexadecimal and binary
- Word with gcc debugger & gdb

