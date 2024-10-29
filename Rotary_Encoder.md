

#  How Rotary Encoder Works and How To Use It with Arduino

[LINK](https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/)


[CODE]()






How it Works





left to right

### for CCW

[1_GND]           <------>  [ard_GND]
[2_VCC]           <------>  [ard_5V]
[3_Button_pin]    <------>  [---]
[4_DT][OUTPUT_B]  <------>  [ard_pin_6]
[5_CLK][OUTPUT_A] <------>  [ard_pin_7]


**or** 


### for CW

[4_DT][OUTPUT_B]  <------>  [ard_pin_7]
[5_CLK][OUTPUT_A] <------>  [ard_pin_6]


**source**

```
/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define outputA 6
 #define outputB 7

 int counter = 0; 
 int aState;
 int aLastState;  

 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 

 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
```
