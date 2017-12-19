#include "filteroriginal.h"

FilterOriginal::FilterOriginal(QObject *parent) : QObject(parent) {}

FilterOriginal::~FilterOriginal() {}

QString FilterOriginal::name() const { return "Original"; }

QImage FilterOriginal::porcess(const QImage &image) { return image; }
