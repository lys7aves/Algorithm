# Speed Typing (5pts, 9pts)



### Problem

Barbara is a speed typer. In order to check her typing speed, she performs a speed test. She is given a string II that she is supposed to type.

While Barbara is typing, she may make some mistakes, such as pressing the wrong key. As her typing speed is important to her, she does not want to spend additional time correcting the mistakes, so she continues to type with the errors until she finishes the speed test. After she finishes the speed test, she produces a PP.

Now she wonders how many extra letters she needs to delete in order to get II from PP. It is possible that Barbara made a mistake and PP cannot be converted back to II just by deleting some letters. In particular, it is possible that Barbara missed some letters.

Help Barbara find out how many extra letters she needs to remove in order to obtain II or if II cannot be obtained from PP by removing letters then output `IMPOSSIBLE`.

### Input

The first line of the input gives the number of test cases, TT. TT test cases follow.

Each test case has 22 lines. The first line of each test case is an input string II (that denotes the string that the typing test has provided). The next line is the produced string PP (that Barbara has entered).

### Output

For each test case, output one line containing `Case #xx: yy`, where xx is the test case number (starting from 11) and yy is the number of extra letters that need to be removed in order to obtain II. If it is not possible to obtain II then output `IMPOSSIBLE` as yy.

### Limits

Memory limit: 1 GB.
1≤T≤1001≤T≤100.
Both the strings contain letters from `a`-`z` and `A`-`Z`.
Length of the given strings will be 1≤|I|,|P|≤1051≤|I|,|P|≤105.

#### Test Set 1

Time limit: 20 seconds.
All letters in II are the same.

#### Test Set 2

Time limit: 40 seconds.

### Sample

*Note: there are additional samples that are not run on submissions down below.*

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0eWIJgJUBQcW6vIG5s6JTS_y-mYQ5IvSqALtnUAY8ZNXPc7oroKU4wh2ey6nmbZxG_2LpZ1G5fc6Xf7u89sc8/speed_typing_sample_ts1_input.txt?dl=1)

*content_copy*

```
2
aaaa
aaaaa
bbbbb
bbbbc
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U3WNimyjNeZZZjEJ2TjxcuKqzNsvcf52KqD9q4GYR83V_jgYYyQ3psJc9E8webKaYMfDG_ZhoNme2n1fVpdaOFB/speed_typing_sample_ts1_output.txt?dl=1)

*content_copy*

```
Case #1: 1
Case #2: IMPOSSIBLE
```

In the first test case, PP contains one extra `a`, so she needs to remove 11 extra letter in order to obtain II.
In the second test case, Barbara typed only 44 letters `b`, while II consists of 55 letters `b` so the answer is `IMPOSSIBLE`.



### Additional Sample - Test Set 2

*The following additional sample fits the limits of Test Set 2. It will not be run against your submitted solutions.*

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U3n__6y6ZljXoru9gyqT5N_AxFXt2J_ALB-lm0tQWnJo0x4R5wuTKvfWzI-gbr5HV8CIWE6EylcjImsIU9Rq6Y/speed_typing_sample_ts2_input.txt?dl=1)

*content_copy*

```
2
Ilovecoding
IIllovecoding
KickstartIsFun
kkickstartiisfun
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U3R0BplSePeO8eu1sLhZ3oOxZRAamlidohFrr9r4n-mRvtiI0GULHtvB5xkD_5tJe0ck1WsDL1yDoU3OG0ECS2y/speed_typing_sample_ts2_output.txt?dl=1)

*content_copy*

```
Case #1: 2
Case #2: IMPOSSIBLE
```

In the first test case, PP has 22 extra letters, `I` and `l`. The other letters are in the order given in II. So she needs to remove 22 letters in order to obtain II.
In the second test case, there is no letter `K` in PP so the answer is `IMPOSSIBLE`.





# Challenge Nine (8pts, 12pts)



### Problem

Ada gives John a positive integer NN. She challenges him to construct a new number (without leading zeros), that is a multiple of 99, by inserting *exactly* one digit (`0` …… `9`) anywhere in the given number NN. It is guaranteed that NN does not have any leading zeros.

As John prefers smaller numbers, he wants to construct the *smallest* such number possible. Can you help John?

### Input

The first line of the input gives the number of test cases, TT. TT test cases follow.

Each test case has a single line containing a positive integer NN: the number Ada gives John.

### Output

For each test case, output one line containing `Case #xx: yy`, where xx is the test case number (starting from 1) and yy is the new number constructed by John. As mentioned earlier, yy cannot have leading zeros.

### Limits

Memory limit: 1 GB.
1≤T≤1001≤T≤100.

#### Test Set 1

Time limit: 20 seconds.
1≤N≤1051≤N≤105.

#### Test Set 2

Time limit: 40 seconds.
For at most 10 cases:
1≤N≤101234561≤N≤10123456.
For the remaining cases:
1≤N≤1051≤N≤105.

### Sample

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U3pgCAbdRhku3zJAdaU3qFJvQwk601awLdXEsdxXxt7C2KkByVjAo8p9p6jJmC7U37LucvOPL1uF6kRFGLZ7Qn1AQ/challenge_nine_sample_ts1_input.txt?dl=1)

*content_copy*

