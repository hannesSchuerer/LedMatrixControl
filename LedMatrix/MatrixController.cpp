#include "MatrixController.hpp"

MatrixController::MatrixController(int dataInputP, int updateP, int shiftP, int clearP, int dataInputN, int updateN, int shiftN, int clearN)
{ 
  dataInputPositive = dataInputP;
  updatePositive = updateP;
  shiftPositive = shiftP;
  clearPositive = clearP;
  dataInputNegative = dataInputN;
  updateNegative = updateN;
  shiftNegative = shiftN;
  clearNegative = clearN;
}

void MatrixController::init()
{
  pinMode(dataInputPositive, OUTPUT);
  pinMode(updatePositive, OUTPUT);
  pinMode(shiftPositive, OUTPUT);
  pinMode(clearPositive, OUTPUT);
  
  pinMode(dataInputNegative, OUTPUT);
  pinMode(updateNegative, OUTPUT);
  pinMode(shiftNegative, OUTPUT);
  pinMode(clearNegative, OUTPUT);

  digitalWrite(shiftPositive, LOW);
  digitalWrite(shiftNegative, LOW);

  digitalWrite(updatePositive, LOW);
  digitalWrite(updateNegative, LOW);

  digitalWrite(clearPositive, HIGH);
  digitalWrite(clearNegative, HIGH);
}

void MatrixController::setLed(int x, int y, bool state)
{
  for(int i = 0; i < 8; i++)
  {
    if(i==x)
    {
      inputPositive(state);
      shiftDataPositive();
    }
    else
    {
      inputPositive(!state);
      shiftDataPositive();
    }
  }
  for(int i = 0; i < 8; i++)
  {
    if(i==y)
    {
      inputNegative(!state);
      shiftDataNegative();
    }
    else
    {
      inputNegative(state);
      shiftDataNegative();
    }
  }
  updateAll();
}

void MatrixController::inputPositive(int binary)
{
  if(binary)
  {
    digitalWrite(dataInputPositive, HIGH);
  }
  else
  {
    digitalWrite(dataInputPositive, LOW);
  }
}

void MatrixController::inputNegative(int binary)
{
  if(binary)
  {
    digitalWrite(dataInputNegative, HIGH);
  }
  else
  {
    digitalWrite(dataInputNegative, LOW);
  }
}

void MatrixController::shiftDataPositive()
{
  digitalWrite(shiftPositive, HIGH);
  digitalWrite(shiftPositive, LOW);
}

void MatrixController::shiftDataNegative()
{
  digitalWrite(shiftNegative, HIGH);
  digitalWrite(shiftNegative, LOW);
}

void MatrixController::updateAll()
{
  digitalWrite(updatePositive, HIGH);
  digitalWrite(updateNegative, HIGH);
  digitalWrite(updatePositive, LOW);
  digitalWrite(updateNegative, LOW);
}

void MatrixController::clearAll()
{
  digitalWrite(clearPositive, LOW);
  digitalWrite(clearNegative, LOW);
  digitalWrite(clearPositive, HIGH);
  digitalWrite(clearNegative, HIGH);
  updateAll();
}
