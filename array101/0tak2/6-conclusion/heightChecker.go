package main

import "sort"

// Height Checker
// https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3228/
//
// 0ms, 4MB
func heightChecker(heights []int) int {
	sorted := make([]int, len(heights))
	copy(sorted, heights)
	sort.Ints(sorted)

	count := 0
	for i, height := range heights {
		if height != sorted[i] {
			count++
		}
	}

	return count
}
