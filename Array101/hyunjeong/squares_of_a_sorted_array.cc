class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 1. 수학적으로 제곱수의 비교는 원소의 절대값을 비교하는 것과 같음. 따라서 양수와 음수의 기준인 '0'에 가장 가까운 값을 target 배열의 시작값으로 둬야함.
        // 2. CS 배경지식 - 투 포인터 알고리즘을 수행하기 위해 추가 배열(target_arr)을 선언함. 처음에는 공간 복잡도를 늘릴 생각을 못 해서 원본 배열 1개만으로 어떻게 정렬하지? 같은 바보같은 생각을 했음..
        
        // 1) for문 돌면서 제곱한 값을 원소에 넣어주고 0에 가장 가까운 값 찾기. 해당 원소의 index 저장(m)
        // 2) 투 포인터 - pointer#1 [0, m-1] 범위 탐색(역순)/ m / pointer#2 [m+1, n] 범위 탐색
        int min_idx = -1;
        int min = 987654321;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] *= nums[i];
            if (nums[i] < min) {
                min = nums[i];
                min_idx = i;
            }
        }
        
        vector<int> target_arr(nums.size());
        target_arr[0] = nums[min_idx];
        int target_idx = 1;
        int pointer_1 = min_idx - 1;
        int pointer_2 = min_idx + 1;
        while (pointer_1 >= 0 && pointer_2 < nums.size()) {
            // 작거나 같은 값 선택
            int value = -1;
            if (nums[pointer_1] <= nums[pointer_2]) {
                value = nums[pointer_1--];
            } else {
                value = nums[pointer_2++];  
            }
            target_arr[target_idx++] = value;
        }
        // 남은 값들 순차적으로 target_arr에 삽입
        if (pointer_1 < 0) {
            while (target_idx < nums.size()) {
                target_arr[target_idx++] = nums[pointer_2++];
            }
        }
        if (pointer_2 >= nums.size()) {
            while (target_idx < nums.size()) {
                target_arr[target_idx++] = nums[pointer_1--];
            }
        }
        
        return target_arr;
    }
};
