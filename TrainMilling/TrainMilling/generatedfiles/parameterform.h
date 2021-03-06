///////////////////////////////////////////////////////////////////////////////
/*! \file	parameterform.h
 *  \author
 *  \date
 *  \brief	Definition file for class parameterform
 *
 *
 *  (C) Copyright Siemens AG A&D MC 2004. All rights reserved.
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef PARAMETERFORM_H_INCLUDED
#define PARAMETERFORM_H_INCLUDED

#include "ui_parameterform.h" //vom UIC erzeugte Header-Datei
#include "slgfwdialogform.h"



/*! \class parameterform
 *  \brief
*/
class ParameterForm : public SlGfwDialogForm,
					public Ui::ParameterFormUi
{
    Q_OBJECT


public:
	int nMillingModuleSelect;
	int nMillingAxisSpeedSelect;
	double fTrainSpeed;
    ///////////////////////////////////////////////////////////////////////////
    // CREATORS
    ///////////////////////////////////////////////////////////////////////////

    /*!
     *	\fn parameterform(QWidget* pParent = 0, const QString& rszName = QString::null)
     *
     *  Constructor
    */
    ParameterForm(QWidget* pParent = 0, const QString& rszName = QString::null);

    /*! \fn virtual ~parameterform(void)
     *
     *  Destructor
    */
    virtual ~ParameterForm(void);



///////////////////////////////////////////////////////////////////////////////
// Overrides
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// public ACCESSORS
///////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////
// MANIPULATORS - system overrides
///////////////////////////////////////////////////////////////////////////////


public slots:

///////////////////////////////////////////////////////////////////////////////
// public SLOTS - system overrides
///////////////////////////////////////////////////////////////////////////////
/*!
*  \fn virtual void onFunction(const QString& rszFunction, const QString& rszArgs, bool& rbHandled);
*
*  Will be called by the framework, if a function should be executed, e.g. if a softkey
*  should execute a command
*/
virtual void onFunction (const QString& rszFunction, const QString& rszArgs, bool& rbHandled);


private:

///////////////////////////////////////////////////////////////////////////////
// member variables
///////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////
// private METHODS
///////////////////////////////////////////////////////////////////////////////



};

#endif // PARAMETERFORM_H_INCLUDED
