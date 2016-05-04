class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = (left+right)/2;
        while(left < right){
            if(nums[mid] == nums[left] && nums[mid] == nums[right]){
                return findInSeq(nums);
            }
            if(nums[left] <= nums[mid] && nums[mid] <= nums[right]){
                return nums[left];
            }
            if(nums[mid] >= nums[left]){
                left = mid+1;
            }
            if(nums[mid] <= nums[right]){
                right = mid;
            }
            mid = (left+right)/2;
        }
        return nums[mid];
    }
    
    int findInSeq(vector<int>& nums){
        int minRec = INT_MAX;
        for(int i = 0;i < nums.size();++i){
            if(minRec > nums[i]){
                minRec = nums[i];
            }
        }
        return minRec;
    }
};