#ifndef XSNDECODER_H
#define XSNDECODER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QtMath>
#include <QDateTime>

#include <fstream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <opencv2/opencv.hpp>

//#define bytes_to_u16(LSB) (((unsigned int) ((unsigned char) (LSB+1))) & 255)<<8 | (((unsigned char) LSB)&255)


class XsnDecoder : public QObject
{
    Q_OBJECT
public:
    explicit XsnDecoder(QObject *parent = nullptr);

    bool decode(QString filename);

    QDateTime dateTime;
    int frames;
    QString basename;
    QString mainFolder;

signals:

public slots:

private:

    cv::Mat lut;

    std::vector<char> readAllBytes(const char *filename);

    std::vector<std::size_t> findAllIndexes(const std::vector<char>& haystack, const std::vector<char>& needle);

    std::vector<char> buffer;
    std::vector<std::size_t> founds;


    cv::Mat extractImage(std::vector<char> &buffer, size_t idx);
    QDateTime extractTime(std::vector<char> &buffer, size_t idx);

    int bytesToU16(std::vector<char> &buffer, size_t idx);
};

#endif // XSNDECODER_H
