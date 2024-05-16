class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 不可以用字符串的方式否则会越界
        bool up = false;
        int size = digits.size();
        digits[size-1] = digits[size-1] + 1;
        for (int i = 0; i < digits.size(); i++)
        {
            if (up)
            {
                digits[size-1-i] = digits[size-1-i] + 1;
            }
            if (digits[size-1-i]>9)
            {
                digits[size-1-i] = 0;
                up = true;
            }
            else
            {
                up = false;
            }
        }
        if (up)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};