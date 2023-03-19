#include "CowUnit.h"

USING_NS_CC;

void CowUnit::Tick(Events& events, const float delta) {
	if ((events.isKeyLeft && !events.isShiftKey)
		|| (events.isKeyRight && !events.isShiftKey)) {
		state = UnitState::WALK;
	}
	else if ((events.isKeyLeft && events.isShiftKey)
			 || (events.isKeyRight && events.isShiftKey)) {
		state = UnitState::RUN;
	}
	else if ((!events.isKeyLeft && !events.isKeyRight)
			 || (events.isKeyLeft && events.isKeyRight)) {
		state = UnitState::STAND;
	}

	float cow_speed = 0; //350 * delta;
	if (state == UnitState::WALK) {
		cow_speed = 5;
	}
	else if (state == UnitState::RUN) {
		cow_speed = 12;
	}

	if (events.isKeyLeft && events.isKeyRight) {
		// TODO: корова мычит и воспроизводится анимация недовольной коровы (встает на дыбы? :D)
		state = UnitState::STAND;
		cow_speed = 0;
	}
	else if (events.isKeyLeft) {
		direction = UnitDirection::LEFT;
		cow_speed *= -1;
	}
	else if (events.isKeyRight) {
		direction = UnitDirection::RIGHT;
	}

	sprite->setFlippedX(!static_cast<bool>(direction));

	auto posX = sprite->getPositionX() + cow_speed;
	auto sprite_size_X = sprite->getTextureRect().getMaxX();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (posX - sprite_size_X / 2 > visibleSize.width && direction == UnitDirection::RIGHT)
		posX = 0 - sprite_size_X / 2;
	else if (posX + sprite_size_X / 2 < 0 && direction == UnitDirection::LEFT)
		posX = visibleSize.width + sprite_size_X / 2;

	sprite->setPositionX(posX);


	const float cow_posY = sprite->getPositionY();
	const float MAX_JUMP_ACCELERATION = 25; //1000 * delta;  // высота прыжка
	const float JUMP_DELTA = 1.1; //std::rand() % 5; //30 * delta;                // замедление/ускорение
	const float COW_ON_LAND_Y = 120; // 105
	static float jump_acceleration = 0;

	if (jump_status == UnitJumpStatus::ON_LAND) {
		if (events.isUpKey) {
			jump_status = UnitJumpStatus::UP;
		}
	}
	if (events.isDownKey) {
		jump_status = UnitJumpStatus::DOWN;
	}

	if (jump_status == UnitJumpStatus::UP) {
		jump_acceleration = MAX_JUMP_ACCELERATION;
		jump_status = UnitJumpStatus::FLY;
	}
	else if (jump_status == UnitJumpStatus::FLY) {
		if (jump_acceleration > 0) {
			sprite->setPositionY(cow_posY + jump_acceleration);
			jump_acceleration -= JUMP_DELTA;
		}
		else {
			jump_status = UnitJumpStatus::DOWN;
			jump_acceleration = 0;
			events.is_change_animation = true;
		}
	}
	else if (jump_status == UnitJumpStatus::DOWN) {
		if (cow_posY >= COW_ON_LAND_Y) {
			sprite->setPositionY(cow_posY - jump_acceleration);
			if (jump_acceleration < MAX_JUMP_ACCELERATION) {
				jump_acceleration += JUMP_DELTA;
			}
		}
		else {
			sprite->setPositionY(COW_ON_LAND_Y);
			jump_status = UnitJumpStatus::ON_LAND;
			jump_acceleration = 0;
			events.is_change_animation = true;
		}
	}

	if (events.is_change_animation) {
		events.is_change_animation = false;
		UpdateUnitAnimation();
	}
}
