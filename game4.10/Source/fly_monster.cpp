#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "fly_monster.h"

namespace  game_framework {
	fly_monster::fly_monster() {
		m_x = 725;
		m_y = 334;
		m_s = 1;
		direction = FALSE;
	}

	void fly_monster::OnInit(int x ,int y ,int s) {

		texture.AddBitmap(IDB_M2_1, RGB(255, 255, 255));
		texture.AddBitmap(IDB_M2_2, RGB(255, 255, 255));
		texture.SetDelayCount(10);
		texture2.AddBitmap(IDB_M2_L1, RGB(255, 255, 255));
		texture2.AddBitmap(IDB_M2_L2, RGB(255, 255, 255));
		texture.SetDelayCount(10);
		m_over.AddBitmap(IDB_M2_OVER, RGB(255, 255, 255));
		m_x = x;
		m_y = y;
		m_s = s;

			
	}
	void fly_monster::OnMove() {
		if (!direction) {
			goright();
		}
		else
		{
			goleft();
		}
		if (m_s == 1) {
			if (m_x > 1000 || m_x < 700) {
				direction = !direction;
			}
		}
		else if (m_s == 2) {
			if (m_x > 960 || m_x < 585) {
				direction = !direction;
			}
		}
		else if (m_s == 3) {
			if (m_x > 1000 || m_x < 700) {
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
	void fly_monster::OnShow() {
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
	void fly_monster::goleft() {
		m_x -= 3;

	}
	void fly_monster::goright() {
		m_x += 3;

	}
	void fly_monster::over() {
		isover = true;

	}


}