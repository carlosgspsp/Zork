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
	actions_map.insert({ "take", Actions::TAKE });
	actions_map.insert({ "drop", Actions::DROP });
	actions_map.insert({ "put", Actions::PUT });
	actions_map.insert({ "close", Actions::CLOSE });
	actions_map.insert({ "open", Actions::OPEN });

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
	Room* basement = new Room("Basement", "You are in the basement.");


	Exit* west_house_to_north_house = new Exit("", "To the north is the north side of the house.", ExitDirections::NORTH, west_house, north_house);
	Exit* west_house_to_south_house = new Exit("", "To the south is the south side of the house.", ExitDirections::SOUTH, west_house, south_house);

	west_house->AddEntity(west_house_to_north_house);
	west_house->AddEntity(west_house_to_south_house);

	Exit* north_house_to_west_house = new Exit("", "To the west is the west side of the house.", ExitDirections::WEST, north_house, west_house);
	Exit* north_house_to_behind_house = new Exit("", "To the east is the back of the house.", ExitDirections::EAST, north_house, behind_house);

	north_house->AddEntity(north_house_to_west_house);
	north_house->AddEntity(north_house_to_behind_house);

	Exit* behind_house_to_north_house = new Exit("", "To the north is the north side of the house.", ExitDirections::NORTH, behind_house, north_house);
	Item* kitchen_key = new Item("stone key", "small stone key with a word written in it 'kitchen'", true, false, false);
	Exit* behind_house_to_kitchen = new Exit("", "To the west you can find a back door to the house, It seems to be a kitchen inside.", ExitDirections::WEST, behind_house, kitchen, true, kitchen_key);
	Exit* behind_house_to_south_house = new Exit("", "To the south is the south side of the house.", ExitDirections::SOUTH, behind_house, south_house);

	behind_house->AddEntity(behind_house_to_north_house);
	behind_house->AddEntity(behind_house_to_kitchen);
	behind_house->AddEntity(behind_house_to_south_house);

	Exit* south_house_to_west_house = new Exit("", "To the west is the west side of the house.", ExitDirections::WEST, south_house, west_house);
	Exit* south_house_to_behind_house = new Exit("", "To the east is the back of the house.", ExitDirections::EAST, south_house, behind_house);

	south_house->AddEntity(south_house_to_behind_house);
	south_house->AddEntity(south_house_to_west_house);


	Exit* kitchen_to_behind_house = new Exit("", "To the east is the back of the house.", ExitDirections::EAST, kitchen, behind_house);
	Exit* kitchen_to_living_room = new Exit("", "To the west is the living room.", ExitDirections::WEST, kitchen, living_room);
	Item* attic_key = new Item("iron key", "iron key with a word written in it 'attic'", true, false, false);
	Exit* kitchen_to_attic = new Exit("", "Going up is the attic.", ExitDirections::UP, kitchen, attic , true, attic_key);

	kitchen->AddEntity(kitchen_to_behind_house);
	kitchen->AddEntity(kitchen_to_living_room);
	kitchen->AddEntity(kitchen_to_attic);

	Exit* living_room_to_kitchen = new Exit("", "To the east is the kitchen.", ExitDirections::EAST, living_room, kitchen);
	Item* basement_key = new Item("wooden key", "wooden key with a word written in it 'basement'", true, false, false);
	Exit* living_room_to_basement = new Exit("", "Going down is the basement.", ExitDirections::DOWN, living_room, basement, true , basement_key);

	living_room->AddEntity(living_room_to_kitchen);
	living_room->AddEntity(living_room_to_basement);

	Exit* attic_to_kitchen = new Exit("", "Going down is the kitchen", ExitDirections::DOWN, attic, kitchen);

	attic->AddEntity(attic_to_kitchen);

	Exit* basement_to_living_room = new Exit("", "Going up is the basement", ExitDirections::UP, basement, living_room);

	basement->AddEntity(basement_to_living_room);

	player = new Player("Player", "The Hero of the Dungeon", west_house);


	Item* mailbox = new Item("mailbox", "small mailbox", false, true, false);
	west_house->AddEntity(mailbox);
	mailbox->AddEntity(kitchen_key);

	Item* table= new Item("table", "Kitchen table", false, true, true);
	kitchen->AddEntity(table);
	table->AddEntity(basement_key);

	Item* steel_chest = new Item("steel chest", "Steel chest", false, true, true);
	steel_chest->AddEntity(attic_key);
	basement->AddEntity(steel_chest);

	Item* treasure = new Item("treasure", "treasure", true, false, false);
	Item* gold_chest = new Item("gold chest", "Gold chest", false, true, true);

	Item* knife = new Item("knife", "knife", true, false, false);
	((Player*)player)->AddEntity(knife);

	gold_chest->AddEntity(treasure);
	attic->AddEntity(gold_chest);

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
	
	entities.push_back(kitchen_key);
	entities.push_back(behind_house_to_kitchen);
	entities.push_back(behind_house_to_south_house);

	entities.push_back(south_house_to_west_house);
	entities.push_back(south_house_to_behind_house);

	entities.push_back(kitchen_to_behind_house);
	entities.push_back(kitchen_to_living_room);
	entities.push_back(attic_key);
	entities.push_back(kitchen_to_attic);

	entities.push_back(living_room_to_kitchen);
	entities.push_back(basement_key);
	entities.push_back(living_room_to_basement);
	entities.push_back(attic_to_kitchen);
	entities.push_back(basement_to_living_room);


	entities.push_back(mailbox);
	entities.push_back(table);
	entities.push_back(steel_chest);
	entities.push_back(gold_chest);
	entities.push_back(knife);


	entities.push_back(player);


}

void World::Play() {
	string command;
	cout << "Wecome to Zork" << endl;
	cout << endl;
	((Player*)player)->Look();
	cout << endl;
	while (!finish_game) {
		getline(std::cin, command, '\n');
		if (command != "") {
			ParseCommand(command);
		}
	}
}

bool World::GameFinished() {
	return finish_game;
}
void World::ParseCommand(string command) {

	vector<string> command_words;
	command_words = Tokenize(command);
	/*cout << endl << "tokenized words" << endl;
	for (int i = 0; i < command_words.size(); i++) {
		cout << endl << ':' << command_words[i] << ':' << endl;
	}*/
	map<string, Actions>::iterator it = actions_map.find(command_words[0]);

	if (it != actions_map.end()) {
		Actions action = actions_map[command_words[0]];
		switch (action)
		{
		case Actions::GO:
			cout << endl << "GO COMMAND" << endl;
			((Player*)player)->Go(command_words, entities, directions_map);
			break;
		case Actions::LOOK:
			cout << endl << "LOOK COMMAND" << endl;
			((Player*)player)->Look();
			break;
		case Actions::INVENTORY:
			cout << endl << "INVENTORY COMMAND" << endl;
			((Player*)player)->Inventory();
			break;
		case Actions::TAKE:
			cout << endl << "TAKE COMMAND" << endl;
			((Player*)player)->Take(command_words);
			break;
		case Actions::DROP:
			cout << endl << "DROP COMMAND" << endl;
			((Player*)player)->Drop(command_words);
			break;
		case Actions::PUT:
			cout << endl << "PUT COMMAND" << endl;
			((Player*)player)->Put(command_words);
			break;
		case Actions::OPEN:
			cout << endl << "OPEN COMMAND" << endl;
			((Player*)player)->Put(command_words);
			break;
		case Actions::CLOSE:
			cout << endl << "CLOSE COMMAND" << endl;
			((Player*)player)->Put(command_words);
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