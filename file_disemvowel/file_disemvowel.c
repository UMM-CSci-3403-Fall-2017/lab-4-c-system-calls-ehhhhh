#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
	
	char vowels[11] = {'a','e','i','o','u','A','E','I','O','U','X'};

	int i = 0;

	while(i<11 && a != vowels[i]) {
		++i;
	}
	
	return (i!=11);
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
	
	for(int i = 0; i < BUF_SIZE; i++) {
		if (isVowel(in_buf[i])) {
			out_buf[j] = in_buf[i];
			j++;
		}
	}

	return j;

}

void disemvowel(FILE* inputFile, FILE* outputFile) {

	int inputSize = BUF_SIZE;

	char* input = (char*) calloc(inputSize,sizeof(char));

	fread(input, sizeof(char), inputSize, inputFile)
	
	int outputSize = 0;

	for (int i = 0; i < inputSize, i++) {
		if !isVowel(input[i]) {
			outputSize++;
		}
	}
	
	char* output = (char*) calloc(outputSize, sizeof(char));

	copy_non_vowels(outputSize, input, output);

}

void main(int argc, char *argv[]) {
	
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
				print("input file not found");
				exit(0);
			}
			outputFile = stdout;
			break;

		case 3:
			if ((inputFile = fopen(argv[1], "r")) == NULL)
			{
				print("input file not found");
				exit(0);
			}
			if ((outputFile = fopen(argv[2], "w")) == NULL)
			{
				print("output file not found");
				exit(0);
			}
			break;
	}

	disemvowel(inputFile, outputFile);

	return 0;
}

void
