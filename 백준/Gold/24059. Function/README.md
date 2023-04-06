# [Gold II] Function - 24059 

[문제 링크](https://www.acmicpc.net/problem/24059) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 정수론, 분할 정복을 이용한 거듭제곱, 페르마의 소정리

### 문제 설명

<p>You are given a function $f \, : \, \mathbb{N}_0 \to \mathbb{N}_0$ defined as below. ($\mathbb{N}_0$ denotes the set of non-negative integers.)</p>

<ul>
	<li>$f(0) = a_0$</li>
	<li>$f(i) = a_i^{f(i - 1)}$ ($i \ge 1$)</li>
</ul>

<p>Find the value of $f(n)$ modulo $m$.</p>

### 입력 

 <p>The first line contains a single integer $n$.</p>

<p>The second line contains $n + 1$ integers $a_0, \, a_1, \, \cdots, \, a_n$.</p>

<p>The third line contains a single integer $m$.</p>

### 출력 

 <p>Print the value of $f(n)$ modulo $m$.</p>

