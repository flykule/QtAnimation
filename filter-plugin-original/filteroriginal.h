#ifndef FILTERORIGINAL_H
#define FILTERORIGINAL_H
#include <Filter.h>
#include <QObject>

class FilterOriginal : public QObject, Filter {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.masteringqt.imageanimation.filters.Filter")
  Q_INTERFACES(Filter)

public:
  FilterOriginal(QObject *parent = 0);
  ~FilterOriginal();

  // Filter interface
public:
  QString name() const override;
  QImage process(const QImage &image) override;
};

#endif // FILTERORIGINAL_H
