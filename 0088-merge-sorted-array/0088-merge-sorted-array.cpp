class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Duplicate Zeros와 유사한 보조배열 문제인듯
        vector<int> target_arr(m + n);
        
        int idx1 = 0;
        int idx2 = 0;
        int target_idx = 0;
        while (idx1 < m && idx2 < n) {
            if (nums1[idx1] < nums2[idx2]) {
                target_arr[target_idx++] = nums1[idx1++];
            } else {
                target_arr[target_idx++] = nums2[idx2++];
            }
        }
        // 하나의 배열이라도 모두 순회했으면 더 이상 두 배열의 원소를 비교할 수 없다.
        if (idx1 < m) {
            while (target_idx < m + n)
                target_arr[target_idx++] = nums1[idx1++];
        }
        if (idx2 < n) {
            while (target_idx < m + n)
                target_arr[target_idx++] = nums2[idx2++];
        }
        
        // 보조 배열의 원소를 nums1에 복사
        for (int i = 0; i < m+n; ++i) {
            nums1[i] = target_arr[i];
        }
    }
};