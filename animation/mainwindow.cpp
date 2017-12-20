#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QPixmap>

#include "filterwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mSourcePicture(),
      mSourceThumbnail(), mCurrentPixmap(), mFilterLoader(),
      mCurrentFilter(nullptr), mFilteredPicture(mSourcePicture), mFilters() {
  ui->setupUi(this);
  ui->pictureLabel->setMinimumSize(1, 1);
  ui->actionSaveAs->setEnabled(false);
  connect(ui->actionOpenPicture, &QAction::triggered, this,
          &MainWindow::loadPicture);
  connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
  connect(ui->actionSaveAs, &QAction::triggered, this,
          &MainWindow::saveAsPicture);
  initFilters();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::loadPicture() {
  QString filename = QFileDialog::getOpenFileName(
      this, "Open Picture", QDir::homePath(), tr("Images (*.png *.jpg)"));
  if (filename.isEmpty()) {
    return;
  }
  ui->actionSaveAs->setEnabled(true);
  mSourcePicture = QImage(filename);
  mSourceThumbnail = mSourcePicture.scaled(QSize(256, 256), Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation);
  for (int i = 0; i < mFilters.size(); ++i) {
    mFilters[i]->setSourcePicture(mSourcePicture);
    mFilters[i]->setSourceThumbnail(mSourceThumbnail);
    mFilters[i]->updateThumbnail();
  }
  mCurrentFilter->process();
}

void MainWindow::resizeEvent(QResizeEvent *event) {}

void MainWindow::displayPicture(const QImage &picture) {
  mFilteredPicture = picture;
  mCurrentPixmap = QPixmap::fromImage(picture);
  updatePicturePixmap();
}

void MainWindow::saveAsPicture() {
  QString filename = QFileDialog::getSaveFileName(
      this, "Save Picture", QDir::homePath(), tr("Images (*.png *.jpg)"));
  if (filename.isEmpty()) {
    return;
  }
  mFilteredPicture.save(filename);
}

void MainWindow::initFilters() {
  mFilterLoader.loadFilters();
  auto &filters = mFilterLoader.filters();

  for (auto &filter : filters) {
    FilterWidget *filterWidget = new FilterWidget(*filter);
    ui->filtersLayout->addWidget(filterWidget);
    connect(filterWidget, &FilterWidget::pictureProcessed, this,
            &MainWindow::displayPicture);
    mFilters.append(filterWidget);
  }
  if (mFilters.length() > 0) {
    mCurrentFilter = mFilters[0];
  }
}

void MainWindow::updatePicturePixmap() {
  if (mCurrentPixmap.isNull()) {
    return;
  }
  ui->pictureLabel->setPixmap(mCurrentPixmap.scaled(
      ui->pictureLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}
