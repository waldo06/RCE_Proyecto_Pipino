#include <WiFi.h>
#include <Wire.h>
#include "HT_SSD1306Wire.h"
#include <WebServer.h>

#include "pagina_web.h"
#include "pagina_index.h"
#include "config.h"
#include "control.h"

WebServer server(80);  // Puerto HTTP


#ifdef WIRELESS_STICK_V3
static SSD1306Wire display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_64_32, RST_OLED);
#else
static SSD1306Wire display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED);
#endif

void VextON(void) {
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW);
}

void pantallaBienvenida() {
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_CENTER);

  int y = (display.getHeight() - 16 - 12) / 2;
  display.drawString(display.getWidth() / 2, y, "Bienvenidos");
  display.display();

  int barWidth = display.getWidth() - 20;
  int barX = 10;
  int barY = display.getHeight() - 10;
  int barHeight = 6;

  for (int i = 0; i <= barWidth; i += 4) {
    display.setColor(BLACK);
    display.fillRect(barX, barY, barWidth, barHeight);
    display.setColor(WHITE);
    display.drawRect(barX, barY, barWidth, barHeight);
    display.fillRect(barX, barY, i, barHeight);
    display.display();
    delay(40);
  }

  delay(700);
}

void pantallaPrincipal() {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);

  display.setFont(ArialMT_Plain_24);
  display.drawString(display.getWidth() / 2, 0, "RCE");

  display.setFont(ArialMT_Plain_16);
  display.drawString(display.getWidth() / 2, 26, "Ingeniería");

  display.setFont(ArialMT_Plain_10);
  display.drawString(display.getWidth() / 2, display.getHeight() - 15, "Industria Argentina");

  display.display();
  delay(2000);
}

void mostrarInfoWiFi(const char* ssid, const char* password, IPAddress ip) {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);

  display.drawString(0, 0, "Red WiFi:");
  display.drawString(0, 12, ssid);

  display.drawString(0, 26, "Clave:");
  display.drawString(0, 38, password);

  display.drawString(0, 50, "IP: " + ip.toString());

  display.display();
}

void iniciarPuntoDeAcceso() {
  const char* ssid = "RCE_Ingenieria";
  const char* password = "12345678";

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();

  Serial.println("Modo AP iniciado");
  Serial.println("SSID: " + String(ssid));
  Serial.println("Password: " + String(password));
  Serial.println("IP: " + IP.toString());

  mostrarInfoWiFi(ssid, password, IP);
}

void iniciarServidorWeb() {
  server.on("/", []() {
    server.send_P(200, "text/html", htmlInicio);
  });

  server.on("/index", []() {
    server.send_P(200, "text/html", htmlIndex);
  });

  server.on("/control", []() {
    server.send_P(200, "text/html", htmlControl);
  });

  server.on("/config", []() {
    server.send_P(200, "text/html", htmlConfig);
  });

  server.begin();
  Serial.println("Servidor web iniciado");
}



void setup() {
  Serial.begin(115200);
  VextON();
  delay(100);

  display.init();
  display.setContrast(255);

  pantallaBienvenida();
  pantallaPrincipal();
  iniciarPuntoDeAcceso();
  iniciarServidorWeb();

}

void loop() {
  server.handleClient();
}

