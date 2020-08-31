
// NotepodView.cpp : implementation of the CNotepodView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Notepod.h"
#endif

#include "NotepodDoc.h"
#include "NotepodView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepodView

IMPLEMENT_DYNCREATE(CNotepodView, CEditView)

BEGIN_MESSAGE_MAP(CNotepodView, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNotepodView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CNotepodView construction/destruction

CNotepodView::CNotepodView() noexcept
{
	// TODO: add construction code here

}

CNotepodView::~CNotepodView()
{
}

BOOL CNotepodView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CNotepodView printing


void CNotepodView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CNotepodView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CNotepodView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CNotepodView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CNotepodView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNotepodView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CNotepodView diagnostics

#ifdef _DEBUG
void CNotepodView::AssertValid() const
{
	CEditView::AssertValid();
}

void CNotepodView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CNotepodDoc* CNotepodView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNotepodDoc)));
	return (CNotepodDoc*)m_pDocument;
}
#endif //_DEBUG


// CNotepodView message handlers
