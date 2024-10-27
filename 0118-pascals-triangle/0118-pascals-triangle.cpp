class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // dynamic array !
        vector<vector<int>> res(numRows);
        res[0] = { 1 };
        for (int i = 1; i < numRows; ++i) {
            // 동적 할당
            res[i] = vector<int>(i + 1);
            // 양쪽 끝
            res[i][0] = 1;
            res[i][i] = 1;
            
            // 중앙
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
            
        }
        return res;
    }
};