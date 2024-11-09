class Solution {
public:
    // 4 방향 (시계 방향)
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };

    void fill (vector<vector<int>>& image, int y, int x, int src_color, int color) {
        // 이미 탐색한 곳은 다시 탐색x => 이 문제는 이미 탐색한 곳의 color가 변경되기 때문에 해당 정보를 그대로 플래그로 사용할 수 있다.
        // (sr, sc)의 원래 색과 같은 color인 경우만 색 변경
        int m = image.size();
        int n = image[0].size();

        for (int i = 0; i < 4; ++i) {
            int y_ = y + dy[i];
            int x_ = x + dx[i];
            // 해당 좌표의 조건 확인 (배열 범위 내인지, src_color와 일치하는지)
            if (y_ >= 0 && y_ < m && x_ >= 0 && x_ < n && image[y_][x_] == src_color) {
                image[y_][x_] = color;
                fill(image, y_, x_, src_color, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Perform the same process for each pixel -> 같은 동작을 반복한다면 재귀나 while 루프
        int src_color = image[sr][sc];
        if (src_color == color) return image;

        image[sr][sc] = color;
        fill(image, sr, sc, src_color, color);
        
        return image;
    }
};