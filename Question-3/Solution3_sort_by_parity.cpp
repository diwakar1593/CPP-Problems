class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> sortParity;
        for(auto i = 0 ; i < nums.size() ; i++){
            if(nums[i]%2 == 0)
                sortParity.push_back(nums[i]);
        }
        for(auto i = 0 ; i < nums.size() ; i++){
            if(nums[i]%2 == 1)
                sortParity.push_back(nums[i]);
        }
        return sortParity;
    }
};
