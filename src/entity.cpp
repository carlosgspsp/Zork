#include "../include/entity.h"

Entity::Entity(string name, string description, EntityType type) {
	this->name = name;
	this->description = description;
	this->type = type;
}


EntityType Entity::GetType() {
	return type;
}

string Entity::GetName() {
	return name;
}

string Entity::GetDescription() {
	return description;
}

const list<Entity*>& Entity::GetContains() {
	return this->contains;
}

void Entity::AddEntity(Entity* entity) {
	contains.push_back(entity);
}

void Entity::RemoveEntity(Entity* entity) {
	contains.remove(entity);
}

void Entity::SetType(EntityType type) {
	this->type = type;
}

void Entity::SetName(string name) {
	this->name = name;
}

void Entity::SetDescription(string description) {
	this->description = description;
}

