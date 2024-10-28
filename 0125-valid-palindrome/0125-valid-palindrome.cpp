class Solution {
public:
    bool isValid(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        // 투 포인터 - Alphanumeric character끼리만 비교. 두 포인터가 중앙에서 만나면 종료.
        // 'A', 'a', '0'
        if (s.size() == 1) return true; // @ 코너 케이스

        int left_idx = 0;
        int right_idx = s.size() - 1;
        int ascii_diff = 'A' - 'a'; // 음수 또는 양수

        while (left_idx < right_idx) { // 홀수 길이 문자열에서 가운데는 검사할 필요x
            // 배열 index 범위 체크를 안 해줘서 다음 케이스에서 에러 발생 - ".,"
            while (left_idx < right_idx && !isValid(s[left_idx])) {
                left_idx++;
            }
            while (left_idx < right_idx && !isValid(s[right_idx])) {
                right_idx--;
            }
            int diff = s[left_idx] - s[right_idx];
            if (diff == 0 || diff == ascii_diff || diff == -ascii_diff) {
                left_idx++;
                right_idx--;
            } else {
                return false;
            }
        }
        return true;
    }
};