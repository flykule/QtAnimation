#ifndef FILTERGRAYSCALE_H
#define FILTERGRAYSCALE_H
#include <Filter.h>
#include <QObject>

class FilterGrayscale : public QObject, Filter {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.masteringqt.imageanimation.filters.Filter")
  Q_INTERFACES(Filter)
public:
  FilterGrayscale(QObject *parent = 0);
  ~FilterGrayscale();

  // Filter interface
public:
  QString name() const;
  QImage process(const QImage &image);
};

#endif // FILTERGRAYSCALE_H
