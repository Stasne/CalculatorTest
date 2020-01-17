#include "queuecontroller.h"
#include <QThread>

QueueController::QueueController(QQueue<StructRequests> &reqQ, QQueue<StructResults> &resQ)
{
	Requests = &reqQ;
	Results = &resQ;
}

void QueueController::Init()
{
	qDebug() << "I'm QueueHandler in new thread" << QThread::currentThreadId();
}

void QueueController::ReceiveRequest(int operationCode, double a, double b)
{
	requestPack.operationCode = operationCode;
	requestPack.a = a;
	requestPack.b = b;
	Requests->enqueue(requestPack);
	emit newRequestReady();
}
void QueueController::ShowResult()
{
	if (Results->isEmpty())
		return;
	qDebug()<< "MyResult" << Results->first().question << Results->first().answer;
	Results->dequeue();

}
