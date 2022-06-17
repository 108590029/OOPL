
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "monster.h"
#include "player1.h"
#include "fly_monster.h"
#include "black_monster.h"
#include "bow.h"


int selectleve = 0;
bool cm,getscore=false;
int bown = 0, blood = 0, totalscore = 0;
int score[4] = {0};


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
	
	CAudio::Instance()->Load(AUDIO_MENU, "sounds\\menu.mp3");
	CAudio::Instance()->Load(AUDIO_BGM, "sounds\\game.mp3");
	CAudio::Instance()->Load(AUDIO_ATC, "sounds\\Attack_1.mp3");
	CAudio::Instance()->Load(AUDIO_ATC_2, "sounds\\Attack_2.mp3");
	CAudio::Instance()->Load(AUDIO_JUMP, "sounds\\jump.mp3");
	logo.LoadBitmap(IDB_ST);
	selectL.LoadBitmap(IDB_SELECT);
	cm = FALSE;
	CAudio::Instance()->Play(AUDIO_MENU, true);


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
		else {
			cm = false;
		}	
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
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, *fp;
		f.CreatePointFont(100, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->TextOut(20, 0, "�x�_��ޤj�� ����ɦV�{���]�p�ҵ{");
		pDC->TextOut(40, 30, "�@�̡G���Y�B");
		pDC->TextOut(40, 60, "�½ұЮv�G���Ӻ~");
		pDC->TextOut(40, 400, "�C�����k");
		pDC->TextOut(60, 430, "�W�U���k���a����");
		pDC->TextOut(60, 460, " SPACE�i�H�o�g�}�b�����Ǫ�");
		pDC->TextOut(60, 490, "�����Ҧ��Ǫ��Y�i�L��");
		pDC->TextOut(60, 520, "ENTER�i�H�����q��");
		
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}
}								



/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
	: CGameState(g) ,NUMBOW(50)
{
	bowa = new bow[NUMBOW];
}

CGameStateRun::~CGameStateRun()
{
	
	delete[] bowa;
}

void CGameStateRun::OnBeginState()
{

	CAudio::Instance()->Stop(AUDIO_MENU);
	CAudio::Instance()->Play(AUDIO_BGM, true);

}

