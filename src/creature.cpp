#include "../include/creature.h"

Creature::Creature(string name, string description, Room* location) : Entity(name, description, EntityType::CREATURE){

	this->location = location;

}

void Creature::Update() {

}

Room* Creature::GetLocation() {
	return location;
}

void Creature::SetLocation(Room* new_location) {
	 location = new_location;
}