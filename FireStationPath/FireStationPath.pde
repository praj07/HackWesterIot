PImage bg;
PImage fire;
PImage crash;
PImage FireEngine;
PVector [] intersectionsA = new PVector [9];
PVector [] intersectionsB = new PVector[13];
int c = 0;
float clock =0;
float prevTime = 0;
boolean runtwodelay = true;
boolean runthreedelay = true;
boolean first = true;
boolean north = true;
boolean runtwo = false;
boolean runthree = false;
Firetruck truck = new Firetruck(831, 540, 683, 145);
Firetruck trucktwo = new Firetruck(831, 540, 683, 145);
Firetruck truckthree = new Firetruck(831, 540, 683, 145);

void setup() {
  size(1291, 811);
  bg = loadImage("FireStation.JPG");
  fire = loadImage("Fire.png");
  crash = loadImage("crash icon.png");
  FireEngine = loadImage("Firetruck.png");
}

void draw() {
  image(bg, 0, 0);
  image(fire, 216 -37, 326 -30, 75, 60);

  // System.out.println(mouseX + " , " + mouseY);

  colorMode(RGB);
  strokeWeight(5);
  stroke(137, 200, 237);
  line (831, 540, 683, 145);
  line (683, 145, 216, 326);
  //image(crash, 754-30, 342-30, 75, 75);
  //stroke(#EC1826);
  //line (831, 540, 763, 364);


  stroke(#23468B);
  intersectionsA[0] = new PVector(781, 408);
  intersectionsA[1] = new PVector(731, 274);
  intersectionsA[2] = new PVector(683, 146);
  intersectionsA[3] = new PVector(554, 195); 
  intersectionsA[4] = new PVector(488, 221);
  intersectionsA[5] = new PVector(423, 246);
  intersectionsA[6] = new PVector(321, 285);
  intersectionsA[7] = new PVector(289, 298);
  intersectionsA[8] = new PVector(0, 0);


  //stroke(#41AF26);
  intersectionsB[0] = new PVector(703, 438);
  intersectionsB[1] = new PVector(651, 456);
  intersectionsB[2] = new PVector(587, 483);
  intersectionsB[3] = new PVector(519, 509); 
  intersectionsB[4] = new PVector(417, 544);
  intersectionsB[5] = new PVector(386, 557);
  intersectionsB[6] = new PVector(319, 583);
  intersectionsB[7] = new PVector(292, 514);
  intersectionsB[8] = new PVector(268, 454);
  intersectionsB[9] = new PVector(244, 391); 
  intersectionsB[10] = new PVector(0, 0);




  for ( int i = 0; i< intersectionsA.length-1; i++) {
    ellipse(intersectionsA[i].x, intersectionsA[i].y, 7, 7);
  }



  /*stroke(#41AF26);
   line (831, 540, 781, 409);
   line (781, 409, 318, 585);
   line( 318, 585, 216, 326);
   
   stroke(#1C3F13);
   ellipse(703, 438, 7, 7);
   ellipse(651, 456, 7, 7);
   ellipse(587, 483, 7, 7);
   ellipse(519, 509, 7, 7);
   ellipse(417, 544, 7, 7);
   ellipse(386, 557, 7, 7);
   ellipse(319, 583, 7, 7);
   ellipse(292, 514, 7, 7);
   ellipse(268, 454, 7, 7);
   ellipse(244, 391, 7, 7);*/
  //System.out.println(int(truck.position.x) + " , " + int(truck.position.y) + " , " + (truck.velocity));

  if (int(truck.position.x) == intersectionsA[c].x && int(truck.position.y) == intersectionsA[c].y) {
    if (first) {
      prevTime = clock = millis();
      first = false;
      truck.velocity.setMag(0);
    }


    if (clock - prevTime > 2000) {
      if (north) {
        truck.setVel(831, 540, 683, 145);
      } else {
        truck.setVel(683, 145, 216, 326);
      }
      first = true;
      c++;
    }
    clock = millis();
  }
  if (int(truck.position.x) == 683 && int(truck.position.y) == 145) {
    truck.setVel(683, 145, 216, 326);
    north = false;
  }
  if (int(truck.position.x) == 216 && int(truck.position.y) == 326) {
    truck.velocity.setMag(0);
    runtwo = true;
  }

  truck.update();
  truck.show(FireEngine);

  if (runtwo) {
    if (runtwodelay) {
      prevTime = clock = millis();
      runtwodelay = false;
    }
    if (clock - prevTime > 3000) {
      image(crash, 754-30, 342-30, 75, 75);
      stroke(#EC1826);
      line (831, 540, 763, 364);
      if (int(trucktwo.position.x) == 769 && int(trucktwo.position.y) == 377) {
        trucktwo.velocity.setMag(0);
        runthree = true;
        north = true;
      }

      trucktwo.update();
      trucktwo.show(FireEngine);
    }
    clock =millis();
  }

  if (runthree) {
    if (runtwodelay) {
      prevTime = clock = millis();
      runtwodelay = false;
    }
    if (clock - prevTime > 3000) {
      for ( int i = 0; i< intersectionsB.length-2; i++) {
        ellipse(intersectionsB[i].x, intersectionsB[i].y, 7, 7);
      }
      stroke(#41AF26);
      line (831, 540, 781, 409);
      line (781, 409, 318, 585);
      line( 318, 585, 216, 326);
      stroke(#1C3F13);
      for ( int i = 0; i< intersectionsB.length-2; i++) {
        ellipse(intersectionsB[i].x, intersectionsB[i].y, 7, 7);
      }

      if (int(truckthree.position.x) == 781 && int(truckthree.position.y) == 408) {
        truckthree.setVel(781, 408, 386, 557);
      }
      if (int(truckthree.position.x) == 319 && int(truckthree.position.y) == 583) {
        truckthree.setVel(319, 583, 216, 326);
      }
      if (int(truckthree.position.x) == 216 && int(truckthree.position.y) == 326) {
        truckthree.velocity.setMag(0);
      }
      
      System.out.println(int(truckthree.position.x) + " , " + int(truckthree.position.y) + " , " + (truckthree.velocity));
      truckthree.update();
      truckthree.show(FireEngine);
    }

    clock = millis();
  }


  //stroke(
}