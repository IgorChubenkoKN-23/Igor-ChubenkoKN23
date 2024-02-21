#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("chcp 65001 & cls");
  int arr[14];
  int i, j, temp;


  printf("Введіть масив розміром 14: ");
  for (i = 0; i < 14; i++) {
    scanf("%d", &arr[i]);
  }


  for (i = 0, j = 13; i < j; i++, j--) {
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }


  for (i = 0; i < 14; i++) {
    printf("%d ", arr[i]);
  }


  int sum = 0;
  for (i = 11; i <= 13; i++) {
    sum += arr[i];
  }


  printf("\nСума трьох останніх елементів: %d\n", sum);


  scanf("%*c");
  printf("Натисніть Enter для завершення");
getch(0);
  return 0;
}
