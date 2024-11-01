class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            Use Quick Sort to sort the array in-place. Time complexity is O(nlogn)
            and space complexity is nums.size() or O(n)
        */
        quickSort(nums, 0, nums.size() - 1);
    }
    
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            // Partitioning index
            int partitionIndex = partition(nums, left, right);
            // Recursively sort elements before and after partition
            quickSort(nums, left, partitionIndex - 1);
            quickSort(nums, partitionIndex + 1, right);
        }
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right]; // Choose the rightmost element as pivot
        int i = left - 1; // Pointer for the smaller element
        
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) { // If current element is smaller than pivot
                i++; // Increment the smaller element pointer
                swap(nums[i], nums[j]); // Swap
            }
        }
        // Place the pivot in its correct position
        swap(nums[i + 1], nums[right]);
        return i + 1; // Return the partitioning index
    }
};
