class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // 1. 수학 - 2배수를 찾으려면 각각을 분자, 분모로 한 번씩 계산해서 a*2 == b 혹은 b*2 == a 인지 확인해야 함
        // 2. CS - 탐색 문제이므로 '선 정렬, 후 탐색'을 시도. 이진 탐색을 생각해보면 '가운데 값*2' 결과가 현재 원소값보다 큰지, 작은지에 따라 탐색 범위를 절반씩 좁혀나간다.
        //      => 찾으려는 값도 배열의 원소중 하나이므로 모든 원소값에 대해서 이진 탐색을 한번씩 시행해야 한다. 따라서 O(N * logN) 탐색시간이 걸림.
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            // binary search - find the double of num
            // @ int low = i + 1; // num의 double을 찾을 것이기 때문에 num보다 작은 범위는 탐색할 필요x
            // @ 음수를 생각하지 못 했음. 다음 예제에서 실패함; [-10,12,-20,-8,15]
            int low = 0;
            int high = arr.size()-1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                // @ i != j 를 고려했어야 함. 다음 예제에서 실패함; [-2,0,10,-19,4,6,-8]
                if (num*2 == arr[mid] && i != mid) return true;
                if (arr[mid] < num*2) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }            
        }
        
        return false;
    }
};