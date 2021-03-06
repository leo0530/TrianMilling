///////////////////////////////////////////////////////////////////////////////
/*! \file	plotwidget2.cpp
 *  \author
 *  \date
 *  \brief	Implementation file for class PlotWidget2
 *
 *  This file is part of the HMI Solutionline GUI Framework.
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////
#include "plotwidget2.h"

///////////////////////////////////////////////////////////////////////////////
// CREATORS
///////////////////////////////////////////////////////////////////////////////

PlotWidget2::PlotWidget2(QWidget* pParent)
	: QWidget(pParent)
{
    mpadding = 0;
    mBKColor = QColor(215,225,235);
	RegulateXAxis(0,10,10);
	RegulateYAxis(0,1,10);
	mPointsCnt = -1;
	m_nZoom = 0;
	m_bFirstTime = true;
	m_bMouseMove = false;
}// <-- PlotWidget2::PlotWidget2 ()


PlotWidget2::~PlotWidget2(void)
{

} // <-- ::~ ()

void PlotWidget2::setXRange(double lower, double upper)
{
	RegulateXAxis(lower,upper,15);
}

void PlotWidget2::setYRange(double lower, double upper)
{
	RegulateYAxis(lower,upper,15);
}

bool PlotWidget2::isEmpty()
{	
	bool retVal;
	retVal = mPointsCnt == -1 ? true : false;
	return retVal;
}

void PlotWidget2::clearData()
{
    this->datax.clear();
    this->datay1.clear();
    this->datay2.clear();
    this->datay3.clear();
	
	//QVector<double> pNullVector; 
	//datax.swap(pNullVector);     

    mBKColor = QColor(215,225,235);
	RegulateXAxis(0,10,10);
	RegulateYAxis(0,1,10);

	mPointsCnt = -1;
	m_nZoom = 0;
}

void PlotWidget2::addData(double x,double y1,double y2,double y3)
{
	this->datax.append(x);
	this->datay1.append(y1);
	this->datay2.append(y2);
	this->datay3.append(y3);
	mPointsCnt++;
}
/*
void PlotWidget2::setData(const QVector<double> &x, const QVector<double> &y1,const QVector<double> &y2)
{
    this->datax.clear();
    this->datay1.clear();
    this->datay2.clear();
    int n = x.size();
    n = qMin(n, y1.size());
    n = qMin(n, y2.size());
	mPointsCnt = n;
    for (int i=0; i<mPointsCnt; ++i)
    {
        this->datax.append(x[i]);
        this->datay1.append(y1[i]);
        this->datay2.append(y2[i]);
    }
}
*/
void PlotWidget2::setBKColor(QColor c)
{
    mBKColor = c;
}

void PlotWidget2::ClearBKColor()
{
    mBKColor = QColor(215,225,235);
}

bool PlotWidget2::zoomIn()
{
	if(m_nZoom > -5){
		m_nZoom--;
		double delta = (yAxisRange.upper - yAxisRange.lower)*0.25;
		double dmin = yAxisRange.lower + delta;
		double dmax = yAxisRange.upper - delta;
		//yAxisRange.lower > 0 ? yAxisRange.lower *= 1.25 : yAxisRange.lower *= 0.8 ;
		//yAxisRange.upper > 0 ? yAxisRange.upper *= 0.8 : yAxisRange.upper *= 1.25 ;
		RegulateYAxis(dmin,dmax,15);
		repaint();
		return true;
	}
	else{
		m_nZoom = -5;
		return false;
	}
	return false;
}

bool PlotWidget2::zoomOut()
{
	if(m_nZoom < 5){
		m_nZoom++;
		double delta = (yAxisRange.upper - yAxisRange.lower)*0.5;
		double dmin = yAxisRange.lower - delta;
		double dmax = yAxisRange.upper + delta;
		//yAxisRange.lower > 0 ? yAxisRange.lower *= 0.8 : yAxisRange.lower *= 1.25 ;
		//yAxisRange.upper > 0 ? yAxisRange.upper *= 1.25 : yAxisRange.upper *= 0.8;
		RegulateYAxis(dmin,dmax,15);
		repaint();
		return true;
	}
	else{
		m_nZoom = 5;
		return false;
	}
	return false;
}

