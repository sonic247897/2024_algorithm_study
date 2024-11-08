class Solution {
public:
    bool isAnagram(string s, string t) {
        // 5 * 10^4 길이 문자열이기 때문에 int형 배열로 '문자-발생 빈도'로 기록해도 overflow 발생하지 않음.
        // 알파벳 소문자 26자에 대한 발생 빈도가 일치하는지만 확인하면 된다.
        if (s.size() != t.size()) return false;

        vector<int> alpha_count(26, 0);
        
        for (int i = 0; i < s.size(); ++i) {
            alpha_count[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            alpha_count[t[i] - 'a']--;
            // s 문자열에 없는 문자를 사용하거나, 한 문자를 너무 많이 사용하면 false
            if (alpha_count[t[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};