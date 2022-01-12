#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int idxOne = m - 1;
        int idxTwo = n - 1;
        int idx = m + n - 1;

        while (idxOne >= 0 && idxTwo >= 0)
        {
            if (nums1[idxOne] >= nums2[idxTwo])
            {
                nums1[idx] = nums1[idxOne];
                idxOne--;
            }
            else
            {
                nums1[idx] = nums2[idxTwo];
                idxTwo--;
            }

            idx--;
        }

        while (idxTwo >= 0)
        {
                nums1[idx] = nums2[idxTwo];
                idxTwo--;
                idx--;
        }
    }
};
