#include <Adafruit_NeoPixel.h>
#include <NeoPixelPainter.h>

#define RING0_PIN  46
#define RING1_PIN  44
#define RING2_PIN  42
#define RING3_PIN  40
#define RING4_PIN  38
#define RING5_PIN  36
#define RING6_PIN  34
#define RING7_PIN  32
#define RING8_PIN  30
#define RING9_PIN  28

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

// We have 4 'waves" of color (brushes) that move along each strip
NeoPixelPainterBrush wave0[] = {
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
NeoPixelPainterBrush wave1[] = {
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
NeoPixelPainterBrush wave2[] = {
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
NeoPixelPainterBrush wave3[] = {
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
    whorl[i].setBrightness(125); // This is to keep power consumption within the ability of the ~3a power supply.
  }

  // Configure the waves of color. Each wave is an array of brushes, one each strip (ring) in the whorl. The brushes are positioned along the strip and follow/interfere with each other to create a semi-random rotating wave effect. 
  // All the brushes are initially set to the blue-turquoise scheme, then the brushes for the "TRANSITION_RING" get readjusted.
  HSV currentColor; // NeoPixelPainter uses a struct for color instead of NeoPixel's 32bit integers
  currentColor.s = 255; 
  currentColor.v = 170; 
  bool shouldFadeIn = true;
  bool shouldFadeOut = true;
  int speedFactor = 20; // 4096 is max for brushSpeed  //    The length of the specific strips 
  float fadeFactor = 110; // 255 is max for fadeSpeed  //    is used to scale these 'Factor values
  // First Wave - Aquamarine
  currentColor.h = 140;
  for(uint8_t i=0; i < RING_COUNT; i++) {
    wave0[i].setColor(currentColor);
    wave0[i].setFadein(shouldFadeIn);
    wave0[i].setFadeout(shouldFadeOut); 
    wave0[i].setFadeSpeed(fadeFactor + whorl[i].numPixels() );
    wave0[i].setSpeed( speedFactor * whorl[i].numPixels() ); 
  }
  // Second Wave - Turquoise
  currentColor.h = 120;
  for(uint8_t i=0; i < RING_COUNT; i++) {
    wave1[i].setColor(currentColor);
    wave1[i].setFadein(shouldFadeIn);
    wave1[i].setFadeout(shouldFadeOut);
    wave1[i].setFadeSpeed( fadeFactor + whorl[i].numPixels() + 40 );
    wave1[i].setSpeed( speedFactor * whorl[i].numPixels() );
    wave1[i].moveTo( whorl[i].numPixels() * .25 );
  }
  // Third Wave - Seafoam
  currentColor.h = 110;
  currentColor.s = 225;
  currentColor.v = 200; 
  for(uint8_t i=0; i < RING_COUNT; i++) {
    wave2[i].setColor(currentColor);
    wave2[i].setFadein(shouldFadeIn);
    wave2[i].setFadeout(shouldFadeOut);
    wave2[i].setFadeSpeed(fadeFactor + whorl[i].numPixels() );
    wave2[i].setSpeed( speedFactor * whorl[i].numPixels() );
    wave2[i].moveTo( whorl[i].numPixels() *  .5 );
  }
  // Fourth Wave - Turquoise
  currentColor.h = 120;
  currentColor.s = 225;
  currentColor.v = 200; 
  for(uint8_t i=0; i < RING_COUNT; i++) {
    wave3[i].setColor(currentColor);
    wave3[i].setFadein(shouldFadeIn);
    wave3[i].setFadeout(shouldFadeOut);
    wave3[i].setFadeSpeed(fadeFactor + whorl[i].numPixels() );
    wave3[i].setSpeed( speedFactor * whorl[i].numPixels() );
    wave3[i].moveTo( whorl[i].numPixels() * .75 );
  }

  // Handle the "TRANSITION_RING"
  // Violet
  currentColor.h = 180; 
  currentColor.s = 255; 
  wave0[TRANSITION_RING].setColor(currentColor);
  wave0[TRANSITION_RING].setFadeSpeed( 250 );
  // Pink
  currentColor.h = 220; 
  currentColor.v = 255;
  wave1[TRANSITION_RING].setColor(currentColor);
  wave1[TRANSITION_RING].setFadeSpeed( 150 );
  // Darker Pink
  currentColor.v = 155; 
  wave2[TRANSITION_RING].setColor(currentColor);
  wave2[TRANSITION_RING].setFadeSpeed( 250 );
  // Purple
  currentColor.h = 190; 
  currentColor.v = 160;
  wave3[TRANSITION_RING].setColor(currentColor);
  wave3[TRANSITION_RING].setFadeSpeed( 250 );
}

void loop() {
  // clear the neopixels
  for(uint8_t i=0; i < RING_COUNT; i++) {
    whorl[i].clear();
  }
    
  // "paint" the current position of the waves on each strip's "canvas" (implicitly updates brushes position for next loop)
  for(int i=0; i < RING_COUNT; i++) {
    wave0[i].paint(); 
    wave1[i].paint();
    wave2[i].paint();
    wave3[i].paint();
  }  

  // transfer canvases to the neopixels
  for(int i=0; i < RING_COUNT; i++) {
    whorlCanvases[i].transfer();
  // }  
  // 
  // // show the neopixels
  // for(int i=0; i < RING_COUNT; i++) {
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
      
    if (wave0[i].isvalid() == false) Serial.println("wavebrush allocation problem");
      else  Serial.println("wavebrush allocation ok");

  }  
}