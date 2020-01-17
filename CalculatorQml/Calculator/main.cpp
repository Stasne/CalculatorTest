#include "computer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	computer w;
	w.show();

	return a.exec();
}
