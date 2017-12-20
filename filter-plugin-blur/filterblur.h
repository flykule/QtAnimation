#ifndef FILTERBLUR_H
#define FILTERBLUR_H
#include <Filter.h>
#include <QObject>

class FilterBlur : public QObject, Filter {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.masteringqt.imageanimation.filters.Filter")
  Q_INTERFACES(Filter)

public:
  FilterBlur(QObject *parent = 0);
  ~FilterBlur();

  // Filter interface
public:
  QString name() const;
  QImage process(const QImage &image);
};

#endif // FILTERBLUR_H
