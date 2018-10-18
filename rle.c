#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char** argv) {
    if (argc != 2) {
	    printf("Error, incorrect mumber of arguments\n");	
            return 0;
    }
    int test;
    int length = strlen(argv[1]);
    char *word = argv[1];
    for (test = 0; test < length; test = test + 1) {
	if (isdigit(word[test])){
		printf("error\n");
		return 0;
}
}
    char *result = (char*)malloc((2*length + 1) * sizeof(char));
    if (result == NULL) {
        return 0;
    }
    int i = 0, position = 0, occurences = 0;
    char transfer[length*2 + 1];
    for (i = 0; i < length; i = i + 1) {
        result[position++] = word[i];
        occurences = 1;
        while ((word[i] == word[i + 1]) && (i + 1 < length)) {
                occurences = occurences + 1;
		i = i + 1;
            }
        sprintf(transfer, "%d", occurences);
        int j = 0;
        while(*(transfer + j)) {
            result[position] = transfer[j];
            position = position + 1;
            j = j + 1;
        }
    }
    result[position] = '\0';
    int resultLength = strlen(result);
    if (length < resultLength) {
        printf("%s\n", argv[1]);
    } else {
        printf("%s\n",result);
    }
    free(result);
    return 0;
}
