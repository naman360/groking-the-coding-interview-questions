/**
 * Problem Statement #
Given a string, find the length of the longest substring which has no repeating characters.

Example 1:

Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".
*/
#include <bits/stdc++.h>
using namespace std;

int noRepeatingSubstring(string s)
{
    int maxi = -1e9;
    int j = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) // abccde
    {
        mp[s[i]]++;

        while (mp[s[i]] > 1)
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
    string s = "aabccbb";
    cout << noRepeatingSubstring(s);
    return 0;
}