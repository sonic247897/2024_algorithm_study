class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 1. m*n 배열을 순회하면서 출발점을 잡는다.
        // 2. 더 이상 '1'을 만날 수 없을 때까지 완전 탐색(BFS). cycle이 존재할 수 있는 양방향 그래프와 같기 때문에 visited 플래그를 설정해야 한다.
        // 3. 1번부터 재시작
        //  => 큐에 들어갈 Node를 어떻게 식별하는지가 중요함. 좌표 계산을 쉽게 하기 위해서는 그냥 (y,x)쌍을 저장하는게 좋을듯.
        //  => 단순하게 한 번 방문한 land('1')를 water('0')로 설정하면 visited 플래그가 필요없다.
        int dy[] = { -1, 0, 1, 0 };
        int dx[] = { 0, 1, 0, -1 };
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int count = 0;
        // 출발점 찾기
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (grid[y][x] == '1') {
                    q.push(make_pair(y, x));
                    grid[y][x] = '0';
                    
                    while (!q.empty()) {
                        pair<int,int> cur = q.front();
                        q.pop();
                        // index 범위 체크 주의!
                        for (int i = 0; i < 4; ++i) {
                            int ny = cur.first + dy[i];
                            int nx = cur.second + dx[i];
                            if (ny >= 0 && ny < m && nx >= 0 && nx < n && grid[ny][nx] == '1') {
                                q.push(make_pair(ny, nx));
                                grid[ny][nx] = '0';
                            }
                        }
                    }        
                    count++;
                }       
            }
        }

        return count;
    }
};