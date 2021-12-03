#include <iostream>
#include <map>
#include "player.h"
using namespace std;

void hud(player& p){
	cout << "\n" << p.name << ": [" << "LVL " << p.level  << " | EXP " << p.experience << " | HLH " << p.health << " | STA " << p.stamina << " | DMG " << p.damage << " | DEF " << p.defense << " | C " << p.credits << "]";
}

void levelup(player& p){
	static const int rqexp[] = {0, 5, 10, 15, 20, 25, 30, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 180, 200, 250, 300, 350, 400, 450, 500, 600, 700, 800, 900, 1000};
	while(p.experience >= rqexp[p.level]){
		p.level = p.level + 1;
		p.health = p.health + 5;
		p.stamina = p.stamina + 5;
		p.damage = p.damage + 3;
		p.defense = p.defense + 3;
	}
}

void combat(player& p){
	string enemy = "imp";
	int rcombat = rand() % 3;
	int low = ((p.damage + p.defense) - 5);
	int high = ((p.damage + p.defense) + 5);
	int enemy_dmg = rand() % high + low;

	if (rcombat == 0){
		enemy = "bandit";
	}
	else if (rcombat == 1){
		enemy = "demon";
	}
	else if (rcombat == 2){
		enemy = "wild boar";
	}

	cout << "\na " << enemy << " appears.\n";

	if (enemy_dmg > p.defense){
		p.health = (p.health - enemy_dmg);
		cout << "the " << enemy << " wins the fight. you lose " << enemy_dmg << " HLH.\n";
		int lossxp = enemy_dmg / 2;
		p.experience = p.experience + lossxp;
		cout << "you gain " << lossxp << " EXP.";
		levelup(p);
		if (p.health <= 0){
			cout << "\nyou die.";
			p.alive = false;
		}
	}
	else{
		cout << "you win the fight.\n";
		int winxp = enemy_dmg;
		p.experience = p.experience + winxp;
		cout << "you gain " << winxp << " EXP.";
		levelup(p);
	}
}

void eat(player& p){
	if (p.inventory["MUSHROOM SOUP"] > 0){
		int bowls = 0;
		cout << "MUSHROOM SOUP: " << p.inventory["MUSHROOM SOUP"];
		cout << "\nhow many bowls of mushroom soup would you like to eat?";
		cin >> bowls;
		p.inventory["MUSHROOM SOUP"] = p.inventory["MUSHROOM SOUP"] - bowls;
		p.health = p.health + (bowls * 2);
		cout << "\nyou ate " << bowls << " bowls of mushroom soup and now have" << p.health << " HLH.";
	}
	else{
		cout << "\nyou don't have any food.";
	}
}

void cook(player& p){
	if ((p.inventory["MUSHROOMS"] > 0) && p.inventory["WATER"] > 0){
		cout << "MUSHROOMS: " << p.inventory["MUSHROOMS"];
		cout << "\nWATER: " << p.inventory["WATER"];
		int bowls = 0;
		cout << "\nhow many bowls of mushroom soup would you like to make?\n";
		cin >> bowls;
		p.inventory["MUSHROOMS"] = p.inventory["MUSHROOMS"] - bowls;
		p.inventory["WATER"] = p.inventory["WATER"] - bowls;
		p.inventory.insert(pair<string, int>("MUSHROOM SOUP", bowls));
		cout << "\nyou made " << bowls << " bowls of mushroom soup.";
	}
	else{
		cout << "\nyou don't have enough ingredients to cook something.";
	}
}

void explore(player& p){
	string gather;
	int rexplore = rand() % 6;
	if (rexplore == 0){
		cout << "\nyou arrive at the mouth of a deep, dark cave.\n";
		combat(p);
		cout << "\nwould you like to gather some mushrooms? y/n: ";
		cin >> gather;
		if (gather == "y"){
			int rgather = rand() % 5 + 1;
			if (p.inventory["MUSHROOMS"] > 0){
				int newmush = p.inventory["MUSHROOMS"] + rgather;
				p.inventory.insert(pair<string, int>("MUSHROOMS", newmush));
			}
			else{
				p.inventory.insert(pair<string, int>("MUSHROOMS", rgather));
			}
			p.experience = p.experience + rgather;
			cout << "you gathered " << rgather << " mushrooms.";
		};
	}
	else if (rexplore == 1){
		string chop;
		cout << "\nyou arrive at an elegant and lush forest.\n";
		cout << "\nwould you like to chop down some trees? y/n: ";
		cin >> chop;
		if (chop == "y"){
			int rchop = rand() % 50 + 10;
			if (p.inventory["WOOD"] > 0){
				int newchop = p.inventory["WOOD"] + rchop;
				p.inventory.insert(pair<string, int>("WOOD", newchop));
			}
			else{
				p.inventory.insert(pair<string, int>("WOOD", rchop));
			}
			p.experience = p.experience + rchop / 15;
			cout << "you chopped up " << rchop << " bundles of wood.";
		};
	}
	else if (rexplore == 2){
		cout << "\nyou arrive at a sulphorous and disgusting swamp.\n";
		combat(p);
	}
	else if (rexplore == 3){
		string mine;
		cout << "\nyou arrive at the foot of a beautiful and breathtaking mountain.\n";
		cout << "\nwould you like to mine some ore? y/n: ";
		cin >> mine;
		if (mine == "y"){
			int rmine = rand() % 50 + 10;
			if (p.inventory["ORE"] > 0){
				int newmine = p.inventory["ORE"] + rmine;
				p.inventory.insert(pair<string, int>("ORE", newmine));
			}
			else{
				p.inventory.insert(pair<string, int>("ORE", rmine));
			}
			p.experience = p.experience + rmine / 20;
			cout << "you mined " << rmine << " ore.";
		};
	}
	else if (rexplore == 4){
		string water;
		cout << "\nyou arrive at an inviting cobalt lake.\n";
		cout << "\nwould you like to collect some water? y/n: ";
		cin >> water;
		if (water == "y"){
			if (p.inventory["WATER"] > 0){
				int newwater = p.inventory["WATER"] + 10;
				p.inventory.insert(pair<string, int>("WATER", newwater));
			}
			else{
				p.inventory.insert(pair<string, int>("WATER", 10));
			}
			p.experience = p.experience + 5;
			cout << "you collected 10 water.";
		};
	}
	else if (rexplore == 5){
		cout << "\nyou arrive at an inconspicuously empty field.\n";
		combat(p);
	}
}

int main(){
	player p("null", true, 1, 0, 10, 10, 1, 1, 0);

	int action = 0;

	cout << "what is your name?\n";
	cin >> p.name;

	while (action != 5 && p.alive == true){
		hud(p);
		cout << "\nwhat would you like to do?\n" << "\n1. explore" << "\n2. check inventory" << "\n3. cook" << "\n4. eat" << "\n5. quit\n";
		cin >> action;
		if (action == 1){
			explore(p);
		}
		else if (action == 2){
			p.displayInventory();
		}
		else if (action == 3){
			cook(p);
		}
		else if (action == 4){
			eat(p);
		}
	};
	return 0;
}
