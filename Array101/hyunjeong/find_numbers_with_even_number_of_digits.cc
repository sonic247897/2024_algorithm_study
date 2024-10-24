class Solution {
public:
    int findNumbers(vector<int>& nums) {
        // 1. CS 배경지식 
        //    - 자릿수와 관련한 연산인 나누기, 곱하기 연산이 무거운 연산이었던 걸로 기억함
        //      => 그래서 처음에는 if문 내부에서 비교 연산자를 사용하면, 내부적으로 빼기/더하기 연산을 해서 비교하기 때문에 더 가볍다고 생각하여 아래와 같이 작성함.
        //         하지만 결과적으로 나누기 연산으로 푸는게 속도가 더 빨랐기 때문에 다시 조사해봐야 할듯
        //        int count = 0;
        //        for(int i = 0; i < nums.size(); ++i) {
        //            if ((nums[i] >= 10 && nums[i] < 100) || (nums[i] >= 1000 && nums[i] <10000) || (nums[i] == 100000)) {
        //                count++;
        //            }
        //        }
        //        return count;
        //    - 자릿수 세는 기준이 10진수이기 때문에 2진수를 사용하는 shift 연산이나 bitwise 연산을 활용하기는 어렵지 않을까?
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            int digit = 0;
            while (tmp != 0) {
                tmp /= 10;
                digit++;
            }
            if (digit % 2 == 0) count++;
        }
        return count;
    }
};