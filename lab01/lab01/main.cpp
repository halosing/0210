#include <QCoreApplication>
#include <QDebug>
#include <QString>
using namespace std;

class student
{
public:
    QString name; //定义变量
    qint32 num; 
    qint16 test1;
    qint16 test2;

    friend QDebug operator<<(QDebug dbg,const student &s) //重载QDebug
    {
        dbg<<s.name<<s.num<<s.test1<<s.test2;
        return dbg;

    }

};
bool comp1(const student &v1,const student &v2)    //对数组名字排序的定义
{
    return v1.name>v2.name;
}

bool comp2(const student &v1,const student &v2 )   //对数组学号排序的定义
{
    return v1.num>v2.num;
}

bool comp3(const student &v1,const student &v2)    //对数组课程1排序的定义
{
    return v1.test1>v2.test1;
}

bool comp4(const student &v1,const student &v2)    //对数组课程2排序的定义
{
    return v1.test2>v2.test2;
}


int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);
    student w[4];

    w[0].name="鲁智深";w[0].num=1403130209;w[0].test1=80;w[0].test2=72;  //根据题目输入数据
    w[1].name="林冲";w[1].num=1403140101;w[1].test1=82;w[1].test2=80;
    w[2].name="宋江";w[2].num=1403140102;w[2].test1=76;w[2].test2=85;
    w[3].name="武松";w[3].num=1403140103;w[3].test1=88;w[3].test2=89;

    QList<student> v;
    v.append(w[0]);  //分配空间
    v.append(w[1]);
    v.append(w[2]);
    v.append(w[3]);
    qDebug()<<"排序之前: ";  //排序输出
    for(int i=0;i<4;i++)
    {
        qDebug().noquote()<<w[i];
    }
    qDebug()<<"通过名字排序: ";
    std::sort(v.begin(),v.end(),comp1);  //调用comp1函数实现名字排序
    for(int i=0;i<4;i++)
    {
        qDebug().noquote()<<v[i];        //输出新的排序顺序
    }
    qDebug()<<"通过学号排序: ";
    std::sort(v.begin(),v.end(),comp2);  //调用comp2函数实现学号排序
    for(int i=0;i<4;i++)
    {
        qDebug().noquote()<<v[i];        //输出新的排序顺序
    }

    qDebug()<<"通过课程1排序: ";
    std::sort(v.begin(),v.end(),comp3);  //调用comp3函数实现课程一排序
    for(int i=0;i<4;i++)
    {
        qDebug().noquote()<<v[i];       //输出新的排序顺序
    }

    qDebug()<<"通过课程2排序: ";
    std::sort(v.begin(),v.end(),comp4); //调用comp4函数实现课程2排序
    for(int i=0;i<4;i++)
    {
        qDebug().noquote()<<v[i];       //输出新的排序顺序
    }


    return a.exec();

}













