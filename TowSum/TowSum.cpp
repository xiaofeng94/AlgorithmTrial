class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int *pos = new int[nums.size()];
        for(int i = 0; i < nums.size();++i){
            pos[i] = i;
        }
        
        int low = 0;
        int high = nums.size()-1;
        int record = target/2;
        while(low < high){
            while(low < high && nums[high] >= record){
                --high;
            }
            while(low < high && nums[low] < record){
                ++low;
            }
            if (low < high) {
                int temp = nums[high];
                nums[high] = nums[low];
                nums[low] = temp;
                // int tempIndx = high;
                pos[low] = high;
                pos[high] = low;
            }
        }
        
        for(int i = 0;i <= low+1;++i){
            int j = low+1;
            if (i == low+1) {
                j = i+1;
            }
            for(;j < nums.size();++j){
                if(nums[i] + nums[j] == target){
                    if(pos[i] > pos[j]){
                        res.push_back(pos[j]);
                        res.push_back(pos[i]);
                    }else{
                        res.push_back(pos[i]);
                        res.push_back(pos[j]);
                    }
                    delete[]pos;
                    return res;
                }
            }
        }
        delete[]pos;
        return res;
    }
};