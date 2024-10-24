package main

import "container/list"

/**
0ms, 4.57MB

스택 사용

s를 순회하면서,
여는 기호면 스택에 넣고, 닫는 기호는 스택 peek 했을 때 짝이 맞는 여는 기호가 있다면 pop
*/

var st *list.List

func handleChar(s rune) bool {
	if s == '(' || s == '[' || s == '{' {
		st.PushBack(s)
		return true
	}

	lastEl := st.Back()
	if lastEl == nil {
		return false
	}
	lastChar := lastEl.Value.(rune)

	if s == ')' && lastChar == '(' {
		st.Remove(lastEl)
		return true
	}

	if s == ']' && lastChar == '[' {
		st.Remove(lastEl)
		return true
	}

	if s == '}' && lastChar == '{' {
		st.Remove(lastEl)
		return true
	}

	return false
}

func isValid(s string) bool {
	if len(s) < 2 {
		return false
	}

	st = list.New()

	for _, c := range s {
		if !handleChar(c) {
			return false
		}
	}

	if st.Len() > 0 {
		return false
	}

	return true
}

func main() {
	result1 := isValid("([])") // true
	println(result1)

	result2 := isValid("()[]{}") // true
	println(result2)
}
