package main

/**
	Merge Sorted Array
	https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/
	// 0ms, 4.2MB
	// 투 포인터를 이용해 큰 수끼리 단순 비교하면서 넣어주면 된다
	// i는 이미 -1인데, j가 0 이상인 반례가 있어 처리 방법을 고민했음
*/
func merge(nums1 []int, m int, nums2 []int, n int) {
	i := m - 1
	j := n - 1
	cursor := m + n - 1 // len(nums1)

	for i >= 0 && j >= 0 {
		if nums1[i] > nums2[j] {
			nums1[cursor] = nums1[i]
			i--
		} else {
			nums1[cursor] = nums2[j]
			j--
		}

		cursor--
	}

	// nums2에 있는 값이 남아있으면 nums1로 복사
	// example> [0], 0, [1], 1
	for j >= 0 {
		nums1[cursor] = nums2[j]
		j--
		cursor--
	}
}
