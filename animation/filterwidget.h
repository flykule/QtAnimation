#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QGraphicsColorizeEffect>
#include <QImage>
#include <QPropertyAnimation>
#include <QWidget>

namespace Ui {
class FilterWidget;
}

class Filter;

class FilterWidget : public QWidget {
  Q_OBJECT

public:
  explicit FilterWidget(Filter &filter, QWidget *parent = 0);
  ~FilterWidget();

  void process();

  void setSourcePicture(const QImage &sourcePicture);
  void setSourceThumbnail(const QImage &sourceThumbnail);
  void updateThumbnail();

  QPropertyAnimation *colorAnimation();
  QString title() const;

signals:
  void pictureProcessed(const QImage &picture);

protected:
  void mousePressEvent(QMouseEvent *) override;

private:
  void initAnimations();
  void startSelectionAnimation();
  Ui::FilterWidget *ui;
  Filter &mFilter;

  QPropertyAnimation mSelectionAnimation;
  QPropertyAnimation mColorAnimation;
  QGraphicsColorizeEffect mColorEffect;

  QImage mDefaultSourcePicture;
  QImage mSourcePicture;
  QImage mSourceThumbnail;

  QImage mFilteredPicture;
  QImage mFilteredThumbnail;
};

#endif // FILTERWIDGET_H