void PlotWidget2::restoreZoom()
{
	m_nZoom = 0;
}

bool PlotWidget2::isZoomInAndOut()
{
	if(m_nZoom > -5 && m_nZoom < 5)
		return true;
	else
		return false;

	return true;
}

void PlotWidget2::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);                        //设置反锯齿模式，好看一点
    /*--------------------------------------------------
     *first step Initialize the Zero point and the Rect of the Graphic Window
     *--------------------------------------------------
    */
    mRectWidth = width();
    mRectHeight = height();
    OPoint.setX(35);
    OPoint.setY(mRectHeight-20);
    mRectWidth = mRectWidth - OPoint.x() - 20;
    mRectHeight = OPoint.y() -20;
    /*--------------------------------------------------
     *Second plot the rect of the Graphic Window
     *--------------------------------------------------
     */
    QPen Tpen;
    Tpen.setColor(Qt::transparent);

    QRect rect(mpadding,mpadding,width()-2*mpadding,height()-2*mpadding);
	painter.setPen(Tpen);
    painter.drawRect(rect);                                                     //外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。
    painter.fillRect(rect,mBKColor);

    /*--------------------------------------------------
     *Thirdly,convert the data to the pixel point
     *--------------------------------------------------
     */
    if(mPointsCnt != -1){
        this->pixelx.clear();
        this->pixely1.clear();
        this->pixely2.clear();
        this->pixely3.clear();
		int n = this->datax.size();
        n = qMin(n, this->datay1.size());
        n = qMin(n, this->datay2.size());
        n = qMin(n, this->datay3.size());
        for (int i=0; i<n; ++i)
        {
			double dx = datax.at(i);
			double dy1 = datay1.at(i);
			double dy2 = datay2.at(i);
			double dy3 = datay3.at(i);
            int x = OPoint.x() + (dx - xAxisRange.lower)/(xAxisRange.upper - xAxisRange.lower) * mRectWidth;
            int y1 = OPoint.y() - (dy1 - yAxisRange.lower)/(yAxisRange.upper - yAxisRange.lower) * mRectHeight;
            int y2 = OPoint.y() - (dy2 - yAxisRange.lower)/(yAxisRange.upper - yAxisRange.lower) * mRectHeight;
            int y3 = OPoint.y() - (dy3 - yAxisRange.lower)/(yAxisRange.upper - yAxisRange.lower) * mRectHeight;
			this->pixelx.append(x);
            this->pixely1.append(y1);
            this->pixely2.append(y2);
            this->pixely3.append(y3);
        }
    }
    /*--------------------------------------------------
     *Fourth,Draw the points of the curve
     * -------------------------------------------------
     */
    if(mPointsCnt != -1){
        QPen pen1,pen2,pen3,penPoint;
        pen1.setColor(Qt::blue);
        pen2.setColor(Qt::red);
		pen3.setColor(Qt::green);
		pen1.setWidth(1);
		pen2.setWidth(1);
 		pen3.setWidth(1);
		penPoint.setColor(Qt::blue);
        penPoint.setWidth(5);

        painter.setPen(pen1);//黑色笔用于连线
        int nPoints = this->pixelx.size();
        for(int i=0;i<nPoints-1;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.drawLine(pixelx.at(i),pixely1.at(i),pixelx.at(i+1),pixely1.at(i+1));
            //painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            //painter.drawPoint(pixelx.at(i),pixely.at(i));
        }
        painter.setPen(pen2);//黑色笔用于连线
        for(int i=0;i<nPoints-1;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.drawLine(pixelx.at(i),pixely2.at(i),pixelx.at(i+1),pixely2.at(i+1));
            //painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            //painter.drawPoint(pixelx.at(i),pixely.at(i));
        }

        painter.setPen(pen3);//黑色笔用于连线
        for(int i=0;i<nPoints-1;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.drawLine(pixelx.at(i),pixely3.at(i),pixelx.at(i+1),pixely3.at(i+1));
            //painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            //painter.drawPoint(pixelx.at(i),pixely.at(i));
        }
        //painter.drawPoint(pixelx.at(nPoints-1),pixely.at(nPoints-1));//绘制最后一个点
    }
    /*--------------------------------------------------
     *Fifth,Draw the Axis
     * -------------------------------------------------
     */
	//this is the new item
	painter.setPen(Tpen);
	QRect Lrect(0,0,OPoint.x(),height());
    painter.drawRect(Lrect);                                                     //外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。
    painter.fillRect(Lrect,mBKColor);

	QRect Brect(0,OPoint.y(),width(),height()-OPoint.y());
    painter.drawRect(Brect);                                                     //外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。
    painter.fillRect(Brect,mBKColor);

	QRect Rrect(OPoint.x()+mRectWidth,0,width()-OPoint.x()-mRectWidth,height());
    painter.drawRect(Rrect);                                                     //外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。
    painter.fillRect(Rrect,mBKColor);

    //绘制刻度线
    QPen penDegree,penDash;
    penDegree.setColor(Qt::black);
    penDegree.setWidth(1);
    penDash.setColor(Qt::black);
    penDash.setWidth(1);
    QVector<qreal> dashes;
    qreal space = 4;
    dashes << 1 << space << 1 <<space;
    penDash.setDashPattern(dashes);

    painter.setPen(penDegree);
    painter.drawLine(OPoint.x(),OPoint.y(),mRectWidth+OPoint.x(),OPoint.y());   //坐标轴x宽度为width
    painter.drawLine(OPoint.x(),OPoint.y()-mRectHeight,OPoint.x(),OPoint.y());  //坐标轴y高度为height

	int nLabelSignature = 1;
    //画上x轴刻度线
    for(int i=0;i<xAxisIndex;i++)
    {
        if(fabs(fabs(xAxisRange.upper) - fabs(xAxisRange.lower)) < 1E-10){
            nLabelSignature = xAxisIndex/2 - 1;
        }
        else if(fabs(xAxisRange.lower) < 1E-10){
            nLabelSignature = - 1;
        }
        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
        if((i-nLabelSignature)%1==0)
        {
            double xNumber = xAxisRange.lower + (xAxisRange.upper - xAxisRange.lower)*(i+1)/xAxisIndex;
            QString strNumber =QString::number(xNumber, 'f', 2);
            painter.drawLine(OPoint.x()+(i+1)*mRectWidth/xAxisIndex,OPoint.y(),OPoint.x()+(i+1)*mRectWidth/xAxisIndex,OPoint.y()-8);
            painter.setPen(penDash);
            painter.drawLine(OPoint.x()+(i+1)*mRectWidth/xAxisIndex,OPoint.y(),OPoint.x()+(i+1)*mRectWidth/xAxisIndex,OPoint.y()-mRectHeight);
            painter.setPen(penDegree);
            painter.drawText(OPoint.x()+(i+0.65)*mRectWidth/xAxisIndex,OPoint.y()+15,strNumber);
        }
        else
        {
            painter.drawLine(OPoint.x()+(i+1)*mRectWidth/xAxisIndex,OPoint.y(),OPoint.x()+(i+1)*mRectWidth/xAxisIndex,OPoint.y()-4);
        }
    }
    //y轴刻度线
    nLabelSignature = 1;
    for(int i=0;i<yAxisIndex;i++)
    {
        if(fabs(fabs(yAxisRange.upper) - fabs(yAxisRange.lower)) < 1E-10){
            nLabelSignature = yAxisIndex/2 - 1;
        }
        else if(fabs(yAxisRange.lower) < 1E-10){
            nLabelSignature = - 1;
        }
        if((i-nLabelSignature)%1==0)
        {
            //主要就是确定一个位置，然后画一条短短的直线表示刻度。
            double yNumber = yAxisRange.lower + (yAxisRange.upper - yAxisRange.lower)*(i+1)/yAxisIndex;
            QString strNumber =QString::number(yNumber, 'f', 2);
            painter.drawLine(OPoint.x(),OPoint.y()-(i+1)*mRectHeight/yAxisIndex,OPoint.x()+8,OPoint.y()-(i+1)*mRectHeight/yAxisIndex);
            painter.setPen(penDash);
            painter.drawLine(OPoint.x(),OPoint.y()-(i+1)*mRectHeight/yAxisIndex,OPoint.x()+mRectWidth,OPoint.y()-(i+1)*mRectHeight/yAxisIndex);
            painter.setPen(penDegree);
            painter.drawText(OPoint.x()-30,OPoint.y()-(i+0.85)*mRectHeight/yAxisIndex,strNumber);
        }
        else
        {
            painter.drawLine(OPoint.x(),OPoint.y()-(i+1)*mRectHeight/yAxisIndex,OPoint.x()+4,OPoint.y()-(i+1)*mRectHeight/yAxisIndex);
        }
    }
    /*--------------------------------------------------
     *sixth,Draw the mouseMove rect
     * -------------------------------------------------
     */
	if(m_bMouseMove && isEmpty()==false){
		m_bMouseMove = false;
		QPen pendarkDash;
		pendarkDash.setColor(Qt::black);
		pendarkDash.setWidth(2);
		QVector<qreal> dashes;
		qreal space = 10;
		dashes << 1 << space << 1 <<space;
		pendarkDash.setDashPattern(dashes);

		painter.setPen(pendarkDash);
		painter.drawRect(qMin(movePoint.x(),pressPoint.x()),
						 qMin(movePoint.y(),pressPoint.y()),
						 abs(movePoint.x()-pressPoint.x()),
						 abs(movePoint.y()-pressPoint.y()) );
	}
}

