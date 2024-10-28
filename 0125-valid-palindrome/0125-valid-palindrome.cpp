class Solution {
public:
    // 0 리턴: Alphanumeric 아님
    // 1 리턴: Alphanumeric 대문자
    // 2 리턴: Alphanumeric 소문자, 숫자
    int isValid(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return 2;
        }
        if (c >= 'A' && c <= 'Z') {
            return 1;
        }
        return 0;
    }

    bool isPalindrome(string s) {
        // 투 포인터 - Alphanumeric character끼리만 비교. 두 포인터가 중앙에서 만나면 종료.
        // 'A', 'a', '0'
        if (s.size() == 1) return true; // @ 코너 케이스

        int left_idx = 0;
        int right_idx = s.size() - 1;
        int ascii_diff = 'a' - 'A'; // 양수

        while (left_idx < right_idx) { // 홀수 길이 문자열에서 가운데는 검사할 필요x
            // 1) 배열 index 범위 체크를 안 해줘서 다음 케이스에서 에러 발생 - ".," => left_idx < right_idx 조건 추가
            while (left_idx < right_idx && isValid(s[left_idx]) == 0) {
                left_idx++;
            }
            while (left_idx < right_idx && isValid(s[right_idx]) == 0) {
                right_idx--;
            }
            // 2) "0P"는 false인데 true로 체크 => |s[left_idx] - s[right_idx]| == |ascii_diff| 인 경우는 대문자-소문자 관계도 있지만, 숫자-영문자 관계도 존재할 수 있음! 따라서 대문자/소문자/숫자 구별을 완전히 해줘야 함.
            if (isValid(s[left_idx]) == 1) s[left_idx] += ascii_diff;
            if (isValid(s[right_idx]) == 1) s[right_idx] += ascii_diff;
            if (s[left_idx] == s[right_idx]) {
                left_idx++;
                right_idx--;
            } else {
                return false;
            }
        }
        return true;
    }
};