#include <QtGui/QApplication>
#include <QLabel>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QImage myImage;
    try
	{
		myImage.load(argv[1]);
	}
	catch(int err)
	{
		std::cout << "Exception: " << err << std::endl;
		std::cout << "Enter a valid Image as argument" << std::endl;
	}

    QLabel myLabel;
    myLabel.setPixmap(QPixmap::fromImage(myImage));

    myLabel.show();

    return a.exec();
}
