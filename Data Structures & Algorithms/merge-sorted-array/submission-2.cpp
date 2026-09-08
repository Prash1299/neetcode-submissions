class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int k = m;
        while(i<n && k<m+n){
            swap(nums1[k], nums2[i]);
            k++;
            i++;
        }
        sort(nums1.begin(), nums1.end());
        
    }
};