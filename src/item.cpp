#include "../include/item.h"

Item::Item(string name, string description, bool takeable, bool container, bool open) : Entity(name, description, EntityType::ITEM) {
	this->takeable = takeable;
	this->container = container;
}

void Item::AddEntity(Entity* entity) {
	if (container) {
		Entity::AddEntity(entity);
	}
}
void Item::Update() {

}