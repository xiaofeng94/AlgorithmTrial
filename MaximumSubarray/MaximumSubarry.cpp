class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int lsum = nums[0];
        // int lastSum = nums[0];
        int currSum = nums[0];

        for(int i = 1;i < nums.size();++i){
            if(currSum < 0){
                    currSum = nums[i];
                    // lastSum = nums[i];
            }else{
                currSum += nums[i];
                // lastSum = currSum;
            }
            
            if(lsum < currSum){
                lsum = currSum;
            }
        }
        
        return lsum;
    }
    
};