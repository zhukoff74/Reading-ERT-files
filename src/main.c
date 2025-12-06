#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define BUFFER_SIZE 1024

void print_usage(const char *program_name) {
    fprintf(stderr, "Как пользоваться: %s --file=<ИМЯ_ФАЙЛА>\n", program_name);
    fprintf(stderr, "Пример: %s --file=Обработка.ert\n", program_name);
}

int main(int argc, char *argv[]) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    const char *prefix = "--file=";
    size_t prefix_len = strlen(prefix);
    
    if (strncmp(argv[1], prefix, prefix_len) != 0) {
        fprintf(stderr, "Ошибка: Неверный формат аргумента\n");
        print_usage(argv[0]);
        return 1;
    }

    const char *filename = argv[1] + prefix_len;
    
    if (strlen(filename) == 0) {
        fprintf(stderr, "Ошибка: Не указано имя файла\n");
        print_usage(argv[0]);
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Ошибка: Невозможно открыть файл '%s'\n", filename);
        perror("fopen");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    printf("\n");
    
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
    
    printf("\n");
    fclose(file);
    
    return 0;
}
