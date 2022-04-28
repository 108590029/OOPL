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
		void OnInit(int x ,int y) ;
		void OnMove();
		void OnShow();
		

	private:
		int m_x;
		int m_y;
		CAnimation texture;
		bool direction;



	};


}

#endif