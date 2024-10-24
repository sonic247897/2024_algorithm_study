class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // - 정렬은 아닌듯. original의 순서가 필요하다.
        // - 보조 배열 추가? 글쎄..
        // - 역순행은? => 이미 살펴본 정보값(오른쪽에서 최대값)을 저장하면서 전진할 수 있음.
        int max = -1;
        for (int i = arr.size() - 1; i >= 0; --i) {
            int tmp = arr[i];
            arr[i] = max;
            if (tmp > max) max = tmp;
        }
        
        return arr;
    }
};