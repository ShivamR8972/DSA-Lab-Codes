#include <stdio.h>

int LinearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int BinarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int recursive_Bin_Search(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return recursive_Bin_Search(arr, low, mid - 1, key);
    else
        return recursive_Bin_Search(arr, mid + 1, high, key);
}

int main() {
    int n, c, key, result;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid Array Size...\n");
        return 0;
    }

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of key: ");
    scanf("%d", &key);

    printf("1. Linear Search\n2. Binary Search\n3. Recursive Binary Search\n");
    printf("[WARNING: The elements must be sorted in increasing order in order to apply binary search]\n");
    printf("Enter the searching technique: ");
    scanf("%d", &c);

    switch (c) {
        case 1:
            result = LinearSearch(arr, n, key);
            break;
        case 2:
            result = BinarySearch(arr, n, key);
            break;
        case 3:
            result = recursive_Bin_Search(arr, 0, n - 1, key);
            break;
        default:
            printf("Invalid Choice...");
            return 0;
    }
    if (result == -1) {
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index: %d", result);
    }


    ///Enter the Name here:  Ex. printf("Alice/n");
    printf("/n");
    ///Enter the Roll Number here:  Ex. printf("123456789");
    printf("");

    return 0;
}
