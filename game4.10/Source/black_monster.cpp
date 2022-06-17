#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "black_monster.h"

namespace  game_framework {
	black_monster::black_monster() {
		m_x = 725;
		m_y = 334;
		m_s = 1;
		direction = FALSE;
	}

	void black_monster::OnInit(int x, int y, int s) {

		texture.AddBitmap(IDB_M3_R1, RGB(255, 255, 255));
		texture.AddBitmap(IDB_M3_RJUMP, RGB(255, 255, 255));
		texture.SetDelayCount(10);
		texture2.AddBitmap(IDB_M3_1, RGB(255, 255, 255));
		texture2.AddBitmap(IDB_M3_JUMP, RGB(255, 255, 255));
		texture.SetDelayCount(10);
		m_over.AddBitmap(IDB_M3_OVER, RGB(255, 255, 255));
		m_x = x;
		m_y = y;
		m_s = s;


	}
	void black_monster::OnMove() {
		if (!direction) {
			goright();
		}
		else
		{
			goleft();
		}
		if (m_s == 1) {
			if (m_x > 240 || m_x < 50) {
				direction = !direction;
			}
		}
		else if (m_s == 2) {
			if (m_x > 980 || m_x < 810) {
				direction = !direction;
			}
		}
	

		texture.SetTopLeft(m_x, m_y);
		texture.OnMove();
		texture2.SetTopLeft(m_x, m_y);
		texture2.OnMove();
		m_over.SetTopLeft(m_x, m_y);
		m_over.OnMove();
	}
	void black_monster::OnShow() {
		if (!isover) {


			if (!direction) {
				texture.OnShow();
			}
			else {
				texture2.OnShow();
			}
		}
		else {
			m_over.OnShow();
		}

	}
	void black_monster::goleft() {
		m_x -= 5;

	}
	void black_monster::goright() {
		m_x += 5;

	}
	void black_monster::over() {
		isover = true;
	}


}