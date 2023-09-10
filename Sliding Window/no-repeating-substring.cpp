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
    // iterate and when encountered a repeating character shrink the window until there is no repeating char
    // for (int i = 0; i < s.size(); i++)
    // {
    //     mp[s[i]]++;

    //     while (mp[s[i]] > 1)
    //     {
    //         mp[s[j]]--;
    //         if (mp[s[j]] == 0)
    //             mp.erase(s[j]);
    //         j++;
    //     }
    //     maxi = max(i - j + 1, maxi);
    // }
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            j = max(j, mp[s[i]] + 1); // shrink window till the next element of last occurence of repeating char (or the next repeating character)
        }
        mp[s[i]] = i; // store the last index at which the character has beenencountered
        maxi = max(i - j + 1, maxi);
    }
    return maxi;
}
int main()
{
    string s = "abccde";
    cout << noRepeatingSubstring(s);
    return 0;
}