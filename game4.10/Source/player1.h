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
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����



	};


}

#endif