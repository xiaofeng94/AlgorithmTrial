class Solution {
public:
    bool isPowerOfThree(int n) {
        int left = 0;
        int right = 19;
        int mid = (left+right)/2;
        while(left <= right){
            int power = myPower(3,mid);
            if(power == n){
                return true;
            }
            if(power < n){
                left = mid+1;
            }else{
                right = mid-1;
            }
            mid = (left+right)/2;
        }
        return false;
    }
    
    int myPower(int bs,int pr){
        if(pr == 0){
            return 1;
        }
        if(pr == 1){
            return bs;
        }
        if(pr%2 == 0){
            return myPower(bs*bs,pr/2);
        }else{
            return bs*myPower(bs*bs,(pr-1)/2);
        }
    }
};