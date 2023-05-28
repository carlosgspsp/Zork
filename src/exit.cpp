#include "../include/exit.h"

Exit::Exit(string name,string description,ExitDirection direction, Room* source, Room* destination): Entity(name, description, EntityType::EXIT) { //Exit constructor

	this->direction = direction;
	this->source = source;
	this->destination = destination;
}
