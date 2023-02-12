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
        while (arr[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(&arr[i++], &arr[j--]);
    }
    return j;
}

void quickSort(int *arr, int l, int r) {
    if (l < r) {
        int q = partition(arr, l, r);
        quickSort(arr, l, q);
        quickSort(arr, q + 1, r);
    }
}

void merge(int *arr, int l, int q, int r) {
    int it1 = l, it2 = q + 1, tmp[r - l + 1];
    int cur = 0;
    while (it1 <= q && it2 <= r) {
        if (arr[it1] < arr[it2]) {
            tmp[cur++] = arr[it1++];
        } else {
            tmp[cur++] = arr[it2++];
        }
    }
    while (it1 <= q) {
        tmp[cur++] = arr[it1++];
    }
    while (it2 <= r) {
        tmp[cur++] = arr[it2++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i - l];
    }
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int q = (l + r) / 2;
        mergeSort(arr, l, q);
        mergeSort(arr, q + 1, r);
        merge(arr, l, q, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}