#include "Engine.h"

bool Engine::ItemCollision(Rect<float> playerRect)
{
	list<Rect<float>>::iterator fruitIter = m_fruitMap.begin();
	list<Rect<float>>::iterator dotsIter = m_dotsMap.begin();
	while (dotsIter != m_dotsMap.end()) {
		if (dotsIter->intersects(playerRect)) {
			//cout << "DOT COLLISION!" << endl;
			dotsIter = m_dotsMap.erase(dotsIter);
			currentScore += 1;
		}
		else {
			++dotsIter;
		}
	}
	while (fruitIter != m_fruitMap.end()) {
		if (fruitIter->intersects(playerRect)) {
			//cout << "FRUIT COLLISION!" << endl;
			fruitIter = m_fruitMap.erase(fruitIter);
			currentScore += 4;
		}
		else {
			++fruitIter;
		}
	}
	if (m_dotsMap.size() <=5)
	{
		//m_level++;
		reset();
		return true;
	}
	return false;
}
