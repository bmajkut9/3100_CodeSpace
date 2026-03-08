#include <stdio.h>
#include <stdlib.h>

void print_elements(char **elems, int count) {
  for (int i = 0; i < count; i++) {
    printf("%s\n", elems[i]);
  }
}

void odd_sort(char **elems, int count) {
  int *odd_place_arr[count];
  for (int i = 0; i < count; i++) {
    
    int odd_count = 0;
    
    int curr = atoi(*elems[i]);
    //int curr = *conv;
    while (curr != 0) {
      if (curr % 2 != 0 && curr % 4 != 0  && curr % 6 != 0 && curr % 8 != 0) {
        odd_count++;
      }
      curr /= 10;
    }
    *odd_place_arr[i] = odd_count;
  }
  for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count - 1; j++)
    if (odd_place_arr[j] > odd_place_arr[j+1]) {
      int temp = odd_place_arr[j];
      char temp_char = *elems[j];
      odd_place_arr[j] = odd_place_arr[j + 1];
      odd_place_arr[j+1] = temp;
      *elems[j] = *elems[j + 1];
      *elems[j + 1] = temp_char;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    perror("Usage : ./place <strings>");
    exit(1);
  }
  odd_sort(&argv[1], argc - 1);
  print_elements(&argv[1], argc - 1);

  return 0;
}
