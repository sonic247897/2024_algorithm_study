// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 내부에서 isBadVersion 최소한으로 호출해서 처음으로 true를 리턴하는 version을 찾아야 함.
        // 1. cs - (false, true)로 변하는 지점을 찾아야 한다. 이진 탐색을 하되 인접한 지점에 API 2번씩(m-1, m) 날려보도록 설계하면 어떨까?
        //  => edge case) 1부터 bad version, 마지막이 bad version
        //  => isBadVersion 호출을 최소화 해야하므로 캐시하자 (n 제한이 2^31 - 1 이라서 메모리 터질거 같은데? => Memory Limit Exceeded 발생)
        // vector<short> cache(n + 1, -1); // [1, n]; -1: 캐시x, 0: false, 1: true

        unsigned int low = 1;
        unsigned int high = n;
        while (low <= high) {
            unsigned int middle = (low + high) / 2; // @ 주의! signed integer overflow
            // bool isBad = cache[middle] == -1 ? isBadVersion(middle) : cache[middle];
            bool isBad = isBadVersion(middle);
            if (isBad) {
                if (middle == 1) return 1; // 1부터 bad version
                if (!isBadVersion(middle - 1)) return middle;  // (false, true)
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }

        // should not reach here
        return -1;
    }
};