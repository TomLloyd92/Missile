#include <iostream>
#include <ctime>
#include <string.h>

//Functions
void intro();
void warHeadSelect();
void missileChecker();
void targetGenerator();
void targetGenerator();
void launchCodeInputChecker();
void collisionDetection();

//ALL CODES
int explosive = 666;
int nuclearArm = 123;
int userCode = 0;

//Bomb Selector
int chosen = 0;

//Target
int targetVerticle = 0;
int targetHorizontal = 0;


typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << std::endl;
	}

}Coordinates;

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy {
	Coordinates coordinates;
}Target;

struct Missile {
	WarHead payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update() {
		coordinates.x += 1;
		coordinates.y += 2;

	}
};

	//Creat Missile Object
	Missile missile;

int main()
{
	float timer = 0;

	//Introducing Game
	intro();

	//Select Warhead
	warHeadSelect();

	//Update Missile Select
	missileChecker();

	//Target Generator
	targetGenerator();

	//Launch Code Entry and Checker
	launchCodeInputChecker();

	//Collision Checker
	collisionDetection();

	system("Pause");

	return 0;
}

void intro()
{
	//Intro
	std::cout << "M I S S I L E  C O M A N D" << std::endl;
	std::cout << "Hit the target with your missile" << std::endl;
	std::cout << "!WARNING!" << std::endl;
	std::cout << "NUKE CODE: 666" << std::endl;
	std::cout << "EXPLOSSIVE CODE: 123" << std::endl;

	system("pause");
	system("cls");

}

void warHeadSelect()
{
	std::cout << "Select you weapon" << std::endl;
	std::cout << "PRESS 1 FOR: NUCLEAR" << std::endl;
	std::cout << "PRESS 2 FOR: EXPLOSIVE" << std::endl;
	std::cin >> chosen;
}

void missileChecker()
{
	if (chosen == 1)
	{
		missile.payload = NUCLEAR;
		std::cout << "Nuclear missile selected" << std::endl;

	}
	else if (chosen == 2)
	{
		missile.payload = EXPLOSIVE;
		std::cout << "Explosive missile selected " << std::endl;
	}

	system("cls");
}

void targetGenerator()
{
	srand((unsigned)time(0));
	
	// How many KM North is the target?
	targetVerticle = (rand() % 30) - 14;
	std::cout << "VERTICLE:" << targetVerticle << " km from current location" << std::endl;

	// East
	targetHorizontal = (rand() % 30) - 14;
	std::cout << "HORIZONTAL: " << targetHorizontal << " km from current location" << std::endl;

	system("pause");
	system("cls");

}

void launchCodeInputChecker()
{
	std::cout << "LAUNCH CODE REQUIRED: " << std::endl;
	std::cin >> userCode;

	if (userCode == explosive && chosen == 1 || userCode == nuclearArm && chosen == 2)
	{
		std::cout << "ACCESS GRANTED!" << std::endl;
	}
	else
	{
		std::cout << "ACCESS DENIED! INTRUDER ALERT!" << std::endl;
	}

	system("PAUSE");
}

void collisionDetection()
{
	int missileVerticle = 0;
	missileVerticle = (rand() % 30) - 14;
	int missileHorizontal = 0;
	missileHorizontal = (rand() % 30) - 14;

	while (missileVerticle != targetVerticle && missileHorizontal != targetHorizontal)
	{
		int fireAgain;
		missileVerticle = (rand() % 15) + 1;
		missileHorizontal = (rand() % 15) + 1;
		std::cout << "MISS! Reload and fire again." << std::endl;
		std::cout << "Press 1 to try again. Press 0 to quit: " << std::endl;
		std::cin >> fireAgain;
		if (fireAgain == 0)
		{
			std::cout << "LAUNCH ABORTED" << std::endl;
			break;
		}

	}

	if (missileVerticle == targetVerticle && missileHorizontal == targetHorizontal)
	{
		std::cout << "TARGET DESTROYED. GREAT JOB TEAM. GET READ FOR THE NEXT FIGHT" << std::endl;
	}

	system("pause");
}