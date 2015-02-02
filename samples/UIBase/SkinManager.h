#ifndef __SKIN_MANAGER_H__
#define __SKIN_MANAGER_H__

typedef struct _tagUISkinInfo
{
	UINT uType;				// 0-��ɫ��1-ͼƬ
	DWORD dwColor;			// ��ɫֵ
	TCHAR szBg[MAX_PATH];	// ͼƬ����
}TUISkinInfo;

typedef class CObserverImpl<bool, TUISkinInfo> CSkinChangedObserver;
typedef class CReceiverImpl<bool, TUISkinInfo> CSkinChangedReceiver;

class CSkinManager
{
public:
	static CSkinManager* GetSkinManager()
	{
		if (m_pSkinManager == NULL)
		{
			m_pSkinManager = new CSkinManager();	
		}

		return m_pSkinManager;
	}

public:
	void AddReceiver(CReceiverImpl<bool, TUISkinInfo>* receiver)
	{
		m_SkinChangeObserver.AddReceiver(receiver);
	}

	void RemoveReceiver(CReceiverImpl<bool, TUISkinInfo>* receiver)
	{
		m_SkinChangeObserver.RemoveReceiver(receiver);
	}

	void Broadcast(TUISkinInfo param)
	{
		m_SkinChangeObserver.Broadcast(param);
	}

	void Notify(TUISkinInfo param)
	{
		m_SkinChangeObserver.Notify(param);
	}

private:
	CSkinManager(){}

private:
	CSkinChangedObserver m_SkinChangeObserver;
	static CSkinManager* m_pSkinManager;
};

CSkinManager* CSkinManager::m_pSkinManager = NULL;

#endif // __SKIN_MANAGER_H__