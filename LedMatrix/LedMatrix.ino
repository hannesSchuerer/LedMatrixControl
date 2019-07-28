#include "MatrixController.hpp"

MatrixController matrixController(2, 3, 4, 5, 6, 7, 8, 9, 8, 8);

void setup() {
  matrixController.init();
}

void loop() {
  
  matrixController.setLed(3, 4, true);
  matrixController.setLed(3, 6, true);

}
