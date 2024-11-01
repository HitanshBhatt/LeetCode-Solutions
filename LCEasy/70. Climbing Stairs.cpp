class Solution {
public:
    int climbStairs(int n) {
        /*
            Solve using Fibonacci sequenece. # of ways to reach step n can be expressed as:
                ways(n) = ways(n-1) + ways(n-2) [single step from (n-1), or two steps from (n-2)]

                Base cases:
                    if n == 0: 1 way to stay at the ground (not climbing any stairs)
                    if n == 1: 1 way to climb to the first step (one single step)
        */

        if (n == 0 || n == 1){
            return 1;
        }

        int first = 1;
        int second = 1;
        int current;

        for (int i = 2; i <= n; ++i){
            current = first + second;   //calculate ways(i)
            first = second; //move forward in the sequence
            second = current;   //update second to the latest calculated value
        }

        return second;
    }
};
