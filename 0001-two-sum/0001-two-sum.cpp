class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // stores value -> index
        for(int i=0; i<nums.size(); i++) {
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i}; // found two indices
            }
            mp[nums[i]] = i; // store current value with index
        }
        return {}; // not expected as per problem guarantee
    }
};