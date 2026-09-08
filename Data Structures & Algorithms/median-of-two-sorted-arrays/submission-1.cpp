class Solution {
public:

// Time complex = O(n, m)

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i =0;
        int j =0;
        vector<int> num;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                num.push_back(nums1[i]);
                i++;
            }
            else{
                num.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            num.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            num.push_back(nums2[j]);
            j++;
        }

        double median = 0.0;
        int k = m+n;

        if(k%2!=0){
            return median = num[k/2];
        }
        else{
            return median = (num[k/2]+num[(k/2)-1])/2.0;
        }
    }
};
