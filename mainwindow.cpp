#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Player = new QMediaPlayer;
    // audioOutput = new QAudioOutput;

    // Player->setAudioOutput(audioOutput);

    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_Seek_Backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_Seek_Forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->horizontalSlider_Volume->setMinimum(0);
    ui->horizontalSlider_Volume->setMaximum(100);
   // connect(player, &QMediaPlayer::positionChanged, this, ui->Seek);





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Seek_Backward_toggled(bool checked)
{
    cout<<ui->horizontalSlider_Duration->value();
}


void MainWindow::on_pushButton_Play_Pause_clicked()
{

    if(IS_Pause){
        IS_Pause = false;
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

        Player->pause();
    }
    else{


         ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        Player->play();
        IS_Pause = true;
    }

}


void MainWindow::on_pushButton_Stop_clicked()
{

}


void MainWindow::on_pushButton_Seek_Forward_toggled(bool checked)
{

}


void MainWindow::on_pushButton_Volume_clicked()
{
    if(IS_Muted){
       IS_Muted = false;
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    }
    else{

        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        IS_Muted = true;
    }

}


void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{

}


void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{

}





void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select A Video File"),"", "");
    video = new QVideoWidget;
    video->setGeometry(5,5, ui->groupBox->width()-10, ui->groupBox->height()-10);
    video->setParent(ui->groupBox);
    Player->setVideoOutput(video);
    Player->setSource(QUrl(filename));
    video->setVisible(true);
    video->show();
    Player->play();

}

