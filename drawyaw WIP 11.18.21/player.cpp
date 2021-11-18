#include <iostream>
#include <map>
#include "player.h"
using namespace std;

void player::setname(string n){
	name = n;
}

string player::getname(){
	return name;
}

void player::setlevel(int lvl){
	level = lvl;
}

int player::getlevel(){
	return level;
}

void player::setexp(int exp){
	experience = exp;
}

int player::getexp(){
	return experience;
}

void player::sethealth(int hlh){
	health = hlh;
}

int player::gethealth(){
	return health;
}

void player::setstamina(int sta){
	stamina = sta;
}

int player::getstamina(){
	return stamina;
}

void player::setdamage(int dmg){
	damage = dmg;
}

int player::getdamage(){
	return damage;
}

void player::setdefense(int def){
	defense = def;
}

int player::getdefense(){
	return defense;
}

void player::setcredits(int c){
	credits = c;
}

int player::getcredits(){
	return credits;
}
