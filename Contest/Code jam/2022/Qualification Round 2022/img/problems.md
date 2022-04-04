# Qualification Round 2022 - Code jam 2022



## Punched Cards (11pts)

### Problem

A secret team of programmers is plotting to disrupt the programming language landscape and bring punched cards back by introducing a new language called *Punched Card Python* that lets people code in Python using punched cards! Like good disrupters, they are going to launch a viral campaign to promote their new language before even having the design for a prototype. For the campaign, they want to draw punched cards of different sizes in ASCII art.

![Example Punched Card.](https://codejam.googleapis.com/dashboard/get_file/AQj_6U1czYfn54qiD2aqETqCx884cVUzIDuxEgv_7KFfDN5b8VWc1JFa-nVRTY2r_KjyYVaL1w/punched_card.png)

The ASCII art of a punched card they want to draw is similar to an R×CR×C matrix without the top-left cell. That means, it has (R⋅C)−1(R⋅C)−1 cells in total. Each cell is drawn in ASCII art as a period (`.`) surrounded by dashes (`-`) above and below, pipes (`|`) to the left and right, and plus signs (`+`) for each corner. Adjacent cells share the common characters in the border. Periods (`.`) are used to align the cells in the top row.

For example, the following is a punched card with R=3R=3 rows and C=4C=4 columns:



```
..+-+-+-+
..|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
```



There are more examples with other sizes in the samples below. Given the integers RR and CC describing the size of a punched card, print the ASCII art drawing of it as described above.

### Input

The first line of the input gives the number of test cases, TT. TT lines follow, each describing a different test case with two integers RR and CC: the number of rows and columns of the punched card that must be drawn.

### Output

For each test case, output one line containing `Case #xx:`, where xx is the test case number (starting from 1). Then, output (2⋅R)+1(2⋅R)+1 additional lines with the ASCII art drawing of a punched card with RR rows and CC columns.

### Limits

Time limit: 5 seconds.
Memory limit: 1 GB.

#### Test Set 1 (Visible Verdict)

1≤T≤811≤T≤81.
2≤R≤102≤R≤10.
2≤C≤102≤C≤10.

### Sample

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0jeEUyfbTLWBsgUlc-GpGeEEiaMDKSruc5aC6zT_pNSECMIq1U_MK4klfmBkCdYZrrEvJxMvvqYLb7fTHVyRK9/punched_cards_sample_ts1_input.txt?dl=1)

*content_copy*

```
3
3 4
2 2
2 3
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0hVuGizE5ZWMOzfE0qEoLVGb4HwG6FY_6ZXfasIWGtQLrqcvkLTU5T0JlH3C780a6ZGuFFs1KaAWctNg3C7KA6YQ/punched_cards_sample_ts1_output.txt?dl=1)

*content_copy*

```
Case #1:
..+-+-+-+
..|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
Case #2:
..+-+
..|.|
+-+-+
|.|.|
+-+-+
Case #3:
..+-+-+
..|.|.|
+-+-+-+
|.|.|.|
+-+-+-+
```

Sample Case #1 is the one described in the problem statement. Sample Cases #2 and #3 are additional examples. Notice that the output for each case contains exactly R⋅C+3R⋅C+3 periods.





## 3D Printing (13pts)

### Problem

You are part of the executive committee of the Database Design Day festivities. You are in charge of promotions and want to print three D's to create a logo of the contest. You can choose any color you want to print them, but all three have to be printed in the same color.

![Illustration of Sample #1.](https://codejam.googleapis.com/dashboard/get_file/AQj_6U1cdSOY7WiKnEIm4EtiJyBgZdflL0gjG2oEiBAUuAtPBJtBjuu9BJSLJBrFb4K43rU9/3d_printing.png)

You were given three printers and will use each one to print one of the D's. All printers use ink from 44 individual cartridges of different colors (cyan, magenta, yellow, and black) to form any color. For these printers, a color is uniquely defined by 44 non-negative integers cc, mm, yy, and kk, which indicate the number of ink units of cyan, magenta, yellow, and black ink (respectively) needed to make the color.

The total amount of ink needed to print a single D is exactly 106106 units. For example, printing a D in pure yellow would use 106106 units of yellow ink and 00 from all others. Printing a D in the Code Jam red uses 00 units of cyan ink, 500000500000 units of magenta ink, 450000450000 units of yellow ink, and 5000050000 units of black ink.

To print a color, a printer must have at least the required amount of ink for each of its 44 color cartridges. Given the number of units of ink each printer has in each cartridge, output any color, defined as 44 non-negative integers that add up to 106106, such that all three printers have enough ink to print it.

### Input

The first line of the input gives the number of test cases, TT. TT test cases follow. Each test case consists of 33 lines. The ii-th line of a test case contains 44 integers CiCi, MiMi, YiYi, and KiKi, representing the number of ink units in the ii-th printer's cartridge for the colors cyan, magenta, yellow, and black, respectively.

### Output

For each test case, output one line containing `Case #xx: rr`, where xx is the test case number (starting from 1) and rr is `IMPOSSIBLE` if there is no color that can be printed by all 33 printers. Otherwise, rr must be equal to "cc mm yy kk" where cc, mm, yy, and kk are non-negative integers that add up to 106106 and c≤Cic≤Ci, m≤Mim≤Mi, y≤Yiy≤Yi, and k≤Kik≤Ki, for all ii.

