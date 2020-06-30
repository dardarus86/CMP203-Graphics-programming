													///////////////////////////////////////////////////////////
													// CODE USED BY JAMIE HADDOW 0705082 FOR CMP203 SKYBOX   //
													///////////////////////////////////////////////////////////
															  //FINISHED // COMMENTED IN .H
// Input class
// Stores current keyboard and mouse state include, pressed keys, mouse button pressed and mouse position.
// @author Paul Robertson

#include "Input.h"


void Input::SetKeyDown(unsigned char key)
{
	keys[key] = true;
}
void Input::SetKeyUp(unsigned char key)
{
	keys[key] = false;
}
void Input::setMouseX(int pos)
{
	mouse.x = pos;
}
void Input::setMouseY(int pos)
{
	mouse.y = pos;
}
void Input::setMousePos(int ix, int iy)
{
	mouse.x = ix;
	mouse.y = iy;
}
void Input::setLeftMouseButton(bool b)
{
	mouse.left = b;
}
bool Input::isKeyDown(int key)
{
	return keys[key];
}
bool Input::isLeftMouseButtonPressed()
{
	return mouse.left;
}
int Input::getMouseX()
{
	return mouse.x;
}
int Input::getMouseY()
{
	return mouse.y;
}



