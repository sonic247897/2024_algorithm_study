class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 1. 수학 - 배열의 순서 지켜야 함. 원본 배열에 수학적 패턴은 존재하지 않기 때문에 원소들을 실제로 이동시키지 않고 결과를 만들 수 있는 함수는 없음.
        //  => 그나마 이동 횟수를 줄이려면 원본 배열 형태로 원복되는 연산 횟수만큼 생략하는 방법이 있음.
        // 2. CS - 하지만 배열에는 index가 존재하기 때문에 index를 계산하는 함수를 만들면 될듯.
        int size = nums.size();
        int move = k % size;
        vector<int> res(size);
        /* 투 포인터 */
        for (int i = 0; i < size; ++i) {
            res[(i + move) % size] = nums[i];
        }
        // 복사
        for (int i = 0; i < size; ++i) {
            nums[i] = res[i];
        }
    
        // O(1)로 풀려면 overwrite가 가능해야 한다.
        // => 삭제되어도 상관 없는 원소가 아니라면, 반복문 1회 시행할 때 tmp 변수에 잠시 저장하는 방법 등으로 안전하게 해당 원소를 저장할 수 있어야 함
        // overwrite 되는 원소의 위치: j = (i + move) % size
        // 해당 원소가 이동해야 할 위치: (j + move) % size = ([(i + move) % size] + move ) % size
        //  = (i + 2*move) % size
        // -> i와 j 사이에는 별 연관이 없기 때문에 tmp 변수에 계속 저장하는 방식으로 풀기 어렵다.
        // 근데 Hint #4 보면 cyclic-dependencies가 존재하는거 같기도..
    }
};