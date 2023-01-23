#pragma once
#include "Preview.h"
#include "Settings.h"


// CTools

class CTools : public CPropertySheet
{
	DECLARE_DYNAMIC(CTools)
	CPreview preview;
	CSettings settings;
public:
	CTools(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CTools(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CTools();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};