If there are multiple solutions, you may output any one of them. (See "What if a test case has multiple correct solutions?" in the [Competing section of the FAQ](https://codingcompetitions.withgoogle.com/codejam/faq#competing).) This information about multiple solutions will not be explicitly stated in the remainder of the 2022 contest.

### Limits

Time limit: 5 seconds.
Memory limit: 1 GB.

#### Test Set 1 (Visible Verdict)

1≤T≤1001≤T≤100.
0≤Ci≤1060≤Ci≤106, for all ii.
0≤Mi≤1060≤Mi≤106, for all ii.
0≤Yi≤1060≤Yi≤106, for all ii.
0≤Ki≤1060≤Ki≤106, for all ii.

### Sample

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U23KcZPWbyC3QWaqzFRW7s1A0YaejwwTEBWrNDEP2xzB_A07i7mEk-hF_cxu19Gaq8rRdskQsCKiKMYSp6NOA/3d_printing_sample_ts1_input.txt?dl=1)

*content_copy*

```
3
300000 200000 300000 500000
300000 200000 500000 300000
300000 500000 300000 200000
1000000 1000000 0 0
0 1000000 1000000 1000000
999999 999999 999999 999999
768763 148041 178147 984173
699508 515362 534729 714381
949704 625054 946212 951187
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U3j2MjGGiAoTaeRKJed1zXFRamTRXVEbu2o9_FkgRLO6LcskafrSr1eoJ_jq7_y_ykg09t-MUgNN-WYWrkY3iw/3d_printing_sample_ts1_output.txt?dl=1)

*content_copy*

```
Case #1: 300000 200000 300000 200000
Case #2: IMPOSSIBLE
Case #3: 400001 100002 100003 399994
```

Sample Case #1 is the image provided above. The proposed color is using up all of the ink in the cyan, magenta, and yellow cartridges of the first printer and all of the ink in the black cartridge of the last printer. This means that no additional unit of ink could be used from any of the 44 ink colors, so the given sample output is the only possible output for this case.

In Sample Case #2, magenta is the only color that both the first and second printers have, so our only chance would be to use 106106 units of magenta. Unfortunately, the third printer does not have quite enough, making this case impossible.

In Sample Case #3, other correct outputs are: "`400000 100000 100000 400000`", "`300000 0 0 700000`", and "`350000 140000 160000 350000`", among lots of others. Notice that "`300000 140000 160000 700000`" would not be a valid answer because, even though there is enough ink in all printers to do that, the total number of ink units must be exactly 106106.





## d1000000

### Problem

While the most typical type of dice have 66 sides, each of which shows a different integer 11 through 66, there are many games that use other types. In particular, a dkdk is a die with kk sides, each of which shows a different integer 11 through kk. A d6d6 is a typical die, a d4d4 has four sides, and a d1000000d1000000 has one million sides.

![Dice from sample case 1](https://codejam.googleapis.com/dashboard/get_file/AQj_6U1qY5tfNCjf8YoCMu6HlnbBl9frVt7iWV6MzsRqgwA1EitmQlG2zgBhSvGwhaDa/D1000000.png)

In this problem, we start with a collection of NN dice. The ii-th die is a dSidSi, that is, it has SiSi sides showing integers 11 through SiSi. A straight of length ℓℓ starting at xx is the list of integers x,x+1,…,x+(ℓ−1)x,x+1,…,x+(ℓ−1). We want to choose some of the dice (possibly all) and pick one number from each to form a straight. What is the longest straight we can form in this way?

### Input

The first line of the input gives the number of test cases, TT. TT test cases follow. Each test case is described in two lines. The first line of a test case contains a single integer NN, the number of dice in the game. The second line contains NN integers S1,S2,…,SNS1,S2,…,SN, each representing the number of sides of a different die.

### Output

For each test case, output one line containing `Case #xx: yy`, where xx is the test case number (starting from 1) and yy is the maximum number of input dice that can be put in a straight.

### Limits

Memory limit: 1 GB.
1≤T≤1001≤T≤100.

#### Test Set 1 (Visible Verdict)

Time limit: 5 seconds.
1≤N≤101≤N≤10.
4≤Si≤204≤Si≤20, for all ii.

#### Test Set 2 (Visible Verdict)

Time limit: 15 seconds.
1≤N≤1051≤N≤105.
4≤Si≤1064≤Si≤106, for all ii.

### Sample

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0HzDWaevGxTM4IrNElYGgPVeNd9eFiTw6rIVkm7Yq-wUF5NqMHrdGeBVdq5MTdSC5geFDtk0QzIO9hhQ/d1000000_sample_ts1_input.txt?dl=1)

