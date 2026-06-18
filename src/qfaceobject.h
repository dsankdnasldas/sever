#ifndef QFACEOBJECT_H
#define QFACEOBJECT_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <seeta/FaceDetector.h>
#include <seeta/FaceEngine.h>

//人脸数据存储， 人脸检测，人脸识别
class QFaceObject : public QObject
{
    Q_OBJECT
public:
    explicit QFaceObject(QObject *parent = nullptr);
    ~QFaceObject();
public slots:
    int64_t face_register(cv::Mat& faceImage);
    int face_query(cv::Mat& faceImage);
signals:
    void send_faceid(int64_t faceid);
private:
    seeta::FaceEngine *fengineptr;

};

#endif // QFACEOBJECT_H