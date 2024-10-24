class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 1. 수학적으로 [1, n] 범위에 없는 숫자가 존재하려면, 반대로 중복되는 숫자가 존재해야 한다.
        // 2. CS - extra space가 있으면 쉽게 풀 수 있다. Height Checker와 유사하게
        int n = nums.size();
        vector<bool> num_exist(n + 1); // [1, n]
        
        for(int i = 0; i < n; ++i) {
            num_exist[nums[i]] = true;
        }
        
        int count = 0;
        for(int i = 1; i < n + 1; ++i) {
            if(!num_exist[i]) count++;
        }
        int target_idx = 0;
        vector<int> not_exist(count);
        for(int i = 1; i < n + 1; ++i) {
            if(!num_exist[i]) {
                not_exist[target_idx++] = i;
            }
        }
        
        return not_exist;
    }
};