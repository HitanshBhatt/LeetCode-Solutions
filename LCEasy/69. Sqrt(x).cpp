class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; // Base case for 0 and 1
        return binarySearch(0, x, x); // Start searching between 0 and x
    }
    
    int binarySearch(int low, int high, int x) {
        if (low > high) {
            return high; // Return the largest integer whose square is ≤ x
        }
        
        int mid = low + (high - low) / 2; // Avoid overflow
        // Check if mid is the square root
        if (mid == x / mid) {
            return mid; // Exact square root found
        } else if (mid < x / mid) {
            return binarySearch(mid + 1, high, x); // Move to the right half
        } else {
            return binarySearch(low, mid - 1, x); // Move to the left half
        }
    }
};
