package main

// Find All Numbers Disappeared in an Array
// https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3270/

// 맵 사용
// 23ms, 9.3MB
func findDisappearedNumbers_map(nums []int) []int {
	table := make(map[int]bool)
	result := make([]int, 0)

	for _, num := range nums {
		table[num] = true
	}

	for i := 1; i <= len(nums); i++ {
		_, exists := table[i]

		if !exists {
			result = append(result, i)
		}
	}

	return result
}

// 샘플 보고 다시 푼 것
// 어짜피 연속된 수이므로 맵을 쓰지 않고, 별도 배열에 존재 여부를 기록,
// 입력된 배열에 덮어쓰는 방식으로 작성
// 1ms, 10.3MB
func findDisappearedNumbers(nums []int) []int {
	table := make([]bool, len(nums))
	// example    nums := []int{1, 3, 1, 3}
	// 인덱스       0 1 2 3
	// 가리키는 수   1 2 3 4
	//             T F T F

	for i := 0; i < len(nums); i++ {
		table[nums[i]-1] = true
	}

	j := 0
	for idx, exists := range table {
		if !exists {
			nums[j] = idx + 1 // 인덱스에서 다시 가리키는 수로 변환
			j++
		}
	}

	return nums[:j] // 0..<j
}
