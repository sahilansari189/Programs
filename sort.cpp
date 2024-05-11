#include <iostream>

int search(int* nums, int numsize, int target) {
    int left = 0;
    int right = numsize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    int pivot = left;
    left = 0;
    right = numsize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int real_mid = (mid + pivot) % numsize;

        if (nums[real_mid] == target) {
            return real_mid;
        } else if (nums[real_mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int nums[] = {4,5,6,7,0,1,2};
    int target = 0;
    int numsize = sizeof(nums) / sizeof(nums[0]);

    int result = search(nums, numsize, target);
    std::cout << "Index of target: " << result << std::endl;

    return 0;
}
