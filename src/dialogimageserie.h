#ifndef DIALOGIMAGESERIE_H
#define DIALOGIMAGESERIE_H

#include <QDialog>

namespace Ui {
class DialogImageSerie;
}

class DialogImageSerie : public QDialog
{
    Q_OBJECT
public:

    struct ImgSerie{
        ImgSerie();
        ImgSerie(double zoom, unsigned imgCount, QString path, unsigned nameItStart, QString prefix, QString suffix, unsigned addIT);
        double zoomStep;
        unsigned imgCount,
            imgCountConst;
        QString dirPath;
        unsigned nameItStart,
            nameStartConst, addIT;
        QString prefix, suffix;
    };

    explicit DialogImageSerie(QWidget *parent = nullptr, ImgSerie s = ImgSerie(), double startZoom = 0, unsigned startAddIT = 0);
    ~DialogImageSerie();


    ImgSerie getImgSerieSettings();

private:
    void updateEndZoom();
    void updateEndItCount();

private slots:
    void on_pushButtonOpenSaveDir_clicked();

    void on_lineEditPath_textChanged(const QString &arg1);

    void on_spinBoxBilderZahl_valueChanged(int arg1);

    void on_doubleSpinBoxZoomStep_valueChanged(double arg1);

    void on_spinBoxAddIt_valueChanged(int arg1);

private:
    Ui::DialogImageSerie *ui;
    QString dir;
    double startZoom;
    unsigned startITC;

};

#endif // DIALOGIMAGESERIE_H
