#include <iostream>
#include <map>
#include "player.h"
using namespace std;

map<string, int> player::displayInventory(){
	for(map <string,int> :: iterator it = inventory.begin(); it!= inventory.end(); ++it)
	    cout << it -> first << ": " << it -> second << '\n';
	return inventory;
}
