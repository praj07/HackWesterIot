# Response Abil-IoT: An Emergency Vehicle Protocol

## Intro 
In times of emergency, vehicles are dispatched to a specific location but will lose an average of 4-7 minutes in their response time, simply from having to stop at intersections and making sure there are no vehicles coming from all other directions. As well, accidents involving an emergency response vehicle is a very common and substantial issues.

**Response Abil-IoT** is a system that works to improve emergency vehicle response time and decrease associated risks by optimizing routes and traffic signals, to make the city a safer place. It takes into consideration the following elements: 
+ location of emergency 
+ best route to emergency 
+ external factors on roads

## Build & Run
There are 3 different aspects of this project; the route finding algorithm, the route simulation, and the arduino which simulates the system respnses in actual traffic intersection scenarios. 

For the **route finding algorithm**, the following steps will be for **all users**:

1) Run "dijkstra.c" in an c-compatible IDE of your choice
2) Enter the value for "number of vertices," which will be the side length of the generated road map matrix
3) Enter the values of the adjacency matrix, assigning specific variables for cost associated with the node, keeping in mind that it's cost with itself and nodes not adjacent will be zero 
4) Enter the starting node (this is typically zero for testing sake) 

After following these steps, the shortest (least cost) path, will be displayed to you. 

For the **route simulation**, complete the following steps for **all users**:

1) Download Processive 3.3.6 (https://github.com/processing/processing/releases/tag/processing-0263-3.3.6)
2) Open "FireStationPath.pde" and "Firetruck.pde" in one Processing window
3) Run the pre-defined simulation

This is only for simulation purposes and shows how paths are chosen and changed based on external factors. 

In terms of the **Arduino simulation**, the following steps will be for **all users**: 

1) Download Arduino (https://github.com/arduino/Arduino)
2) Complete the wiring on a Arduino development board with an ATmega328P microcontroller, 12 digital I/O pins, an analog I/O pin, and a switch
3) Ensure the board is connected to your laptop, and the port is correctly set
4) In the Arduino code, you are able to change which direction the emergency vehicle is coming from. This is automatically set to "bottom" but can also be "left," "right," or "top"
5) Upload the "" file to the board
6) The regular traffic light system will run on the board. To simulate the emergency vehicle scenario, flip the switch and observe the changes
7) The switch can be flipped again to return the traffic light system to normal after the vehicle has passed

## Application
In a city, this implementation would need to be widely scaled according to size of the population. The most effective way to monitor the system would be to have it centralized to one hub, that controls all the decision making processes. The three previously discussed elements would need to be integrated with one another to create a system that is able to generate a map based on the location of the emergency and the nearest dispatch station, implement the algorithm to find the best path, and then change the traffic lights on the intersections on this best route, which will be timed based on estimated time of arrivals. 

## Collaborators 
> Paavan Raj

> Tushar Mahajan

> Annie Wu
