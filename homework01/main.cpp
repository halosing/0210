#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <vector>
#define s 0x12345678                                                   //给定32位无符号整型数
#define MAX(x,y) ( ((x) > (y)) ? (x) : (y) )                           //宏实现返回最大值
#define MIN(x,y) ( ((x) < (y)) ? (x) : (y) )                           //宏实现返回最大值
typedef quint32 word;                                                  //用typedef说明32位无符号数新类型为word
typedef quint8  byte;                                                  //用typedef说明8位无符号数新类型为byte

#define HHI(xxx) ((byte) ((word)(xxx) >> 24))                          //取出最高位
#define LHI(xxx) ((byte) ((word)(xxx) >> 16))                          //取出次高位
#define HLO(xxx) ((byte) ((word)(xxx) >> 8))                           //取出次低位
#define LLO(xxx) ((byte) ((word)(xxx) & 255))                          //取出最低位

int main()
{
    QList<byte> values;
    values<<HHI(s)<<LHI(s)<<HLO(s)<<LLO(s);                           //将结果存入Qlist<quint>对象values中
    qDebug()<<"原始值:0x12345678=="<<s;
    qDebug("0x12==%d 0x34==%d 0x56==%d 0x78==%d",
          values.at(0),values.at(1),values.at(2),values.at(3));
    qDebug("最高8位和次高8位最大值:0x%x(%d)",                            //调用宏比较输出最大值
           MAX(HHI(s),LHI(s)),MAX(HHI(s),LHI(s)));
    qDebug("次低8位和最低8位最小值:0x%x(%d)",
           MIN(HLO(s),LLO(s)),MIN(HLO(s),LLO(s)));                   //调用宏比较输出最小值

    word csm;
    csm=HLO(s)<<24|HHI(s)<<16|LLO(s)<<8|LHI(s);                     //重新组成新数

    qDebug("重新组合后数值:0x%x(%d)",csm,csm);                        //由题中给定顺序组合成新32位无符号整型数输出

    qDebug()<<"排序前:"<<values;
    std::sort(values.begin(),values.end(),std::greater<byte>());   //调用stdsort函数使用大于运算符进行比较排序
    qDebug()<<"排序后:"<<values;
}