/**
 * Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.

Example 1:

Input: [1, 0, 2, 1, 0]
Output: [0 0 1 1 2]
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> sort012(vector<int> v)
{
    int low = 0, mid = 0, high = v.size() - 1;
    while (mid <= high)
    {
        if (v[mid] == 0)
        {
            swap(v[low], v[mid]);
            low++, mid++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(v[mid], v[high]);
            high--;
        }
    }
    return v;
}

int main()
{

    vector<int> v{2, 2, 0, 1, 2, 0};

    vector<int> ans = sort012(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}