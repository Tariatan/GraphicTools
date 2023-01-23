#pragma once
#include "afxcmn.h"


// CSettings dialog

class CSettings : public CPropertyPage
{
	DECLARE_DYNAMIC(CSettings)

public:
	CSettings();
	virtual ~CSettings();

// Dialog Data
	enum { IDD = IDD_SETTINGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CHotKeyCtrl m_HotKey;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedApply();
};
