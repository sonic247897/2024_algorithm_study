class Solution {
public:
    string reverseWords(string s) {
        // s를 역순회하면 자동으로 reverse word를 읽을수 있다.
        vector<string> words;
        
        // 1. reverse word 읽기 - space를 발견하거나, 맨 앞 단어인 경우에 멈춤
        int i = s.size() - 1;
        while (i >= 0) {
            string tmp = "";
            while (i >= 0 && s[i] != ' ') {
                tmp += s[i--];
            }
            words.push_back(tmp);
            i--; // space
        }
        // 2. reverse word를 역순으로 나열해서 문자열 만들기
        string res = "";
        for (auto it = words.rbegin(); it != words.rend(); ++it) {
            res += *it;
            res += " ";
        }
        res.pop_back();
        
        return res;
    }
};