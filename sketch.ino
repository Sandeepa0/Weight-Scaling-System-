
#include<HX711.h>

const int ld_cell=2;
const int ld_sck=4;

HX711 scale;

void setup() {
  Serial.begin(115200);
  scale.begin(ld_cell,ld_sck);

}

void loop() {
  if(scale.is_ready())
  {
    scale.set_scale();
    Serial.println("Tare_remove_weight...");
    delay(5000);
    scale.tare();
    Serial.println("tare done...");
    Serial.println("now put weight..");
    delay(5000);
    long reading = scale.get_units(10);
    Serial.println(reading/419.8);

  }
  delay(10);
}
