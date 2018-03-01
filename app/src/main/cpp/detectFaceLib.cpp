//
// Created by enclaveit on 01/03/2018.
//

#include <jni.h>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat frame_gray;
std::vector<cv::Rect> faces;
cv::Mat faceROI;
//cv::CascadeClassifier face_cascade("/storage/emulated/0/data/haarcascade_frontalface_alt.xml");
cv::CascadeClassifier face_cascade("/sdcard/data/haarcascade_frontalface_alt.xml");
void haarCascadeDetect(cv::Mat& frame);

extern "C" {
JNIEXPORT void JNICALL
Java_com_example_wilson_humancharacteristics_CameraDetect_CameraDetectActivity_detectFace(
        JNIEnv *env,
        jobject /* this */,
        jlong imgMat) {

    cv::Mat* img = (cv::Mat*) imgMat;
    haarCascadeDetect(*img);
}

JNIEXPORT jstring JNICALL
Java_com_example_wilson_humancharacteristics_CameraDetect_CameraDetectActivity_fromDetectFaceLib(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "From CameraDetect Lib";
    return env->NewStringUTF(hello.c_str());
}
}


void haarCascadeDetect(cv::Mat& frame){
    if(face_cascade.empty()){
        printf("--(!)Error loading\n"); return;
    }


    cv::cvtColor( frame, frame_gray, cv::COLOR_RGBA2GRAY );
    cv::equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.5, 3, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(50, 50) );
    for( size_t i = 0; i < faces.size(); i++ )
    {
        cv::rectangle(frame, cv::Point(faces[i].x, faces[i].y),
                      cv::Point(faces[i].x + faces[i].width, faces[i].y+faces[i].height), cv::Scalar(255,0,255), 3);

//        faceROI = frame_gray( faces[i] );
    }
}
