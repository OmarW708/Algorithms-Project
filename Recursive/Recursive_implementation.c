#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int isTriangle(int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}

// ----------- Merge Sort -----------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1)
        arr[k++] = leftArr[i++];

    while (j < n2)
        arr[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

// ----------- Recursive Optimization -----------
int recursiveSolution(int arr[], int n, int idx) {
    if (idx + 2 >= n) return 0;
    if (isTriangle(arr[idx], arr[idx + 1], arr[idx + 2])) return 1;
    return recursiveSolution(arr, n, idx + 1);
}

int optimisedSolutionRecursive(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
    return recursiveSolution(arr, n, 0);
}

// ----------- Solve -----------
void solve() {
    int arr1[] = {10, 50, 1};
    int arr2[] = {10, 2, 5, 1, 8, 20};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("%d\n", optimisedSolutionRecursive(arr1, n1));
    printf("%d\n", optimisedSolutionRecursive(arr2, n2));
}

int main() {
    solve();
    return 0;
}
