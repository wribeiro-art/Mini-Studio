
#include <SFML/Window/Event.hpp>

class Controller
{
private :

public:
	int mID;

	Controller(int ID);
	
	bool IsConnected(int ID);
	int ReturnPressedButton(int ID);
	float ReturnJoystickValueX();
	float ReturnJoystickValueY();

};
