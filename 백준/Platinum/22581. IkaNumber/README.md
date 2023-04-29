# [Platinum II] IkaNumber - 22581 

[문제 링크](https://www.acmicpc.net/problem/22581) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

이분 탐색, 분할 정복을 이용한 거듭제곱, 수학, 정수론

### 문제 설명

<p>数直線上の整数座標に, ねこの Taro の家, にんじん, うさぎの Hanako の家がこの順に並んでいる. 点 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container> にいるイカは, 一回のジャンプで <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi><mo>+</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x + 1$</span></mjx-container> または <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi><mo>+</mo><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x + 2$</span></mjx-container> に移動することができる.</p>

<p>あなたは, イカが Taro の家から Hanako の家までにんじんの置かれている座標に止まらずに行く経路が何通りあるか求めようとしたが, Taro の家, にんじん, Hanako の家の座標を知らないので 求めることができなかった. そこで, 代わりに経路の数として考えられる数をすべて列挙することにした.</p>

<p>ある Taro の家, にんじん, Hanako の家の配置に対してイカの経路数となる整数をイカ数と呼ぶことにする. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container> 番目に小さいイカ数 (1-indexed) を mod 1,000,000,007 で求めよ.</p>

### 입력 

 <p>入力はイカの形式で与えられる:</p>

<blockquote>
<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span> </mjx-container></p>
</blockquote>

### 출력 

 <p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container> 番目に小さいイカ数を 1,000,000,007 で割った余りを 1 行に出力せよ.</p>

