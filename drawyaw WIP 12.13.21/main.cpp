#include <iostream>
#include <Windows.h>
#include <map>
#include "player.h"
using namespace std;

void hud(player& p){
	cout << "\n" << flush;
	Sleep(500);
	cout << "\n" << p.name << ": [" << "LVL " << p.level  << " | EXP " << p.experience << " | HLH " << p.health  << " | DEF " << p.defense << " | C " << p.credits << "]";
}

void levelup(player& p){
	static const int rqexp[] = {0, 5, 10, 15, 20, 25, 30, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 180, 200, 250, 300, 350, 400, 450, 500, 600, 700, 800, 900, 1000};
	while(p.experience >= rqexp[p.level]){
		p.level = p.level + 1;
		p.health = p.health + 1;
		p.defense = p.defense + 1;
		cout << flush;
		Sleep(500);
		cout << "\nyou level up. your health and defense increases.";
	}
}

void merchant(player& p){
	cout << flush;
	Sleep(500);
	cout << "\na merchant waves to you quickly." << flush;
	Sleep(500);
	cout << "\ndo you wave back? y/n:\n";
	string wave = "n";
	cin >> wave;
	if (wave == "y"){
		cout << flush;
		Sleep(500);
		cout << "\nINVENTORY:\n" << flush;
		Sleep(500);
		p.displayInventory();
		cout << flush;
		Sleep(500);
		cout << "\nwill you buy something or sell? buy/sell:\n";
		string buysell = "null";
		cin >> buysell;
		if (buysell == "buy"){
			if (p.credits < 5){
				cout << flush;
				Sleep(500);
				cout << "\nthe merchant shakes their head. you don't have enough credits.";
			}
			else{
				cout << flush;
				Sleep(500);
				cout << "\nthe merchant has wares to sell." << flush;
				Sleep(500);
				static const string wares[] = {"\n[MUSHROOMS + 1] (5 credits)", "\n[WATER + 1] (5 credits)"};
				cout << wares[0] << " " << wares[1] << flush;
				Sleep(500);
				cout << "\nyou have " << p.credits << " CREDITS" << flush;
				Sleep(500);
				cout << "\nINVENTORY:\n" << flush;
				Sleep(500);
				p.displayInventory();
				cout << flush;
				Sleep(500);
				cout << "\nwhat would you like to buy?\n";
				string purchase = "null";
				cin >> purchase;
				if (purchase == "mushrooms"){
					cout << flush;
					Sleep(500);
					cout << "\nhow many mushrooms would you like to buy?\n";
					int amount = 0;
					cin >> amount;
					if (amount == 0){
						cout << flush;
						Sleep(500);
						cout << "\nthe mushroom merchant scoffs in offense.";
					}
					else if ((amount * 5) > p.credits){
						cout << flush;
						Sleep(500);
						cout << "\nyou don't have enough credits to buy that many mushrooms.";
					}
					else{
						p.inventory["MUSHROOMS"] = p.inventory["MUSHROOMS"] + amount;
						cout << flush;
						Sleep(500);
						cout << "\nthe merchant hands you a sack of mushrooms." << flush;
						Sleep(500);
						p.credits = p.credits - (amount * 5);
						cout << "\nyou now have " << p.credits << " credits." << flush;
						Sleep(500);
						cout << "\nthe merchant thanks you for your purchase.";
					}
				}
				else if (purchase == "water"){
					cout << "\nhow much water would you like to buy?\n";
					int amount = 0;
					cin >> amount;
					if (amount == 0){
						cout << flush;
						Sleep(500);
						cout << "\nthe mushroom merchant scoffs in offense.";
					}
					else if ((amount * 5) > p.credits){
						cout << flush;
						Sleep(500);
						cout << "\nyou don't have enough credits to buy that much water.";
					}
					else{
						p.inventory["WATER"] = p.inventory["WATER"] + amount;
						cout << flush;
						Sleep(500);
						cout << "\nthe merchant hands you a jug of water." << flush;
						Sleep(500);
						p.credits = p.credits - (amount * 5);
						cout << "\nyou now have " << p.credits << " credits." << flush;
						Sleep(500);
						cout << "\nthe merchant thanks you for your purchase.";
					}
				}
				else{
					cout << flush;
					Sleep(500);
					cout << "\nthe merchant shakes their head, confused. they don't have that for sale.";
				}
			}
		}
		if (buysell == "sell"){
			cout << flush;
			Sleep(500);
			cout << "\nINVENTORY:\n" << flush;
			Sleep(500);
			p.displayInventory();
			Sleep(500);
			cout << "\nthe merchant asks you what you'd like to sell:\n" << flush;
			Sleep(500);
			string sell = "null";
			cin >> sell;
			if (sell == "mushrooms"){
				int number = 0;
				cout << flush;
				Sleep(500);
				cout << "\nhow many mushrooms would you like to sell?\n";
				cin >> number;
				if (number > p.inventory["MUSHROOMS"]){
					cout << flush;
					Sleep(500);
					cout << "\nyou don't have that many.";
				}
				else{
					p.inventory["MUSHROOMS"] = p.inventory["MUSHROOMS"] - number;
					p.credits = p.credits + (number * 5);
					cout << flush;
					Sleep(500);
					cout << "\nyou now have " << p.credits << " credits.";
				}
			}
			else if (sell == "wood"){
				int number = 0;
				cout << flush;
				Sleep(500);
				cout << "\nhow much wood would you like to sell?\n";
				cin >> number;
				if (number > p.inventory["WOOD"]){
					cout << flush;
					Sleep(500);
					cout << "\nyou don't have that many.";
				}
				else{
					p.inventory["WOOD"] = p.inventory["WOOD"] - number;
					p.credits = p.credits + (number * 5);
					cout << flush;
					Sleep(500);
					cout << "\nyou now have " << p.credits << " credits.";
				}
			}
			else if (sell == "ore"){
				int number = 0;
				cout << flush;
				Sleep(500);
				cout << "\nhow much ore would you like to sell?\n";
				cin >> number;
				if (number > p.inventory["ORE"]){
					cout << flush;
					Sleep(500);
					cout << "\nyou don't have that many.";
				}
				else{
					p.inventory["ORE"] = p.inventory["ORE"] - number;
					p.credits = p.credits + (number * 5);
					cout << flush;
					Sleep(500);
					cout << "\nyou now have " << p.credits << " credits.";
				}
			}
			else if (sell == "water"){
				int number = 0;
				cout << flush;
				Sleep(500);
				cout << "\nhow much water would you like to sell?\n";
				cin >> number;
				if (number > p.inventory["WATER"]){
					cout << flush;
					Sleep(500);
					cout << "\nyou don't have that many.";
				}
				else{
					p.inventory["WATER"] = p.inventory["WATER"] - number;
					p.credits = p.credits + (number * 5);
					cout << flush;
					Sleep(500);
					cout << "\nyou now have " << p.credits << " credits.";
				}
			}
			else if (sell == "mushroom soup"){
				int number = 0;
				cout << flush;
				Sleep(500);
				cout << "\nhow many bowls of mushroom soup would you like to sell?\n";
				cin >> number;
				if (number > p.inventory["MUSHROOM SOUP"]){
					cout << flush;
					Sleep(500);
					cout << "\nyou don't have that many.";
				}
				else{
					p.inventory["MUSHROOM SOUP"] = p.inventory["MUSHROOM SOUP"] - number;
					p.credits = p.credits + (number * 5);
					cout << flush;
					Sleep(500);
					cout << "\nyou now have " << p.credits << " credits.";
				}
			}
			else{
				cout << flush;
				Sleep(500);
				cout << "\nyou can't sell that.";
			}
		}
	}
	cout << flush;
	Sleep(500);
	cout << "\nthe merchant waves goodbye." << flush;
}

