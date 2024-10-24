class Solution {    
    public void insertEl(int[] arr, int value, int index) {
        for (int i = arr.length - 2; i >= index; i--) {
            arr[i + 1] = arr[i];
        }    
        arr[index] = value;
    }
    
    public void duplicateZeros(int[] arr) {
        int cursor = 0;
        while (cursor < arr.length) {
            if (arr[cursor] == 0) {
                insertEl(arr, 0, cursor);
                cursor++;
            }
            cursor++;
        }
    }
}
// 14 ms, 43.5 MB
