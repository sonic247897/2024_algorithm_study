class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 1. CS - 오름차순 정렬된 정수 배열. 이미 정렬되어 있다면 '이진 탐색'을 할 수 있다.
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            mid = (left + right) / 2;
        }
        return -1;
    }
};