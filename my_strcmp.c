#include "main.h"

int my_strcmp(char *string1, char *string2) {
    while (*string1 == *string2) {
        if (*string1 == '\0') {
            return 0;
        }
        string1++;
        string2++;
    }
    return *string1 - *string2;
}

