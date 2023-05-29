#pragma once
#include "room.h"


class Item : public Entity
{
private:
	bool takeable;
	bool container;
	bool open;

public:
	Item(string name, string description, bool takeable, bool container, bool open);
	void AddEntity(Entity* entity);
	bool isTakeble();
	bool isContainer();
	bool isOpen();
	bool SetTakeable(bool takeable);
	bool SetContainer(bool container);
	bool SetOpen(bool open);
	void Update()override;
};

