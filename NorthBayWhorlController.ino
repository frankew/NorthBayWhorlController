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

#define RING_COUNT 10
#define TRANSITION_RING 7

// Called rings, but actually strips. 
// typedef Adafruit_NeoPixel* NeoPixPointer;
Adafruit_NeoPixel whorl[RING_COUNT] = {
  Adafruit_NeoPixel(RING0_LENGTH, RING0_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING1_LENGTH, RING1_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING2_LENGTH, RING2_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING3_LENGTH, RING3_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING4_LENGTH, RING4_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING5_LENGTH, RING5_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING6_LENGTH, RING6_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING7_LENGTH, RING7_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING8_LENGTH, RING8_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(RING9_LENGTH, RING9_PIN, NEO_GRB + NEO_KHZ800)
};

//create canvas, linked to the neopixels (must be created before the brush)
NeoPixelPainterCanvas pixelCanvases[] = {
  NeoPixelPainterCanvas(&whorl[0]),    
  NeoPixelPainterCanvas(&whorl[1]),   
  NeoPixelPainterCanvas(&whorl[2]),   
  NeoPixelPainterCanvas(&whorl[3]),    
  NeoPixelPainterCanvas(&whorl[4]),   
  NeoPixelPainterCanvas(&whorl[5]),   
  NeoPixelPainterCanvas(&whorl[6]),   
  NeoPixelPainterCanvas(&whorl[7]),   
  NeoPixelPainterCanvas(&whorl[8]),   
  NeoPixelPainterCanvas(&whorl[9])  
};

//create brushes, linked to the canvas
NeoPixelPainterBrush waveBrushes[] = {
  NeoPixelPainterBrush(&pixelCanvases[0]),
  NeoPixelPainterBrush(&pixelCanvases[1]),
  NeoPixelPainterBrush(&pixelCanvases[2]),
  NeoPixelPainterBrush(&pixelCanvases[3]),
  NeoPixelPainterBrush(&pixelCanvases[4]),
  NeoPixelPainterBrush(&pixelCanvases[5]),
  NeoPixelPainterBrush(&pixelCanvases[6]),
  NeoPixelPainterBrush(&pixelCanvases[7]),
  NeoPixelPainterBrush(&pixelCanvases[8]),
  NeoPixelPainterBrush(&pixelCanvases[9])
};

uint32_t cTurqsBackground = whorl[0].ColorHSV(29120,  250,  25);
uint32_t cPinkySwearBackground = whorl[0].ColorHSV(57000,  250,  15);

void setup() {

  Serial.begin(115200);      // Just for development
  randomSeed(analogRead(0)); //some noise for random seed 

  checkBrushesAndCanvases();

  // Setup  neopixels
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
  for(uint8_t i=0; i < RING_COUNT; i++) {
    whorl[i].begin();
    whorl[i].setBrightness(100);
  }

  // Configure the brushes
  HSV paintColor;
  paintColor.h = 90; // random(115, 135); //  
  paintColor.s = 195; 
  paintColor.v = 170; 
  int brushSpeed = 4096/2; // 4096 is Max
  int fadeSpeed = 255; // Max
  bool shouldFadeOut = true;
  bool shouldFadeIn = true;
  for(uint8_t i=0; i < RING_COUNT; i++) {
    waveBrushes[i].setSpeed(brushSpeed); 
    waveBrushes[i].setFadein(shouldFadeIn);
    waveBrushes[i].setFadeout(shouldFadeOut);
    waveBrushes[i].setFadeSpeed(fadeSpeed);
    waveBrushes[i].setColor(paintColor);
  }
  // one ring "TRANSITION_RING" gets readjusted 
  paintColor.h = 175; // Pink
  paintColor.s = 255; 
  waveBrushes[TRANSITION_RING].setColor(paintColor);

}

void loop() {
  // clear the neopixels and set fresh background colors
  for(uint8_t i=0; i < RING_COUNT; i++) {
    whorl[i].clear();
    for (uint8_t j=0; j < whorl[i].numPixels(); j++) {
      if (i == TRANSITION_RING) {
        whorl[i].setPixelColor(j, cPinkySwearBackground);
      } else {
        whorl[i].setPixelColor(j, cTurqsBackground);
      }
    }
  }
    
  // paint the canvases (and update brushes)
  for(int i=0; i < RING_COUNT; i++) {
    waveBrushes[i].paint();
  }  

  // transfer canvases to the neopixels
  for(int i=0; i < RING_COUNT; i++) {
    pixelCanvases[i].transfer();
  }  
  
  // show the neopixels
  for(int i=0; i < RING_COUNT; i++) {
    whorl[i].show();
  }

}

void checkBrushesAndCanvases() {
  //check if ram allocation of brushes and canvases was successful (painting will not work if unsuccessful, program should still run though)
  //this check is optional but helps to check if something does not work, especially on low ram chips like the Arduino Uno
  for(int i=0; i < RING_COUNT; i++) {
  
    Serial.print("checking ring number: ");
    Serial.println(i);
    if (pixelCanvases[i].isvalid() == false) Serial.println("canvas allocation problem");
      else  Serial.println("canvas allocation ok");
      
    if (waveBrushes[i].isvalid() == false) Serial.println("wavebrush allocation problem");
      else  Serial.println("wavebrush allocation ok");

  }  
}