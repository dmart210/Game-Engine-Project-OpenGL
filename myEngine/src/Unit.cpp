#include "Unit.h"

namespace Engine
{
	Unit::Unit(const std::string& image, int x, int y) :
		mImage(image), mXPos(x), mYPos(y)
	{
	}

	Unit::Unit(std::string&& image, int x, int y) :
		mImage(move(image)), mXPos(x), mYPos(y)
	{
	}

	int Unit::GetWidth() const
	{
		return mImage.GetWidth();
	}

	int Unit::GetHeight() const
	{
		return mImage.GetHeight();
	}

	int Unit::GetXCoord() const
	{
		return mXPos;
	}

	int Unit::GetYCoord() const
	{
		return mYPos;
	}

	void Unit::SetCoords(int x, int y)
	{
		mXPos = x;
		mYPos = y;

	}

	void Unit::UpdateXCoord(int amount)
	{
		mXPos += amount;

	}

	void Unit::UpdateYCoord(int amount)
	{
		mYPos += amount;
	}



	bool UnitsOverlap(const Unit& a, const Unit& b)
	{
		int leftA{ a.mXPos };
		int rightA{ a.mXPos + a.mImage.GetWidth() };
		int leftB{ b.mXPos };
		int rightB{ b.mXPos + b.mImage.GetWidth() };

		bool xIntersection{ (leftA <= leftB and leftB <= rightA) or (leftB <= leftA and leftA <= rightB) };

		int botA{ a.mYPos };
		int topA{ a.mYPos + a.mImage.GetHeight()};
		int botB{ b.mYPos };
		int topB{ a.mYPos + b.mImage.GetHeight()};

		bool yIntersection{ (botA <= botB and botB <= topA) or (botB <= botA and botA <= topB) };

		return xIntersection and yIntersection;

	}

}