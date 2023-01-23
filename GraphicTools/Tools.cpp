// Tools.cpp : implementation file
//

#include "stdafx.h"
#include "GraphicTools.h"
#include "Tools.h"
#include ".\tools.h"


// CTools

IMPLEMENT_DYNAMIC(CTools, CPropertySheet)
CTools::CTools(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CTools::CTools(LPCTSTR pszCaption /*заголовок*/, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&preview);
 	AddPage(&settings);
}

CTools::~CTools()
{
}


BEGIN_MESSAGE_MAP(CTools, CPropertySheet)
END_MESSAGE_MAP()


// CTools message handlers

BOOL CTools::OnInitDialog()
{
	BOOL bResult = false;
	try
	{
        bResult = CPropertySheet::OnInitDialog();
    }
	catch (...)
	{
	}

	CRect r;
	GetWindowRect(&r);
	r.bottom -= 30;
	MoveWindow(&r);

	GetDlgItem(IDOK)->DestroyWindow();
	GetDlgItem(IDCANCEL)->DestroyWindow();
	GetDlgItem(IDHELP)->DestroyWindow();
	GetDlgItem(ID_APPLY_NOW)->DestroyWindow();

	return bResult;
}
