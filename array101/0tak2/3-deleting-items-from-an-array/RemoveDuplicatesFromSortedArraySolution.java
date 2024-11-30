/**
 * Remove Duplicates from Sorted Array
 * https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3248/
 * 6 ms, 45MB
 * 아주 느림
 */
class Solution {
    public int removeDuplicates(int[] nums) {
        int p1 = 1;
        int p2 = 2;
        int prevVal = nums[0];
        
        while (p1 < nums.length && p2 < nums.length && p1 < p2) {
            // System.out.println("loop start p1=" + p1 + " p2=" + p2 + " prevVal=" + prevVal);
            
            int leftVal = nums[p1];
            if (leftVal > prevVal) { // 왼쪽 포인터가 가리키는 수가 중복 아님
                p1++;
                p2++;
                prevVal = leftVal;
                // System.out.println("loop end (1) p1=" + p1 + " p2=" + p2 + " prevVal=" + prevVal + "\n");
                continue;
            }
            
            // 왼쪽 포인터가 가리키는 수가 중복임
            int rightVal = nums[p2];
            if (rightVal > prevVal) {
                // System.out.println("swap");
                // System.out.println("Prev: " + Arrays.toString(nums));
                nums[p1] = rightVal;
                nums[p2] = leftVal;
                
                // System.out.println("Modified: " + Arrays.toString(nums));
                
                // 포인터 재할당
                prevVal = nums[p1];
                p1++;
                p2 = p1 + 1;
            } else {
                p2++;
            }
            
            // System.out.println("loop end (2) p1=" + p1 + " p2=" + p2 + " prevVal=" + prevVal + "\n");
        }
        
        if (p2 == nums.length && p2 - 1 == p1 && nums[p2 - 1] > nums[p2 - 2]) {
            // for: [1, 2, 3]
            return p1 + 1;
        }
        
        if (nums.length == 2 && nums[0] >= nums[1]) {
            return nums.length - 1;
        } else if (nums.length <= 2) {
            return nums.length;
        }
        
        return p1;
    }
}