void PlotWidget2::mousePressEvent(QMouseEvent* e)
{
	if(m_bFirstTime){
		WidgetPoint = this->pos();
		m_bFirstTime = false;
	}
	pressPoint = cursor().pos() - WidgetPoint;
	pressPoint.setY(pressPoint.y() - 50);
	m_nMouseMoveCnt = 0;
}

void PlotWidget2::mouseMoveEvent(QMouseEvent *)
{
	movePoint = cursor().pos() - WidgetPoint;
	movePoint.setY(movePoint.y() - 50);
	m_nMouseMoveCnt++;
	if(m_nMouseMoveCnt == 1){
		m_nMouseMoveCnt = 0;
		m_bMouseMove = true;
		repaint();
	}
}

void PlotWidget2::mouseReleaseEvent(QMouseEvent* e)
{
	m_bMouseMove = false;
	if(isEmpty()==true)
		return;

	releasePoint = cursor().pos() - WidgetPoint;
	releasePoint.setY(releasePoint.y() - 50);

	double sx = double(pressPoint.x() - OPoint.x())/mRectWidth * (xAxisRange.upper - xAxisRange.lower) + xAxisRange.lower;
	double sy = double(OPoint.y() - pressPoint.y())/mRectHeight* (yAxisRange.upper - yAxisRange.lower) + yAxisRange.lower;

	double ex = double(releasePoint.x() - OPoint.x())/mRectWidth * (xAxisRange.upper - xAxisRange.lower) + xAxisRange.lower;
	double ey = double(OPoint.y() - releasePoint.y())/mRectHeight* (yAxisRange.upper - yAxisRange.lower) + yAxisRange.lower;

	double yMin=1E10;
	double yMax=-1E10;
	double xMin=1E10;
	double xMax=-1E10;

	xMin = qMin(xMin, sx);
	xMin = qMin(xMin, ex);

	xMax = qMax(xMax, sx);
	xMax = qMax(xMax, ex);

	yMin = qMin(yMin, sy);
	yMin = qMin(yMin, ey);

	yMax = qMax(yMax, sy);
	yMax = qMax(yMax, ey);

	xMin = xMin > 0 ? floor(xMin) : xMin;
	xMin = xMin < 0 ? floor(xMin) : xMin;
	xMax = xMax > 0 ? ceil(xMax) : xMax;
	xMax = xMax < 0 ? ceil(xMax) : xMax;

	yMin = yMin > 0 ? floor(yMin) : yMin;
	yMin = yMin < 0 ? floor(yMin) : yMin;
	yMax = yMax > 0 ? ceil(yMax) : yMax;
	yMax = yMax < 0 ? ceil(yMax) : yMax;

	RegulateXAxis(xMin,xMax,15);
	RegulateYAxis(yMin,yMax,15);
	m_nZoom = 0;
	repaint();
}

