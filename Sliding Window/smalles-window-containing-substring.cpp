/**
 * Smallest Window containing Substring (hard) #
Given a string and a pattern, find the smallest substring in the given string which has all the characters of the given pattern.

Example 1:

Input: String="aabdec", Pattern="abc"
Output: "abdec"
Explanation: The smallest substring having all characters of the pattern is "abdec"
*/
#include <bits/stdc++.h>
using namespace std;

string smallestSubstring(string s, string p)
{
    unordered_map<char, int> mp;
    int j = 0;
    for (int i = 0; i < p.size(); i++)
    {
        mp[p[i]]++;
    }
    int matched = 0, start = 0, end = 0, mini = 1e9;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end()) // if found
        {
            // cout << s[i] << " ";
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                matched++;
        }

        while (matched == mp.size())
        {

            if (mini > i - j + 1)
            {
                mini = min(i - j + 1, mini);
                start = j,
                end = i;
            }

            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]++;
                if (mp[s[j]] == 1)
                    matched--;
            }
            j++;
        }
    }

    // cout << start << " " << end;
    string ans = "";
    if (start && end)
        for (int i = start; i <= end; i++)
        {
            ans += s[i];
        }
    return ans;
}
int main()
{
    string s = "adcad";
    string p = "abc";
    cout << smallestSubstring(s, p);
    return 0;
}