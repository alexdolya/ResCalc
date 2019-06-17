#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    strips=4;
    f_n=1;
    s_n=0;
    t_n=0;
    tks=500;
    mnoz=0.1;
    dopusk=5;
    nominal=(f_n*100+s_n*10+t_n)*mnoz;
    ui->setupUi(this);
    ui->howManyStripes->addItem("4");
    ui->howManyStripes->addItem("5");
    ui->howManyStripes->addItem("6");
    hide_strip_3();
    hide_strip_6();
    print_nominal();
    ui->label->setText("Alex Dolya, 2019");
}

Widget::~Widget()
{
    delete ui;
}



void Widget::hide_strip_3 ()
{
    ui->stripe1_black_3->setCheckable(false);
    ui->stripe1_black_3->setDisabled(true);
    ui->stripe1_brown_3->setDisabled(true);
    ui->stripe1_red_3->setDisabled(true);
    ui->stripe1_orange_3->setDisabled(true);
    ui->stripe1_yellow_3->setDisabled(true);
    ui->stripe1_green_3->setDisabled(true);
    ui->stripe1_blue_3->setDisabled(true);
    ui->stripe1_purple_3->setDisabled(true);
    ui->stripe1_gray_3->setDisabled(true);
    ui->stripe1_white_3->setDisabled(true);
    ui->stripe_3->hide();
}

void Widget::enable_strip_3()
{
    ui->stripe1_black_3->setCheckable(true);
    ui->stripe1_black_3->setDisabled(false);
    ui->stripe1_brown_3->setDisabled(false);
    ui->stripe1_red_3->setDisabled(false);
    ui->stripe1_orange_3->setDisabled(false);
    ui->stripe1_yellow_3->setDisabled(false);
    ui->stripe1_green_3->setDisabled(false);
    ui->stripe1_blue_3->setDisabled(false);
    ui->stripe1_purple_3->setDisabled(false);
    ui->stripe1_gray_3->setDisabled(false);
    ui->stripe1_white_3->setDisabled(false);
    ui->stripe_3->show();
}

void Widget::hide_strip_6 ()
{
    ui->stripe1_gold_6->setCheckable(false);
    ui->stripe1_gold_6->setDisabled(true);
    ui->stripe1_silver_6->setDisabled(true);
    ui->stripe1_brown_6->setDisabled(true);
    ui->stripe1_red_6->setDisabled(true);
    ui->stripe1_orange_6->setDisabled(true);
    ui->stripe1_yellow_6->setDisabled(true);
    ui->stripe1_blue_6->setDisabled(true);
    ui->stripe1_purple_6->setDisabled(true);
    ui->stripe_6->hide();
}

void Widget::enable_strip_6 ()
{
    ui->stripe1_gold_6->setCheckable(true);
    ui->stripe1_gold_6->setDisabled(false);
    ui->stripe1_silver_6->setDisabled(false);
    ui->stripe1_brown_6->setDisabled(false);
    ui->stripe1_red_6->setDisabled(false);
    ui->stripe1_orange_6->setDisabled(false);
    ui->stripe1_yellow_6->setDisabled(false);
    ui->stripe1_blue_6->setDisabled(false);
    ui->stripe1_purple_6->setDisabled(false);
    ui->stripe_6->show();
}


void  Widget::print_nominal ()
{
    QChar c = 177;
    if (strips==4)
    {
        nominal=(f_n*10+s_n*1)*mnoz;
    }
    else
    {
        nominal=(f_n*100+s_n*10+t_n)*mnoz;
    }

    if (strips==4||strips==5)
    {
        if (nominal<1000000&&nominal>=1000)
        {
            ui->resultOut->setText(QString::number(nominal/1000)+" кОм "+c+QString::number(dopusk)+"%");
        }
        else if (nominal>=1000000)
        {
            ui->resultOut->setText(QString::number(nominal/1000000)+" МОм " +c+QString::number(dopusk)+"%");
        }
        else
        {
            ui->resultOut->setText(QString::number(nominal)+" Ом " +c+QString::number(dopusk)+"%");
        }
    }
    else if (strips==6)
    {
        if (nominal<1000000&&nominal>=1000)
        {
            ui->resultOut->setText(QString::number(nominal/1000)+" кОм "+c+QString::number(dopusk)+"%"+" ТКС "+c+QString::number(tks)+" ppm/C");
        }
        else if (nominal>=1000000)
        {
            ui->resultOut->setText(QString::number(nominal/1000000)+" МОм " +c+QString::number(dopusk)+"%"+" ТКС "+c+QString::number(tks)+" ppm/C");
        }
        else
        {
            ui->resultOut->setText(QString::number(nominal)+" Ом " +c+QString::number(dopusk)+"%"+" ТКС "+c+QString::number(tks)+" ppm/C");
        }
    }


}

