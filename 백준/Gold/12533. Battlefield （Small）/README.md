# [Gold V] Battlefield (Small) - 12533 

[문제 링크](https://www.acmicpc.net/problem/12533) 

### 성능 요약

메모리: 2172 KB, 시간: 0 ms

### 분류

그래프 이론, 그래프 탐색, 오일러 경로

### 문제 설명

<p>You are playing a game where the battlefield consists of <strong>N</strong> cities and <strong>R</strong> bidirectional roads. Your goal is to start at some city <strong>C</strong> of your choice and visit all <strong>R</strong> roads exactly once ending this trip at <strong>C</strong>. If this is not possible you must add the minimum number of additional roads to the initial set of roads to make this trip feasible. Please note that there might be more than one road connecting the same pair of cities and that you are allowed to add roads between any pair of cities regardless of whether they already had roads connecting them or not as shown in the sample input/output.</p>

### 입력 

 <p>The first line of input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow. For each test case there will be:</p>

<ul>
	<li>One line containing the value <strong>N</strong>, the number of cities.</li>
	<li>One line containing the value <strong>R</strong>, the number of roads.</li>
	<li><strong>R</strong> lines corresponding to the roads. Each contains 2 values <strong>A</strong> and <strong>B</strong> separated by one space. <strong>A</strong> and <strong>B</strong> are 2 distinct integers (0 ≤ <strong>A</strong>,<strong>B</strong> < <strong>N</strong>) indicating the end points of that road.</li>
</ul>

<h3>Limits</h3>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 30</li>
	<li>2 ≤ <strong>N</strong> ≤ 1000</li>
	<li>1 ≤ <strong>R</strong> ≤ 15</li>
</ul>

<p> </p>

### 출력 

 <p>For each test case, output one line containing "Case #<strong>x</strong>: ", where <strong>x</strong> is the number of the test case, followed by the minimum number of roads needed.</p>

