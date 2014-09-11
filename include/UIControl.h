#ifndef __UICONTROL_H__
#define __UICONTROL_H__

namespace duisharp {
	/////////////////////////////////////////////////////////////////////////////////////
	//

	typedef CUIControl* (CALLBACK* FINDCONTROLPROC)(CUIControl*, LPVOID);

	class DUISHARP_API CUIControl
	{
	public:
		CUIControl();
		virtual ~CUIControl();

	public:
		virtual CStdString GetName() const;
		virtual void SetName(LPCTSTR pstrName);
		virtual LPCTSTR GetClass() const;
		virtual LPVOID GetInterface(LPCTSTR pstrName);
		virtual UINT GetControlFlags() const;

		virtual bool Activate();
		virtual CUIManager* GetManager() const;
		virtual void SetManager(CUIManager* pManager, CUIControl* pParent, bool bInit = true);
		virtual CUIControl* GetParent() const;
		
		// �ı����
		virtual CStdString GetText() const;
		virtual void SetText(LPCTSTR pstrText);
		virtual void SetFont(LPCTSTR pstrName);
		virtual CStdString GetFont() const;
		virtual UINT GetTextStyle() const;
		virtual void SetTextStyle(UINT uStyle);
		virtual DWORD GetTextColor() const;
		virtual void SetTextColor(DWORD dwTextColor);
		virtual void SetDisabledTextColor(DWORD dwTextColor);
		virtual DWORD GetDisabledTextColor() const;
		virtual void SetTextPadding(RECT rc);
		virtual RECT GetTextPadding() const;
		virtual bool IsShowHtml();
		virtual void SetShowHtml(bool bShowHtml = true);
		virtual int GetGlowSize() const;
		virtual void SetGlowSize(int nGlowSize);

		// ͼ�����
		DWORD GetBkColor() const;
		void SetBkColor(DWORD dwBackColor);
		LPCTSTR GetBkImage();
		void SetBkImage(LPCTSTR pStrImage);
		DWORD GetForeColor() const;
		void SetForeColor(DWORD dwForeColor);
		LPCTSTR GetForeImage();
		void SetForeImage(LPCTSTR pStrImage);
		DWORD GetBorderColor() const;
		void SetBorderColor(DWORD dwBorderColor);
		DWORD GetFocusBorderColor() const;
		void SetFocusBorderColor(DWORD dwBorderColor);
		bool IsColorHSL() const;
		void SetColorHSL(bool bColorHSL);
		int GetBorderSize() const;
		void SetBorderSize(int nSize);
		SIZE GetBorderRound() const;
		void SetBorderRound(SIZE cxyRound);
		bool DrawImage(HDC hDC, LPCTSTR pStrImage, LPCTSTR pStrModify = NULL);
		
		// λ�����
		virtual const RECT& GetPos() const;
		virtual void SetPos(RECT rc);
		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual int GetX() const;
		virtual int GetY() const;
		virtual RECT GetPadding() const;
		virtual void SetPadding(RECT rcPadding); // ������߾࣬���ϲ㴰�ڻ���
		virtual SIZE GetFixedXY() const;         // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedXY(SIZE szXY);      // ��floatΪtrueʱ��Ч
		virtual int GetFixedWidth() const;       // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedWidth(int cx);      // Ԥ��Ĳο�ֵ
		virtual int GetFixedHeight() const;      // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedHeight(int cy);     // Ԥ��Ĳο�ֵ
		virtual int GetMinWidth() const;
		virtual void SetMinWidth(int cx);
		virtual int GetMaxWidth() const;
		virtual void SetMaxWidth(int cx);
		virtual int GetMinHeight() const;
		virtual void SetMinHeight(int cy);
		virtual int GetMaxHeight() const;
		virtual void SetMaxHeight(int cy);
		
		// �����ؼ�
		virtual bool IsFloat() const;
		virtual void SetFloat(bool bFloat = true);
		virtual UINT GetFloatAlign() const;
		virtual void SetFloatAlign(UINT uAlign);
		virtual void SetFloatPadding(RECT rcPadding);
		virtual RECT GetFloatPadding() const;


		// �Զ���Ӧ��С
		virtual bool IsAutoWidth() const;
		virtual void SetAutoWidth(bool bAuto);
		virtual bool IsAutoHeight() const;
		virtual void SetAutoHeight(bool bAuto);

		// ����״̬
		virtual UINT GetLockStatus();
		virtual void SetLockStatus(UINT uLock);

		// �����ʾ
		virtual CStdString GetToolTip() const;
		virtual void SetToolTip(LPCTSTR pstrText);

		// ���
		virtual WORD GetCursor();
		virtual void SetCursor(WORD wCursor);

		// ��ݼ�
		virtual TCHAR GetShortcut() const;
		virtual void SetShortcut(TCHAR ch);

		// �˵�
		virtual bool IsContextMenuUsed() const;
		virtual void SetContextMenuUsed(bool bMenuUsed);

		// �û�����
		virtual const CStdString& GetUserData(); // �������������û�ʹ��
		virtual void SetUserData(LPCTSTR pstrText); // �������������û�ʹ��
		virtual UINT_PTR GetTag() const; // �������������û�ʹ��
		virtual void SetTag(UINT_PTR pTag); // �������������û�ʹ��

		// һЩ��Ҫ������
		virtual bool IsVisible() const;
		virtual void SetVisible(bool bVisible = true);
		virtual void SetInternVisible(bool bVisible = true); // �����ڲ����ã���ЩUIӵ�д��ھ������Ҫ��д�˺���
		virtual bool IsEnabled() const;
		virtual void SetEnabled(bool bEnable = true);
		virtual bool IsMouseEnabled() const;
		virtual void SetMouseEnabled(bool bEnable = true);
		virtual bool IsKeyboardEnabled() const;
		virtual void SetKeyboardEnabled(bool bEnable = true);
		virtual bool IsFocused() const;
		virtual void SetFocus();

