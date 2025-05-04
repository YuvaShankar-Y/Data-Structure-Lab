A. Polycarp was presented with some sequence of integers a of length n. A sequence can make Polycarp happy only if it consists of different numbers (i.e., distinct numbers).

In order to make his sequence like this, Polycarp is going to make some (possibly zero) number of moves. In one move, he can:

remove the first (leftmost) element of the sequence.

For example, in one move, the sequence [3, 1, 4, 3] will produce the sequence [1, 4, 3], which consists of different numbers.

Determine the minimum number of moves he needs to make so that in the remaining sequence all elements are different. In other words, find the length of the smallest prefix of the given sequence a, after removing which all values in the remaining sequence will be unique.

Input:

The first line of the input contains a single integer t (1 <= t <= 10^4) \u2014 the number of test cases.

Each test case consists of two lines.
The first line contains an integer n (1 <= n <= 2 * 10^5) \u2014 the length of the given sequence a.
The second line contains n integers a_1, a_2, ..., a_n (1 <= a_i <= n) \u2014 elements of the given sequence a.

It is guaranteed that the sum of n values over all test cases does not exceed 2 * 10^5.

Output:

For each test case print your answer on a separate line  the minimum number of elements that must be removed from the beginning of the sequence so that all remaining elements are different.


B. Three guys play a game: first, each person writes down n distinct words of length 3. Then, they total up the number of points as follows:

If a word was written by one person \u2014 that person gets 3 points.

If a word was written by two people \u2014 each of the two gets 1 point.

If a word was written by all three \u2014 nobody gets any points.

In the end, how many points does each player have?

Input:

The input consists of multiple test cases. The first line contains an integer t (1 <= t <= 100) \u2014 the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1 <= n <= 1000) \u2014 the number of words written by each person.

The following three lines each contain n distinct strings \u2014 the words written by each person. Each string consists of 3 lowercase English characters.

Output:

For each test case, output three space-separated integers \u2014 the number of points each of the three guys earned. You should output the answers in the same order as the input; the i-th integer should be the number of points earned by the i-th guy.

C. Write a separate C++ menu-driven program to implement Priority Queue ADT using a max heap. Maintain proper boundary conditions and follow good coding practices. The Priority Queue ADT has the following operations,

1. Insert
2. Delete
3. Display
4. Search
5. Sort (Heap Sort)
6. Exit