```
3
5
33
12121
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U15hkMr5X3yZDzod41VSD85FmqOn5HuS8fmC1KrM6j62EvXoPvr5jyDzxrhTYFjOK2ny9cSDbzyALa1bGazmJ0IVtw/challenge_nine_sample_ts1_output.txt?dl=1)

*content_copy*

```
Case #1: 45
Case #2: 333
Case #3: 121212
```

In Sample Case #1, there are only two numbers that can be constructed satisfying the divisibility constraint: 4545 and 5454. John chooses the smaller number.

In Sample Case #2, 333333 is the only number possible.

In Sample Case #3, there are four possible options - 212121212121, 122121122121, 121221121221 and 121212121212 - out of which the smallest number is 121212121212.





# Palindrome Free Strings (13pts, 18pts)



### Problem

You are given a string SS consisting of characters `0`, `1`, and `?`. You can replace each `?` with either `0` or `1`. Your task is to find if it is possible to assign each `?` to either `0` or `1` such that the resulting string has no [substrings](https://en.wikipedia.org/wiki/Substring) that are [palindromes](https://en.wikipedia.org/wiki/Palindrome) of length 55 or more.

### Input

The first line of the input gives the number of test cases, TT. TT test cases follow.

Each test case consists of two lines.
The first line of each test case contains an integer NN, denoting the length of the string SS.
The second line of each test case contains a string SS of length NN.

### Output

For each test case, output one line containing `Case #xx: yy`, where xx is the test case number (starting from 1) and yy is `POSSIBLE` if there is a possible resulting string that has no palindromic substrings of length 55 or more, or `IMPOSSIBLE` otherwise.

### Limits

Memory limit: 1 GB.
1≤T≤1001≤T≤100.
SS only consists of characters `0`, `1` and `?`.

#### Test Set 1

Time limit: 20 seconds.
1≤N≤151≤N≤15.

#### Test Set 2

Time limit: 90 seconds.
1≤N≤5×1041≤N≤5×104.

### Sample

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0wKU1Dm_53PYwzCDR1g7Xh2xxeCSNp18rUY9EsRsEWeqCDZXGs6pL-0625c39rZIaTyoQ56IXmdLkBn7XQBDwr1tbrWFcBxOJErA/palindrome_free_strings_sample_ts1_input.txt?dl=1)

*content_copy*

```
2
9
100???001
5
100??
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U3rpsyBnOf6MKFAkmhZGdTL4fuTADVI3EMHVqvUyQNwzEdUx7PQHqgixCHJrMIobUxc9TsxkdHmAkfbSo1VlkkQZxksmXdAQ_5Bi2U/palindrome_free_strings_sample_ts1_output.txt?dl=1)

*content_copy*

```
Case #1: IMPOSSIBLE
Case #2: POSSIBLE
```

In Sample Case #1, to prevent the whole string from being a palindrome, the first and last question mark must be different characters.

If we replace first question mark with `0` and replace the last question mark with `1`, we get `1000?1001`. If the remaining `?` is replaced by `1`, we get 100011001, then the first 55 characters form a palindrome of length 55. Otherwise, we get `100001001`, the first 66 characters are a palindrome of length 66.

If we replace first question mark with `1` we get 1001?0001. If the remaining `?` is replaced by `1`, we get 100110001, then the last 55 characters form a palindrome of length 55. Otherwise, we get `100100001`, the last 66 characters are a palindrome of length 66.

Hence, there is no way to get a valid string.

In Sample Case #2, one of the valid strings after replacing all the `?` is `10011`.





# Interesting Integers



### Problem

Let us call an integer *interesting* if the product of its digits is [divisible](https://en.wikipedia.org/wiki/Divisor#Definition) by the sum of its digits. You are given two integers AA and BB. Find the number of interesting integers between AA and BB (both inclusive).

### Input

The first line of the input gives the number of test cases, TT. TT lines follow.

Each line represents a test case and contains two integers: AA and BB.

### Output

For each test case, output one line containing `Case #xx: yy`, where xx is the test case number (starting from 1) and yy is the number of interesting integers between AA and BB (inclusive).

### Limits

Time limit: 20 seconds.
Memory limit: 1 GB.
1≤T≤1001≤T≤100.

#### Test Set 1

1≤A≤B≤1051≤A≤B≤105.

#### Test Set 2

1≤A≤B≤10121≤A≤B≤1012.

### Sample

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U1RivownX_czTrir_T9onlrfGP-f2BCVUKObrnRZznUjfELoknO9GUy4sM4Fk-uSufVVtEtmxdZuFtSsQCK3R7RQhY9c_oNmQ/interesting_integers_sample_ts1_input.txt?dl=1)

*content_copy*

```
4
1 9
91 99
451 460
501 1000
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0m_dOKqELCh-fJeodiikS6cR4CNa5LaVbOs6WJSZvIn_AYqd0Al4iuudXJvajGyqJ3maWI-Id45w5FtLpY4xnbSQze-VR8Vd0/interesting_integers_sample_ts1_output.txt?dl=1)

*content_copy*

```
Case #1: 9
Case #2: 0
Case #3: 5
Case #4: 176
```

In Sample Case #1, since the product and the sum of digits are the same for single-digit integers, all integers between 11 and 99 are interesting.

In Sample Case #2, there are no interesting integers between 9191 and 9999.

In Sample Case #3, there are five interesting integers between 451451 and 460460:

1. 451451 (product of its digits is 4×5×1=204×5×1=20, sum of its digits is 4+5+1=104+5+1=10).
2. 453453 (product of its digits is 4×5×3=604×5×3=60, sum of its digits is 4+5+3=124+5+3=12).
3. 456456 (product of its digits is 4×5×6=1204×5×6=120, sum of its digits is 4+5+6=154+5+6=15).
4. 459459 (product of its digits is 4×5×9=1804×5×9=180, sum of its digits is 4+5+9=184+5+9=18).
5. 460460 (product of its digits is 4×6×0=04×6×0=0, sum of its digits is 4+6+0=104+6+0=10).

.