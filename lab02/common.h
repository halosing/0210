#ifndef COMMON_H
#define COMMON_H

    namespace ST {//ST 命名空间参考
    enum ShapeType {
        None         = 0x00,       //绘制形状的枚举变量 枚举值 None  0x00 曲线  Line  0x01 直线 Rectangle  0x02 矩形 ...
        Line         = 0x01<<0,
        Rectangle    = 0x01<<1,
        Ellipse      = 0x01<<2,
        Triangle     = 0x01<<3,
        Diamond      = 0x01<<4,
        Text         = 0x01<<5,
        TypeMask     = 0x0f
    };
    }

    #define BACKGROUND_COLOR Qt::white
    #define FOREGROUND_COLOR Qt::red


    #endif // COMMON_H
