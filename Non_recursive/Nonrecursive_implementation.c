#include <stdio.h>

// Function to check if three numbers can form a triangle
int isTriangle(int a, int b, int c) {
    if (a + b > c && b + c > a && c + a > b)
        return 1;
    return 0;
}

// Brute force function (non-recursive)
int Brute_force(int A[], int n) {
    // Try all triplets
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                
                if (isTriangle(A[i], A[j], A[k])) {
                    return 1; // valid triangle
                }
            }
        }
    }
    return 0; // No triangle found
}


int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    int result = Brute_force(arr, n);


    if (result == 1)
        printf("Valid triangle exists\n");
    else
        printf("No valid triangle\n");

    return 0;
}

