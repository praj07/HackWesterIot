
Intersection[]gridLayout = new Intersection[50000]; 
Road [] roadLayout = new Road [50000];
int x = 0;
//int y = 0;
int min;
int DisPos;
int EmerPos;
int nodeWidth = 20;
int nodeLength = 15;


void setup() {
  size(1280, 720);
  background (0);
  // interA = new Intersection(width/2,height/2, true);
  //interB = new Intersection(width/2+ 100,height/2, true);
  //Oxford = new Road(interA, interB);

  int gridX = width/nodeWidth;
  int gridY = height/nodeLength; 
  for (int i = 40; i < height; i += gridY) {
    for (int j = 40; j < width; j += gridX) {
      //  if (random(1) > 0.2) 
      {
        gridLayout[x] = new Intersection( j, i, (random(1)> 0.5), int(random(2, 10))); // Intersection (xPos, yPos ,is it Traffic signal, cost) 
        x++;
      }
    }
  }
  int randomizerD = int(random(x/3)); //randomizing dispatch location
  int randomizerE = int(random(x-15, x)); //randomizing emergency location
  /* do {
   randomizerE = int(random(2*x/3));
   } while (randomizerE == randomizerD); */  // makes sure emergency location and dispatch location are not the same 

  for (int c = 0; c<x; c++) { 
    if (randomizerD == c) { // finds location of dispatch and sets value to zero
      gridLayout[c].setDispatch();
      gridLayout[c].cost = 0;
      DisPos= c;
    }
    if (randomizerE == c) { //finds location of dispatch and sets value to one (which is gonna be min cuz everything else is 2-10)
      gridLayout[c].setEmergency();
      gridLayout[c].cost = 1; 
      EmerPos =c;
    }
  }
}
//}

void draw() {
  for (int a = 0; a < x; a++) {
    gridLayout[a].show();
  }

  int [] posGraph = Dijkstra();
  for (int v = 0; v <  -1; v++) {
    roadLayout[v] = new Road(gridLayout[posGraph[v]], gridLayout[posGraph[v+1]]);
    roadLayout[v].show();
  }
}


int [] Dijkstra () {
  int pos = 1;
  int nodeLoc = DisPos;
  int zeroNode = DisPos;
  int[] path = new int[nodeWidth*nodeLength];
  path[0] = DisPos;
  int size = nodeWidth*nodeLength; 

  while (zeroNode != EmerPos) {
    min = 999;
    if ((zeroNode-1)>0) {
      if (gridLayout[zeroNode-1].cost<min && gridLayout[zeroNode-1].visited==false && ((zeroNode+21) %21) == 0) {
        min = gridLayout[zeroNode-1].cost;
        nodeLoc = zeroNode-1;
      }
    }
    if ( (zeroNode-nodeWidth)> 0) {
      if (gridLayout[zeroNode-nodeWidth].cost<min  && gridLayout[zeroNode-nodeWidth].visited==false && ((zeroNode+21) %21) == 0) {
        min = gridLayout[zeroNode-nodeWidth].cost;
        nodeLoc = zeroNode+1;
      }
    }
    if ((zeroNode+1)< size) {
      if (gridLayout[zeroNode+1].cost<min && gridLayout[zeroNode+1].visited==false && zeroNode %20 == 0) {
        min = gridLayout[zeroNode+1].cost;
        nodeLoc = zeroNode+1;
      }
    }
    if ((zeroNode+nodeWidth)< size) {
      if (gridLayout[zeroNode+nodeWidth].cost<min && gridLayout[zeroNode+nodeWidth].visited==false && zeroNode%20 == 0) {
        min = gridLayout[zeroNode+nodeWidth].cost;
        nodeLoc = zeroNode+nodeWidth;
      }
    }
      gridLayout[nodeLoc].visited=true;
      path[pos] = nodeLoc;
      zeroNode = nodeLoc;
      pos++;
  }

  return path;
}