#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int minSubArrayLen(int target, const std::vector<int>& nums) {
    int left = 0;
    int current_sum = 0;
    int min_length = INT_MAX; // Use INT_MAX to easily track the minimum

    for (int right = 0; right < nums.size(); ++right) {
        // 1. Expand the window by including the element at 'right'
        current_sum += nums[right];

        // 2. Contract the window while the condition is met (sum >= target)
        while (current_sum >= target) {
            // Update the optimal result (window length is right - left + 1)
            min_length = std::min(min_length, right - left + 1);

            // Shrink the window from the left
            current_sum -= nums[left];
            left++;
        }
    }

    // If min_length was never updated, no valid subarray exists
    return (min_length == INT_MAX) ? 0 : min_length;
}

int main() {
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    
    int result = minSubArrayLen(target, nums);
    std::cout << "Minimum window length: " << result << std::endl; // Output: 2 ([4, 3])
    
    return 0;
}
