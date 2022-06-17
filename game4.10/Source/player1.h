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
		void OnInit(int a);
		void OnMove();
		void OnShow();
		int getx();
		int gety();
		void setx(int a);
		void sety(int a);
		void attack(bool flag);
		int x;
		int y;
		int dir;
	

	private:
		
		int select;
		CAnimation player_o;
		CAnimation player_Left;
		CAnimation player_Right;
		CAnimation player_Up;
		CAnimation player_Down;
		CAnimation player_Attack_left;
		CAnimation player_Attack_right;
		char outx[4];
		char outy[4];

		CMovingBitmap p;
		bool direction;
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isAttack;


	};


}

#endif