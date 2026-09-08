class Solution {
public:
    int mySqrt(int x) {
        
        int l = 0;
        int r = x;
        int ans = 0;

        long long m = l + (r-l)/2;

        while(l<=r){
            if((long long)m*m == x){
                return m;
            }
            else if((long long)m*m > x){
                r = m-1;
            }
            else{
                ans = m;
                l = m + 1;
            }
            m = l + (r-l)/2;

        }

        return ans;
    }
};