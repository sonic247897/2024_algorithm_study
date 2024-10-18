class Solution {
    public int findNumbers(int[] nums) {
        int evenCount = 0;
        
        for (int num : nums) {
            int digits = (int) Math.log10(num) + 1; // (1ms, 42.9MB)
            // int digits = String.valueOf(num).length(); // (2ms, 43.8MB)
            
            if (digits % 2 == 0) evenCount++;
        }
        
        return evenCount;
    }
}