#define PUL 9 //CLK  定义9输出端口为 PUL（脉冲信号）
#define DIR 10 //CW  定义10输出端口为DIR（方向信号）

void setup() {
  // put your setup code here, to run once:
  pinMode(PUL,OUTPUT);
  pinMode(DIR,OUTPUT);
  Serial.begin(9600);  //定义串口比特波率（用于与计算机通信。。。还未开发目前）
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(DIR,LOW);//先让arduino向驱动板输出一个低电平使其反转。
  /* 
   *  3200是由步进电机的转动角和细分数决定，
   * 比如我使用的是1.8的转动角，转动一圈需要200次，
   * 即200步，如使用驱动器上有细分开关，需要×细分数，
   * 比如我打开16细分，200*16=3200.
   * ps：脉冲间距很重要，不调整好容易出现电机来回转和抖动的情况。
   */
  for(int j = 0 ; j<=10;j++)//外层for循环控制转动圈数
    {
    for(int i = 0 ; i<=3200 ; i++)//内层for循环控制转动一圈需要多少个脉冲
    {
    digitalWrite(PUL,LOW);
    delayMicroseconds(20);//脉冲间距
    digitalWrite(PUL,HIGH);
    delayMicroseconds(20);//脉冲间距
    }
    delay(100);
    } 
    delay(10000);

    digitalWrite(DIR,HIGH);
  for(int j = 0 ; j<=10;j++)
    {
    for(int i = 0 ; i<=3200 ; i++)
    {
    digitalWrite(PUL,HIGH);
    delayMicroseconds(20);
    digitalWrite(PUL,LOW);
    delayMicroseconds(20);
    }
    delay(100);
    } 
    delay(10000);
}
