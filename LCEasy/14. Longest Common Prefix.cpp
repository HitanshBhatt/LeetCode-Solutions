class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
            strs is a vector of strings. Therefore, s[i] should return a string
        */
        if (strs.empty()) return "";

        string prefix = strs[0]; //first string is the prefix

        //compare first string with every string in the strs vector
        for (int i = 0; i < strs.size(); ++i){
            //reduce prefix length until it matches the beginning of strs[i]
            while(strs[i].find(prefix) != 0){   //while the prefix is not found
                prefix = prefix.substr(0, prefix.length() - 1); //reduces size of prefix to curr length - 1 and compare again

                //return empty string if no common prefix found
                if (prefix.empty()){
                    return "";
                }
            }
        }

        return prefix;
    }
};
