
int byteRecibido = 0, i = 0;
int led[6] = {3,5,6,9,10,11};

void setup()
{
  Serial.begin(115200);
  for(i = 0; i < 6; i++)
    pinMode(led[i], OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    byteRecibido = Serial.read();
    analogWrite(led[i],byteRecibido);
    i++;
    if(i > 5) i = 0;
    //delay(1);
  }
}
