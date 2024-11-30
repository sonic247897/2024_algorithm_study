/**
 * Merge Sorted Array
 * https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/
 * 
 * FAILED
 * 
 * 반례
 * Input:
 *   [4,5,6,0,0,0]
 *   3
 *   [1,2,3]
 *   3
 * Output:
 *   [1,4,2,5,3,6]
 * Expected:
 *   [1,2,3,4,5,6]
 */
class MergeSortedArraySolution {
    public void insertEl(int[] arr, int value, int index) {
        for (int i = arr.length - 2; i >= index; i--) {
            arr[i + 1] = arr[i];
        }    
        arr[index] = value;
    }
    
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int cursor1 = 0;
        int cursor2 = 0;
        
        while (cursor1 < nums1.length && cursor2 < nums2.length) {
            int num1 = nums1[cursor1];
            int num2 = nums2[cursor2];
            
            System.out.println("c1=" + cursor1 + " c2=" + cursor2);
            
            if(cursor1 >= m) {
                System.out.println("c " + num1 + " " + num2);
                insertEl(nums1, num2, cursor1);
                cursor1++;
                cursor2++;
                continue;
            }
            
            if(num1 <= num2) {
                System.out.println("a " + num1 + " " + num2);
                cursor1++;
                
                System.out.println("[SKIP]");
            } else {
                System.out.println("b " + num1 + " " + num2);
                // num1의 왼쪽에 num2를 인서트
                insertEl(nums1, num2, cursor1);
                
                cursor1 += 2; // 인서트한 num2의 다음 원소
                cursor2++;
                
                System.out.println(Arrays.toString(nums1));
            }
        }
    }
}
