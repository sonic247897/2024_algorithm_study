class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Follow-up: Could you solve the problem in linear time and in O(1) space?
        // 1. cs - nums 배열의 길이제한 5*10^4는 int로 표현할 수 있다.
        //      - 추가 공간이 없다면 배열 내부에서 in-operation을 해야함. 포인터 몇 개 정도는 O(1)임.
        // 2. 수학 - 당연히 발생빈도수를 세야 하지만, 그 정보를 저장할 자료구조는 없는 상황 (majority number를 제외하면 최대 (5*10^4)/2 종류의 정수가 존재할 수 있다)
        //          => 포인터로 1, 2, 3 순위만 유지하는건? - 초반 분포와 후반의 분포가 다를수 있음.
        //      - 절반을 넘게 비중을 차지하는 수가 항상 존재한다는 점을 이용한다면? => Moore Voting Algorithm

        // 1. Initialize two variables: count and candidate. Set count to 0 and candidate to an arbitrary value.
        int count = 0;
        int candidate = nums[0];

        // 2. Iterate through the array nums: O(N) - it traverses the array once!
        //  a. If count is 0, assign the current element as the new candidate and increment count by 1.
        //  b. If the current element is the same as the candidate, increment count by 1.
        //  c. If the current element is different from the candidate, decrement count by 1.
        for (int num : nums) {
            if (count == 0) candidate = num;

            if (num == candidate) count++;
            else count--;
        }

        // 3. After the iteration, the candidate variable will hold the majority element.
        return candidate;
    }
};