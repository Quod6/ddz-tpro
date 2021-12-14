#include "Lib.h"
class Bot {
public:
  Bot();
  void run();
  void move_to(int inx);
  void lclick_to(int inx);
  void rclick_to(int inx);
  void drag(int from_inx,int to_inx);
  POINT point[points_cnt];
};
