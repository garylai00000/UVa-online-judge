# [10827 Maximum sum on a torus](https://uva.onlinejudge.org/external/108/10827.pdf)
Three approaches for this problem
## Approach 1 (inclusion and exclusion)
First, expand the grid length and width to 2*N as following example, which makes it easier to solve the cyclic situation.

original grid (2*2):

| a | b |
|---|---|
| c | d |

after expand (4*4):

| a | b | a | b |
|---|---|---|---|
| c | d | c | d |
| a | b | a | b |
| c | d | c | d |

Second, calculate an 2D array **sum** where 

![image1](https://github.com/garylai00000/UVa-online-judge/blob/master/UVa10827/images/image1.png?raw=true)

By using **inclusion and exclusion**, we can calculate this array in **O(N^2)**

Finally, enumerate each rectangle in the expanded grid with length at most **N** and find the max summation, using the 2D array **sum** with **inclusion and exclusion**.

### Time complexity
### O(N^4) 

## Approach 2 (Maximum Subarray with length at most N)
First, expand the grid length and width to 2*N as following example, which makes it easier to solve the cyclic situation.

original grid (2*2):

| a | b |
|:-:|---|
| c | d |

after expand (4*4):

| a | b | a | b |
|:-:|---|---|---|
| c | d | c | d |
| a | b | a | b |
| c | d | c | d |

Second, calculate an 2D array **sum** where 

![image2](https://github.com/garylai00000/UVa-online-judge/blob/master/UVa10827/images/image2.png?raw=true)


Third, enumerate each up and down boundary and calculate the correspondent column summation for each column as an array, the problem then becomes a **maximum sub array problem** with length at most **N** and we can solve this problem in **O(N)** with a **double ended queue**.

### Time complexity
### O(N^3) 

## Approach 3 (Maximum and Minimum Subarray)
First, expand the grid length to 2*N as following example, without expanding the width of the grid, we have to handle the cyclic situation in another way.

original grid (2*2):

| a | b |
|:-:|---|
| c | d |

after expand (4*2):

| a | b | 
|:-:|---|
| c | d |
| a | b |
| c | d | 

Second, calculate an 2D array **sum**  same as **Approach 2** where 


![image2](https://github.com/garylai00000/UVa-online-judge/blob/master/UVa10827/images/image2.png?raw=true)

which denotes the column summation

Third, enumerate each up and down boundary and calculate the correspondent column summation for each column as an array, similar to **Approach 2** but instead of finding the **maximum sub array** with length at most **N**, we find the **maximum sub array** and the **minimum sub array** which represents two cases. The **maximum sub array** indicates the case without cyclic. The other cyclic case can be calculated by the **total summation of the array** minus the **minimum sub array**. Then we choose the larger one as a better solution.

### Time complexity
### O(N^3) 

Although **Approach 2 and 3** shares the same time complexity, **Approach 3** is faster since it reduces the gird into half.
