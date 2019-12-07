class  obstacle{
  float y;
  y = random(2,7);
  public:
    void drawOobstacle(){
      for(int x_motion = display.width();x_motion>=0; x_motion= x_motion-50)
      display.drawLine(x_motion,display.height()-6,x_motion,display.height()-6-y,WHITE);
    }
};
