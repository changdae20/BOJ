# [Gold II] Molecules, Molecules - 9233 

[문제 링크](https://www.acmicpc.net/problem/9233) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 브루트포스 알고리즘

### 문제 설명

<p>Organic molecules can be amazingly complex and need a great variety of shapes and conventions to represent them, particularly if we wish to depict details of their 3-dimensional structures. However, if we restrict ourselves to reasonably simple compounds, i.e. those with only single bonds between atoms, then we can represent them on a simple rectangular grid with bonds aligned horizontally or vertically. In such a molecule, carbon is bonded to four adjacent atoms, nitrogen to 3, oxygen to 2 and hydrogen to 1. Unfortunately not all such grids represent valid molecules. Your task is to write a program that will determine whether a given grid represents a valid molecule.</p>

### 입력 

 <p>Input will consist of a series of possible molecules portrayed as grids. The first line of the input for each molecule will consist of a pair of integers (r and c, 1 ≤ r c ≤ 5) representing the number of rows and columns in the rectangle to follow. The next r lines will contain c characters each, where the characters are chosen from the set {‘.’ (empty), ‘H’ (hydrogen), ‘O’ (oxygen), ‘N’ (nitrogen), ‘C’ (carbon)}. The file will be terminated by a line containing two zeroes (0 0). Note that ‘molecules’ classified as valid may not be physically realisable, and that there may in fact be more than one molecule present.</p>

### 출력 

 <p>For each potential molecule in the input, output one of the following lines:</p>

<pre>Molecule <num> is valid.
Molecule <num> is invalid.</pre>

<p>where <num> is a running number starting at 1.</p>

