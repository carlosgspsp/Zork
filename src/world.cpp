#include "../include/world.h"
#include "../include/room.h"
#include "../include/player.h"


World::World() { //World constructor
	
	//Recreating the initial zone of Zork
	Room* west_house = new Room("West of House", "This is an open field west of a white house.");
	Room* north_house = new Room("North of House", "You are facing the north side of a white house.  There is no door here, and all the windows are barred.");
	Room* behind_house = new Room("Behind House", "You are behind the white house.");
	Room* south_house = new Room("South of house", "You are facing the south side of a white house.");

	Room* kitchen =  new Room("Kitchen", "You are in the kitchen of the white house");
	Room* attic = new Room("Kitchen", "You are kitchen of the white house");
	Room* living_room = new Room("Kitchen", "You are kitchen of the white house");


	Exit* west_house_to_north_house = new Exit("", "", ExitDirection::NORTH, west_house, north_house);
	Exit* west_house_to_south_house = new Exit("", "", ExitDirection::SOUTH, west_house, south_house);

	Exit* north_house_to_west_house = new Exit("", "", ExitDirection::WEST, north_house, west_house);
	Exit* north_house_to_behind_house = new Exit("", "", ExitDirection::EAST, north_house, behind_house);

	Exit* behind_house_to_north_house = new Exit("", "", ExitDirection::NORTH, behind_house, north_house);
	Exit* behind_house_to_kitchen = new Exit("", "In one corner of the house there is a small window which is open.", ExitDirection::EAST, behind_house, kitchen);
	Exit* behind_house_to_south_house = new Exit("", "", ExitDirection::SOUTH, behind_house, south_house);

	Exit* south_house_to_west_house = new Exit("", "", ExitDirection::WEST, south_house, west_house);
	Exit* south_house_to_behind_house = new Exit("", "", ExitDirection::EAST, south_house, behind_house);

	Player* player = new Player("Player","The Hero of the Dungeon", west_house);

	entities.push_back(west_house);
	entities.push_back(north_house);
	entities.push_back(behind_house);
	entities.push_back(south_house);

	entities.push_back(kitchen);
	//entities.push_back(attic);
	//entities.push_back(living_room);


	entities.push_back(west_house_to_north_house);
	entities.push_back(west_house_to_south_house);

	entities.push_back(north_house_to_west_house);
	entities.push_back(north_house_to_behind_house);

	entities.push_back(behind_house_to_north_house);
	entities.push_back(behind_house_to_kitchen);
	entities.push_back(behind_house_to_south_house);

	entities.push_back(south_house_to_west_house);
	entities.push_back(south_house_to_behind_house);

	entities.push_back(player);


}