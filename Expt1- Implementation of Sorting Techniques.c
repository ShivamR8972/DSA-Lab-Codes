#include <stdio.h>

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                flag = 0;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag)
            break;
    }
}

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;
    return i + 1;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void CountingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n, c;
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

    printf("Elements before sorting are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n"
           "4. Quick Sort\n5. Merge Sort\n6. Counting Sort\n");
    printf("Enter the Method of Sorting: ");
    scanf("%d", &c);

    switch (c) {
        case 1:
            BubbleSort(arr, n);
            printf("Elements after applying BubbleSort: ");
            break;
        case 2:
            SelectionSort(arr, n);
            printf("Elements after applying SelectionSort: ");
            break;
        case 3:
            InsertionSort(arr, n);
            printf("Elements after applying InsertionSort: ");
            break;
        case 4:
            QuickSort(arr, 0, n - 1);
            printf("Elements after applying QuickSort: ");
            break;
        case 5:
            MergeSort(arr, 0, n - 1);
            printf("Elements after applying MergeSort: ");
            break;
        case 6:
            CountingSort(arr, n);
            printf("Elements after applying CountingSort: ");
            break;
        default:
            printf("Invalid Choice...\n");
            break;
    }

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }


    ///Enter the Name here:  Ex. printf("Alice/n");
    printf("/n");
    ///Enter the Roll Number here:  Ex. printf("123456789");
    printf("");

    return 0;
}
