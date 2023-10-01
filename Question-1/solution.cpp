#include <iostream>
#include <vector>

using namespace std;

int findFirstPosition(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int firstPosition = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            firstPosition = mid;
            right = mid - 1; // Move to the left to find the first occurrence
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return firstPosition;
}

int findLastPosition(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int lastPosition = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            lastPosition = mid;
            left = mid + 1; // Move to the right to find the last occurrence
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return lastPosition;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int first = findFirstPosition(nums, target);
    int last = findLastPosition(nums, target);

    if (first != -1 && last != -1) {
        cout << "First position: " << first << endl;
        cout << "Last position: " << last << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
