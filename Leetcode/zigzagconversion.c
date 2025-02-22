#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* matrixtoarray(char** a, int row, int column, int length) {
    char* string = malloc(sizeof(char) * (length + 1)); 
    if (string == NULL) {
        return NULL;  
    }

    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < length; j++) {
            
            if (a[i][j] != 0) {  
                string[index++] = a[i][j];
            }
        }
    }
    string[length] = '\0';  
    return string;
}

char* convert(char* s, int numRows) {
    if (numRows == 1 || strlen(s) <= numRows) {
        return strdup(s);
    }

    int len = strlen(s);

    char** a = calloc(numRows, sizeof(char*));
    if (a == NULL) {
        return NULL;  
    }

    for (int i = 0; i < numRows; i++) {
        a[i] = calloc(len, sizeof(char));  
        if (a[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(a[j]);
            }
            free(a);
            return NULL; 
        }
    }

    int column = 0;
    volatile int rows = 0;
    int string_index = 0;


    while (1) {
        if (rows == 0) {
         
            for (int i = 0; i < numRows; i++) {
                if (string_index < len) {

                    a[i][column] = s[string_index++];
                } else {
                    break;  
                }
                rows=i;
            }
            rows--;
        } else {

            if (string_index < len) {

                a[rows][column] = s[string_index++];
                rows--;  
            } else {
                break;  
            }
        }

        column++; 

        if (string_index == len) {
            break;  
        }
    }

    char* returnvalue = matrixtoarray(a, numRows, column, len);


    for (int i = 0; i < numRows; i++) {
        free(a[i]);
    }
    free(a);

    return returnvalue;
}


