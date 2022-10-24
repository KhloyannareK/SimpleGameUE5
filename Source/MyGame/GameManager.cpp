#include "GameManager.h"
#include "Lift.h"

GameManager* GameManager::m_ptr = nullptr;

void GameManager::switchTheLift() const {
	m_liftPtr->setGoingUp();
}
