class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 수학적으로 1 증가시키면 999 + 1 = 1000 처럼 최대 1자리수가 증가할 수 있음
        // 덧셈은 least significant 부터 계산하기 때문에 배열을 역순회한다.
        bool vector_sizeup = false;
        
        for (int i = digits.size() - 1 ; i >= 0; --i) {
            if (++digits[i] == 10) {
                digits[i] = 0;
                if (i == 0) vector_sizeup = true;
            } else {
                break;
            }
        }
        
        // 벡터 크기 + 1로 재할당
        if (vector_sizeup) {
            vector<int> res(digits.size() + 1);
            res[0] = 1;
            for (int i = 0; i < digits.size(); ++i) {
                res[i + 1] = digits[i];
            }
            return res;
        }
        return digits;
    }
};