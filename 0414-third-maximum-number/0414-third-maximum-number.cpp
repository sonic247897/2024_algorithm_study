class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // try #1 - 실패 
        // 길이가 3인 max 배열을 모든 원소에 대해서 비교하면 됨 - O(3N)
        // 근데 nums[i]의 하한이 int 범위라 max 배열의 초기화가 어려움 => 초기화 값을 nums 배열의 첫 3개 값(실존하는 값)으로 설정하면 됨
        //  => 아니다. 위 방법을 쓰려면 max 배열 내에서 '비교'뿐 아니라 '정렬'도 필요함!
        
        // try #2
        // 진짜 단순하게.. 선형 탐색으로 1st 찾아서 지우고, 그 다음 탐색으로 또 2nd 지우고, 마지막 탐색으로 3rd 를 찾는 방법이 있음. (이진 탐색하려면 정렬부터 해야해서 NlogN 복잡도) => O(3N)
        // ex) [3, 3, 3, 3, 2, 2, 2]
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }

        // 무조건 존재함 ex) [1]
        int first_max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= first_max) first_max = nums[i];
        }
        
        bool second_exist = false;
        int second_max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < first_max && nums[i] >= second_max) {
                second_max = nums[i];
                second_exist = true; // second_max 값이 실제로 INT_MIN인 경우 second_exist가 true/false인지 판단할 수 없다.
            }
        }
        
        if (second_exist) {
            bool third_exist = false;
            int third_max = INT_MIN;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < second_max && nums[i] >= third_max) {
                    third_max = nums[i];
                    third_exist = true;
                }
            }
            
            if (third_exist) return third_max;
        }
        
        return first_max;
    }
};