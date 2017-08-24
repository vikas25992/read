#include<iostream>
#include<fstream>
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <vector>

#include <sstream>
#include<string>

using namespace std;
using namespace cv;

Mat readImgage(const string& read_address);

void showImage(Mat& image);

Mat siftDescriptors(const string& file_address);

int main()
{
	
	Mat pic,Desc;

	ostringstream oss;

	for(int i=1; i<3; i++)
	{

		oss.clear();

		oss.str("");

		string address = "/home/vikas/Desktop/Project/string/pics/";
		
		oss << address << i <<".jpeg";

		pic = readImgage(oss.str());

		Desc = siftDescriptors(oss.str());
	
		cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";

		
		//cout<<oss.str()<<endl;
		
		

		//pic = readImgage(oss.str());

		//showImage(pic);

		//pic = imread(oss.str(),0);

		//imshow("pic",pic);

		//waitKey(0);
						
	}

	cout<<oss.str()<<endl;

	
	cout<<Desc<<endl;

	//imshow( "Display window", pic );

	//showImage(pic);
	
	return 0;
}



Mat readImgage(const string& read_address)
{

    cout<<"Reading Image"<<endl;
    //cout<<file_address<<endl;
    Mat image;
    image = imread(read_address, CV_LOAD_IMAGE_GRAYSCALE);
    return image;
}



Mat siftDescriptors(const string& file_address)
{

	cout<<file_address<<endl;
	Mat test_image = imread(file_address, CV_LOAD_IMAGE_GRAYSCALE);

	if(test_image.empty())
    {
        cout<<"Can't read the images\n";
        return -1;
    }


	SiftFeatureDetector detector(300);
	vector<KeyPoint> Keypoints;
	detector.detect(test_image, Keypoints);

	SiftDescriptorExtractor extractor;
	Mat trainDescriptors;	
	extractor.compute(test_image, Keypoints, trainDescriptors);
	return trainDescriptors;


}



void showImage(Mat& image)
{
	cout<<"show Image"<<endl;
	namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
   	imshow( "Display window", image );                   // Show our image inside it.
   	waitKey(0);   
}



//string address = main_folder + i + end;

		
		//cout<<main_folder + i + end<<endl;

		//char c = i;

		//strcat(address,i);

		//address.push_back(i);

		//strcat(address,end);

		//cout<<address<<endl;

		//address += std::to_string(i);

//strcat(address,i);

		//strcat(address,".jpeg");

//str += ss.str();

		//ss << i;

		//cout<<str<<endl;

		//pic = imread(address,0);


		//imshow("pic",pic);

		//waitKey(0);

