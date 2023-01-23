// Preview.cpp : implementation file
//

#include "stdafx.h"
#include "GraphicTools.h"
#include "Preview.h"
#include ".\preview.h"


// CPreview dialog

IMPLEMENT_DYNAMIC(CPreview, CPropertyPage)
CPreview::CPreview()
	: CPropertyPage(CPreview::IDD)
{
}

CPreview::~CPreview()
{
}

void CPreview::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COLOR, m_Color);
	DDX_Control(pDX, IDC_TEXT, m_Text);
}


BEGIN_MESSAGE_MAP(CPreview, CPropertyPage)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_HOTKEY, OnHotKey)
END_MESSAGE_MAP()


// CPreview message handlers

BOOL CPreview::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	clColor = GetSysColor(COLOR_BTNFACE);
	hDesktop = ::GetDC(NULL); // окно с дескриптором Null - desktop

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPreview::OnSetActive() // когда переключаемся на закладку
{
	SetTimer(1, 100, 0);

	return CPropertyPage::OnSetActive();
}

BOOL CPreview::OnKillActive() // уходим с закладки
{
	KillTimer(0);

	return CPropertyPage::OnKillActive();
}

void CPreview::OnTimer(UINT nIDEvent)
{
	CPoint pt;
	GetCursorPos(&pt);
	clColor = ::GetPixel(hDesktop, pt.x, pt.y);

	CString s, t;
	t.Format("RGB(%d,%d,%d)", clColor & 0xFF, clColor >> 8 & 0xFF, clColor >> 16);
	s += t + "\r\n";

	t.Format("#%02X%02X%02X", clColor & 0xFF, clColor >> 8 & 0xFF, clColor >> 16);
	s += t + "\r\n";

	t.Format("%#06X", clColor);
	s += t + "\r\n";

	m_Text.SetWindowText(s);
	m_Color.Invalidate(0);
	CPropertyPage::OnTimer(nIDEvent);
}

HBRUSH CPreview::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);

	if(pWnd == &m_Color)
	{
		HBRUSH br = (HBRUSH) GetStockObject(DC_BRUSH);
		SetDCBrushColor(pDC->GetSafeHdc(), clColor);
		return br;
	}
	return hbr;
}

LRESULT CPreview::OnHotKey(WPARAM wParam /*номер комбинации*/, LPARAM lParam /*в младшей части - модификатор, в старших - клавиша*/)
{
	if(!OpenClipboard()) // открывает клипборд
	{
		MessageBox("Не дало");
		return -1;
	}
	EmptyClipboard(); // очистка клипборда

	CString s;
	m_Text.GetWindowText(s);

	// выделение памяти для клипборда
	HANDLE h = GlobalAlloc(GMEM_MOVEABLE /*память переносимая*/, s.GetLength() + 1);
	char * p = (char *) GlobalLock(h); // блокирует память, чтобы она не перемещалась
	lstrcpy(p, s);

	GlobalUnlock(h);

	SetClipboardData(CF_TEXT, p);
	CloseClipboard();

	return 0;
}
