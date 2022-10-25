#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <locale>
#include <math.h>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
string str;
bool flag = false;
QString sos;
QString sos_2;
string boom;
double digit = 0;




string* function_for_QT_delenieUmnozhenie(string str)
{
    string* mass = new string[100];
    int j = 0;
    for (int i = 0; i < mass->size() + 1; i++)
    {
        mass[i] = "";
    }
    for (int i = 0; i < str.length() + 1; i++)
    {
        if (str[i] == '+')
        {
            j++;
            mass[j] = str[i];
            j++;
        }
        else if (str[i] == '-')
        {
            if (i == 0)
            {
                mass[j] = str[i];
            }
            else
            {
                j++;
                mass[j] = str[i];
                j++;
            }

        }
        else if (str[i] == '*')
        {
            j++;
            mass[j] = str[i];
            j++;
        }
        else if (str[i] == '/')
        {
            j++;
            mass[j] = str[i];
            j++;
        }
        else if (str[i] == '%')
        {
            j++;
            mass[j] = str[i];
            j++;
        }
        else
        {
            mass[j] = mass[j] + str[i];
        }
    }


link:;
    for (int i = 0; (i < mass->length() + 2); i++)
    {
        if (mass[i] == "*")
        {
            mass[i - 1] = to_string(stod(mass[i - 1]) * stod(mass[i + 1]));
                for (int b = i + 2; b < 100; b++)
                                {
                                    mass[b - 2] = mass[b];
                                    mass[b] = "";
                                }
                                goto link;
                }
        if (mass[i] == "/")
        {
            mass[i - 1] = to_string(stod(mass[i - 1]) / stod(mass[i + 1]));
            if (i <= mass->length() - 2)
            {
                for (int b = i + 2; b < 100; b++)
                {
                    mass[b - 2] = mass[b];
                    mass[b] = "";
                }
                goto link;
            }
        }
        if (mass[i] == "%")
                {
                    mass[i - 1] = to_string(stoi(mass[i - 1]) % stoi(mass[i + 1]));
                    for (int b = i + 2; b < mass->length(); b++)
                    {
                        mass[b - 2] = mass[b];
                        mass[b] = "";
                    }

                    goto link;
                }
    }
    return mass;
}



double function_for_QT(string str)
{
    string* mass = new string[100];
    mass = function_for_QT_delenieUmnozhenie(str);
    double result = 0;
    int j = 0;
link:;
    if (mass[0] == "-")
    {
        mass[0] = "-" + mass[1];
    }

    for (int i = 0; i < mass->size() + 2; i++)
    {
        if (mass[i] == "+")
        {
            mass[i - 1] = to_string(stod(mass[i - 1]) + stod(mass[i + 1]));
            if (i <= mass->length() - 2)
            {
                for (int b = i + 2; b < 100; b++)
                {
                    mass[b - 2] = mass[b];
                    mass[b] = "";
                }
                goto link;
            }
        }
        else if (mass[i] == "-")
        {
            mass[i - 1] = to_string(stod(mass[i - 1]) - stod(mass[i + 1]));

            if (i <= mass->length() - 2)// ошибка здесь
            {
                for (int b = i + 2; b < 100; b++)
                {
                    mass[b - 2] = mass[b];
                    mass[b] = "";
                }
                goto link;
            }
        }
    }
    result = stod(mass[0]);
    for (int i = 1; i <= (mass->size() - 2); i = i + 2)
    {
        if (mass[i] == "+")
        {
            result = result + stod(mass[i + 1]);
        }
        if (mass[i] == "-")
        {
            result = result - stod(mass[i + 1]);
        }
    }
    return result;
}


double MainWindow::Show()
{

        digit = function_for_QT(str);
        boom = to_string(digit);
        sos_2 = QString::fromStdString(boom);
        ui->label_2->setText(sos_2);
        return digit;
}

void MainWindow::on_pushButton_delit_clicked()
{
    if (flag == true)
    {
 Show();
        str = str + "/";
        sos = QString::fromStdString(str);

        ui->label->setText(sos);


}

}

void MainWindow::on_pushButton_umnozhit_clicked()
{
    if (flag == true)
    {
        Show();
        str = str + "*";
        sos = QString::fromStdString(str);
        ui->label->setText(sos);




        flag = false;

    }
}

void MainWindow::on_pushButton_minus_clicked()
{
    if (flag == true)
    {
 Show();
        str = str + "-";
        sos = QString::fromStdString(str);
        ui->label->setText(sos);




        flag = false;

    }
}

void MainWindow::on_pushButton_plus_clicked()
{
    if (flag == true)
    {
        Show();

        str = str + "+";
        sos = QString::fromStdString(str);
        ui->label->setText(sos);


        flag = false;
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    flag = true;
    str = str + "1";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
}

void MainWindow::on_pushButton_2_clicked()
{
    flag = true;
    str = str + "2";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
}

void MainWindow::on_pushButton_3_clicked()
{
    flag = true;
    str = str + "3";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_4_clicked()
{
    flag = true;
    str = str + "4";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_5_clicked()
{
    flag = true;
    str = str + "5";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_6_clicked()
{
    flag = true;
    str = str + "6";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_7_clicked()
{
    flag = true;
    str = str + "7";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_8_clicked()
{
    flag = true;
    str = str + "8";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_9_clicked()
{
    flag = true;
    str = str + "9";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_0_clicked()
{
    flag = true;
    str = str + "0";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}


void MainWindow::on_pushButton_ravno_clicked()
{
    if (flag == true)
    {
    digit = function_for_QT(str);
    str = to_string(digit);
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
    ui->label_2->setText(sos);
    }
}

void MainWindow::on_pushButton_AC_clicked()
{
    str = "0";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
    ui->label_2->setText(sos);
}

void MainWindow::on_pushButton_plusminus_clicked()
{
    QString labal = ui->label->text();
    digit = labal.toDouble();
    digit = digit * (-1);
    str = to_string(digit);
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
    ui->label_2->setText(sos);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (flag == true)
    {
        str = str + ".";
        sos = QString::fromStdString(str);
        ui->label->setText(sos);
        flag = false;
    }
}

void MainWindow::on_pushButton_procent_clicked()
{
    QString labal = ui->label->text();
    digit = labal.toDouble();
    digit = digit / 100;
    str = to_string(digit);
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
    ui->label_2->setText(sos);
    }
