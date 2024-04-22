class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};

        int counter = nums[0];
        int pre = 0;
        vector<string> res;
        for (int i = 1; i <nums.size(); i++)
        {
            if (nums[i]==counter+1)
            {
                counter = nums[i];
            }
            else
            {
                res.push_back(buildString(pre, i-1, nums));
                pre = i;
                counter = nums[i];
            }
        }

        res.push_back(buildString(pre, nums.size()-1, nums));

        return res;
    }

    string buildString(int start, int end, vector<int> & nums)
    {
        string res;
        if(end == start)
            res += to_string(nums[start]);
        else
        {
            res += to_string(nums[start]);
            res += "->";
            res += to_string(nums[end]);
        }
        return res;
    }
};