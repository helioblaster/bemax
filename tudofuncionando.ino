#include <Wire.h>
#include <LiquidCrystal_I2C.h> // MODIFICADO
#include <Adafruit_NeoPixel.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define SENSOR_PULSO A1
#define MIC_PIN A0
#define LED_PIN 6
#define NUM_LEDS 12

Adafruit_NeoPixel ring(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

unsigned long ledAltoAte = 0;
unsigned long duracaoAlerta = 1500;

// Variáveis de Pulso
int baseline = 500; // 405 baseline original
int threshold = 200; // 566 threshold original

unsigned long ultimaDeteccao = 0;
int ultimoValor = 0;
bool aguardandoQueda = false;

int bpm = 0;
int bpm_mostrado = 80;
unsigned long ultimoUpdate = 0;

void setup() {
  Serial.begin(115200);

  // LCD
  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Monitor de Pulso");
  delay(1500);
  lcd.clear();

  // NeoPixel
  ring.begin();
  ring.show();
}

void loop() {
  //  Leitura do BPM
  int leitura = analogRead(SENSOR_PULSO);

  // Filtro
  float alpha = 0.1;
  int valor = ultimoValor + alpha * (leitura - ultimoValor);
  ultimoValor = valor;
  unsigned long agora = millis();
  bool picoDetectado = false;

  // Detecção do pico
  if (!aguardandoQueda && valor > threshold) {

    unsigned long intervalo = agora - ultimaDeteccao;

    if (intervalo > 400) {
      bpm = 60000 / intervalo;
      ultimaDeteccao = agora;
      picoDetectado = true;
    }

    aguardandoQueda = true;
  }

  if (aguardandoQueda && valor < baseline) {
    aguardandoQueda = false;
  }

  if (picoDetectado) {
    if (bpm >= 60 && bpm <= 100) {
      bpm_mostrado = bpm;
    }
  }
//  Leitura do sensor de ruído
int micValue = analogRead(MIC_PIN);
unsigned long agora2 = millis();

String nivelRuido;

if (micValue >= 134) {
    nivelRuido = "ALTO!";
    ledAltoAte = agora2 + duracaoAlerta;
}

if (agora2 < ledAltoAte) {
    setColor(255, 0, 0);   // vermelho
    nivelRuido = "Alto";
}
else {
    if (micValue < 130) {
      setColor(0, 255, 0);        // verde
      nivelRuido = "Baixo";
    }
    else {
      setColor(255, 150, 0);      // amarelo
      nivelRuido = "Medio";
    }
}
  //  Atualização do LCD(300 ms)
  if (agora - ultimoUpdate > 300) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("BPM: ");
    lcd.print(bpm_mostrado);

    lcd.setCursor(0, 1);
    lcd.print("Ruido: ");
    lcd.print(nivelRuido);

    ultimoUpdate = agora;
  }

  delay(10);
}
// LED RGB
void setColor(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    ring.setPixelColor(i, ring.Color(r, g, b));
  }
  ring.show();
}