#include <stdio.h>

void merge(int *arr, int l, int q, int r) {
    //printf("merging\n");
    int it1 = l;
    int it2 = q + 1;
    int cur = 0;
    int tmp[r - l + 1];
    while (it1 <= q && it2 <= r) {
        if (arr[it1] <= arr[it2]) {
            tmp[cur++] = arr[it1];
            it1++;
        } else {
            tmp[cur++] = arr[it2];
            it2++;
        }
    }
    while (it1 <= q) {
        tmp[cur++] = arr[it1];
        it1++;
    }
    while (it2 <= r) {
        tmp[cur++] = arr[it2];
        it2++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i - l];
    }
}

void mergeSort(int *arr, int l, int r) {
    if (r - l + 1 > 1) {
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