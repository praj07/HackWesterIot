class Firetruck { 

  
  PVector velocity;
  PVector position;

  Firetruck(int _w, int _x, int _y, int _z) {
    position = new PVector(_w, _x);
    int dx = _w - _y;
    int dy = _x - _z;
    float theta = atan2(dy, dx);
   // System.out.println(theta);
    velocity = PVector.fromAngle(theta);
    velocity.setMag(-1);
  }

  void setVel(int _w, int _x, int _y, int _z) {
    int dx = _w - _y;
    int dy = _x - _z;
    float theta = atan2(dy, dx);
    velocity = PVector.fromAngle(theta);
    velocity.setMag(-1);
  }

  void stop() {
  }

  void update () {
    position = position.add(velocity);
  }

  void show(PImage FireEngine) {
    image(FireEngine, int(position.x) -37, int(position.y) -37, 75, 75);
  }
}