void combat(player& p){
	string enemy = "imp";
	srand (time(NULL));
	int rcombat = rand() % 3;
	if (rcombat == 0){
		enemy = "bandit";
	}
	else if (rcombat == 1){
		enemy = "demon";
	}
	else if (rcombat == 2){
		enemy = "wild boar";
	}
	cout << flush;
	Sleep(500);
	cout << "\na " << enemy << " appears.";
	srand (time(NULL));
	int enemy_dmg = rand() % (p.defense + p.defense) + (p.defense - (p.defense / 2));
	if (enemy_dmg <= 0){
		enemy_dmg = 1;
	}
	if (enemy_dmg > p.defense){
		p.health = (p.health - enemy_dmg);
		cout << flush;
		Sleep(500);
		cout << "\nthe " << enemy << " wins the fight. you lose " << enemy_dmg << " HLH." << flush;
		Sleep(500);
		int lossxp = enemy_dmg / 2;
		p.experience = p.experience + lossxp;
		cout << "\nyou gain " << lossxp << " EXP." << flush;
		Sleep(500);
		levelup(p);
		if (p.health <= 0){
			if (enemy == "bandit"){
				cout << flush;
				Sleep(500);
				cout << "\nwith a confident yell, the bandit slashes you with his sword, and you collapse, dead on the path.";
			}
			else if (enemy == "demon"){
				cout << flush;
				Sleep(500);
				cout << "\nthe demon heartily laughs as he grasps you by the throat with his clawed hand, and throws you down, dead, onto the path.";
			}
			else if (enemy == "wild boar"){
				cout << flush;
				Sleep(500);
				cout << "\nthe boar grunts as it spears you on its tusks and throws you, dead, against the path.";
			}
			p.alive = false;
			cout << flush;
			Sleep(1000);
			cout << "\ndon't give up. restart." << flush;
			Sleep(10000);
		}
	}
	else{
		cout << flush;
		Sleep(500);
		cout << "\nyou win the fight.";
		int winxp = enemy_dmg;
		p.experience = p.experience + winxp;
		cout << flush;
		Sleep(500);
		cout << "\nyou gain " << winxp << " EXP.";
		srand (time(NULL));
		int combatcredits = rand() % enemy_dmg + 1;
		p.credits = p.credits + combatcredits;
		cout << flush;
		Sleep(500);
		cout << "\nyou gain " << combatcredits << " credits.";
		levelup(p);
	}
}

