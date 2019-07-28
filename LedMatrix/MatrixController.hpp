#include "Arduino.h"

class MatrixController
{
  private:
    int dataInputPositive;
    int updatePositive;
    int shiftPositive;
    int clearPositive;

    int dataInputNegative;
    int updateNegative;
    int shiftNegative;
    int clearNegative;
    
  public:
    MatrixController(int dataInputP, int updateP, int shiftP, int clearP, int dataInputN, int updateN, int shiftN, int clearN);
    void setLed(int x, int y, bool state);
    void inputPositive(int binary);
    void inputNegative(int binary);
    void shiftDataPositive();
    void shiftDataNegative();
    void updateAll();
    void clearAll();
    void init();
};
