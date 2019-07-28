# LedMatrixControl
Controller for a led matrix with shift register

Componets used: 2x 8 bit shiftregister 74hc595
                8 220kΩ resistors
                1 Led Matrix 8x8
                1 Arduino Mega 2560 for prototyping
                A bunch of jumper wires
                1 Breadboard also for prototyping
                
MatrixController class: The constructor needs the 4 pins of each shift register. You can find the pins in the datasheet of the
                        74hc595 shiftregister.
                        The init() function initializes the 8 pins and puts it in the right state. Just init it in the setup function 
                        of Arduino.
                        The setLed() function needs a x and y position and the state of the led.
                        The updateAll() function updates all bits that are safed in the shift register.
                        The clearAll() function sets all pins of the register to 0.
                        
After prototyping I'll design a pcb board and solder the componetns on the board.                        
