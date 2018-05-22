This is a solution to [this codeforces problem](http://codeforces.com/contest/340/problem/D). <br/>
Basically, it talks about a 'Bubble sort graph' - a graph where the vertices are the elements of an array _a_,<br/>
and there's an edge betweeen two elements a<sub>i</sub> and a<sub>j</sub> 
if while bubble sorting the array the two elements a<sub>i</sub> and a<sub>j</sub> are swapped.

Our task is to find the _maximum independent set_ of vertices of this graph.

---

At first glance, the problem seems complicated, but once you make a few observations, the problem boils down to 
just finding the **Longest increasing subsequence** of the given array. We need to find LIS in nlogn time because 
n is of the order 10<sup>5</sup>.


### The observations

<img src="bubblesortgraph/editorial.jpg" />
