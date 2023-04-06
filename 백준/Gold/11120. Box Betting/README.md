# [Gold III] Box Betting - 11120 

[문제 링크](https://www.acmicpc.net/problem/11120) 

### 성능 요약

메모리: 3996 KB, 시간: 268 ms

### 분류

수학, 이분 탐색, 확률론

### 문제 설명

<p>Theres a new delivery boy at your company, supposed to drive around delivering a specific number of items to different locations. He needs to deliver at least X of an item, while the truck can at most take Y of the item. If there are more, the truck is will to break down due to the weight. If there are less, that means he hasn’  fulfilled the assignment. At the loading station, there’s a row of boxes he can bring along. Each box contains a specified number of items.</p>

<p>This driver isn’t the sharpest snail on the rock, however. Since he’s also too shy to ask for help, he’s decided to just choose one entirely random starting point in the row of boxes. Then he chooses a random end point among the boxes from the starting point to the end, inclusive. All the boxes between those points (inclusive) are loaded onto the truck.</p>

<p>You and the other employees have started betting on whether or not the truck breaks down, he brings to few items along or if he should happen to be lucky enough to fulfil the assignment without any problems. This gets you wondering. What is the actual probability for each of these scenarios to occur? Assume for the sake of this problem that the driver will always be able to fit all the boxes into the truck (after all, he had to have SOME skill, seeing as he was hired).</p>

### 입력 

 <p>The input will start with a line containing a single number T, the number of test cases. Each test case consists of three lines. The first one contains a single number N, the number of boxes. The second line contains a sequence of N characters (A-Z), B<sub>1</sub>B<sub>2</sub>...B<sub>N</sub> (no whitespace), representing the amount of items in each of the boxes in the same order as they’re located on the loading dock. An A represents an empty box, B a box with 1 item, and so on until Z, which represents a box with 25 items in it. The third line contains the two numbers L and U. L is the number of items the driver is supposed to deliver, while U is the maximum number of items the truck can take before it’ll break down.</p>

<ul>
	<li>0 < T ≤ 100</li>
	<li>1 < B ≤ 200000</li>
	<li>’A’ ≤ A<sub>i</sub> ≤ ’Z’</li>
	<li>0 ≤ L ≤ U ≤ 50000</li>
	<li>Both the starting and ending points of the segment are chosen with a uniform probability distribution.</li>
	<li>Any answer within 10<sup>−6</sup> of the correct one will be accepted.</li>
</ul>

### 출력 

 <p>For each test case, output three floating point numbers on a single line. The first number gives the probability that the driver succeeds, the second one that that he brings along too few items, and the third one that the truck breaks down.</p>

