# [Silver V] Loo Rolls - 17895 

[문제 링크](https://www.acmicpc.net/problem/17895) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 정수론

### 제출 일자

2024년 6월 7일 21:33:04

### 문제 설명

<p>Your friend Nick needs your help with a hard problem that he came across in real life. Nick has a loo roll of length ℓ centimetres in his bathroom. Every time he visits the toilet, he uses exactly n centimetres of loo roll. When the roll runs out, Nick always goes to the store and buys a new one of length ℓ directly afterwards. However, sometimes the roll runs out even though Nick still needs a non-zero amount of paper. Let us call such an event a crisis.</p>

<p>Nick has a clever way of preventing crises from happening: he uses a backup roll. The backup roll is another roll of length ℓ that is hidden somewhere in the bathroom, and when the regular roll runs out even though Nick still needs more paper, he will take that amount from the backup roll. Then he will replace the regular roll directly after the visit.</p>

<p>As you can imagine, this makes crises much less frequent. But still, the backup roll will also slowly run out, and eventually a crisis might still happen. So to generalize this, Nick wants to use several layers of backup rolls. First he will take paper from roll number 1 (the regular roll), if it runs out he will take from roll number 2, then if roll 2 runs out from roll number 3, and so on all the way up to roll number k. After each visit, all the rolls that have run out will be replaced. Nick managed to prove that if he picks a large enough number k, he can actually make it so that crises never happen! Your task is to find the smallest such number k.</p>

### 입력 

 <p>The input consists of a single line containing the two integers ℓ and n (1 ≤ n ≤ ℓ ≤ 10<sup>10</sup>).</p>

### 출력 

 <p>Output the smallest integer k such that crises will never happen when using k layers of rolls (including the regular roll).</p>

