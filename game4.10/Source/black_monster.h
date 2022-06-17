#pragma once
#pragma once
#ifndef _black_monster_H_
#define _black_monster_H_



namespace game_framework {
	class black_monster
	{
	public:
		black_monster();
		//~black_monster();
		void goleft();
		void goright();
		void OnInit(int x, int y, int s);
		void OnMove();
		void OnShow();
		void over();
		int m_x;
		int m_y;
		int m_s;

	private:
		
		CAnimation texture;
		CAnimation m_over;
		CAnimation texture2;
		bool direction;
		bool isover = false;


	};


}

#endif