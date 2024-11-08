class Solution {
public:
    void reverseString(vector<char>& s) {
        // two pointer 시나리오1 설명에 나온 swap 예제 그대로 작성하면 될듯
        /* 투 포인터 */
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};