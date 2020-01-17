#include "computer.h"
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>

computer::computer(QWidget *parent) :
	QMainWindow(parent)
{
	CalculationThread = new QThread;
	CalculationSimulator = new CalculatorSimulator(Requests, Results);
	CalculationSimulator->moveToThread(CalculationThread);
	connect(CalculationThread, SIGNAL(started()), CalculationSimulator, SLOT(Init()));
	CalculationThread->start();

	RequestResultThread = new QThread;
	QueueHandler = new QueueController(Requests, Results);
	QueueHandler->moveToThread(RequestResultThread);
	connect(RequestResultThread, SIGNAL(started()), QueueHandler, SLOT(Init()));
	RequestResultThread->start();

	connect(QueueHandler, SIGNAL(newRequestReady()), CalculationSimulator, SLOT(OperateNewRequest()), Qt::DirectConnection);
	connect(CalculationSimulator, SIGNAL(CalculationFinished()), QueueHandler, SLOT(ShowResult()), Qt::DirectConnection);


}

computer::~computer()
{
}

void computer::resizeEvent(QResizeEvent *)
{
	m_windowSize = this->size();
}

void computer::moveEvent(QMoveEvent *)
{
	m_windowPosition = this->pos();

}

void computer::keyPressEvent(QKeyEvent *key)
{
	// Обрабатывать клавиатуру.
	// Нужно ли реализовывать иначе, или привязать к слотам GUI.
// key0 keyCode 48
//	switch (stage)
//	{
//	case (operandA):
//		a *= 10;
//		a += key->key()-48;
//		break;
//	case (operandB):
//		b *= 10;
//		b += key->key()-48;
//		break;
//	}
	CalculationSimulator->SetOperationDelay(0, 1500);
	CalculationSimulator->SetOperationDelay(1, 1000);
	CalculationSimulator->SetOperationDelay(2, 1000);
	CalculationSimulator->SetOperationDelay(3, 1000);
	QueueHandler->ReceiveRequest(2,50.2,17);
	QueueHandler->ReceiveRequest(1,50.2,55);
	QueueHandler->ReceiveRequest(3,50.2,2);
	QueueHandler->ReceiveRequest(0,50.2,152);

}
void computer::closeEvent(QCloseEvent*)
{
	qDebug() << "close";
}
