#include "centerframe.h"
#include "drawwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QGridLayout>
#include <QLineEdit>
#include <QDebug>

CenterFrame::CenterFrame(QWidget *parent) : QFrame(parent)
{
    // 创建用户命令区
    createUserCommandArea();  //创建用户区中心窗口 参数 parent 对窗口指针 该函数的主要任务是创建用户界面，构造用户绘图区和用户命令区

    // 创建界面
    createUI();
}

DrawWidget *CenterFrame::insideWidget() const  //获取绘图区绘图对象的指针 返回绘图区对象指针
{
    return drawWidget;
}


void CenterFrame::createUserCommandArea()  //创建绘图框的用户命令区 该函数创建用户界面中的右侧绘图功能区的按键按键使用QPushButton，根据功能需要创建相应的按键， 按键使用的图标，由QPainter绘制出来，图形距离图标边框3px

//界面的设计遵循以下过程： 创建控件(并设置属性) -> 创建布局 ->在布局中添加控件 ->在其他布局中添加该布局(或设置为父窗口的布局) 整个过程由内到外，一步一步完成。

{

    // 选项Group
    group = new QGroupBox(this);
    group->setTitle(tr("选项"));

    int btnWidth=32;
    int btnHeight=32;
    // 准备绘制按钮图标
    QPixmap p(btnWidth-2, btnHeight-2);
    QPainter painter(&p);
    QPen pen(BACKGROUND_COLOR);
    pen.setWidthF(2);
    pen.setStyle(Qt::DotLine);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);

    // 矩形按钮
    btnRect = new QPushButton(group);
    btnRect->setToolTip("绘制矩形");
    btnRect->setCheckable(true);
    btnRect->setIconSize(p.size());
    connect(btnRect,&QPushButton::clicked,
            this,&CenterFrame::on_btnRectClicked);

    p.fill(FOREGROUND_COLOR);
    painter.drawRect(3,3,p.size().width()-2*3,p.size().height()-2*3);
       btnRect->setIcon (QIcon(p));

       // 圆形按钮
       btnEllipse = new QPushButton(group);
       btnEllipse->setToolTip("绘制圆形");
       btnEllipse->setCheckable(true);
       btnEllipse->setIconSize(p.size());

       p.fill(FOREGROUND_COLOR);
       painter.drawEllipse(3,3,p.size().width()-2*3,p.size().height()-2*3);
       btnEllipse->setIcon (QIcon(p));
       connect(btnEllipse,&QPushButton::clicked,
               this,&CenterFrame::on_btnEllipseClicked);

       // 直线按钮
       btnLine = new QPushButton(group);
       btnLine->setToolTip("绘制直线");
       btnLine->setCheckable(true);
       btnLine->setIconSize(p.size());

       p.fill(FOREGROUND_COLOR);
       painter.drawLine(3+3,p.size().height()-2*3,p.size().width()-2*3,3+3);
       btnLine->setIcon (QIcon(p));
       connect(btnLine,&QPushButton::clicked,
               this,&CenterFrame::on_btnLineClicked);

       // 三角形
       btnTriangle = new QPushButton(group);
       btnTriangle->setToolTip("绘制三角形");
       btnTriangle->setCheckable(true);
       btnTriangle->setIconSize(p.size());

       p.fill(FOREGROUND_COLOR);
       // 三角形的三个顶点
       QPointF pt1(3,p.size().height()-3);
       QPointF pt2(p.size().width()/2,3);
       QPointF pt3(-3+p.size().width(),-3+p.size().height());
       QVector<QPointF> pts;
       pts<<pt1<<pt2<<pt2<<pt3<<pt3<<pt1;

       // 使用drawLines时需要注意，点数必须为偶数，两两成对作为一个边
      // 如果是奇数，最后一个点会被舍弃
      painter.drawLines(pts);
      btnTriangle->setIcon (QIcon(p));
      connect(btnTriangle,&QPushButton::clicked,
              this,&CenterFrame::on_btnTriangleClicked);

      // 文本按钮
      btnText = new QPushButton(group);
      btnText->setToolTip("绘制文本");
      btnText->setCheckable(true);
      btnText->setIconSize(p.size());

      p.fill(FOREGROUND_COLOR);
      QFont font = painter.font();
      font.setFamily("Modern No. 20");
      font.setPixelSize(26);
      painter.setFont(font);

      painter.drawText(p.rect(),Qt::AlignCenter,"T");
      btnText->setIcon (QIcon(p));
      connect(btnText,&QPushButton::clicked,
              this,&CenterFrame::on_btnTextClicked);

      //菱形按钮

       btnDiamond =new QPushButton(group);

       btnDiamond->setToolTip("绘制菱形");

       btnDiamond->setCheckable(true);

       btnDiamond->setIconSize(p.size());

       //菱形的四个顶点

       p.fill(FOREGROUND_COLOR);

       QPointF p1(p.size().width()/2,3);

       QPointF p2(3,p.size().height()/2);

       QPointF p3(p.size().width()/2,p.size().height()-3/2);

       QPointF p4(p.size().width()-3,p.size().height()/2);

       QVector<QPointF> p0;

       p0<<p1<<p2<<p2<<p3<<p3<<p4<<p4<<p1;

       painter.drawPolygon(p0);

       btnDiamond->setIcon (QIcon(p));

       connect(btnDiamond,&QPushButton::clicked,

               this,&CenterFrame::on_btnDiamondClicked);


     //图片按钮
     btnPicture= new QPushButton(group); //新建btnPicture
     btnPicture->setCheckable(true); //将图片按钮设为两种状态的按钮
     btnPicture->setIconSize(p.size());
     btnPicture->setToolTip("绘制需要添加的图片");
     QPixmap pixmap(p.size());
     QPainter paint(&pixmap);
     QImage image("D:/protect/res/picture02.jpg");     //用QImage读取图片
     QRect targetRect(0,0,p.size().width(),p.size().height());
     QRect sourceRect =image.rect();
     paint.drawImage(targetRect,image,sourceRect);
       connect(btnPicture,&QPushButton::clicked,
            this,&CenterFrame::on_btnPictureClicked);
       btnPicture->setIcon(QIcon(pixmap));

              // 选项Group布局
      QGridLayout *gridLayout = new QGridLayout();
      gridLayout->addWidget(btnRect,0,0);
      gridLayout->addWidget(btnEllipse,0,1);
      gridLayout->addWidget(btnTriangle,1,0);
      gridLayout->addWidget(btnLine,1,1);
      gridLayout->addWidget(btnText,2,0);
      gridLayout->addWidget(btnDiamond,2,1);  //添加菱形按钮
      gridLayout->addWidget(btnPicture,3,0); //添加图片按钮
      gridLayout->setMargin(3);
      gridLayout->setSpacing(3);
      group->setLayout(gridLayout);

  }


  void CenterFrame::createUI()     //创建用户界面 该函数创建一个用户绘图区，并将用户命令区添加进来， 最后统一使用QSS设置按键外观， 对控件外观的设置，程序控制较为繁琐，一般多使用QSS进行。 具体风格设置方法，请参阅Qt文档：Qt Style Sheets Reference

  {

      edtText = new QLineEdit();
      edtText->setToolTip(tr("输入需要绘制的文本"));   // 设置工具提示
       edtText->setVisible(false);                     //  初始时，文本框设为隐藏
       edtText->setClearButtonEnabled(true);           //  在编辑框中显示一个清除按键
       edtText->setMaximumWidth(91);
       // textEdited信号与textChanged信号类似，
       // 区别是前者只在外部编辑时发出，setText等内部函数修改文本时，该信号不会发射
       // textChanged信号只要是文本发生变化都会反射，无论是否是内部函数修改
       connect(edtText,&QLineEdit::textEdited,
               this,&CenterFrame::on_edtTextEdited);   // 连接文本输入时的处理槽函数
       // 右侧垂直布局
       vLayout = new QVBoxLayout();
       vLayout->addWidget(group);
       vLayout->addWidget(edtText);
       vLayout->addStretch();
       vLayout->setMargin(5);


       // 创建绘图区
       drawWidget = new DrawWidget(this);    //新建一个drawWidget对象

       //水平布局
       hLayout = new QHBoxLayout();
       hLayout->addWidget(drawWidget);
       hLayout->addLayout(vLayout);
       hLayout->setStretch(0,1);
       hLayout->setStretch(1,0);
       hLayout->setMargin(0);
       hLayout->setSpacing(0);

       setLayout(hLayout);


       // 使用QSS设置按键的风格
       // 具体风格设置，请参阅Qt文档：Qt Style Sheets Reference
       QString myStyleSheet =
               "QPushButton  { "
                   "background-color: none;"
                   "border-style: flat;"
                   "border-width: 1px;"
                   "border-radius: 3px;"
                   "border-color: #8f8f91;"
                   "min-width: 32px;"
                   "min-Height: 32px;"
                   "padding: 2px;"
               "}"
               "QPushButton:checked {"
                   "background-color: #b7bfcc;"
               "}"
               "QPushButton:hover {"
                   "border-style: outset;"
               "}";
       setStyleSheet(myStyleSheet);

   }

   void CenterFrame::updateButtonStatus()//更新按键状态 功能框的按键按下后，设置了一个标志，可以通过该标志实现统一更新按键状态

   {
       // 首先将所有按键复位
       btnRect->setChecked(false);
       btnLine->setChecked(false);
       btnTriangle->setChecked(false);
       btnEllipse->setChecked(false);
       btnText->setChecked(false);
       edtText->setVisible(false);
       btnPicture->setChecked(false);//新加按钮复位

       // 然后根据设置的绘图类型重新切换按键状态
       switch (drawWidget->shapeType()) {
       case ST::Rectangle:
           btnRect->setChecked(true);
           break;
       case ST::Line:
           btnLine->setChecked(true);
           break;
       case ST::Ellipse:
           btnEllipse->setChecked(true);
           break;
       case ST::Triangle:
           btnTriangle->setChecked(true);
           break;
       case ST::Diamond:
           btnDiamond->setChecked(true);
           break;
       case ST::Text:
           btnText->setChecked(true);
           edtText->setVisible(true);      // 使编辑框可见
           edtText->setFocus();            // 编辑框获得输入焦点
           break;
       case ST::Pict:
           btnPicture->setChecked(true);
           break;
           default:
        break;

       }
   }

   void CenterFrame::setPenStyle(int penStyle)  //改变画笔风格  参数penStyle 新的画笔风格 直接调用DrawWidget成员函数设置新风格

   {
       drawWidget->setStyle(penStyle);
   }

   void CenterFrame::setPenWidth(int width)//改变画笔宽度 参数 width 新的画笔宽度 直接调用DrawWidget成员函数设置新宽度

   {
       drawWidget->setWidth(width);
   }

   void CenterFrame::setPenColor(QColor color)  //改变画笔颜色 参数 color 新的画笔颜色 直接调用DrawWidget成员函数设置新颜色

   {
       drawWidget->setColor(color);
   }

   void CenterFrame::clearPaint()   //清除当前绘图 直接调用DrawWidget成员函数清除当前绘图

   {
       drawWidget->clear();
   }
   //void CenterFrame::savePict()
