#pragma once
#include "afxwin.h"


// CPreview dialog

class CPreview : public CPropertyPage
{
	DECLARE_DYNAMIC(CPreview)

	COLORREF clColor;
	HDC hDesktop;
public:
	CPreview();
	virtual ~CPreview();

// Dialog Data
	enum { IDD = IDD_PREVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_Color;
	CStatic m_Text;
	virtual BOOL OnInitDialog();
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
};