void PlotWidget2::RegulateXAxis(double dMin, double dMax, int iMaxAxisNum)
{
    if(iMaxAxisNum<1 || dMax<dMin)
        return;

    double dDelta = dMax - dMin;
	/*
    if(dDelta<1.0)					//Modify this by your requirement.
    {
        dMax+=(1.0-dDelta)/2.0;
        dMin-=(1.0-dDelta)/2.0;
    }
    dDelta = dMax - dMin;
	*/
    int iExp = (int)(log(dDelta)/log(10.0))-2;
    double dMultiplier = pow(10.0, iExp);
    const double dSolutions[] = {1, 2, 5, 10, 20, 50, 100, 200, 500,1000,2000,5000};
    int i;
    for(i=0; i<sizeof(dSolutions)/sizeof(double); i++)
    {
        double dMultiCal = dMultiplier * dSolutions[i];
        if(((int)(dDelta/dMultiCal) + 1)<=iMaxAxisNum)
        {
            break;
        }
    }

    double dInterval = dMultiplier * dSolutions[i];

    double dStartPoint = ((int)ceil(dMin/dInterval) - 1) * dInterval;
    int iAxisIndex;
    for(iAxisIndex=0; 1; iAxisIndex++)
    {
        //printf("%f", dStartPoint+dInterval*iAxisIndex);
		if(dStartPoint+dInterval*iAxisIndex>dMax){
			xAxisRange.upper = dStartPoint+dInterval*iAxisIndex;
            break;
		}
        //printf(" | ");
    }
	xAxisRange.lower = dStartPoint;
	xAxisIndex = iAxisIndex;
}