void Widget::on_howManyStripes_currentTextChanged(const QString &arg1)
{
    if (arg1=="4")
    {
        strips=4;
        hide_strip_3();
        hide_strip_6();
        print_nominal();
    }
    else if (arg1=="5")
    {
        strips=5;
        enable_strip_3();
        hide_strip_6();
        ui->stripe_3->setStyleSheet("QLabel { background-color : black;  }");
        ui->stripe1_black_3->setChecked(true);
        print_nominal();
    }
    else if (arg1=="6")
    {
        strips=6;
        enable_strip_3();
        enable_strip_6();
        ui->stripe_3->setStyleSheet("QLabel { background-color : black;  }");
        ui->stripe1_black_3->setChecked(true);
        ui->stripe_6->setStyleSheet("QLabel { background-color : gold;  }");
        ui->stripe1_gold_6->setChecked(true);
        print_nominal();
    }

}

//первая полоса

void Widget::on_stripe1_brown_clicked()
{
    f_n=1;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : brown;  }");
}

void Widget::on_stripe1_red_clicked()
{
    f_n=2;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : red;  }");
}

void Widget::on_stripe1_orange_clicked()
{
    f_n=3;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : orange;  }");
}

void Widget::on_stripe1_yellow_clicked()
{
    f_n=4;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : yellow;  }");
}

void Widget::on_stripe1_green_clicked()
{
    f_n=5;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : green;  }");
}

void Widget::on_stripe1_blue_clicked()
{
    f_n=6;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : blue;  }");
}

void Widget::on_stripe1_purple_clicked()
{
    f_n=7;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : purple;  }");
}

void Widget::on_stripe1_gray_clicked()
{
    f_n=8;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : gray;  }");
}

void Widget::on_stripe1_white_clicked()
{
    f_n=9;
    print_nominal();
    ui->stripe_1->setStyleSheet("QLabel { background-color : white;  }");
}

//вторая полоса

void Widget::on_stripe1_black_2_clicked()
{
    s_n=0;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : black;  }");
}

void Widget::on_stripe1_brown_2_clicked()
{
    s_n=1;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : brown;  }");
}

void Widget::on_stripe1_red_2_clicked()
{
    s_n=2;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : red;  }");
}

void Widget::on_stripe1_orange_2_clicked()
{
    s_n=3;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : orange;  }");
}

void Widget::on_stripe1_yellow_2_clicked()
{
    s_n=4;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : yellow;  }");
}

void Widget::on_stripe1_green_2_clicked()
{
    s_n=5;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : green;  }");
}

void Widget::on_stripe1_blue_2_clicked()
{
    s_n=6;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : blue;  }");
}

void Widget::on_stripe1_purple_2_clicked()
{
    s_n=7;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : purple;  }");
}

void Widget::on_stripe1_gray_2_clicked()
{
    s_n=8;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : gray;  }");
}

void Widget::on_stripe1_white_2_clicked()
{
    s_n=9;
    print_nominal();
    ui->stripe_2->setStyleSheet("QLabel { background-color : white;  }");
}

//третья полоса

void Widget::on_stripe1_black_3_clicked()
{
    t_n=0;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : black;  }");
}

void Widget::on_stripe1_brown_3_clicked()
{
    t_n=1;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : brown;  }");
}

void Widget::on_stripe1_red_3_clicked()
{
     t_n=2;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : red;  }");
}

void Widget::on_stripe1_orange_3_clicked()
{
    t_n=3;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : orange;  }");
}

void Widget::on_stripe1_yellow_3_clicked()
{
    t_n=4;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : yellow;  }");
}

void Widget::on_stripe1_green_3_clicked()
{
    t_n=5;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : green;  }");
}

void Widget::on_stripe1_blue_3_clicked()
{
    t_n=6;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : blue;  }");
}

void Widget::on_stripe1_purple_3_clicked()
{
    t_n=7;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : purple;  }");
}

void Widget::on_stripe1_gray_3_clicked()
{
    t_n=8;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : gray;  }");
}

void Widget::on_stripe1_white_3_clicked()
{
    t_n=8;
    print_nominal();
    ui->stripe_3->setStyleSheet("QLabel { background-color : white;  }");
}

