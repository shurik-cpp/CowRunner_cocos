#pragma once
#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include <iostream>
#include <unordered_map>
#include "cocos2d.h"

struct isEvents {
	bool isKeyLeft = false;
	bool isKeyRight = false;
	bool isUpKey = false;
	bool isDownKey = false;
	bool isShiftKey = false;
	bool is_change_animation = false;
};

enum class UnitState {
	STAND,
	WAIT,
	WALK,
	RUN,
	JUMP,
	END_STATE
};



class AnimationManager {
public:
	explicit AnimationManager(const std::string& name)
		: unit_name(name)
	{
		anims_frames_and_delays = GetAnimsFramesAndDelay(unit_name);
	}

	void SetState(const UnitState st) { state = st; }
	size_t GetNumberOfFrames() const { return anims_frames_and_delays.at(state).frame_count; }
	float GetAnimationDelay() const { return anims_frames_and_delays.at(state).delay; }
	std::string GetAnimationName(const UnitState state) const { return unit_name + "_" + UnitStateToString(state); }

private:
	std::string unit_name;
	UnitState state;

	struct AnimProperties {
		size_t frame_count;
		float delay;
	};

	std::unordered_map<UnitState, AnimProperties> anims_frames_and_delays;
	std::unordered_map<UnitState, std::string> anim_names_of_state;

	std::string UnitStateToString(const UnitState state) const {
		switch (state) {
			case UnitState::STAND:
				return "stand";
			case UnitState::WAIT:
				return "wait";
			case UnitState::WALK:
				return "walk";
			case UnitState::RUN:
				return "run";
			case UnitState::JUMP:
				return "jump";
			default:
				return "undefined_state";
		}
		return "";
	}

	std::unordered_map<UnitState, AnimProperties> GetAnimsFramesAndDelay(const std::string& unit_name);
	size_t GetAnimsFramesCount(const std::string& anim_name);

	std::string BuildAnimationName(const std::string& action) const {
		std::stringstream ss;
		ss << unit_name << '_' << action;
		return ss.str();
	}
};

class GameUnit {
public:
	explicit GameUnit(const std::string& name)
		: unit_name(name)
		, anim_manager(name)
	{ }

	virtual ~GameUnit() {
		//cocos2d::AnimationCache::getInstance()->destroyInstance();
		CC_SAFE_DELETE(sprite);
	}

	virtual cocos2d::Sprite* getSprite() { return sprite; }
	virtual void setSprite(cocos2d::Sprite* s) { sprite = s; }

	virtual void initAnimations();
	virtual void tick(isEvents& events, const float delta) = 0;

protected:
	enum UnitDirection { LEFT, RIGHT };
	enum UnitJumpStatus { FLY, UP, DOWN, ON_LAND };

	cocos2d::Sprite* sprite = nullptr;
	UnitDirection direction = RIGHT;
	UnitState state = UnitState::STAND;
	UnitJumpStatus jump_status = DOWN;
	std::string unit_name;
	AnimationManager anim_manager;

	cocos2d::Animation* CreateAnimation(const UnitState action, const unsigned int loops);
	void updateUnitAnimation();
};

class Cow : public GameUnit {
public:
	explicit Cow(const std::string& name)
		: GameUnit(name)
	{ }

	void tick(isEvents& events, const float delta) override;
};

class Enemy : public GameUnit {
public:
	explicit Enemy(const std::string& name)
		: GameUnit(name)
	{ }

	void tick(isEvents& events, const float delta) override;
};

#endif // GAMEUNIT_H
