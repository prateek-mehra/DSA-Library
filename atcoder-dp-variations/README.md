##### Identification
* Choice- Recursion -> DP
* Optimal Substructure- Min,Max,Largest etc

Creating a **choice diagram** helps in coding the recursive function which consists of base condition and the choice diagram part.

For efficiently finding **base conditions**, focus on extremities of inputs.

* When it's possible to choose an object, we either choose it or neglect it based on the optimalness.
* When it's not possible to choose the object, we neglect it and shift our focus towards remaining object and eventually reach base condition.

This means, in the recursive memoization approach, we're doing a process for all types of substructures only once, then we're using  previous results.

For example, for ***knapsack problem***, we start with the last object:
* If it's weight is less than or equal to the weight of the knapsack, we either include it or neglect it based on the optimalness.
* If it's weight is greater than the weight of the knapsack, we neglect it and focus on remaining n-1 objects and eventually reach base consition. On the way we keep storing results in a DP and use them starting from the second recursive call possibly.

Memoization technique can lead to StackOverflow error if the too many recursive calls lead to filling of function stack.
