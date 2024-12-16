class Solution {
public:
    int climbStairs(int n) {
        // 1. 수학 문제 - 한 번에 1 or 2 스텝만 가능하며, 순서가 중요하고 n을 초과하면 안 된다.
        //  방법
        //    1) (1 + 1 + ... + 1) = n 을 만족하는 경우의 수 1
        //    2) 위 다항식에 2 하나 끼워 넣기; 만족하는 경우의 수 `항의개수C1 - 항의 개수는 이전 시도보다 1개 감소
        //    3) 다항식에 2 하나 더 끼워 넣기; 만족하는 경우의 수 `항의개수C2 - 항의 개수는 이전 시도보다 1개 감소
        //    ... 이하 반복
        //    m) (2 + 2 + ... + 2) = n 을 만족하는 경우의 수 `항의개수C항의개수(= 1) - n이 짝수인 경우에만 성립
        //  => 컴비네이션 공식을 구현해야 한다.
        // 2. cs - 컴비네이션 공식을 최적화하는 알고리즘이 존재하는가? 
        //      - 그것보다도 팩토리얼(!) 계산이 포함되기 때문에 overflow를 조심해야 한다. 혹시 모르니 double 변수로 계산하자..
        int res = 1; // 방법 1)
        
        int two_steps = 1;
        // 2 step 개수가 늘어나서 n을 초과할 때까지 반복
        while (n - 2*two_steps >= 0) {
            // 컴비네이션 계산
            int term = n - two_steps; // 다항식 항의 개수
            double comb = 1;
            int small_quot = term < two_steps ? term : two_steps;
            for (int i = small_quot; i > 0; i--) {
                comb *= term;
                term--;
            }
            for (int i = 1; i <= small_quot; ++i) {
                comb /= i;
            }

            res += comb;
            two_steps++;
        }

        return res;
    }
};