class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // 1. 수학 - 배열의 원소값을 십진수 0~9로 제한. => 이 조건을 쓸 수 있을것 같지가 않음(혹시 모르지만?) 
        // 2. CS 
        //   - 배열 길이 10^4는 너무 크다. 배열이 메모리 연속적이더라도 이 범위를 한 번에 처리할 수 있는 연산은 없을듯.
        //   - 단순히 shifting을 해버리면 O(N^2) 시간복잡도가 되어버림. 차라리 공간 복잡도를 늘려서 해결할 수는 없나?
        //     => 정렬 알고리즘처럼 배열 문제는 '보조 배열 추가' 방법으로 해결되는 문제가 상당함.
        vector<int> target_arr(arr.size());
        
        int idx = 0;
        int target_idx = 0;
        while (target_idx < arr.size()) {
            if (arr[idx] == 0) {
                // @ 주의 - 여기 범위 체크 안 해서 heap buffer overflow 에러 발생함
                target_arr[target_idx++] = 0;
                if (target_idx >= arr.size()) break;
                target_arr[target_idx++] = 0;
                idx++;
            } else {
                target_arr[target_idx++] = arr[idx++];
            }
        }
        
        // 보조 배열의 값을 다시 원래 배열에 복사
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = target_arr[i];
        }
    }
};