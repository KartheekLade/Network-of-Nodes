# Network-of-Nodes
Custom CHV CTF car
------------------------------------------



---------
## You will need:

## Hardware 
* Arduuino ( Nano / Uno / Mega ).
* MCP2515.
* OBD-II Jack.
* Power bank for powering Arduino's.
* Toy car .
## Software 
* Arduino IDE.

You can get Arduino IDE software from the official [page](https://www.arduino.cc/en/software). 

Steps to setup the car
----------------------------------
1) Flash the code into the arduino's (Depends upon how many nodes you like to setup).
2) Connect the jumper wires according to the layout provided in the repository.
3) Setup a common port for debugging purposes (you can put a common pins on bread board and connect with a OBD-II Jack)

#
Make sure you have all the libraries installed and The hardcoded arbitration ID's in the .ino files can be changed and you can create multiple carnodes according to usage. same code with changes in id and functions needs to be done. 
#
Usage
-----
- Can be used to conduct CTF's and use as a test bed in trainings.

Troubleshooting
---------------
* If you get an error / random dumps then problem might be with pins aren't properly installed and in the board. (Soldering them is recomended for heavy use)
* If the arduino does not seem to be responding commands try reflashing or change the RX pin in code and hardware.
* if the electronic components of toy car isnt working then try checking the power at jumper pin ends to ensure the required voltage for motors.(if you can use a relay module to regulate power).
