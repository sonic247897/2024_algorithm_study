class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /* 투 포인터 */
        // input array 원소들의 순서를 지켜야 하므로 정방향 순회. 0은 개수를 따로 세서 나중에 배열 길이만큼 채워주면 됨.
        int count_zero = 0;
        int target_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                count_zero++;
            } else {
                nums[target_idx++] = nums[i];
            }
        }
        
        for (int i = target_idx; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};