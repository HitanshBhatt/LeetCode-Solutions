class Solution {
public:
    bool isPalindrome(int x) {
        /*
            Two pointers upproach. Check if values of two pointers are equal until they meet.
            If they are, number is a palindrome
        */

        //negative #'s are not palindromes
        if (x < 0) return false;

        string num = to_string(x);

        bool is_same = false;

        int left = 0;
        int right = num.length() - 1;

        while (left < right){
            //not a palindrome is characters don't match
            if(num[left] != num[right]){
                return false;
            }

            left++;
            right--;
        }
        //if all characters matched, it is a palindrome
        return true;
    }
};
