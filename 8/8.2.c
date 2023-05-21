#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char** arr, int low, int high) {
    char* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strlen(arr[j]) <= strlen(pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int program2() {
    int size;
    printf("Enter array of strings: ");
    scanf("%d", &size);

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    char** strings = (char**)malloc(size * sizeof(char*));


    printf("Enter strings:\n");
    for (int i = 0; i < size; i++) {
        char* buffer = NULL;
        size_t  buffer_size = 0;
        ssize_t length = getline(&buffer, &buffer_size, stdin);
        if (buffer[length - 1] == '\n')
            buffer[length - 1] = '\0';
        strings[i] = strdup(buffer);
        free(buffer);
    }

    quicksort(strings, 0, size - 1);

    printf("Sorted strings:\n");

    for (int i = 0; i < size; i++) {
        if (i < size - 1)
            printf("%s\n", strings[i]);
        else
            printf("%s", strings[i]);
    }

    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}