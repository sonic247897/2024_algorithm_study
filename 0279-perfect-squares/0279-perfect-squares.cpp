class Solution {
public:
    int numSquares(int n) {
        // 1. 수학 - 가장 큰 제곱수부터 빼면 가장 작은 항의 개수가 나올 것 같지만, 제곱수만 더할 수 있다는 제약 때문에 오히려 n을 완성하지 못 할 수도 있다.(12 = 4+4+4)
        //  => 따라서 더이상 특별한 규칙을 발견할 수 없는 한 '완전 탐색'을 시도해야 한다.
        // 2. cs - 완전 탐색 및 최단 루트는 BFS.
        // 1) 트리 or 그래프로 추상화하기
        //  => 단순 경우의 수를 나타내는 트리 구조(수형도)로 추상화? X. 이 문제에서는 (1, 1, 4) 혹은 (1, 4, 1)을 똑같은 경우의 수로 생각해야 탐색의 수를 줄일 수 있기 때문.
        //  => 양방향 그래프도 같은 이유로 탈락.
        // 2) node 및 visited 정의
        //  => node를 누적합으로 정의. 먼저 방문한 누적합이 최소 항으로 구성되어 있기 때문에 Set으로 visited 플래그를 나타낼 수 있음.
        if (n == 1) return 1;
        queue<int> q;
        unordered_set<int> visited;
        
        // 초기화 - start node는 1 ~ (n 이하의 가장 큰 제곱수)
        int i = 1;
        int node = 1;
        while (node <= n) {
            if (node == n) return 1;
            q.push(node);
            visited.insert(node);
            
            i++; node = i*i;
        }

        int step = 1;
        while (!q.empty()) {
            // step 별로 처리
            step++;
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();
                // 1, 4, 9, ... n 보다 작은 제곱수까지 누적합 구하기
                int num = 1;
                while (num*num <= n - cur) {
                    int next = cur + num*num;
                    if (next == n) return step;
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                    num++;
                }
            }   
        }
        
        return step;  
    }
};