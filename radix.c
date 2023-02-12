#include <stdio.h>
#include <minwindef.h>

int cnt(int num) {
    num /= 10;
    int i = 1;
    while (num > 0) {
        i++;
        num /= 10;
    }
    return i;
}

int get_dig(int num, int k) {
    for (int i = 0; i < k - 1; i++) {
        num /= 10;
    }
    return num % 10;
}

void radix_sort(int *arr, int n) {
    int mlen = 0;
    for (int i = 0; i < n; i++) {
        mlen = max(mlen, cnt(arr[i]));
    }
    for (int k = 1; k <= mlen; k++) {
        int tmp[10][n];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = -1;
            }
        }
        for (int ind = 0; ind < n; ind++) {
            int i = get_dig(arr[ind], k);
            int j = 0;
            while (tmp[i][j] != -1) j++;
            tmp[i][j] = arr[ind];
        }
        int cur = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; tmp[i][j] != -1; j++) {
                arr[cur] = tmp[i][j];
                cur++;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    radix_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}