class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        long long rem = 0, sum = 0, num = x;
        while (num != 0)
        {
            rem = num % 10;
            sum = sum * 10 + rem;
            num /= 10;
        }
        return sum == x;
    }
};