// exmp1.h : main header file for the EXMP1 application
//

#if !defined(AFX_EXMP1_H__A0E42111_F0D8_481E_AD19_CD329FA2DE5B__INCLUDED_)
#define AFX_EXMP1_H__A0E42111_F0D8_481E_AD19_CD329FA2DE5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CExmp1App:
// See exmp1.cpp for the implementation of this class
//

class CExmp1App : public CWinApp
{
public:
	CExmp1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExmp1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExmp1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXMP1_H__A0E42111_F0D8_481E_AD19_CD329FA2DE5B__INCLUDED_)
