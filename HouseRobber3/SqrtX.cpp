
class Solution {
public:
    int mySqrt(int x) {
//        if (x == 1) {
//            return 1;
//        }
        double left = 0;
        double right = x;
        double mid = (left/2+right/2);
        double mid2 = mid*mid;
        int loop = 0;
        while(loop < 100){
            if(mid2 <= x ){
                left = mid;
            }
            if(mid2 >= x){
                right = mid;
            }
            mid = (double)(left+right)/2;
            
            mid2 = mid*mid;
            loop++;
        }
        
        return (mid);
    }
};