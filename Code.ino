#define enA 7
#define in1 6
#define in2 5
#define in3 4
#define in4 3
#define enB 2

int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 8;

int kecepatan=255;
int state = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  Serial.begin(9600);
  motor_stop();
  delay(100);
  Serial.println(" Controller\n ");
  Serial.println(" =======================");
  Serial.println("  w -> Maju           ");
  Serial.println("  s -> Mundur         ");
  Serial.println("  a -> Belok Kiri     ");
  Serial.println("  d -> Belok Kanan    ");
  Serial.println("  b -> Berhenti  ");
  Serial.println(" =======================");
}

void loop() {
  if(Serial.available() > 0)
  { 
    state = Serial.read(); 
    Serial.println(state);
    }
  if(!digitalRead(state == 'w'))
  {
    motor_maju();
    led_maju();
    }
  if(!digitalRead(state == 's'))
  {
    motor_mundur();
    led_mundur();
    }
  if(!digitalRead(state == 'a'))
  {
    motor_puterkiri();
    led_puterkiri();
    }
  if(!digitalRead(state == 'd'))
  {
    motor_puterkanan();
    led_puterkanan();
    }
  if(!digitalRead(state == 'b'))
  {
    motor_stop();
    led_stop();
    }
}

void motor_maju()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, HIGH);//Motor A
  digitalWrite(in2, LOW);//Motor A
  digitalWrite(in3, HIGH);//Motor B
  digitalWrite(in4, LOW);//Motor B
  analogWrite (enB, kecepatan);
  Serial.println(" Maju");
}
void motor_mundur()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, LOW);//Motor A
  digitalWrite(in2, HIGH);//Motor A
  digitalWrite(in3, LOW);//Motor B
  digitalWrite(in4, HIGH);//Motor B
  analogWrite (enB, kecepatan);
  Serial.println(" Mundur");
}
void motor_puterkiri()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, LOW);//Motor A
  digitalWrite(in2, LOW);//Motor A
  digitalWrite(in3, HIGH);//Motor B
  digitalWrite(in4, LOW);//Motor B
  analogWrite (enB, kecepatan);
  Serial.println(" Kiri");
}
void motor_puterkanan()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, HIGH);//Motor A
  digitalWrite(in2, LOW);//Motor A
  digitalWrite(in3, LOW);//Motor B
  digitalWrite(in4, LOW);//Motor B
  analogWrite (enB, kecepatan);
  Serial.println(" Kanan");
}
void motor_stop()
{
  analogWrite (enA, 0);
  analogWrite (enB, 0);
  Serial.println("Berhenti");
}

void led_maju(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
void led_mundur(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void led_puterkiri(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
}

void led_puterkanan(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
}

void led_stop(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
