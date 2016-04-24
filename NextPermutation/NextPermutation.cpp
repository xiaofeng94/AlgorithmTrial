class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int indx = nums.size()-1;
        while(indx > 0){

            if(nums[indx-1] < nums[indx]){
                break;
            }
            --indx;
        }
        if(indx >= 1){
            int currNum = nums[indx-1];
            int pos = nums.size()-1;
            while(pos >= indx){
                if(nums[pos] > currNum){
                    break;
                }
                --pos;
            }
            int temp = nums[pos];
            nums[pos] = nums[indx-1];
            nums[indx-1] = temp;
            
        }
        quickSort(nums, indx, nums.size()-1);
        
    }
    
    void quickSort(vector<int>& nums,int left,int right){
    if(left >= right){
        return;
    }
        int low = left;
        int hight = right;
        int base = nums[left];
        while(low < hight){
            while(low < hight && nums[hight] >= base){
                hight--;
            }
            nums[low] = nums[hight];
            while(low < hight &&  nums[low] <= base){
                low++;
            }
            nums[hight] = nums[low];
        }
        nums[low] = base;
        
        quickSort(nums,low+1,right);
        quickSort(nums,left,low-1);
    }
};