// {
   // drawWidget->save();
 //}



   void CenterFrame::on_btnRectClicked()  //绘制矩形按键响应槽函数 该函数的主要任务有2个， 1、设置界面按键状态，其他按键需要恢复未选定状态 2、设置绘制图形类别为矩形(ST::Rectangle

   {
       if(btnRect->isChecked()){
           updateButtonStatus();
           drawWidget->setShapeType(ST::Rectangle);
       }else{
           drawWidget->setShapeType(ST::None);
       }

   }


   void CenterFrame::on_btnEllipseClicked()   //绘制圆形按键响应槽函数 该函数与矩形响应槽函数功能基本类似， 1、设置界面按键状态，其他按键需要恢复未选定状态 2、设置绘制图形类别为圆形(ST::Ellipse)

   {
       if(btnEllipse->isChecked()){
           drawWidget->setShapeType(ST::Ellipse);
           updateButtonStatus();
       }else{
           drawWidget->setShapeType(ST::None);
       }

   }
   void CenterFrame::on_btnLineClicked()  //绘制直线按键响应槽函数 该函数与矩形响应槽函数功能基本类似， 1、设置界面按键状态，其他按键需要恢复未选定状态 2、设置绘制图形类别为直线(ST::Line)

   {
       if(btnLine->isChecked()){
           drawWidget->setShapeType(ST::Line);
           updateButtonStatus();
       }else{
           drawWidget->setShapeType(ST::None);
       }
   }


   void CenterFrame::on_btnTriangleClicked()   //绘制三角形按键响应槽函数 该函数与矩形响应槽函数功能基本类似， 1、设置界面按键状态，其他按键需要恢复未选定状态 2、设置绘制图形类别为矩形(ST::Triangle)

   {
       if(btnTriangle->isChecked()){
           drawWidget->setShapeType(ST::Triangle);
           updateButtonStatus();
       }else{
           drawWidget->setShapeType(ST::None);
       }
   }

   void CenterFrame::on_btnPictureClicked()   //绘制图片响应槽函数

 {
 if(btnPicture->isChecked()){
    drawWidget->pict() ;
    updateButtonStatus();
  }else{
    drawWidget->setShapeType(ST::None);
 }
   }

   void CenterFrame::on_btnTextClicked()  //绘制文本按键响应槽函数 该函数除包括矩形响应槽函数的基本功能外，需要设定用户输入文本框的状态 1、设置界面按键状态，其他按键需要恢复未选定状态 2、设置绘制图形类别为矩形(ST::Triangle) 3、显示或隐藏文本框，并使文本框在显示时获得输入焦点

   {

       if(btnText->isChecked()){
           drawWidget->setShapeType(ST::Text);
           updateButtonStatus();
       }else{
           drawWidget->setShapeType(ST::None);
       }
   }

   void CenterFrame::on_btnDiamondClicked()

    {

        if(btnDiamond->isChecked()){

            drawWidget->setShapeType(ST::Diamond);



            updateButtonStatus();

        }else{

            drawWidget->setShapeType(ST::None);

        }

    }
   void CenterFrame::on_edtTextEdited(const QString &text)  //输入文本响应槽函数 参数text 文本内容

   {
       drawWidget->setDrawnText(text);
   }











































































































































































































































































































































