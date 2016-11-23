class Solution {
    public:
        double kth(vector<int> & v1,vector<int> & v2, int i, int j, int k) {
            int n = v1.size(), m = v2.size(), inf = 0x7fffffff, mid = k >> 1;
            if(i >= n) return v2[j + k - 1];
            if(j >= m) return v1[i + k - 1];
            if(k == 1) return min(v1[i], v2[j]);
            int v1m = i + mid - 1 >= n ? inf : v1[i + mid - 1];
            int v2m = j + mid- 1 >= m ? inf : v2[j + mid - 1];
            if(v1m < v2m) return kth(v1, v2, i + mid, j, k - mid);
            else return kth(v1, v2, i, j + mid, k - mid);
        }
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int mn = nums1.size() + nums2.size(), mid = mn >> 1;
            if(mn & 1) return kth(nums1, nums2, 0, 0, mid + 1);
            else return (kth(nums1, nums2, 0, 0, mid) + kth(nums1, nums2, 0, 0, mid + 1)) * 0.5;
        }
};