void PlotWidget2::RegulateYAxis(double dMin, double dMax, int iMaxAxisNum)
{
    if(iMaxAxisNum<1 || dMax<dMin)
        return;

    double dDelta = dMax - dMin;
	/*
    if(dDelta<1.0)					//Modify this by your requirement.
    {
        dMax+=(1.0-dDelta)/2.0;
        dMin-=(1.0-dDelta)/2.0;
    }
    dDelta = dMax - dMin;
	*/
    int iExp = (int)(log(dDelta)/log(10.0))-2;
    double dMultiplier = pow(10.0, iExp);
    const double dSolutions[] = {1, 2, 5, 10, 20, 50, 100, 200, 500,1000,2000,5000};
    int i;
    for(i=0; i<sizeof(dSolutions)/sizeof(double); i++)
    {
        double dMultiCal = dMultiplier * dSolutions[i];
        if(((int)(dDelta/dMultiCal) + 1)<=iMaxAxisNum)
        {
            break;
        }
    }

    double dInterval = dMultiplier * dSolutions[i];

    double dStartPoint = ((int)ceil(dMin/dInterval) - 1) * dInterval;
    int iAxisIndex;
    for(iAxisIndex=0; 1; iAxisIndex++)
    {
        //printf("%f", dStartPoint+dInterval*iAxisIndex);
		if(dStartPoint+dInterval*iAxisIndex>dMax){
			yAxisRange.upper = dStartPoint+dInterval*iAxisIndex;
            break;
		}
        //printf(" | ");
    }
	yAxisRange.lower = dStartPoint;
	yAxisIndex = iAxisIndex;
}