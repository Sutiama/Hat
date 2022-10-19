#include "Input.h"
#include <conio.h>

char Input::GetKey()
{
	if (_kbhit())
	{
		char Key;
		Key = _getch();
		return Key;
	}
	else
	{
		return 0;
	}
	
}