*content_copy*

```
4
4
6 10 12 8
6
5 4 5 4 4 4
10
10 10 7 6 7 4 4 5 7 4
1
10
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U3MkkssFM-fs3A1ETN4CU2fFDGt8VuMSGaUUK973i7jaEifbJJV9jzlXmamqs2xlAzDAckoLa77B49RN2s/d1000000_sample_ts1_output.txt?dl=1)

*content_copy*

```
Case #1: 4
Case #2: 5
Case #3: 9
Case #4: 1
```

In Sample Case #1, there are multiple ways to form a straight using all 44 dice. One possible way is shown in the image above.

In Sample Case #2, since none of the dice can show an integer greater than 55, there is no way to have a straight with more than 55 dice. There are multiple ways to form a straight with exactly 55 dice. For example, pick the integers 44 and 55 for both d5d5⁠'s and then integers 1,2,1,2, and 33 for three of the d4d4⁠'s to form 1,2,3,4,51,2,3,4,5.

In Sample Case #3, it is possible to form the straight 1,2,3,4,5,6,7,8,91,2,3,4,5,6,7,8,9 by discarding one d4d4 and using the d4d4⁠'s, d5d5, and d6d6 to get 11 through 44; the d7d7⁠'s to get 55 through 77; and the d10d10⁠'s to get 88 and 99. There is no way to form a straight of length 1010, so this is the best that can be done.

In Sample Case #4, we can only form a straight of length 11, but we can do so by picking any integer for the d10d10 we are given.





## Chain Reactions

### Problem

Wile lives alone in the desert, so he entertains himself by building complicated machines that run on chain reactions. Each machine consists of NN modules indexed 1,2,…,N1,2,…,N. Each module may point at one other module with a lower index. If not, it points at the abyss.

Modules that are not pointed at by any others are called *initiators*. Wile can manually trigger initiators. When a module is triggered, it triggers the module it is pointing at (if any) which in turn may trigger a third module (if it points at one), and so on, until the chain would hit the abyss or an already triggered module. This is called a *chain reaction*.

Each of the NN modules has a fun factor FiFi. The fun Wile gets from a chain reaction is the largest fun factor of all modules that triggered in that chain reaction. Wile is going to trigger each initiator module once, in some order. The overall fun Wile gets from the session is the sum of the fun he gets from each chain reaction.

For example, suppose Wile has 44 modules with fun factors F1=60,F2=20,F3=40,F1=60,F2=20,F3=40, and F4=50F4=50 and module 11 points at the abyss, modules 22 and 33 at module 11, and module 44 at module 22. There are two initiators (33 and 44) that Wile must trigger, in some order.

![Example in statement when activating 4 then 3.](https://codejam.googleapis.com/dashboard/get_file/AQj_6U082gwrOWxTIk0xb0txUp0BUKaS_Eq-ajDPKkxFmikoP0Mj0FSs7KrB_0xXsCCs5A/example_1.gif)

As seen above, if Wile manually triggers module 44 first, modules 44, 22, and 11 will get triggered in the same chain reaction, for a fun of max(50,20,60)=60max(50,20,60)=60. Then, when Wile triggers module 33, module 33 will get triggered alone (module 11 cannot get triggered again), for a fun of 4040, and an overall fun for the session of 60+40=10060+40=100.

![Example in statement when activating 3 then 4.](https://codejam.googleapis.com/dashboard/get_file/AQj_6U1l2CkoolsqG_Rbe9sg49oRAp4iWH_XpyxM8UUBooUbKHsKPfsxbZ869C9oBMO4Aw/example_2.gif)

However, if Wile manually triggers module 33 first, modules 33 and 11 will get triggered in the same chain reaction, for a fun of max(40,60)=60max(40,60)=60. Then, when Wile triggers module 44, modules 44 and 22 will get triggered in the same chain reaction, for a fun of max(50,20)=50max(50,20)=50, and an overall fun for the session of 60+50=11060+50=110.

Given the fun factors and the setup of the modules, compute the maximum fun Wile can get if he triggers the initiators in the best possible order.

### Input

The first line of the input gives the number of test cases, TT. TT test cases follow, each described using 3 lines. Each test case starts with a line with a single integer NN, the number of modules Wile has. The second line contains NN integers F1,F2,…,FNF1,F2,…,FN where FiFi is the fun factor of the ii-th module. The third line contains NN integers P1,P2,…PNP1,P2,…PN. If Pi=0Pi=0, that means module ii points at the abyss. Otherwise, module ii points at module PiPi.

### Output

For each test case, output one line containing `Case #xx: yy`, where xx is the test case number (starting from 1) and yy is the maximum fun Wile can have by manually triggering the initiators in the best possible order.

