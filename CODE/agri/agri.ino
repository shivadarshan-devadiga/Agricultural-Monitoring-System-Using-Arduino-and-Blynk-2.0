// Blynk IOT Smart Agriculture Monitoring System
#define BLYNK_TEMPLATE_ID "TMPL3yRl7xtzw" //from blynk app
#define BLYNK_TEMPLATE_NAME "Agriculture Project" //from blynk app
#define BLYNK_AUTH_TOKEN "d9wkdqilDe9WlbuRgcE_t-yNnDlIN7CZ" //from blynk app
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

char auth[] = "d9wkdqilDe9WlbuRgcE_t-yNnDlIN7CZ";
char ssid[] = "Galaxy M21CA92"; //wifi name
char pass[] = "22122003"; //wifi password

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN D4
DHT dht(DHTPIN,DHT11);
#define ONE_WIRE_BUS D6
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

#define buzzer D5
#define rainPin D7
int rainState = 0;
int lastRainState = 0;
const int AirValue = 633; //calculated with salt water
const int WaterValue = 286; //calculated with pure water
const int SensorPin = A0;
int soilMoistureValue = 0;
int soilmoisturepercent = 0;
int relay = D0;

void setup()
{
  Serial.begin(115200);
  delay(100);
  Blynk.begin(auth, ssid, pass);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  sensors.begin();
  dht.begin();
}

void loop() {
  Blynk.run();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  Serial.print("Soil Temperature: ");
  Serial.println(temp);
  Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print("Humidity: ");
  Serial.println(h);

  Blynk.virtualWrite(V3, t);
  Blynk.virtualWrite(V4, h);
  Blynk.virtualWrite(V2, temp);

  soilMoistureValue = analogRead(SensorPin);
  Serial.println(soilMoistureValue);

  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  Blynk.virtualWrite(V1, soilmoisturepercent);

  if (soilmoisturepercent > 100)
  {
    Serial.println("100 %");
    delay(1500);
    display.clearDisplay();

    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,5);
    display.print("RH of Soil: ");
    display.print("100");
    display.print(" %");

    // display Air temperature
    display.setCursor(0,15);
    display.print("Soil Temp: ");
    display.print(temp);
    display.print(" ");
    display.cp437(true);
    display.write(176);
    display.print("C");

    display.display();
    delay(1500);
  }
  else if (soilmoisturepercent < 0)
  {
    Serial.println("0 %");
    delay(1500);
    display.clearDisplay();

    // display Soil temperature
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 5);
    display.print("RH of Soil: ");
    display.print("0");
    display.print(" %");

    // display Air temperature
    display.setCursor(0,15);
    display.print("Soil Temp: ");
    display.print(temp);
    display.print(" ");
    display.cp437(true);
    display.write(176);
    display.print("C");

    display.display();
    delay(1500);
  }
  else if (soilmoisturepercent >= 0 && soilmoisturepercent <= 100)
  {
    Serial.print(soilmoisturepercent);
    Serial.println("%");
    delay(1500);
    display.clearDisplay();

    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 5);
    display.print("RH of Soil: ");
    display.print(soilmoisturepercent);
    display.print(" %");

    display.setCursor(0, 15);
    display.print("Soil Temp: ");
    display.print(temp);
    display.print(" ");
    display.cp437(true);
    display.write(176);
    display.print("C");

    display.display();
    delay(1500);
  }
  if (soilmoisturepercent >= 0 && soilmoisturepercent <= 50)
  {
    Serial.println("Soil mositure level is very low!! Plants need water... Pump is activated");
    //send notification    
    Blynk.logEvent("soil_moisture") ;
    digitalWrite(relay, LOW);
    digitalWrite(buzzer, HIGH);
    Serial.println("Motor is ON");
    delay(1000);
  }
  else if (soilmoisturepercent > 50 && soilmoisturepercent <= 100)
  {
    Serial.println("Soil Moisture level looks good...");
    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, LOW);
    Serial.println("Motor is OFF");
    delay(1000);
  }

  rainState = digitalRead(rainPin);
  Serial.println(rainState);

  if (rainState == 0 && lastRainState == 0) 
  {
    Serial.println("It's Raining outside!");
    Blynk.logEvent("rain_alert") ;
    lastRainState = 1;
    delay(1000);
  }
  else if (rainState == 0 && lastRainState == 1) 
  {
    delay(1000);
  }
  else 
  {
    Serial.println("No Rains...");
    lastRainState = 0;
    delay(1000);
  }
  delay(100);
}