#include <ctype.h>
#include <string.h>
#include "utils.h"

void str_trim(char *s) {
    if (s == NULL || s[0] == '\0') return;
    int start = 0;
    while (s[start] != '\0' && isspace((unsigned char)s[start])) start++;
    if (start > 0) memmove(s, s + start, strlen(s + start) + 1);
    int len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) {
        s[len - 1] = '\0';
        len--;
    }
}

int is_all_digit(const char *s) {
    if (s == NULL || s[0] == '\0') return 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isdigit((unsigned char)s[i])) return 0;
    }
    return 1;
}
