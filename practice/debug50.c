#include <stdio.h>

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    print_array(numbers, size);
    return 0;
}
