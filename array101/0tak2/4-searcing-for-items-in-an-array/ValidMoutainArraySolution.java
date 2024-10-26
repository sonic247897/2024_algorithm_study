/**
 * Valid Mountain Array
 * https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/
 * 
 * 3ms, 45MB
 * 
 * 선형탐색. 더 좋은 방법 검토
 */
class ValidMoutainArraySolution {
    public boolean validMountainArray(int[] arr) {
        // 증가 -> 증가 -> ... -> 감소 -> 감소 -> ...만 가능
        
        int prev = -1; // init
        State prevState = State.NOT_SET;
        boolean switched = false;
        
        if (arr.length <= 1) {
            return false;
        }
        
        for (int num : arr) {
            if (prev == -1) {
                prev = num;
                continue;
            }
            
            if (num > prev && (prevState == State.INCREASE || prevState == State.NOT_SET)) {
                // 증가
                if (prevState == State.NOT_SET) prevState = State.INCREASE;
                prev = num;
                continue;
            }
            
            if (num < prev && prevState == State.DECREASE) {
                // 감소
                prev = num;
                continue;
            }
            
            if (num < prev && prevState == State.INCREASE && !switched) {
                // 증가 -> 감소
                switched = true;
                prev = num;
                prevState = State.DECREASE;
                continue;
            }
            
            return false;
        }
        
        if (!switched) {
            return false;
        }
        return true;
    }
    
    public enum State {
        INCREASE, DECREASE, NOT_SET;
    }
}
