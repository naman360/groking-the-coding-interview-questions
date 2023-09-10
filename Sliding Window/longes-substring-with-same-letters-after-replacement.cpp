/**
 * Problem Statement #
Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter, find the length of the longest substring having the same letters after replacement.

Example 1:

Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
*/

#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k)
{
    int maxi = -1e9;
    int j = 0, maxOcc = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
        maxOcc = max(maxOcc, mp[s[i]]); // storing the maximum occurence number
        int windowSize = i - j + 1;
        if (windowSize - maxOcc > k) // window size - maximum occurence of an element if it is greater thank k we must shrink the window as we can only replace k characters but there are more than k distinct chars
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                mp.erase(s[j]);

            j++;
        }
        maxi = max(maxi, i - j + 1);
    }
    return maxi;
}
int main()
{
    string s = "abbcb";
    int k = 1;
    cout << longestSubstring(s, k);
    return 0;
}