/**
  Squares of a Sorted Array
  https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3240/
  1ms, 47.3MB
*/
class SquaresOfASortedArraySolution {
    public int[] sortedSquares(int[] nums) {
        // === 스트림으로 비벼보기 ===
        // 제곱한 뒤 정렬하므로 적어도 O(n * log n)
        // return Arrays.stream(nums).map(i -> i * i).sorted().toArray(); // 12ms, 46.1MB
        
        // === 투포인터 ===
        // nums의 중간 어느 지점에서 음수 -> 양수가 전환될 때를 기준점으로,
        // 양쪽 끝에서 안으로 들어가면서 제곱수의 값이 감소한다.
        // 양쪽 끝의 인덱스를 각각 포인터로 잡고 안쪽으로 옮기면서 진행한다.
        // O(n)
        int[] result = new int[nums.length];
        int leftIndex = 0;
        int rightIndex = nums.length - 1;
        
        for (int i = nums.length - 1; i >= 0; i--) { // 큰 값부터 작은 값으로 진행하므로 결과 배열의 마지막 인덱스에서 시작
            if (Math.abs(nums[leftIndex]) > Math.abs(nums[rightIndex])) {
                result[i] = nums[leftIndex] * nums[leftIndex];
                leftIndex++;
            } else {
                result[i] = nums[rightIndex] * nums[rightIndex];
                rightIndex--;
            }
        }

        return result; // 1ms, 47.3MB
    }
}
