class Solution {
public:
    string reverseWords(string s) {
        // 1. word 순서대로 저장
        vector<string> words;
        int i = 0;
        while (i < s.size()) {
            // 앞 공백 제거
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            if (i >= s.size()) break; // 맨 끝 공백
            string tmp = "";
            while (i < s.size() && s[i] != ' ') {
                tmp += s[i++];
            }
            words.emplace_back(tmp);
        }
        
        // 2. 뒤에서부터 차례로 word를 뽑아와서 문장 만들기
        string res = "";
        for (auto it = words.rbegin(); it != words.rend(); ++it) {
            res += *it;
            res += " ";
        }
        res.pop_back();
        
        return res;
    }
};