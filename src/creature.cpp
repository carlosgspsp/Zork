#include "../include/creature.h"

Creature::Creature(string name, string description, Room* location) : Entity(name, description, EntityType::CREATURE){

	this->location = location;

}

void Creature::Update() {

}