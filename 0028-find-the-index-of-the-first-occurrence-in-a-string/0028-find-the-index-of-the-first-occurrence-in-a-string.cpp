class Solution {
public:
    int strStr(string haystack, string needle) {
        // Ex2) haystack = "leetcode", needle = "leeto" 처럼 window 실패하면, 실패한 지점을 다음 window의 시작점으로 지정할 수 있는가? 반례가 있는지?
        // => "mississippi", "issip" 같은 경우가 있어서 그냥 linear search 해야할듯
        for (int i = 0; i < haystack.size(); ++i) {
            for (int j = 0; j < needle.size() && i+j < haystack.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
                
                if (j == needle.size() - 1) return i;
            }
        }
        
        return -1;

        // 잡설
        /* 문자열이 숫자 배열과 달리 더 까다로운 점은 뭘까?
         => 수학 패턴은 오름차/내림차순 등 패턴이 단순한 문제가 주류라서 정렬 등에 의해 쉽게 패턴이 파악된다면, 
            문자열은 알파벳 소문자 26종류를 조합해서 의미를 만들기 때문에 패턴이 너무 다양함.
            26이라는 숫자를 이용해서 수학적으로 단순화 할 수는 없을까?
        */
    }
};