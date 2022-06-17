#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "player1.h"

namespace  game_framework {

	player1::player1() {

		//x = 10;
		//y = 385;
		direction = FALSE;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}


	void player1::OnInit(int a){
		select = a;
		player_o.AddBitmap(IDB_PLAYER, RGB(255, 255, 255));
		player_Left.AddBitmap(IDB_PLAYER_LEFT, RGB(255, 255, 255));
		player_Right.AddBitmap(IDB_PLAYER_RIGHT, RGB(255, 255, 255));
		player_Up.AddBitmap(IDB_PLAYER_UP, RGB(255, 255, 255));
		player_Down.AddBitmap(IDB_PLAYER_DOWN, RGB(255, 255, 255));
		player_Attack_right.AddBitmap(IDB_PLAYER_ATTACK1, RGB(255, 255, 255));
		//sprintf(outx, "a:%d\n", a);
		//OutputDebugString(outx);
		//player_Left.SetTopLeft(x, y);
		//player_Right.SetTopLeft(x, y);
		//player_Up.SetTopLeft(x, y);
		if (a == 1) {
			x = 10;
			y = 385;

		}
		else if(a == 2){
			x = 550;
			y = 560;
		}
		else if (a == 3) {
			x = 680;
			y = 640;
		}
		else if (a == 4) {
			x = 500;
			y = 155;
		}
	}

	int player1::getx() {
		return x;
	}

	int player1::gety() {
		return y;
	}
	void player1::sety(int a) {
		y = a;
	}
	void player1::setx(int a) {
		x = a;
	}
	void player1::OnMove() {
	
		//player_o.OnMove();

		if (isMovingLeft) {
			if (x>10)
				x -= 5;

			player_Left.OnMove();
			
			
			
		}else if (isMovingRight) {

			if (x<1000)
				x += 5;
			player_Right.OnMove();
		}else if (isMovingUp) {			
			y -= 5;
			player_Up.OnMove();

	

			
		}
		else if (isMovingDown) {
			if (select == 1) {
				if (y < 385) {
					y += 5;
				}
					
			}
			else if (select == 2) {
				if (y < 560) {
					y += 5;
				}

			}
			
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
		//sprintf(outx, "x:%d\n", x);
		//sprintf(outy, " y:%d\n", y);
		//OutputDebugString(outx);
		player_Attack_right.SetTopLeft(x, y);
		

		if (isMovingLeft) {
			player_Left.OnShow();
			dir = 1;
		}
		else if (isMovingRight) {
			player_Right.OnShow();
			dir = 2;
		}
		else if (isMovingUp) {
			player_Up.OnShow();
			dir = 0;
		}
		else if (isMovingDown) {
			player_Down.OnShow();
			dir = 0;
		}
		/*else if(isAttack) {
			player_Attack_right.OnShow();
			
		}*/
		else
		{
			if (dir == 1) {
				player_Left.OnShow();
			}
			else if (dir == 2) {
				player_Right.OnShow();
			}
			else {
				player_o.OnShow();
			}
				
		}
		if (isAttack) {
			player_Attack_right.OnShow();

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
	void player1::attack(bool flag) {
		isAttack = flag;
		

	}

}