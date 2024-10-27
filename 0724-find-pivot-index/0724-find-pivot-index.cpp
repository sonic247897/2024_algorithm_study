class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 수학적으로 total sum = left sum + pivot element + right sum
        //  => 그렇다면 누적 합을 저장하는 배열을 만드는건 어떨까? 누적합은 left sum이고, right sum은 total sum - pivot - left sum 으로 쉽게 구할수 있다.
        // int 배열로 하면 overflow 발생할 가능성은? => 10^3 * 10^4 = 10^7 으로 int 범위 내임
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            // overwrite 해도 괜찮음
            nums[i] += nums[i-1];
        }
        
        int total_sum = nums[size - 1];
        // 코너 케이스 확인: if (i == 0)
        if (total_sum - nums[0] == 0) return 0;
        for(int i = 1; i < size ; ++i) {
            int left_sum = nums[i-1];
            int right_sum = total_sum - nums[i];
            if (left_sum == right_sum) return i;
        }
        return -1;
    }
};