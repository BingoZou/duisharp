#ifndef __UIGIF_H__
#define __UIGIF_H__

namespace duisharp {

	struct GIFFrame    // structure that keeps a single frame info
	{
		TImageInfo* pImage;
		SIZE frameSize;
		SIZE frameOffset;
		UINT nDelay;       // delay (in 1/100s of a second)
		UINT nDisposal;    // disposal method
	};

	typedef std::vector<GIFFrame> GIFFRAME;
	typedef std::vector<GIFFrame>::iterator GIFFRAMEITER;
	
	struct TGIFHeader;
	struct TGIFLSDescriptor;

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

		SIZE GetSize() const;
		int GetWidth() const;
		int GetHeight() const;
		int GetFrame() const;
		int GetFrames() const;
		COLORREF GetBkColor() const;

		LPCTSTR GetGifImage();
		void SetGifImage(LPCTSTR pStrImage);

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void DoEvent(TUIEvent& event);

		void PaintBkImage(HDC hDC);

	private:
		int GetNextBlockLen() const;
		BOOL SkipNextBlock();
		BOOL SkipNextGraphicBlock();
		void ResetDataPointer();
		enum GIFBlockTypes GetNextBlock() const;
		UINT GetSubBlocksLen(UINT nStartingOffset) const;
		LPBYTE GetNextGraphicBlock(UINT* pBlockLen, UINT* pDelay, SIZE* pBlockSize, SIZE* pBlockOffset, UINT* pDisposal);

	protected:
		CStdString m_sGifImage;
		bool m_bGifGdi;

	private:
		unsigned char* m_pRawData;		// ����ʱ�����ݴ涯���ļ����� ����������������Ч
		UINT m_nDataSize;				// GIF�ļ���С
		TGIFHeader* m_pGIFHeader;		// GIF�ļ�ͷ
		TGIFLSDescriptor* m_pGIFLSDescriptor; // �߼���Ļ��ʶ��
		UINT m_nGlobalCTSize;			// ȫ����ɫ�б��С
		SIZE m_szGif;					// ͼ��ߴ�
		COLORREF m_clrBackground;		// ����ɫ
		volatile long m_nCurrFrame;	// ��ǰ֡����ֵ
		UINT m_nCurrOffset;			// ���ȡƫ����

		// ��������
		UINT *m_puFrameElapse;			// ֡���
		UINT m_nFramePosition;			// ��ǰ֡
		GIFFRAME* m_pvFrames;			// ֡����
		bool m_bGif;					// �Ƿ�GifͼƬ
		bool m_bPlaying;				// �Ƿ����ڲ���
	};
} // namespace duisharp

#endif // __UIGIF_H__
