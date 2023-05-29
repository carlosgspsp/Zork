#include "../include/world.h"
#include "../include/room.h"
#include "../include/player.h"
#include "../include/item.h"




World::World() { //World constructor

	finish_game = false;

	//filling maps with posible string keys
	actions_map.insert({ "l", Actions::LOOK });
	actions_map.insert({ "look", Actions::LOOK });
	actions_map.insert({ "go", Actions::GO });
	actions_map.insert({ "east", Actions::GO });
	actions_map.insert({ "e", Actions::GO });
	actions_map.insert({ "west", Actions::GO });
	actions_map.insert({ "w", Actions::GO });
	actions_map.insert({ "north", Actions::GO });
	actions_map.insert({ "n", Actions::GO });
	actions_map.insert({ "south", Actions::GO });
	actions_map.insert({ "s", Actions::GO });
	actions_map.insert({ "up", Actions::GO });
	actions_map.insert({ "u", Actions::GO });
	actions_map.insert({ "down", Actions::GO });
	actions_map.insert({ "d", Actions::GO });
	actions_map.insert({ "inventory", Actions::INVENTORY });
	actions_map.insert({ "i", Actions::INVENTORY });
	actions_map.insert({ "quit", Actions::QUIT });
	actions_map.insert({ "q", Actions::QUIT });

	directions_map.insert({ "north", ExitDirections::NORTH });
	directions_map.insert({ "n", ExitDirections::NORTH });
	directions_map.insert({ "south", ExitDirections::SOUTH });
	directions_map.insert({ "s", ExitDirections::SOUTH });
	directions_map.insert({ "west", ExitDirections::WEST });
	directions_map.insert({ "w", ExitDirections::WEST });
	directions_map.insert({ "east", ExitDirections::EAST });
	directions_map.insert({ "e", ExitDirections::EAST });
	directions_map.insert({ "up", ExitDirections::UP });
	directions_map.insert({ "u", ExitDirections::UP });
	directions_map.insert({ "down", ExitDirections::DOWN });
	directions_map.insert({ "d", ExitDirections::DOWN });





	//Recreating the initial zone of Zork with Rooms, Exits and the player
	Room* west_house = new Room("West of House", "This is an open field west of a white house.");
	Room* north_house = new Room("North of House", "You are facing the north side of a white house.  There is no door here, and all the windows are barred.");
	Room* behind_house = new Room("Behind House", "You are behind the white house.");
	Room* south_house = new Room("South of house", "You are facing the south side of a white house.");

	Room* kitchen = new Room("Kitchen", "You are in the kitchen of the white house");
	Room* attic = new Room("Attic", "This is the attic.");
	Room* living_room = new Room("Living Room", "You are in the living room.");


	Exit* west_house_to_north_house = new Exit("", "", ExitDirections::NORTH, west_house, north_house);
	Exit* west_house_to_south_house = new Exit("", "", ExitDirections::SOUTH, west_house, south_house);

	Exit* north_house_to_west_house = new Exit("", "", ExitDirections::WEST, north_house, west_house);
	Exit* north_house_to_behind_house = new Exit("", "", ExitDirections::EAST, north_house, behind_house);

	Exit* behind_house_to_north_house = new Exit("", "", ExitDirections::NORTH, behind_house, north_house);
	Exit* behind_house_to_kitchen = new Exit("", "In one corner of the house there is a small window which is open.", ExitDirections::WEST, behind_house, kitchen);
	Exit* behind_house_to_south_house = new Exit("", "", ExitDirections::SOUTH, behind_house, south_house);

	Exit* south_house_to_west_house = new Exit("", "", ExitDirections::WEST, south_house, west_house);
	Exit* south_house_to_behind_house = new Exit("", "", ExitDirections::EAST, south_house, behind_house);

	Exit* kitchen_to_behind_house = new Exit("", "", ExitDirections::EAST, kitchen, behind_house);
	Exit* kitchen_to_living_room = new Exit("", "", ExitDirections::WEST, kitchen, living_room);
	Exit* kitchen_to_attic = new Exit("", "", ExitDirections::UP, kitchen, attic);

	Exit* living_room_to_kitchen = new Exit("", "", ExitDirections::EAST, living_room, kitchen);

	Exit* attic_to_kitchen = new Exit("", "", ExitDirections::DOWN, attic, kitchen);


	player = new Player("Player", "The Hero of the Dungeon", west_house);


	Item* mailbox = new Item("mailbox", "small mailbox", false, true, false);
	west_house->AddEntity(mailbox);

	Item* stone = new Item("stone", "small stone", false, false, false);
	player->AddEntity(stone);
			
	

	entities.push_back(west_house);
	entities.push_back(north_house);
	entities.push_back(behind_house);
	entities.push_back(south_house);

	entities.push_back(kitchen);
	entities.push_back(attic);
	entities.push_back(living_room);


	entities.push_back(west_house_to_north_house);
	entities.push_back(west_house_to_south_house);

	entities.push_back(north_house_to_west_house);
	entities.push_back(north_house_to_behind_house);

	entities.push_back(behind_house_to_north_house);
	entities.push_back(behind_house_to_kitchen);
	entities.push_back(behind_house_to_south_house);

	entities.push_back(south_house_to_west_house);
	entities.push_back(south_house_to_behind_house);

	entities.push_back(kitchen_to_behind_house);
	entities.push_back(kitchen_to_living_room);
	entities.push_back(kitchen_to_attic);

	entities.push_back(living_room_to_kitchen);

	entities.push_back(attic_to_kitchen);
	

	entities.push_back(mailbox);

	entities.push_back(player);


}

