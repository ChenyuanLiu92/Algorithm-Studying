class Solution {
public:
    bool isHappy(int n) {

    int fast = n;
    int slow = n;
    do
    {
        slow = getSquareSum(slow);
        fast = getSquareSum(fast);
        fast = getSquareSum(fast);
    }
    while (fast != slow);

    return slow == 1;
    }

    int getSquareSum(int n)
    {
        int sum = 0;
        while (n>0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
};