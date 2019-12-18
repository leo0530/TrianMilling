#include "plotwidget.h"
#include <cstdlib>
#include <ctime>


PlotWidget::PlotWidget(QWidget *parent) :
    QWidget(parent)
{
    mpadding = 0;
    mBKColor = QColor(215,225,235);
    mDisplayMode = DisplayMode_NoLabel;
    mYellowLabelIndex = -1;

	RegulateXAxis(0,10,10);
	RegulateYAxis(0,1,10);
}

PlotWidget::~PlotWidget()
{

}

void PlotWidget::setXRange(double lower, double upper)
{
	RegulateXAxis(lower,upper,15);
}

void PlotWidget::setYRange(double lower, double upper)
{
	RegulateYAxis(lower,upper,15);
}

void PlotWidget::clearData()
{
    this->datax.clear();
    this->datay.clear();

    mBKColor = QColor(215,225,235);
    mDisplayMode = DisplayMode_NoLabel;
    mYellowLabelIndex = -1;
	RegulateXAxis(0,10,10);
	RegulateYAxis(0,1,10);
}

void PlotWidget::setData(const QVector<double> &x, const QVector<double> &y)
{
    this->datax.clear();
    this->datay.clear();
    int n = x.size();
    n = qMin(n, y.size());
    for (int i=0; i<n; ++i)
    {
        this->datax.append(x[i]);
        this->datay.append(y[i]);
    }

	int CenterIndex = n/2;
	int NoZeroIndex = -1;
	double Threshold = 30;
	for(int i=0 ; i<n ; i++){
		double value = this->datay.at(i);
		if(fabs(value) > Threshold){
			NoZeroIndex = i;
			break;
		}
	}
	mYellowLabelIndex = (NoZeroIndex==-1) ? CenterIndex : NoZeroIndex;
}

int PlotWidget::GetLabelIndex( )
{
    return mYellowLabelIndex;
}

bool PlotWidget::IsEmpty()
{
    if(mYellowLabelIndex == -1)
        return true;
    else
        return false;
}

void PlotWidget::setBKColor(QColor c)
{
    mBKColor = c;
}

void PlotWidget::ClearBKColor()
{
    mBKColor = QColor(215,225,235);
}

void PlotWidget::setDisplayMode(int nMode)
{
    mDisplayMode = nMode;
}

int PlotWidget::IncreaseLabel()
{
    if( (mYellowLabelIndex != -1 ) && ((mDisplayMode == DisplayMode_DashLabel) || (mDisplayMode == DisplayMode_SolidLabel)) )
    {
        mYellowLabelIndex++;
        mYellowLabelIndex = mYellowLabelIndex >= (datax.size()-1) ? (datax.size()-1) : mYellowLabelIndex;
        repaint();
        return mYellowLabelIndex;
    }
    return -1;
}

int PlotWidget::DecreaseLabel()
{
    if( (mYellowLabelIndex != -1 ) && ((mDisplayMode == DisplayMode_DashLabel) || (mDisplayMode == DisplayMode_SolidLabel)) )
    {
        mYellowLabelIndex--;
        mYellowLabelIndex = mYellowLabelIndex <= 0 ? 0:mYellowLabelIndex;
        repaint();
        return mYellowLabelIndex;
    }
    return -1;
}

int PlotWidget::QuickIncreaseLabel()
{
    if( (mYellowLabelIndex != -1 ) && ((mDisplayMode == DisplayMode_DashLabel) || (mDisplayMode == DisplayMode_SolidLabel)) )
    {
        mYellowLabelIndex += 5;
        mYellowLabelIndex = mYellowLabelIndex >= (datax.size()-1) ? (datax.size()-1) : mYellowLabelIndex;
        repaint();
        return mYellowLabelIndex;
    }
    return -1;
}

int PlotWidget::QuickDecreaseLabel()
{
    if( (mYellowLabelIndex != -1 ) && ((mDisplayMode == DisplayMode_DashLabel) || (mDisplayMode == DisplayMode_SolidLabel)) )
    {
        mYellowLabelIndex -= 5;
        mYellowLabelIndex = mYellowLabelIndex <= 0 ? 0:mYellowLabelIndex;
        repaint();
        return mYellowLabelIndex;
    }
    return -1;
}

void PlotWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);                        //设置反锯齿模式，好看一点
    /*--------------------------------------------------
     *first step Initialize the Zero point and the Rect of the Graphic Window
     *--------------------------------------------------
    */
    mRectWidth = width();
    mRectHeight = height();
    OPoint.setX(50);
    OPoint.setY(mRectHeight-30);
    mRectWidth = mRectWidth - OPoint.x() - 20;
    mRectHeight = OPoint.y() -20;
    /*--------------------------------------------------
     *Second plot the rect of the Graphic Window
     *--------------------------------------------------
     */
    QPen Tpen;
    Tpen.setColor(Qt::transparent);

    QRect rect(mpadding,mpadding,width()-2*mpadding,height()-2*mpadding);
    painter.drawRect(rect);                                                     //外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。
    painter.fillRect(rect,mBKColor);
    /*--------------------------------------------------
     *Thirdly,convert the data to the pixel point
     *--------------------------------------------------
     */
    if(mYellowLabelIndex != -1){
        this->pixelx.clear();
        this->pixely.clear();
        int n = this->datax.size();
        n = qMin(n, this->datay.size());
        for (int i=0; i<n; ++i)
        {
            int x = OPoint.x() + (datax.at(i) - xAxisRange.lower)/(xAxisRange.upper - xAxisRange.lower) * mRectWidth;
            int y = OPoint.y() - (datay.at(i) - yAxisRange.lower)/(yAxisRange.upper - yAxisRange.lower) * mRectHeight;
            this->pixelx.append(x);
            this->pixely.append(y);
        }
    }
    /*--------------------------------------------------
     *Fourth,Draw the points of the curve
     * -------------------------------------------------
     */
    if(mYellowLabelIndex != -1){
        QPen pen,penPoint;
        pen.setColor(Qt::blue);
        pen.setWidth(1);
        penPoint.setColor(Qt::blue);
        penPoint.setWidth(5);

        painter.setPen(pen);//黑色笔用于连线
        int nPoints = this->pixelx.size();
        for(int i=0;i<nPoints-1;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.drawLine(pixelx.at(i),pixely.at(i),pixelx.at(i+1),pixely.at(i+1));
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
            painter.drawText(OPoint.x()+(i+0.65)*mRectWidth/xAxisIndex,OPoint.y()+20,strNumber);
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
            painter.drawText(OPoint.x()-40,OPoint.y()-(i+0.85)*mRectHeight/yAxisIndex,strNumber);
        }
        else
        {
            painter.drawLine(OPoint.x(),OPoint.y()-(i+1)*mRectHeight/yAxisIndex,OPoint.x()+4,OPoint.y()-(i+1)*mRectHeight/yAxisIndex);
        }
    }
    /*--------------------------------------------------
     *Sixth,Draw the Yellow Line
     * -------------------------------------------------
     */
    QPen YellowDashPen,YellowSolidPen;
    int index;
    QVector<qreal> yellowdashes;
    qreal yellowspace = 2;
    yellowdashes << 4 << yellowspace << 4 << yellowspace;
    switch(mDisplayMode)
    {
    case DisplayMode_DashLabel:
        YellowDashPen.setColor(QColor(255,255,0));
        YellowDashPen.setWidth(2);
        YellowDashPen.setDashPattern(yellowdashes);
        painter.setPen(YellowDashPen);
        if(mYellowLabelIndex != -1){
            index = mYellowLabelIndex;
            painter.drawLine(pixelx.at(index),OPoint.y(),pixelx.at(index),OPoint.y()-mRectHeight);
        }
        else{
            painter.drawLine(OPoint.x()+mRectWidth/2,OPoint.y(),OPoint.x()+mRectWidth/2,OPoint.y()-mRectHeight);
        }
        break;
    case DisplayMode_SolidLabel:
        YellowSolidPen.setColor(QColor(255,255,0));
        YellowSolidPen.setWidth(2);
        painter.setPen(YellowSolidPen);
        if(mYellowLabelIndex != -1){
            index = mYellowLabelIndex;
            painter.drawLine(pixelx.at(index),OPoint.y(),pixelx.at(index),OPoint.y()-mRectHeight);
        }
        else{
            painter.drawLine(OPoint.x()+mRectWidth/2,OPoint.y(),OPoint.x()+mRectWidth/2,OPoint.y()-mRectHeight);
        }
        break;
    default:
        break;
    }

