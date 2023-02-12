#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int l, int r) {
    int v = arr[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (arr[i] < v) {
            i++;
        }
        while (arr[j] > v]) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(&arr[i++], &arr[j--]);
    }
    return j;
}

void quick_sort(int *arr, int l, int r) {
    if (l < r) {
        int q = partition(arr, l, r);
        quick_sort(arr, l, q);
        quick_sort(arr, q + 1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}