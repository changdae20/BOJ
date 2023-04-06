# [Silver II] Pancake Deque - 25096 

[문제 링크](https://www.acmicpc.net/problem/25096) 

### 성능 요약

메모리: 2420 KB, 시간: 2068 ms

### 분류

자료 구조, 그리디 알고리즘, 덱

### 문제 설명

<p>Pancakes are normally served in stacks, but the Infinite House of Pancakes embraces change! The restaurant's new advertising hook is to serve the pancakes from a deque, or double-ended queue.</p>

<p>You are a server at the restaurant, and your job is to serve every pancake in the deque. Customers will arrive one at a time, and each one gets a single pancake. You must serve each customer either the leftmost or rightmost pancake in the deque; the choice is yours. When a pancake is served, it disappears from the deque, exposing the pancake that was next to it. Or, once there is only one pancake left, your only choice is to serve that one, and then your job is complete!</p>

<p style="text-align: center;"><img alt="" src="" style="width: 471px; height: 115px;"></p>

<p>Each pancake has a deliciousness level. Because customers do not get to choose which pancakes they get, each customer only has to pay for their pancake if it is at least as delicious as <i>each</i> of the pancakes that <i>all</i> of the previous customers got. (The first customer always pays for their pancake, since in that case there are no previous customers.)</p>

<p>How many customers will pay for their pancake, if you serve the pancakes in an order that maximizes that number?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case is described with two lines. The first line of a test case contains a single integer $N$, the number of pancakes in the pancake deque. The second line of a test case contains $N$ integers $D_1,D_2,\dots,D_N$, where $D_i$ is the deliciousness level of the $i$-th pancake from the left in the deque.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where $x$ is the test case number (starting from 1) and $y$ is the number of customers who pay for their pancakes, if you serve the pancakes in an order that maximizes that number.</p>

