class Solution {
public:
    int findMin(vector<int>& nums) {
        int minn = INT_MAX;
        int low = 0;
        int high = nums.size() - 1;
        while( low <= high){
            int mid = low + ( high - low ) / 2;
            if( nums[mid] == nums[low] && nums[mid] == nums[high]){
                minn = min( minn,nums[low]);
                high -=1;
                low += 1;
                continue;
            }
            if( nums[low] <= nums[mid]){
                minn = min( minn, nums[low]);
                low = mid + 1;
            }
            else{
                minn = min(minn, nums[mid]);
                high = mid - 1;
            }
        }
        return minn;
        
    }
};