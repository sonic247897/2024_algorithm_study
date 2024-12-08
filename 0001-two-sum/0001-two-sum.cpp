class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
        // 1. cs - 배열은 정렬, 탐색, 투(three)포인터
        // 2. 수학 - nums[a] + nums[b] = target 식을 만족함. nums 배열의 for 문을 돌면 nums[a]와 target 두 가지 정보를 알게 되고, nums[b]만 찾으면 된다. 
        //  => 세 정보(변수)가 위와 같은 수식을 만족하기 때문에, 수학적 계산을 통해 탐색 과정을 단축할 수 있다. nums[b] = target - nums[a] 에서 key-value를 nums[a]-a 인 해시맵으로 저장 (Only one valid answer exists. 조건 때문에 가능)
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); ++i) {
            // 검사
            if (map.contains(target - nums[i])) {
                return vector<int> { map[target - nums[i]], i };
            }
            // hash map에 저장
            map[nums[i]] = i;
        }
        return vector<int> { -1 };
    }
};