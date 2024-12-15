class Solution {
public: 
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        // find the strict mountain array
        // 1. 수학 - 원소값은 음수가 아닌 수.
        // 2. CS - 특정 값을 찾으려는 것이 아니라 (정렬되지 않은)전체 원소에 대한 추세를 알아보려고 하는 문제. linear search가 필요할듯.
        
        // 각 지점에 대해서 국소적으로 만족해야 하는 조건들이 있다. => 두 지점임. two pointer
        /* 양 쪽에서부터 산을 타고 올라오는 두 사람 */
        // 필수 조건 - 한 발짝씩은 나아가야 함
        int size = arr.size();
        if (arr[0] >= arr[1] || arr[size - 2] <= arr[size - 1]) return false;
        
        int left = 1;
        int right = size - 2;
        while (arr[left] < arr[left + 1]) left++;
        while (arr[right] < arr[right - 1]) right--;
        
        // 중앙에서 마주친다면 strict mountain
        if (right == left) return true;
        return false;
    }
};