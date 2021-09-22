#### Working of the algorithm in my words:

* Convert any problem to its graph equivalent representation.
* Maintain a list of unvisited vertices. Assign a vertex as “source” and also allocate a maximum possible cost (infinity) to every other vertex. The cost of the source to itself will be zero as it actually takes nothing to go to itself.
* In every step of the algorithm, it tries to minimize the cost for each vertex.
* For every unvisited neighbor (V2, V3) of the current vertex (V1) calculate the new cost from V1.
* The new cost of V2 is calculated as :
* Minimum( existing cost of V2 , (sum of cost of V1 + the cost of edge from V1 to V2) )
* When all the neighbors of the current node are visited and cost has been calculated, mark the current node V1 as visited and remove it from the unvisited list.
* Select next vertex with smallest cost from the unvisited list and repeat from step 4.
* The algorithm finally ends when there are no unvisited nodes left.

##### Uses:

* It is most widely used in finding shortest possible distance and show directions between 2 geographical locations such as in Google Maps.
* This is also widely used in routing of data in networking and telecommunication domains for minimizing the delay occurred for transmission.
* Wherever you encounter the need for shortest path solutions be it in robotics, transportation, embedded systems, factory or production plants to detect faults, etc this algorithm is used.
