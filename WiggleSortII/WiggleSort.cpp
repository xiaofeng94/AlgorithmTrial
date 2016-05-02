class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        int midIndx  = ((nums.size()&1) == 0?nums.size()/2:nums.size()/2+1);
        for(int i = 0;i < midIndx/2;++i){
            int temp = nums[i];
            nums[i] = nums[midIndx-i-1];
            nums[midIndx-i-1] = temp;
        }
        for(int i = midIndx;i < nums.size()-midIndx/2;++i){
            int temp = nums[i];
            nums[i] = nums[nums.size()-i-1+midIndx];
            nums[nums.size()-i-1+midIndx] = temp;
        }
        vector<int> nums2(nums);
        
        for(int i = 0;i < nums2.size();i+=2){
            nums[i] = nums2[i/2];
            nums[i+1] = nums2[midIndx++];
        }
    }
    
    void quickSort(vector<int>& nums,int left,int right){
        if(left >= right){
            return;
        }
        int low = left;
        int high = right;
        int record = nums[low];
        while(high > low){
            while(high > low && nums[high] >= record){
                --high;
            }
            nums[low] = nums[high];
            while(high > low && nums[low] < record){
                ++low;
            }
            nums[high] = nums[low];
        }
        nums[low] = record;
        quickSort(nums, low+1, right);
        quickSort(nums, left, low-1);
    }
};