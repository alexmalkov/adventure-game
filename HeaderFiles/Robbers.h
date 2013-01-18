////////////////////
/// Advanced C++
/// Adventure Game 2 
/// Malkov/Danchenkov
////////////////////
#ifndef __Robbers_h__
#define __Robbers_h__
#include "GameObject.h"
using namespace std;

class Robbers : public GameObject
{
	private:
		int stealAmount;
	
	public: 
		Robbers(int amount)
		{
			stealAmount = amount;
		}
		virtual ~Robbers(){};
		
		void SetStealAmount(int val)
		{
			stealAmount = val;
		}
		
		int GetStealAmount()
		{
			return stealAmount;
		}
};


#endif
