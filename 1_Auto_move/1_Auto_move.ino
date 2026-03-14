// PWM control pin
#define PWM1_PIN            5
#define PWM2_PIN            6      
// 74HCT595N Chip pins
#define SHCP_PIN            2                               // The displacement of the clock  时钟的位移
#define EN_PIN              7                               // Can make control 使能引脚
#define DATA_PIN            8                               // Serial data  串行数据
#define STCP_PIN            4                               // Memory register clock  内存寄存器时钟             

const int Forward       = 92;                              // forward  前进
const int Backward      = 163;                              // back 后退
const int Stop          = 0;                                // stop 停车
const int Contrarotate  = 172;                              // Counterclockwise rotation  逆时针旋转
const int Clockwise     = 83;                              // Rotate clockwise 顺时针旋转

void setup()
{
    pinMode(SHCP_PIN, OUTPUT);
    pinMode(EN_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(STCP_PIN, OUTPUT);
    pinMode(PWM1_PIN, OUTPUT);
    pinMode(PWM2_PIN, OUTPUT);
}

void loop()
{
    /* Forward */
    Motor(Forward, 250,250);      
    delay(2000);
    /* Backward */
    Motor(Backward, 250,250);
    delay(2000);
    /* Contrarotate */
    Motor(Contrarotate, 250,250);
    delay(2000);
    /* Clockwise */
    Motor(Clockwise, 250,250);
    delay(2000);
    /* Stop */
    Motor(Stop, 250,250);
    delay(2000);
}

void Motor(int Dir, int Speed1 , int Speed2)
{
    analogWrite(PWM1_PIN, Speed1);
    analogWrite(PWM2_PIN, Speed2);
    digitalWrite(EN_PIN, LOW);
    digitalWrite(STCP_PIN, LOW);
    shiftOut(DATA_PIN, SHCP_PIN, MSBFIRST, Dir);
    digitalWrite(STCP_PIN, HIGH);
}