#ifndef QUEUECONTROLLER_H
#define QUEUECONTROLLER_H
#include <QDebug>
#include <QQueue>
#include <QWidget>
#include "common.h"




class QueueController : public QObject
{
	Q_OBJECT
public:
	explicit QueueController(QQueue<StructRequests>&, QQueue<StructResults>&);

signals:
	void newRequestReady();
private:
	QQueue<StructRequests> *Requests;
	QQueue<StructResults> *Results;
	StructResults resultPack;
	StructRequests requestPack;

public slots:
	void Init();
	void ReceiveRequest(int operationCode, double a, double b);
	void ShowResult();
};

#endif // QUEUECONTROLLER_H
