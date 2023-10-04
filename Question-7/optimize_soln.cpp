#include<iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        // Check if the input number is less than or equal to 0.
        // If it is, return false since ugly numbers are defined as positive integers.
        if (n <= 0) {
            return false;
        }
        
        // Use a while loop to repeatedly divide the number by 2, 3, or 5
        // as long as it is divisible by any of these primes.
        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else if (n % 3 == 0) {
                n = n / 3;
            } else if (n % 5 == 0) {
                n = n / 5;
            } else {
                // If the number is not divisible by 2, 3, or 5,
                // it cannot be an ugly number, so break out of the loop.
                break;
            }
        }
        
        // After the loop, check if the remaining number is 1.
        // If it is, the original number was an ugly number, so return true.
        return (n == 1);
    }
};

int main() {
    Solution solution;
    
    // Test cases
    int num1 = 6;  // 6 is an ugly number (2 * 3)
    int num2 = 8;  // 8 is an ugly number (2 * 2 * 2)
    int num3 = 14; // 14 is not an ugly number
    
    bool result1 = solution.isUgly(num1);
    bool result2 = solution.isUgly(num2);
    bool result3 = solution.isUgly(num3);
    
    // Print the results for each test case
    cout << num1 << " is ugly? " << (result1 ? "Yes" : "No") << endl;
    cout << num2 << " is ugly? " << (result2 ? "Yes" : "No") << endl;
    cout << num3 << " is ugly? " << (result3 ? "Yes" : "No") << endl;
    
    return 0;
}
