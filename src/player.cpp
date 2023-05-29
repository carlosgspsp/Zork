#include "../include/player.h"
#include "../include/item.h"

using namespace std;

Player::Player(string name, string description, Room* location) : Creature(name, description, location) {

}


void Player::Update() {

}

void Player::Go(vector<string> args, const vector<Entity*>& entities, map<string, ExitDirections>& directions_map) {

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

void Player::Look() {
	Room* location = GetLocation();

	cout << endl << location->GetName();
	cout << endl << location->GetDescription();

	for (auto entity : location->GetContains()) {
		cout << endl << "There is a " << entity->GetDescription() << " here.";
		
			
		if (!entity->GetContains().empty()) {
			cout << endl << "The " << entity->GetDescription() << " contains:";
			for (auto inside_entity : entity->GetContains()) {
				cout << endl << "A " << inside_entity->GetDescription();
			}
		}
	}

	cout << endl;
	
}

void Player::Inventory() {
	cout << endl << "You are carrying:";
	for (auto entity : this->GetContains()) {
		cout << endl << "A " << entity->GetDescription();
	}
	cout << endl;
}

void Player::Take(vector<string> args) {
	
	Room* location = GetLocation();
	Entity* entity = nullptr;
	bool take = false;
	bool found = false;
	for (auto room_entity : location->GetContains()) {
		for (int i = 1; i < args.size(); i++) {
			if (args[i].compare(room_entity->GetName()) == 0) {
				found = true;
				if (room_entity->GetType() == EntityType::ITEM) {
					if (((Item*)room_entity)->isTakeble()) {
						take = true;
						entity = room_entity;
					}
				}
				
				
			}
		}
	}

	if (take && entity != nullptr) {
		AddEntity(entity);
		location->RemoveEntity(entity);

		cout << entity->GetName() << " taken." << endl;
	}
	else if (found){
		cout << "The item could not be taken" << endl;
	}
	else {
		cout << "The item was not found" << endl;
	}

}

void Player::Drop(vector<string> args) {

	Room* location = GetLocation();
	Entity* entity = nullptr;
	bool drop = false;
	for (auto player_entity : GetContains()) {
		for (int i = 1; i < args.size(); i++) {
			if (args[i].compare(player_entity->GetName()) == 0) {
						drop = true;
						entity = player_entity;
			}
		}
	}


	if (drop && entity != nullptr) {
		location->AddEntity(entity);
		RemoveEntity(entity);

		cout << entity->GetName() << " dropped." << endl;
	}
	else {
		cout << "The item could not be dropped" << endl;
	}

}