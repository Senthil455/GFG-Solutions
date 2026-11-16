# 📝 812. Rotate String (LeetCode)

🔗 [Problem Link](https://leetcode.com/problems/rotate-string/)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen) ![Language](https://img.shields.io/badge/Language-C-blue)

### 💡 Tags
String, String Matching

### 🚀 Performance
- **Runtime:** N/A
- **Memory:** N/A

---

### 📜 Problem Description

Given two strings  `s`  and  `goal` , return  `true`   *if and only if*   `s`   *can become*   `goal`   *after some number of  **shifts**  on*   `s` .

A  **shift**  on  `s`  consists of moving the leftmost character of  `s`  to the rightmost position.

	
- For example, if  `s = "abcde"` , then it will be  `"bcdea"`  after one shift.

**Example 1:**

**Input:**  s = "abcde", goal = "cdeab"

**Output:**  true

**Explanation:**

Rotating  `s`  to the left by 2 positions moves  `"ab"`  to the end, resulting in  `"cdeab"` , which is equal to  `goal` .

**Example 2:**

**Input:**  s = "abcde", goal = "abced"

**Output:**  false

**Explanation:**

No sequence of rotations of  `s`  can produce  `"abced"` . The characters appear in a different relative order, so  `goal`  is not a rotation of  `s` .

**Constraints:**

	
- `1 <= s.length, goal.length <= 100`
	
- `s`  and  `goal`  consist of lowercase English letters.