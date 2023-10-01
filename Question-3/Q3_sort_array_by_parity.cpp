class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        std::vector<int> answer;
        for (int x: nums) {
            if (x % 2 == 0) {
                result.push_back(x);
            }
        }
        for (int y : nums) {
            if (y % 2 != 0) {
                result.push_back(y);
            }
        }
        return answer;
    }
};