/*
Question 1:
We will prove by induction that for all integers n >= 1, (1 + 2^n) <= 3^n. 

Base Case: 
n = 1
P(n)= (1 + 2^1) <= 3^1
    3 <= 3
This is true for the base case, we will assume that this is also true for an integer
k where k >= 1. 

Induction step: 
If P(k) is true, we will prove that P(k+1) is also true. 
P(k) = (1 + 2^k) <= 3^k
    2^k <= 3^k - 1
P(k+1) = (1+ 2^(k+1)) <= 3^(k+1)
     = (1 + 2^k * 2) <= 3^k * 3 //rewritten
     = 2^k * 2 <= (3^k *3)- 1

the inductive step showedc that 2^k <= 3^k -1, 
if we multiple both sides by 3 we get the inequality 3*2k <= 3* 3^k - 3, 
if that is true, then 2^k * 2 <= (3*2k <= 3* 3^k - 3)<= (3^k *3)- 1 
and P(k+1) is also true             ^inductive step


Question 2:
a. Must have at least 1 digit:
    total possible combos - combos with no digits: 
Total: 26 lowercase, 26 uppercase, 10 digits: 62
5^62, for each of the 5 characters you have 62 choices, 62*62*62*62*62 

no digits: 
5^52, for each of the 5 characters you can only choose 52 of the characters, 52*52*52*52*52
(5^62 - 5^52)= 5^10 combinations

b. C(10, 5), you use combinations because in sets {1, 2, 3} is the same as {2, 1, 3} etc.
Out of the 10 integers you are choosing combinations of 5. Since order does not matter
we use combinations and not permutations. 

Question 3: 
a. 
Total combos: 2^8 = 256
There are 4 ways you can have more 0's than 1's:
8 zeroes, 0 ones: 1 possible combination 
7 zeroes, 1 ones; C(8, 1) combinations (choose the ones spot the one would be)
6 zeroes, 2 ones; C(8, 2)
5 zeroes, 3 ones; C(8, 3)
(1 + 8 + 28 + 56) / 256 = 93/256
0.363 chance

b. 
Possible sums: 
2: 4/36 = .2222222
3: 12/36 = 1
4: 11/36 = 1.2222
5: 6/36 = .833333
6: 1/36 = .166667

E(x): 2(4/26) + 3(12/36) + 3(11/36) + 5(6/36) + 6(1/36)
expected: 3.44

Question 4: 
Function1:
theta log^2(n)
    the outter loop is a constant, the while loop is running at log n, the inner for loop 
    is running at log(n)

    The last for loop runs at theta log(n), but this loop is lower order;

Function2:
    This would run at theta log(n), since you are halving n every time the function is
    recursively called, 
*/