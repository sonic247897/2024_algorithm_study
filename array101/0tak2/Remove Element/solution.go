package main

// 0ms, 3.9MB
func removeElement(nums []int, val int) int {
	length := len(nums)
	p1 := 0
	p2 := len(nums) - 1

	for p1 < len(nums) && p2 >= 0 && p1 <= p2 {
		if nums[p1] != val {
			p1++
			continue
		}

		if nums[p2] == val {
			p2--
			length-- // p2가 감소하면 길이도 감소해야한다
			continue
		}

		tmp := nums[p1]
		nums[p1] = nums[p2]
		nums[p2] = tmp
		length--
		p1++
		p2--
	}

	return length
}

// 0ms, 4.2MB
// 이게맞나? 싶은 복잡한 풀이
func removeElement_alter(nums []int, val int) int {
	length := len(nums)
	p := len(nums) - 1 // val이 아닌 원소를 가리키는 포인터

	for i := 0; i < len(nums); i++ {
		for p >= 0 {
			if nums[p] != val { // val이 아닌 원소를 찾아놓는다
				break
			}

			p--
		}

		if i > p { // p가 i보다 작아지면 멈춘다
			break
		}

		if nums[i] == val { // val을 찾으면 p가 가리키는 원소와 바꾼다
			tmp := nums[i]
			nums[i] = nums[p]
			nums[p] = tmp
			p--
			length-- // 길이 1감소
		}
	}

	for i := length - 1; i >= 0; i-- { // [3, 2, 2, 3], val=3과 같은 경우, 위에서 [2, 2, 3, 3], length = 3이 된다.
		if nums[i] == val { // 마지막 원소부터 val이 있는지 확인하고 length를 보정한다.
			length--
		}
	}

	return length
}

// range문 활용
func removeElement_sample(nums []int, val int) int {
	var i int = 0
	for _, v := range nums {
		if v != val {
			nums[i] = v
			i++
		}
	}
	return i

}
