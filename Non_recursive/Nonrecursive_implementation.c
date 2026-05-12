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
    // Test case 1
    int arr1[] = {10, 50, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Test 1 Result: %d\n", Brute_force(arr1, n1)); // Expected: 0

    // Test case 2
    int arr2[] = {10, 2, 5, 1, 8, 20};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Test 2 Result: %d\n", Brute_force(arr2, n2)); // Expected: 1

    return 0;
}
