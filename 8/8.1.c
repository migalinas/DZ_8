#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strend(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);

    if (len2 > len1)
        return 0;
    char *end_of_s = s + (len1 - len2);
    if (strcmp(end_of_s, t) == 0)
        return 1;
    else
        return 0;
}

int program1() {
    char *s = NULL;
    char *t = NULL;

    printf("Enter s: ");
    size_t size_of_s = 0;
    getline(&s, &size_of_s, stdin);

    printf("Enter t: ");
    size_t size_of_t = 0;
    getline(&t, &size_of_t, stdin);

    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';

    if (t[strlen(t) - 1] == '\n')
        t[strlen(t) - 1] = '\0';

    int res = strend(s, t);
    printf("Result: %d\n", res);

    free(s);
    free(t);

    return 0;
}
