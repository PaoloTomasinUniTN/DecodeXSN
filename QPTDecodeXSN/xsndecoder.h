#ifndef XSNDECODER_H
#define XSNDECODER_H

#include <QObject>
#include <QDebug>

#include <opencv2/opencv.hpp>

class XsnDecoder : public QObject
{
    Q_OBJECT
public:
    explicit XsnDecoder(QObject *parent = nullptr);

signals:

public slots:
};

#endif // XSNDECODER_H
