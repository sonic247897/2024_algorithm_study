package main

import "fmt"

func main() {
	arr := []int{1, 1, 2}
	fmt.Println(removeDuplicates(arr))
	fmt.Println(arr)
}

// 0ms, 6MB
// 정답 찾아봄
func removeDuplicates(nums []int) int {
	p1 := 0
	for p2 := 0; p2 < len(nums); p2++ {
		if nums[p1] != nums[p2] {
			p1++
			nums[p1] = nums[p2]
		}
	}

	return p1 + 1
}

/*
	   1  1  2  2  3
	   p1
	   p2

	   --

	   1  1  2  2  3
	   p1
	      p2

	   --

	   1  1  2  2  3
	   p1
	         p2

	   1  2  2  2  3
	      p1
	         p2

       --

       1  2  2  2  3
       	  p1
	            p2

       --

       1  2  2  2  3
       	  p1
	               p2

       --

       1  2  3  2  3
             p1
	               p2
*/