/*
    QPainter painter(this);

    int widgetWidth = this->width();
    int widgetHeight = this->height();
    int pointx = 30;                                    //确定坐标轴起点坐标，这里定义(35,280)
    int pointy = widgetHeight-30;
    int width = widgetWidth-20-pointx;                  //确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。
    int height = widgetHeight-40;


    painter.setRenderHint(QPainter::Antialiasing, true);        //设置反锯齿模式，好看一点

    //绘制坐标轴 坐标轴原点(35，280)
    painter.drawRect(5,5,widgetWidth-10,widgetHeight-10);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。
    QRect rect(5,5,widgetWidth-10,widgetHeight-10);
    painter.fillRect(rect,Qt::white);
    painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为width
    painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为height



    srand(time(NULL));

    //获得数据中最大值和最小值、平均数
    int n=30;//n为数据个数
    double sum=0;
    double ave=0;
    int _ma=0;//数组里的最大值
    int _mi=inf;

    //int a[n];//数据储存在数组a中，大小为n
    int *a = new int[n];

    for(int i=0;i<n;i++)
        a[i]=rand()%40+20;
    int maxpos=0,minpos=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(a[i]>_ma){
            _ma=a[i];
            maxpos=i;
        }
        if(a[i]<_mi){
            _mi=a[i];
            minpos=i;
        }
    }
    ave=sum/n;//平均数

    double kx=(double)width/(n-1); //x轴的系数
    double ky=(double)height/_ma;//y方向的比例系数
    QPen pen,penPoint;
    pen.setColor(Qt::black);
    pen.setWidth(2);

    penPoint.setColor(Qt::blue);
    penPoint.setWidth(5);
    for(int i=0;i<n-1;i++)
    {
        //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
        painter.setPen(pen);//黑色笔用于连线
        painter.drawLine(pointx+kx*i,pointy-a[i]*ky,pointx+kx*(i+1),pointy-a[i+1]*ky);
        painter.setPen(penPoint);//蓝色的笔，用于标记各个点
        painter.drawPoint(pointx+kx*i,pointy-a[i]*ky);
    }
    painter.drawPoint(pointx+kx*(n-1),pointy-a[n-1]*ky);//绘制最后一个点

    //绘制平均线
    QPen penAve;
    penAve.setColor(Qt::red);//选择红色
    penAve.setWidth(2);
    penAve.setStyle(Qt::DotLine);//线条类型为虚线
    painter.setPen(penAve);
    painter.drawLine(pointx,pointy-ave*ky,pointx+width,pointy-ave*ky);

    //绘制最大值和最小值
    QPen penMaxMin;
    penMaxMin.setColor(Qt::darkGreen);//暗绿色
    painter.setPen(penMaxMin);
    painter.drawText(pointx+kx*maxpos-kx,pointy-a[maxpos]*ky-5, QString::number(_ma));
    painter.drawText(pointx+kx*minpos-kx,pointy-a[minpos]*ky+15,QString::number(_mi));

    penMaxMin.setColor(Qt::red);
    penMaxMin.setWidth(7);
    painter.setPen(penMaxMin);
    painter.drawPoint(pointx+kx*maxpos,pointy-a[maxpos]*ky);//标记最大值点
    painter.drawPoint(pointx+kx*minpos,pointy-a[minpos]*ky);//标记最小值点


    //绘制刻度线
    QPen penDegree;
    penDegree.setColor(Qt::black);
    penDegree.setWidth(2);
    painter.setPen(penDegree);
    //画上x轴刻度线
    int i;
    //for(i=0;i<10;i++)//分成10份
    for(i=0;i<10;i++)
    {
        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
        painter.drawLine(pointx+(i+1)*width/10,pointy,pointx+(i+1)*width/10,pointy+4);
        painter.drawText(pointx+(i+0.65)*width/10,pointy+10,QString::number((int)((i+1)*((double)n/10))));
    }
    //y轴刻度线
    double _maStep=(double)_ma/10;//y轴刻度间隔需根据最大值来表示
    for(int i=0;i<10;i++)
    {
        //代码较长，但是掌握基本原理即可。
        //主要就是确定一个位置，然后画一条短短的直线表示刻度。
        painter.drawLine(pointx,pointy-(i+1)*height/10,
                         pointx-4,pointy-(i+1)*height/10);
        painter.drawText(pointx-20,pointy-(i+0.85)*height/10,
                         QString::number((int)(_maStep*(i+1))));
    }
    */
}


void PlotWidget::RegulateXAxis(double dMin, double dMax, int iMaxAxisNum)
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

void PlotWidget::RegulateYAxis(double dMin, double dMax, int iMaxAxisNum)
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