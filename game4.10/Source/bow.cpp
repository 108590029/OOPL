#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "bow.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CBall: Ball class
	/////////////////////////////////////////////////////////////////////////////

	bow::bow()
	{
		is_alive = false;
		x = 50;
		y = 370;
	}

	

	bool bow::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = x + dx;				// �y�����W��x�y��
		int y1 = y + dy;				// �y�����W��y�y��
		int x2 = x1 + bmp.Width();	// �y���k�U��x�y��
		int y2 = y1 + bmp.Height();	// �y���k�U��y�y��
									//
									// �˴��y���x�λP�ѼƯx�άO�_���涰
									//
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	bool bow::IsAlive()
	{
		return is_alive;
	}

	void bow::LoadBitmap()
	{
		bmp.LoadBitmap(IDB_BOWR, RGB(255, 255, 255));			// ���J�y���ϧ�
		
	}

	void bow::OnMove()
	{
		if (!is_alive)
			return;

		
			if (x < 950 && y<487) {
				x += 10;
				y += 1;
			
			}
		
	}

	void bow::SetDelay(int d)
	{
		delay = d;
	}

	void bow::SetIsAlive(bool alive)
	{
		is_alive = alive;
	}

	void bow::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void bow::OnShow()
	{
		if (is_alive) {
			bmp.SetTopLeft(x, y);
			bmp.ShowBitmap();

		}
	}
}