		// ��ʱ������
		bool SetTimer(UINT nTimerID, UINT iElapse);
		void KillTimer(UINT nTimerID);

		// ֪ͨ��Ϣ����
<<<<<<< HEAD
		void SendNotify(LPCTSTR pstrMessage, WPARAM wParam = 0, LPARAM lParam = 0, bool bAsync = false);
		void SendNotify(TUINotify& Msg, bool bAsync = false);
=======
		void SendNotify(LPCTSTR pstrMessage, WPARAM wParam = 0, LPARAM lParam = 0, BOOL bAsync = FALSE);
		void SendNotify(TUINotify& Msg, BOOL bAsync = FALSE);
>>>>>>> origin/master

		// ��Ч����
		virtual bool IsEffectRunning(UINT uEffect);
		virtual UINT GetEffect();
		virtual void SetEffect(UINT uEffect);
		virtual UINT GetEffectTime();
		virtual void SetEffectTime(UINT uTime = 300);
		// uFlag:1-��ͼ��0-����
		virtual void StartEffect(UINT uTime = 0, UINT uFlag = 1, bool bClear = true);
		virtual void StopEffect(bool bMsg = true, bool bClear = true);

		virtual CUIControl* FindControl(FINDCONTROLPROC Proc, LPVOID pData, UINT uFlags);

		void Invalidate();
		bool IsUpdateNeeded() const;
		void NeedUpdate();
		void NeedParentUpdate();
		void NeedLayout();
		void NeedParentLayout();
		DWORD GetAdjustColor(DWORD dwColor);

	public:

		virtual void Init();
		virtual void DoInit();

		virtual void Event(TUIEvent& event);
		virtual void DoEvent(TUIEvent& event);

		virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		virtual void SetStyle(LPCTSTR pstrValue);
		CUIControl* ApplyAttributeList(LPCTSTR pstrList);

		virtual SIZE EstimateSize(SIZE szAvailable, bool bSized = true);

		virtual void DoPaint(HDC hDC, const RECT& rcPaint, UINT uType = 0);
		virtual bool PaintPre(HDC hDC, const RECT& rcPaint, UINT uType = 0);
		virtual bool PaintPost(HDC hDC, const RECT& rcPaint, UINT uType = 0);
		virtual void PaintBkColor(HDC hDC);
		virtual void PaintBkImage(HDC hDC);
		virtual void PaintStatusImage(HDC hDC);
		virtual void PaintForeColor(HDC hDC);
		virtual void PaintForeImage(HDC hDC);
		virtual void PaintText(HDC hDC);
		virtual void PaintBorder(HDC hDC);
		virtual void PaintIconImage(HDC hDC);

		virtual void DoPostPaint(HDC hDC, const RECT& rcPaint, UINT uType = 0);
		// ��Ч���ƺ���
		virtual void EffectPaint(HDC hDC, RECT rcPaint, UINT &uRet);

	public:
		CEventSource OnInit;
		CEventSource OnDestroy;
		CEventSource OnSize;
		CEventSource OnEvent;
		CEventSource OnNotify;

	protected:
		CUIManager* m_pManager;
		CUIControl* m_pParent;
		CStdString m_sName;
		bool m_bUpdateNeeded;
		bool m_bLayoutNeeded;
		bool m_bMenuUsed;
		RECT m_rcItem;
		RECT m_rcPadding;
		SIZE m_cXY;
		SIZE m_cxyFixed;
		SIZE m_cxyMin;
		SIZE m_cxyMax;
		bool m_bVisible;
		bool m_bInternVisible;
		bool m_bEnabled;
		bool m_bMouseEnabled;
		bool m_bKeyboardEnabled ;
		bool m_bFocused;
		bool m_bFloat;
		UINT m_uFloatAlign;
		RECT m_rcFloatPadding;
		bool m_bSetPos; // ��ֹSetPosѭ������
		bool m_bSized;

		CStdString m_sFont;
		CStdString m_sText;
		DWORD m_dwTextColor;
		DWORD m_dwDisabledTextColor;
		UINT m_uTextStyle;
		RECT m_rcTextPadding;
		bool m_bShowHtml;
		int m_nGlowSize;
		bool m_bAutoWidth;
		bool m_bAutoHeight;
		UINT m_uLockStatus;

		CStdString m_sToolTip;
		WORD m_wCursor;
		TCHAR m_chShortcut;
		CStdString m_sUserData;
		UINT_PTR m_pTag;

		DWORD m_dwBackColor;
		CStdString m_sBkImage;
		DWORD m_dwForeColor;
		CStdString m_sForeImage;
		DWORD m_dwBorderColor;
		DWORD m_dwFocusBorderColor;
		bool m_bColorHSL;
		int m_nBorderSize;
		SIZE m_cxyBorderRound;
		RECT m_rcPaint;
		// ������Ч����
		bool m_bEffect;
		UINT m_uEffect;
		UINT m_uEffectTime;
		UINT m_uHalfEffectTime;
		double m_fXDistance;
		double m_fYDistance;
		double m_fXSpeed;
		double m_fYSpeed;
		double m_fXStep;
		double m_fYStep;
		RECT m_rcEffect;
		HBITMAP m_hBitmap;
		RECT m_rcWnd;
	};

} // namespace duisharp

#endif // __UICONTROL_H__
