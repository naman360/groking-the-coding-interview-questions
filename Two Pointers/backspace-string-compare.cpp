/**
 * Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.

Example 1:

Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
*/
#include <bits/stdc++.h>
using namespace std;

bool backspacecompare(string s1, string s2)
{
    int f = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == '#')
        {
            if (f > 0)
                f--;
        }
        else
        {
            s1[f++] = s1[i];
        }
    }
    int p = 0;
    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] == '#')
        {
            if (p > 0)
                p--;
        }
        else
        {
            s2[p++] = s2[i];
        }
    }
    if (f != p)
        return false;

    for (int i = 0; i < f; i++)
    {
        if (s1[i] != s2[i])
            return false;
    }

    return true;
}

int main()
{

    string s1 = "xywrrmp", s2 = "xywrrmp";
    cout << backspacecompare(s1, s2);
    return 0;
}