package main

import "fmt"

/**
		Replace Elements with Greatest Element on Right Side
		https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/
*/

func main() {
	fmt.Println(replaceElements([]int{17, 18, 5, 4, 6, 1}))
}

// 957ms, 9.2MB
func replaceElements_slow(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		if i+1 >= len(arr) {
			arr[i] = -1
			continue
		}

		max := arr[i+1]
		for j := i + 1; j < len(arr); j++ {
			if arr[j] > max {
				max = arr[j]
			}
		}
		arr[i] = max
	}

	return arr
}

// 0ms, 10.3MB
// Hint #1 Loop through the array starting from the end.
// 마지막 원소에서 첫번째 원소로 순회; 루프마다,
// 1. 그동안의 최댓값을 할당하고,
// 2. 새로운 원소와 최댓값을 비교해 최댓값 업데이트
func replaceElements(arr []int) []int {
	if len(arr) == 1 {
		return []int{-1}
	}

	max := -1
	for i := len(arr) - 1; i >= 0; i-- {
		tmp := arr[i]
		arr[i] = max

		if tmp > max {
			max = tmp
		}
	}

	return arr
}
