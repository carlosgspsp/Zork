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
	Room* location = GetLocation();
	map<string, ExitDirections>::iterator it = directions_map.find(args[direction_pos]);


	bool moved = false;
	if (it != directions_map.end()) {
		direction = it->second;
		for (auto room_entity : location->GetContains()) {
			if (room_entity->GetType() == EntityType::EXIT) {
				if (((Exit*)room_entity)->GetDirection() == direction) {
					if (((Exit*)room_entity)->isLocked()) {
						for (auto player_entity : GetContains()) {
							if (player_entity == ((Exit*)room_entity)->getKey()) {
								((Exit*)room_entity)->setLocked(false);
								SetLocation(((Exit*)room_entity)->GetDestination());
								moved = true;
								cout << endl << "The exit was unlocked with the item '" << ((Exit*)room_entity)->getKey()->GetName() << "'"<< endl;
							}
						}
						if (!moved) {
							cout << endl << "A key its necessary to unlock this exit";
						}
					}
					else {
							SetLocation(((Exit*)room_entity)->GetDestination());
							moved = true;
					}
				}


			}
		}




		if (!moved) {
			cout << endl << "You can not go to that direction from here." << endl;
		}
		else {
			Look();
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
		if (entity->GetType() == EntityType::EXIT) {
			cout << endl << entity->GetDescription();
		}
	}

	cout << endl;

	for (auto entity : location->GetContains()) {
		if (entity->GetType() == EntityType::ITEM) {
			cout << endl << "There is a " << entity->GetDescription() << " here.";


			if (!entity->GetContains().empty()) {
				cout << endl << "The " << entity->GetDescription() << " contains:";
				for (auto inside_entity : entity->GetContains()) {
					cout << endl << "A " << inside_entity->GetDescription();
				}
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
	Entity* container = nullptr;
	bool take = false;
	bool found = false;
	string name = "";

	if (args.size() == 2) {

		name = args[1];
	}
	else {


		for (int i = 1; i < args.size(); i++) {
			name += args[i] + " ";
		}
		name.erase(name.size() - 1, 1);
	}

	for (auto room_entity : location->GetContains()) {
		if (room_entity->GetType() == EntityType::ITEM) {
			if (name.compare(room_entity->GetName()) == 0) {
				found = true;
				if (room_entity->GetType() == EntityType::ITEM) {
					if (((Item*)room_entity)->isTakeble()) {
						take = true;
						entity = room_entity;
						container = location;
					}
				}


			}
			else if (((Item*)room_entity)->isContainer()) {
				for (auto item_entity : ((Item*)room_entity)->GetContains()) {
					if (name.compare(item_entity->GetName()) == 0) {
						found = true;
						if (item_entity->GetType() == EntityType::ITEM) {
							if (((Item*)item_entity)->isTakeble()) {
								take = true;
								entity = item_entity;
								container = room_entity;
							}
						}


					}
				}
			}

		}

	}


	if (take && entity != nullptr && container != nullptr) {
		AddEntity(entity);
		container->RemoveEntity(entity);

		cout << entity->GetName() << " taken." << endl;
	}
	else if (found) {
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
	string name = "";
	if (args.size() == 2) {

		name = args[1];
	}
	else {


		for (int i = 1; i < args.size(); i++) {
			name += args[i] + " ";
		}
		name.erase(name.size() - 1, 1);
	}

	for (auto player_entity : GetContains()) {

		if (name.compare(player_entity->GetName()) == 0) {
			drop = true;
			entity = player_entity;
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

void Player::Put(vector<string> args) {

	string entity_name = "";
	string container_name = "";
	int in_position;
	Room* location = GetLocation();
	Entity* entity = nullptr;
	Entity* new_container = nullptr;
	Entity* old_container = nullptr;

	bool entity_found = false;
	bool container_found = false;

	for (int i = 0; i < args.size(); i++) {
		if (args[i].compare("in") == 0) {
			in_position = i;
		}
	}

	for (int i = 1; i < in_position; i++) {
		entity_name += args[i] + " ";
	}
	for (int i = in_position + 1; i < args.size(); i++) {
		container_name += args[i] + " ";
	}

	entity_name.erase(entity_name.size() - 1, 1);
	container_name.erase(container_name.size() - 1, 1);



	for (auto player_entity : GetContains()) {
		if (player_entity->GetType() == EntityType::ITEM) {
			if (entity_name.compare(player_entity->GetName()) == 0) {
				entity = player_entity;
				old_container = this;
				entity_found = true;
			}
			if (container_name.compare(player_entity->GetName()) == 0 && ((Item*)player_entity)->isContainer()) {
				new_container = player_entity;
				container_found = true;

			}
		}

	}

	for (auto room_entity : location->GetContains()) {
		if (room_entity->GetType() == EntityType::ITEM) {
			if (entity_name.compare(room_entity->GetName()) == 0) {
				entity = room_entity;
				old_container = location;
				entity_found = true;
			}
			if (container_name.compare(room_entity->GetName()) == 0 && ((Item*)room_entity)->isContainer()) {
				new_container = room_entity;
				container_found = true;

			}
		}

	}


	if (entity_found && container_found) {
		new_container->AddEntity(entity);
		old_container->RemoveEntity(entity);

		cout << endl << "The item: " << entity->GetName() << " has been moved to " << new_container->GetName() << endl;
	}
	else {
		cout << endl << "The item could not be moved" << endl;
	}


}
