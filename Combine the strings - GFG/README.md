# Combine the strings
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>s </strong>containing <strong>n </strong>strings, find the length of the string obtained by combining the strings. Two strings can be only combined if the last character of the first string and the first character of the second string are the same.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 3
s[] = {"RBR", "BBR", "RRR"}
<strong>Output: </strong>9
<strong>Explanation: </strong>Combined string can 
&nbsp;            be: BRR + RBR + RRR</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 2
s[] = {"RRR", "BBB"}
<strong>Output: </strong>0
<strong>Explanation: </strong>Since combining condition
&nbsp;            isn't fulfilled answer is 0.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Your task is to complete the function&nbsp;<strong>combine()&nbsp;</strong>which takes 2 arguments(integer n and array of n strings) and returns the maximum length of combined strings possible. If no 2 strings can be combined return 0.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(n).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2&lt;=n&lt;=1000<br>
1&lt;=|s<sub>i</sub>|&lt;=1000, where 0&lt;=i&lt;n<br>
s will only contain {R,B}</span></p>
</div>