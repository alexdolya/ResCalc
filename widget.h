#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDir>
#include <QPixmap>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:


    void hide_strip_3 ();

    void enable_strip_3 ();

    void hide_strip_6 ();

    void enable_strip_6 ();

    void print_nominal ();

    //первая полоса

    void on_stripe1_orange_clicked();

    void on_stripe1_yellow_clicked();

    void on_stripe1_green_clicked();

    void on_stripe1_red_clicked();

    void on_stripe1_brown_clicked();

    void on_stripe1_blue_clicked();

    void on_stripe1_purple_clicked();

    void on_stripe1_gray_clicked();

    void on_stripe1_white_clicked();

    //вторая полоса

    void on_stripe1_black_2_clicked();

    void on_stripe1_brown_2_clicked();

    void on_stripe1_red_2_clicked();

    void on_stripe1_orange_2_clicked();

    void on_stripe1_yellow_2_clicked();

    void on_stripe1_green_2_clicked();

    void on_stripe1_blue_2_clicked();

    void on_stripe1_purple_2_clicked();

    void on_stripe1_gray_2_clicked();

    void on_stripe1_white_2_clicked();

    //третья полоса

    void on_stripe1_black_3_clicked();

    void on_stripe1_brown_3_clicked();

    void on_stripe1_red_3_clicked();

    void on_stripe1_orange_3_clicked();

    void on_stripe1_yellow_3_clicked();

    void on_stripe1_green_3_clicked();

    void on_stripe1_blue_3_clicked();

    void on_stripe1_purple_3_clicked();

    void on_stripe1_gray_3_clicked();

    void on_stripe1_white_3_clicked();

    void on_howManyStripes_currentTextChanged(const QString &arg1);

    void on_stripe4_gold_4_clicked();

    void on_stripe4_silver_4_clicked();

    void on_stripe1_black_4_clicked();

    void on_stripe1_brown_4_clicked();

    void on_stripe1_red_4_clicked();

    void on_stripe1_orange_4_clicked();

    void on_stripe1_yellow_4_clicked();

    void on_stripe1_green_4_clicked();

    void on_stripe1_blue_4_clicked();

    void on_stripe1_purple_4_clicked();

    void on_stripe1_gray_4_clicked();

    void on_stripe1_gold_5_clicked();

    void on_stripe1_silver_5_clicked();

    void on_stripe1_brown_5_clicked();

    void on_stripe1_red_5_clicked();

    void on_stripe1_green_5_clicked();

    void on_stripe1_blue_5_clicked();

    void on_stripe1_purple_5_clicked();

    void on_stripe1_gray_5_clicked();

    void on_stripe1_gold_6_clicked();

    void on_stripe1_silver_6_clicked();

    void on_stripe1_brown_6_clicked();

    void on_stripe1_red_6_clicked();

    void on_stripe1_orange_6_clicked();

    void on_stripe1_yellow_6_clicked();

    void on_stripe1_blue_6_clicked();

    void on_stripe1_purple_6_clicked();

private:
    Ui::Widget *ui;
    int strips;
    double nominal, f_n, s_n, t_n, mnoz, dopusk, tks ;
};

#endif // WIDGET_H
