#include <./include/Player.h>
#include <./include/NPC.h>

class Game
{
	public:
		Game();
		void run();
	private:
		void initialize();
		void update();
		void draw();
		GameObject* player;
		GameObject* npc;
		GameObject* npc2;
		GameObject* npc3;
};