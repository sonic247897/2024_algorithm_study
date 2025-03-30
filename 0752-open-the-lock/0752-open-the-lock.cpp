#include <string>

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 1. 수학 - 모든 경우의 수 10^4 => 완전탐색 가능(최소를 구해야 하므로 중복해서 탐색할 필요x)
        // 2. cs - deadends와 target에 대한 규칙이 없기 때문에 완전 탐색이 필요하며, 1번에 1 slot씩만 이동할 수 있으므로 사실상 4차원 미로임. (hint에서는 10^4 노드를 가진 그래프라고 함)
        /* 'map'과 'set'은 이진 트리를 사용해서 탐색하기 때문에 visited 플래그로 사용할 경우 중복 체크에 O(logN) 시간이 걸릴 수 있다. 
          반면에 'unordered_map'과 'unordered_set'은 hash table을 사용해서 O(1)이 걸린다.  
        */
        
        if (target == "0000") return 0;
        // 맨 처음에 deadends를 전부 visited로 설정하면 순회에서 제외됨
        unordered_set<string> visited;
        for (const std::string& deadend : deadends) {
            visited.insert(deadend);
        }
        if (visited.find("0000") != visited.end()) return -1;
        
        // Node 식별자 - string 그대로 사용
        queue<string> q;        
        q.push("0000");
        visited.insert("0000");
        int step = 1;
        
        // 각 digit마다 -1, +1 slot을 이동할 수 있고, 4개 digit이므로 2*4 = 8개 노드를 큐에 넣어주면서 진행 (wrap around를 주의!)
        while (!q.empty()) {                
            int size = q.size();
            while (size-- > 0) {
                string cur = q.front();
                q.pop();
                // ascii 이용하면 편할듯
                for (int i = 0; i < 4; ++i) {              
                    // -1 slot
                    string next(cur);
                    char cur_digit = cur[i] == '0' ? '9' : cur[i] - 1;
                    next.at(i) = cur_digit;
                    if (next == target) return step;
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }

                    // +1 slot
                    string next_(cur);
                    cur_digit = cur[i] == '9' ? '0' : cur[i] + 1;
                    next_.at(i) = cur_digit;
                    if (next_ == target) return step;
                    if (visited.find(next_) == visited.end()) {
                        q.push(next_);
                        visited.insert(next_);
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};