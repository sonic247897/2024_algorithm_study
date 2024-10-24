package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// 1ms, 4.50MB
// todo: resultList를 따로 만들 필요가 없다
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	resultList := &ListNode{}

	if list1 == nil && list2 == nil {
		return nil
	}

	if list1 != nil && list2 == nil {
		return list1
	}

	if list1 == nil && list2 != nil {
		return list2
	}

	resultEl := resultList
	for list1 != nil || list2 != nil {
		if list1 == nil {
			// fmt.Println("list1 nil")
			// fmt.Println("list2", list2.Val, list2.Next)

			resultEl.Val = list2.Val
			list2 = list2.Next

			if list2 != nil {
				resultEl.Next = &ListNode{}
				resultEl = resultEl.Next
			}

			// fmt.Println("if0-0", resultEl)
			continue
		}

		if list2 == nil {
			// fmt.Println("list1", list1.Val, list1.Next)
			// fmt.Println("list2 nil")

			resultEl.Val = list1.Val
			list1 = list1.Next

			if list1 != nil {
				resultEl.Next = &ListNode{}
				resultEl = resultEl.Next
			}

			// fmt.Println("if0-1", resultEl)
			continue
		}

		// fmt.Println("list1", list1.Val, list1.Next)
		// fmt.Println("list2", list2.Val, list2.Next)
		if list1.Val < list2.Val {
			resultEl.Val = list1.Val
			resultEl.Next = &ListNode{}

			// fmt.Println("if1", resultEl)

			list1 = list1.Next
			resultEl = resultEl.Next
		} else {
			resultEl.Val = list2.Val
			resultEl.Next = &ListNode{}

			// fmt.Println("if2", resultEl)

			list2 = list2.Next
			resultEl = resultEl.Next
		}
	}

	return resultList
}

func main() {
	list1 := &ListNode{-9, nil}
	list1.Next = &ListNode{3, nil}
	list2 := &ListNode{5, nil}
	list2.Next = &ListNode{7, nil}

	resultList := mergeTwoLists(list1, list2)
	for resultList != nil {
		// fmt.Println(resultList.Val)
		resultList = resultList.Next
	}
}
