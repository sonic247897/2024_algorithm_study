class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 1. 수학 - 필요한 원소 값을 재귀로 채우면 된다. (top -> bottom)
        // 2. CS - 하지만 재귀 풀이는 중복 계산이 포함된다. 따라서 이미 계산한 결과를 캐시할 수 있을것 같음. => 기존 2차원 배열을 사용한 풀이는 공간복잡도가 O(rowIndex)보다 크다. 공간 복잡도를 줄이면서 캐시를 하기 위해서는 tmp 변수가 필요하다.
        //  -> 가운데 있는 원소는 두 번씩 사용됨에 주의해야함. 따라서 해당 원소들을 tmp로 저장해서 사용한다.
        if (rowIndex == 0) return { 1 };
        
        int size = rowIndex + 1;
        vector<int> res(size);
        res[0] = 1;
        res[1] = 1;
        
        for (int i = 2; i < size; ++i) {
            int prev = res[0]; // 1
            for (int j = 1; j <= i; ++j) {
                int tmp = res[j]; // 두 번씩 사용되기 때문에 다음 반복문으로 넘겨야 함 (res[j]가 overwrite 되기 전에 저장)
                res[j] = prev + res[j];
                prev = tmp;
            }
        }
        res[size - 1] = 1;
        
        return res;
    }
};