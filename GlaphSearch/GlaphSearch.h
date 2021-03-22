
// GlaphSearch.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CGlaphSearchApp:
// このクラスの実装については、GlaphSearch.cpp を参照してください
//

class CGlaphSearchApp : public CWinApp
{
public:
	CGlaphSearchApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CGlaphSearchApp theApp;
