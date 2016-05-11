class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mymap;
        for(int i = 0;i < nums.size();++i){
            if(mymap.find(nums[i]) == mymap.end()){
                mymap[nums[i]] = 1;
            }else{
                mymap[nums[i]] += 1;
            }
        }
        
        for(int i = 0;i < nums.size();++i){
            if(mymap[nums[i]] == 1){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};