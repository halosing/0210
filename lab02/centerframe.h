#ifndef CENTERFRAME_H
#define CENTERFRAME_H
#include <QFrame>
#include <common.h>


class QVBoxLayout;
class QHBoxLayout;
class DrawWidget;
class QGroupBox;
class QPushButton;
class QLineEdit;

class CenterFrame : public QFrame    //用户绘图框架类,本类是一个窗口容器，内含左侧绘图区和右侧功能区，集中管理用户的绘图指令 并将参数传递给DrawWidget类，使之能够正确绘图。

  {
       Q_OBJECT
   public:
      explicit CenterFrame(QWidget *parent=0);


       DrawWidget* insideWidget() const;

   protected:

      void createUserCommandArea();

       void createUI();

       void updateButtonStatus();


   public slots:
      void setPenStyle(int penStyle);
      void setPenWidth(int width=1);
      void setPenColor(QColor color);
      void clearPaint();
     // void savePict();



   protected slots:
       void on_btnRectClicked();
       void on_btnEllipseClicked();
       void on_btnLineClicked();
       void on_btnTriangleClicked();
       void on_btnTextClicked();
       void on_edtTextEdited(const QString &text);
       void on_btnDiamondClicked();
      // void on_btnPictureClicked();
       

   private:
       QVBoxLayout* vLayout;
       QHBoxLayout* hLayout;
       DrawWidget* drawWidget;
       QGroupBox* group;
       QPushButton* btnRect;
       QPushButton* btnEllipse;
       QPushButton* btnLine;
       QPushButton* btnTriangle;
       //QPushButton* btnPicture;
       QPushButton* btnText;
       QLineEdit* edtText;
       QPushButton* btnDiamond;


  };

 #endif // CENTERFRAME_H
