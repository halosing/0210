#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>

namespace SK {       //定义命名空间为SK
enum SortKind{       //将数据分为不同列
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}


typedef struct{
    QStringList stud_Data;//结构定义
} studData;

QDebug operator<< (QDebug d, const studData &data) 
{
    for(int i=1;i<=data.stud.size();i++)    // 补全运算符重载函数，使其可以直接输出studData结构
    {
    	 d.noquote().nospace()<<QString(data.stud_Data.at(i))<<"\t" ;
    }
    return d;
}

// 比较列位置，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)    //重载规则，switch与上面的enum匹配
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
        case SK::col01: result=d1.stud_Data.at(1)>d2.stud_Data.at(1);   break;
        case SK::col02: result=d1.stud_Data.at(2)>d2.stud_Data.at(2);   break;
        case SK::col03: result=d1.stud_Data.at(3)>d2.stud_Data.at(3);   break;
        case SK::col04: result=d1.stud_Data.at(4)>d2.stud_Data.at(4);   break;
        case SK::col05: result=d1.stud_Data.at(5)>d2.stud_Data.at(5);   break;
        case SK::col06: result=d1.stud_Data.at(6)>d2.stud_Data.at(6);   break;
        case SK::col07: result=d1.stud_Data.at(7)>d2.stud_Data.at(7);   break;
        case SK::col08: result=d1.stud_Data.at(8)>d2.stud_Data.at(8);   break;
        case SK::col09: result=d1.stud_Data.at(9)>d2.stud_Data.at(9 );  break;
        case SK::col10: result=d1.stud_Data.at(10)>d2.stud_Data.at(10); break;
        case SK::col11: result=d1.stud_Data.at(11)>d2.stud_Data.at(11); break;
        case SK::col12: result=d1.stud_Data.at(12)>d2.stud_Data.at(12); break;
        case SK::col13: result=d1.stud_Data.at(13)>d2.stud_Data.at(13); break;
        case SK::col14: result=d1.stud_Data.at(14)>d2.stud_Data.at(14); break;
        case SK::col15: result=d1.stud_Data.at(15)>d2.stud_Data.at(15); break;
        case SK::col16: result=d1.stud_Data.at(16)>d2.stud_Data.at(16); break;
        case SK::col17: result=d1.stud_Data.at(17)>d2.stud_Data.at(17); break;
        case SK::col18: result=d1.stud_Data.at(18)>d2.stud_Data.at(18); break;
        case SK::col19: result=d1.stud_Data.at(19)>d2.stud_Data.at(19); break;
        case SK::col20: result=d1.stud_Data.at(20)>d2.stud_Data.at(20); break;
        case SK::col21: result=d1.stud_Data.at(21)>d2.stud_Data.at(21); break;
        case SK::col22: result=d1.stud_Data.at(22)>d2.stud_Data.at(22); break;
        case SK::col23: result=d1.stud_Data.at(23)>d2.stud_Data.at(23 );break;
        case SK::col24: result=d1.stud_Data.at(24)>d2.stud_Data.at(24 );break;
        case SK::col25: result=d1.stud_Data.at(25)>d2.stud_Data.at(25 );break;
        case SK::col26: result=d1.stud_Data.at(26)>d2.stud_Data.at(26 );break;
        case SK::col27: result=d1.stud_Data.at(27)>d2.stud_Data.at(27 );break;
        case SK::col28: result=d1.stud_Data.at(28)>d2.stud_Data.at(28 );break;
        case SK::col29: result=d1.stud_Data.at(29)>d2.stud_Data.at(29 );break;
        case SK::col30: result=d1.stud_Data.at(30)>d2.stud_Data.at(30 );break;
        case SK::col31: result=d1.stud_Data.at(31)>d2.stud_Data.at(31 );break;
        case SK::col32: result=d1.stud_Data.at(32)>d2.stud_Data.at(32 );break;
    
    }
    return result;

}


class ScoreSorter  //此类完成读取数据、排序输出
{
public:
    ScoreSorter(QString dataFile); //定义ScoreSorter构造函数
    void readFile();               //定义读取文件函数
    void doSort();                 //定义排序函数
   
	QStringList  Listtitle;        //数据表头
	QString FileName;              //定义变量
    QList<studData>   data;        //数据
    
}；

ScoreSorter::ScoreSorter(QString dataFile)  //带参数scoresorter构造函数
{
    FileName=dataFile;                      //初始化成员
}

void ScoreSorter::readFile()       //读文件函数
    {
    QFile F(this→FileName);  //参考QT助手
    if (!F.open(QIODevice::ReadOnly | QIODevice::Text))
    {
    	qDebug().noquote().nospace()<<"文件打开失败"<<endl;
    	return ;
    }
    QDebug().noquote().nospace()<<"开始读取文件"<<FileName;

    studData momentdata;
    QString Ltitile(file.readLine());    //读取整行 
    this→Listtitile=Ltitile.split(" "，QString::SkipEmptyParts);   //按空格方式读取
   
    while(!F.atEnd())
    {
    	QString sh(F.readLine());
    	momentdata.stud_Data=sh.split(" ",QString::SkipEmptyParts);
    	if((momentdata.stud_Data).last()=="\n")
    	{
    		momentdata.stud_Data.removeLast();   //读数据
    	}
    	if(momentdata.stud_Data) 
    	continue;
    	this→data.append(momentdata);  //加数据到data
    }
    F.close();
    qDebug()<<Listtitile.size();
    qDebug().noquote().nospace()<<"读取文件完成"<<FileName；
    }
    

void ScoreSorter::doSort()         //排序输出函数
{
	for(int i=1;i<this→Listtitile.size();i++)
	{
		myCmp thcmp(i-1);     //初始化排序对象
		std::sort(data.begin(),data.end(),thcmp);
		qDebug().noquote().nospace()<<"排序之后输出数据，目前排序第"<<i<<"列："
		qDebug()<<"     "(this→Listtitile);   //输出表头
		for(int i=0;i<this→Listtitile.size();i++)
		{
		  qDebug()<<data.ai(i);
		  qDebug()<<"-------------------------------------------------------\n";
		}
	}

}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)    //参考Qt助手
{
    QString txtMessage;
    txtMessage = data.ai(i);
    txtMessage += QString("\r\n");

    QFile F("D:\\sorted_data.txt");
    if(F.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream out(&F);
        out<<txtMessage;
    }
    file.flush();
    file.close();
}

int main()
{
    qInstallMessageHandler(myMessageOutput);///注册MsgHandler回调函数

    QString datafile = "D：\\data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);  //调用带参构造函数初始化
    s.readFile();             //调用readFile函数读数据文件
    s.doSort();               //调用doSort函数排序和输出
    return 0;
}
