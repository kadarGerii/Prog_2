#include "functions.h"

int main() {
    int a[] = {1, 4, 4, 1, 5,5};
    int i = 0;
    int j = 6;
    printf("\n%d\n", a[maximum(a, 0, j-1)]);
    mergeSort(a, 0, j-1);
    for ( i = 0; i < j; ++i) {
        printf("%d ", a[i]);
    }
    printf("\nsum: %d", sum(a, i, j));
    return 0;
}
