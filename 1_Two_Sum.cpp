class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Return indices in a vector (we can see the return type in the
        // signature of the function)
        vector<int> output;
        
        // Hash map
        // Unordered maps are associative containers that store elements formed 
        // by the combination of a key value and a mapped value
        unordered_map<int, int> residues; //Key: residue Val: index
        
        
        for(int index = 0; index < nums.size(); index++) {
            // search if index is present
            auto it = residues.find(nums[index]);
            
            
            if ( it != residues.end()) {
                output.push_back(it->second);
                output.push_back(index);
                return output;
            }
            else {
                residues[target-nums[index]] = index;
            }
        }
        return output;
    }
        
        
};
