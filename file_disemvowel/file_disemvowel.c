#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
	
	char vowels[11] = {'a','e','i','o','u','A','E','I','O','U','X'};

	int i = 0;

	while(i<11 && c != vowels[i]) {
		++i;
	}
		
	return (i!=11);
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {

	int j = 0;

	int nonvowels = 0;

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

	int outputSize = 0;
	
	char* input = (char*) calloc(inputSize,sizeof(char));

	char* output = (char*) calloc(inputSize,sizeof(char));
	
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
		case 1:
			inputFile = stdin;
			outputFile = stdout;
			break;
		case 2:
			if ((inputFile = fopen(argv[1], "r")) == NULL)
			{
				printf("input file not found");
				exit(0);
			}
			outputFile = stdout;
			break;

		case 3:
			if ((inputFile = fopen(argv[1], "r")) == NULL)
			{
				printf("input file not found");
				exit(0);
			}
			if ((outputFile = fopen(argv[2], "w")) == NULL)
			{
				printf("output file not found");
				exit(0);
			}
			break;
	}

	disemvowel(inputFile, outputFile);

	fclose(inputFile);
	fclose(outputFile);	
	return 0;
}

