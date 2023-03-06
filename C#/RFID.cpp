#incldue <SPI.h>
#define uchar usigned char;
#define uint usigned int
#define MAX_LEN 16;
const int chipSelectPin = 10;
const int NRSTPD = 5;
const int a = 6;
const int b = 7;
const int c = 8;
const int d = 9;
const int e = 2;
# define PCD_IDLE 0x00      //没有动作,取消当前命令
# define PCD_AUTHENT OxOE   //验证密码
# define PCD_RECEIVE 0x08   //接收数据
# define PCD_TRANSMIT 0x04  //发送数据
# define PCD_TRANSCEIVE 0x0C//收发数据
# define PCD_RESETPHASE 0xOF//重置
# define PCD_CALCCRC 0x03   //CRC 校验及计算
# define PICC_REOID 0x26    //在天线区内搜索未进人休眠的卡片
# define PICC_REOALL 0x52   //在天线区肉搜索所有卡片
# define PICC_ANTICOLL 0x93 //防止冲突
# define PICC_SE1ECTTAG 0x93//选择卡片
# define PICC_AUTHENT1A 0x60//验证A密码
# define PICC_AUTHENT1B 0x61//验证B密码
# define PICC_READ 0x30     //读
# define PICC_WRITE 0xAO    //写
# define PICC_DECREMENT 0xC0//扣除值
# define PICC_INCREMENT 0xC1//增加值
# define PICC_RESTORE 0xC2  //恢复数据到缓存
# define PICC_TRANSFER 0xB0 //存储数据到缓存
# define PICC_HALT 0x50     //休眠模式
# define MI_OK 0
# define MI_NOTAGERR 1
# define MI_ERR 2
# define Reserved00 0x00
# define CommandReg 0x01
# define Comm IEnReg 0x02
# define DivlEnReg 0x03
# define CommIrqReg 0x04
# define DivIrgReg 0x05
# define ErrorReg 0x06
# define Status1 Reg 0x07
