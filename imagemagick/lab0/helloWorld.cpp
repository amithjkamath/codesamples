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
    cout << "Error. Enter two arguments: image-to-read and image-to-write." << endl;
    return 1;
  }
  try {
    // Read file into image object
    image.read(argv[1]);

    // Add noise.
    image.addNoise(ImpulseNoise); 

    // Write the image to a file, specified by the input.
    image.write(argv[2]);
  }
  catch( Exception &error_ )
    {
      std::cout << "Caught exception: " << error_.what() << std::endl;
      return 1;
    }
  return 0;
}
