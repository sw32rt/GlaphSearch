
// GlaphSearchDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "GlaphSearch.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "BestFirstSearch.h"
#include "GlaphSearchDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGlaphSearchDlg ダイアログ



CGlaphSearchDlg::CGlaphSearchDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLAPHSEARCH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGlaphSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT1, m_ddx_ShortestPathText1);
}

void CGlaphSearchDlg::CreateMap(void)
{
	for (int x = 0; x < m_MapSize; x++)
	{
		for (int y = 0; y < m_MapSize; y++)
		{
			m_Vlist.push_back(Vertex(15 + (x * 20), 15 + (y * 20)));
		}
	}

	
	/* 迷路 start */
	{
		m_Elist.push_back(Edge(to_1d(0, 0), to_1d(0, 1)));
		m_Elist.push_back(Edge(to_1d(0, 0), to_1d(1, 0)));
		m_Elist.push_back(Edge(to_1d(0, 1), to_1d(0, 2)));
		m_Elist.push_back(Edge(to_1d(0, 2), to_1d(0, 3)));
		m_Elist.push_back(Edge(to_1d(0, 3), to_1d(0, 4)));
		m_Elist.push_back(Edge(to_1d(0, 3), to_1d(1, 3)));
		m_Elist.push_back(Edge(to_1d(0, 4), to_1d(0, 5)));
		m_Elist.push_back(Edge(to_1d(0, 4), to_1d(1, 4)));
		m_Elist.push_back(Edge(to_1d(0, 5), to_1d(0, 6)));
		m_Elist.push_back(Edge(to_1d(0, 5), to_1d(1, 5)));
		m_Elist.push_back(Edge(to_1d(0, 6), to_1d(0, 7)));
		m_Elist.push_back(Edge(to_1d(0, 6), to_1d(1, 6)));
		m_Elist.push_back(Edge(to_1d(0, 7), to_1d(0, 8)));
		m_Elist.push_back(Edge(to_1d(0, 8), to_1d(0, 9)));
		m_Elist.push_back(Edge(to_1d(0, 9), to_1d(0, 10)));
		m_Elist.push_back(Edge(to_1d(0, 9), to_1d(1, 9)));
		m_Elist.push_back(Edge(to_1d(0, 10), to_1d(0, 11)));
		m_Elist.push_back(Edge(to_1d(0, 11), to_1d(0, 12)));
		m_Elist.push_back(Edge(to_1d(0, 11), to_1d(1, 11)));
		m_Elist.push_back(Edge(to_1d(0, 12), to_1d(0, 13)));
		m_Elist.push_back(Edge(to_1d(0, 13), to_1d(0, 14)));
		m_Elist.push_back(Edge(to_1d(0, 14), to_1d(0, 15)));
		m_Elist.push_back(Edge(to_1d(0, 14), to_1d(1, 14)));
		m_Elist.push_back(Edge(to_1d(0, 15), to_1d(0, 16)));
		m_Elist.push_back(Edge(to_1d(0, 16), to_1d(0, 17)));
		m_Elist.push_back(Edge(to_1d(0, 17), to_1d(0, 18)));
		m_Elist.push_back(Edge(to_1d(0, 17), to_1d(1, 17)));
		m_Elist.push_back(Edge(to_1d(0, 18), to_1d(0, 19)));
		m_Elist.push_back(Edge(to_1d(0, 19), to_1d(0, 20)));
		m_Elist.push_back(Edge(to_1d(0, 20), to_1d(0, 21)));
		m_Elist.push_back(Edge(to_1d(0, 20), to_1d(1, 20)));
		m_Elist.push_back(Edge(to_1d(0, 21), to_1d(0, 22)));
		m_Elist.push_back(Edge(to_1d(0, 21), to_1d(1, 21)));
		m_Elist.push_back(Edge(to_1d(0, 22), to_1d(0, 23)));
		m_Elist.push_back(Edge(to_1d(0, 22), to_1d(1, 22)));
		m_Elist.push_back(Edge(to_1d(0, 23), to_1d(0, 24)));
		m_Elist.push_back(Edge(to_1d(0, 23), to_1d(1, 23)));
		m_Elist.push_back(Edge(to_1d(0, 24), to_1d(0, 25)));
		m_Elist.push_back(Edge(to_1d(0, 24), to_1d(1, 24)));
		m_Elist.push_back(Edge(to_1d(0, 25), to_1d(0, 26)));
		m_Elist.push_back(Edge(to_1d(0, 25), to_1d(1, 25)));
		m_Elist.push_back(Edge(to_1d(0, 26), to_1d(0, 27)));
		m_Elist.push_back(Edge(to_1d(0, 27), to_1d(0, 28)));
		m_Elist.push_back(Edge(to_1d(0, 28), to_1d(0, 29)));
		m_Elist.push_back(Edge(to_1d(0, 29), to_1d(0, 30)));
		m_Elist.push_back(Edge(to_1d(0, 29), to_1d(1, 29)));
		m_Elist.push_back(Edge(to_1d(0, 30), to_1d(0, 31)));
		m_Elist.push_back(Edge(to_1d(1, 0), to_1d(2, 0)));
		m_Elist.push_back(Edge(to_1d(1, 1), to_1d(1, 2)));
		m_Elist.push_back(Edge(to_1d(1, 1), to_1d(2, 1)));
		m_Elist.push_back(Edge(to_1d(1, 2), to_1d(1, 3)));
		m_Elist.push_back(Edge(to_1d(1, 2), to_1d(2, 2)));
		m_Elist.push_back(Edge(to_1d(1, 4), to_1d(2, 4)));
		m_Elist.push_back(Edge(to_1d(1, 5), to_1d(2, 5)));
		m_Elist.push_back(Edge(to_1d(1, 6), to_1d(2, 6)));
		m_Elist.push_back(Edge(to_1d(1, 7), to_1d(1, 8)));
		m_Elist.push_back(Edge(to_1d(1, 8), to_1d(1, 9)));
		m_Elist.push_back(Edge(to_1d(1, 9), to_1d(2, 9)));
		m_Elist.push_back(Edge(to_1d(1, 10), to_1d(1, 11)));
		m_Elist.push_back(Edge(to_1d(1, 10), to_1d(2, 10)));
		m_Elist.push_back(Edge(to_1d(1, 12), to_1d(1, 13)));
		m_Elist.push_back(Edge(to_1d(1, 12), to_1d(2, 12)));
		m_Elist.push_back(Edge(to_1d(1, 13), to_1d(1, 14)));
		m_Elist.push_back(Edge(to_1d(1, 14), to_1d(2, 14)));
		m_Elist.push_back(Edge(to_1d(1, 15), to_1d(1, 16)));
		m_Elist.push_back(Edge(to_1d(1, 15), to_1d(2, 15)));
		m_Elist.push_back(Edge(to_1d(1, 16), to_1d(1, 17)));
		m_Elist.push_back(Edge(to_1d(1, 16), to_1d(2, 16)));
		m_Elist.push_back(Edge(to_1d(1, 17), to_1d(1, 18)));
		m_Elist.push_back(Edge(to_1d(1, 18), to_1d(2, 18)));
		m_Elist.push_back(Edge(to_1d(1, 19), to_1d(1, 20)));
		m_Elist.push_back(Edge(to_1d(1, 19), to_1d(2, 19)));
		m_Elist.push_back(Edge(to_1d(1, 21), to_1d(2, 21)));
		m_Elist.push_back(Edge(to_1d(1, 22), to_1d(2, 22)));
		m_Elist.push_back(Edge(to_1d(1, 24), to_1d(2, 24)));
		m_Elist.push_back(Edge(to_1d(1, 25), to_1d(1, 26)));
		m_Elist.push_back(Edge(to_1d(1, 26), to_1d(1, 27)));
		m_Elist.push_back(Edge(to_1d(1, 27), to_1d(1, 28)));
		m_Elist.push_back(Edge(to_1d(1, 28), to_1d(1, 29)));
		m_Elist.push_back(Edge(to_1d(1, 30), to_1d(1, 31)));
		m_Elist.push_back(Edge(to_1d(1, 30), to_1d(2, 30)));
		m_Elist.push_back(Edge(to_1d(1, 31), to_1d(2, 31)));
		m_Elist.push_back(Edge(to_1d(2, 0), to_1d(3, 0)));
		m_Elist.push_back(Edge(to_1d(2, 1), to_1d(3, 1)));
		m_Elist.push_back(Edge(to_1d(2, 3), to_1d(2, 4)));
		m_Elist.push_back(Edge(to_1d(2, 3), to_1d(3, 3)));
		m_Elist.push_back(Edge(to_1d(2, 4), to_1d(2, 5)));
		m_Elist.push_back(Edge(to_1d(2, 5), to_1d(2, 6)));
		m_Elist.push_back(Edge(to_1d(2, 6), to_1d(2, 7)));
		m_Elist.push_back(Edge(to_1d(2, 7), to_1d(2, 8)));
		m_Elist.push_back(Edge(to_1d(2, 8), to_1d(2, 9)));
		m_Elist.push_back(Edge(to_1d(2, 9), to_1d(2, 10)));
		m_Elist.push_back(Edge(to_1d(2, 10), to_1d(2, 11)));
		m_Elist.push_back(Edge(to_1d(2, 11), to_1d(2, 12)));
		m_Elist.push_back(Edge(to_1d(2, 12), to_1d(2, 13)));
		m_Elist.push_back(Edge(to_1d(2, 12), to_1d(3, 12)));
		m_Elist.push_back(Edge(to_1d(2, 13), to_1d(3, 13)));
		m_Elist.push_back(Edge(to_1d(2, 14), to_1d(3, 14)));
		m_Elist.push_back(Edge(to_1d(2, 15), to_1d(3, 15)));
		m_Elist.push_back(Edge(to_1d(2, 16), to_1d(3, 16)));
		m_Elist.push_back(Edge(to_1d(2, 17), to_1d(2, 18)));
		m_Elist.push_back(Edge(to_1d(2, 17), to_1d(3, 17)));
		m_Elist.push_back(Edge(to_1d(2, 19), to_1d(2, 20)));
		m_Elist.push_back(Edge(to_1d(2, 20), to_1d(2, 21)));
		m_Elist.push_back(Edge(to_1d(2, 20), to_1d(3, 20)));
		m_Elist.push_back(Edge(to_1d(2, 22), to_1d(2, 23)));
		m_Elist.push_back(Edge(to_1d(2, 23), to_1d(2, 24)));
		m_Elist.push_back(Edge(to_1d(2, 25), to_1d(2, 26)));
		m_Elist.push_back(Edge(to_1d(2, 25), to_1d(3, 25)));
		m_Elist.push_back(Edge(to_1d(2, 26), to_1d(3, 26)));
		m_Elist.push_back(Edge(to_1d(2, 27), to_1d(2, 28)));
		m_Elist.push_back(Edge(to_1d(2, 27), to_1d(3, 27)));
		m_Elist.push_back(Edge(to_1d(2, 28), to_1d(3, 28)));
		m_Elist.push_back(Edge(to_1d(2, 29), to_1d(2, 30)));
		m_Elist.push_back(Edge(to_1d(2, 29), to_1d(3, 29)));
		m_Elist.push_back(Edge(to_1d(2, 30), to_1d(3, 30)));
		m_Elist.push_back(Edge(to_1d(2, 31), to_1d(3, 31)));
		m_Elist.push_back(Edge(to_1d(3, 0), to_1d(4, 0)));
		m_Elist.push_back(Edge(to_1d(3, 1), to_1d(3, 2)));
		m_Elist.push_back(Edge(to_1d(3, 1), to_1d(4, 1)));
		m_Elist.push_back(Edge(to_1d(3, 2), to_1d(3, 3)));
		m_Elist.push_back(Edge(to_1d(3, 3), to_1d(4, 3)));
		m_Elist.push_back(Edge(to_1d(3, 4), to_1d(3, 5)));
		m_Elist.push_back(Edge(to_1d(3, 4), to_1d(4, 4)));
		m_Elist.push_back(Edge(to_1d(3, 5), to_1d(3, 6)));
		m_Elist.push_back(Edge(to_1d(3, 5), to_1d(4, 5)));
		m_Elist.push_back(Edge(to_1d(3, 6), to_1d(3, 7)));
		m_Elist.push_back(Edge(to_1d(3, 6), to_1d(4, 6)));
		m_Elist.push_back(Edge(to_1d(3, 7), to_1d(3, 8)));
		m_Elist.push_back(Edge(to_1d(3, 7), to_1d(4, 7)));
		m_Elist.push_back(Edge(to_1d(3, 8), to_1d(3, 9)));
		m_Elist.push_back(Edge(to_1d(3, 8), to_1d(4, 8)));
		m_Elist.push_back(Edge(to_1d(3, 9), to_1d(3, 10)));
		m_Elist.push_back(Edge(to_1d(3, 9), to_1d(4, 9)));
		m_Elist.push_back(Edge(to_1d(3, 10), to_1d(3, 11)));
		m_Elist.push_back(Edge(to_1d(3, 10), to_1d(4, 10)));
		m_Elist.push_back(Edge(to_1d(3, 11), to_1d(4, 11)));
		m_Elist.push_back(Edge(to_1d(3, 12), to_1d(4, 12)));
		m_Elist.push_back(Edge(to_1d(3, 13), to_1d(3, 14)));
		m_Elist.push_back(Edge(to_1d(3, 13), to_1d(4, 13)));
		m_Elist.push_back(Edge(to_1d(3, 14), to_1d(3, 15)));
		m_Elist.push_back(Edge(to_1d(3, 14), to_1d(4, 14)));
		m_Elist.push_back(Edge(to_1d(3, 15), to_1d(3, 16)));
		m_Elist.push_back(Edge(to_1d(3, 16), to_1d(3, 17)));
		m_Elist.push_back(Edge(to_1d(3, 17), to_1d(3, 18)));
		m_Elist.push_back(Edge(to_1d(3, 18), to_1d(3, 19)));
		m_Elist.push_back(Edge(to_1d(3, 18), to_1d(4, 18)));
		m_Elist.push_back(Edge(to_1d(3, 19), to_1d(4, 19)));
		m_Elist.push_back(Edge(to_1d(3, 20), to_1d(3, 21)));
		m_Elist.push_back(Edge(to_1d(3, 20), to_1d(4, 20)));
		m_Elist.push_back(Edge(to_1d(3, 21), to_1d(4, 21)));
		m_Elist.push_back(Edge(to_1d(3, 22), to_1d(3, 23)));
		m_Elist.push_back(Edge(to_1d(3, 22), to_1d(4, 22)));
		m_Elist.push_back(Edge(to_1d(3, 23), to_1d(4, 23)));
		m_Elist.push_back(Edge(to_1d(3, 24), to_1d(3, 25)));
		m_Elist.push_back(Edge(to_1d(3, 24), to_1d(4, 24)));
		m_Elist.push_back(Edge(to_1d(3, 25), to_1d(4, 25)));
		m_Elist.push_back(Edge(to_1d(3, 26), to_1d(3, 27)));
		m_Elist.push_back(Edge(to_1d(3, 26), to_1d(4, 26)));
		m_Elist.push_back(Edge(to_1d(3, 27), to_1d(4, 27)));
		m_Elist.push_back(Edge(to_1d(3, 28), to_1d(3, 29)));
		m_Elist.push_back(Edge(to_1d(3, 28), to_1d(4, 28)));
		m_Elist.push_back(Edge(to_1d(3, 29), to_1d(4, 29)));
		m_Elist.push_back(Edge(to_1d(3, 30), to_1d(4, 30)));
		m_Elist.push_back(Edge(to_1d(3, 31), to_1d(4, 31)));
		m_Elist.push_back(Edge(to_1d(4, 0), to_1d(4, 1)));
		m_Elist.push_back(Edge(to_1d(4, 0), to_1d(5, 0)));
		m_Elist.push_back(Edge(to_1d(4, 1), to_1d(5, 1)));
		m_Elist.push_back(Edge(to_1d(4, 2), to_1d(4, 3)));
		m_Elist.push_back(Edge(to_1d(4, 2), to_1d(5, 2)));
		m_Elist.push_back(Edge(to_1d(4, 3), to_1d(5, 3)));
		m_Elist.push_back(Edge(to_1d(4, 4), to_1d(4, 5)));
		m_Elist.push_back(Edge(to_1d(4, 4), to_1d(5, 4)));
		m_Elist.push_back(Edge(to_1d(4, 5), to_1d(4, 6)));
		m_Elist.push_back(Edge(to_1d(4, 5), to_1d(5, 5)));
		m_Elist.push_back(Edge(to_1d(4, 6), to_1d(4, 7)));
		m_Elist.push_back(Edge(to_1d(4, 6), to_1d(5, 6)));
		m_Elist.push_back(Edge(to_1d(4, 7), to_1d(4, 8)));
		m_Elist.push_back(Edge(to_1d(4, 7), to_1d(5, 7)));
		m_Elist.push_back(Edge(to_1d(4, 8), to_1d(4, 9)));
		m_Elist.push_back(Edge(to_1d(4, 8), to_1d(5, 8)));
		m_Elist.push_back(Edge(to_1d(4, 9), to_1d(4, 10)));
		m_Elist.push_back(Edge(to_1d(4, 9), to_1d(5, 9)));
		m_Elist.push_back(Edge(to_1d(4, 10), to_1d(4, 11)));
		m_Elist.push_back(Edge(to_1d(4, 10), to_1d(5, 10)));
		m_Elist.push_back(Edge(to_1d(4, 11), to_1d(5, 11)));
		m_Elist.push_back(Edge(to_1d(4, 12), to_1d(4, 13)));
		m_Elist.push_back(Edge(to_1d(4, 13), to_1d(5, 13)));
		m_Elist.push_back(Edge(to_1d(4, 14), to_1d(5, 14)));
		m_Elist.push_back(Edge(to_1d(4, 15), to_1d(4, 16)));
		m_Elist.push_back(Edge(to_1d(4, 15), to_1d(5, 15)));
		m_Elist.push_back(Edge(to_1d(4, 16), to_1d(4, 17)));
		m_Elist.push_back(Edge(to_1d(4, 17), to_1d(4, 18)));
		m_Elist.push_back(Edge(to_1d(4, 17), to_1d(5, 17)));
		m_Elist.push_back(Edge(to_1d(4, 19), to_1d(4, 20)));
		m_Elist.push_back(Edge(to_1d(4, 19), to_1d(5, 19)));
		m_Elist.push_back(Edge(to_1d(4, 20), to_1d(5, 20)));
		m_Elist.push_back(Edge(to_1d(4, 21), to_1d(4, 22)));
		m_Elist.push_back(Edge(to_1d(4, 21), to_1d(5, 21)));
		m_Elist.push_back(Edge(to_1d(4, 22), to_1d(5, 22)));
		m_Elist.push_back(Edge(to_1d(4, 23), to_1d(4, 24)));
		m_Elist.push_back(Edge(to_1d(4, 23), to_1d(5, 23)));
		m_Elist.push_back(Edge(to_1d(4, 24), to_1d(5, 24)));
		m_Elist.push_back(Edge(to_1d(4, 25), to_1d(4, 26)));
		m_Elist.push_back(Edge(to_1d(4, 25), to_1d(5, 25)));
		m_Elist.push_back(Edge(to_1d(4, 26), to_1d(5, 26)));
		m_Elist.push_back(Edge(to_1d(4, 27), to_1d(4, 28)));
		m_Elist.push_back(Edge(to_1d(4, 27), to_1d(5, 27)));
		m_Elist.push_back(Edge(to_1d(4, 28), to_1d(5, 28)));
		m_Elist.push_back(Edge(to_1d(4, 29), to_1d(4, 30)));
		m_Elist.push_back(Edge(to_1d(4, 29), to_1d(5, 29)));
		m_Elist.push_back(Edge(to_1d(4, 31), to_1d(5, 31)));
		m_Elist.push_back(Edge(to_1d(5, 0), to_1d(6, 0)));
		m_Elist.push_back(Edge(to_1d(5, 1), to_1d(5, 2)));
		m_Elist.push_back(Edge(to_1d(5, 1), to_1d(6, 1)));
		m_Elist.push_back(Edge(to_1d(5, 3), to_1d(6, 3)));
		m_Elist.push_back(Edge(to_1d(5, 4), to_1d(5, 5)));
		m_Elist.push_back(Edge(to_1d(5, 4), to_1d(6, 4)));
		m_Elist.push_back(Edge(to_1d(5, 5), to_1d(5, 6)));
		m_Elist.push_back(Edge(to_1d(5, 5), to_1d(6, 5)));
		m_Elist.push_back(Edge(to_1d(5, 6), to_1d(5, 7)));
		m_Elist.push_back(Edge(to_1d(5, 6), to_1d(6, 6)));
		m_Elist.push_back(Edge(to_1d(5, 7), to_1d(5, 8)));
		m_Elist.push_back(Edge(to_1d(5, 7), to_1d(6, 7)));
		m_Elist.push_back(Edge(to_1d(5, 8), to_1d(5, 9)));
		m_Elist.push_back(Edge(to_1d(5, 8), to_1d(6, 8)));
		m_Elist.push_back(Edge(to_1d(5, 9), to_1d(5, 10)));
		m_Elist.push_back(Edge(to_1d(5, 9), to_1d(6, 9)));
		m_Elist.push_back(Edge(to_1d(5, 10), to_1d(5, 11)));
		m_Elist.push_back(Edge(to_1d(5, 10), to_1d(6, 10)));
		m_Elist.push_back(Edge(to_1d(5, 11), to_1d(6, 11)));
		m_Elist.push_back(Edge(to_1d(5, 12), to_1d(5, 13)));
		m_Elist.push_back(Edge(to_1d(5, 12), to_1d(6, 12)));
		m_Elist.push_back(Edge(to_1d(5, 13), to_1d(5, 14)));
		m_Elist.push_back(Edge(to_1d(5, 14), to_1d(5, 15)));
		m_Elist.push_back(Edge(to_1d(5, 14), to_1d(6, 14)));
		m_Elist.push_back(Edge(to_1d(5, 15), to_1d(6, 15)));
		m_Elist.push_back(Edge(to_1d(5, 16), to_1d(5, 17)));
		m_Elist.push_back(Edge(to_1d(5, 16), to_1d(6, 16)));
		m_Elist.push_back(Edge(to_1d(5, 17), to_1d(5, 18)));
		m_Elist.push_back(Edge(to_1d(5, 18), to_1d(5, 19)));
		m_Elist.push_back(Edge(to_1d(5, 18), to_1d(6, 18)));
		m_Elist.push_back(Edge(to_1d(5, 20), to_1d(5, 21)));
		m_Elist.push_back(Edge(to_1d(5, 20), to_1d(6, 20)));
		m_Elist.push_back(Edge(to_1d(5, 21), to_1d(6, 21)));
		m_Elist.push_back(Edge(to_1d(5, 22), to_1d(5, 23)));
		m_Elist.push_back(Edge(to_1d(5, 22), to_1d(6, 22)));
		m_Elist.push_back(Edge(to_1d(5, 23), to_1d(6, 23)));
		m_Elist.push_back(Edge(to_1d(5, 24), to_1d(5, 25)));
		m_Elist.push_back(Edge(to_1d(5, 24), to_1d(6, 24)));
		m_Elist.push_back(Edge(to_1d(5, 25), to_1d(6, 25)));
		m_Elist.push_back(Edge(to_1d(5, 26), to_1d(5, 27)));
		m_Elist.push_back(Edge(to_1d(5, 26), to_1d(6, 26)));
		m_Elist.push_back(Edge(to_1d(5, 27), to_1d(6, 27)));
		m_Elist.push_back(Edge(to_1d(5, 28), to_1d(5, 29)));
		m_Elist.push_back(Edge(to_1d(5, 28), to_1d(6, 28)));
		m_Elist.push_back(Edge(to_1d(5, 29), to_1d(6, 29)));
		m_Elist.push_back(Edge(to_1d(5, 30), to_1d(6, 30)));
		m_Elist.push_back(Edge(to_1d(5, 31), to_1d(6, 31)));
		m_Elist.push_back(Edge(to_1d(6, 0), to_1d(6, 1)));
		m_Elist.push_back(Edge(to_1d(6, 0), to_1d(7, 0)));
		m_Elist.push_back(Edge(to_1d(6, 1), to_1d(6, 2)));
		m_Elist.push_back(Edge(to_1d(6, 2), to_1d(7, 2)));
		m_Elist.push_back(Edge(to_1d(6, 3), to_1d(7, 3)));
		m_Elist.push_back(Edge(to_1d(6, 4), to_1d(6, 5)));
		m_Elist.push_back(Edge(to_1d(6, 4), to_1d(7, 4)));
		m_Elist.push_back(Edge(to_1d(6, 5), to_1d(6, 6)));
		m_Elist.push_back(Edge(to_1d(6, 5), to_1d(7, 5)));
		m_Elist.push_back(Edge(to_1d(6, 6), to_1d(6, 7)));
		m_Elist.push_back(Edge(to_1d(6, 6), to_1d(7, 6)));
		m_Elist.push_back(Edge(to_1d(6, 7), to_1d(6, 8)));
		m_Elist.push_back(Edge(to_1d(6, 7), to_1d(7, 7)));
		m_Elist.push_back(Edge(to_1d(6, 8), to_1d(6, 9)));
		m_Elist.push_back(Edge(to_1d(6, 8), to_1d(7, 8)));
		m_Elist.push_back(Edge(to_1d(6, 9), to_1d(6, 10)));
		m_Elist.push_back(Edge(to_1d(6, 9), to_1d(7, 9)));
		m_Elist.push_back(Edge(to_1d(6, 10), to_1d(6, 11)));
		m_Elist.push_back(Edge(to_1d(6, 10), to_1d(7, 10)));
		m_Elist.push_back(Edge(to_1d(6, 11), to_1d(7, 11)));
		m_Elist.push_back(Edge(to_1d(6, 12), to_1d(6, 13)));
		m_Elist.push_back(Edge(to_1d(6, 12), to_1d(7, 12)));
		m_Elist.push_back(Edge(to_1d(6, 13), to_1d(7, 13)));
		m_Elist.push_back(Edge(to_1d(6, 14), to_1d(7, 14)));
		m_Elist.push_back(Edge(to_1d(6, 15), to_1d(6, 16)));
		m_Elist.push_back(Edge(to_1d(6, 15), to_1d(7, 15)));
		m_Elist.push_back(Edge(to_1d(6, 16), to_1d(6, 17)));
		m_Elist.push_back(Edge(to_1d(6, 17), to_1d(6, 18)));
		m_Elist.push_back(Edge(to_1d(6, 18), to_1d(6, 19)));
		m_Elist.push_back(Edge(to_1d(6, 19), to_1d(6, 20)));
		m_Elist.push_back(Edge(to_1d(6, 21), to_1d(6, 22)));
		m_Elist.push_back(Edge(to_1d(6, 23), to_1d(6, 24)));
		m_Elist.push_back(Edge(to_1d(6, 25), to_1d(6, 26)));
		m_Elist.push_back(Edge(to_1d(6, 25), to_1d(7, 25)));
		m_Elist.push_back(Edge(to_1d(6, 26), to_1d(7, 26)));
		m_Elist.push_back(Edge(to_1d(6, 27), to_1d(6, 28)));
		m_Elist.push_back(Edge(to_1d(6, 27), to_1d(7, 27)));
		m_Elist.push_back(Edge(to_1d(6, 28), to_1d(7, 28)));
		m_Elist.push_back(Edge(to_1d(6, 29), to_1d(6, 30)));
		m_Elist.push_back(Edge(to_1d(6, 29), to_1d(7, 29)));
		m_Elist.push_back(Edge(to_1d(6, 30), to_1d(7, 30)));
		m_Elist.push_back(Edge(to_1d(6, 31), to_1d(7, 31)));
		m_Elist.push_back(Edge(to_1d(7, 0), to_1d(7, 1)));
		m_Elist.push_back(Edge(to_1d(7, 1), to_1d(8, 1)));
		m_Elist.push_back(Edge(to_1d(7, 2), to_1d(7, 3)));
		m_Elist.push_back(Edge(to_1d(7, 4), to_1d(7, 5)));
		m_Elist.push_back(Edge(to_1d(7, 4), to_1d(8, 4)));
		m_Elist.push_back(Edge(to_1d(7, 5), to_1d(7, 6)));
		m_Elist.push_back(Edge(to_1d(7, 5), to_1d(8, 5)));
		m_Elist.push_back(Edge(to_1d(7, 6), to_1d(7, 7)));
		m_Elist.push_back(Edge(to_1d(7, 6), to_1d(8, 6)));
		m_Elist.push_back(Edge(to_1d(7, 7), to_1d(7, 8)));
		m_Elist.push_back(Edge(to_1d(7, 7), to_1d(8, 7)));
		m_Elist.push_back(Edge(to_1d(7, 8), to_1d(7, 9)));
		m_Elist.push_back(Edge(to_1d(7, 8), to_1d(8, 8)));
		m_Elist.push_back(Edge(to_1d(7, 9), to_1d(7, 10)));
		m_Elist.push_back(Edge(to_1d(7, 10), to_1d(7, 11)));
		m_Elist.push_back(Edge(to_1d(7, 12), to_1d(8, 12)));
		m_Elist.push_back(Edge(to_1d(7, 13), to_1d(7, 14)));
		m_Elist.push_back(Edge(to_1d(7, 14), to_1d(7, 15)));
		m_Elist.push_back(Edge(to_1d(7, 16), to_1d(7, 17)));
		m_Elist.push_back(Edge(to_1d(7, 16), to_1d(8, 16)));
		m_Elist.push_back(Edge(to_1d(7, 17), to_1d(7, 18)));
		m_Elist.push_back(Edge(to_1d(7, 17), to_1d(8, 17)));
		m_Elist.push_back(Edge(to_1d(7, 18), to_1d(8, 18)));
		m_Elist.push_back(Edge(to_1d(7, 20), to_1d(7, 21)));
		m_Elist.push_back(Edge(to_1d(7, 20), to_1d(8, 20)));
		m_Elist.push_back(Edge(to_1d(7, 21), to_1d(7, 22)));
		m_Elist.push_back(Edge(to_1d(7, 22), to_1d(7, 23)));
		m_Elist.push_back(Edge(to_1d(7, 22), to_1d(8, 22)));
		m_Elist.push_back(Edge(to_1d(7, 23), to_1d(7, 24)));
		m_Elist.push_back(Edge(to_1d(7, 24), to_1d(8, 24)));
		m_Elist.push_back(Edge(to_1d(7, 26), to_1d(7, 27)));
		m_Elist.push_back(Edge(to_1d(7, 28), to_1d(7, 29)));
		m_Elist.push_back(Edge(to_1d(7, 29), to_1d(8, 29)));
		m_Elist.push_back(Edge(to_1d(7, 30), to_1d(8, 30)));
		m_Elist.push_back(Edge(to_1d(7, 31), to_1d(8, 31)));
		m_Elist.push_back(Edge(to_1d(8, 0), to_1d(9, 0)));
		m_Elist.push_back(Edge(to_1d(8, 1), to_1d(8, 2)));
		m_Elist.push_back(Edge(to_1d(8, 1), to_1d(9, 1)));
		m_Elist.push_back(Edge(to_1d(8, 2), to_1d(8, 3)));
		m_Elist.push_back(Edge(to_1d(8, 3), to_1d(9, 3)));
		m_Elist.push_back(Edge(to_1d(8, 4), to_1d(8, 5)));
		m_Elist.push_back(Edge(to_1d(8, 4), to_1d(9, 4)));
		m_Elist.push_back(Edge(to_1d(8, 5), to_1d(8, 6)));
		m_Elist.push_back(Edge(to_1d(8, 5), to_1d(9, 5)));
		m_Elist.push_back(Edge(to_1d(8, 6), to_1d(8, 7)));
		m_Elist.push_back(Edge(to_1d(8, 6), to_1d(9, 6)));
		m_Elist.push_back(Edge(to_1d(8, 7), to_1d(8, 8)));
		m_Elist.push_back(Edge(to_1d(8, 7), to_1d(9, 7)));
		m_Elist.push_back(Edge(to_1d(8, 8), to_1d(9, 8)));
		m_Elist.push_back(Edge(to_1d(8, 9), to_1d(8, 10)));
		m_Elist.push_back(Edge(to_1d(8, 9), to_1d(9, 9)));
		m_Elist.push_back(Edge(to_1d(8, 10), to_1d(8, 11)));
		m_Elist.push_back(Edge(to_1d(8, 11), to_1d(8, 12)));
		m_Elist.push_back(Edge(to_1d(8, 13), to_1d(8, 14)));
		m_Elist.push_back(Edge(to_1d(8, 13), to_1d(9, 13)));
		m_Elist.push_back(Edge(to_1d(8, 14), to_1d(8, 15)));
		m_Elist.push_back(Edge(to_1d(8, 15), to_1d(9, 15)));
		m_Elist.push_back(Edge(to_1d(8, 16), to_1d(9, 16)));
		m_Elist.push_back(Edge(to_1d(8, 17), to_1d(9, 17)));
		m_Elist.push_back(Edge(to_1d(8, 18), to_1d(8, 19)));
		m_Elist.push_back(Edge(to_1d(8, 19), to_1d(8, 20)));
		m_Elist.push_back(Edge(to_1d(8, 19), to_1d(9, 19)));
		m_Elist.push_back(Edge(to_1d(8, 21), to_1d(8, 22)));
		m_Elist.push_back(Edge(to_1d(8, 21), to_1d(9, 21)));
		m_Elist.push_back(Edge(to_1d(8, 22), to_1d(8, 23)));
		m_Elist.push_back(Edge(to_1d(8, 23), to_1d(9, 23)));
		m_Elist.push_back(Edge(to_1d(8, 24), to_1d(8, 25)));
		m_Elist.push_back(Edge(to_1d(8, 25), to_1d(9, 25)));
		m_Elist.push_back(Edge(to_1d(8, 26), to_1d(8, 27)));
		m_Elist.push_back(Edge(to_1d(8, 26), to_1d(9, 26)));
		m_Elist.push_back(Edge(to_1d(8, 27), to_1d(8, 28)));
		m_Elist.push_back(Edge(to_1d(8, 28), to_1d(8, 29)));
		m_Elist.push_back(Edge(to_1d(8, 28), to_1d(9, 28)));
		m_Elist.push_back(Edge(to_1d(8, 30), to_1d(9, 30)));
		m_Elist.push_back(Edge(to_1d(8, 31), to_1d(9, 31)));
		m_Elist.push_back(Edge(to_1d(9, 0), to_1d(9, 1)));
		m_Elist.push_back(Edge(to_1d(9, 0), to_1d(10, 0)));
		m_Elist.push_back(Edge(to_1d(9, 1), to_1d(10, 1)));
		m_Elist.push_back(Edge(to_1d(9, 2), to_1d(9, 3)));
		m_Elist.push_back(Edge(to_1d(9, 2), to_1d(10, 2)));
		m_Elist.push_back(Edge(to_1d(9, 3), to_1d(10, 3)));
		m_Elist.push_back(Edge(to_1d(9, 4), to_1d(9, 5)));
		m_Elist.push_back(Edge(to_1d(9, 4), to_1d(10, 4)));
		m_Elist.push_back(Edge(to_1d(9, 5), to_1d(9, 6)));
		m_Elist.push_back(Edge(to_1d(9, 5), to_1d(10, 5)));
		m_Elist.push_back(Edge(to_1d(9, 6), to_1d(9, 7)));
		m_Elist.push_back(Edge(to_1d(9, 6), to_1d(10, 6)));
		m_Elist.push_back(Edge(to_1d(9, 7), to_1d(9, 8)));
		m_Elist.push_back(Edge(to_1d(9, 7), to_1d(10, 7)));
		m_Elist.push_back(Edge(to_1d(9, 8), to_1d(10, 8)));
		m_Elist.push_back(Edge(to_1d(9, 9), to_1d(10, 9)));
		m_Elist.push_back(Edge(to_1d(9, 10), to_1d(9, 11)));
		m_Elist.push_back(Edge(to_1d(9, 10), to_1d(10, 10)));
		m_Elist.push_back(Edge(to_1d(9, 11), to_1d(9, 12)));
		m_Elist.push_back(Edge(to_1d(9, 12), to_1d(9, 13)));
		m_Elist.push_back(Edge(to_1d(9, 13), to_1d(10, 13)));
		m_Elist.push_back(Edge(to_1d(9, 14), to_1d(9, 15)));
		m_Elist.push_back(Edge(to_1d(9, 14), to_1d(10, 14)));
		m_Elist.push_back(Edge(to_1d(9, 15), to_1d(10, 15)));
		m_Elist.push_back(Edge(to_1d(9, 16), to_1d(10, 16)));
		m_Elist.push_back(Edge(to_1d(9, 17), to_1d(9, 18)));
		m_Elist.push_back(Edge(to_1d(9, 18), to_1d(10, 18)));
		m_Elist.push_back(Edge(to_1d(9, 20), to_1d(9, 21)));
		m_Elist.push_back(Edge(to_1d(9, 20), to_1d(10, 20)));
		m_Elist.push_back(Edge(to_1d(9, 22), to_1d(10, 22)));
		m_Elist.push_back(Edge(to_1d(9, 23), to_1d(9, 24)));
		m_Elist.push_back(Edge(to_1d(9, 23), to_1d(10, 23)));
		m_Elist.push_back(Edge(to_1d(9, 25), to_1d(10, 25)));
		m_Elist.push_back(Edge(to_1d(9, 26), to_1d(9, 27)));
		m_Elist.push_back(Edge(to_1d(9, 27), to_1d(9, 28)));
		m_Elist.push_back(Edge(to_1d(9, 27), to_1d(10, 27)));
		m_Elist.push_back(Edge(to_1d(9, 29), to_1d(9, 30)));
		m_Elist.push_back(Edge(to_1d(9, 29), to_1d(10, 29)));
		m_Elist.push_back(Edge(to_1d(9, 31), to_1d(10, 31)));
		m_Elist.push_back(Edge(to_1d(10, 0), to_1d(11, 0)));
		m_Elist.push_back(Edge(to_1d(10, 1), to_1d(11, 1)));
		m_Elist.push_back(Edge(to_1d(10, 2), to_1d(11, 2)));
		m_Elist.push_back(Edge(to_1d(10, 3), to_1d(11, 3)));
		m_Elist.push_back(Edge(to_1d(10, 4), to_1d(10, 5)));
		m_Elist.push_back(Edge(to_1d(10, 4), to_1d(11, 4)));
		m_Elist.push_back(Edge(to_1d(10, 5), to_1d(10, 6)));
		m_Elist.push_back(Edge(to_1d(10, 5), to_1d(11, 5)));
		m_Elist.push_back(Edge(to_1d(10, 6), to_1d(10, 7)));
		m_Elist.push_back(Edge(to_1d(10, 6), to_1d(11, 6)));
		m_Elist.push_back(Edge(to_1d(10, 7), to_1d(10, 8)));
		m_Elist.push_back(Edge(to_1d(10, 7), to_1d(11, 7)));
		m_Elist.push_back(Edge(to_1d(10, 8), to_1d(11, 8)));
		m_Elist.push_back(Edge(to_1d(10, 9), to_1d(11, 9)));
		m_Elist.push_back(Edge(to_1d(10, 10), to_1d(10, 11)));
		m_Elist.push_back(Edge(to_1d(10, 11), to_1d(11, 11)));
		m_Elist.push_back(Edge(to_1d(10, 12), to_1d(10, 13)));
		m_Elist.push_back(Edge(to_1d(10, 12), to_1d(11, 12)));
		m_Elist.push_back(Edge(to_1d(10, 13), to_1d(11, 13)));
		m_Elist.push_back(Edge(to_1d(10, 14), to_1d(11, 14)));
		m_Elist.push_back(Edge(to_1d(10, 15), to_1d(11, 15)));
		m_Elist.push_back(Edge(to_1d(10, 16), to_1d(11, 16)));
		m_Elist.push_back(Edge(to_1d(10, 17), to_1d(10, 18)));
		m_Elist.push_back(Edge(to_1d(10, 17), to_1d(11, 17)));
		m_Elist.push_back(Edge(to_1d(10, 19), to_1d(10, 20)));
		m_Elist.push_back(Edge(to_1d(10, 19), to_1d(11, 19)));
		m_Elist.push_back(Edge(to_1d(10, 21), to_1d(10, 22)));
		m_Elist.push_back(Edge(to_1d(10, 22), to_1d(10, 23)));
		m_Elist.push_back(Edge(to_1d(10, 22), to_1d(11, 22)));
		m_Elist.push_back(Edge(to_1d(10, 23), to_1d(10, 24)));
		m_Elist.push_back(Edge(to_1d(10, 24), to_1d(10, 25)));
		m_Elist.push_back(Edge(to_1d(10, 24), to_1d(11, 24)));
		m_Elist.push_back(Edge(to_1d(10, 26), to_1d(10, 27)));
		m_Elist.push_back(Edge(to_1d(10, 26), to_1d(11, 26)));
		m_Elist.push_back(Edge(to_1d(10, 28), to_1d(10, 29)));
		m_Elist.push_back(Edge(to_1d(10, 28), to_1d(11, 28)));
		m_Elist.push_back(Edge(to_1d(10, 30), to_1d(10, 31)));
		m_Elist.push_back(Edge(to_1d(10, 30), to_1d(11, 30)));
		m_Elist.push_back(Edge(to_1d(10, 31), to_1d(11, 31)));
		m_Elist.push_back(Edge(to_1d(11, 0), to_1d(12, 0)));
		m_Elist.push_back(Edge(to_1d(11, 1), to_1d(11, 2)));
		m_Elist.push_back(Edge(to_1d(11, 1), to_1d(12, 1)));
		m_Elist.push_back(Edge(to_1d(11, 2), to_1d(11, 3)));
		m_Elist.push_back(Edge(to_1d(11, 4), to_1d(11, 5)));
		m_Elist.push_back(Edge(to_1d(11, 5), to_1d(11, 6)));
		m_Elist.push_back(Edge(to_1d(11, 6), to_1d(11, 7)));
		m_Elist.push_back(Edge(to_1d(11, 7), to_1d(11, 8)));
		m_Elist.push_back(Edge(to_1d(11, 9), to_1d(12, 9)));
		m_Elist.push_back(Edge(to_1d(11, 10), to_1d(11, 11)));
		m_Elist.push_back(Edge(to_1d(11, 10), to_1d(12, 10)));
		m_Elist.push_back(Edge(to_1d(11, 11), to_1d(11, 12)));
		m_Elist.push_back(Edge(to_1d(11, 12), to_1d(12, 12)));
		m_Elist.push_back(Edge(to_1d(11, 13), to_1d(12, 13)));
		m_Elist.push_back(Edge(to_1d(11, 14), to_1d(12, 14)));
		m_Elist.push_back(Edge(to_1d(11, 15), to_1d(11, 16)));
		m_Elist.push_back(Edge(to_1d(11, 16), to_1d(11, 17)));
		m_Elist.push_back(Edge(to_1d(11, 16), to_1d(12, 16)));
		m_Elist.push_back(Edge(to_1d(11, 18), to_1d(11, 19)));
		m_Elist.push_back(Edge(to_1d(11, 18), to_1d(12, 18)));
		m_Elist.push_back(Edge(to_1d(11, 20), to_1d(11, 21)));
		m_Elist.push_back(Edge(to_1d(11, 20), to_1d(12, 20)));
		m_Elist.push_back(Edge(to_1d(11, 21), to_1d(11, 22)));
		m_Elist.push_back(Edge(to_1d(11, 22), to_1d(11, 23)));
		m_Elist.push_back(Edge(to_1d(11, 22), to_1d(12, 22)));
		m_Elist.push_back(Edge(to_1d(11, 24), to_1d(12, 24)));
		m_Elist.push_back(Edge(to_1d(11, 25), to_1d(11, 26)));
		m_Elist.push_back(Edge(to_1d(11, 25), to_1d(12, 25)));
		m_Elist.push_back(Edge(to_1d(11, 27), to_1d(11, 28)));
		m_Elist.push_back(Edge(to_1d(11, 27), to_1d(12, 27)));
		m_Elist.push_back(Edge(to_1d(11, 29), to_1d(11, 30)));
		m_Elist.push_back(Edge(to_1d(11, 29), to_1d(12, 29)));
		m_Elist.push_back(Edge(to_1d(11, 30), to_1d(12, 30)));
		m_Elist.push_back(Edge(to_1d(11, 31), to_1d(12, 31)));
		m_Elist.push_back(Edge(to_1d(12, 0), to_1d(12, 1)));
		m_Elist.push_back(Edge(to_1d(12, 0), to_1d(13, 0)));
		m_Elist.push_back(Edge(to_1d(12, 1), to_1d(12, 2)));
		m_Elist.push_back(Edge(to_1d(12, 2), to_1d(13, 2)));
		m_Elist.push_back(Edge(to_1d(12, 3), to_1d(12, 4)));
		m_Elist.push_back(Edge(to_1d(12, 3), to_1d(13, 3)));
		m_Elist.push_back(Edge(to_1d(12, 4), to_1d(12, 5)));
		m_Elist.push_back(Edge(to_1d(12, 5), to_1d(12, 6)));
		m_Elist.push_back(Edge(to_1d(12, 5), to_1d(13, 5)));
		m_Elist.push_back(Edge(to_1d(12, 6), to_1d(12, 7)));
		m_Elist.push_back(Edge(to_1d(12, 7), to_1d(12, 8)));
		m_Elist.push_back(Edge(to_1d(12, 7), to_1d(13, 7)));
		m_Elist.push_back(Edge(to_1d(12, 8), to_1d(13, 8)));
		m_Elist.push_back(Edge(to_1d(12, 9), to_1d(12, 10)));
		m_Elist.push_back(Edge(to_1d(12, 9), to_1d(13, 9)));
		m_Elist.push_back(Edge(to_1d(12, 10), to_1d(12, 11)));
		m_Elist.push_back(Edge(to_1d(12, 11), to_1d(12, 12)));
		m_Elist.push_back(Edge(to_1d(12, 13), to_1d(12, 14)));
		m_Elist.push_back(Edge(to_1d(12, 14), to_1d(12, 15)));
		m_Elist.push_back(Edge(to_1d(12, 15), to_1d(12, 16)));
		m_Elist.push_back(Edge(to_1d(12, 17), to_1d(12, 18)));
		m_Elist.push_back(Edge(to_1d(12, 17), to_1d(13, 17)));
		m_Elist.push_back(Edge(to_1d(12, 19), to_1d(12, 20)));
		m_Elist.push_back(Edge(to_1d(12, 19), to_1d(13, 19)));
		m_Elist.push_back(Edge(to_1d(12, 20), to_1d(12, 21)));
		m_Elist.push_back(Edge(to_1d(12, 21), to_1d(12, 22)));
		m_Elist.push_back(Edge(to_1d(12, 22), to_1d(12, 23)));
		m_Elist.push_back(Edge(to_1d(12, 22), to_1d(13, 22)));
		m_Elist.push_back(Edge(to_1d(12, 23), to_1d(12, 24)));
		m_Elist.push_back(Edge(to_1d(12, 24), to_1d(13, 24)));
		m_Elist.push_back(Edge(to_1d(12, 25), to_1d(12, 26)));
		m_Elist.push_back(Edge(to_1d(12, 26), to_1d(12, 27)));
		m_Elist.push_back(Edge(to_1d(12, 26), to_1d(13, 26)));
		m_Elist.push_back(Edge(to_1d(12, 28), to_1d(12, 29)));
		m_Elist.push_back(Edge(to_1d(12, 28), to_1d(13, 28)));
		m_Elist.push_back(Edge(to_1d(12, 29), to_1d(13, 29)));
		m_Elist.push_back(Edge(to_1d(12, 30), to_1d(13, 30)));
		m_Elist.push_back(Edge(to_1d(12, 31), to_1d(13, 31)));
		m_Elist.push_back(Edge(to_1d(13, 0), to_1d(14, 0)));
		m_Elist.push_back(Edge(to_1d(13, 1), to_1d(14, 1)));
		m_Elist.push_back(Edge(to_1d(13, 2), to_1d(14, 2)));
		m_Elist.push_back(Edge(to_1d(13, 3), to_1d(13, 4)));
		m_Elist.push_back(Edge(to_1d(13, 3), to_1d(14, 3)));
		m_Elist.push_back(Edge(to_1d(13, 4), to_1d(14, 4)));
		m_Elist.push_back(Edge(to_1d(13, 5), to_1d(13, 6)));
		m_Elist.push_back(Edge(to_1d(13, 6), to_1d(14, 6)));
		m_Elist.push_back(Edge(to_1d(13, 7), to_1d(14, 7)));
		m_Elist.push_back(Edge(to_1d(13, 8), to_1d(13, 9)));
		m_Elist.push_back(Edge(to_1d(13, 9), to_1d(14, 9)));
		m_Elist.push_back(Edge(to_1d(13, 10), to_1d(13, 11)));
		m_Elist.push_back(Edge(to_1d(13, 10), to_1d(14, 10)));
		m_Elist.push_back(Edge(to_1d(13, 11), to_1d(14, 11)));
		m_Elist.push_back(Edge(to_1d(13, 12), to_1d(13, 13)));
		m_Elist.push_back(Edge(to_1d(13, 12), to_1d(14, 12)));
		m_Elist.push_back(Edge(to_1d(13, 14), to_1d(13, 15)));
		m_Elist.push_back(Edge(to_1d(13, 14), to_1d(14, 14)));
		m_Elist.push_back(Edge(to_1d(13, 15), to_1d(13, 16)));
		m_Elist.push_back(Edge(to_1d(13, 16), to_1d(13, 17)));
		m_Elist.push_back(Edge(to_1d(13, 16), to_1d(14, 16)));
		m_Elist.push_back(Edge(to_1d(13, 18), to_1d(13, 19)));
		m_Elist.push_back(Edge(to_1d(13, 19), to_1d(13, 20)));
		m_Elist.push_back(Edge(to_1d(13, 20), to_1d(13, 21)));
		m_Elist.push_back(Edge(to_1d(13, 21), to_1d(13, 22)));
		m_Elist.push_back(Edge(to_1d(13, 22), to_1d(13, 23)));
		m_Elist.push_back(Edge(to_1d(13, 23), to_1d(13, 24)));
		m_Elist.push_back(Edge(to_1d(13, 23), to_1d(14, 23)));
		m_Elist.push_back(Edge(to_1d(13, 25), to_1d(13, 26)));
		m_Elist.push_back(Edge(to_1d(13, 25), to_1d(14, 25)));
		m_Elist.push_back(Edge(to_1d(13, 27), to_1d(13, 28)));
		m_Elist.push_back(Edge(to_1d(13, 27), to_1d(14, 27)));
		m_Elist.push_back(Edge(to_1d(13, 28), to_1d(14, 28)));
		m_Elist.push_back(Edge(to_1d(13, 29), to_1d(14, 29)));
		m_Elist.push_back(Edge(to_1d(13, 30), to_1d(14, 30)));
		m_Elist.push_back(Edge(to_1d(13, 31), to_1d(14, 31)));
		m_Elist.push_back(Edge(to_1d(14, 0), to_1d(14, 1)));
		m_Elist.push_back(Edge(to_1d(14, 0), to_1d(15, 0)));
		m_Elist.push_back(Edge(to_1d(14, 1), to_1d(15, 1)));
		m_Elist.push_back(Edge(to_1d(14, 2), to_1d(15, 2)));
		m_Elist.push_back(Edge(to_1d(14, 4), to_1d(14, 5)));
		m_Elist.push_back(Edge(to_1d(14, 4), to_1d(15, 4)));
		m_Elist.push_back(Edge(to_1d(14, 5), to_1d(14, 6)));
		m_Elist.push_back(Edge(to_1d(14, 6), to_1d(14, 7)));
		m_Elist.push_back(Edge(to_1d(14, 7), to_1d(14, 8)));
		m_Elist.push_back(Edge(to_1d(14, 7), to_1d(15, 7)));
		m_Elist.push_back(Edge(to_1d(14, 8), to_1d(15, 8)));
		m_Elist.push_back(Edge(to_1d(14, 9), to_1d(15, 9)));
		m_Elist.push_back(Edge(to_1d(14, 10), to_1d(15, 10)));
		m_Elist.push_back(Edge(to_1d(14, 11), to_1d(14, 12)));
		m_Elist.push_back(Edge(to_1d(14, 11), to_1d(15, 11)));
		m_Elist.push_back(Edge(to_1d(14, 12), to_1d(14, 13)));
		m_Elist.push_back(Edge(to_1d(14, 13), to_1d(14, 14)));
		m_Elist.push_back(Edge(to_1d(14, 13), to_1d(15, 13)));
		m_Elist.push_back(Edge(to_1d(14, 14), to_1d(14, 15)));
		m_Elist.push_back(Edge(to_1d(14, 15), to_1d(14, 16)));
		m_Elist.push_back(Edge(to_1d(14, 15), to_1d(15, 15)));
		m_Elist.push_back(Edge(to_1d(14, 17), to_1d(14, 18)));
		m_Elist.push_back(Edge(to_1d(14, 17), to_1d(15, 17)));
		m_Elist.push_back(Edge(to_1d(14, 18), to_1d(14, 19)));
		m_Elist.push_back(Edge(to_1d(14, 18), to_1d(15, 18)));
		m_Elist.push_back(Edge(to_1d(14, 19), to_1d(14, 20)));
		m_Elist.push_back(Edge(to_1d(14, 19), to_1d(15, 19)));
		m_Elist.push_back(Edge(to_1d(14, 20), to_1d(14, 21)));
		m_Elist.push_back(Edge(to_1d(14, 20), to_1d(15, 20)));
		m_Elist.push_back(Edge(to_1d(14, 21), to_1d(14, 22)));
		m_Elist.push_back(Edge(to_1d(14, 21), to_1d(15, 21)));
		m_Elist.push_back(Edge(to_1d(14, 22), to_1d(15, 22)));
		m_Elist.push_back(Edge(to_1d(14, 23), to_1d(14, 24)));
		m_Elist.push_back(Edge(to_1d(14, 24), to_1d(14, 25)));
		m_Elist.push_back(Edge(to_1d(14, 24), to_1d(15, 24)));
		m_Elist.push_back(Edge(to_1d(14, 26), to_1d(14, 27)));
		m_Elist.push_back(Edge(to_1d(14, 26), to_1d(15, 26)));
		m_Elist.push_back(Edge(to_1d(14, 27), to_1d(15, 27)));
		m_Elist.push_back(Edge(to_1d(14, 28), to_1d(14, 29)));
		m_Elist.push_back(Edge(to_1d(14, 29), to_1d(14, 30)));
		m_Elist.push_back(Edge(to_1d(14, 29), to_1d(15, 29)));
		m_Elist.push_back(Edge(to_1d(14, 30), to_1d(14, 31)));
		m_Elist.push_back(Edge(to_1d(14, 30), to_1d(15, 30)));
		m_Elist.push_back(Edge(to_1d(14, 31), to_1d(15, 31)));
		m_Elist.push_back(Edge(to_1d(15, 0), to_1d(16, 0)));
		m_Elist.push_back(Edge(to_1d(15, 1), to_1d(15, 2)));
		m_Elist.push_back(Edge(to_1d(15, 1), to_1d(16, 1)));
		m_Elist.push_back(Edge(to_1d(15, 2), to_1d(15, 3)));
		m_Elist.push_back(Edge(to_1d(15, 2), to_1d(16, 2)));
		m_Elist.push_back(Edge(to_1d(15, 3), to_1d(15, 4)));
		m_Elist.push_back(Edge(to_1d(15, 3), to_1d(16, 3)));
		m_Elist.push_back(Edge(to_1d(15, 4), to_1d(15, 5)));
		m_Elist.push_back(Edge(to_1d(15, 4), to_1d(16, 4)));
		m_Elist.push_back(Edge(to_1d(15, 5), to_1d(15, 6)));
		m_Elist.push_back(Edge(to_1d(15, 6), to_1d(16, 6)));
		m_Elist.push_back(Edge(to_1d(15, 7), to_1d(16, 7)));
		m_Elist.push_back(Edge(to_1d(15, 8), to_1d(15, 9)));
		m_Elist.push_back(Edge(to_1d(15, 10), to_1d(16, 10)));
		m_Elist.push_back(Edge(to_1d(15, 11), to_1d(15, 12)));
		m_Elist.push_back(Edge(to_1d(15, 12), to_1d(15, 13)));
		m_Elist.push_back(Edge(to_1d(15, 12), to_1d(16, 12)));
		m_Elist.push_back(Edge(to_1d(15, 13), to_1d(15, 14)));
		m_Elist.push_back(Edge(to_1d(15, 14), to_1d(15, 15)));
		m_Elist.push_back(Edge(to_1d(15, 14), to_1d(16, 14)));
		m_Elist.push_back(Edge(to_1d(15, 15), to_1d(15, 16)));
		m_Elist.push_back(Edge(to_1d(15, 16), to_1d(16, 16)));
		m_Elist.push_back(Edge(to_1d(15, 17), to_1d(15, 18)));
		m_Elist.push_back(Edge(to_1d(15, 17), to_1d(16, 17)));
		m_Elist.push_back(Edge(to_1d(15, 18), to_1d(15, 19)));
		m_Elist.push_back(Edge(to_1d(15, 18), to_1d(16, 18)));
		m_Elist.push_back(Edge(to_1d(15, 19), to_1d(15, 20)));
		m_Elist.push_back(Edge(to_1d(15, 19), to_1d(16, 19)));
		m_Elist.push_back(Edge(to_1d(15, 20), to_1d(15, 21)));
		m_Elist.push_back(Edge(to_1d(15, 20), to_1d(16, 20)));
		m_Elist.push_back(Edge(to_1d(15, 21), to_1d(15, 22)));
		m_Elist.push_back(Edge(to_1d(15, 21), to_1d(16, 21)));
		m_Elist.push_back(Edge(to_1d(15, 22), to_1d(16, 22)));
		m_Elist.push_back(Edge(to_1d(15, 23), to_1d(15, 24)));
		m_Elist.push_back(Edge(to_1d(15, 23), to_1d(16, 23)));
		m_Elist.push_back(Edge(to_1d(15, 25), to_1d(15, 26)));
		m_Elist.push_back(Edge(to_1d(15, 25), to_1d(16, 25)));
		m_Elist.push_back(Edge(to_1d(15, 27), to_1d(15, 28)));
		m_Elist.push_back(Edge(to_1d(15, 27), to_1d(16, 27)));
		m_Elist.push_back(Edge(to_1d(15, 28), to_1d(15, 29)));
		m_Elist.push_back(Edge(to_1d(15, 30), to_1d(16, 30)));
		m_Elist.push_back(Edge(to_1d(15, 31), to_1d(16, 31)));
		m_Elist.push_back(Edge(to_1d(16, 0), to_1d(17, 0)));
		m_Elist.push_back(Edge(to_1d(16, 1), to_1d(17, 1)));
		m_Elist.push_back(Edge(to_1d(16, 2), to_1d(17, 2)));
		m_Elist.push_back(Edge(to_1d(16, 3), to_1d(17, 3)));
		m_Elist.push_back(Edge(to_1d(16, 4), to_1d(16, 5)));
		m_Elist.push_back(Edge(to_1d(16, 4), to_1d(17, 4)));
		m_Elist.push_back(Edge(to_1d(16, 5), to_1d(16, 6)));
		m_Elist.push_back(Edge(to_1d(16, 5), to_1d(17, 5)));
		m_Elist.push_back(Edge(to_1d(16, 7), to_1d(16, 8)));
		m_Elist.push_back(Edge(to_1d(16, 7), to_1d(17, 7)));
		m_Elist.push_back(Edge(to_1d(16, 8), to_1d(16, 9)));
		m_Elist.push_back(Edge(to_1d(16, 9), to_1d(17, 9)));
		m_Elist.push_back(Edge(to_1d(16, 10), to_1d(16, 11)));
		m_Elist.push_back(Edge(to_1d(16, 10), to_1d(17, 10)));
		m_Elist.push_back(Edge(to_1d(16, 11), to_1d(16, 12)));
		m_Elist.push_back(Edge(to_1d(16, 12), to_1d(16, 13)));
		m_Elist.push_back(Edge(to_1d(16, 13), to_1d(16, 14)));
		m_Elist.push_back(Edge(to_1d(16, 13), to_1d(17, 13)));
		m_Elist.push_back(Edge(to_1d(16, 14), to_1d(16, 15)));
		m_Elist.push_back(Edge(to_1d(16, 15), to_1d(16, 16)));
		m_Elist.push_back(Edge(to_1d(16, 17), to_1d(16, 18)));
		m_Elist.push_back(Edge(to_1d(16, 17), to_1d(17, 17)));
		m_Elist.push_back(Edge(to_1d(16, 18), to_1d(16, 19)));
		m_Elist.push_back(Edge(to_1d(16, 18), to_1d(17, 18)));
		m_Elist.push_back(Edge(to_1d(16, 19), to_1d(16, 20)));
		m_Elist.push_back(Edge(to_1d(16, 19), to_1d(17, 19)));
		m_Elist.push_back(Edge(to_1d(16, 20), to_1d(16, 21)));
		m_Elist.push_back(Edge(to_1d(16, 20), to_1d(17, 20)));
		m_Elist.push_back(Edge(to_1d(16, 21), to_1d(16, 22)));
		m_Elist.push_back(Edge(to_1d(16, 21), to_1d(17, 21)));
		m_Elist.push_back(Edge(to_1d(16, 22), to_1d(17, 22)));
		m_Elist.push_back(Edge(to_1d(16, 23), to_1d(16, 24)));
		m_Elist.push_back(Edge(to_1d(16, 24), to_1d(16, 25)));
		m_Elist.push_back(Edge(to_1d(16, 24), to_1d(17, 24)));
		m_Elist.push_back(Edge(to_1d(16, 25), to_1d(16, 26)));
		m_Elist.push_back(Edge(to_1d(16, 26), to_1d(16, 27)));
		m_Elist.push_back(Edge(to_1d(16, 26), to_1d(17, 26)));
		m_Elist.push_back(Edge(to_1d(16, 27), to_1d(16, 28)));
		m_Elist.push_back(Edge(to_1d(16, 27), to_1d(17, 27)));
		m_Elist.push_back(Edge(to_1d(16, 28), to_1d(16, 29)));
		m_Elist.push_back(Edge(to_1d(16, 29), to_1d(16, 30)));
		m_Elist.push_back(Edge(to_1d(16, 30), to_1d(16, 31)));
		m_Elist.push_back(Edge(to_1d(16, 31), to_1d(17, 31)));
		m_Elist.push_back(Edge(to_1d(17, 0), to_1d(17, 1)));
		m_Elist.push_back(Edge(to_1d(17, 0), to_1d(18, 0)));
		m_Elist.push_back(Edge(to_1d(17, 1), to_1d(17, 2)));
		m_Elist.push_back(Edge(to_1d(17, 1), to_1d(18, 1)));
		m_Elist.push_back(Edge(to_1d(17, 2), to_1d(17, 3)));
		m_Elist.push_back(Edge(to_1d(17, 3), to_1d(17, 4)));
		m_Elist.push_back(Edge(to_1d(17, 3), to_1d(18, 3)));
		m_Elist.push_back(Edge(to_1d(17, 4), to_1d(18, 4)));
		m_Elist.push_back(Edge(to_1d(17, 5), to_1d(17, 6)));
		m_Elist.push_back(Edge(to_1d(17, 6), to_1d(17, 7)));
		m_Elist.push_back(Edge(to_1d(17, 7), to_1d(17, 8)));
		m_Elist.push_back(Edge(to_1d(17, 7), to_1d(18, 7)));
		m_Elist.push_back(Edge(to_1d(17, 8), to_1d(17, 9)));
		m_Elist.push_back(Edge(to_1d(17, 10), to_1d(17, 11)));
		m_Elist.push_back(Edge(to_1d(17, 10), to_1d(18, 10)));
		m_Elist.push_back(Edge(to_1d(17, 11), to_1d(17, 12)));
		m_Elist.push_back(Edge(to_1d(17, 12), to_1d(17, 13)));
		m_Elist.push_back(Edge(to_1d(17, 12), to_1d(18, 12)));
		m_Elist.push_back(Edge(to_1d(17, 14), to_1d(17, 15)));
		m_Elist.push_back(Edge(to_1d(17, 14), to_1d(18, 14)));
		m_Elist.push_back(Edge(to_1d(17, 15), to_1d(17, 16)));
		m_Elist.push_back(Edge(to_1d(17, 15), to_1d(18, 15)));
		m_Elist.push_back(Edge(to_1d(17, 16), to_1d(17, 17)));
		m_Elist.push_back(Edge(to_1d(17, 16), to_1d(18, 16)));
		m_Elist.push_back(Edge(to_1d(17, 17), to_1d(17, 18)));
		m_Elist.push_back(Edge(to_1d(17, 17), to_1d(18, 17)));
		m_Elist.push_back(Edge(to_1d(17, 18), to_1d(17, 19)));
		m_Elist.push_back(Edge(to_1d(17, 18), to_1d(18, 18)));
		m_Elist.push_back(Edge(to_1d(17, 19), to_1d(17, 20)));
		m_Elist.push_back(Edge(to_1d(17, 19), to_1d(18, 19)));
		m_Elist.push_back(Edge(to_1d(17, 20), to_1d(17, 21)));
		m_Elist.push_back(Edge(to_1d(17, 20), to_1d(18, 20)));
		m_Elist.push_back(Edge(to_1d(17, 21), to_1d(17, 22)));
		m_Elist.push_back(Edge(to_1d(17, 21), to_1d(18, 21)));
		m_Elist.push_back(Edge(to_1d(17, 22), to_1d(18, 22)));
		m_Elist.push_back(Edge(to_1d(17, 23), to_1d(17, 24)));
		m_Elist.push_back(Edge(to_1d(17, 23), to_1d(18, 23)));
		m_Elist.push_back(Edge(to_1d(17, 24), to_1d(17, 25)));
		m_Elist.push_back(Edge(to_1d(17, 24), to_1d(18, 24)));
		m_Elist.push_back(Edge(to_1d(17, 25), to_1d(17, 26)));
		m_Elist.push_back(Edge(to_1d(17, 25), to_1d(18, 25)));
		m_Elist.push_back(Edge(to_1d(17, 26), to_1d(18, 26)));
		m_Elist.push_back(Edge(to_1d(17, 27), to_1d(18, 27)));
		m_Elist.push_back(Edge(to_1d(17, 28), to_1d(17, 29)));
		m_Elist.push_back(Edge(to_1d(17, 28), to_1d(18, 28)));
		m_Elist.push_back(Edge(to_1d(17, 29), to_1d(17, 30)));
		m_Elist.push_back(Edge(to_1d(17, 30), to_1d(18, 30)));
		m_Elist.push_back(Edge(to_1d(17, 31), to_1d(18, 31)));
		m_Elist.push_back(Edge(to_1d(18, 0), to_1d(19, 0)));
		m_Elist.push_back(Edge(to_1d(18, 1), to_1d(18, 2)));
		m_Elist.push_back(Edge(to_1d(18, 2), to_1d(19, 2)));
		m_Elist.push_back(Edge(to_1d(18, 3), to_1d(19, 3)));
		m_Elist.push_back(Edge(to_1d(18, 5), to_1d(18, 6)));
		m_Elist.push_back(Edge(to_1d(18, 5), to_1d(19, 5)));
		m_Elist.push_back(Edge(to_1d(18, 6), to_1d(19, 6)));
		m_Elist.push_back(Edge(to_1d(18, 7), to_1d(18, 8)));
		m_Elist.push_back(Edge(to_1d(18, 7), to_1d(19, 7)));
		m_Elist.push_back(Edge(to_1d(18, 8), to_1d(19, 8)));
		m_Elist.push_back(Edge(to_1d(18, 9), to_1d(18, 10)));
		m_Elist.push_back(Edge(to_1d(18, 9), to_1d(19, 9)));
		m_Elist.push_back(Edge(to_1d(18, 11), to_1d(18, 12)));
		m_Elist.push_back(Edge(to_1d(18, 11), to_1d(19, 11)));
		m_Elist.push_back(Edge(to_1d(18, 13), to_1d(19, 13)));
		m_Elist.push_back(Edge(to_1d(18, 14), to_1d(18, 15)));
		m_Elist.push_back(Edge(to_1d(18, 14), to_1d(19, 14)));
		m_Elist.push_back(Edge(to_1d(18, 15), to_1d(18, 16)));
		m_Elist.push_back(Edge(to_1d(18, 15), to_1d(19, 15)));
		m_Elist.push_back(Edge(to_1d(18, 16), to_1d(18, 17)));
		m_Elist.push_back(Edge(to_1d(18, 16), to_1d(19, 16)));
		m_Elist.push_back(Edge(to_1d(18, 17), to_1d(18, 18)));
		m_Elist.push_back(Edge(to_1d(18, 17), to_1d(19, 17)));
		m_Elist.push_back(Edge(to_1d(18, 18), to_1d(18, 19)));
		m_Elist.push_back(Edge(to_1d(18, 18), to_1d(19, 18)));
		m_Elist.push_back(Edge(to_1d(18, 19), to_1d(18, 20)));
		m_Elist.push_back(Edge(to_1d(18, 19), to_1d(19, 19)));
		m_Elist.push_back(Edge(to_1d(18, 20), to_1d(18, 21)));
		m_Elist.push_back(Edge(to_1d(18, 20), to_1d(19, 20)));
		m_Elist.push_back(Edge(to_1d(18, 21), to_1d(18, 22)));
		m_Elist.push_back(Edge(to_1d(18, 21), to_1d(19, 21)));
		m_Elist.push_back(Edge(to_1d(18, 22), to_1d(19, 22)));
		m_Elist.push_back(Edge(to_1d(18, 24), to_1d(19, 24)));
		m_Elist.push_back(Edge(to_1d(18, 25), to_1d(19, 25)));
		m_Elist.push_back(Edge(to_1d(18, 26), to_1d(19, 26)));
		m_Elist.push_back(Edge(to_1d(18, 27), to_1d(19, 27)));
		m_Elist.push_back(Edge(to_1d(18, 28), to_1d(18, 29)));
		m_Elist.push_back(Edge(to_1d(18, 28), to_1d(19, 28)));
		m_Elist.push_back(Edge(to_1d(18, 29), to_1d(18, 30)));
		m_Elist.push_back(Edge(to_1d(18, 30), to_1d(18, 31)));
		m_Elist.push_back(Edge(to_1d(18, 30), to_1d(19, 30)));
		m_Elist.push_back(Edge(to_1d(18, 31), to_1d(19, 31)));
		m_Elist.push_back(Edge(to_1d(19, 0), to_1d(19, 1)));
		m_Elist.push_back(Edge(to_1d(19, 1), to_1d(19, 2)));
		m_Elist.push_back(Edge(to_1d(19, 1), to_1d(20, 1)));
		m_Elist.push_back(Edge(to_1d(19, 2), to_1d(19, 3)));
		m_Elist.push_back(Edge(to_1d(19, 3), to_1d(19, 4)));
		m_Elist.push_back(Edge(to_1d(19, 3), to_1d(20, 3)));
		m_Elist.push_back(Edge(to_1d(19, 4), to_1d(19, 5)));
		m_Elist.push_back(Edge(to_1d(19, 4), to_1d(20, 4)));
		m_Elist.push_back(Edge(to_1d(19, 5), to_1d(20, 5)));
		m_Elist.push_back(Edge(to_1d(19, 6), to_1d(19, 7)));
		m_Elist.push_back(Edge(to_1d(19, 8), to_1d(20, 8)));
		m_Elist.push_back(Edge(to_1d(19, 9), to_1d(20, 9)));
		m_Elist.push_back(Edge(to_1d(19, 10), to_1d(19, 11)));
		m_Elist.push_back(Edge(to_1d(19, 10), to_1d(20, 10)));
		m_Elist.push_back(Edge(to_1d(19, 11), to_1d(19, 12)));
		m_Elist.push_back(Edge(to_1d(19, 12), to_1d(19, 13)));
		m_Elist.push_back(Edge(to_1d(19, 12), to_1d(20, 12)));
		m_Elist.push_back(Edge(to_1d(19, 13), to_1d(20, 13)));
		m_Elist.push_back(Edge(to_1d(19, 14), to_1d(19, 15)));
		m_Elist.push_back(Edge(to_1d(19, 14), to_1d(20, 14)));
		m_Elist.push_back(Edge(to_1d(19, 15), to_1d(19, 16)));
		m_Elist.push_back(Edge(to_1d(19, 15), to_1d(20, 15)));
		m_Elist.push_back(Edge(to_1d(19, 16), to_1d(19, 17)));
		m_Elist.push_back(Edge(to_1d(19, 16), to_1d(20, 16)));
		m_Elist.push_back(Edge(to_1d(19, 17), to_1d(19, 18)));
		m_Elist.push_back(Edge(to_1d(19, 17), to_1d(20, 17)));
		m_Elist.push_back(Edge(to_1d(19, 18), to_1d(19, 19)));
		m_Elist.push_back(Edge(to_1d(19, 18), to_1d(20, 18)));
		m_Elist.push_back(Edge(to_1d(19, 19), to_1d(19, 20)));
		m_Elist.push_back(Edge(to_1d(19, 19), to_1d(20, 19)));
		m_Elist.push_back(Edge(to_1d(19, 20), to_1d(19, 21)));
		m_Elist.push_back(Edge(to_1d(19, 20), to_1d(20, 20)));
		m_Elist.push_back(Edge(to_1d(19, 21), to_1d(19, 22)));
		m_Elist.push_back(Edge(to_1d(19, 21), to_1d(20, 21)));
		m_Elist.push_back(Edge(to_1d(19, 22), to_1d(20, 22)));
		m_Elist.push_back(Edge(to_1d(19, 23), to_1d(19, 24)));
		m_Elist.push_back(Edge(to_1d(19, 24), to_1d(19, 25)));
		m_Elist.push_back(Edge(to_1d(19, 25), to_1d(19, 26)));
		m_Elist.push_back(Edge(to_1d(19, 26), to_1d(19, 27)));
		m_Elist.push_back(Edge(to_1d(19, 27), to_1d(19, 28)));
		m_Elist.push_back(Edge(to_1d(19, 28), to_1d(19, 29)));
		m_Elist.push_back(Edge(to_1d(19, 28), to_1d(20, 28)));
		m_Elist.push_back(Edge(to_1d(19, 29), to_1d(20, 29)));
		m_Elist.push_back(Edge(to_1d(19, 30), to_1d(20, 30)));
		m_Elist.push_back(Edge(to_1d(19, 31), to_1d(20, 31)));
		m_Elist.push_back(Edge(to_1d(20, 0), to_1d(20, 1)));
		m_Elist.push_back(Edge(to_1d(20, 0), to_1d(21, 0)));
		m_Elist.push_back(Edge(to_1d(20, 1), to_1d(21, 1)));
		m_Elist.push_back(Edge(to_1d(20, 2), to_1d(20, 3)));
		m_Elist.push_back(Edge(to_1d(20, 2), to_1d(21, 2)));
		m_Elist.push_back(Edge(to_1d(20, 4), to_1d(21, 4)));
		m_Elist.push_back(Edge(to_1d(20, 5), to_1d(20, 6)));
		m_Elist.push_back(Edge(to_1d(20, 5), to_1d(21, 5)));
		m_Elist.push_back(Edge(to_1d(20, 6), to_1d(20, 7)));
		m_Elist.push_back(Edge(to_1d(20, 7), to_1d(20, 8)));
		m_Elist.push_back(Edge(to_1d(20, 7), to_1d(21, 7)));
		m_Elist.push_back(Edge(to_1d(20, 9), to_1d(20, 10)));
		m_Elist.push_back(Edge(to_1d(20, 9), to_1d(21, 9)));
		m_Elist.push_back(Edge(to_1d(20, 10), to_1d(20, 11)));
		m_Elist.push_back(Edge(to_1d(20, 11), to_1d(20, 12)));
		m_Elist.push_back(Edge(to_1d(20, 11), to_1d(21, 11)));
		m_Elist.push_back(Edge(to_1d(20, 12), to_1d(21, 12)));
		m_Elist.push_back(Edge(to_1d(20, 14), to_1d(20, 15)));
		m_Elist.push_back(Edge(to_1d(20, 15), to_1d(20, 16)));
		m_Elist.push_back(Edge(to_1d(20, 16), to_1d(20, 17)));
		m_Elist.push_back(Edge(to_1d(20, 17), to_1d(20, 18)));
		m_Elist.push_back(Edge(to_1d(20, 18), to_1d(20, 19)));
		m_Elist.push_back(Edge(to_1d(20, 19), to_1d(20, 20)));
		m_Elist.push_back(Edge(to_1d(20, 20), to_1d(20, 21)));
		m_Elist.push_back(Edge(to_1d(20, 21), to_1d(20, 22)));
		m_Elist.push_back(Edge(to_1d(20, 23), to_1d(20, 24)));
		m_Elist.push_back(Edge(to_1d(20, 23), to_1d(21, 23)));
		m_Elist.push_back(Edge(to_1d(20, 24), to_1d(20, 25)));
		m_Elist.push_back(Edge(to_1d(20, 24), to_1d(21, 24)));
		m_Elist.push_back(Edge(to_1d(20, 25), to_1d(20, 26)));
		m_Elist.push_back(Edge(to_1d(20, 25), to_1d(21, 25)));
		m_Elist.push_back(Edge(to_1d(20, 26), to_1d(20, 27)));
		m_Elist.push_back(Edge(to_1d(20, 27), to_1d(20, 28)));
		m_Elist.push_back(Edge(to_1d(20, 27), to_1d(21, 27)));
		m_Elist.push_back(Edge(to_1d(20, 28), to_1d(21, 28)));
		m_Elist.push_back(Edge(to_1d(20, 29), to_1d(21, 29)));
		m_Elist.push_back(Edge(to_1d(20, 30), to_1d(20, 31)));
		m_Elist.push_back(Edge(to_1d(20, 30), to_1d(21, 30)));
		m_Elist.push_back(Edge(to_1d(20, 31), to_1d(21, 31)));
		m_Elist.push_back(Edge(to_1d(21, 0), to_1d(22, 0)));
		m_Elist.push_back(Edge(to_1d(21, 1), to_1d(21, 2)));
		m_Elist.push_back(Edge(to_1d(21, 1), to_1d(22, 1)));
		m_Elist.push_back(Edge(to_1d(21, 2), to_1d(21, 3)));
		m_Elist.push_back(Edge(to_1d(21, 2), to_1d(22, 2)));
		m_Elist.push_back(Edge(to_1d(21, 3), to_1d(21, 4)));
		m_Elist.push_back(Edge(to_1d(21, 3), to_1d(22, 3)));
		m_Elist.push_back(Edge(to_1d(21, 5), to_1d(21, 6)));
		m_Elist.push_back(Edge(to_1d(21, 6), to_1d(21, 7)));
		m_Elist.push_back(Edge(to_1d(21, 6), to_1d(22, 6)));
		m_Elist.push_back(Edge(to_1d(21, 8), to_1d(21, 9)));
		m_Elist.push_back(Edge(to_1d(21, 8), to_1d(22, 8)));
		m_Elist.push_back(Edge(to_1d(21, 9), to_1d(21, 10)));
		m_Elist.push_back(Edge(to_1d(21, 10), to_1d(21, 11)));
		m_Elist.push_back(Edge(to_1d(21, 10), to_1d(22, 10)));
		m_Elist.push_back(Edge(to_1d(21, 11), to_1d(22, 11)));
		m_Elist.push_back(Edge(to_1d(21, 12), to_1d(21, 13)));
		m_Elist.push_back(Edge(to_1d(21, 13), to_1d(21, 14)));
		m_Elist.push_back(Edge(to_1d(21, 13), to_1d(22, 13)));
		m_Elist.push_back(Edge(to_1d(21, 14), to_1d(21, 15)));
		m_Elist.push_back(Edge(to_1d(21, 15), to_1d(21, 16)));
		m_Elist.push_back(Edge(to_1d(21, 15), to_1d(22, 15)));
		m_Elist.push_back(Edge(to_1d(21, 16), to_1d(21, 17)));
		m_Elist.push_back(Edge(to_1d(21, 17), to_1d(21, 18)));
		m_Elist.push_back(Edge(to_1d(21, 17), to_1d(22, 17)));
		m_Elist.push_back(Edge(to_1d(21, 19), to_1d(22, 19)));
		m_Elist.push_back(Edge(to_1d(21, 20), to_1d(21, 21)));
		m_Elist.push_back(Edge(to_1d(21, 20), to_1d(22, 20)));
		m_Elist.push_back(Edge(to_1d(21, 21), to_1d(21, 22)));
		m_Elist.push_back(Edge(to_1d(21, 22), to_1d(21, 23)));
		m_Elist.push_back(Edge(to_1d(21, 23), to_1d(22, 23)));
		m_Elist.push_back(Edge(to_1d(21, 24), to_1d(22, 24)));
		m_Elist.push_back(Edge(to_1d(21, 25), to_1d(21, 26)));
		m_Elist.push_back(Edge(to_1d(21, 26), to_1d(22, 26)));
		m_Elist.push_back(Edge(to_1d(21, 27), to_1d(22, 27)));
		m_Elist.push_back(Edge(to_1d(21, 28), to_1d(21, 29)));
		m_Elist.push_back(Edge(to_1d(21, 28), to_1d(22, 28)));
		m_Elist.push_back(Edge(to_1d(21, 29), to_1d(21, 30)));
		m_Elist.push_back(Edge(to_1d(21, 29), to_1d(22, 29)));
		m_Elist.push_back(Edge(to_1d(21, 31), to_1d(22, 31)));
		m_Elist.push_back(Edge(to_1d(22, 0), to_1d(22, 1)));
		m_Elist.push_back(Edge(to_1d(22, 1), to_1d(23, 1)));
		m_Elist.push_back(Edge(to_1d(22, 2), to_1d(23, 2)));
		m_Elist.push_back(Edge(to_1d(22, 3), to_1d(22, 4)));
		m_Elist.push_back(Edge(to_1d(22, 3), to_1d(23, 3)));
		m_Elist.push_back(Edge(to_1d(22, 4), to_1d(22, 5)));
		m_Elist.push_back(Edge(to_1d(22, 5), to_1d(23, 5)));
		m_Elist.push_back(Edge(to_1d(22, 7), to_1d(22, 8)));
		m_Elist.push_back(Edge(to_1d(22, 7), to_1d(23, 7)));
		m_Elist.push_back(Edge(to_1d(22, 8), to_1d(22, 9)));
		m_Elist.push_back(Edge(to_1d(22, 9), to_1d(22, 10)));
		m_Elist.push_back(Edge(to_1d(22, 10), to_1d(23, 10)));
		m_Elist.push_back(Edge(to_1d(22, 11), to_1d(23, 11)));
		m_Elist.push_back(Edge(to_1d(22, 12), to_1d(22, 13)));
		m_Elist.push_back(Edge(to_1d(22, 12), to_1d(23, 12)));
		m_Elist.push_back(Edge(to_1d(22, 13), to_1d(22, 14)));
		m_Elist.push_back(Edge(to_1d(22, 14), to_1d(22, 15)));
		m_Elist.push_back(Edge(to_1d(22, 14), to_1d(23, 14)));
		m_Elist.push_back(Edge(to_1d(22, 15), to_1d(22, 16)));
		m_Elist.push_back(Edge(to_1d(22, 16), to_1d(22, 17)));
		m_Elist.push_back(Edge(to_1d(22, 16), to_1d(23, 16)));
		m_Elist.push_back(Edge(to_1d(22, 18), to_1d(23, 18)));
		m_Elist.push_back(Edge(to_1d(22, 19), to_1d(23, 19)));
		m_Elist.push_back(Edge(to_1d(22, 20), to_1d(22, 21)));
		m_Elist.push_back(Edge(to_1d(22, 21), to_1d(22, 22)));
		m_Elist.push_back(Edge(to_1d(22, 22), to_1d(22, 23)));
		m_Elist.push_back(Edge(to_1d(22, 23), to_1d(23, 23)));
		m_Elist.push_back(Edge(to_1d(22, 24), to_1d(22, 25)));
		m_Elist.push_back(Edge(to_1d(22, 24), to_1d(23, 24)));
		m_Elist.push_back(Edge(to_1d(22, 25), to_1d(22, 26)));
		m_Elist.push_back(Edge(to_1d(22, 26), to_1d(23, 26)));
		m_Elist.push_back(Edge(to_1d(22, 27), to_1d(22, 28)));
		m_Elist.push_back(Edge(to_1d(22, 27), to_1d(23, 27)));
		m_Elist.push_back(Edge(to_1d(22, 29), to_1d(22, 30)));
		m_Elist.push_back(Edge(to_1d(22, 29), to_1d(23, 29)));
		m_Elist.push_back(Edge(to_1d(22, 30), to_1d(22, 31)));
		m_Elist.push_back(Edge(to_1d(23, 0), to_1d(23, 1)));
		m_Elist.push_back(Edge(to_1d(23, 0), to_1d(24, 0)));
		m_Elist.push_back(Edge(to_1d(23, 1), to_1d(24, 1)));
		m_Elist.push_back(Edge(to_1d(23, 2), to_1d(23, 3)));
		m_Elist.push_back(Edge(to_1d(23, 2), to_1d(24, 2)));
		m_Elist.push_back(Edge(to_1d(23, 3), to_1d(23, 4)));
		m_Elist.push_back(Edge(to_1d(23, 4), to_1d(23, 5)));
		m_Elist.push_back(Edge(to_1d(23, 4), to_1d(24, 4)));
		m_Elist.push_back(Edge(to_1d(23, 6), to_1d(23, 7)));
		m_Elist.push_back(Edge(to_1d(23, 6), to_1d(24, 6)));
		m_Elist.push_back(Edge(to_1d(23, 8), to_1d(23, 9)));
		m_Elist.push_back(Edge(to_1d(23, 8), to_1d(24, 8)));
		m_Elist.push_back(Edge(to_1d(23, 9), to_1d(23, 10)));
		m_Elist.push_back(Edge(to_1d(23, 10), to_1d(24, 10)));
		m_Elist.push_back(Edge(to_1d(23, 11), to_1d(23, 12)));
		m_Elist.push_back(Edge(to_1d(23, 11), to_1d(24, 11)));
		m_Elist.push_back(Edge(to_1d(23, 12), to_1d(23, 13)));
		m_Elist.push_back(Edge(to_1d(23, 13), to_1d(23, 14)));
		m_Elist.push_back(Edge(to_1d(23, 13), to_1d(24, 13)));
		m_Elist.push_back(Edge(to_1d(23, 14), to_1d(23, 15)));
		m_Elist.push_back(Edge(to_1d(23, 15), to_1d(23, 16)));
		m_Elist.push_back(Edge(to_1d(23, 15), to_1d(24, 15)));
		m_Elist.push_back(Edge(to_1d(23, 16), to_1d(24, 16)));
		m_Elist.push_back(Edge(to_1d(23, 17), to_1d(23, 18)));
		m_Elist.push_back(Edge(to_1d(23, 17), to_1d(24, 17)));
		m_Elist.push_back(Edge(to_1d(23, 18), to_1d(23, 19)));
		m_Elist.push_back(Edge(to_1d(23, 18), to_1d(24, 18)));
		m_Elist.push_back(Edge(to_1d(23, 19), to_1d(23, 20)));
		m_Elist.push_back(Edge(to_1d(23, 20), to_1d(23, 21)));
		m_Elist.push_back(Edge(to_1d(23, 20), to_1d(24, 20)));
		m_Elist.push_back(Edge(to_1d(23, 21), to_1d(23, 22)));
		m_Elist.push_back(Edge(to_1d(23, 22), to_1d(23, 23)));
		m_Elist.push_back(Edge(to_1d(23, 24), to_1d(23, 25)));
		m_Elist.push_back(Edge(to_1d(23, 24), to_1d(24, 24)));
		m_Elist.push_back(Edge(to_1d(23, 25), to_1d(23, 26)));
		m_Elist.push_back(Edge(to_1d(23, 27), to_1d(24, 27)));
		m_Elist.push_back(Edge(to_1d(23, 28), to_1d(23, 29)));
		m_Elist.push_back(Edge(to_1d(23, 28), to_1d(24, 28)));
		m_Elist.push_back(Edge(to_1d(23, 29), to_1d(23, 30)));
		m_Elist.push_back(Edge(to_1d(23, 30), to_1d(23, 31)));
		m_Elist.push_back(Edge(to_1d(23, 31), to_1d(24, 31)));
		m_Elist.push_back(Edge(to_1d(24, 1), to_1d(24, 2)));
		m_Elist.push_back(Edge(to_1d(24, 1), to_1d(25, 1)));
		m_Elist.push_back(Edge(to_1d(24, 2), to_1d(24, 3)));
		m_Elist.push_back(Edge(to_1d(24, 3), to_1d(24, 4)));
		m_Elist.push_back(Edge(to_1d(24, 5), to_1d(24, 6)));
		m_Elist.push_back(Edge(to_1d(24, 5), to_1d(25, 5)));
		m_Elist.push_back(Edge(to_1d(24, 7), to_1d(25, 7)));
		m_Elist.push_back(Edge(to_1d(24, 8), to_1d(24, 9)));
		m_Elist.push_back(Edge(to_1d(24, 9), to_1d(24, 10)));
		m_Elist.push_back(Edge(to_1d(24, 10), to_1d(24, 11)));
		m_Elist.push_back(Edge(to_1d(24, 12), to_1d(24, 13)));
		m_Elist.push_back(Edge(to_1d(24, 13), to_1d(24, 14)));
		m_Elist.push_back(Edge(to_1d(24, 14), to_1d(24, 15)));
		m_Elist.push_back(Edge(to_1d(24, 16), to_1d(24, 17)));
		m_Elist.push_back(Edge(to_1d(24, 19), to_1d(24, 20)));
		m_Elist.push_back(Edge(to_1d(24, 20), to_1d(24, 21)));
		m_Elist.push_back(Edge(to_1d(24, 21), to_1d(24, 22)));
		m_Elist.push_back(Edge(to_1d(24, 22), to_1d(24, 23)));
		m_Elist.push_back(Edge(to_1d(24, 23), to_1d(24, 24)));
		m_Elist.push_back(Edge(to_1d(24, 24), to_1d(24, 25)));
		m_Elist.push_back(Edge(to_1d(24, 25), to_1d(24, 26)));
		m_Elist.push_back(Edge(to_1d(24, 26), to_1d(24, 27)));
		m_Elist.push_back(Edge(to_1d(24, 27), to_1d(24, 28)));
		m_Elist.push_back(Edge(to_1d(24, 29), to_1d(24, 30)));
		m_Elist.push_back(Edge(to_1d(24, 29), to_1d(25, 29)));
		m_Elist.push_back(Edge(to_1d(24, 30), to_1d(24, 31)));
		m_Elist.push_back(Edge(to_1d(24, 31), to_1d(25, 31)));
		m_Elist.push_back(Edge(to_1d(25, 0), to_1d(25, 1)));
		m_Elist.push_back(Edge(to_1d(25, 0), to_1d(26, 0)));
		m_Elist.push_back(Edge(to_1d(25, 1), to_1d(26, 1)));
		m_Elist.push_back(Edge(to_1d(25, 2), to_1d(25, 3)));
		m_Elist.push_back(Edge(to_1d(25, 2), to_1d(26, 2)));
		m_Elist.push_back(Edge(to_1d(25, 3), to_1d(25, 4)));
		m_Elist.push_back(Edge(to_1d(25, 3), to_1d(26, 3)));
		m_Elist.push_back(Edge(to_1d(25, 4), to_1d(25, 5)));
		m_Elist.push_back(Edge(to_1d(25, 4), to_1d(26, 4)));
		m_Elist.push_back(Edge(to_1d(25, 5), to_1d(25, 6)));
		m_Elist.push_back(Edge(to_1d(25, 5), to_1d(26, 5)));
		m_Elist.push_back(Edge(to_1d(25, 6), to_1d(25, 7)));
		m_Elist.push_back(Edge(to_1d(25, 7), to_1d(25, 8)));
		m_Elist.push_back(Edge(to_1d(25, 8), to_1d(25, 9)));
		m_Elist.push_back(Edge(to_1d(25, 9), to_1d(25, 10)));
		m_Elist.push_back(Edge(to_1d(25, 10), to_1d(25, 11)));
		m_Elist.push_back(Edge(to_1d(25, 11), to_1d(25, 12)));
		m_Elist.push_back(Edge(to_1d(25, 12), to_1d(25, 13)));
		m_Elist.push_back(Edge(to_1d(25, 13), to_1d(25, 14)));
		m_Elist.push_back(Edge(to_1d(25, 14), to_1d(25, 15)));
		m_Elist.push_back(Edge(to_1d(25, 15), to_1d(25, 16)));
		m_Elist.push_back(Edge(to_1d(25, 16), to_1d(25, 17)));
		m_Elist.push_back(Edge(to_1d(25, 17), to_1d(25, 18)));
		m_Elist.push_back(Edge(to_1d(25, 18), to_1d(25, 19)));
		m_Elist.push_back(Edge(to_1d(25, 19), to_1d(25, 20)));
		m_Elist.push_back(Edge(to_1d(25, 20), to_1d(25, 21)));
		m_Elist.push_back(Edge(to_1d(25, 20), to_1d(26, 20)));
		m_Elist.push_back(Edge(to_1d(25, 21), to_1d(25, 22)));
		m_Elist.push_back(Edge(to_1d(25, 22), to_1d(25, 23)));
		m_Elist.push_back(Edge(to_1d(25, 23), to_1d(25, 24)));
		m_Elist.push_back(Edge(to_1d(25, 24), to_1d(25, 25)));
		m_Elist.push_back(Edge(to_1d(25, 25), to_1d(25, 26)));
		m_Elist.push_back(Edge(to_1d(25, 26), to_1d(25, 27)));
		m_Elist.push_back(Edge(to_1d(25, 27), to_1d(25, 28)));
		m_Elist.push_back(Edge(to_1d(25, 28), to_1d(25, 29)));
		m_Elist.push_back(Edge(to_1d(25, 28), to_1d(26, 28)));
		m_Elist.push_back(Edge(to_1d(25, 30), to_1d(25, 31)));
		m_Elist.push_back(Edge(to_1d(25, 30), to_1d(26, 30)));
		m_Elist.push_back(Edge(to_1d(25, 31), to_1d(26, 31)));
		m_Elist.push_back(Edge(to_1d(26, 0), to_1d(27, 0)));
		m_Elist.push_back(Edge(to_1d(26, 1), to_1d(27, 1)));
		m_Elist.push_back(Edge(to_1d(26, 2), to_1d(26, 3)));
		m_Elist.push_back(Edge(to_1d(26, 2), to_1d(27, 2)));
		m_Elist.push_back(Edge(to_1d(26, 3), to_1d(26, 4)));
		m_Elist.push_back(Edge(to_1d(26, 3), to_1d(27, 3)));
		m_Elist.push_back(Edge(to_1d(26, 4), to_1d(27, 4)));
		m_Elist.push_back(Edge(to_1d(26, 5), to_1d(26, 6)));
		m_Elist.push_back(Edge(to_1d(26, 5), to_1d(27, 5)));
		m_Elist.push_back(Edge(to_1d(26, 6), to_1d(26, 7)));
		m_Elist.push_back(Edge(to_1d(26, 7), to_1d(27, 7)));
		m_Elist.push_back(Edge(to_1d(26, 8), to_1d(26, 9)));
		m_Elist.push_back(Edge(to_1d(26, 8), to_1d(27, 8)));
		m_Elist.push_back(Edge(to_1d(26, 10), to_1d(26, 11)));
		m_Elist.push_back(Edge(to_1d(26, 10), to_1d(27, 10)));
		m_Elist.push_back(Edge(to_1d(26, 11), to_1d(26, 12)));
		m_Elist.push_back(Edge(to_1d(26, 12), to_1d(26, 13)));
		m_Elist.push_back(Edge(to_1d(26, 12), to_1d(27, 12)));
		m_Elist.push_back(Edge(to_1d(26, 13), to_1d(26, 14)));
		m_Elist.push_back(Edge(to_1d(26, 14), to_1d(26, 15)));
		m_Elist.push_back(Edge(to_1d(26, 15), to_1d(26, 16)));
		m_Elist.push_back(Edge(to_1d(26, 15), to_1d(27, 15)));
		m_Elist.push_back(Edge(to_1d(26, 17), to_1d(26, 18)));
		m_Elist.push_back(Edge(to_1d(26, 17), to_1d(27, 17)));
		m_Elist.push_back(Edge(to_1d(26, 18), to_1d(27, 18)));
		m_Elist.push_back(Edge(to_1d(26, 19), to_1d(27, 19)));
		m_Elist.push_back(Edge(to_1d(26, 20), to_1d(27, 20)));
		m_Elist.push_back(Edge(to_1d(26, 21), to_1d(26, 22)));
		m_Elist.push_back(Edge(to_1d(26, 21), to_1d(27, 21)));
		m_Elist.push_back(Edge(to_1d(26, 22), to_1d(26, 23)));
		m_Elist.push_back(Edge(to_1d(26, 22), to_1d(27, 22)));
		m_Elist.push_back(Edge(to_1d(26, 23), to_1d(26, 24)));
		m_Elist.push_back(Edge(to_1d(26, 23), to_1d(27, 23)));
		m_Elist.push_back(Edge(to_1d(26, 24), to_1d(26, 25)));
		m_Elist.push_back(Edge(to_1d(26, 24), to_1d(27, 24)));
		m_Elist.push_back(Edge(to_1d(26, 25), to_1d(26, 26)));
		m_Elist.push_back(Edge(to_1d(26, 25), to_1d(27, 25)));
		m_Elist.push_back(Edge(to_1d(26, 26), to_1d(26, 27)));
		m_Elist.push_back(Edge(to_1d(26, 26), to_1d(27, 26)));
		m_Elist.push_back(Edge(to_1d(26, 27), to_1d(27, 27)));
		m_Elist.push_back(Edge(to_1d(26, 28), to_1d(27, 28)));
		m_Elist.push_back(Edge(to_1d(26, 29), to_1d(26, 30)));
		m_Elist.push_back(Edge(to_1d(26, 29), to_1d(27, 29)));
		m_Elist.push_back(Edge(to_1d(26, 30), to_1d(27, 30)));
		m_Elist.push_back(Edge(to_1d(26, 31), to_1d(27, 31)));
		m_Elist.push_back(Edge(to_1d(27, 0), to_1d(27, 1)));
		m_Elist.push_back(Edge(to_1d(27, 0), to_1d(28, 0)));
		m_Elist.push_back(Edge(to_1d(27, 1), to_1d(28, 1)));
		m_Elist.push_back(Edge(to_1d(27, 2), to_1d(27, 3)));
		m_Elist.push_back(Edge(to_1d(27, 3), to_1d(27, 4)));
		m_Elist.push_back(Edge(to_1d(27, 5), to_1d(28, 5)));
		m_Elist.push_back(Edge(to_1d(27, 6), to_1d(27, 7)));
		m_Elist.push_back(Edge(to_1d(27, 6), to_1d(28, 6)));
		m_Elist.push_back(Edge(to_1d(27, 7), to_1d(28, 7)));
		m_Elist.push_back(Edge(to_1d(27, 8), to_1d(27, 9)));
		m_Elist.push_back(Edge(to_1d(27, 8), to_1d(28, 8)));
		m_Elist.push_back(Edge(to_1d(27, 9), to_1d(27, 10)));
		m_Elist.push_back(Edge(to_1d(27, 10), to_1d(27, 11)));
		m_Elist.push_back(Edge(to_1d(27, 11), to_1d(27, 12)));
		m_Elist.push_back(Edge(to_1d(27, 12), to_1d(27, 13)));
		m_Elist.push_back(Edge(to_1d(27, 13), to_1d(27, 14)));
		m_Elist.push_back(Edge(to_1d(27, 15), to_1d(27, 16)));
		m_Elist.push_back(Edge(to_1d(27, 15), to_1d(28, 15)));
		m_Elist.push_back(Edge(to_1d(27, 16), to_1d(27, 17)));
		m_Elist.push_back(Edge(to_1d(27, 17), to_1d(28, 17)));
		m_Elist.push_back(Edge(to_1d(27, 19), to_1d(27, 20)));
		m_Elist.push_back(Edge(to_1d(27, 19), to_1d(28, 19)));
		m_Elist.push_back(Edge(to_1d(27, 20), to_1d(28, 20)));
		m_Elist.push_back(Edge(to_1d(27, 21), to_1d(27, 22)));
		m_Elist.push_back(Edge(to_1d(27, 21), to_1d(28, 21)));
		m_Elist.push_back(Edge(to_1d(27, 22), to_1d(27, 23)));
		m_Elist.push_back(Edge(to_1d(27, 22), to_1d(28, 22)));
		m_Elist.push_back(Edge(to_1d(27, 23), to_1d(27, 24)));
		m_Elist.push_back(Edge(to_1d(27, 23), to_1d(28, 23)));
		m_Elist.push_back(Edge(to_1d(27, 24), to_1d(27, 25)));
		m_Elist.push_back(Edge(to_1d(27, 24), to_1d(28, 24)));
		m_Elist.push_back(Edge(to_1d(27, 25), to_1d(27, 26)));
		m_Elist.push_back(Edge(to_1d(27, 25), to_1d(28, 25)));
		m_Elist.push_back(Edge(to_1d(27, 26), to_1d(27, 27)));
		m_Elist.push_back(Edge(to_1d(27, 26), to_1d(28, 26)));
		m_Elist.push_back(Edge(to_1d(27, 27), to_1d(28, 27)));
		m_Elist.push_back(Edge(to_1d(27, 28), to_1d(27, 29)));
		m_Elist.push_back(Edge(to_1d(27, 28), to_1d(28, 28)));
		m_Elist.push_back(Edge(to_1d(27, 29), to_1d(28, 29)));
		m_Elist.push_back(Edge(to_1d(27, 30), to_1d(27, 31)));
		m_Elist.push_back(Edge(to_1d(27, 30), to_1d(28, 30)));
		m_Elist.push_back(Edge(to_1d(27, 31), to_1d(28, 31)));
		m_Elist.push_back(Edge(to_1d(28, 0), to_1d(29, 0)));
		m_Elist.push_back(Edge(to_1d(28, 1), to_1d(28, 2)));
		m_Elist.push_back(Edge(to_1d(28, 2), to_1d(29, 2)));
		m_Elist.push_back(Edge(to_1d(28, 3), to_1d(28, 4)));
		m_Elist.push_back(Edge(to_1d(28, 4), to_1d(28, 5)));
		m_Elist.push_back(Edge(to_1d(28, 4), to_1d(29, 4)));
		m_Elist.push_back(Edge(to_1d(28, 5), to_1d(29, 5)));
		m_Elist.push_back(Edge(to_1d(28, 7), to_1d(28, 8)));
		m_Elist.push_back(Edge(to_1d(28, 9), to_1d(28, 10)));
		m_Elist.push_back(Edge(to_1d(28, 9), to_1d(29, 9)));
		m_Elist.push_back(Edge(to_1d(28, 10), to_1d(28, 11)));
		m_Elist.push_back(Edge(to_1d(28, 10), to_1d(29, 10)));
		m_Elist.push_back(Edge(to_1d(28, 11), to_1d(28, 12)));
		m_Elist.push_back(Edge(to_1d(28, 12), to_1d(29, 12)));
		m_Elist.push_back(Edge(to_1d(28, 13), to_1d(28, 14)));
		m_Elist.push_back(Edge(to_1d(28, 13), to_1d(29, 13)));
		m_Elist.push_back(Edge(to_1d(28, 14), to_1d(29, 14)));
		m_Elist.push_back(Edge(to_1d(28, 15), to_1d(28, 16)));
		m_Elist.push_back(Edge(to_1d(28, 15), to_1d(29, 15)));
		m_Elist.push_back(Edge(to_1d(28, 16), to_1d(29, 16)));
		m_Elist.push_back(Edge(to_1d(28, 17), to_1d(28, 18)));
		m_Elist.push_back(Edge(to_1d(28, 17), to_1d(29, 17)));
		m_Elist.push_back(Edge(to_1d(28, 18), to_1d(28, 19)));
		m_Elist.push_back(Edge(to_1d(28, 19), to_1d(29, 19)));
		m_Elist.push_back(Edge(to_1d(28, 20), to_1d(29, 20)));
		m_Elist.push_back(Edge(to_1d(28, 21), to_1d(28, 22)));
		m_Elist.push_back(Edge(to_1d(28, 21), to_1d(29, 21)));
		m_Elist.push_back(Edge(to_1d(28, 22), to_1d(28, 23)));
		m_Elist.push_back(Edge(to_1d(28, 22), to_1d(29, 22)));
		m_Elist.push_back(Edge(to_1d(28, 23), to_1d(28, 24)));
		m_Elist.push_back(Edge(to_1d(28, 23), to_1d(29, 23)));
		m_Elist.push_back(Edge(to_1d(28, 24), to_1d(28, 25)));
		m_Elist.push_back(Edge(to_1d(28, 24), to_1d(29, 24)));
		m_Elist.push_back(Edge(to_1d(28, 25), to_1d(28, 26)));
		m_Elist.push_back(Edge(to_1d(28, 25), to_1d(29, 25)));
		m_Elist.push_back(Edge(to_1d(28, 26), to_1d(28, 27)));
		m_Elist.push_back(Edge(to_1d(28, 26), to_1d(29, 26)));
		m_Elist.push_back(Edge(to_1d(28, 27), to_1d(29, 27)));
		m_Elist.push_back(Edge(to_1d(28, 28), to_1d(29, 28)));
		m_Elist.push_back(Edge(to_1d(28, 29), to_1d(28, 30)));
		m_Elist.push_back(Edge(to_1d(28, 29), to_1d(29, 29)));
		m_Elist.push_back(Edge(to_1d(28, 31), to_1d(29, 31)));
		m_Elist.push_back(Edge(to_1d(29, 0), to_1d(29, 1)));
		m_Elist.push_back(Edge(to_1d(29, 0), to_1d(30, 0)));
		m_Elist.push_back(Edge(to_1d(29, 1), to_1d(30, 1)));
		m_Elist.push_back(Edge(to_1d(29, 2), to_1d(29, 3)));
		m_Elist.push_back(Edge(to_1d(29, 3), to_1d(30, 3)));
		m_Elist.push_back(Edge(to_1d(29, 4), to_1d(29, 5)));
		m_Elist.push_back(Edge(to_1d(29, 5), to_1d(30, 5)));
		m_Elist.push_back(Edge(to_1d(29, 6), to_1d(29, 7)));
		m_Elist.push_back(Edge(to_1d(29, 6), to_1d(30, 6)));
		m_Elist.push_back(Edge(to_1d(29, 7), to_1d(29, 8)));
		m_Elist.push_back(Edge(to_1d(29, 8), to_1d(30, 8)));
		m_Elist.push_back(Edge(to_1d(29, 9), to_1d(30, 9)));
		m_Elist.push_back(Edge(to_1d(29, 10), to_1d(29, 11)));
		m_Elist.push_back(Edge(to_1d(29, 11), to_1d(29, 12)));
		m_Elist.push_back(Edge(to_1d(29, 12), to_1d(29, 13)));
		m_Elist.push_back(Edge(to_1d(29, 14), to_1d(30, 14)));
		m_Elist.push_back(Edge(to_1d(29, 15), to_1d(30, 15)));
		m_Elist.push_back(Edge(to_1d(29, 16), to_1d(29, 17)));
		m_Elist.push_back(Edge(to_1d(29, 17), to_1d(29, 18)));
		m_Elist.push_back(Edge(to_1d(29, 18), to_1d(30, 18)));
		m_Elist.push_back(Edge(to_1d(29, 19), to_1d(29, 20)));
		m_Elist.push_back(Edge(to_1d(29, 19), to_1d(30, 19)));
		m_Elist.push_back(Edge(to_1d(29, 20), to_1d(30, 20)));
		m_Elist.push_back(Edge(to_1d(29, 21), to_1d(29, 22)));
		m_Elist.push_back(Edge(to_1d(29, 22), to_1d(29, 23)));
		m_Elist.push_back(Edge(to_1d(29, 23), to_1d(29, 24)));
		m_Elist.push_back(Edge(to_1d(29, 24), to_1d(29, 25)));
		m_Elist.push_back(Edge(to_1d(29, 25), to_1d(29, 26)));
		m_Elist.push_back(Edge(to_1d(29, 26), to_1d(29, 27)));
		m_Elist.push_back(Edge(to_1d(29, 28), to_1d(29, 29)));
		m_Elist.push_back(Edge(to_1d(29, 28), to_1d(30, 28)));
		m_Elist.push_back(Edge(to_1d(29, 30), to_1d(29, 31)));
		m_Elist.push_back(Edge(to_1d(29, 30), to_1d(30, 30)));
		m_Elist.push_back(Edge(to_1d(29, 31), to_1d(30, 31)));
		m_Elist.push_back(Edge(to_1d(30, 0), to_1d(31, 0)));
		m_Elist.push_back(Edge(to_1d(30, 1), to_1d(30, 2)));
		m_Elist.push_back(Edge(to_1d(30, 2), to_1d(31, 2)));
		m_Elist.push_back(Edge(to_1d(30, 3), to_1d(30, 4)));
		m_Elist.push_back(Edge(to_1d(30, 4), to_1d(31, 4)));
		m_Elist.push_back(Edge(to_1d(30, 6), to_1d(30, 7)));
		m_Elist.push_back(Edge(to_1d(30, 7), to_1d(30, 8)));
		m_Elist.push_back(Edge(to_1d(30, 7), to_1d(31, 7)));
		m_Elist.push_back(Edge(to_1d(30, 8), to_1d(30, 9)));
		m_Elist.push_back(Edge(to_1d(30, 9), to_1d(31, 9)));
		m_Elist.push_back(Edge(to_1d(30, 10), to_1d(30, 11)));
		m_Elist.push_back(Edge(to_1d(30, 10), to_1d(31, 10)));
		m_Elist.push_back(Edge(to_1d(30, 11), to_1d(30, 12)));
		m_Elist.push_back(Edge(to_1d(30, 12), to_1d(30, 13)));
		m_Elist.push_back(Edge(to_1d(30, 12), to_1d(31, 12)));
		m_Elist.push_back(Edge(to_1d(30, 13), to_1d(30, 14)));
		m_Elist.push_back(Edge(to_1d(30, 14), to_1d(30, 15)));
		m_Elist.push_back(Edge(to_1d(30, 14), to_1d(31, 14)));
		m_Elist.push_back(Edge(to_1d(30, 15), to_1d(30, 16)));
		m_Elist.push_back(Edge(to_1d(30, 16), to_1d(30, 17)));
		m_Elist.push_back(Edge(to_1d(30, 16), to_1d(31, 16)));
		m_Elist.push_back(Edge(to_1d(30, 17), to_1d(30, 18)));
		m_Elist.push_back(Edge(to_1d(30, 20), to_1d(31, 20)));
		m_Elist.push_back(Edge(to_1d(30, 21), to_1d(30, 22)));
		m_Elist.push_back(Edge(to_1d(30, 21), to_1d(31, 21)));
		m_Elist.push_back(Edge(to_1d(30, 22), to_1d(30, 23)));
		m_Elist.push_back(Edge(to_1d(30, 22), to_1d(31, 22)));
		m_Elist.push_back(Edge(to_1d(30, 23), to_1d(30, 24)));
		m_Elist.push_back(Edge(to_1d(30, 24), to_1d(30, 25)));
		m_Elist.push_back(Edge(to_1d(30, 25), to_1d(30, 26)));
		m_Elist.push_back(Edge(to_1d(30, 25), to_1d(31, 25)));
		m_Elist.push_back(Edge(to_1d(30, 26), to_1d(30, 27)));
		m_Elist.push_back(Edge(to_1d(30, 27), to_1d(30, 28)));
		m_Elist.push_back(Edge(to_1d(30, 27), to_1d(31, 27)));
		m_Elist.push_back(Edge(to_1d(30, 29), to_1d(30, 30)));
		m_Elist.push_back(Edge(to_1d(30, 29), to_1d(31, 29)));
		m_Elist.push_back(Edge(to_1d(30, 31), to_1d(31, 31)));
		m_Elist.push_back(Edge(to_1d(31, 0), to_1d(31, 1)));
		m_Elist.push_back(Edge(to_1d(31, 1), to_1d(31, 2)));
		m_Elist.push_back(Edge(to_1d(31, 2), to_1d(31, 3)));
		m_Elist.push_back(Edge(to_1d(31, 3), to_1d(31, 4)));
		m_Elist.push_back(Edge(to_1d(31, 4), to_1d(31, 5)));
		m_Elist.push_back(Edge(to_1d(31, 5), to_1d(31, 6)));
		m_Elist.push_back(Edge(to_1d(31, 6), to_1d(31, 7)));
		m_Elist.push_back(Edge(to_1d(31, 7), to_1d(31, 8)));
		m_Elist.push_back(Edge(to_1d(31, 8), to_1d(31, 9)));
		m_Elist.push_back(Edge(to_1d(31, 9), to_1d(31, 10)));
		m_Elist.push_back(Edge(to_1d(31, 10), to_1d(31, 11)));
		m_Elist.push_back(Edge(to_1d(31, 11), to_1d(31, 12)));
		m_Elist.push_back(Edge(to_1d(31, 12), to_1d(31, 13)));
		m_Elist.push_back(Edge(to_1d(31, 13), to_1d(31, 14)));
		m_Elist.push_back(Edge(to_1d(31, 14), to_1d(31, 15)));
		m_Elist.push_back(Edge(to_1d(31, 15), to_1d(31, 16)));
		m_Elist.push_back(Edge(to_1d(31, 16), to_1d(31, 17)));
		m_Elist.push_back(Edge(to_1d(31, 17), to_1d(31, 18)));
		m_Elist.push_back(Edge(to_1d(31, 18), to_1d(31, 19)));
		m_Elist.push_back(Edge(to_1d(31, 19), to_1d(31, 20)));
		m_Elist.push_back(Edge(to_1d(31, 20), to_1d(31, 21)));
		m_Elist.push_back(Edge(to_1d(31, 22), to_1d(31, 23)));
		m_Elist.push_back(Edge(to_1d(31, 23), to_1d(31, 24)));
		m_Elist.push_back(Edge(to_1d(31, 24), to_1d(31, 25)));
		m_Elist.push_back(Edge(to_1d(31, 25), to_1d(31, 26)));
		m_Elist.push_back(Edge(to_1d(31, 26), to_1d(31, 27)));
		m_Elist.push_back(Edge(to_1d(31, 27), to_1d(31, 28)));
		m_Elist.push_back(Edge(to_1d(31, 28), to_1d(31, 29)));
		m_Elist.push_back(Edge(to_1d(31, 29), to_1d(31, 30)));
		m_Elist.push_back(Edge(to_1d(31, 30), to_1d(31, 31)));

	}
	/* 迷路 end */

	m_Start = to_1d(0, 31);
	m_Goal = to_1d(26, 3);
}

