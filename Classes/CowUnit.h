#ifndef COWUNIT_H
#define COWUNIT_H

#include "cocos2d.h"
#include "GameUnit.h"

class CowUnit : public GameUnit {
public:
	explicit CowUnit(const std::string& name)
		: GameUnit(name)
	{ }

	void Tick(Events& events, const float delta) override;
};

#endif // COWUNIT_H
