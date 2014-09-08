#ifndef __UIGIF_H__
#define __UIGIF_H__

namespace duisharp {

	struct GIFFrame    // structure that keeps a single frame info
	{
		TImageInfo* pImage;
		UINT nDelay;       // delay (in 1/100s of a second)
	};
	
	enum enGifTimer
	{
		TIMER_GIF = UITIMER_ID_ANIMATION,
	};

	class DUISHARP_API CUIGif : public CUILabel
	{
	public:
		CUIGif();
		~CUIGif();

	public:
		static bool IsGif(const LPBYTE pData, DWORD dwSize);

	public:
		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

	public:
		bool Load(const LPBYTE pData, DWORD dwSize, DWORD dwMask = 0);
		void UnLoad();

		bool IsGif();
		bool Play();
		void Stop();
		bool IsPlaying() const;

		int GetFrame() const;
		int GetFrames() const;
		COLORREF GetBkColor() const;

		LPCTSTR GetGifImage();
		void SetGifImage(LPCTSTR pStrImage);

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void DoEvent(TUIEvent& event);

		void PaintBkImage(HDC hDC);

	protected:
		CStdString m_sGifImage;
		bool m_bGif;							// �Ƿ�GifͼƬ
		bool m_bPlaying;						// �Ƿ����ڲ���
		COLORREF m_clrBackground;				// ����ɫ
		CStdPtrArrayImpl<GIFFrame*> m_vFrames;	// ֡����
		volatile long m_nCurrFrame;				// ��ǰ֡����ֵ
	};
} // namespace duisharp

#endif // __UIGIF_H__
