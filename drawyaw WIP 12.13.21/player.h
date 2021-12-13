#include <iostream>
#include <map>
using namespace std;

class player {
	public:
		string name;
		bool alive;
		int level;
		int experience;
		int health;
		int defense;
		int credits;
		map<string, int> inventory;
		map<string, int> displayInventory();
		player(string n, bool a, int lvl, int exp, int hlh, int def, int c){
			name = n;
			alive = a;
			level = lvl;
			experience = exp;
			health = hlh;
			defense = def;
			credits = c;
		}
};
