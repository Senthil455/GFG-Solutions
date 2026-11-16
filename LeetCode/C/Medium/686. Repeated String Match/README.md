# 📝 686. Repeated String Match (LeetCode)

🔗 [Problem Link](https://leetcode.com/problems/repeated-string-match/)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange) ![Language](https://img.shields.io/badge/Language-C-blue)

### 💡 Tags
String, String Matching, Z Algorithm, Knuth–Morris–Pratt Algorithm, Boyer–Moore String-Search Algorithm

### 🚀 Performance
- **Runtime:** 36 ms
- **Memory:** 8.7 MB

---

### 📜 Problem Description

You are given two strings  `a`  and  `b` ​​​​​​​ consisting of lowercase English letters​​​​​​​.

Return the  **minimum**  number of times you should repeat string  `a`  so that string  `b`  is a  **substring**  of it. If it is  **impossible**  for  `b` ​​​​​​ to be a substring of  `a`  after repeating it, return -1.

**Note:**  string  `"abc"`  repeated 0 times is  `""` , repeated 1 time is  `"abc"`  and repeated 2 times is  `"abcabc"` .

A  **subarray**  is a contiguous sequence of elements within an array.

**Example 1:**

```
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

```

**Example 2:**

```
Input: a = "a", b = "aa"
Output: 2

```

**Constraints:**

	
- `1 <= a.length, b.length <= 104`
	
- `a`  and  `b`  consist of lowercase English letters.