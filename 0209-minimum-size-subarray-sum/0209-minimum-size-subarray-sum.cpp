class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 1. 수학 - 규칙 세우기. 추가배열에 누적합을 저장하지 않고, 좀 더 복잡한 규칙을 정해서 값을 저장한다.
        //  => sum >= target 인 min(right_idx - left_idx + 1) 값 저장 (left_idx < right_idx)
        // positive integers 라는 조건도 활용하면 좋다. => left_idx가 커질수록 sum이 작아지게 된다. sum 중에 최소값을 찾는게 유리하므로 left_idx를 0부터 시작해서 점점 증가시키면서 조건을 확인한다.
        /* 투 포인터 */
        if (nums[0] >= target) return 1;
        
        vector<int> min_length(nums.size(), 987654321);
        
        // min_length[0] = 987654321;
        int sum = nums[0];
        int left_idx = 0;
        for (int right_idx = 1; right_idx < nums.size(); ++right_idx) {
            sum += nums[right_idx];
            if (sum < target) continue;
            min_length[right_idx] = right_idx - left_idx + 1; // 길이 저장
            
            while (left_idx < right_idx) {
                sum -= nums[left_idx];
                left_idx++;
                if (sum >= target) {
                    min_length[right_idx] = right_idx - left_idx + 1; // 길이 저장
                } else { // 조건문 시도해보고 실패하면 직전 상태 복원
                    left_idx--;
                    sum += nums[left_idx];
                    break;
                }
            }
        }
        
        int min = 987654321;
        for (int i = 0; i < min_length.size(); ++i) {
            min = min_length[i] < min ? min_length[i] : min;
        }
        if (min == 987654321) return 0;
        return min;
    }
};