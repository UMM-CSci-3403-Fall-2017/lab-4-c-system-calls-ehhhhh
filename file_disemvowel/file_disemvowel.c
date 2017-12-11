#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {

	//Creates an array with all vowels	
	char vowels[11] = {'a','e','i','o','u','A','E','I','O','U','X'};

	int i = 0;

	//loops through the array, checking for matches
	while(i<11 && c != vowels[i]) {
		++i;
	}

	//if we got to the end of the array, it means we had no matches, so we return
	//the opposite of 'did we get to the end of the array'	
	return (i!=11);
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {

	int j = 0;

	int nonvowels = 0;

	//removes every non-vowel and increases the count of them
	for(int i = 0; i < num_chars; i++) {
		if (!is_vowel(in_buf[i])) {
			out_buf[j] = in_buf[i];
			j++;
			nonvowels++;
		}
	}

	return nonvowels;

}

void disemvowel(FILE* inputFile, FILE* outputFile) {

	int inputSize = BUF_SIZE;

	//initializes outputSize at zero
	int outputSize = 0;
	
	char* input = (char*) calloc(inputSize,sizeof(char));

	//allocate the same buffer size for both in case there are no vowels
	char* output = (char*) calloc(inputSize,sizeof(char));
	
	//dynamically adjusts size of buffer to be written (outputSize), then copies the non-vowels
	//to the output buffer.
	while ((outputSize = fread(input, sizeof(char), inputSize, inputFile))) {
	      fwrite(output, sizeof(char), copy_non_vowels(outputSize, input, output), outputFile);
	}
	


	free(input);
	free(output);
}

int main(int argc, char *argv[]) {
	
	FILE *inputFile;
	FILE *outputFile;

	switch (argc) {
		case 1: //handle command line input and standard output
			inputFile = stdin;
			outputFile = stdout;
			break;
		case 2: //handle file to standard output
			if ((inputFile = fopen(argv[1], "r")) == NULL)
			{
				printf("input file not found\n");
				exit(0);
			}
			outputFile = stdout;
			break;

		case 3: //handle file to specified file
			if ((inputFile = fopen(argv[1], "r")) == NULL)
			{
				printf("input file not found\n");
				exit(0);
			}
			if ((outputFile = fopen(argv[2], "w")) == NULL)
			{
				printf("output file not found\n");
				exit(0);
			}
			break;
		default: //incorrect number of command line arguments
			printf("Incorrect number of arguments \n");
			break;
	}

	disemvowel(inputFile, outputFile);

	fclose(inputFile);
	fclose(outputFile);	
	return 0;
}

