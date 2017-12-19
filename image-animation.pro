TEMPLATE = subdirs

CONFIG+= C++14

OTHER_FILES += \
                            sdk/Filter.h \
                            README.md \
                            plugins-common.pri \
                            plugins-common-opencv.pri

SUBDIRS += \
    filter-plugin-original \
    filter-plugin-grayscale \
    filter-plugin-blur

