#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "player1.h"

namespace  game_framework {

	player1::player1() {

		x = 10;
		y = 385;
		direction = FALSE;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}
	void player1::xy(int a ) {
		select = a;

	}
	void player1::OnInit(){

		player_o.AddBitmap(IDB_PLAYER, RGB(255, 255, 255));
		player_Left.AddBitmap(IDB_PLAYER_LEFT, RGB(255, 255, 255));
		player_Right.AddBitmap(IDB_PLAYER_RIGHT, RGB(255, 255, 255));
		player_Up.AddBitmap(IDB_PLAYER_UP, RGB(255, 255, 255));
		player_Down.AddBitmap(IDB_PLAYER_DOWN, RGB(255, 255, 255));


		player_Left.SetTopLeft(x, y);
		player_Right.SetTopLeft(x, y);
		player_Up.SetTopLeft(x, y);
	}
	void player1::OnMove() {
	
		player_o.OnMove();

		if (isMovingLeft) {
			if (x>10)
				x -= 5;

			player_Left.OnMove();
			
			
			
		}else if (isMovingRight) {
			if (x<960)
				x += 5;
			player_Right.OnMove();
		}else if (isMovingUp) {			
			y -= 5;
			player_Up.OnMove();

			
		}else if (isMovingDown) {
			if (y < 385)
				y += 5;
			player_Down.OnMove();

		}
		else {
			player_Left.Reset();
			player_Right.Reset();
			player_Up.Reset();
			player_Down.Reset();
			player_o.OnMove();

		}

			
	

	}
	void player1::OnShow() {
		player_o.SetTopLeft(x, y);
		player_Left.SetTopLeft(x, y);
		player_Right.SetTopLeft(x, y);
		player_Up.SetTopLeft(x, y);
		player_Down.SetTopLeft(x, y);
		sprintf(outx, " x:%d\n", x);
		sprintf(outy, " y:%d\n", y);
		OutputDebugString(outx);
		


		if (isMovingLeft) {
			player_Left.OnShow();
		}
		else if (isMovingRight) {
			player_Right.OnShow();
		}
		else if (isMovingUp) {
			player_Up.OnShow();
		}
		else if (isMovingDown) {
			player_Down.OnShow();
		}
		else {

			player_o.OnShow();

		}
		

	}
	void player1::goLeft(bool flag) {
		isMovingLeft = flag;
	
	}
	void player1::goRight(bool flag) {
		isMovingRight = flag;

	}
	void player1::goUp(bool flag) {
		isMovingUp = flag;

	}
	void player1::goDown(bool flag) {
		isMovingDown = flag;
	}


}