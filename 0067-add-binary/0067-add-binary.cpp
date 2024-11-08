class Solution {
public:
    string addBinary(string a, string b) {
        // 1. cs - length가 너무 길고 a, b 길이도 서로 달라서 컴퓨터 구조에서 사용하는 효율적인 byte 연산 덧셈 알고리즘 같은건 쓸 수 없을것 같음 (그런게 있는지...?!)
        //  => 이거 divide and conquer 방식으로 bit 연산 가능한 길이로 쪼개서 더하는 방법은 없나?
        // 2. 수학적으로 2진수 덧셈은 least significant number부터 차례로 더한다. 덧셈에서 올림 계산은 일반 덧셈과 똑같은 알고리즘을 사용하기 때문에 a, b 자릿수를 맞춘 후 빈 자리를 0으로 채우면 하나의 while문으로 끝까지 계산할 수 있다.
        int res_size = 0;
        if (a.size() > b.size()) {
            res_size = a.size();
            // 앞에 0 채우기 - https://stackoverflow.com/questions/6143824/add-leading-zeroes-to-string-without-sprintf
            b = string(res_size - b.size(), '0') + b;
        } else {
            res_size = b.size();
            a = string(res_size - a.size(), '0') + a;
        }
        // 결과 저장할 string
        string res(res_size, '0');
        
        int i = res_size - 1;
        int round_up = 0; // 올림
        while (i >= 0) {
            // 경우의 수(2*2*2 = 8)를 줄이기 위해 숫자 연산으로 변경 (딱히 성능 때문은 아니고 내가 코드 짜기 귀찮고 헷갈려서)
            int a_ = a[i] - '0';
            int b_ = b[i] - '0';
            int tmp = a_ + b_ + round_up;
            switch (tmp) {
                case 0: {
                    res[i] = '0';
                    round_up = 0;
                    break;
                }
                case 1: {
                    res[i] = '1';
                    round_up = 0;
                    break;
                }
                case 2: {
                    res[i] = '0';
                    round_up = 1;
                    break;
                }
                case 3: {
                    res[i] = '1';
                    round_up = 1;
                    break;
                }
            }
            i--;
        }
        
        if (round_up == 1) res = '1' + res;
        return res;
    }
};