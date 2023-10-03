#include <iostream>
#include <vector>

// Function to find the last occurrence of the target element in a sorted array.
//using Binary-search
int findLastOccurrence(int A[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the current element is the target and the next element is not the target.
        if (A[mid] == target && (mid == n - 1 || A[mid + 1] != target)) {
            return mid; // Return the index of the last occurrence.
        } else if (A[mid] <= target) {
            low = mid + 1; // Move to the right half of the array.
        } else {
            high = mid - 1; // Move to the left half of the array.
        }
    }

    return -1; // Return -1 if the target is not found.
}

// Function to find the first occurrence of the target element in a sorted array.
int findFirstOccurrence(int A[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the current element is the target and the previous element is not the target.
        if (A[mid] == target && (mid == 0 || A[mid - 1] != target)) {
            return mid; // Return the index of the first occurrence.
        } else if (A[mid] < target) {
            low = mid + 1; // Move to the right half of the array.
        } else {
            high = mid - 1; // Move to the left half of the array.
        }
    }

    return -1; // Return -1 if the target is not found.
}

// Function to find both the first and last occurrences of the target element.
std::vector<int> findFirstLastOccurrence(int A[], int n, int target) {
    std::vector<int> firstLast(2, -1);
    firstLast[0] = findFirstOccurrence(A, n, target);
    firstLast[1] = findLastOccurrence(A, n, target);

    return firstLast;
}

int main() {
    int A[] = {1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    int target = 2;

    std::vector<int> result = findFirstLastOccurrence(A, n, target);

    if (result[0] != -1 && result[1] != -1) {
        std::cout << "First occurrence: " << result[0] << ", Last occurrence: " << result[1] << std::endl;
    } else {
        std::cout << "Target element not found." << std::endl;
    }

    return 0;
}