void eat(player& p){
	if (p.inventory["MUSHROOM SOUP"] > 0){
		int bowls = 0;
		cout << flush;
		Sleep(500);
		cout << "MUSHROOM SOUP: " << p.inventory["MUSHROOM SOUP"] << flush;
		Sleep(500);
		cout << "\nhow many bowls of mushroom soup would you like to eat?\n";
		cin >> bowls;
		if (bowls > p.inventory["MUSHROOM SOUP"]){
			cout << flush;
			Sleep(500);
			cout << "\nyou don't have that many bowls.";
		}
		else{
		p.inventory["MUSHROOM SOUP"] = p.inventory["MUSHROOM SOUP"] - bowls;
		p.health = p.health + (bowls * 3);
		cout << flush;
		Sleep(500);
		cout << "\nyou ate " << bowls << " bowls of mushroom soup and now have " << p.health << " HLH.";
		}
	}
	else{
		cout << flush;
		Sleep(500);
		cout << "\nyou don't have any food.";
	}
}

void cook(player& p){
	if ((p.inventory["MUSHROOMS"] > 0) && p.inventory["WATER"] > 0){
		cout << flush;
		Sleep(500);
		cout << "MUSHROOMS: " << p.inventory["MUSHROOMS"];
		cout << flush;
		Sleep(500);
		cout << "\nWATER: " << p.inventory["WATER"];
		int bowls = 0;
		cout << flush;
		Sleep(500);
		cout << "\nhow many bowls of mushroom soup would you like to make?\n";
		cin >> bowls;
		if ((bowls > p.inventory["MUSHROOMS"]) || (bowls > p.inventory["WATER"])){
			cout << flush;
			Sleep(500);
			cout << "\nyou don't have enough ingredients to make that many.";
		}
		else{
			p.inventory["MUSHROOMS"] = p.inventory["MUSHROOMS"] - bowls;
			p.inventory["WATER"] = p.inventory["WATER"] - bowls;
			p.inventory["MUSHROOM SOUP"] = bowls;
			cout << flush;
			Sleep(500);
			cout << "\nyou made " << bowls << " bowls of mushroom soup." << flush;
			Sleep(500);
			p.experience = p.experience + bowls;
			cout << "\nyou gain " << bowls << " EXP.";
			levelup(p);
		}
	}
	else{
		cout << flush;
		Sleep(500);
		cout << "\nyou don't have enough ingredients to cook something.";
	}
}

