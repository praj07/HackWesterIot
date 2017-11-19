class Node {

  PVector location; 
  int cost = int (random(2, 10));
  Node [] adjacents = new Node[4]; // 0 = up, 1 = right, 2 = down, 3 = left
  float [] distances = new float [4];  // 0 = up distance, 1 = right distance, 2 = down distance, 3 = left distance
  boolean isTrafficLight;
  boolean isDispatch = false;
  boolean isEmergency = false;
  boolean visited = false;
  Node child = null;

  Node(int _x, int _y, boolean traffic) {
    location = new PVector(_x, _y);
    isTrafficLight = traffic;
  }

  void setAdjacents (Node up, Node right, Node down, Node left) {
    adjacents[0] = up;
    adjacents[1] = right;
    adjacents[2] = down;
    adjacents[3] = left;

    for (int i =0; i < adjacents.length; i++) {
      if (adjacents[i]!=null) {
        distances[i] = location.dist(adjacents[i].location);
      }
    }
  }

  Node checkAdjacents () {
    int min = 11;
    Node minNode = null;
    int found=0; 
    //Node []path = new Node[10000]; 


    for (int i=0; i< adjacents.length; i++) {
      if (adjacents[i]!= null) {
        if (adjacents[i].cost<min) {
          if (!adjacents[i].visited) {
            //System.out.println(found);
            //min = adjacents[i].cost;
            minNode = adjacents[i];
            //found = i;
          }
        }
      }
    }

   // adjacents[found].visited = true; 

    return minNode;
  }



  void show() {
    if (isDispatch) {
      colorMode(RGB, 100);
      stroke(0, 0, 255); // blue is dispatch
      cost = 0;
    } else if (isEmergency) {
      colorMode(RGB, 100);
      stroke(255, 0, 0); //red is emergecny
      cost = -1;
    } else if (isTrafficLight) {
      colorMode(RGB, 100);
      stroke(0, 204, 0); //traffic lights are green
    } else {
      stroke(100);
    }
    strokeWeight(10);
    ellipse(location.x, location.y, 4, 4);
    textSize(15);
    text(cost, location.x -10, location.y -10);
  }
}