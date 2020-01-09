#pragma once  
#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include "QWidget.h"
#include "QPainter.h"
#include "QMath.h"

class  AxisRange
{
public:
  double lower, upper;
  static const double minRange; //1e-280;
  static const double maxRange; //1e280;
};

#define DisplayMode_NoLabel         0x00
#define DisplayMode_DashLabel       0x01
#define DisplayMode_SolidLabel      0x02

class PlotWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlotWidget(QWidget *parent = 0);
    ~PlotWidget();
public:
        QVector<double>	datax;
        QVector<double> datay;
        QVector<int>	pixelx;
        QVector<int>    pixely;
        AxisRange       xAxisRange;
        AxisRange       yAxisRange;
		int				xAxisIndex;
		int				yAxisIndex;

        int             mRectWidth;
        int             mRectHeight;
        int             mpadding;
        QPoint          OPoint;
        QColor          mBKColor;
        int             mDisplayMode;
        int             mYellowLabelIndex;
public:
		void clearData();
		void setData(const QVector<double> &x, const QVector<double> &y);
		void setBKColor(QColor c);
		void ClearBKColor();
		void setDisplayMode(int nMode);
		int IncreaseLabel();
		int DecreaseLabel();
		int QuickIncreaseLabel();
		int QuickDecreaseLabel();
		int GetLabelIndex();
		bool IsEmpty();
		void setXRange(double lower, double upper);
		void setYRange(double lower, double upper);
		void RegulateXAxis(double dMin, double dMax, int iMaxAxisNum);
		void RegulateYAxis(double dMin, double dMax, int iMaxAxisNum);


protected:
    void paintEvent(QPaintEvent *e);
};


#endif // PLOTWIDGET_H
