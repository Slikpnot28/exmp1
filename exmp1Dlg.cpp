// exmp1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "exmp1.h"
#include "exmp1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExmp1Dlg dialog

CExmp1Dlg::CExmp1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExmp1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExmp1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nSel = 0;
}

void CExmp1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExmp1Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExmp1Dlg, CDialog)
	//{{AFX_MSG_MAP(CExmp1Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExmp1Dlg message handlers

BOOL CExmp1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	ModifyStyle(GetStyle(),0);
	ModifyStyleEx(GetExStyle(),0);
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);
	double ratiox = cx / 1024.0;
	double ratioy = cy / 768.0;
	
	m_rect[1] = CRect((int)(373 * ratiox),(int)(199 * ratioy),
						(int)(653 * ratiox),(int)(235 * ratioy));
	m_rect[2] = CRect((int)(373 * ratiox),(int)(247 * ratioy),
						(int)(653 * ratiox),(int)(280 * ratioy));
	m_rect[3] = CRect((int)(373 * ratiox),(int)(294 * ratioy),
						(int)(653 * ratiox),(int)(328 * ratioy));
	m_rect[4] = CRect((int)(373 * ratiox),(int)(342 * ratioy),
						(int)(501 * ratiox),(int)(376 * ratioy));
	m_rect[5] = CRect((int)(523 * ratiox),(int)(341 * ratioy),
						(int)(653 * ratiox),(int)(376 * ratioy));
	m_rect[6] = CRect((int)(373 * ratiox),(int)(389 * ratioy),
						(int)(653 * ratiox),(int)(423 * ratioy));
	m_rect[7] = CRect((int)(373 * ratiox),(int)(475 * ratioy),
						(int)(653 * ratiox),(int)(510 * ratioy));
	int i = 1;
	CString str;
	while(i <= IMG_CNT)
	{
		str.Format("./img/%d.bmp",i);
		m_mdc[i%8].LoadBitmap(str);
		i++;
	}

	MoveWindow(0,0,cx,cy);
	m_nSel = 0;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExmp1Dlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CMemDC &mdc = m_mdc[m_nSel];
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);
	dc.StretchBlt(0,0,cx,cy,&mdc,0,0,mdc.Width(),mdc.Height(),SRCCOPY);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExmp1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CExmp1Dlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	int i = 1;
	while(i < IMG_CNT)
	{
		if(m_rect[i].PtInRect(point))
		{
			if(m_nSel != i)
			{
				m_nSel = i;
				Invalidate(FALSE);
			}
			break;
		}
		i++;
	}
	if(i == IMG_CNT && m_nSel != 0)
	{
		m_nSel = 0;
		Invalidate(FALSE);
	}

	CDialog::OnMouseMove(nFlags, point);
}

void CExmp1Dlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_rect[6].PtInRect(point))
	{
		EndDialog(IDOK);
	}
	
}