### Limits

Memory limit: 1 GB.
1≤T≤1001≤T≤100.
1≤Fi≤1091≤Fi≤109.
0≤Pi≤i−10≤Pi≤i−1, for all ii.

#### Test Set 1 (Visible Verdict)

Time limit: 5 seconds.
1≤N≤101≤N≤10.

#### Test Set 2 (Visible Verdict)

Time limit: 5 seconds.
1≤N≤10001≤N≤1000.

#### Test Set 3 (Hidden Verdict)

Time limit: 10 seconds.
1≤N≤1000001≤N≤100000.

### Sample

Sample Input

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0Utcq9fa05l-xjNl5TBjMNGY4u9v6k5fsQvaTUorKS_bBE9Y1RDEzTE-MdwjLsN_SnYOxFN1qWIt2V1BfmzSudJOc/chain_reactions_sample_ts1_input.txt?dl=1)

*content_copy*

```
3
4
60 20 40 50
0 1 1 2
5
3 2 1 4 5
0 1 1 1 0
8
100 100 100 90 80 100 90 100
0 1 2 1 2 3 1 3
```

Sample Output

[*save_alt*](https://codejam.googleapis.com/dashboard/get_file/AQj_6U1-glPVJY6cQ_GLkTgEOnklrnAZlsKjIpgLgoJ60XsiMW7kyP1z-azqFByeglR5hw6a0EizcEfj-sSpU2DHN0GyXUak/chain_reactions_sample_ts1_output.txt?dl=1)

*content_copy*

```
Case #1: 110
Case #2: 14
Case #3: 490
```

Sample Case #1 is the one explained in the problem statement.

In Sample Case #2, there are 44 initiators (modules 22 through 55), so there are 44 chain reactions. Activating them in order 3,5,4,23,5,4,2 yields chains of fun 3,5,4,23,5,4,2 for an overall fun of 1414. Notice that we are summing the four highest fun numbers in the input, so there is no way to get more than that.

In Sample Case #3, an optimal activation order of the 55 initiators is 4,5,7,6,84,5,7,6,8.





## Twisty Little Passages (29pts)

### Problem

You are investigating a cave. The cave has NN rooms. There are underground passages that bidirectionally connect some pairs of rooms. Each room has at least one passage connected to it. No passage goes from a room to itself, and no two rooms are connected by more than one passage.

When in a room, you can identify what room you are in and see how many passages it connects to, but you cannot distinguish the passages. You want to estimate the number of passages that exist in the cave. You are allowed to do up to KK operations. An operation is either:

- be magically teleported to a room of your choice, or
- walk through a random passage connected to the room you are in, taking you to the room at the other end of that passage.

When you decide to walk through a passage, you are unable to choose which one, because they are all alike. A passage is chosen for you uniformly at random.

You begin the investigation in an arbitrary room. Estimate the number of passages between rooms in the cave with at most KK operations.

If EE is your estimate and PP is the actual number of passages, your solution is considered correct for a test case if and only if P⋅2/3≤E≤P⋅4/3P⋅2/3≤E≤P⋅4/3.

To pass a test set, your solution must be correct for at least 90% of the test cases in that set.

### Input and output

This is an interactive problem. You should make sure you have read the information in the Interactive Problems section of our [FAQ](https://codingcompetitions.withgoogle.com/codejam/faq).

Initially, your program should read a single line containing an integer, TT, the number of test cases. Then, TT test cases must be processed.

For each test case, your program must first read a line containing two integers NN and KK: the number of rooms in the cave, and the maximum number of room operations you are allowed. Rooms are numbered between 11 and NN. Then, your program must process up to K+1K+1 exchanges.

The ii-th exchange starts with you reading a line containing two integers RiRi and PiPi, representing the number of the room you are currently in and the number of passages it connects to. Then, you must output a single line containing one of the following:

- A single uppercase `W`: this means you want to walk through a random passage.
- A single uppercase `T` and an integer SS: this means you want to teleport to room SS.
- A single uppercase `E` and an integer EE: this means you want to finish exploring and estimate that the cave contains EE passages.

After an estimation operation, the judge will immediately start the next test case if there is one, regardless of the correctness of your estimation. If there is no next test case, the judge will wait for you to finish without any further output.

If the judge receives an invalidly formatted line from your program at any moment, or if your (K+1)(K+1)-th exchange for a test case is not an estimation operation, the judge will print a single number −1−1 and will not print any further output. If your program continues to wait for the judge after receiving a −1−1, your program will time out, resulting in a Time Limit Exceeded error. Notice that it is your responsibility to have your program exit in time to receive a Wrong Answer judgment instead of a Time Limit Exceeded error. As usual, if the memory limit is exceeded, or your program gets a runtime error, you will receive the appropriate judgment.

### Limits

Time limit: 120 seconds.
Memory limit: 1 GB.

#### Test Set 1 (Visible Verdict)

1≤T≤1001≤T≤100.
2≤N≤1052≤N≤105.
K=8000K=8000.
Each room has at least one passage connected to it.

### Testing Tool

You can use this testing tool to test locally or on our platform. To test locally, you will need to run the tool in parallel with your code; you can use our [interactive runner](https://storage.googleapis.com/coding-competitions.appspot.com/interactive_runner.py) for that. For more information, read the instructions in comments in that file, and also check out the [Interactive Problems section](https://codingcompetitions.withgoogle.com/codejam/faq#interactive-problems) of the FAQ.

Instructions for the testing tool are included in comments within the tool. We encourage you to add your own test cases. Please be advised that although the testing tool is intended to simulate the judging system, it is **NOT** the real judging system and might behave differently. If your code passes the testing tool but fails the real judge, please check the [Coding section](https://codingcompetitions.withgoogle.com/codejam/faq#coding) of the FAQ to make sure that you are using the same compiler as us.

[Download testing tool](https://codejam.googleapis.com/dashboard/get_file/AQj_6U3RZNgcxXrkH2_6VkJNCKqP0eq4chLwlfkVTiLdVQLewmiXfgBu6o3iGi8Ezq5BxsFiumNi/local_testing_tool.py3?dl=1)

Sample Interaction

Judge

Solution

Number of cases

```
1
```

Case 1

```
5 3
```

Judge gives N=5,K=3N=5,K=3.

```
4 1
```

We start at room 44 which has 11 passage.

```
T 5
```

Teleport to room 5.

```
5 2
```

It has two passages.

```
W
```

Walk through a passage.

```
4 1
```

We arrived at room 4 again.

```
T 1
```

Teleport to room 1.

```
1 3
```

It has three passages.

```
E 5
```

Guess 5 passages.
(It can be shown that the actual number of passages is either 4 or 5. The two possible graphs for this test case are shown below.)

![Twisty Little Passages sample case example.](https://codejam.googleapis.com/dashboard/get_file/AQj_6U1ixCEatJoow51MZZQHduLjUYFq4Avs9unNxrP-DvS3Y4fAfvoZ3E1R5vae8Il0wF32QFphrwKmqaGyekA/twisty_little_passages.png)