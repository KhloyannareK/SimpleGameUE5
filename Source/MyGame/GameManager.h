#pragma once

class ALift;

class GameManager
{
public:
	static GameManager* getObject() 
	{
		if (m_ptr) {
			return m_ptr;
		}
		return (m_ptr = new GameManager);
	}

	void incrCocosCount() 
	{
		++m_cocosCount;
		UE_LOG(LogTemp, Warning, TEXT("%d-th cocos incremented"), m_cocosCount);
	}

	void decrCocosCount()
	{
		--m_cocosCount;
		UE_LOG(LogTemp, Warning, TEXT("%d-th cocos decremented"), m_cocosCount);
	}

	bool noCocos() const
	{
		return 0 == m_cocosCount;
	}

	void setLiftPtr(ALift* ptr) {
		m_liftPtr = ptr;
	}

	void switchTheLift() const;
	
	void nullifyCocosCount()
	{
		m_cocosCount = 0;
	}
private:
	int m_cocosCount{0};
	static GameManager* m_ptr;
	ALift* m_liftPtr;
	GameManager() {}
};

