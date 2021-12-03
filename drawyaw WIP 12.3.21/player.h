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
		int stamina;
		int damage;
		int defense;
		int credits;
		map<string, int> inventory;

		void setname(string n);

		string getname();

		void setalive(bool a);

		bool getalive();

		void setlevel(int lvl);

		int getlevel();

		void setexp(int exp);

		int getexp();

		void sethealth(int hlh);

		int gethealth();

		void setstamina(int sta);

		int getstamina();

		void setdamage(int dmg);

		int getdamage();

		void setdefense(int def);

		int getdefense();

		void setcredits(int c);

		int getcredits();

		void addInventory();

		map<string, int> removeInventory();

		map<string, int> displayInventory();

		player(string n, bool a, int lvl, int exp, int hlh, int sta, int dmg, int def, int c){
			name = n;
			alive = a;
			level = lvl;
			experience = exp;
			health = hlh;
			stamina = sta;
			damage = dmg;
			defense = def;
			credits = c;
		}
};
