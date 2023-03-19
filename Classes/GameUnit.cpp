#include "GameUnit.h"
#include <fstream>
#include <exception>

USING_NS_CC;

std::string UnitStateToString(const UnitState state) {
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

Animation* GameUnit::CreateAnimation(const UnitState action, const unsigned int loops) {
	auto animation = Animation::create();
	auto cow_frame_cache = SpriteFrameCache::getInstance(); // кеш загружен в AppDeligate.cpp ( spritecache->addSpriteFramesWithFile("res/cow/cow_stay_sheet.plist"); )
	anim_manager.SetState(action);
	for (int i = 1; i <= anim_manager.GetNumberOfFrames(); i++) {
		std::stringstream file_name;
		file_name << "./" << anim_manager.GetAnimationName(action) << '_' << i;
		//std::cout << file_name.str() << std::endl;
		animation->addSpriteFrame(cow_frame_cache->getSpriteFrameByName(file_name.str()));
	}
	animation->setDelayPerUnit(anim_manager.GetAnimationDelay());// / 6.0f); // This animation contains 14 frames, will     continuous 2.8 seconds.
	animation->setLoops(loops);
	return animation;
}

void GameUnit::InitAnimations() {
	auto animCache = AnimationCache::getInstance();

	animCache->addAnimation(
				CreateAnimation(UnitState::STAND, CC_REPEAT_FOREVER),
				anim_manager.GetAnimationName(UnitState::STAND)
				);
	animCache->addAnimation(
				CreateAnimation(UnitState::WALK, CC_REPEAT_FOREVER),
				anim_manager.GetAnimationName(UnitState::WALK)
				);
	animCache->addAnimation(
				CreateAnimation(UnitState::RUN, CC_REPEAT_FOREVER),
				anim_manager.GetAnimationName(UnitState::RUN)
				);

	UpdateUnitAnimation();
}

void GameUnit::UpdateUnitAnimation() {
	sprite->stopAllActions();
	auto animCache = AnimationCache::getInstance();
	sprite->runAction(Animate::create(animCache->getAnimation(anim_manager.GetAnimationName(state))));
}

std::unordered_map<UnitState, AnimationManager::AnimProperties> AnimationManager::GetAnimsFramesAndDelay(const std::string& unit_name)
{
	std::unordered_map<UnitState, AnimProperties> result;
	for (size_t i = 0; i < static_cast<size_t>(UnitState::END_STATE); ++i) {
		AnimProperties properties;
		UnitState state = static_cast<UnitState>(i);
		properties.frame_count = GetAnimsFramesCount(GetAnimationName(state));
		//FIXME: пока костыль с задержкой только для коровы
		switch (state) {
			case UnitState::STAND:
				properties.delay = 0.08;
				break;
			case UnitState::WALK:
				properties.delay = 0.07;
				break;
			case UnitState::RUN:
				properties.delay = 0.02;
				break;
			default:
				properties.delay = 0.0;
		}
		result.emplace(std::pair<UnitState, AnimProperties>{state, properties});
		//result[state] = properties;
	}

	std::cout << "AnimProperties for a \"" << unit_name << "\":\n";
	for (const auto& it : result) {
		std::cout << "state = " << UnitStateToString(it.first) << ", prop: count = "
				  << it.second.frame_count << ", delay = " << it.second.delay << std::endl;
	}
	return result;
}

size_t AnimationManager::GetAnimsFramesCount(const std::string& anim_name)
{
	std::string file_name = "res/cow/cow_sprite_sheet.plist";
	file_name = FileUtils::getInstance()->fullPathForFilename(file_name);
	std::ifstream fs(file_name);
	if (!fs.is_open())
		std::cerr << "Can't open " << file_name << std::endl;
	std::string line;
	size_t count = 0;
	//std::cout << "AnimationManager::GetAnimsFramesCount():" << std::endl;
	while (std::getline(fs, line)) {
		size_t pos = line.find(anim_name);
		if (pos != std::string::npos) {
			count++;
			//std::cout << '\"' << anim_name << '\"' << " entry in file: " << file_name << std::endl;
		}

	}
	return count;
}
