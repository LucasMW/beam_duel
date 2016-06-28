#define LED_PIN 4
#define BT_LEFT 6
#define BT_RIGHT 7
#define BT_BEAM 8

#define MIN_INTERVAL 100

int STOP = false;
int LED_STATE = 0;
int INTERVAL = 20;
int OLD = millis();
int BT_LEFT_LASTPRESS = millis();
int BT_RIGHT_LASTPRESS = millis();
int BT_UP_LASTPRESS = millis();
int BT_UP_LAST_STATUS = LOW;
int BT_LEFT_LAST_STATUS = LOW;
int BT_RIGHT_LAST_STATUS = LOW;
void setup () {
    pinMode(BT_LEFT, INPUT);
    pinMode(BT_RIGHT, INPUT);
    pinMode(BT_BEAM, INPUT);
    Serial.begin(9600);
    Serial.println("ON");
    //Keyboard.begin();
}

void loop () {
  
 if(STOP == false){ 
    int btup = digitalRead(BT_BEAM); // Read button state
    if(btup == HIGH){
      int btup_now = millis();
      if(btup_now - MIN_INTERVAL >= BT_UP_LASTPRESS){
        if(BT_UP_LAST_STATUS == LOW) Serial.print("1");
        BT_UP_LAST_STATUS = HIGH;
        Serial.print("W");
        BT_UP_LASTPRESS = millis();
      }
    }
  else{
      if(BT_UP_LAST_STATUS == HIGH) Serial.print("0");
      BT_UP_LAST_STATUS = LOW;
    }
    
    int btleft = digitalRead(BT_LEFT); // Read button state
    if(btleft == HIGH){
      int btleft_now = millis();
      if(btleft_now - MIN_INTERVAL >= BT_LEFT_LASTPRESS){
        if(BT_LEFT_LAST_STATUS == LOW) Serial.print("1");
        BT_LEFT_LAST_STATUS = HIGH;
        Serial.print("A");
        BT_LEFT_LASTPRESS = millis();
        //Keyboard.press(KEY_LEFT_ARROW);
      }
    }
    else{
      if(BT_LEFT_LAST_STATUS == HIGH) Serial.print("0");
      BT_LEFT_LAST_STATUS = LOW;
    }
    
    int btright = digitalRead(BT_RIGHT); // Read button state
    if(btright == HIGH){
      int btright_now = millis();
      if(btright_now - MIN_INTERVAL >= BT_RIGHT_LASTPRESS){
        if(BT_RIGHT_LAST_STATUS == LOW) Serial.print("1");
        BT_RIGHT_LAST_STATUS = HIGH;
        Serial.print("D");
        BT_RIGHT_LASTPRESS = millis();
        //Keyboard.press(KEY_RIGHT_ARROW);
      }
    }
    else{
      if(BT_RIGHT_LAST_STATUS == HIGH) Serial.print("0");
      BT_RIGHT_LAST_STATUS = LOW;
    }
 }
}
