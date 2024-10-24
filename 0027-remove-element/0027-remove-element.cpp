class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 이미 살펴본 원소는 overwrite 해도 됨 => 투 포인터. in-place.
        int target_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[target_idx++] = nums[i];
            }
        }
        
        return target_idx;
    }
};