package main

import "sort"

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
