class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int expectedSum = nums.size()*(nums.size() + 1)/2;
        int actualSum = 0;
        
        // for(int i : nums) {
        // // for (int i = 0; i < nums.size(); i++){
        //     actualSum += i;
        // }
        
        for (auto it = begin (nums); it != end (nums); ++it) {
            actualSum += *it;
        }
        return expectedSum - actualSum;
    }
};
