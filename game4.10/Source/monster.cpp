#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "monster.h"

namespace  game_framework {
	monster::monster() {
		m_x = 10;
		m_y = 300;
		direction = FALSE;
	}

	void monster::OnInit(int x ,int y) {

		texture.AddBitmap(IDB_M1_1, RGB(255, 255, 255));
		texture.AddBitmap(IDB_M1_2, RGB(255, 255, 255));
		texture.AddBitmap(IDB_M1_3, RGB(255, 255, 255));
		texture.SetDelayCount(10);
		m_x = x;
		m_y = y;

			
	}
	void monster::OnMove() {
		if (!direction) {
			goright();
		}
		else
		{
			goleft();
		}
		if (m_x > 950 || m_x < 10) {
			direction = !direction;
		}

		texture.SetTopLeft(m_x, m_y);
		texture.OnMove();

	}
	void monster::OnShow() {
		texture.OnShow();

	}
	void monster::goleft() {
		m_x -= 2;


	}
	void monster::goright() {
		m_x += 2;

	}


}