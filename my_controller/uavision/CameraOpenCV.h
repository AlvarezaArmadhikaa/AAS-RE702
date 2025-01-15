#ifndef CAMERAOPENCV_H_
#define CAMERAOPENCV_H_

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "UAVision.h"
#include "Camera.h"
#include "CameraSettings.h"
#include "CameraSettingsOpenCV.h"

/**
 * Class for accessing a webcam (or a generic USB cam)
 * based on OpenCV methods.
 */


namespace uav{


class CameraOpenCV: public Camera
{
public:

	cv::VideoCapture capture;

	/**
	 * Destructor
	 */

	~CameraOpenCV(){ capture.release();}

	/**
	 * Method for initializing the camera.
	 */
	int initCamera(CameraSettings *camSettings);

	/**
	 * Method for initializing the camera.
	 */
	int init(CameraSettings *camSettings);

	/**
	 * Method for start sending images.
	 */
	void startCamera(CameraSettings *camSettings);

	/**
	 * Method for stop sending images.
	 */
	void stopCamera(CameraSettings *camSettings);

	/**
	 * Method for stopping the camera and finishing the connection.
	 */
	void shutDownCamera();

	/**
	 * Method for setting camera parameters.
	 * @param *camSettings - camera parameters to be set.
	 */
	void setParameters(CameraSettings *camSettings);

	/**
	 * Pure virtual method for setting the value of one camera parameter.
	 * @param parameter - camera parameter to be set.
	 * @param value - new value of the parameter to be set.
	 */
	void setParameter(unsigned int parameter, unsigned value);

	/**
	 * Method for retrieving the value of one camera parameter.
	 * @param parameter - camera parameter to be retrieved.
	 * @param *value - value of the parameter to be retrieved.
	 */
	void getParameter(unsigned int parameter, double *value);

	/**
	 * Method for retrieving the camera settings.
	 * @param *camSettings - camera settings to be retrieved.
	 */
	void getParameters(CameraSettings *camSettings);

	/**
	 * Method for retrieving the limits of the value of a camera parameter.
	 * @param parameter - camera parameter to be retrieved.
	 * @param parameterRange - values of the limits of the parameter to be filled.
	 */
	void getParameterRanges(unsigned int parameter,ParameterRange parameterRange);

	/**
	 * Method for retrieving the limits of the value of a camera parameter.
	 * @param parameter - camera parameter to be retrieved.
	 * @param parameterRange - values of the limits of the parameter to be filled.
	 */
	void getParametersRanges( ParameterRange parameterRange[] );

	/**
	 * Pure virtual method for reading a frame from the camera.
	 * @param &imageOpenCV - frame read.
	 */
	int readFrame( cv::Mat &imageOpenCV );
	//virtual Mat& operator>> () = 0;

	/**
	 * Method for setting the camera in full auto-mode.
	 * @param *camSettings - camera settings that are to be set in automode.
	 */
	void setAutoMode(CameraSettings *camSettings );

	/**
	 * Method for setting the camera in manual mode.
	 * @param *camSettings - camera settings to be set in manual mode.
	 */
	void setManualMode(CameraSettings *camSettings );

	/**
	 * Method for printing the camera settings.
	 */
	void printParameters();


	/**
	 * Method for printing just one camera parameter.
	 * @param parameter - camera parameter whose value should be printed.
	 */
	void printParameter(unsigned int parameter);

	void rewind(){}
};
}
#endif
