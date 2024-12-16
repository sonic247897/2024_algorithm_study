class Solution {
public:
    int longestPalindrome(string s) {
        // 1. 수학 - palindrome 문자열은 가운데를 기준으로 문자가 양쪽에 같은 빈도로 발생해야 하므로 짝수개 존재하는 문자를 포함할 수 있다. palindrome의 가운데 문자는 반복되지 않아도 되므로 발생빈도수가 홀수인 문자가 존재한다면 전체 길이가 +1 된다.
        //  => 따라서 알파벳의 개수가 중요하다. 대/소문자 발생빈도를 저장하는 배열을 정의해서 풀어보자.
        if (s.size() == 1) return 1;

        // @ 코드가 기억나지 않을 때는 printf로 범위 찍어보기!
        // printf("A: %d\n", 'A'); // 65
        // printf("a: %d\n", 'a'); // 97
        // printf("z: %d\n", 'z'); // 122
        vector<int> alpha(58);
        for (int i = 0; i < s.size(); ++i) {
            alpha[s[i] - 'A']++;
        }
        
        int res = 0;
        bool has_odd = false;
        for (int i = 0; i < alpha.size(); ++i) {
            if (alpha[i] % 2 == 0) {
                res += alpha[i];
            } else {
                res = res + alpha[i] - 1;
                has_odd = true;
            }
        }
        if (has_odd) res += 1;

        return res;
    }
};