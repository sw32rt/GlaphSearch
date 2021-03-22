
// GlaphSearchDlg.h : ヘッダー ファイル
//

#pragma once
#include "GraphSearch.h"


// CGlaphSearchDlg ダイアログ
class CGlaphSearchDlg : public CDialogEx
{
// コンストラクション
public:
	CGlaphSearchDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLAPHSEARCH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート
// ユーザー
public:
	void CreateMap(void);
	const int m_MapSize = 32;
	int m_Start = 0;
	int m_Goal = (m_MapSize * m_MapSize) - 1;
	GraphSearch* m_Graph = NULL;
	std::vector<Vertex> m_Vlist;
	std::vector<Edge> m_Elist;
	int to_1d(int x, int y);


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnBnClickedButtonBfs();
	afx_msg void OnBnClickedButtonDfs();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonBestfirstsearch();
	CStatic m_ddx_ShortestPathText1;
};
