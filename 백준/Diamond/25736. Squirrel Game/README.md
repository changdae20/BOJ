# [Diamond V] Squirrel Game - 25736 

[문제 링크](https://www.acmicpc.net/problem/25736) 

### 성능 요약

메모리: 3192 KB, 시간: 44 ms

### 분류

게임 이론, 스프라그–그런디 정리

### 문제 설명

<p>Twinkle and Nova are walking in a national park. There are $M$ stones laid out in the park at positions $1,\cdots ,M$, from left to right. There are also $N$ squirrels on the stones at $x_1,\cdots ,x_N$, from left to right. The squirrels are on different stones from each other, and they are all facing left.</p>

<p>Twinkle suggests the following game to Nova. Twinkle and Nova take turns alternately. On each turn, a player has to place an acorn on one of the stones without a squirrel. Also, there must be at least one squirrel to the right of the acorn.</p>

<p>After placing an acorn, the leftmost $K$ squirrels among the squirrels to the right of the acorn start running towards the acorn at the same time. (If there are less than $K$ squirrels to the right of the acorn, all of them start running.) All the squirrels run at the same speed. Once any of the squirrels reach the acorn, all the squirrels immediately stop. The squirrel who has reached the acorn puts the acorn into its cheek pouch, effectively removing the acorn on the stone.</p>

<p>If there is no valid stone to place an acorn on, the player currently taking the turn immediately loses.</p>

<p>Twinkle goes first. Determine who will win if both players are playing optimally.</p>

<p style="text-align: center;"><img alt="" src="" style="max-width: 100%; width: 600px;"></p>

### 입력 

 <p>The first line contains three space-separated integers, $M$, $N$, and $K$.</p>

<p>The second line contains $N$ space-separated integers $x_1,\cdots ,x_N$.</p>

### 출력 

 <p>If Twinkle wins, output <span style="color:#e74c3c;"><code>Twinkle</code></span>. Otherwise, output <span style="color:#e74c3c;"><code>Nova</code></span>.</p>

