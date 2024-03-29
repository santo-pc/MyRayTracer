#include <iostream>
#include <string>
#define GLM_PRECISION_HIGHP_FLOAT
#define GLM_PRECISION_HIGHP_DOUBLE
#include <glm/glm.hpp>
// // #include <free_image/FreeImage.h>
#include "RayTracer.h"
#include "readfile.h"
#include "RenderSettings.h"
#include "Camera.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
//
//
using namespace std;

// void SaveImageFile(MyImage &image, const string & fname)
// {
// 	
// 	FreeImage_Initialise();
//
// 	FIBITMAP * img = FreeImage_Allocate(imege.width, image.height, 24);
//
// 	if (img)
// 	{
// 		RGBQUAD color;
//
// 		for (int i = 0; i < image.width; i++)
// 			for (int j = 0; j < image.height; j++)
// 			{
// 				color.rgbRed = image.image[j][i].x;
// 				color.rgbGreen = image.image[j][i].y;
// 				color.rgbBlue = image.image[j][i].z;
// 				FreeImage_SetPixelColor(img, i, j, &color);
// 			}
//
// 		FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);
//
// 		//delete img;	
//
// 		std::cout << "Saving screenshot: " << fname << "\n";
// 	}
// 	else
// 		std::cout << "Error: Something happened while saving image: " << fname << "\n";	
// 	
// 	FreeImage_DeInitialise();
// 	
// }

int main(int argc, char * argv[])
{
  cout << "Hello world";

	if (argc < 2) 
	{
		cerr << "Usage: transforms scenefile [grader input (optional)]\n";
		exit(-1);
	}

	char * sceneFile = argv[1];

	cout << "Scene File: " << sceneFile << endl;

  std::string outputFileName = "";
  outputFileName.append(sceneFile).append("imagResult.png");

	RayTracer tracer;

	Camera * cam = new Camera();

	Scene * scene = new Scene();

	readfile(sceneFile, cam, scene);

	MyImage image = tracer.RayTrace(cam, scene, RENDERSETTINGS->width, RENDERSETTINGS->height);

  std::vector<unsigned char> data = image.to_char_vector();
  
  return stbi_write_png(outputFileName.c_str(), 
      RENDERSETTINGS->width,
      RENDERSETTINGS->height,
      4, 
      &(data[0]),
      4*RENDERSETTINGS->width);
/* 	system("PAUSE"); */

	return 0;
}
