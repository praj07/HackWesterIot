
//Node inter; 
int rows = 11;
int cols = 20;
int []disPos = {1, 2};
int []emerPos = {8, 9};
Node [][]grid = new Node[rows][cols];
int x = 0, y = 0;

void setup() {
  size(1500, 720);
  background (0);
  int gridX = width/cols;
  int gridY = height/rows;

  for ( int i =0; i< rows; i ++) {
    for (int j = 0; j < cols; j ++) {
      //if (random(1) >0.7) {
      grid[i][j] = new Node(i*gridX+40, j*gridY+40, (random(1) > 0.5));
      //}
    }
  }
  grid[1][2].isDispatch=true;
  grid[8][9].isEmergency = true;
  for ( int i =0; i< rows; i ++) {
    for (int j = 0; j < cols; j ++) {
      if (i == 0) { //top row
        if (j == 0) {            // Up    Right         Down         Left
          grid[i][j].setAdjacents(null, grid[i][j+1], grid[i+1][j], null);
        } else if (j == cols -1) {
          grid[i][j].setAdjacents(null, null, grid[i+1][j], grid[i][j-1]);
        } else {
          grid[i][j].setAdjacents(null, grid[i][j+1], grid[i+1][j], grid[i][j-1]);
        }
      }
      if (i==rows-1) { //bottom row
        if (j == 0) {
          grid[i][j].setAdjacents(grid[i-1][j], grid[i][j+1], null, null);
        } else if (j == cols-1) {
          grid[i][j].setAdjacents(grid[i-1][j], null, null, grid[i][j-1]);
        } else {
          grid[i][j].setAdjacents(grid[i-1][j], grid[i][j+1], null, grid[i][j-1]);
        }
      }
      if (j == 0) { //left
        if (i == 0) {
          grid[i][j].setAdjacents(null, grid[i][j+1], grid[i+1][j], null);
        } else if (i == rows-1) {
          grid[i][j].setAdjacents(grid[i-1][j], grid[i][j+1], null, null);
        } else {
          grid[i][j].setAdjacents(grid[i-1][j], grid[i][j+1], grid[i+1][j], null);
        }
      }
      if (j==cols-1) { //right
        if (i ==0) {
          grid[i][j].setAdjacents(null, null, grid[i+1][j], grid[i][j-1]);
        } else if (i == rows-1) {
          grid[i][j].setAdjacents(grid[i-1][j], null, null, grid[i][j-1]);
        } else {
          grid[i][j].setAdjacents(grid[i-1][j], null, grid[i+1][j], grid[i][j-1]);
        }
      }
    }
  }
}

void draw() {
  //inter.show();
  for ( int i =0; i< rows; i ++) {
    for (int j = 0; j < cols; j ++) {
      grid[i][j].show();
    }
  }
  Node [] current = Djikstra();
  for (int k =0; k<current.length; k++) {
    strokeWeight(4);
    line(current[k].location.x, current[k].location.y, current[k+1].location.x, current[k+1].location.x);
    //current = current.child;
  }
}


Node [] Djikstra() {
  Node zeroNode = grid[disPos[0]][disPos[1]];
  Node []path = new Node[10000]; 
  int pathPos = 0;
  /*Node current = zeroNode;
   
   while (current != grid[emerPos[0]][emerPos[1]]) {
   current.child = current.checkAdjacents();
   current = current.child;
   if(current == grid[emerPos[0]][emerPos[1]]){
   current.child = null;
   }
   }*/

  while (zeroNode!= grid[emerPos[0]][emerPos[1]]) {
   // zeroNode.visited =true;
    zeroNode = zeroNode.checkAdjacents();
    path[pathPos] = zeroNode;
    pathPos++;
  }

  return path;
}