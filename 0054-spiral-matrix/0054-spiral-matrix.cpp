class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {        
        // 이것도 수학적으로 접근해야 할듯
        // (0, 0)부터 시작.
        // '기준'을 한 가지로 잡아야 순회가 쉽다. => 한 번 직선순회 할 때 끝까지 하지 않고 마지막에서 -1 번째까지만 순회한다는 기준을 세운다. 그러면 다음 직선순회와 겹치지 않는다.
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n);
        // 1st. (0, 0)부터 시작
        // 왼쪽으로 n-1 순회
        // 아래로 m-1 순회
        // 오른쪽으로 n-1 순회
        // 위로 m-1 순회
        // 2nd. 안쪽 사각형 진입 - (1, 1)부터 시작. m, n은 2씩 감소함
        // 움직일 수 없을때까지 반복.. => m 혹은 n이 1이 되는 경우가 마지막 순회임
        int y = 0;
        int x = 0;
        int res_idx = 0;
        int count = 0;
        while (m > 1 && n > 1) {
            count = 0;
            while (count++ < n-1) {
                res[res_idx++] = matrix[y][x];
                x++;
            }
            count = 0;
            while (count++ < m-1) {
                res[res_idx++] = matrix[y][x];
                y++;
            }
            count = 0;
            while (count++ < n-1) {
                res[res_idx++] = matrix[y][x]; // x는 n-1부터 시작
                x--;
            }
            count = 0;
            while (count++ < m-1) {
                res[res_idx++] = matrix[y][x]; // y는 m-1부터 시작
                y--;
            }
            // (y, x)는 시작점으로 돌아옴
            // 안쪽 사각형 진입
            y++;
            x++;
            m -= 2;
            n -= 2;
        }
    
        // 마지막 일자형 사각형 처리
        if (m == 1 && n == 1) {
            res[res_idx++] = matrix[y][x];
            return res;
        }
        
        if (m == 1) {
            for (int i = 0; i < n ; ++i) {
                res[res_idx++] = matrix[y][x + i];
            }
        }
        if (n == 1) {
            for (int i = 0; i < m ; ++i) {
                res[res_idx++] = matrix[y + i][x];
            }
        }
        return res;
    }
};