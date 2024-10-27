class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // 크기 비교 문제 등을 풀 때 음수가 코너 케이스가 되는 경우가 많았는데, 이 문제는 음수 범위x
        // 1. 최대값 찾고, 두 번째 최대값 찾아서 2배 곱해서 크기 비교 (third maximum 문제와 유사한듯?)
        //   => 전체를 정렬하면 O(nlogn)이 걸림. 근데 max, second_max, 현재원소 값 3개를 정렬하는건 상수시간 고정이라 O(1)일듯. 정렬하면서 순회하면 전체적으로 O(n)
        // 2. 하지만 index를 리턴해야 하므로 index 정보도 같이 저장해야 함
        
        // 초기화
        int max, second_max, max_idx = -1;
        if (nums[0] > nums[1]) {
            max = nums[0];
            second_max = nums[1];
            max_idx = 0;
        } else {
            max = nums[1];
            second_max = nums[0];
            max_idx = 1;
        }
        
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] > max) {
                second_max = max;  
                max = nums[i];
                max_idx = i;
            } else if (nums[i] > second_max) {
                second_max = nums[i];
            }
        }
        
        if (max >= second_max*2) return max_idx;
        return -1;
    }
};