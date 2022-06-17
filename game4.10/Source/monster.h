#pragma once
#ifndef _monster_H_
#define _monster_H_



namespace game_framework {
	class monster
	{
	public:
		monster();
		//~monster();
		void goleft();
		void goright();
		void OnInit(int x ,int y,int s) ;
		void OnMove();
		void OnShow();
		void over();
		void die();
		bool isdie = false;
		int m_x;
		int m_y;
		int m_s;

	private:

		CAnimation texture;
		CAnimation texture2;
		CAnimation m_over;
		bool direction;
		bool isover = false;
		


	};


}

#endif