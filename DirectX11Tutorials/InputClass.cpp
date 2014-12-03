
#include "InputClass.h"

InputClass::InputClass()
{

}

InputClass::InputClass(const InputClass& other)
{

}

InputClass::~InputClass()
{

}

void InputClass::Initialize()
{
	int i;

	for (i = 0; i < 256; i++)
	{
		_keys[i] = false;
	}

	return;
}

void InputClass::KeyDown(unsigned int input)
{
	_keys[input] = true;
	return;
}

void InputClass::KeyUp(unsigned int input)
{
	_keys[input] = false;
	return;
}

bool InputClass::IsKeyDown(unsigned int key)
{
	return _keys[key];
}