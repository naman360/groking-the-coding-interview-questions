
/**
 * Problem Statement #
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Example 1:

Input: String="aabbcc", K=1
Output: 2
Explanation: The longest substring with no more than '2' distinct characters is "araa".
*/
#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k)
{
    unordered_map<char, int> mp;
    int j = 0;
    int maxi = -1e9;
    int len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
        while (mp.size() > k)
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                mp.erase(s[j]);
            j++;
        }
        maxi = max(i - j + 1, maxi);
    }
    return maxi;
}
int main()
{
    string s = "araaci";
    int k = 2;
    cout << longestSubstring(s, k);
    return 0;
}