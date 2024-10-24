class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* 투 포인터 */
        int target_idx = 1; // 배열의 첫 번째 원소는 그대로 둔다.
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] != nums[i]) {
                nums[target_idx++] = nums[i];
            }
        }
        return target_idx;
    }
};