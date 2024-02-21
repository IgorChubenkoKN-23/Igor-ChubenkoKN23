#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("chcp 65001 & cls");
    char sentence[1000];
    printf("Введіть речення: ");

    scanf("%[^.\n]", sentence);

    if (strstr(sentence, "сайт") != NULL || strstr(sentence, "site") != NULL) {
        printf("Слово 'сайт' знайдено в реченні.\n");
    } else {
        printf("Слово 'сайт' не знайдено в реченні.\n");
    }
    printf("Натисніть Enter для завершення");
getch();
    return 0;
}