void World::Play() {
	string command;

	while (!finish_game) {
		//string.getline(command,100, '\n');
		cout << endl;
		getline(std::cin, command, '\n');
		//cout << endl << command;
		ParseCommand(command);
	}
}

bool World::GameFinished() {
	return finish_game;
}
void World::ParseCommand(string command) {

	vector<string> command_words;
	command_words = Tokenize(command);
	cout << endl << "tokenized words" << endl;
	for (int i = 0; i < command_words.size(); i++) {
		cout << endl << ':' << command_words[i] << ':' << endl;
	}
	map<string, Actions>::iterator it = actions_map.find(command_words[0]);

	if (it != actions_map.end()) {
		Actions action = actions_map[command_words[0]];
		switch (action)
		{
		case Actions::GO:
			cout << endl << "GO COMMAND" << endl;
			cout << "Old player location;: " << ((Player*)player)->GetLocation()->GetName() << endl;
			((Player*)player)->Go(command_words, entities, directions_map);
			cout << "New player location;: " << ((Player*)player)->GetLocation()->GetName() << endl;
			break;
		case Actions::LOOK:
			cout << endl << "LOOK COMMAND" << endl;
			((Player*)player)->Look();
			break;
		case Actions::INVENTORY:
			cout << endl << "INVENTORY COMMAND" << endl;
			((Player*)player)->Inventory();
			break;
		case Actions::QUIT:
			finish_game = true;
			break;
		default:
			break;
		}
	}
	else {
		cout << endl << "I do not recognise that command" << endl;
	}


}



vector<string> World::Tokenize(string command) {



	for (int i = 0; i < command.length(); i++) { //Transform command to lowercase
		command[i] = tolower(command[i]);
	}

	//Remove blank space from command first and last positions
	while (command[0] == ' ') {
		command.erase(0, 1);
	}
	while (command[command.length() - 1] == ' ') {
		command.erase(command.length() - 1, 1);
	}

	//cout << "'" << command << "'";
	vector<string> result;
	int pos = 2;
	while (pos != -1) {
		pos = command.find(" ");
		if (pos != -1) {
			string substr = command.substr(0, pos);
			if (!substr.empty()) {
				result.push_back(substr);
			}
			command.erase(0, pos + 1);
		}
		else {

			result.push_back(command);
		}
	}


	return result;
}