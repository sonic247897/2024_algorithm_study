package main

/**
	Squares of a Sorted Array
	https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3240/
	1ms, 8.5MB
*/
func sortedSquares(nums []int) []int {
	p1 := 0
	p2 := len(nums) - 1
	cursor := p2
	result := make([]int, len(nums))

	for p1 <= p2 {
		if p1 == p2 { // when len(nums) is odd
			result[cursor] = nums[p1] * nums[p1]
			break
		}

		sq1 := nums[p1] * nums[p1]
		sq2 := nums[p2] * nums[p2]

		if sq1 > sq2 {
			result[cursor] = sq1
			cursor--
			p1++
		} else {
			result[cursor] = sq2
			cursor--
			p2--
		}
	}

	return result
}
