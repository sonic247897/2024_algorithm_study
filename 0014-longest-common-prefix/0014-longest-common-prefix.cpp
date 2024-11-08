class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 1. cs - string 사이즈가 커지면서 중간중간 메모리에 동적으로 재할당할 때 시간이 오래 걸릴것. 즉, string 사이즈를 최대한 정답에 가깝게 예측해서 미리 할당해두는 것이 이 문제의 키포인트일까?
        /* linear search */
        string res = "";
        int size = strs.size();

        int min_str_size = 987654321;
        for (int i = 0; i < size; ++i) {
            min_str_size = strs[i].size() < min_str_size ? strs[i].size() : min_str_size; 
        }
        
        for (int i = 0; i < min_str_size; ++i) {
            char tmp = strs[0][i];
            for (int j = 1; j < size; ++j) {
                if (strs[j][i] != tmp) {
                    return res;
                }
            }
            res += tmp;
        }
        
        return res;
    }
};