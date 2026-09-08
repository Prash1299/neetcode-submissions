class Solution {
public:

    int Isequal(vector<int> piles, int mid, int n, int h){

        long long count = 0;

        for(int i=0; i<n; i++){
            
            count = count + ((long long)piles[i] + mid -1)/mid;
            if(count > h){
                return count;
            }
            
        }
        return count;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        
        for(int i = 0; i<n; i++){
            maxi = max(piles[i], maxi);
        }

        int left = 1;
        int right = maxi;

        // search apce is mini->maxi

        int mid = (right + left)/2;
        int ans = 0;

        while(left <= right){
            
            if(Isequal(piles, mid, n, h) <= h){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1; 
            }
            mid = (right + left)/2;
        }

        return ans;;
    }
};
