// Settings.cpp : implementation file
//

#include "stdafx.h"
#include "GraphicTools.h"
#include "Settings.h"
#include ".\settings.h"


// CSettings dialog

IMPLEMENT_DYNAMIC(CSettings, CPropertyPage)
CSettings::CSettings()
	: CPropertyPage(CSettings::IDD)
{
}

CSettings::~CSettings()
{
}

void CSettings::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HOTKEY1, m_HotKey);
}


BEGIN_MESSAGE_MAP(CSettings, CPropertyPage)
	ON_BN_CLICKED(IDC_APPLY, OnBnClickedApply)
END_MESSAGE_MAP()


// CSettings message handlers

BOOL CSettings::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	m_HotKey.SetRules(HKCOMB_NONE, HOTKEYF_CONTROL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
#include "Tools.h"
void CSettings::OnBnClickedApply()
{
	WORD Key, m;
	m_HotKey.GetHotKey(Key, m);

	UINT mod = 0;
	if(m & HOTKEYF_CONTROL)
		mod |= MOD_CONTROL;
	if(m & HOTKEYF_SHIFT)
		mod |= MOD_SHIFT;
	if(m & HOTKEYF_ALT)
		mod |= MOD_ALT;
	if(m & HOTKEYF_EXT)
		mod |= MOD_WIN;	

	if(!RegisterHotKey(((CTools *) GetParent())->GetPage(0)->m_hWnd, 1, mod, Key))
		MessageBox("Не дала");
}
