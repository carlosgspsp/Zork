#include "../include/exit.h"

using namespace std;

Exit::Exit(string name,string description,ExitDirections direction, Room* source, Room* destination): Entity(name, description, EntityType::EXIT) { //Exit constructor

	this->direction = direction;
	this->source = source;
	this->destination = destination;
	this->locked = false;
	this->key = nullptr;
}

Exit::Exit(string name, string description, ExitDirections direction, Room* source, Room* destination, bool locked, Item* key) : Entity(name, description, EntityType::EXIT) { //Exit constructor

	this->direction = direction;
	this->source = source;
	this->destination = destination;
	this->locked = locked;
	this->key = key;
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

bool Exit::isLocked() {
	return this->locked;
}

void Exit::setLocked(bool locked) {
	this->locked = locked;
}

Item* Exit::getKey() {
	return this->key;
}
