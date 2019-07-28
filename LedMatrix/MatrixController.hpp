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

    int matrixSizeX;
    int matrixSizeY;
    
    void inputPositive(int binary);
    void inputNegative(int binary);
    void shiftDataPositive();
    void shiftDataNegative();
    
  public:
    MatrixController(int dataInputP, int updateP, int shiftP, int clearP, int dataInputN, int updateN, int shiftN, int clearN, int x, int y);
    void setLed(int x, int y, bool state);
    void updateAll();
    void clearAll();
    void init();
};
