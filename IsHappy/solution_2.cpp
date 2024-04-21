class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        do
        {
            int sum = getDigitSum(n);
            if (sum == 1)
                return true;

            std::unordered_set<int>::iterator it = set.find(sum);
            if (it == set.end())
            {
                set.insert(sum);
                n = sum;
            }
            else
            {
                if (sum == 1)
                    return true;

                else
                    return false;
            }
        }
        while (1);
        return false;
    }

    int getDigitSum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
};