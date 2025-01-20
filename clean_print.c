/*
 * This program is in the fledgling state of what will ultimately be a 'clean chat' program.
 *
 * The idea is to take a user-input string, see if they used any 'dirty words', and if so
 * replace them with a cooresponding 'clean word', concatenate the string back together and print
 * out the clean string.
 *
 *
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int FindNumWords(char*);
char** TokenizeInputString(int, char*);
void CleanUpString(int, char**);
void PrintCleanString(int, char**);
void DeallocWords(int, char**);

const char* dirty_words[] = {"failed", "shit"};
const char* clean_words[] = {"passed", "poo"};

int main(void) {
	char my_string[] = "Test failed you shit\n";
	printf("\nOriginal string:\n%s\n", my_string);

	int word_count = FindNumWords(my_string);
	char** words = TokenizeInputString(word_count, my_string);
	CleanUpString(word_count, words);
	
	printf("\nClean string:\n");
	PrintCleanString(word_count, words);
	printf("\n");

	DeallocWords(word_count, words);
}

int FindNumWords(char* input) {
	if (input == NULL) {
		fprintf(stderr, "ERROR: empty input string in tokenize_input_string()\n");
		return 1;
	}
	
	// Get number of words for 'strtok()' call	
	int word_count = 1;
	int i = 0;
	while (input[i] != '\0') {
		if (input[i] == ' ') {
			word_count++;
		}
		i++;
	}
	return word_count;
}

char** TokenizeInputString(int word_count, char* input) {
	char** word_toks = calloc(word_count, sizeof(char*));
	int i = 0;

	char* token = strtok(input, " \n");
	while (token != NULL && i < word_count) {
		word_toks[i] = calloc(1, strlen(token) + 1);
		strncpy(word_toks[i], token, strlen(token));
		token = strtok(NULL, " \n");
		i++;
	}
	return word_toks;
}

void CleanUpString(int word_count, char** words) {
	int size = sizeof(dirty_words)/sizeof(dirty_words[0]);

	for (int i = 0; i < word_count; i++) {
		for (int j = 0; j < size; j++) {
			if (strcmp(words[i], dirty_words[j]) == 0) {
				printf("word %d is dirty\n", i);
				free(words[i]);
				words[i] = calloc(1, sizeof(char*));
				strncpy(words[i], clean_words[j], strlen(clean_words[j]));
				break;
			}
			else {
				printf("word %d is clean\n", i);
			}
		}
	}
}

void PrintCleanString(int word_count, char** clean_words) {
	for (int i = 0; i < word_count; i++) {
		printf("%s ", clean_words[i]);
	}
	printf("\n");
}

void DeallocWords(int word_count, char** input_array) {
	for(int i = 0; i < word_count; i++) {
		free(input_array[i]);
	}
	free(input_array);
}
