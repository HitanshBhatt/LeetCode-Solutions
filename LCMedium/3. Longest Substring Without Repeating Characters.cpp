class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            Two pointers (left and right) and hash map to track the last seen index of each character
        */
        unordered_map<char, int> charMap; //hash map to store last seen index of each character
        int maxLength = 0;  //max length of substring
        int left = 0;   //left pointer

        for (int right = 0; right < s.length(); ++right){
            char currentChar = s[right];

            //if current char is already in the hashmap, move left pointer
            if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= left){
                left = charMap[currentChar] + 1;    //move left pointer to right of repeated character
            }

            charMap[currentChar] = right; //update last seen index of currentChar
            //right - left + 1 to calculate window size
            maxLength = max(maxLength, right - left + 1); //calculate max length
        }

        return maxLength;
    }
};