//четвертая полоса

void Widget::on_stripe4_gold_4_clicked()
{
    mnoz=0.1;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : gold;  }");
}

void Widget::on_stripe4_silver_4_clicked()
{
    mnoz=0.01;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : silver;  }");
}

void Widget::on_stripe1_black_4_clicked()
{
    mnoz=1;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : black;  }");
}

void Widget::on_stripe1_brown_4_clicked()
{
    mnoz=10;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : brown;  }");
}

void Widget::on_stripe1_red_4_clicked()
{
    mnoz=100;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : red;  }");
}

void Widget::on_stripe1_orange_4_clicked()
{
    mnoz=1000;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : orange;  }");
}

void Widget::on_stripe1_yellow_4_clicked()
{
    mnoz=10000;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : yellow;  }");
}

void Widget::on_stripe1_green_4_clicked()
{
    mnoz=100000;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : green;  }");
}

void Widget::on_stripe1_blue_4_clicked()
{
    mnoz=1000000;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : blue;  }");
}

void Widget::on_stripe1_purple_4_clicked()
{
    mnoz=10000000;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : purple;  }");
}

void Widget::on_stripe1_gray_4_clicked()
{
    mnoz=100000000;
    print_nominal();
    ui->stripe_4->setStyleSheet("QLabel { background-color : gray;  }");
}

//пятая полоса

void Widget::on_stripe1_gold_5_clicked()
{
    dopusk=5;
    print_nominal();
    ui->stripe_5->setStyleSheet("QLabel { background-color : gold;  }");
}

void Widget::on_stripe1_silver_5_clicked()
{
    dopusk=10;
    print_nominal();
    ui->stripe_5->setStyleSheet("QLabel { background-color : silver;  }");
}

void Widget::on_stripe1_brown_5_clicked()
{
    dopusk=1;
    print_nominal();
    ui->stripe_5->setStyleSheet("QLabel { background-color : brown;  }");
}

void Widget::on_stripe1_red_5_clicked()
{
    dopusk=2;
    print_nominal();
    ui->stripe_5->setStyleSheet("QLabel { background-color : red;  }");
}

void Widget::on_stripe1_green_5_clicked()
{
    dopusk=0.5;
    print_nominal();
    ui->stripe_5->setStyleSheet("QLabel { background-color : green;  }");
}

void Widget::on_stripe1_blue_5_clicked()
{
    dopusk=0.25;
    print_nominal();
    ui->stripe_5->setStyleSheet("QLabel { background-color : blue;  }");
}

void Widget::on_stripe1_purple_5_clicked()
{
    dopusk=0.1;
    print_nominal();
    ui->stripe_5->setStyleSheet("QLabel { background-color : purple;  }");
}

void Widget::on_stripe1_gray_5_clicked()
{
    dopusk=0.05;
    print_nominal();
    ui->stripe_5->setStyleSheet("QLabel { background-color : gray;  }");
}

//шестая полоса полоса

void Widget::on_stripe1_gold_6_clicked()
{
    tks=500;
    print_nominal();
    ui->stripe_6->setStyleSheet("QLabel { background-color : gold;  }");
}

void Widget::on_stripe1_silver_6_clicked()
{
    tks=1000;
    print_nominal();
    ui->stripe_6->setStyleSheet("QLabel { background-color : silver;  }");

}

void Widget::on_stripe1_brown_6_clicked()
{
    tks=100;
    print_nominal();
    ui->stripe_6->setStyleSheet("QLabel { background-color : brown;  }");
}

void Widget::on_stripe1_red_6_clicked()
{
    tks=50;
    print_nominal();
    ui->stripe_6->setStyleSheet("QLabel { background-color : red;  }");
}

void Widget::on_stripe1_orange_6_clicked()
{
    tks=15;
    print_nominal();
    ui->stripe_6->setStyleSheet("QLabel { background-color : orange;  }");
}

void Widget::on_stripe1_yellow_6_clicked()
{
    tks=25;
    print_nominal();
    ui->stripe_6->setStyleSheet("QLabel { background-color : yellow;  }");
}

void Widget::on_stripe1_blue_6_clicked()
{
    tks=10;
    print_nominal();
    ui->stripe_6->setStyleSheet("QLabel { background-color : blue;  }");
}

void Widget::on_stripe1_purple_6_clicked()
{
    tks=5;
    print_nominal();
    ui->stripe_6->setStyleSheet("QLabel { background-color : purple;  }");
}
