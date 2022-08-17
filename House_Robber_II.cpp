//Leetcode_Question

class Solution {
public:
    int max_sum(vector<int>& ans)
    {
        int n = ans.size();
        int prev = ans[0];
        int prev2 = 0;
        for(int i=1; i<n; i++)
        {
            int take = ans[i];
            if(i > 1)
            {
                take += prev2;
            }
            int not_take = prev;
            int cur_i = max(take, not_take);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        for(int i=0; i<n; i++)
        {
            if(i != 0)
            {
                temp1.push_back(nums[i]);
            }
            if(i != n-1)
            {
                temp2.push_back(nums[i]);
            }
        }
        return max(max_sum(temp1), max_sum(temp2));
    }
};