int CGlaphSearchDlg::to_1d(int x, int y)
{
	return y + (x * m_MapSize);
}

BEGIN_MESSAGE_MAP(CGlaphSearchDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGlaphSearchDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CGlaphSearchDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CGlaphSearchDlg::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_BFS, &CGlaphSearchDlg::OnBnClickedButtonBfs)
	ON_BN_CLICKED(IDC_BUTTON_DFS, &CGlaphSearchDlg::OnBnClickedButtonDfs)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_BestFirstSearch, &CGlaphSearchDlg::OnBnClickedButtonBestfirstsearch)
END_MESSAGE_MAP()


// CGlaphSearchDlg メッセージ ハンドラー

BOOL CGlaphSearchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

#if 1
	// TODO: 初期化をここに追加します。
	CreateMap();
#else
	m_Vlist.push_back(Vertex(100, 20));
	m_Vlist.push_back(Vertex(50, 60));
	m_Vlist.push_back(Vertex(120, 50));
	m_Vlist.push_back(Vertex(150, 50));
	m_Vlist.push_back(Vertex(160, 90));
	m_Vlist.push_back(Vertex(190, 40));
	m_Vlist.push_back(Vertex(100, 100));
	m_Vlist.push_back(Vertex(60, 150));
	m_Vlist.push_back(Vertex(150, 140));
	m_Vlist.push_back(Vertex(190, 110));
	m_Vlist.push_back(Vertex(230, 150));
	m_Vlist.push_back(Vertex(280, 120));
	m_Vlist.push_back(Vertex(260, 60));

	m_Elist.push_back(Edge(0, 1));
	m_Elist.push_back(Edge(1, 2));
	m_Elist.push_back(Edge(3, 2));
	m_Elist.push_back(Edge(3, 5));
	m_Elist.push_back(Edge(5, 4));
	m_Elist.push_back(Edge(1, 6));
	m_Elist.push_back(Edge(4, 6));
	m_Elist.push_back(Edge(4, 8));
	m_Elist.push_back(Edge(8, 7));
	m_Elist.push_back(Edge(6, 7));
	m_Elist.push_back(Edge(9, 8));
	m_Elist.push_back(Edge(9, 10));
	m_Elist.push_back(Edge(10, 11));
	m_Elist.push_back(Edge(4, 12));
