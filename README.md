# Response Abil-IoT

##Intro 
In times of emergency, vehicles are dispatched to a specific location but will lose an average of 4-7 minutes in their response time, simply from having to stop at intersections and making sure there are no vehicles coming from all other directions. As well, accidents involving an emergency response vehicle is a very common and substantial issues.

**Response Abil-IoT** is a system that works to improve emergency vehicle response time and decrease associated risks by optimizing routes and traffic signals, to make the city a safer place. It takes into consideration the following elements: 
+ location of emergency 
+ best route to emergency 
+ external factors on roads

##Build & Run
There are 3 different aspects of this project; the route finding algorithm, the route simulation, and the arduino which simulates the system respnses in actual traffic intersection scenarios. 

For the route finding algorithm, the following steps will be for **all users**:

1) Run "dijkstra.c" in an c-compatible IDE of your choice
2) Enter the value for "number of vertices," which will be the side length of the generated road map matrix
3) Enter the values of the adjacency matrix, assigning specific variables for cost associated with the node, keeping in mind that it's cost with itself and nodes not adjacent will be zero 
4) Enter the starting node (this is typically zero for testing sake) 

After following these steps, the shortest (least cost) path, will be displayed to you. 

For the route simulation, complete the following steps for **all users**:

1) 

##Collaborators 
> Paavan Raj
> Tushar Mahajan
> Annie Wu
