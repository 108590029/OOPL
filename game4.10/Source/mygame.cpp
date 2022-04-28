
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
// �o��class���C�����C���}�Y�e������
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
	//	GotoGameState(GAME_STATE_RUN);						// ������GAME_STATE_RUN
	//else if (nChar == KEY_ESC)								// Demo �����C������k
		//PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// �����C��
	

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
	
		//GotoGameState(GAME_STATE_RUN);// ������GAME_STATE_RUN
		
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
	// �K�Wlogo
	//
	/*
	logo.SetTopLeft((SIZE_X - logo.Width())/2, SIZE_Y/8);
	
	//
	// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
	//
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
	fp=pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	if (ENABLE_GAME_PAUSE)
		pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
	pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC*/
}								



/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
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
	//background.SetTopLeft(BACKGROUND_X,0);				// �]�w�I�����_�l�y��
	//help.SetTopLeft(0, SIZE_Y - help.Height());			// �]�w�����Ϫ��_�l�y��
	//hits_left.SetInteger(HITS_LEFT);					// ���w�ѤU��������
	//hits_left.SetTopLeft(HITS_LEFT_X,HITS_LEFT_Y);		// ���w�ѤU�����ƪ��y��
	//CAudio::Instance()->Play(AUDIO_LAKE, true);			// ���� WAVE
	//CAudio::Instance()->Play(AUDIO_DING, false);		// ���� WAVE
	//CAudio::Instance()->Play(AUDIO_NTUT, true);			// ���� MIDI
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	//
	// �p�G�Ʊ�ק�cursor���˦��A�h�N�U���{����commment�����Y�i
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//
	// ���ʭI���Ϫ��y��
	//

		//player.SetTopLeft(playerX, playerY);
		monster1.OnMove();
		monster2.OnMove();
		monster3.OnMove();
		p1.OnMove();



	

	

}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	//ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
	//
	// �}�l���J���
	//

	//background1.LoadBitmap(IDB_BACKGROUND1);	// ���J�I�����ϧ�

	//background.LoadBitmap(IDB_BACKGROUND1);
	//
	// ��������Loading�ʧ@�A�����i��
	//
	//ShowInitProgress(50);
	//Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �~����J��L���
	
	//corner.ShowBitmap(background1);

	//CAudio::Instance()->Load(AUDIO_DING,  "sounds\\ding.wav");	// ���J�s��0���n��ding.wav
	//CAudio::Instance()->Load(AUDIO_LAKE,  "sounds\\lake.mp3");	// ���J�s��1���n��lake.mp3
	//CAudio::Instance()->Load(AUDIO_NTUT,  "sounds\\ntut.mid");	// ���J�s��2���n��ntut.mid
	//
	// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
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
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
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
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
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

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	//eraser.SetMovingLeft(true);

	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	//eraser.SetMovingLeft(false);
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	// �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��

}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	//eraser.SetMovingRight(true);

}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	//eraser.SetMovingRight(false);

}

void CGameStateRun::OnShow()
{
	//
	//  �`�N�GShow�̭��d�U���n���ʥ��󪫥󪺮y�СA���ʮy�Ъ��u�@����Move���~��A
	//        �_�h��������sø�Ϯ�(OnDraw)�A����N�|���ʡA�ݰ_�ӷ|�ܩǡC���ӳN�y
	//        ���AMove�t�dMVC����Model�AShow�t�dView�A��View�������Model�C

	
	//level2.ShowBitmap();
	//level3.ShowBitmap();
	//level4.ShowBitmap();
	//player.ShowBitmap();
	/*
	level1.ShowBitmap();			// �K�W�I����
	monster1.OnShow();
	monster2.OnShow();
	monster3.OnShow();
	p1.OnShow();*/
	//  �K�W���W�Υk�U��������
	//
	//corner.SetTopLeft(0,0);
	//corner.ShowBitmap();
	//corner.SetTopLeft(SIZE_X-corner.Width(), SIZE_Y-corner.Height());
	//corner.ShowBitmap();
	//p1.OnShow();
	if (selectleve == 1) {
		level1.ShowBitmap();			// �K�W�I����
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
// �o��class���C�����������A(Game Over)
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
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
//	ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	//Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �̲׶i�׬�100%
	//
	//ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	/*
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
	fp=pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC*/
}




}
