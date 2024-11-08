class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // trial#1. 통과는 하지만 하위권. O(NlogN)
        // 1. 수학 - pair가 되면 하나의 수는 반드시 버려진다. sum을 최대로 만들기 위해서는 큰 수를 최대한 살려야 한다.
        //  => 바로 인접한 수끼리 pair를 맺는것이 유리함. 어차피 작은 패를 골라야 하는데 더 큰 패를 붙여서 버릴 필요가 없기 때문.
        // 2. CS - 정렬은 O(NlogN)이 걸린다. O(N) 시간 복잡도로 maximized sum을 찾을수 있는가?
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i+=2) {
            sum += nums[i];
        }
        return sum;
    }
};