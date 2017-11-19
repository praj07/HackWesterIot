class Road {
  float len;
  PVector a;
  PVector b;
   
   Road (Intersection c, Intersection d){
     a = c.a.copy();
     b = d.a.copy();  
     
   }
   
   void show(){
   strokeWeight(4);
   stroke(50,50,50);
   line(a.x,a.y,b.x,b.y); 
   }


}