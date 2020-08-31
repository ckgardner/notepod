
// NotepodView.h : interface of the CNotepodView class
//

#pragma once


class CNotepodView : public CEditView
{
protected: // create from serialization only
	CNotepodView() noexcept;
	DECLARE_DYNCREATE(CNotepodView)

// Attributes
public:
	CNotepodDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CNotepodView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NotepodView.cpp
inline CNotepodDoc* CNotepodView::GetDocument() const
   { return reinterpret_cast<CNotepodDoc*>(m_pDocument); }
#endif

