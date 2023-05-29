#include "../include/player.h"

using namespace std;

Player::Player(string name, string description, Room* location) : Creature(name, description, location) {

}


void Player::Update() {

}

void Player::Go(vector<string> args, const vector<Entity*>& entities, map<string, ExitDirections> directions_map){

	int direction_pos = (args.size() > 2) ? 1 : args.size() - 1;
	ExitDirections direction;

	map<string, ExitDirections>::iterator it = directions_map.find(args[direction_pos]);


	bool moved = false;
	if (it != directions_map.end()) {
		direction = it->second;

		for (auto entity : entities) {
			if (entity->GetType() == EntityType::EXIT) {
				if (((Exit*)entity)->GetSource() == GetLocation()) {
					if (((Exit*)entity)->GetDirection() == direction) {
						if (!moved) {
							SetLocation(((Exit*)entity)->GetDestination());
							moved = true;
						}
						
					}
				}
			}
		}

		if (!moved) {
			cout << endl << "You can not go to that direction from here." << endl;
		}

	}
	else {
		cout << endl << "I did not understad that direction." << endl;
	}


	
}