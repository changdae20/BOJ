# [Diamond II] Tiling with T-tetrominoes - 18183 

[문제 링크](https://www.acmicpc.net/problem/18183) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

수학, 다이나믹 프로그래밍, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍, 분할 정복을 이용한 거듭제곱, 런타임 전의 전처리, 벌리캠프–매시

### 문제 설명

<p>T-tetromino는 아래와 같은 모양을 말한다.</p>

<p style="text-align: center;"><img alt="" src="" width="120"></p>

<p>N×M 크기의 직사각형 격자판이 있다. 이 격자판을 T-tetromino로 채우는 경우의 수는 몇 가지일까?</p>

<p>돌리거나 뒤집어서 같은 모양도 따로 센다.</p>

<p>예를 들어, N=4, M=4일 때 방법은 아래와 같은 2가지이다.</p>

<p style="text-align: center;"><img alt="" src="" width="480"></p>

### 입력 

 <p>첫째 줄에 직사각형 격자판의 가로 길이 N과 세로 길이 M이 주어진다. (1 ≤ N ≤ 10<sup>18</sup>​​​​, 1 ≤ M ≤ 15)</p>

### 출력 

 <p>T-tetromino로 직사각형 격자판을 채우는 경우의 수를 998,244,353으로 나눈 나머지를 출력한다.</p>

