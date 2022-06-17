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
		int x1 = x + dx;				// 球的左上角x座標
		int y1 = y + dy;				// 球的左上角y座標
		int x2 = x1 + bmp.Width();	// 球的右下角x座標
		int y2 = y1 + bmp.Height();	// 球的右下角y座標
									//
									// 檢測球的矩形與參數矩形是否有交集
									//
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	bool bow::IsAlive()
	{
		return is_alive;
	}

	void bow::LoadBitmap()
	{
		bmp.LoadBitmap(IDB_BOWR, RGB(255, 255, 255));			// 載入球的圖形
		
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