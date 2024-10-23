package main

import "fmt"

func main() {
	arr := []int{1, 0, 1}
	moveZeroes(arr)
	fmt.Println(arr)
}

// 0ms, 10.2MB
// 포인터 1: 왼쪽부터 0을 찾는다
// 포인터 2: 왼쪽부터 0이 아닌 수를 찾는다
// 둘 다 찾으면 바꾼다
func moveZeroes(nums []int) {
	p1 := 0
	p2 := 0

	for p1 <= len(nums)-1 && p2 <= len(nums)-1 && p1 <= p2 {
		// fmt.Println("p1 =", p1, "nums[p1] =", nums[p1], "p2 =", p2, "nums[p2] =", nums[p2])

		if nums[p1] != 0 {
			p1++
			p2 = p1
			continue
		}

		if nums[p2] == 0 {
			p2++
			continue
		}

		tmp := nums[p1]
		nums[p1] = nums[p2]
		nums[p2] = tmp

		p1++
		p2++
	}
}

// 샘플 풀이
// range문을 이용해 순차적으로 0이 아닌 값을 앞부터 채우고, 그 수 만큼 0을 추가
// inplace op 취지와는 안맞는 듯...? 그냥 go가 빠른거 아닌가?
func moveZeroes_alter(nums []int) {
	j := 0
	for i, val := range nums {
		if nums[i] != 0 {
			nums[j] = val
			j++
		}
	}
	for i := j; i < len(nums); i++ {
		nums[i] = 0
	}
}
