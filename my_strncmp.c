#include "main.h"

int my_strncmp(char *string1, char *string2, size_t n) {
    while (n > 0) {
        if (*string1 == '\0' || *string1 != *string2) {
            return *string1 - *string2;
        }
        string1++;
        string2++;
        n--;
    }
    return 0;
}
