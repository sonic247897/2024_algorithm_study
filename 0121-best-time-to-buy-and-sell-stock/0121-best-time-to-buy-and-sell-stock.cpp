class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 정렬이나 탐색이 아님. 순서가 유지되어야 함.
        // min, max가 필요함.
        // 현재 가리키는 원소가 min이라고 가정하고, 오른쪽에 있는 max와의 차이를 계산한다.
        // O(N)으로 풀려면 왼쪽부터 역순회하면서 max를 저장하고, 앞으로 마주치는 원소와 뺄셈하여 profit을 구한다.
        int max_profit = 0;
        int max = prices[prices.size()-1];
        for (int i = prices.size()-2; i >= 0; --i) {
            if (prices[i] > max) {
                max = prices[i];
            } else {
                int profit = max - prices[i];
                if (profit > max_profit) max_profit = profit;
            }
        }
        return max_profit;
    }
};