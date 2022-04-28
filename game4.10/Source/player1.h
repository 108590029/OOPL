#pragma once
#ifndef _player1_H_
#define player1_H_



namespace game_framework {
	class player1
	{
	public:
		player1();

		//~monster();
		void goLeft(bool flag);
		void goRight(bool flag);
		void goUp(bool flag);
		void goDown(bool flag);
		void OnInit();
		void OnMove();
		void OnShow();
		void xy(int a);


	private:
		int x;
		int y;
		int select;
		CAnimation player_o;
		CAnimation player_Left;
		CAnimation player_Right;
		CAnimation player_Up;
		CAnimation player_Down;
		CAnimation player_Attack;
		char outx[4];
		char outy[4];

		CMovingBitmap p;
		bool direction;
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動



	};


}

#endif