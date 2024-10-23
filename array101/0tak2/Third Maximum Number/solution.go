package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(thirdMax([]int{1, 2, -2 ^ 31}))
}

// 0ms, 4.7MB
// solution은 아주 화려하네...
// 시간복잡도 -> 3N -> O(N)이기는 함
func thirdMax(nums []int) int {
	first := nums[0]
	for _, num := range nums {
		if num > first {
			first = num
		}
	}
	fmt.Println(first)

	second := math.MinInt64
	secondFound := false
	for _, num := range nums {
		if num < first && num > second {
			second = num
			secondFound = true
		}
	}
	fmt.Println(second, secondFound)
	if !secondFound {
		return first
	}

	third := math.MinInt64
	thirdFound := false
	for _, num := range nums {
		if num < second && num > third {
			third = num
			thirdFound = true
		}
	}
	fmt.Println(third, thirdFound)
	if !thirdFound {
		return first
	}

	return third
}
