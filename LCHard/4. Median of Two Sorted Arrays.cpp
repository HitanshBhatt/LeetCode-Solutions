class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }
        
        int n = nums1.size();
        int m = nums2.size();
        int low = 0, high = n;

        while (low <= high) {
            int partition1 = (low + high) / 2; // Partition index for nums1
            int partition2 = (n + m + 1) / 2 - partition1; // Partition index for nums2

            // If partition is at the ends, use -infinity and +infinity
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == n) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == m) ? INT_MAX : nums2[partition2];

            // Check if we have found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // We have partitioned the array correctly
                if ((n + m) % 2 == 0) {
                    // Even case
                    return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
                } else {
                    // Odd case
                    return std::max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Move towards the left side in nums1
                high = partition1 - 1;
            } else {
                // Move towards the right side in nums1
                low = partition1 + 1;
            }
        }
        
        throw std::invalid_argument("Input arrays are not sorted");
    }
};