void explore(player& p){
	string gather;
	srand (time(NULL));
	int rexplore = rand() % 6;
	if (rexplore == 0){
		cout << flush;
		Sleep(500);
		cout << "\nyou arrive at the mouth of a deep, dark cave." << flush;
		Sleep(500);
		cout << "\nwould you like to gather some mushrooms? y/n:\n";
		cin >> gather;
		if (gather == "y"){
			int rgather = rand() % 5 + 1;
			if (p.inventory["MUSHROOMS"] > 0){
				int newmush = p.inventory["MUSHROOMS"] + rgather;
				p.inventory["MUSHROOMS"] = newmush;
			}
			else{
				p.inventory["MUSHROOMS"] = rgather;
			}
			p.experience = p.experience + rgather;
			cout << flush;
			Sleep(500);
			cout << "\nyou gathered " << rgather << " mushrooms." << flush;
			Sleep(500);
			cout << "\nyou gain " << rgather << " EXP.";
			levelup(p);
		}
		srand (time(NULL));
		int merchantchance = rand() % 2;
		if (merchantchance == 1){
			merchant(p);
		}
		srand (time(NULL));
		int combatchance = rand() % 2;
		if (combatchance == 0){
			cout << flush;
			Sleep(500);
			cout << "\nthe cave appears to be empty.";
		}
		else{
			combat(p);
		}
	}
	else if (rexplore == 1){
		string chop;
		cout << flush;
		Sleep(500);
		cout << "\nyou arrive at an elegant and lush forest." << flush;
		Sleep(500);
		cout << "\nwould you like to chop down some trees? y/n:\n";
		cin >> chop;
		if (chop == "y"){
			int rchop = rand() % 5 + 1;
			if (p.inventory["WOOD"] > 0){
				int newchop = p.inventory["WOOD"] + rchop;
				p.inventory["WOOD"] = newchop;
			}
			else{
				p.inventory["WOOD"] = rchop;
			}
			p.experience = p.experience + rchop;
			cout << flush;
			Sleep(500);
			cout << "\nyou chopped up " << rchop << " bundles of wood." << flush;
			Sleep(500);
			cout << "\nyou gain " << rchop << " EXP.";
			levelup(p);
		}
		srand (time(NULL));
		int merchantchance = rand() % 2;
		if (merchantchance == 1){
			merchant(p);
		}
		srand (time(NULL));
		int combatchance = rand() % 2;
		if (combatchance == 0){
			cout << flush;
			Sleep(500);
			cout << "\nthe forest is peaceful for now.";
		}
		else{
			combat(p);
		}
	}
	else if (rexplore == 2){
		cout << flush;
		Sleep(500);
		cout << "\nyou arrive at a sulphorous and disgusting swamp.";
		srand (time(NULL));
		srand (time(NULL));
		int merchantchance = rand() % 2;
		if (merchantchance == 1){
			merchant(p);
		}
		int combatchance = rand() % 2;
		if (combatchance == 0){
			cout << flush;
			Sleep(500);
			cout << "\nthe swamp appears to be calm for now.";
		}
		else{
			combat(p);
		}
	}
	else if (rexplore == 3){
		string mine;
		cout << flush;
		Sleep(500);
		cout << "\nyou arrive at the foot of a beautiful and breathtaking mountain." << flush;
		Sleep(500);
		cout << "\nwould you like to mine some ore? y/n:\n";
		cin >> mine;
		if (mine == "y"){
			int rmine = rand() % 5 + 1;
			if (p.inventory["ORE"] > 0){
				int newmine = p.inventory["ORE"] + rmine;
				p.inventory["ORE"] = newmine;
			}
			else{
				p.inventory["ORE"] = rmine;
			}
			p.experience = p.experience + rmine;
			cout << flush;
			Sleep(500);
			cout << "\nyou mined " << rmine << " ore." << flush;
			Sleep(500);
			cout << "\nyou gain " << rmine << " EXP.";
			levelup(p);
		}
		srand (time(NULL));
		int merchantchance = rand() % 2;
		if (merchantchance == 1){
			merchant(p);
		}
		srand (time(NULL));
		int combatchance = rand() % 2;
		if (combatchance == 0){
			cout << flush;
			Sleep(500);
			cout << "\nthe mountain is peaceful for now.";
		}
		else{
			combat(p);
		}
	}
	else if (rexplore == 4){
		string water;
		cout << flush;
		Sleep(500);
		cout << "\nyou arrive at an inviting cobalt lake." << flush;
		Sleep(500);
		cout << "\nwould you like to collect some water? y/n:\n";
		cin >> water;
		if (water == "y"){
			int newwater = 5;
			if (p.inventory["WATER"] > 0){
				newwater = p.inventory["WATER"] + 5;
			}
			p.inventory["WATER"] = newwater;
			p.experience = p.experience + 5;
			cout << flush;
			Sleep(500);
			cout << "\nyou collected 5 water." << flush;
			Sleep(500);
			cout << "\nyou gain 5 EXP.";
			levelup(p);
		}
		srand (time(NULL));
		int merchantchance = rand() % 2;
		if (merchantchance == 1){
			merchant(p);
		}
		srand (time(NULL));
		int combatchance = rand() % 2;
		if (combatchance == 0){
			cout << flush;
			Sleep(500);
			cout << "\nthe lake is peaceful for now.";
		}
		else{
			combat(p);
		}
	}
	else if (rexplore == 5){
		cout << flush;
		Sleep(500);
		cout << "\nyou arrive at an inconspicuously empty field.";
		srand (time(NULL));
		srand (time(NULL));
		int merchantchance = rand() % 2;
		if (merchantchance == 1){
			merchant(p);
		}
		int combatchance = rand() % 2;
		if (combatchance == 0){
			cout << flush;
			Sleep(500);
			cout << "\nthe field is peaceful for now.";
		}
		else{
			combat(p);
		}
	}
}

