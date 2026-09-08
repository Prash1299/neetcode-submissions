/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int check1(int target, MountainArray &mountainArr, int ans, int start){
        
        int end = ans;
        int mid1 = (start+end)/2;

        while(start <= end){
            if(mountainArr.get(mid1)==target){
                return mid1;
            }
            else if(mountainArr.get(mid1) > target){
                end = mid1 - 1;
            }
            else{
                start = mid1 + 1;
            }
            mid1 = (start+end)/2;
        }
        return -1;
        
    }

    int check2(int target, MountainArray &mountainArr, int ans, int end){
        
        int start = ans+1;
        int mid2 = (start+end)/2;

        while(start <= end){
            if(mountainArr.get(mid2)==target){
                return mid2;
            }
            else if(mountainArr.get(mid2) > target){
                start = mid2 + 1;
            }
            else{
                end = mid2 - 1;
            }
            mid2 = (start+end)/2;
        }

        return -1;
        
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 0;
        int e = n-1;
        int mid = s+(e-s)/2;
        int ans = 0;

        while(s<e){
            // if(mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) > mountainArr.get(mid+1)){
            //     ans = mid;
            // }
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }

        ans = s;

        if(target == mountainArr.get(ans)){
            return ans;
        }

        int index1 = check1(target, mountainArr, ans, 0);
        if(index1!=-1){
            return index1;
        }
        else{
            return check2(target, mountainArr, ans, n-1);;
        }
        
    }
};

