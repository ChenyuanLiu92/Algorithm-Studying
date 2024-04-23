#include <vector>
#include <iostream>
class Sort
{
    public :
    void bubbleSort(std::vector<int> & nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j + 1 < nums.size(); j++)
            {
                if (nums[j] > nums[j+1])
                {
                    // swap
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                }
            }
        }
    }

    void selectedSort(std::vector<int> & nums)
    {
        for (int i = 0; i<nums.size(); i++)
        {
            int min = nums[i];
            int min_idx = i;
            for (int j = i +1 ;j<nums.size(); j++)
            {
                if (nums[j] < min)
                {
                    min = nums[j];
                    min_idx = j;
                }
            }
            int tmp = nums[i];
            nums[i] = min;
            nums[min_idx] = tmp;
        }
    }
};

int main()
{
    using namespace std;
    std::vector<int> nums;
    for (int i = 0; i<5;i++)
        nums.push_back(5-i);
    Sort s;
    s.selectedSort(nums);
    for (int i  = 0; i<nums.size(); i++)
        cout<<nums[i]<<"  ";

    return 0;
}