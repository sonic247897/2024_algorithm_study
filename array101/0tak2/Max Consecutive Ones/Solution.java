class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int max = 0;
        
        for (int num : nums) {
            if (num == 0) {
                if (count > max) max = count;
                count = 0;
                continue;
            }
            
            // num == 1 // true
            count++;
        }
        
        if (count > max) max = count; // is there any way to remove repeating evaluation?
        return max;
    }
}
