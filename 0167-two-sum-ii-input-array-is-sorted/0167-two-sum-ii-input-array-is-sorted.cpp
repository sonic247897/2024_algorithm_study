class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // @ 시간 복잡도는 괜찮으나 공간 복잡도가 좋지 않음. key-value로 저장하려면, 배열 말고 map을 쓰는게 나을듯
        // 정답이 단 1쌍만 존재하고, 원소값의 범위가 [-1000, 1000]으로 작기 때문에 '값-index' 배열을 이용한다면?
        // => X. 같은 원소가 존재하는 경우가 있음. ex) [1, 3, 3, 4], target = 6
        // 그렇다면 정렬되었다는 조건을 이용해야 함. 위의 edge case에서만 배열 말고 '조건문'으로 검증하면 될듯 (바로 인접한 두 원소값이 같고, 해당 원소값을 2배하면 target 값과 같아지는 경우 정답)
        vector<int> saved_index(2001, -1); // [-1000, 1000]
        saved_index[numbers[0] + 1000] = 0;
        for (int i = 1; i < numbers.size(); ++i) {
            if (numbers[i] == numbers[i-1] && numbers[i]*2 == target) {
                // 1개 솔루션만 존재하기 때문에 i와 i-1이 다른 수와 더해서 target이 되는 경우는 존재하지 않는다.
                return { i, i+1 }; 
            } else {
                saved_index[numbers[i] + 1000] = i; 
            }
        }
        
        // 두 원소값 더해서 target과 일치하는 index쌍 찾기
        for (int i = 0; i < numbers.size(); ++i) {
            int required_num = target - numbers[i];
            // @ heap-buffer-overflow 예외처리 (이 부분 놓침)
            if (required_num < -1000 || required_num > 1000) continue;
            if (saved_index[required_num + 1000] != -1) {
                return { i+1, saved_index[required_num + 1000]+1 };
            }   
        }
        
        // should not reach here
        return { -1 };
    }
};