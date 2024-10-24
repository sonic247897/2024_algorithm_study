// 0 ms, 42.2 MB
// 투 포인터 사용 -> 힌트 보고 풀었음
class Solution {
    public int removeElement(int[] nums, int val) {
        int p1 = 0;
        int p2 = nums.length - 1;
        int length = nums.length;
        
        while(p1 < nums.length && p2 >= 0 && p1 <= p2) {
            int num1 = nums[p1];
            int num2 = nums[p2];
            
            if (num1 != val) {
                p1++;
                continue;
            }
            
            if (num2 == val) {
                p2--;
                length--;
                continue;
            }
            
            // System.out.println("swap p1=" + p1 + " p2=" + p2);
            nums[p1] = num2;
            nums[p2] = num1;
            p1++;
            p2--;
            length--;
        }
        
        return length;
    }
}
