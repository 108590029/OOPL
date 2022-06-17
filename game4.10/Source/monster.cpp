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
		m_s = 1;
		direction = FALSE;
	}

	void monster::OnInit(int x ,int y ,int s) {

		texture.AddBitmap(IDB_M1_1, RGB(255, 255, 255));
		texture.AddBitmap(IDB_M1_2, RGB(255, 255, 255));
		texture.AddBitmap(IDB_M1_3, RGB(255, 255, 255));
		texture.SetDelayCount(10);
		texture2.AddBitmap(IDB_M1_1, RGB(255, 255, 255));
		texture2.AddBitmap(IDB_M1_L2, RGB(255, 255, 255));
		texture2.AddBitmap(IDB_M1_L3, RGB(255, 255, 255));
		texture.SetDelayCount(10);
		m_over.AddBitmap(IDB_M1_OVER, RGB(255, 255, 255));


		m_x = x;
		m_y = y;
		m_s = s;

			
	}
	void monster::OnMove() {
		if (!direction) {
			goright();
		}
		else
		{
			goleft();
		}
		if (m_s == 1) {
			if (m_x > 950 || m_x < 10) {
				direction = !direction;
			}
		}
		else if (m_s == 2) {
			if (m_x > 1000 || m_x < 720) {
				direction = !direction;
			}
		}
		else if (m_s == 3) {
			if (m_x > 350 || m_x < 70) {
				direction = !direction;
			}
		}
		else if (m_s == 4) {
			if (m_x > 950 || m_x < 680) {
				direction = !direction;
			}
		}
		else if (m_s == 5) {
			if (m_x > 790 || m_x < 530) {
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
	void monster::OnShow(){
		if(!isover){
			if (!isdie) {

				if (!direction) {
					texture.OnShow();
				}
				else {
					texture2.OnShow();
				}
			}
			else {
				m_over.OnShow();
				
				isover = true;
			}
		}
		

	}
	void monster::goleft() {
		m_x -= 2;


	}
	void monster::goright() {
		m_x += 2;

	}
	void monster::over() {
		isover = true;
	}
	void monster::die() {
		isdie = true;
		
	}
}