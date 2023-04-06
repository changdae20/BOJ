# [Platinum III] Destructive Game - 24656 

[문제 링크](https://www.acmicpc.net/problem/24656) 

### 성능 요약

메모리: 2020 KB, 시간: 24 ms

### 분류

게임 이론, 스프라그–그런디 정리

### 문제 설명

<p>There are $N$ stone piles, numbered by sequential integers from $1$ to $N$. The $i$-th pile contains $a_i$ stones. Additionally, each pile $i$ has an integer $b_i$ associated with it.</p>

<p>Alice and Bob play the following game using those stone piles.</p>

<p>They are alternately performing the following operation: choose pile $i$ and a nonnegative integer $k$ such that $b_i^k$ is not greater than the current number of stones in pile $i$, and remove $b_i^k$ stones from pile $i$. If a player cannot do that on their turn, the opposite player wins.</p>

<p>Alice moves first. Determine who will win if both players are playing optimally.</p>

### 입력 

 <p>The first line of input contains one integer $N$ ($1 \le N \le 10^5$), the number of piles. The $i$-th of the following $N$ lines contains two integers $a_i$ and $b_i$ ($1 \le a_i, b_i \le 10^9$): the initial number of stones in the $i$-th pile and the integer associated with it, respectively.</p>

### 출력 

 <p>If Alice wins the game when both sides are playing optimally, print "<code>Alice</code>". Otherwise, print "<code>Bob</code>".</p>

