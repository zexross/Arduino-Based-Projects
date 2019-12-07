class ball{
    float x =7;
    float y = display.height()-13
    int i;
  public:
  void drawball(){
   for(i=0; i<=5; i++){
  display.drawCircle(x,y,i,WHITE);
  }
  }
  void jumpball(){
   for(i=0; i<=5; i++){
  display.drawCircle(x,y-2*i,i,WHITE);
  } 
};
