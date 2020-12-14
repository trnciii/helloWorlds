#include <iostream>
#include <glm/glm.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

unsigned char tonemap(double c){
	int c_out = 255*pow(c,(1/2.2)) +0.5;
	if(255 < c_out)c_out = 255;
	if(c_out < 0)c_out = 0;
	return c_out&0xff;
}

int writeImage(glm::vec3* color, int w, int h, const char* name){
	unsigned char *tone = new unsigned char[3*w*h];
	for(int i=0; i<w*h; i++){
		tone[3*i  ] = tonemap(color[i].x);
		tone[3*i+1] = tonemap(color[i].y);
		tone[3*i+2] = tonemap(color[i].z);
	}
	// return 1 if succeed.
	int result = stbi_write_png(name, w, h, 3, tone, 3*w);

	delete[] tone;
	return result;
}

int main(){
	int width = 512;
	int height = 512;
	glm::vec3* result = new glm::vec3[width*height];

	for(int i=0; i<width*height; i++){
		int xi = i%width;
		int yi = i/width;

		result[i] = glm::vec3((double)xi/width, (double)yi/height, 0.5);
	}

	std::string out("result.png");
	writeImage(result, width, height, out.data());

	return 0;
}