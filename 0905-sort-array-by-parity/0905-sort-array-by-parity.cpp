class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // 1. 원소가 배열의 앞으로 이동해야하므로 Move Zeroes처럼 overwrite 할 수 없다. (in-place 알고리즘 사용 불가)
        //  => 보조 배열이 필요함
        // 2. 짝수 개수만 세주면 그냥 시작 위치를 정해서 그대로 나열할 수 있음.
        int even_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) even_count++;
        }
        
        int even_pointer = 0;
        int odd_pointer = even_count;
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                result[even_pointer++] = nums[i];
            } else {
                result[odd_pointer++] = nums[i];
            }
        }
        
        return result;
    }
};