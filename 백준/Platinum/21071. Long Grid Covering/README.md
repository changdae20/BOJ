# [Platinum I] Long Grid Covering - 21071 

[문제 링크](https://www.acmicpc.net/problem/21071) 

### 성능 요약

메모리: 2028 KB, 시간: 40 ms

### 분류

수학, 다이나믹 프로그래밍, 분할 정복을 이용한 거듭제곱

### 문제 설명

<p>We have a grid of height $3$ and width $n$, as well as pieces that occupy $3$ adjacent cells. Given $n$, determine the number of ways to fill the grid so that each cell is covered by exactly one piece and no piece sticks out of the grid. Here there is an example of a way to fill a grid of width $4$:</p>

<p style="text-align: center;"><img alt="" src=""></p>

<p>Notice that any piece will be a rotation of one of the pieces of this example. Find the answers modulo $10^9 + 7$.</p>

### 입력 

 <p>The first line contains an integer $t$, the number of test cases ($1 \leq t \leq 100$).</p>

<p>Each test case is given on a separate line containing an integer $n$ ($1 \leq n \leq 10^{18}$), the width of the grid.</p>

### 출력 

 <p>For each test case, print a line with a single integer: the number of ways to fill the grid with aforementioned conditions modulo $10^9 + 7$.</p>

