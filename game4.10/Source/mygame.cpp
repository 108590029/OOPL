
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "monster.h"
#include "player1.h"


int selectleve = 0;



namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
}

void CGameStateInit::OnInit()
{

	logo.LoadBitmap(IDB_ST);
	selectL.LoadBitmap(IDB_SELECT);
	cm = FALSE;
	


}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//const char KEY_ESC = 27;
	//const char KEY_SPACE = ' ';
	//if (nChar == KEY_SPACE)
	//	GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
	//else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
		//PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// 關閉遊戲
	

}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	if (cm) {
		sprintf(outx, "x:%d ", point.x);
		sprintf(outy, " y:%d\n", point.y);
		OutputDebugString(outx);

		if (point.x >= 50 && point.y >= 260 && point.x <= 140 && point.y
			<= 310) {
			selectleve = 1;
			
			GotoGameState(GAME_STATE_RUN);
		}
		else if (point.x >= 140 && point.y >= 260 && point.x <= 230 && point.y
			<= 310)
		{
			selectleve = 2;
			GotoGameState(GAME_STATE_RUN);
		}
		else if (point.x >= 230 && point.y >= 260 && point.x <=320 && point.y
			<= 310)
		{
			selectleve = 3;
			GotoGameState(GAME_STATE_RUN);
		}
		else if (point.x >= 320 && point.y >= 260 && point.x <= 410 && point.y
			<= 310)
		{
			selectleve = 4;
			GotoGameState(GAME_STATE_RUN);
		}
	
		//GotoGameState(GAME_STATE_RUN);// 切換至GAME_STATE_RUN
		
	}
	else
	{
		cm = TRUE;
	}
	

}

void CGameStateInit::OnShow()
{

	
	if (cm) {

		selectL.ShowBitmap();

	}
	else
	{
		logo.ShowBitmap();
	}

	//
	// 貼上logo
	//
	/*
	logo.SetTopLeft((SIZE_X - logo.Width())/2, SIZE_Y/8);
	
	//
	// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
	//
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	if (ENABLE_GAME_PAUSE)
		pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
	pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC*/
}								



/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
	: CGameState(g)		
{
	
}

CGameStateRun::~CGameStateRun()
{
	

}

