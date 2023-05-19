class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
  int maxLength = 0;
  int start = 0;
  int end = 0;
  set<char> seen;

  while (end < n) {
    if (seen.find(s[end]) == seen.end()) {
      seen.insert(s[end]);
      end++;
      maxLength = max(maxLength, end - start);
    } else {
      seen.erase(s[start]);
      start++;
    }
  }

  return maxLength;
    }
};