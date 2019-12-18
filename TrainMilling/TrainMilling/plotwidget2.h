///////////////////////////////////////////////////////////////////////////////
/*! \file	plotwidget2.h
 *  \author
 *  \date
 *  \brief	Definition file for class PlotWidget2
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef PLOTWIDGET2_H_INCLUDED
#define PLOTWIDGET2_H_INCLUDED

#include "QWidget.h"
#include "plotwidget.h"
#include "qMath.h"
/*! \class PlotWidget2
 *  \brief
*/
class PlotWidget2 : public QWidget
{
    Q_OBJECT


public:

    PlotWidget2(QWidget* pParent = 0);
    virtual ~PlotWidget2(void);

public:
        QVector<double>	datax;
        QVector<double> datay1;
        QVector<double> datay2;
        QVector<double> datay3;
        QVector<int>	pixelx;
        QVector<int>    pixely1;
        QVector<int>    pixely2;
        QVector<int>    pixely3;

		AxisRange       xAxisRange;
        AxisRange       yAxisRange;
		int				xAxisIndex;
		int				yAxisIndex;

		int				mPointsCnt;
        int             mRectWidth;
        int             mRectHeight;
        int             mpadding;
        QPoint          OPoint;
		QPoint			pressPoint;
		QPoint			movePoint;
		QPoint			releasePoint;
		QPoint			WidgetPoint;
        QColor          mBKColor;
		bool			m_bFirstTime;
		bool			m_bMouseMove;
		int				m_nMouseMoveCnt;
		int				m_nZoom;
public:
		void clearData();
		void addData(double x,double y1,double y2,double y3);
		//svoid setData(const QVector<double> &x, const QVector<double> &y1,const QVector<double> &y2);
		void setBKColor(QColor c);
		void ClearBKColor();
		void setXRange(double lower, double upper);
		void setYRange(double lower, double upper);
		bool zoomIn();
		bool zoomOut();
		void restoreZoom();
		bool isZoomInAndOut();
		bool isEmpty();
		void RegulateXAxis(double dMin, double dMax, int iMaxAxisNum);
		void RegulateYAxis(double dMin, double dMax, int iMaxAxisNum);

protected:
		void paintEvent(QPaintEvent *e);
		void mousePressEvent(QMouseEvent *);
		void mouseReleaseEvent(QMouseEvent *);
		void mouseMoveEvent(QMouseEvent *);

};

#endif // PLOTWIDGET2_H_INCLUDED
