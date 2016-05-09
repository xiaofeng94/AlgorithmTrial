class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 || k < 0){
            return;
        }
        k = k%nums.size();
        vector<int> temp;
        for(int i = 0;i < nums.size()-k;++i){
            temp.push_back(nums[i]);
        }
        for(int i = 0;i < k;++i){
            nums[i] = nums[nums.size()-k+i];
        }
        for(int i = k;i < nums.size();++i){
            nums[i] = temp[i-k];
        }
    }
};