void CGameStateRun::OnBeginState()
{

//	const int HITS_LEFT = 10;
	//const int HITS_LEFT_X = 590;
	//const int HITS_LEFT_Y = 0;
	//const int BACKGROUND_X = 0;
	//const int ANIMATION_SPEED = 15;

//	eraser.Initialize();
	//background.SetTopLeft(BACKGROUND_X,0);				// 設定背景的起始座標
	//help.SetTopLeft(0, SIZE_Y - help.Height());			// 設定說明圖的起始座標
	//hits_left.SetInteger(HITS_LEFT);					// 指定剩下的撞擊數
	//hits_left.SetTopLeft(HITS_LEFT_X,HITS_LEFT_Y);		// 指定剩下撞擊數的座標
	//CAudio::Instance()->Play(AUDIO_LAKE, true);			// 撥放 WAVE
	//CAudio::Instance()->Play(AUDIO_DING, false);		// 撥放 WAVE
	//CAudio::Instance()->Play(AUDIO_NTUT, true);			// 撥放 MIDI
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	//
	// 如果希望修改cursor的樣式，則將下面程式的commment取消即可
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//
	// 移動背景圖的座標
	//

		//player.SetTopLeft(playerX, playerY);
		monster1.OnMove();
		monster2.OnMove();
		monster3.OnMove();
		p1.OnMove();



	

	

}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	//ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
	//
	// 開始載入資料
	//

	//background1.LoadBitmap(IDB_BACKGROUND1);	// 載入背景的圖形

	//background.LoadBitmap(IDB_BACKGROUND1);
	//
	// 完成部分Loading動作，提高進度
	//
	//ShowInitProgress(50);
	//Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 繼續載入其他資料
	
	//corner.ShowBitmap(background1);

	//CAudio::Instance()->Load(AUDIO_DING,  "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
	//CAudio::Instance()->Load(AUDIO_LAKE,  "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
	//CAudio::Instance()->Load(AUDIO_NTUT,  "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
	//
	// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
	//
	//playerX = 830;
	//playerY = 384;
	level1.LoadBitmap(IDB_LE1);
	level2.LoadBitmap(IDB_LE2);
	level3.LoadBitmap(IDB_LE3);
	level4.LoadBitmap(IDB_LE4);
	//background1.LoadBitmap(IDB_SELECT);
	//player.LoadBitmapA(IDB_PLAYER,RGB(255,255,255));
	monster1.OnInit(100,395);
	p1.OnInit();
	monster2.OnInit(250,395);
	monster3.OnInit(400, 395);
	/*
	if (selectleve == 1) {
		p1.OnInit(10, 385);
	}
	else if (selectleve == 2) {
		p1.OnInit(700, 200);
	}
	else if (selectleve == 3) {
		p1.OnInit(500, 385);
	}
	else if (selectleve == 4) {
		p1.OnInit(260, 230);
	}*/
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	/*
	if (nChar == KEY_LEFT)
		playerX -= 5;
	if (nChar == KEY_RIGHT)
		playerX += 5;
	if (nChar == KEY_UP)
		playerY -= 5;
	if (nChar == KEY_DOWN)
		playerY += 5;
	*/


	if (nChar == KEY_LEFT)
		p1.goLeft(true);
	if (nChar == KEY_RIGHT)
		p1.goRight(true);
	if (nChar == KEY_UP)
		p1.goUp(true);
	if (nChar == KEY_DOWN)
		p1.goDown(true);
	
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	/*
	if (nChar == KEY_LEFT)
		action.SetMovingLeft(false);
	if (nChar == KEY_RIGHT)
		action.SetMovingRight(false);
	if (nChar == KEY_UP)
		action.SetMovingUp(false);
	if (nChar == KEY_DOWN)
		action.SetMovingDown(false);
		*/
	if (nChar == KEY_LEFT)
		p1.goLeft(false);
	if (nChar == KEY_RIGHT)
		p1.goRight(false);
	if (nChar == KEY_UP)
		p1.goUp(false);
	if (nChar == KEY_DOWN)
		p1.goDown(false);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	//eraser.SetMovingLeft(true);

	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	//eraser.SetMovingLeft(false);
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	// 沒事。如果需要處理滑鼠移動的話，寫code在這裡

}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	//eraser.SetMovingRight(true);

}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	//eraser.SetMovingRight(false);

}

void CGameStateRun::OnShow()
{
	//
	//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
	//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
	//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。

	
	//level2.ShowBitmap();
	//level3.ShowBitmap();
	//level4.ShowBitmap();
	//player.ShowBitmap();
	/*
	level1.ShowBitmap();			// 貼上背景圖
	monster1.OnShow();
	monster2.OnShow();
	monster3.OnShow();
	p1.OnShow();*/
	//  貼上左上及右下角落的圖
	//
	//corner.SetTopLeft(0,0);
	//corner.ShowBitmap();
	//corner.SetTopLeft(SIZE_X-corner.Width(), SIZE_Y-corner.Height());
	//corner.ShowBitmap();
	//p1.OnShow();
	if (selectleve == 1) {
		level1.ShowBitmap();			// 貼上背景圖
		monster1.OnShow();
		monster2.OnShow();
		monster3.OnShow();		
		p1.OnShow();

	}
	else if (selectleve == 2)
	{
		level2.ShowBitmap();		
		p1.OnShow();
	}
	else if (selectleve == 3)
	{
		level3.ShowBitmap();		
		p1.OnShow();
	}
	else if (selectleve == 4)
	{
		level4.ShowBitmap();
		p1.OnShow();
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
	: CGameState(g)
{

}

void CGameStateOver::OnMove()
{
	//counter--;
	//if (counter < 0)
		//GotoGameState(GAME_STATE_INIT);

}

void CGameStateOver::OnBeginState()
{

}

void CGameStateOver::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
//	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	//Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	//ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	/*
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC*/
}




}
