#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtMultimediaWidgets>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_pushButton_Seek_Backward_toggled(bool checked);

    void on_pushButton_Play_Pause_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_Seek_Forward_toggled(bool checked);

    void on_pushButton_Volume_clicked();

    void on_horizontalSlider_Volume_valueChanged(int value);

    void on_horizontalSlider_Duration_valueChanged(int value);

    void on_actionOpen_2_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *Player;
    QVideoWidget *video;
    QAudioOutput audioOutput;
    qint64 duration;
    bool IS_Pause = true;
    bool IS_Muted = false;
};
#endif // MAINWINDOW_H
