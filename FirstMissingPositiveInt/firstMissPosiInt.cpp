class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() <= 0){
            return 1;
        }
        for(int i = 0;i < nums.size();){
            
            if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i+1){
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }else{
                ++i;
            }
        }
        
        int indx = 0;
        while(nums[indx] == indx+1){
            ++indx;
        }
        
        return indx+1;
    }
    
};