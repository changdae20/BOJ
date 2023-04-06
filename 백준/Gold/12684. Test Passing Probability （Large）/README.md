# [Gold III] Test Passing Probability (Large) - 12684 

[문제 링크](https://www.acmicpc.net/problem/12684) 

### 성능 요약

메모리: 2948 KB, 시간: 1292 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘

### 문제 설명

<p>Dave is taking a multiple choice test on the Internet. Dave possibly gets many opportunities to submit his answers to the test, but he passes only if he gets all the questions correct. He must answer every question on the test to make a submission. The only information he receives after he submits is whether he has passed.</p>

<p>For each question, he estimates the probability that each of 4 responses is correct, independent of his responses to other questions. Given a fixed number of submissions he can make, Dave wants to choose his responses so that he maximizes the probability of passing the test.</p>

<p>What is the probability that Dave will pass the test if he chooses his responses optimally?</p>

### 입력 

 <p>The first line of input gives the number of cases, <strong>C</strong>. <strong>C</strong> test cases follow.</p>

<p>Each test case starts with a line containing <strong>M</strong> and <strong>Q</strong>. Dave is allowed to make <strong>M</strong>submissions to solve the test. There are <strong>Q</strong> questions on the test. <strong>Q</strong> lines follow, each containing 4 probabilities of correctness. There will be at most 6 digits after the decimal point. The probabilities for each line are non-negative and sum to 1.</p>

<p>Limits</p>

<ul>
	<li>1 ≤ <strong>C</strong> ≤ 100 </li>
	<li>1 ≤ <strong>Q</strong> ≤ 30 </li>
	<li>1 ≤ <strong>M</strong> ≤ 10000 </li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #<strong>X</strong>: <strong>Y</strong>" where <strong>X</strong> is the number of the test case (starting from 1), and <strong>Y</strong> is the probability of success. <br>
Answers with a relative or absolute error of at most 10<sup>−6</sup> will be considered correct.</p>

