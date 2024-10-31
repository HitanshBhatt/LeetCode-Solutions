class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            Approach:
                - Sort the array to find duplicates and use two pointer approach
                - Iterate using two pointers:  For each element, fix it as the first element of the triplet 
                    and use two pointers (left and right) to find pairs that sum to zero with the fixed element.\
                - After finding a valid triplet, skip duplicate values
        */

        vector<vector<int>> result;

        sort(nums.begin(), nums.end()); //sort the vector (array)

        for (int i = 0; i < nums.size(); ++i){
            //skip duplicates
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            //element nums[i] is one potential value
            int left = i + 1;   //left pointer
            int right = nums.size() - 1; //right pointer

            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0){
                    //result is a vetor of vector of ints; vector denoted by {}
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    //move pointers after adding a valid result
                    left++;
                    right--;
                }
                //for 2 cases below: array is sorted therefore left most value is lowest and right most value is highest
                else if(sum < 0){
                    left++; //increase sum by moving left pointer
                }
                else{
                    right--; //decrease sum by moving right pointer
                }
            }
        }

        return result;
    }
};
