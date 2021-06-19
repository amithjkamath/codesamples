#include <Magick++.h>
#include <iostream>

using namespace Magick;

int main(int argc,char **argv)
{
	InitializeMagick(*argv);

	// Construct the image object. Seperating image construction from the
	// the read operation ensures that a failure to read the image file
	// doesn't render the image object useless.
	Image image;
	if(argc != 3)
	{
		std::cout << "Error: image not specified." << std::endl;
		return  -1;
	}
	try {
    // Read a file into image object
    image.read(argv[1]);

    // Crop the image to specified size (width, height, xOffset, yOffset)
    image.resize(Geometry(1000,1000));
	
	image.blur(5,2.5);
	image.annotate("Copylefted 2014",Geometry(500,500,50,50));
    // Write the image to a file
    image.write(argv[2]);
  	}
  	catch( Exception &error_ )
    {
    	std::cout << "Caught exception: " << error_.what() << std::endl;
    	return 1;
    }
  	return 0;
}