void CGameStateRun::OnMove()							// ���ʹC������
{
		monster1_1.OnMove();
		monster1_2.OnMove();
		monster1_3.OnMove();
		monster2_1.OnMove();
		monster2_2.OnMove();
		monster3_1.OnMove();
		monster4_1.OnMove();
		fly_monster2_1.OnMove();
		fly_monster4_1.OnMove();
		black_monster3_1.OnMove();
		black_monster3_2.OnMove();
		p1.OnMove();
		p2.OnMove();
		p3.OnMove();
		p4.OnMove();

		int i;
		for (i = 0; i < NUMBOW; i++) {
			bowa[i].OnMove();
			if (selectleve == 1) {
				if (bowa[i].IsAlive() && bowa[i].y<465 && bowa[i].x >= monster1_1.m_x - 50 && bowa[i].x <= monster1_1.m_x && !monster1_1.isdie ) {
					monster1_1.die();
					getscore = true;				
				}
				else if (bowa[i].IsAlive() && bowa[i].y < 465 && bowa[i].x >= monster1_2.m_x - 50 && bowa[i].x <= monster1_2.m_x && !monster1_2.isdie ){
					monster1_2.die();
					getscore = true;
				}
				else if (bowa[i].IsAlive() && bowa[i].y < 465 && bowa[i].x >= monster1_3.m_x - 50 && bowa[i].x <= monster1_3.m_x && !monster1_3.isdie) {
					monster1_3.die();	
					getscore = true;
				}
				if (monster1_1.isdie && monster1_2.isdie && monster1_3.isdie) {
					isNext = true;
				}
		
			}
			else if (selectleve == 2) {
				if (bowa[i].IsAlive() && bowa[i].y < 465 && bowa[i].x >= monster2_1.m_x - 50 && bowa[i].x <= monster2_1.m_x && !monster2_1.isdie) {
					monster2_1.die();
					getscore = true;
				}
				else if (bowa[i].IsAlive() && bowa[i].y < 465 && bowa[i].x >= monster2_2.m_x - 50 && bowa[i].x <= monster1_2.m_x && !monster2_2.isdie) {
					monster2_2.die();
					getscore = true;
				}
				
			}
			else if (selectleve == 3) {
				if (bowa[i].IsAlive() && bowa[i].y < 465 && bowa[i].x >= monster3_1.m_x - 50 && bowa[i].x <= monster3_1.m_x && !monster3_1.isdie) {
					monster3_1.die();
					getscore = true;
				}
			}
			else if (selectleve == 4) {
				if (bowa[i].IsAlive() && bowa[i].y < 465 && bowa[i].x >= monster4_1.m_x - 50 && bowa[i].x <= monster4_1.m_x && !monster4_1.isdie) {
					monster4_1.die();
					getscore = true;
				}
			}
		}

		if (getscore) {
			score[selectleve] += 150;
			getscore = false;
		}

		

		

		for (i = 0; i < NUMBOW; i++) {
			if (bowa[i].IsAlive()) {
				if (bowtime != 0) {
					bowtime -= 1;
				}
				else {
					bowa[i].SetIsAlive(false);
					bowtime = 100;
				}


				//CAudio::Instance()->Play(AUDIO_ATC_2);		
			}
		}
		if (selectleve == 1) {
	
			if ((p1.gety()<=385 && p1.gety()>=320) && ((p1.getx() >= monster1_1.m_x-50 && p1.getx() <= monster1_1.m_x && !monster1_1.isdie) || (p1.getx() >= monster1_2.m_x - 50 && p1.getx() <= monster1_2.m_x && !monster1_2.isdie ) || (p1.getx() >= monster1_3.m_x - 50 && p1.getx() <= monster1_3.m_x && !monster1_3.isdie))) {
				if (blood < 3 && time == 0 ) {
					CAudio::Instance()->Play(AUDIO_JUMP, false);		
					p1.setx(p1.getx() - 50);				
					blood += 1;
					time = 20;
					
				}else {
					time -= 1;
				}
				if (blood == 3) {
					GotoGameState(GAME_STATE_OVER);
				}
				

			}
		}
		else if (selectleve == 2) {
			if ( (p2.getx() >= monster2_1.m_x - 50 && p2.getx() <= monster2_1.m_x && !monster2_1.isdie) || (p2.getx() >= monster2_2.m_x - 50 && p2.getx() <= monster2_2.m_x && !monster2_2.isdie)) {
				if (blood < 3 && time == 0) {
					CAudio::Instance()->Play(AUDIO_JUMP, false);
					p2.setx(p2.getx() - 50);
					blood += 1;
					time = 20;

				}
				else {
					time -= 1;
				}
				if (blood == 3) {
					GotoGameState(GAME_STATE_OVER);
				}


			}
		}
		else if (selectleve == 3) {
			if (p3.getx() >= monster3_1.m_x - 50 && p3.getx() <= monster3_1.m_x && !monster3_1.isdie){
				if (blood < 3 && time == 0) {
					CAudio::Instance()->Play(AUDIO_JUMP, false);
					p3.setx(p3.getx() - 50);
					blood += 1;
					time = 50;

				}
				else {
					time -= 1;
				}
				if (blood == 3) {
					GotoGameState(GAME_STATE_OVER);
				}


			}
		}
		else if (selectleve == 4) {
			if (p4.getx() >= monster4_1.m_x - 50 && p4.getx() <= monster4_1.m_x && !monster4_1.isdie) {
				if (blood < 3 && time == 0) {
					CAudio::Instance()->Play(AUDIO_JUMP, false);
					p4.setx(p4.getx() - 50);
					blood += 1;
					time = 20;

				}
				else {
					time -= 1;
				}
				if (blood == 3) {
					GotoGameState(GAME_STATE_OVER);
				}


			}
		}
	

}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	
	
	level1.LoadBitmap(IDB_LE1);
	level2.LoadBitmap(IDB_LE2);
	level3.LoadBitmap(IDB_LE3);
	level4.LoadBitmap(IDB_LE4);
	continueNext.LoadBitmap(IDB_SCORE);
	pause.LoadBitmapA(IDB_PAUSE);
	//background1.LoadBitmap(IDB_SELECT);
	//player.LoadBitmapA(IDB_PLAYER,RGB(255,255,255));
	blood1.LoadBitmapA(IDB_BLOOD,RGB(255,255,255));
	blood2.LoadBitmapA(IDB_BLOOD, RGB(255, 255, 255));
	blood3.LoadBitmapA(IDB_BLOOD, RGB(255, 255, 255));
	monster1_1.OnInit(100, 395,1);
	monster1_2.OnInit(250, 395,1);
	monster1_3.OnInit(400, 395,1);
	monster2_1.OnInit(723, 572, 2);
	monster2_2.OnInit(340, 240, 3);

	monster3_1.OnInit(700, 265, 4);
	monster4_1.OnInit(680, 155, 5);

	fly_monster2_1.OnInit(700, 334,1);
	fly_monster4_1.OnInit(590,-8,2);

	black_monster3_1.OnInit(190, 265, 1);
	black_monster3_2.OnInit(830, 460, 2);


	int i = 0;
	for (i = 0; i < NUMBOW; i++) {
		bowa[i].LoadBitmap();
	}












	p1.OnInit(1);
	p2.OnInit(2);
	p3.OnInit(3);
	p4.OnInit(4);
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
;
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y ox1B
	const char KEY_ENTER = 0x0D;
	const char KEY_SPACE = 0X20;
	const char KEY_ESC= 0X1B;

	
	
	if (nChar == KEY_ENTER) {
		
		score[selectleve] = 450;
		selectleve += 1;
		isNext = true;
		GotoGameState(GAME_STATE_RUN);
	}
	if (nChar == KEY_ESC) {
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
	}
	if (selectleve == 1){
		if (nChar == KEY_SPACE) {
			p1.attack(true);
			//
			int i;
			for (i = bown; i <= bown+1; i++) {
				bowa[i].SetXY(p1.getx(), p1.gety()+55);
				bowa[i].SetIsAlive(true);		
			}
			bown += 1;

			CAudio::Instance()->Play(AUDIO_ATC, false);
			//monster1_1.die();
		}
		if (nChar == KEY_LEFT) {
			p1.goLeft(true);

		}

		if (nChar == KEY_RIGHT) {
			p1.goRight(true);
		}

		if (nChar == KEY_UP) {
			p1.goUp(true);
			
		}

		if (nChar == KEY_DOWN) {
			p1.goDown(true);
		}
		if (nChar == KEY_SPACE) {
			p1.attack(true);
		}
	}
	else if (selectleve == 2) {

		if (nChar == KEY_SPACE) {
			p2.attack(true);
			//
			int i;
			for (i = bown; i <= bown + 1; i++) {
				bowa[i].SetXY(p2.getx(), p2.gety() + 55);
				bowa[i].SetIsAlive(true);
			}
			bown += 1;

			CAudio::Instance()->Play(AUDIO_ATC, false);
			//monster1_1.die();
		}

	
		if (nChar == KEY_LEFT) {
			p2.goLeft(true);
		}

		if (nChar == KEY_RIGHT) {
			p2.goRight(true);
		}

		if (nChar == KEY_UP) {
			p2.goUp(true);
		}

		if (nChar == KEY_DOWN) {
			p2.goDown(true);
		}
	}
	else if (selectleve == 3) {
		if (nChar == KEY_SPACE) {
			p3.attack(true);
			//
			int i;
			for (i = bown; i <= bown + 1; i++) {
				bowa[i].SetXY(p3.getx(), p3.gety() + 55);
				bowa[i].SetIsAlive(true);
			}
			bown += 1;

			CAudio::Instance()->Play(AUDIO_ATC, false);
			//monster1_1.die();
		}

		if (nChar == KEY_LEFT) {
			p3.goLeft(true);
		}

		if (nChar == KEY_RIGHT) {
			p3.goRight(true);
		}

		if (nChar == KEY_UP) {
			p3.goUp(true);
		}

		if (nChar == KEY_DOWN) {
			p3.goDown(true);
		}
	}
	else if (selectleve == 4) {
		if (nChar == KEY_SPACE) {
			p4.attack(true);
			//
			int i;
			for (i = bown; i <= bown + 1; i++) {
				bowa[i].SetXY(p4.getx(), p4.gety() + 55);
				bowa[i].SetIsAlive(true);
			}
			bown += 1;

			CAudio::Instance()->Play(AUDIO_ATC, false);
			//monster1_1.die();
		}

		if (nChar == KEY_LEFT) {
			p4.goLeft(true);
		}

		if (nChar == KEY_RIGHT) {
			p4.goRight(true);
		}

		if (nChar == KEY_UP) {
			p4.goUp(true);
		}

		if (nChar == KEY_DOWN) {
			p4.goDown(true);
		}
	}

		
	
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
	const char KEY_SPACE = 0X20;

	
	if (selectleve == 1) {
		if (nChar == KEY_SPACE) {
			p1.attack(false);
		}
		if (nChar == KEY_LEFT) {
			p1.goLeft(false);
		}
		if (nChar == KEY_RIGHT) {
			p1.goRight(false);
		}

		if (nChar == KEY_UP) {
			p1.goUp(false);
		}
		if (nChar == KEY_DOWN) {
			p1.goDown(false);
		}
	}
	else if (selectleve == 2) {
		if (nChar == KEY_SPACE) {
			p2.attack(false);
		}
		if (nChar == KEY_LEFT) {;
			p2.goLeft(false);
		}

		if (nChar == KEY_RIGHT) {
			p2.goRight(false);
		}

		if (nChar == KEY_UP) {
			p2.goUp(false);
		}
		if (nChar == KEY_DOWN) {
			p2.goDown(false);
		}
	}
	else if (selectleve == 3) {
		if (nChar == KEY_SPACE) {
			p3.attack(false);
		}
		if (nChar == KEY_LEFT) {
			p3.goLeft(false);
		}
		if (nChar == KEY_RIGHT) {
			p3.goRight(false);
		}
		if (nChar == KEY_UP) {
			p3.goUp(false);
		}
		if (nChar == KEY_DOWN) {
			p3.goDown(false);
		}
	}
	else if (selectleve == 4) {
		if (nChar == KEY_SPACE) {
			p4.attack(false);
		}
		if (nChar == KEY_LEFT) {
			p4.goLeft(false);
		}

		if (nChar == KEY_RIGHT) {
			p4.goRight(false);
		}

		if (nChar == KEY_UP) {
			p4.goUp(false);
		}
		if (nChar == KEY_DOWN) {
			p4.goDown(false);
		}
	}


		
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	//
	sprintf(outx, "x:%d\n", point.x);
	sprintf(outy, " y:%d\n", point.y);
	OutputDebugString(outx);
	//eraser.SetMovingLeft(true);

	if (point.x >= 900 && point.y >= 10 && point.x <= 1040 && point.y
		<= 50) {
		stop_game = true;
		
	}
	if (point.x >= 375 && point.y >= 375 && point.x <= 735 && point.y
		<= 433) {
		stop_game = false;

	}
	if (point.x >= 375 && point.y >= 458 && point.x <= 735 && point.y
		<= 515 && stop_game) {
		leave_game = true;
	}

	if (point.x >= 378 && point.y >= 431 && point.x <= 738 && point.y
		<= 486) {
		isNext = false;
		GotoGameState(GAME_STATE_RUN);

	}
	if (point.x >= 378 && point.y >= 515 && point.x <= 738 && point.y
		<= 568 && isNext) {
		leave_game = true;
	}




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

	if (leave_game) {
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
	}
	if (isNext) {

		continueNext.ShowBitmap();
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, *fp;
		f.CreatePointFont(100, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);			// ��� font f
		pDC->SetBkColor(RGB(255, 255, 255));
		pDC->SetTextColor(RGB(116, 50, 154));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, " %d", score[selectleve-1]);
		pDC->TextOut(650, 320, str);
		sprintf(str, " %d", score[1] + score[2] + score[3] + score[4]);
		pDC->TextOut(650, 365, str);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();
		if (stop_game) {
			isNext = false;
		}
		
		

	}
	else if (stop_game) {
		pause.ShowBitmap();
		
	}
	else if (selectleve == 1) {
		
		level1.ShowBitmap();			// �K�W�I����
		monster1_1.OnShow();
		monster1_2.OnShow();
		monster1_3.OnShow();
		p1.OnShow();
		int i = 0;
		for (i = 0; i < NUMBOW; i++) {
			bowa[i].OnShow();
		}
		blood1.SetTopLeft(960, 690);
		blood2.SetTopLeft(1015, 690);
		blood3.SetTopLeft(1070, 690);

		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, *fp;
		f.CreatePointFont(100, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);			// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->TextOut(1100, 755, "   ");
		pDC->SetTextColor(RGB(228, 81, 159));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, "%d", score[selectleve]);
		pDC->TextOut(1060, 755, str);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();
	}
	else if (selectleve == 2)
	{
		level2.ShowBitmap();	
		fly_monster2_1.OnShow();
		monster2_1.OnShow();
		monster2_2.OnShow();
		p2.OnShow();
		for (int i = 0; i < NUMBOW; i++) {
			bowa[i].OnShow();
		}
		blood1.SetTopLeft(968, 690);
		blood2.SetTopLeft(1023, 690);
		blood3.SetTopLeft(1078, 690);
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, *fp;
		f.CreatePointFont(100, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);			// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->TextOut(1104, 755, "    ");
		pDC->SetTextColor(RGB(228, 81, 159));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, "%d", score[selectleve]);
		pDC->TextOut(1068, 755, str);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();
	}
	else if (selectleve == 3)
	{
		level3.ShowBitmap();	
		monster3_1.OnShow();
		black_monster3_1.OnShow();
		black_monster3_2.OnShow();
		p3.OnShow();
		for (int i = 0; i < NUMBOW; i++) {
			bowa[i].OnShow();
		}
		blood1.SetTopLeft(920, 690);
		blood2.SetTopLeft(975, 690);
		blood3.SetTopLeft(1030, 690);
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, *fp;
		f.CreatePointFont(100, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);			// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->TextOut(1060, 755, "  ");
		pDC->SetTextColor(RGB(228, 81, 159));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, "%d", score[selectleve]);
		pDC->TextOut(1020, 755, str);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();
	}
	else if (selectleve == 4)
	{
		level4.ShowBitmap();
		monster4_1.OnShow();
		fly_monster4_1.OnShow();
		p4.OnShow();
		for (int i = 0; i < NUMBOW; i++) {
			bowa[i].OnShow();
		}
		blood1.SetTopLeft(918, 690);
		blood2.SetTopLeft(973, 690);
		blood3.SetTopLeft(1028, 690);
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, *fp;
		f.CreatePointFont(100, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);			// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->TextOut(1048, 755, "   ");
		pDC->SetTextColor(RGB(228, 81, 159));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, "%d", score[selectleve]);
		pDC->TextOut(1018, 755, str);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();
	}
	if (!isNext) {
		if (blood == 1) {
			blood1.ShowBitmap();
		}
		else if (blood == 2) {
			blood1.ShowBitmap();
			blood2.ShowBitmap();
		}
		else if (blood == 3) {
			blood1.ShowBitmap();
			blood2.ShowBitmap();
			blood3.ShowBitmap();
		}
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
	
}

void CGameStateOver::OnBeginState()
{

}

void CGameStateOver::OnInit()
{
	over.LoadBitmapA(IDB_GAMEOVER);

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
	over.ShowBitmap();
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f, *fp;
	f.CreatePointFont(100, "Times New Roman");	// ���� font f; 160���16 point���r
	fp = pDC->SelectObject(&f);			// ��� font f
	pDC->SetBkColor(RGB(255, 255, 255));
	pDC->SetTextColor(RGB(116, 50, 154));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, " %d", score[1]+score[2]+score[3]+score[4]);
	pDC->TextOut(598, 290, str);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();
	counter--;
	//if (counter < 0)
		//PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
}




}
