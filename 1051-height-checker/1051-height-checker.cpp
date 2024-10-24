class Solution {
public:
    int heightChecker(vector<int>& heights) {
        /* 1. 오름차순 정렬 - O(NlogN)
        // 정렬된 배열이 무조건 필요할 것 같은데..? 그럼 시간 복잡도 O(NlogN) 인가?
        int size = heights.size();
        vector<int> expected(size); 
        for (int i = 0; i < size; ++i) {
            expected[i] = heights[i];
        }
        std::sort(expected.begin(), expected.end());
        
        int count_diff = 0;
        for(int i = 0; i < size; ++i) {
            if (heights[i] != expected[i]) count_diff++;
        }
        
        return count_diff;
        */
        // https://stackoverflow.com/questions/3578083/what-is-the-best-way-to-use-a-hashmap-in-c
        // 2. heights 범위가 작음을 이용. 해시맵 사용(key - heights, value - heights의 빈도) - O(N)
        //  => ordered_map 쓰면 heights 값을 오름차순으로 차례대로 순회하면서(N) 탐색하기 때문에(logN) O(NlogN)이 됨.
        //  => 반면에 배열은 오름차순으로 순회하면서(N) 탐색하기 때문에(1) 최종적으로 O(N)이 됨 - index가 오름차순이라는 성질 때문에.
        // 1) 오름차순 배열 만들기
        vector<int> count_heights(101); // heights: 1 ~ 100
        int size = heights.size();
        for(int i = 0; i < size; ++i) {
            count_heights[heights[i]]++;
        }
        
        vector<int> expected(size);
        int expected_idx = 0;
        for(int i = 1; i < 101; ++i) { // heights: 1 ~ 100
            while (count_heights[i] > 0) {
                expected[expected_idx++] = i;
                count_heights[i]--;
            }
        }

        // 2) 원본과 비교
        int count_diff = 0;
        for (int i = 0; i < size; ++i) {
            if (heights[i] != expected[i]) count_diff++;
        }
        
        return count_diff;
    }
};