// Missile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>



int main()
{
	struct Missile {

		WarHead Payload;

		Coordiantes coordiantes;

		Target target;

		void arm()
		{
			if (armed)
				armed = false;
			else
				armed = true;
		}
		void Update()
		{
			coordiantes.x += 1;
			coordiantes.y += 1;
		}
	};

	typedef struct Position
	{
		int x;
		int y;

		void print()
		{
			std::cout << x << y << std::endl;
		}
	} coordiantes;

	enum WarHead {Explosives, Nuclear};

	typedef struct Enemy {
		Coordiantes coordiantes;
	}Target;

    return 0;
}

