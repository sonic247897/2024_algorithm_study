class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 알파벳 문제는 배열로 풀 수 있다.
        // 1) magazine 문자열에서 각 알파벳이 등장하는 빈도수를 배열에 저장
        vector<int> alpha_count(26);
        for (int i = 0; i < magazine.size(); ++i) {
            alpha_count[magazine[i] - 'a']++;
        }
        // 2) ransomNote 문자열에서 각 알파벳이 등장하는 빈도수를 체크. 배열 원소값이 음수가 되면 false
        for (int i = 0; i < ransomNote.size(); ++i) {
            if (--alpha_count[ransomNote[i] - 'a'] < 0) return false;
        }

        return true;
    }
};