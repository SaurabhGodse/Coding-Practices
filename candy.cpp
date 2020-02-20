// 135. Candy
// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Example 1:

// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:

// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two conditions.


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> asc(n, 1);
        vector<int> desc(n, 1);
        for(int i = 1; i < n; i++)
        {
            if(ratings[i - 1] < ratings[i])
            {
                asc[i] = asc[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                desc[i] = desc[i + 1] + 1;
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += max(asc[i], desc[i]);
        return sum;
            
    }
};