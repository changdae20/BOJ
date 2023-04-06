# [Gold IV] Hectic Harbour II - 25252 

[문제 링크](https://www.acmicpc.net/problem/25252) 

### 성능 요약

메모리: 3584 KB, 시간: 44 ms

### 분류

자료 구조, 애드 혹, 연결 리스트

### 문제 설명

<p>An upcycled shipping container makes a good site to open a pop-up store in a trendy part of town. Such a business comes with its own risks -- for example, this morning a local freight company mistook your premises for one of their crates and sent it to the shipyard for loading.</p>

<p>Your crate is now sitting in the shipyard in one of two stacks ready for loading onto the ship. Each crate except yours has its own tracking number.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 406px; height: 150px;"></p>

<p style="text-align: center;">Figure H.1: Illustration of Sample Input 2. Your business is in the unmarked crate.</p>

<p>The system for loading crates is automated and proceeds in a preset order. First, the crate with the next tracking number is uncovered by picking up all of the crates on top, one-by-one, and moving every single one across to the other stack individually. Then the crate is taken to the ship. Since your crate is not part of this order, it is generally ignored and will not be loaded.</p>

<p>After loading a crate, some time is spent securing the whole cargo on board. This is your chance to recover your container -- if it is on top of one of the stacks, you will have just enough time to slide it off and get it back.</p>

<p>How many such opportunities will you have in total?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with three integers $n$, $s_1$ and $s_2$ ($2 \leq s_1, s_2 \leq 2 \cdot 10^{5}, s_1 + s_2 = n + 1$), the number of crates with a tracking number, the number of crates on the first stack, and the number of crates on the second stack respectively.</li>
	<li>One line containing $s_1$ integers, the tracking numbers of the crates on the first stack, in order from bottom to top.</li>
	<li>One line containing $s_2$ integers, the tracking numbers of the crates on the second stack, in order from bottom to top.</li>
</ul>

<p>The crates with tracking number are numbered from $1$ to $n$ and are removed from the stacks in that order. Your crate has tracking number $0$ and will never be on top of one of the stacks initially.</p>

### 출력 

 <p>Output the number of occasions at which your crate is on top of one of the stacks and the crane is busy loading a crate.</p>

