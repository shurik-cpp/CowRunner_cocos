#ifndef ENEMYUNIT_H
#define ENEMYUNIT_H

#include "GameUnit.h"

class EnemyUnit : public GameUnit {
public:
	explicit EnemyUnit(const std::string& name)
		: GameUnit(name)
	{ }

	void Tick(Events& events, const float delta) override;
};

#endif // ENEMYUNIT_H
