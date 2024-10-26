/**
 * Check If N and Its Double Exist
 * https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/
 * 
 * 2 ms, 43.6
 * 
 * Map을 사용한 메모이제이션
 * Two Sum도 이렇게 가능할 듯?
 */
class CheckIfNAndItesDoubleExistSolution {
    public boolean checkIfExist(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            
            if (map.get(num * 2) != null) {
                return true;
            }
            
            if (num % 2 == 0 && map.get(num / 2) != null) {
                return true;
            }
            
            map.put(num, i);
        }
        
        return false;
    }
}
