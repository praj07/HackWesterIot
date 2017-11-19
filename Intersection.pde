class Intersection {

  PVector a;  
  int cost; 
  boolean isTrafficLight;
  boolean isDispatch = false;
  boolean isEmergency = false;
  boolean visited = false;


  Intersection(int adx, int ady, boolean traffic, int _cost) {
    a = new PVector(adx, ady);
    isTrafficLight = traffic;
    cost = _cost;
  }

  void show() {
    if (isDispatch) {
      colorMode(RGB, 100);
      stroke(0, 0, 255); // blue is dispatch
    } else if (isEmergency) {
      colorMode(RGB, 100);
      stroke(255, 0, 0); //red is emergecny
    } else if (isTrafficLight) {
      colorMode(RGB, 100);
      stroke(0, 204, 0); //
    } else {
      stroke(100);
    }
    strokeWeight(10);
    ellipse(a.x, a.y, 4, 4);
    textSize(15);
    text(cost, a.x -10, a.y -10);
  }

  void setDispatch() {
    isDispatch = true;
  }

  void setEmergency() {
    isEmergency = true;
  }
}