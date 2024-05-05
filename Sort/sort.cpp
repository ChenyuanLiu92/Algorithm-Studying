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

    void insertSort(std::vector<int> & nums)
    {
        for (int i = 1 ; i<nums.size(); i++)
        {
            int now = nums[i];
            int j;
            for (j = i-1; j>=0;j--)
            {
                if (nums[j]>now)
                    nums[j+1] = nums[j];
                else
                {
                    nums[j+1] = now;
                    break;
                }
            }
            nums[j+1] = now;
        }
    }

    void shellSort(std::vector<int> & nums)
    {
        int gap = nums.size()/2;
        while (gap > 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i+gap; j<nums.size(); j+=gap)
                {
                    // 插入排序
                    int k;
                    int now = nums[j];
                    for ( k = j-gap; k>=0; k -= gap)
                    {
                        if (nums[k]>now)
                        {
                            nums[k+gap] = nums[k];
                        }
                        else
                        {
                            nums[k+gap] = now;
                            break;
                        }
                    }
                    nums[k + gap] = now;
                }
            }
            gap /= 2;
        }
    }

    void quickSort(int low, int high, std::vector<int> & nums)
    {
        if (low < high)
        {
        int pivot = partition(low, high, nums);
        quickSort(low, pivot-1, nums);
        quickSort(pivot+1, high, nums);
        }
    }
    int partition(int low, int high, std::vector<int> & nums)
    {
        int pivot = nums[high];
        while (low <= high)
        {
            if (nums[low] > nums[high])
            {
                std::swap(nums[low], swab(high));
                high--;
                continue;
            }

            if (nums[])

        }
        return low - 1;
    }
};

int main()
{
    using namespace std;
    std::vector<int> nums;
    for (int i = 0; i<5;i++)
        nums.push_back(i);
    Sort s;
    s.quickSort(0, 4 ,nums);
    for (int i  = 0; i<nums.size(); i++)
        cout<<nums[i]<<"  ";

    return 0;
}