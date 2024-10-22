class Solution {
public:
    bool isValid(string s) {
        // 순서 있음. <시작, 끝> 쌍 존재.
        // 함수 호출과 유사함 => stack
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;

        stack<char> stack;        
        stack.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            switch (s[i]) {
                // open bracket
                case '(' :
                case '{' :
                case '[' : {
                    stack.push(s[i]);
                    break;
                }
                // closed bracket
                case ')': {
                    if (stack.empty() || stack.top() != '(') return false;
                    stack.pop();
                    break;
                }
                case '}': {
                    if (stack.empty() || stack.top() != '{') return false;
                    stack.pop();
                    break;
                }
                case ']': {
                    if (stack.empty() || stack.top() != '[') return false;
                    stack.pop();
                    break;
                }
            }
        }
        if (stack.empty()) return true;
        return false;
    }
};