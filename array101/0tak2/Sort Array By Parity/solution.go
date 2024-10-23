package main

// 0ms, 6.3MB
// 왼쪽 포인터는 짝수를, 오른쪽 포인터를 홀수를 찾고 swap
// 문제 조건에 순서 상관 없다고 했음
func sortArrayByParity(nums []int) []int {
	p1 := 0
	p2 := len(nums) - 1

	for p1 < p2 {
		if nums[p1]%2 == 0 {
			p1++
			continue
		}

		if nums[p2]%2 != 0 {
			p2--
			continue
		}

		tmp := nums[p1]
		nums[p1] = nums[p2]
		nums[p2] = tmp
	}

	return nums
}
