#include <iostream>
#include <map>
using namespace std;

class player {
	public:
		string name;
		int level;
		int experience;
		int health;
		int stamina;
		int hunger;
		int thirst;
		int damage;
		int defense;
		int credits;

		string getname(){
			return name;
		}

		player(string n, int lvl, int exp, int hlh, int sta, int hun, int thr, int dmg, int def, int c){
			name = n;
			level = lvl;
			experience = exp;
			health = hlh;
			stamina = sta;
			hunger = hun;
			thirst = thr;
			damage = dmg;
			defense = def;
			credits = c;
		}
};



int main(){

	player p("null", 1, 0, 1, 1, 50, 50, 1, 1, 0);

	cout << name << ": " << level;

	return 0;
}
