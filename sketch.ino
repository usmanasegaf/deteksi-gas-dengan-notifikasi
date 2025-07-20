#include <WiFi.h>
#include <HTTPClient.h>

#define GAS_SENSOR_PIN 34
#define BUZZER_PIN 25
#define LED_PIN 26

const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Token dan Chat ID kamu
const char* telegramBotToken = "8090456066:AAGx42e_wvjSMuuz1hf_7Y9MIDGGhGtmYZw";
const char* chatID = "8199538562";

unsigned long waktuTerakhirKirim = 0;
const unsigned long intervalKirim = 15000; // 15 detik

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nTerhubung ke WiFi!");
  Serial.println(WiFi.localIP());
}

void loop() {
  int gasValue = analogRead(GAS_SENSOR_PIN);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > 3497) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);

    unsigned long sekarang = millis();
    if (sekarang - waktuTerakhirKirim >= intervalKirim) {
      kirimNotifikasi(gasValue);
      waktuTerakhirKirim = sekarang;
    }
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    waktuTerakhirKirim = 0; // reset waktu agar bisa kirim ulang jika muncul lagi
  }

  delay(1000); // Deteksi tetap per 1 detik
}

void kirimNotifikasi(int value) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + String(telegramBotToken)
                + "/sendMessage?chat_id=" + String(chatID)
                + "&text=⚠️ Gas terdeteksi > 200ppm! Nilai: " + String(value) 
                + ", Nilai 3497 = 200 ppm ";

    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.println("Notifikasi terkirim.");
    } else {
      Serial.println("Gagal kirim notifikasi.");
    }
    http.end();
  }
}
