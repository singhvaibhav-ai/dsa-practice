#include <bits/stdc++.h>
using namespace std;

// Reverse a String
// brute force approach
// TC = O(n)
// SC = O(n)
void reverseString(string &str)
{
    int n = str.length();
    string dupStr = str;
    for (int i = 0; i < n; i++)
    {
        str[i] = dupStr[n - i - 1];
    }
}

// Optimal approach
// TC = O(n)
// SC = O(1)
void reverseStringOptimal(string &str)
{
    int left = 0, right = str.size() - 1;
    while (left < right)
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

// Palindrome Check
// TC = O(n)
// SC = O(1)
bool isPalindrome(string &str)
{
    int left = 0, right = str.size() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// Largest odd number in a string
// TC = O(n)
// SC = O(1)
string largestOddNumber(string &s)
{
    int j = -1, n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 1)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return "";
    int i = 0;
    while (i <= j)
    {
        if (s[i] != '0')
            break;
        i++;
    }
    return s.substr(i, j - i + 1);
}

// Longest common prefix
// TC = O(maxlength of string * n * log n) + O(maxlength of string)
// where n is the number of strings
// SC = O(Maxlength of string)
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
    {
        return "";
    }
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    string ans = "";
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
            break;
        ans += first[i];
    }
    return ans;
}

// Isomorphic String
// TC = O(n)
// SC = O(2*256)
bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int s_map[256] = {0}, t_map[256] = {0};
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s_map[s[i]] != 0 || t_map[t[i]] != 0)
        {
            if (s_map[s[i]] != t[i] + 1 || t_map[t[i]] != s[i] + 1)
                return false;
        }
        s_map[s[i]] = t[i] + 1;
        t_map[t[i]] = s[i] + 1;
    }
    return true;
}

// Rotate String
// Brute Force Approach
// TC = O(n^2)
// SC = O(n)
bool rotateString(string &s, string &goal)
{
    if (s.size() != goal.size())
        return false;
    int n = s.size();
    string left = "";
    for (int i = 0; i < n; i++)
    {
        string right = s.substr(i);
        if (right + left == goal)
            return true;
        left += s[i];
    }
    return false;
}

// Optimal Approach
// TC = O(n) + O(2n) = O(n)
// SC = O(n)
// Explanation: Concatenate the string with itself and check if the goal is a substring of this new string.
bool rotateString(string &s, string &goal)
{
    if (s.size() != goal.size())
        return false;
    string temp = s + s;
    return temp.find(goal) != string::npos; // Rabin-Karp algorithm is used internally by std::string::find
}

// Valid Anagram
// Sorting Approach (Brute Force)
// TC = O(n log n)
// SC = O(n)
bool anagramStrings1(string &s, string &t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// Hashing Approach (Optimal)
// TC = O(n)
// SC = O(1)
bool anagramStrings2(string &s, string &t)
{
    if (s.size() != t.size())
        return false;
    int hash_s[26] = {0}, hash_t[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash_s[s[i] - 'a']++;
        hash_t[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash_s[i] != hash_t[i])
            return false;
    }
    return true;
}

// Sort Characters by Frequency
bool comparator(pair<int, char> &a, pair<int, char> &b)
{
    if (a.first < b.first)
        return false;
    if (a.first > b.first)
        return true;
    return a.second < b.second;
}
vector<char> sortByFrequency(string &s)
{
    pair<int, char> freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = {0, 'a' + i};
    }
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a'].first++;
    }
    sort(freq, freq + 26, comparator);
    vector<char> ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i].first == 0)
            break;
        ans.push_back(freq[i].second);
    }
    return ans;
}
int main()
{
    return 0;
}