#endif
	m_Graph = new BreadthFirstSearch(m_Vlist, m_Elist);
	m_Graph->init(m_Start, m_Goal);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CGlaphSearchDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CGlaphSearchDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CClientDC cdc(this);

		// ペンを作成します。
		// ペンのスタイル : 実線
		// ペンの太さ    : 1
		// ペンの色     : 黒
		CPen pen(PS_SOLID, 1, RGB(0, 0, 0));

		// 新しいペン(pen)を設定し、設定されていた元のペンをpOldPenに保存します。
		CPen* pOldPen = cdc.SelectObject(&pen);

		// 辺を描画
		for (auto e : m_Graph->elist)
		{
			cdc.MoveTo(m_Graph->vlist[e.from]);
			cdc.LineTo(m_Graph->vlist[e.to]);
		}
		cdc.SelectObject(pOldPen);

		int index = 0;
		// 頂点を描画
		for (auto v : m_Graph->vlist)
		{
			int color = 0;

			switch (m_Graph->slist[index])
			{
			case E_Status_UnExplored:
				// 未探索
				color = RGB(255, 255, 255);
				break;
			case E_Status_Looked:
				// 認知
				color = RGB(0, 255, 255);
				break;
			case E_Status_Exploring:
				// 探索中
				color = RGB(200, 200, 0);
				break;
			case E_Status_Searched:
				// 探索済み
				color = RGB(100, 100, 100);
				break;
			case E_Status_ShortestPath:
				// 最短経路
				color = RGB(0, 200, 0);
				break;
			default:
				break;
			}

			if (m_Graph->SearchVertexIndex == index)
			{ // ゴール
				color = RGB(200, 100, 0);
			}

			// 塗りつぶし色
			CBrush brush(color);
			// 新しいブラシ(brush)を設定し、設定されていた元のブラシをpOldBrushに保存します。
			CBrush* pOldBrush = cdc.SelectObject(&brush);

			CSize size(10, 10);
			CPoint point(v.x - (size.cx / 2), v.y - (size.cy / 2));
			CRect rect(point, size);
			cdc.Ellipse(rect);
			
			cdc.SelectObject(pOldBrush);

			//// 情報text
			//CFont font;
			//CFont* pOldfont;
			//font.CreateFontW(10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"consolas");
			//pOldfont = cdc.SelectObject(&font);
			//CString str;
			//point.Offset(10, -5);
			//str.Format(L"%d", index);
			//cdc.TextOutW(point.x, point.y, str);
			//str.Format(L"%2d", m_Graph->routelist[index]);
			//point.Offset(0, 10);
			//cdc.TextOutW(point.x, point.y, str);
			//cdc.SelectObject(pOldfont);
			index++;
		}
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CGlaphSearchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGlaphSearchDlg::OnBnClickedOk()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	//CDialogEx::OnOK();
}


void CGlaphSearchDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: ここにメッセージ ハンドラー コードを追加します。
	if (m_Graph)
	{
		delete m_Graph;
	}
}


void CGlaphSearchDlg::OnBnClickedButtonReset()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	m_Graph->init(m_Start, m_Goal);
	Invalidate(FALSE);
}


void CGlaphSearchDlg::OnBnClickedButtonNext()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	bool end = m_Graph->SearchNext();
	if (end)
	{
		int count = m_Graph->GetShortestPathDistance();
		CString str;
		str.Format(L"Searched shortest path : %3d", count);
		m_ddx_ShortestPathText1.SetWindowTextW(str);
	}
	Invalidate(FALSE);
}


void CGlaphSearchDlg::OnBnClickedButtonBfs()
{ //幅優先探索
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	if (m_Graph)
	{
		delete m_Graph;
	}
	m_Graph = new BreadthFirstSearch(m_Vlist, m_Elist);
	m_Graph->init(m_Start, m_Goal);
}


void CGlaphSearchDlg::OnBnClickedButtonDfs()
{ //深さ優先探索
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	if (m_Graph)
	{
		delete m_Graph;
	}
	m_Graph = new DepthFirstSearch(m_Vlist, m_Elist);
	m_Graph->init(m_Start, m_Goal);
}


void CGlaphSearchDlg::OnBnClickedButtonBestfirstsearch()
{ //最良優先探索
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	if (m_Graph)
	{
		delete m_Graph;
	}
	m_Graph = new BestFirstSearch(m_Vlist, m_Elist);
	m_Graph->init(m_Start, m_Goal);
}
