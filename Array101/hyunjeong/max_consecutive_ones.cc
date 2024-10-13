class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                count++;
            } else {
                max_count = count > max_count ? count: max_count;
                count = 0;
                // 남아있는 원소 개수가 현재 max_count보다 적으면 더이상 탐색x
                if (nums.size() - i < max_count) break;
            }
        }
        max_count = count > max_count ? count: max_count;
        return max_count;
    }
};