class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // 수학적 접근이 필요해보임
        // 무조건 (0, 0)부터 시작
        // 대각선에 위치한 원소들의 공통점은 (y, x) 좌표에서 y + x 값이 동일하다는 것. 이 상태에서 y의 값이 1씩 증가하거나 1씩 감소하는 형태로 진행된다.
        int m = mat.size();
        int n = mat[0].size();
        // overwrite 못 함
        vector<int> res(m * n);
        int res_idx = 0;        
        for (int i = 0; i <= m-1 + n-1; ++i) { // y + x 의 최대값 = m-1 + n-1
            // i = 0순회 - y 감소하는 방향(올라감), 1순회 - y 증가하는 방향(내려감), 2순회 - y 감소, 3순회 - y 증가, ....
            // -> 2번 시행하면 원 패턴으로 돌아오므로 %2 연산 결과로 분기문을 만들 수 있다.
            if (i % 2 == 0) { // 올라감
                int y = i < m ? i: m - 1;
                int x = i - y;
                while (y >= 0 && x < n) {
                    res[res_idx++] = mat[y][x];
                    y--; x++;
                }
            } else { // 내려감
                int x = i < n ? i : n - 1;
                int y = i - x;
                while (y < m && x >=0) {
                    res[res_idx++] = mat[y][x];
                    y++; x--;
                }
            }  
        }
        return res;
    }
};