#include <Adafruit_NeoPixel.h>
#include <NeoPixelPainter.h>

#define RING0_PIN  51
#define RING1_PIN  49
#define RING2_PIN  47
#define RING3_PIN  45
#define RING4_PIN  43
#define RING5_PIN  41
#define RING6_PIN  39
#define RING7_PIN  37
#define RING8_PIN  35
#define RING9_PIN  33

#define RING0_LENGTH  12
#define RING1_LENGTH  22
#define RING2_LENGTH  35
#define RING3_LENGTH  51 
#define RING4_LENGTH  64
#define RING5_LENGTH  61 
#define RING6_LENGTH  72
#define RING7_LENGTH  84 
#define RING8_LENGTH  94
#define RING9_LENGTH  15

// Called rings, but actually strips. 
Adafruit_NeoPixel ring0 = Adafruit_NeoPixel(RING0_LENGTH, RING0_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(RING1_LENGTH, RING1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring2 = Adafruit_NeoPixel(RING2_LENGTH, RING2_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring3 = Adafruit_NeoPixel(RING3_LENGTH, RING3_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring4 = Adafruit_NeoPixel(RING4_LENGTH, RING4_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring5 = Adafruit_NeoPixel(RING5_LENGTH, RING5_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring6 = Adafruit_NeoPixel(RING6_LENGTH, RING6_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring7 = Adafruit_NeoPixel(RING7_LENGTH, RING7_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring8 = Adafruit_NeoPixel(RING8_LENGTH, RING8_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring9 = Adafruit_NeoPixel(RING9_LENGTH, RING9_PIN, NEO_GRB + NEO_KHZ800);

//create canvas, linked to the neopixels (must be created before the brush)
NeoPixelPainterCanvas ring0Canvas = NeoPixelPainterCanvas(&ring0);    
NeoPixelPainterCanvas ring1Canvas = NeoPixelPainterCanvas(&ring1);   
NeoPixelPainterCanvas ring2Canvas = NeoPixelPainterCanvas(&ring2);   
NeoPixelPainterCanvas ring3Canvas = NeoPixelPainterCanvas(&ring3);    
NeoPixelPainterCanvas ring4Canvas = NeoPixelPainterCanvas(&ring4);   
NeoPixelPainterCanvas ring5Canvas = NeoPixelPainterCanvas(&ring5);   
NeoPixelPainterCanvas ring6Canvas = NeoPixelPainterCanvas(&ring6);   
NeoPixelPainterCanvas ring7Canvas = NeoPixelPainterCanvas(&ring7);   
NeoPixelPainterCanvas ring8Canvas = NeoPixelPainterCanvas(&ring8);   
NeoPixelPainterCanvas ring9Canvas = NeoPixelPainterCanvas(&ring9);   

//create brushes, linked to the canvas
NeoPixelPainterBrush waveBrush0 = NeoPixelPainterBrush(&ring0Canvas);  
NeoPixelPainterBrush waveBrush1 = NeoPixelPainterBrush(&ring1Canvas); 
NeoPixelPainterBrush waveBrush2 = NeoPixelPainterBrush(&ring2Canvas); 
NeoPixelPainterBrush waveBrush3 = NeoPixelPainterBrush(&ring3Canvas);
NeoPixelPainterBrush waveBrush4 = NeoPixelPainterBrush(&ring4Canvas);  
NeoPixelPainterBrush waveBrush5 = NeoPixelPainterBrush(&ring5Canvas); 
NeoPixelPainterBrush waveBrush6 = NeoPixelPainterBrush(&ring6Canvas);
NeoPixelPainterBrush waveBrush7 = NeoPixelPainterBrush(&ring7Canvas);
NeoPixelPainterBrush waveBrush8 = NeoPixelPainterBrush(&ring8Canvas); 
NeoPixelPainterBrush waveBrush9 = NeoPixelPainterBrush(&ring9Canvas); 

// uint32_t cTurqs             = ring3.ColorHSV(160 * 182,  .96 * 255,  .62 * 255); /* Turks       : H:177 S:46  V:82 */
// uint32_t cPinkySwear        = ring3.ColorHSV(315 * 182, 1.00 * 255,  .80 * 255); /* Pinky Swear : H:315 S:100 V:100 */
// uint32_t cDarkTurqs         = ring3.ColorHSV(160 * 182, 1.00 * 255,  .27 * 255); /* Dark Turqs  : H:186 S:100 V:55 */
// uint32_t cPurps             = ring3.ColorHSV(265 * 182, 1.00 * 255,  .50 * 255); /* Purps       : H:251 S:65  V:44 */
// uint32_t cIntermediatePurps = ring3.ColorHSV(265 * 182, 1.00 * 255,  .25 * 255); /* Intermediate Purps  : H:288 S:88  V:72 */
// uint32_t cSeafoam           = ring3.ColorHSV(120 * 182,  .5 * 255,  .22 * 255); /* Seafoam     : H:145 S:37  V:92 */
// uint32_t cOffColor          = ring3.ColorHSV(0, 0,  0);

uint32_t cTurqsBackground = ring0.ColorHSV(29120,  250,  50);
uint32_t cPinkySwearBackground = ring0.ColorHSV(57000,  250,  50);

void setup() {
  randomSeed(analogRead(0)); //new random seed 
  // Serial.begin(115200);

  pinMode(RING0_PIN, OUTPUT);
  pinMode(RING1_PIN, OUTPUT);
  pinMode(RING2_PIN, OUTPUT);
  pinMode(RING3_PIN, OUTPUT);
  pinMode(RING4_PIN, OUTPUT);
  pinMode(RING5_PIN, OUTPUT);
  pinMode(RING6_PIN, OUTPUT);
  pinMode(RING7_PIN, OUTPUT);
  pinMode(RING8_PIN, OUTPUT);
  pinMode(RING9_PIN, OUTPUT);

int arr[7] = {25, 63, 74, 69, 81, 65, 68};
  
 for (int element: arr) {
    Serial.println(element);
 }

  ring0.begin();
  ring0.setBrightness(75);
  ring1.begin();
  ring1.setBrightness(75);
  ring2.begin();
  ring2.setBrightness(75);
  ring3.begin();
  ring3.setBrightness(75);
  ring4.begin();
  ring4.setBrightness(75);
  ring5.begin();
  ring5.setBrightness(75);
  ring6.begin();
  ring6.setBrightness(75);
  ring7.begin();
  ring7.setBrightness(75);
  ring8.begin();
  ring8.setBrightness(75);
  ring9.begin();
  ring9.setBrightness(75);

  Serial.println("few");

  //check if ram allocation of brushes and canvases was successful (painting will not work if unsuccessful, program should still run though)
  //this check is optional but helps to check if something does not work, especially on low ram chips like the Arduino Uno
  checkBrushesAndCanvases();

  HSV brushcolor;
  
  brushcolor.h = 90; // random(115, 135); //  
  brushcolor.s = 255; 
  brushcolor.v = 255; // most "intense" color
  
  int brushSpeed = 4096;
  int fadeSpeed = 255;
  bool shouldFadeOut = true;
  bool shouldFadeIn = true;


  waveBrush0.setSpeed(brushSpeed); 
  waveBrush0.setFadein(shouldFadeIn);
  waveBrush0.setFadeout(shouldFadeOut);
  waveBrush0.setFadeSpeed(fadeSpeed);
  waveBrush0.setColor(brushcolor);
  
  waveBrush1.setSpeed(brushSpeed); 
  waveBrush1.setFadein(shouldFadeIn);
  waveBrush1.setFadeout(shouldFadeOut);
  waveBrush1.setFadeSpeed(fadeSpeed);
  waveBrush1.setColor(brushcolor);
  
  waveBrush2.setSpeed(brushSpeed); 
  waveBrush2.setFadein(shouldFadeIn);
  waveBrush2.setFadeout(shouldFadeOut);
  waveBrush2.setFadeSpeed(fadeSpeed);
  waveBrush2.setColor(brushcolor);
  
  waveBrush3.setSpeed(brushSpeed); 
  waveBrush3.setFadein(shouldFadeIn);
  waveBrush3.setFadeout(shouldFadeOut);
  waveBrush3.setFadeSpeed(fadeSpeed);
  waveBrush3.setColor(brushcolor);
  
  waveBrush4.setSpeed(brushSpeed);
  waveBrush4.setFadein(shouldFadeIn);
  waveBrush4.setFadeout(shouldFadeOut); 
  waveBrush4.setFadeSpeed(fadeSpeed);
  // brushcolor.h = random(105,115);
  waveBrush4.setColor(brushcolor);

  waveBrush5.setSpeed(brushSpeed);
  waveBrush5.setFadein(shouldFadeIn);
  waveBrush5.setFadeout(shouldFadeOut); 
  waveBrush5.setFadeSpeed(fadeSpeed);
  // brushcolor.h = random(105,115);
  waveBrush5.setColor(brushcolor);
  
  waveBrush6.setSpeed(brushSpeed); 
  waveBrush6.setFadein(shouldFadeIn);
  waveBrush6.setFadeout(shouldFadeOut);
  waveBrush6.setFadeSpeed(fadeSpeed);
  // brushcolor.h = random(105,115);
  waveBrush6.setColor(brushcolor);
    
  waveBrush7.setSpeed(brushSpeed);
  waveBrush7.setFadein(shouldFadeIn);
  waveBrush7.setFadeout(shouldFadeOut); 
  waveBrush7.setFadeSpeed(fadeSpeed);
  brushcolor.h = 175;
  waveBrush7.setColor(brushcolor);
  
  waveBrush8.setSpeed(brushSpeed);
  waveBrush8.setFadein(shouldFadeIn);
  waveBrush8.setFadeout(shouldFadeOut); 
  waveBrush8.setFadeSpeed(fadeSpeed);
  brushcolor.h = 90;
  waveBrush8.setColor(brushcolor);

  waveBrush9.setSpeed(brushSpeed);
  waveBrush9.setFadein(shouldFadeIn);
  waveBrush9.setFadeout(shouldFadeOut); 
  waveBrush9.setFadeSpeed(fadeSpeed);
  // brushcolor.h = random(105,115);
  waveBrush9.setColor(brushcolor);  

}

void loop() {

  ring0.clear();
  ring1.clear();
  ring2.clear();
  ring3.clear();
  ring4.clear();
  ring5.clear();
  ring6.clear();
  ring7.clear();
  ring8.clear();
  ring9.clear();
  
  // setting base color each ring before painting waves
  int i;
  for (i = 0; i < RING0_LENGTH; i++) {
    ring0.setPixelColor(i, cTurqsBackground); 
  }

  for (i = 0; i < RING1_LENGTH; i++) {
    ring1.setPixelColor(i, cTurqsBackground); 
  }

  for (i = 0; i < RING2_LENGTH; i++) {
    ring2.setPixelColor(i, cTurqsBackground); 
  }  
  
  for (i = 0; i < RING3_LENGTH; i++) {
    ring3.setPixelColor(i, cTurqsBackground); 
  }

  for (i = 0; i < RING4_LENGTH; i++) {
    ring4.setPixelColor(i, cTurqsBackground); 
  }

  for (i = 0; i < RING5_LENGTH; i++) {
    ring5.setPixelColor(i, cTurqsBackground); 
  }
  
  for (i = 0; i < RING6_LENGTH; i++) {
    ring6.setPixelColor(i, cTurqsBackground); 
  }

  for (i = 0; i < RING7_LENGTH; i++) {
    ring7.setPixelColor(i, cPinkySwearBackground); 
  }
  
  for (i = 0; i < RING8_LENGTH; i++) {
    ring8.setPixelColor(i, cTurqsBackground); 
  }

  for (i = 0; i < RING9_LENGTH; i++) {
    ring9.setPixelColor(i, cTurqsBackground); 
  }

  //apply the paint of the first brush to the canvas (and update the brush)
  waveBrush0.paint();
  waveBrush1.paint();
  waveBrush2.paint();
  waveBrush3.paint();
  waveBrush4.paint();
  waveBrush5.paint();
  waveBrush6.paint();
  waveBrush7.paint();
  waveBrush8.paint();
  // waveBrush9.paint();  

  //transfer the canvas to the neopixels
  ring0Canvas.transfer(); 
  ring1Canvas.transfer(); 
  ring2Canvas.transfer(); 
  ring3Canvas.transfer(); 
  ring4Canvas.transfer(); 
  ring5Canvas.transfer(); 
  ring6Canvas.transfer(); 
  ring7Canvas.transfer(); 
  ring8Canvas.transfer(); 
  ring9Canvas.transfer(); 
  
  ring0.show();
  ring1.show();
  ring2.show();
  ring3.show();
  ring4.show();
  ring5.show();
  ring6.show();
  ring7.show();
  ring8.show();
  ring9.show();
}

void checkBrushesAndCanvases() {

  if (ring0Canvas.isvalid() == false) Serial.println("canvas allocation problem");
  else  Serial.println("ring 0 canvas allocation ok");
  
  if (ring1Canvas.isvalid() == false) Serial.println("canvas allocation problem");
  else  Serial.println("ring 1 canvas allocation ok");
  
  if (ring2Canvas.isvalid() == false) Serial.println("canvas allocation problem");
  else  Serial.println("ring 2 canvas allocation ok");

  if (ring3Canvas.isvalid() == false) Serial.println("canvas allocation problem");
  else  Serial.println("ring 3 canvas allocation ok");
  
  if (ring4Canvas.isvalid() == false) Serial.println("canvas 4 allocation problem");
  else  Serial.println("ring 4 canvas allocation ok");
  
  if (ring5Canvas.isvalid() == false) Serial.println("canvas 5 allocation problem");
  else  Serial.println("ring 5 canvas allocation ok");
  
  if (ring6Canvas.isvalid() == false) Serial.println("canvas 6 allocation problem");
  else  Serial.println("ring 6 canvas allocation ok");
  
  if (ring7Canvas.isvalid() == false) Serial.println("canvas 7 allocation problem");
  else  Serial.println("ring 7 canvas allocation ok");
  
  if (ring8Canvas.isvalid() == false) Serial.println("canvas 8 allocation problem");
  else  Serial.println("ring 8 canvas allocation ok");
  
  if (ring9Canvas.isvalid() == false) Serial.println("canvas 9 allocation problem");
  else  Serial.println("ring 9 canvas allocation ok");


  if (waveBrush0.isvalid() == false) Serial.println("brush 0 allocation problem");
  else  Serial.println("brush 0 allocation ok");
  
  if (waveBrush1.isvalid() == false) Serial.println("brush 1 allocation problem");
  else  Serial.println("brush 1 allocation ok");
  
  if (waveBrush2.isvalid() == false) Serial.println("brush 2 allocation problem");
  else  Serial.println("brush 2 allocation ok");

  if (waveBrush3.isvalid() == false) Serial.println("brush 3 allocation problem");
  else  Serial.println("brush 3 allocation ok");
  
  if (waveBrush4.isvalid() == false) Serial.println("brush 4 allocation problem");
  else  Serial.println(F("brush 4 allocation ok"));
  
  if (waveBrush5.isvalid() == false) Serial.println("brush 5 allocation problem");
  else  Serial.println(F("brush 5 allocation ok"));
  
  if (waveBrush6.isvalid() == false) Serial.println("brush 6 allocation problem");
  else  Serial.println(F("brush 6 allocation ok"));
  
  if (waveBrush7.isvalid() == false) Serial.println("brush 7 allocation problem");
  else  Serial.println(F("brush 7 allocation ok"));
  
  if (waveBrush8.isvalid() == false) Serial.println("brush 8 allocation problem");
  else  Serial.println(F("brush 8 allocation ok"));
  
  if (waveBrush9.isvalid() == false) Serial.println("brush 9 allocation problem");
  else  Serial.println("brush 9 allocation ok");
}