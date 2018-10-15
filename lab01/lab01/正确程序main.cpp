#include <iostream>
#include <QCoreApplication>
#include <QVector>
#include<QDebug>

using namespace std;
typedef struct{
    QString name=""; //定义name变量
    QString stu_num="";
    qint64 subject1;
    qint64 subject2;
    }stu_data;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    stu_data data_1,data_2,data_3,data_4;
    data_1.stu_num="1403130209";data_1.name="鲁智深";data_1.subject1=80;data_1.subject2=72;
    data_2.stu_num="1403140101";data_2.name="林冲";data_2.subject1=82;data_2.subject2=76;
    data_3.stu_num="1403140102";data_3.name="宋江";data_3.subject1=76;data_3.subject2=85;
    data_4.stu_num="1403140103";data_4.name="武松";data_4.subject1=88;data_4.subject2=80;

    QVector<stu_data> data;
    data.push_back(data_1);
    data.push_back(data_2);
    data.push_back(data_3);
    data.push_back(data_4);

  
    qDebug()<<"排序前:\n";
    display(&data);

    QVector<stu_data> sort_name=data;
    sort(sort_name.begin(),sort_name.end(),cmp_name);
    qDebug()<<"通过姓名排序:\n";
    display(&sort_name);


    QVector<stu_data> sort_subject1=data;
    sort(sort_subject1.begin(),sort_subject1.end(),cmp_subject1);
    qDebug()<<"通过课程一排序：\n";
    display(&sort_subject1);

    QVector<stu_data> sort_subject2=data;
    sort(sort_subject2.begin(),sort_subject2.end(),cmp_subject2);
    qDebug()<<"通过课程二排序：\n";
    display(&sort_subject2);
    return a.exec();
}
void display(QVector<stu_data> *data);
bool cmp_name(stu_data a,stu_data b);
bool cmp_subject1(stu_data a,stu_data b);
bool cmp_subject2(stu_data a,stu_data b);
bool cmp_name(stu_data a,stu_data b)
{
   if(a.name>=b.name)
   {
       return 0;
    }
   else
   {
       return 1;
   }
}


bool cmp_subject1(stu_data a,stu_data b)
{
    if(a.subject1>=b.subject1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool cmp_subject2(stu_data a,stu_data b)
{
    if(a.subject2>=b.subject2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(QVector<stu_data> *data)
    
    {
    qDebug()<<"学号"<<"     "<<"姓名"<<"     "<<"课程1"<<"  "<<"课程2\n";
    for(QVector<stu_data>::iterator m = data->begin(); m != data->end(); m++ ){
    qDebug()<<m->stu_num<<"   "<<m->name<<"    "<<m->subject1<<"    "<<m->subject2<<"\n";
    }
    cout<<endl;
    }












