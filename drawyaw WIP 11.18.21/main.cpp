#include <iostream>
#include <map>
#include "player.h"
using namespace std;

void hud(player p){
	cout << "\n" << p.name << ": [" << "LVL " << p.level  << " | EXP " << p.experience << " | HLH " << p.health << " | STA " << p.stamina << " | DMG " << p.damage << " | DEF " << p.defense << " | C " << p.credits << "]";
}

int combat(player p){
	string enemy = "imp";
	int rc = rand() % 3;
	int low = ((p.damage + p.defense) / 2);
	int high = ((p.damage + p.defense) * 2);
	int enemy_dmg = rand() % high + low;

	if (rc == 0){
		enemy = "bandit";
	}
	else if (rc == 1){
		enemy = "demon";
	}
	else if (rc == 2){
		enemy = "wild boar";
	}

	cout << "a " << enemy << " appears.\n";

	if (enemy_dmg > p.defense){
		p.health = p.health - enemy_dmg;
		cout << "the " << enemy << " wins. you lose " << enemy_dmg << " HLH.";
	}
	else{
		cout << "you win.";
	}

	return(p.health);
}

void explore(player p){
	int re = rand() % 6;
	if (re == 0){
		cout << "\nyou arrive at the mouth of a deep, dark cave.\n";
		combat(p);
	}
	else if (re == 1){
		cout << "\nyou arrive at an elegant and lush forest.\n";
	}
	else if (re == 2){
		cout << "\nyou arrive at a sulphorous and disgusting swamp.\n";
		combat(p);
	}
	else if (re == 3){
		cout << "\nyou arrive at the foot of a beautiful and breathtaking mountain.\n";
	}
	else if (re == 4){
		cout << "\nyou arrive at an inviting cobalt lake.\n";
	}
	else if (re == 5){
		cout << "\nyou arrive at an inconspicuously empty field.\n";
		combat(p);
	}
}

int main(){
	player p("null", 1, 0, 10, 10, 1, 1, 0);
	int action = 0;

	cout << "what is your name?\n";
	cin >> p.name;

	while (action != 2){
		hud(p);
		cout << "\nwhat would you like to do?\n" << "\n1. explore" << "\n2. quit\n";
		cin >> action;
		if (action == 1){
			explore(p);
		}
	};
	return 0;
}
