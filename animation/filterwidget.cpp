#include "filterwidget.h"
#include "ui_filterwidget.h"
#include <Filter.h>
#include <QDebug>

using namespace std;

FilterWidget::FilterWidget(Filter &filter, QWidget *parent)
    : QWidget(parent), ui(new Ui::FilterWidget), mFilter(filter),
      mDefaultSourcePicture(":/lenna.jpg"), mSourcePicture(),
      mSourceThumbnail(mDefaultSourcePicture.scaled(
          QSize(256, 256), Qt::KeepAspectRatio, Qt::SmoothTransformation)),
      mFilteredPicture(), mFilteredThumbnail() {
  ui->setupUi(this);
  ui->titleLabel->setText(mFilter.name());

  updateThumbnail();
}

FilterWidget::~FilterWidget() { delete ui; }

void FilterWidget::process() {
  //  if (mFilter == null) {
  //    qDebug() << "Filter Null!!!!";
  //  }
  //  qDebug() << mFilter.name();
  mFilteredPicture = mFilter.process(mSourcePicture);
  emit pictureProcessed(mFilteredPicture);
}

void FilterWidget::setSourcePicture(const QImage &sourcePicture) {
  mSourcePicture = sourcePicture;
}

void FilterWidget::setSourceThumbnail(const QImage &sourceThumbnail) {
  mSourceThumbnail = sourceThumbnail;
}

void FilterWidget::updateThumbnail() {
  mFilteredThumbnail = mFilter.process(mSourceThumbnail);
  QPixmap pixmap = QPixmap::fromImage(mFilteredThumbnail);
  ui->thumbnailLabel->setPixmap(pixmap);
}

QString FilterWidget::title() const { return mFilter.name(); }

void FilterWidget::mousePressEvent(QMouseEvent *) { process(); }
