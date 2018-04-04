# [10827 Maximum sum on a torus](https://uva.onlinejudge.org/external/108/10827.pdf)
Three approaches for this problem
## Approach 1 (inclusion and exclusion)
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

![img1](http://www.sciweavers.org/tex2img.php?eq=%20sum%5Bn%5D%5Bm%5D%20%3D%20%5Csum_%7Bi%3D0%7D%5En&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)![img1](http://www.sciweavers.org/tex2img.php?eq=%5Csum_%7Bj%3D0%7D%5Em%20grid%5Bi%5D%5Bj%5D%20&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)

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

![img2](http://www.sciweavers.org/tex2img.php?eq=sum%5Bn%5D%5Bm%5D%20%3D%20%5Csum_%7Bi%3D0%7D%5E%7Bn%7D%20grid%5Bi%5D%5Bm%5D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)


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


![img3](http://www.sciweavers.org/tex2img.php?eq=sum%5Bn%5D%5Bm%5D%20%3D%20%5Csum_%7Bi%3D0%7D%5E%7Bn%7D%20grid%5Bi%5D%5Bm%5D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)

which denotes the column summation

Third, enumerate each up and down boundary and calculate the correspondent column summation for each column as an array, similar to **Approach 2** but instead of finding the **maximum sub array** with length at most **N**, we find the **maximum sub array** and the **minimum sub array** which represents two cases. The **maximum sub array** indicates the case without cyclic. The other cyclic case can be calculated by the **total summation of the array** minus the **minimum sub array**. Then we choose the larger one as a better solution.

### Time complexity
### O(N^3) 

Although **Approach 2 and 3** shares the same time complexity, **Approach 3** is faster since it reduces the gird into half.