int main(){
	player p("null", true, 1, 0, 10, 1, 0);
	int action = 0;
	cout << "you stand alone, a wayward one, at the whim of the universe." << flush;
	Sleep(1000);
	cout << "\nwhat is your name?\n";
	cin >> p.name;
	while (action != 6 && p.alive == true){
		hud(p);
		cout << flush;
		Sleep(500);
		cout << "\nwhat would you like to do?\n" << flush;
		Sleep(500);
		cout << "\n1. explore" << flush;
		Sleep(100);
		cout << "\n2. check inventory" << flush;
		Sleep(100);
		cout << "\n3. cook" << flush;
		Sleep(100);
		cout << "\n4. eat" << flush;
		Sleep(100);
		cout << "\n5. ask for help" << flush;
		Sleep(100);
		cout << "\n6. give up\n";
		cin >> action;
		if (action == 1){
			explore(p);
		}
		else if (action == 2){
			cout << flush;
			Sleep(500);
			cout << "\nyour inventory:\n" << flush;
			Sleep(500);
			p.displayInventory();
		}
		else if (action == 3){
			cook(p);
		}
		else if (action == 4){
			eat(p);
		}
		else if (action == 5){
			cout << flush;
			Sleep(500);
			cout << "\na subtle yet powerful voice echoes in your head:\n" << flush;
			Sleep(500);
			cout << "\nexplore to visit locations. locations will randomly have enemies to kill for credits," << flush;
			Sleep(500);
			cout << "\nresources to harvest, and even sometimes a mysterious wandering merchant." << flush;
			Sleep(500);
			cout << "\nyou can cook mushroom soup with mushrooms and water to gain health. the" << flush;
			Sleep(500);
			cout << "\nmerchant also has mushrooms and water to sell if you can't find any." << flush;
			Sleep(500);
			cout << "\nsell any other resources you find to buy more mushrooms and water." << flush;
			Sleep(500);
			cout << "\nkeep leveling up to prolong your journey and see how far you can go." << flush;
			Sleep(500);
			cout << "\nsometimes a goal isn't always in sight. you have to keep trying anyway." << flush;
		}
		else if (action == 6){
			p.alive = false;
			cout << "\noverwhelmed and exhausted, you collapse on the path and don't get back up." << flush;
			Sleep(500);
			cout << "\ndon't give up. restart." << flush;
			Sleep(10000);
		}
		else{
			cout << flush;
			Sleep(500);
			cout << "\nyou sit still and think about all the other things you could potentially do, but can't." << flush;
		}
	};
	return 0;
}
