// Approach- 
// To solve the "Sort Array By Parity" problem using the two-pointer approach:
// i and j: Two pointers initialized to the start and end of the array, respectively.
// Enhanced Breakdown:
// Initialization:

// Initialize i to 0 and j to the last index of the array.
// While Loop:

// Keep iterating until i is less than j.
// Increment i if the element at i is even.
// Decrement j if the element at j is odd.
// Swap the elements at i and j if the above conditions aren't met.
// Return the Modified Array:

// After the loop completes, the array will be sorted by parity.

// CODE

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j = n-1;
        while(i<j){
            while(i<j && nums[i]%2 == 0) i++;
            while(i<j && nums[j]%2 != 0) j--;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};
