#include "FaceDetector.h"
#include <iostream>

FaceDetector::FaceDetector() {
    // Initialize with default parameters
}

bool FaceDetector::initialize() {
    // Load Haar cascade classifiers
    std::string face_cascade_path = "haarcascades/haarcascade_frontalface_alt2.xml";
    std::string eye_cascade_path = "haarcascades/haarcascade_eye_tree_eyeglasses.xml";
    
    if (!face_cascade.load(face_cascade_path)) {
        std::cerr << "Error loading face cascade classifier!" << std::endl;
        return false;
    }
    
    if (!eye_cascade.load(eye_cascade_path)) {
        std::cerr << "Warning: Could not load eye cascade classifier!" << std::endl;
        // This is not critical for face detection
    }
    
    return true;
}

std::vector<cv::Rect> FaceDetector::detectFaces(const cv::Mat& frame) {
    std::vector<cv::Rect> faces;
    cv::Mat gray_frame;
    
    // Convert to grayscale for better detection
    if (frame.channels() > 1) {
        cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
    } else {
        gray_frame = frame.clone();
    }
    
    // Equalize histogram for better contrast
    cv::equalizeHist(gray_frame, gray_frame);
    
    // Detect faces
    face_cascade.detectMultiScale(
        gray_frame, 
        faces, 
        1.1,        // scale factor
        3,          // minimum neighbors
        0,          // flags
        cv::Size(30, 30)  // minimum size
    );
    
    return faces;
}

std::vector<cv::Rect> FaceDetector::detectEyes(const cv::Mat& frame, const cv::Rect& face) {
    std::vector<cv::Rect> eyes;
    cv::Mat gray_frame, face_roi;
    
    // Convert to grayscale
    if (frame.channels() > 1) {
        cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
    } else {
        gray_frame = frame.clone();
    }
    
    // Extract face region
    face_roi = gray_frame(face);
    
    // Detect eyes within the face region
    eye_cascade.detectMultiScale(
        face_roi,
        eyes,
        1.1,
        2,
        0,
        cv::Size(10, 10)
    );
    
    // Adjust eye coordinates to full frame
    for (auto& eye : eyes) {
        eye.x += face.x;
        eye.y += face.y;
    }
    
    return eyes;
}

cv::Mat FaceDetector::extractFace(const cv::Mat& frame, const cv::Rect& face) {
    return frame(face).clone();
}
