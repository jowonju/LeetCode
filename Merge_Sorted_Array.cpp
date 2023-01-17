class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
        //solution1
        if(m == m + n)
            return ;
        
        for(int i = m, j = 0; j < n; i++, j++)
        {       
            nums1[i] = nums2[j];
        }
        
        sort(nums1.begin(), nums1.end());

        //solution 2
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 and j >= 0) {
            if(nums1[i] < nums2[j]) {
                nums1[k--] = nums2[j--];
            } else {
                nums1[k--] = nums1[i--];
            }
        }
        
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
};