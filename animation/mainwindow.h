#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QImage>
#include <QMainWindow>
#include <QVector>

#include "filterloader.h"

namespace Ui {
class MainWindow;
}

class FilterWidget;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void loadPicture();

protected:
  void resizeEvent(QResizeEvent *event) override;
private slots:
  void displayPicture(const QImage &picture);
  void saveAsPicture();

private:
  void initFilters();
  void updatePicturePixmap();

  QImage mSourcePicture;
  QImage mSourceThumbnail;
  QImage mFilteredPicture;
  QPixmap mCurrentPixmap;

  FilterLoader mFilterLoader;
  FilterWidget *mCurrentFilter;
  QVector<FilterWidget *> mFilters;
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
