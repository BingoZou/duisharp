// Implementation of the CNotifyIconData class and the CTrayIconImpl template.
#pragma once
#include <ShellAPI.h>

// Wrapper class for the Win32 NOTIFYICONDATA structure
class CNotifyIconData : public NOTIFYICONDATA
{
public:	
	CNotifyIconData()
	{
		memset(this, 0, sizeof(NOTIFYICONDATA));
		cbSize = sizeof(NOTIFYICONDATA);
	}
};

// Template used to support adding an icon to the taskbar.
// This class will maintain a taskbar icon and associated context menu.
template <class T>
class CTrayIconImpl
{
public:
	CTrayIconImpl() 
	{
		m_bInstalled = false;
		m_nMenuID = 0;
		m_nDefault = 0;
		// ע��������Ϣ
		WM_TRAYICON = ::RegisterWindowMessage(_T("WM_TRAYICON"));
	}

	~CTrayIconImpl()
	{
		RemoveIcon();
	}

public:
	BEGIN_UIMSG_MAP(CTrayIconImpl)
		UIMESSAGE_HANDLER(WM_TRAYICON, OnTrayIcon)
	END_UIMSG_MAP()

public:
	bool IsInstalled() const
	{
		return m_bInstalled;
	}

	// ���ò˵���ԴID
	void SetMenuID(int nID)
	{
		m_nMenuID = nID;
	}

	// ���ò˵�Ĭ����ID
	inline void SetDefaultItem(UINT nID) 
	{ 
		m_nDefault = nID; 
	}

	// ��װ������ͼ��
	// 	lpszToolTip - ��ʾ��Ϣ
	//	hIcon - ͼ����
	// 	nID	- �˵�����ԴID
	bool InstallIcon(LPCTSTR lpszToolTip, HICON hIcon, UINT nID)
	{
		T* pT = static_cast<T*>(this);
		// ��ʼ������	
		m_nid.hWnd = pT->GetHWND();
		m_nid.uID = nID;
		m_nid.hIcon = hIcon;
		m_nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
		m_nid.uCallbackMessage = WM_TRAYICON;
		_tcscpy(m_nid.szTip, lpszToolTip);
		// ��װ
		m_bInstalled = Shell_NotifyIcon(NIM_ADD, &m_nid) ? true : false;

		return m_bInstalled;
	}

	// �Ƴ�������ͼ��
	bool RemoveIcon()
	{
		if (!m_bInstalled)
			return false;

		m_bInstalled = false;

		// �Ƴ�
		m_nid.uFlags = 0;
		int i=0;
		BOOL bRet = FALSE;
		bRet = Shell_NotifyIcon(NIM_DELETE, &m_nid);
		return TRUE == bRet;
	}

	// ������ʾ��Ϣ����
	bool SetTooltipText(LPCTSTR pszTooltipText)
	{
		if (pszTooltipText == NULL)
			return FALSE;

		// ��ʼ������
		m_nid.uFlags = NIF_TIP;
		_tcscpy(m_nid.szTip, pszTooltipText);

		// ��������
		return Shell_NotifyIcon(NIM_MODIFY, &m_nid) ? true : false;
	}

	LRESULT OnTrayIcon(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		if (wParam != m_nid.uID)
			return 0;

		T* pT = static_cast<T*>(this);

		// ���ز˵�
		CMenu oMenu;
		if (!oMenu.LoadMenu(m_nMenuID)) return 0;

		if ( LOWORD(lParam) == WM_RBUTTONUP ) {
			CMenuHandle oPopup(oMenu.GetSubMenu(0));
			pT->PrepareMenu(oPopup);

			SetForegroundWindow(pT->GetHWND());
			if (m_nDefault == 0)
				oPopup.SetMenuDefaultItem(0, TRUE);
			else
				oPopup.SetMenuDefaultItem(m_nDefault);

			POINT pos = {0};
			GetCursorPos(&pos);
			oPopup.TrackPopupMenu(TPM_LEFTALIGN | TPM_NONOTIFY, pos.x, pos.y, pT->GetHWND());
			pT->PostMessage(WM_NULL);
		}
		else if ( LOWORD(lParam) == WM_LBUTTONDOWN )
		{
			::SetForegroundWindow(pT->GetHWND());

			CMenuHandle oPopup(oMenu.GetSubMenu(0));			
			if ( m_nDefault ) {
				pT->SendMessage(WM_COMMAND, m_nDefault, 0);
			}
			else {
				UINT nItem = oPopup.GetMenuItemID(0);
				pT->SendMessage(WM_COMMAND, nItem, 0);
			}
		}
		// ���ٲ˵�
		oMenu.DestroyMenu();
		return 0;
	}

	// ��ʾ��ʾ��Ϣ
	BOOL ShowBalloon(PTSTR szBalloonTitle, PTSTR szBalloonMsg, DWORD dwIcon, UINT nTimeOut)
	{
		ASSERT (dwIcon == NIIF_WARNING || dwIcon == NIIF_ERROR || dwIcon == NIIF_INFO || dwIcon == NIIF_NONE);
		BOOL bBalloonShown = FALSE;

		m_nid.dwInfoFlags = dwIcon;
		m_nid.uFlags |= NIF_INFO;
		m_nid.uTimeout = nTimeOut;
		_tcscpy(m_nid.szInfoTitle, szBalloonTitle);
		_tcscpy(m_nid.szInfo, szBalloonMsg);

		bBalloonShown = ::Shell_NotifyIcon(NIM_MODIFY, &m_nid);

		return bBalloonShown;  
	}

	// �Բ˵���������ò���
	virtual void PrepareMenu(HMENU hMenu)
	{

	}

private:
	UINT WM_TRAYICON;
	CNotifyIconData m_nid;
	bool m_bInstalled;
	UINT m_nDefault;
	int m_nMenuID;
};
