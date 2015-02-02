#ifndef __UISHADOW_H__
#define __UISHADOW_H__

namespace duisharp
{
	class CUIManager;
	class DUISHARP_API CUIShadow
	{
	public:
		CUIShadow(void);
		virtual ~CUIShadow(void);

	public:
		static bool Initialize(HINSTANCE hInstance);

		void Create(HWND hParent, CUIManager *pManager = NULL);
		bool IsShadowed(HWND hParent) const;
		bool IsEnable() const;
		void SetEnable(bool bEnable = true);
		CStdString GetImage();
		void SetImage(LPCTSTR pImage);
		RECT GetBorder() const;
		void SetBorder(RECT rcBorder);
		RECT GetOffset() const;
		void SetOffset(RECT rcOffset);
		bool IsTrans() const;
		void SetTrans(bool bTrans = true);
		bool IsPrepared() const;
		void SetPrepared(bool bPrepared = true);

	protected:
		// ��������Ϣ������
		static LRESULT CALLBACK ParentProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		LRESULT OnWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		LRESULT OnParentProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		// ˢ��
		void Update(HWND hParent);
		// ��ʾ
		void Show(HWND hParent, bool bFast = true);
		void ShowShadow(bool bVisible, bool bFast = false);

	private:
		// �ྲ̬����������ʵ�������������Ӱ����
		static HINSTANCE s_hInstance;
		static CStdStringPtrMapImpl<CUIShadow*> s_Shadowmap;

	private:
		// ��ӰͼƬ
		CStdString m_sImage;
		// UI������
		CUIManager* m_pManager;
		// �Ƿ�ˢ��
		bool m_bUpdate;
		// �Ƿ�ɼ�
		bool m_bVisible;
		// �Ƿ�����
		bool m_bEnabled;
		// �Ƿ�Ͷ�������Ϣ
		bool m_bTrans;
		// �Ƿ������ƶ�
		bool m_bMoving;
		// ��Ӱ��С
		RECT m_rcBorder;
		// ƫ����
		RECT m_rcOffset;
		// ��ʼλ��
		POINT m_ptPos;
		// ���ڴ�С
		LPARAM m_WndSize;
		// ���ھ��
		HWND m_hWnd;
		// ��������Ϣ������
		WNDPROC m_OriParentProc;
		// ˫����
		HDC m_hDcPaint;
		HDC m_hDcBuffer;
		HBITMAP m_hBmpBuffer;
		// �������Ƿ񲼾����
		bool m_bPrepared;
	};
}

#endif //__UISHADOW_H__