#include <Adafruit_SH1106.h>
#include <RTClib.h>

#define OLED_RESET 4

Adafruit_SH1106 display(OLED_RESET);

RTC_DS3231 RTC;




void setup() {
display.begin(SH1106_SWITCHCAPVCC, 0x3C);

//RTC.adjust(DateTime(__DATE__,__TIME__));    //Subir el codigo, luego comentar esta linea de codigo y volver a subirlo al arduino.
                                            // esta linea sirve para ajustar el horario y fecha, si no la comentas al subirlo nuevamente
                                            // puedes tener problemas con horario y fecha al desconectar el arduino
}

void loop() {

display.clearDisplay();
DateTime now = RTC.now();

display.clearDisplay(); 
display.setRotation(0);
display.setCursor(28,0);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println("RELOJ DIGITAL");

display.setRotation(0);
display.setCursor(15,20);
display.setTextColor(WHITE);
display.setTextSize(2);
display.println(now.hour());

display.setRotation(0);
display.setCursor(40,17);
display.setTextColor(WHITE);
display.setTextSize(3);
display.println(":");


display.setRotation(0);
display.setCursor(53,20);
display.setTextColor(WHITE);
display.setTextSize(2);
display.println(now.minute());

display.setRotation(0);
display.setCursor(75,17);
display.setTextColor(WHITE);
display.setTextSize(3);
display.println(":");

display.setRotation(0);
display.setCursor(90,20);
display.setTextColor(WHITE);
display.setTextSize(2);
display.println(now.second());


display.setRotation(0);
display.setCursor(25,50);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(now.day());


display.setRotation(0);
display.setCursor(40,50);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println("-");

display.setRotation(0);
display.setCursor(50,50);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(now.month());


display.setRotation(0);
display.setCursor(65,50);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println("-");

display.setRotation(0);
display.setCursor(75,50);
display.setTextColor(WHITE);
display.setTextSize(1);
display.println(now.year());
display.display();



}
