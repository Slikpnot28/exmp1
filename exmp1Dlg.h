// exmp1Dlg.h : header file
//

#if !defined(AFX_EXMP1DLG_H__9BE9E879_ED3C_4F87_8A41_F7228F42C0E8__INCLUDED_)
#define AFX_EXMP1DLG_H__9BE9E879_ED3C_4F87_8A41_F7228F42C0E8__INCLUDED_

#include "MemDC.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExmp1Dlg dialog

class CExmp1Dlg : public CDialog
{
// Construction
public:
	CExmp1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExmp1Dlg)
	enum { IDD = IDD_EXMP1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExmp1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExmp1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_nSel;
	enum {IMG_CNT = 8};
	CMemDC m_mdc[IMG_CNT];
	CRect m_rect[IMG_CNT - 1];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXMP1DLG_H__9BE9E879_ED3C_4F87_8A41_F7228F42C0E8__INCLUDED_)
