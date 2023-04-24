#include "main.h"
size_t my_getline(char **lineptr) {
    static char buffer[BUFSIZ];
    static int buffer_size = 0;

    size_t line_size = 0;
    char *line = NULL;
    int newline_found = 0;
    int i;

    while (1) {
        if (buffer_size == 0) {
            buffer_size = read(STDIN_FILENO, buffer, BUFSIZ);
            if (buffer_size == 0) {
                break;
            }
        }
        for (i = 0; i < buffer_size; i++) {
            if (buffer[i] == '\n') {
                newline_found = 1;
                line = malloc(line_size + i + 1);
                memcpy(line, *lineptr, line_size);
                memcpy(line + line_size, buffer, i);
                line_size += i;
                line[line_size] = '\0';
                buffer_size -= i + 1;
                break;
            }
        }
        if (newline_found) {
            break;
        }
        line = malloc(line_size + buffer_size);
        memcpy(line, *lineptr, line_size);
        memcpy(line + line_size, buffer, buffer_size);
        line_size += buffer_size;
        buffer_size = 0;
    }
    *lineptr = line;
    return line_size;
}

