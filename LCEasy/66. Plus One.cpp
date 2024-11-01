class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // Just add one and return
                return digits;
            }
            digits[i] = 0; // Set current digit to 0 and carry over
        }
        
        // If we are here, it means we have a carry that needs to be added
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};
