#include "../include/exit.h"

using namespace std;

Exit::Exit(string name,string description,ExitDirections direction, Room* source, Room* destination): Entity(name, description, EntityType::EXIT) { //Exit constructor

	this->direction = direction;
	this->source = source;
	this->destination = destination;
}

void Exit::Update() {

}

Room* Exit::GetSource() {
	return source;
}

Room* Exit::GetDestination() {
	return destination;
}

ExitDirections Exit::GetDirection() {
	return direction;
}
