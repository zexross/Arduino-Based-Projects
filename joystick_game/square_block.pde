class Block{
  float []x = {0,50,100,150,200,250,300,350,400,450,500};
  float []y = {0,20,40,60,80,100,120,140,160,180,200};
  
 Block(){
   void drawBlock(){
     
   for(int i = 0; i<10; i++){
     rect(x[i],y[i],25,10);
   }