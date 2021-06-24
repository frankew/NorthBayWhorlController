#include <Adafruit_NeoPixel.h>
#include <NeoPixelPainter.h>


#define RING0_PIN  46 // 51
#define RING1_PIN  44 // 49
#define RING2_PIN  42 // 47
#define RING3_PIN  40 // 45
#define RING4_PIN  38 // 43
#define RING5_PIN  36 // 41
#define RING6_PIN  34 // 39
#define RING7_PIN  32 // 37
#define RING8_PIN  30 // 35
#define RING9_PIN  28 // 33

#define RING0_LENGTH  12
#define RING1_LENGTH  22
#define RING2_LENGTH  35
#define RING3_LENGTH  51 
#define RING4_LENGTH  64
#define RING5_LENGTH  61 
#define RING6_LENGTH  70
#define RING7_LENGTH  84 
#define RING8_LENGTH  94
#define RING9_LENGTH  15

#define RING_COUNT 10
#define TRANSITION_RING 7

// Called rings, but actually neopixel strips. 
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

//create canvases for each strip of neopixel strips in whorl[]
NeoPixelPainterCanvas whorlCanvases[] = {
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

// create brushes, linked to the canvases in whorlCanvases[]
NeoPixelPainterBrush waveBrushes[] = {
  NeoPixelPainterBrush(&whorlCanvases[0]),
  NeoPixelPainterBrush(&whorlCanvases[1]),
  NeoPixelPainterBrush(&whorlCanvases[2]),
  NeoPixelPainterBrush(&whorlCanvases[3]),
  NeoPixelPainterBrush(&whorlCanvases[4]),
  NeoPixelPainterBrush(&whorlCanvases[5]),
  NeoPixelPainterBrush(&whorlCanvases[6]),
  NeoPixelPainterBrush(&whorlCanvases[7]),
  NeoPixelPainterBrush(&whorlCanvases[8]),
  NeoPixelPainterBrush(&whorlCanvases[9])
};
NeoPixelPainterBrush wave2Brushes[] = {
  NeoPixelPainterBrush(&whorlCanvases[0]),
  NeoPixelPainterBrush(&whorlCanvases[1]),
  NeoPixelPainterBrush(&whorlCanvases[2]),
  NeoPixelPainterBrush(&whorlCanvases[3]),
  NeoPixelPainterBrush(&whorlCanvases[4]),
  NeoPixelPainterBrush(&whorlCanvases[5]),
  NeoPixelPainterBrush(&whorlCanvases[6]),
  NeoPixelPainterBrush(&whorlCanvases[7]),
  NeoPixelPainterBrush(&whorlCanvases[8]),
  NeoPixelPainterBrush(&whorlCanvases[9])
};
NeoPixelPainterBrush wave3Brushes[] = {
  NeoPixelPainterBrush(&whorlCanvases[0]),
  NeoPixelPainterBrush(&whorlCanvases[1]),
  NeoPixelPainterBrush(&whorlCanvases[2]),
  NeoPixelPainterBrush(&whorlCanvases[3]),
  NeoPixelPainterBrush(&whorlCanvases[4]),
  NeoPixelPainterBrush(&whorlCanvases[5]),
  NeoPixelPainterBrush(&whorlCanvases[6]),
  NeoPixelPainterBrush(&whorlCanvases[7]),
  NeoPixelPainterBrush(&whorlCanvases[8]),
  NeoPixelPainterBrush(&whorlCanvases[9])
};
NeoPixelPainterBrush wave4Brushes[] = {
  NeoPixelPainterBrush(&whorlCanvases[0]),
  NeoPixelPainterBrush(&whorlCanvases[1]),
  NeoPixelPainterBrush(&whorlCanvases[2]),
  NeoPixelPainterBrush(&whorlCanvases[3]),
  NeoPixelPainterBrush(&whorlCanvases[4]),
  NeoPixelPainterBrush(&whorlCanvases[5]),
  NeoPixelPainterBrush(&whorlCanvases[6]),
  NeoPixelPainterBrush(&whorlCanvases[7]),
  NeoPixelPainterBrush(&whorlCanvases[8]),
  NeoPixelPainterBrush(&whorlCanvases[9])
};

void setup() {

  randomSeed(analogRead(0)); //some noise for random seed 

  // Serial.begin(115200);      // Just for development
  // checkBrushesAndCanvases(); // check if ram allocation of brushes and canvases was successful (painting will not work if unsuccessful, program should still run though)

  // Set up the neopixel whorl
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
    whorl[i].setBrightness(125);
  }

  // Set up the brushes
  int speedFactor = 20; // 4096 is max for brushSpeed
  float fadeFactor = 110; // 255 is max for fadeSpeed
  bool shouldFadeOut = true;
  bool shouldFadeIn = true;
  
  // NeoPixelPainter uses a struct for color instead of NeoPixel's 32bit integers
  HSV waveColor;
  waveColor.h = 140; // random(115, 135); //  
  waveColor.s = 255; 
  waveColor.v = 170; 
  for(uint8_t i=0; i < RING_COUNT; i++) {
    waveBrushes[i].setColor(waveColor);
    waveBrushes[i].setFadein(shouldFadeIn);
    waveBrushes[i].setFadeout(shouldFadeOut); 
    waveBrushes[i].setFadeSpeed(fadeFactor + whorl[i].numPixels() );
    waveBrushes[i].setSpeed( speedFactor * whorl[i].numPixels() ); 
  }
  
  waveColor.h = 120; // Turqs  
  for(uint8_t i=0; i < RING_COUNT; i++) {
    wave2Brushes[i].setColor(waveColor);
    wave2Brushes[i].setFadein(shouldFadeIn);
    wave2Brushes[i].setFadeout(shouldFadeOut);
    wave2Brushes[i].setFadeSpeed(fadeFactor + whorl[i].numPixels() );
    wave2Brushes[i].setSpeed( speedFactor * whorl[i].numPixels() );
    wave2Brushes[i].moveTo( whorl[i].numPixels() * .25 );
  }

  waveColor.h = 110; // 
  waveColor.v = 200; 
  waveColor.s = 225;
  // fadeFactor = 60;
  for(uint8_t i=0; i < RING_COUNT; i++) {
    wave3Brushes[i].setColor(waveColor);
    wave3Brushes[i].setFadein(shouldFadeIn);
    wave3Brushes[i].setFadeout(shouldFadeOut);
    wave3Brushes[i].setFadeSpeed(fadeFactor + whorl[i].numPixels() );
    wave3Brushes[i].setSpeed( speedFactor * whorl[i].numPixels() );
    wave3Brushes[i].moveTo( whorl[i].numPixels() *  .5 );
  }
  
  waveColor.h = 120; // 
  waveColor.v = 200; 
  waveColor.s = 225;
  // fadeFactor = 60;
  for(uint8_t i=0; i < RING_COUNT; i++) {
    wave4Brushes[i].setColor(waveColor);
    wave4Brushes[i].setFadein(shouldFadeIn);
    wave4Brushes[i].setFadeout(shouldFadeOut);
    wave4Brushes[i].setFadeSpeed(fadeFactor + whorl[i].numPixels() );
    wave4Brushes[i].setSpeed( speedFactor * whorl[i].numPixels() );
    wave4Brushes[i].moveTo( whorl[i].numPixels() * .75 );
  }

  
  // the brush for the "TRANSITION_RING" gets readjusted to have a different color
  waveColor.h = 180; // Purple
  waveColor.s = 255; 
  waveBrushes[TRANSITION_RING].setColor(waveColor);
  waveBrushes[TRANSITION_RING].setFadeSpeed( 250 );
  
  waveColor.h = 220; // Pink
  waveColor.v = 255;
  wave2Brushes[TRANSITION_RING].setColor(waveColor);
  wave2Brushes[TRANSITION_RING].setFadeSpeed( 150 );
  
  waveColor.h = 220;
  waveColor.v = 155;
  wave3Brushes[TRANSITION_RING].setColor(waveColor);
  wave3Brushes[TRANSITION_RING].setFadeSpeed( 250 );
  
  waveColor.h = 190;
  waveColor.v = 160;
  wave4Brushes[TRANSITION_RING].setColor(waveColor);
  wave4Brushes[TRANSITION_RING].setFadeSpeed( 250 );
}

void loop() {
  // clear the neopixels and reset the minimum background colors
  for(uint8_t i=0; i < RING_COUNT; i++) {
    whorl[i].clear();
  }
    
  // paint the canvases (and update brushes)
  for(int i=0; i < RING_COUNT; i++) {
    waveBrushes[i].paint(); 
    wave2Brushes[i].paint();
    wave3Brushes[i].paint();
    wave4Brushes[i].paint();
  }  

  // transfer canvases to the neopixels
  for(int i=0; i < RING_COUNT; i++) {
    whorlCanvases[i].transfer();
  }  
  
  // show the neopixels
  for(int i=0; i < RING_COUNT; i++) {
    whorl[i].show();
  }
}

void checkBrushesAndCanvases() {
  //this check is optional but helps to check if something does not work, especially on low ram chips like the Arduino Uno
  for(int i=0; i < RING_COUNT; i++) {
    Serial.print("checking ring number: ");
    Serial.println(i);
    if (whorlCanvases[i].isvalid() == false) Serial.println("canvas allocation problem");
      else  Serial.println("canvas allocation ok");
      
    if (waveBrushes[i].isvalid() == false) Serial.println("wavebrush allocation problem");
      else  Serial.println("wavebrush allocation ok");

  }  
}