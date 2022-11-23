#include <Input.h>

using namespace Perception::Layer::Element;

/// <summary>
/// Instantiate an empty Input for a Neural Node 
/// </summary>
Input::Input()
{
}

/// <summary>
/// Instantiate an Input for a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_value">float</param>
Input::Input(float param_value)
{
}

/// <summary>
/// Assigns the input a value
/// </summary>
/// <param name="param_value">float</param>
void Input::Set_Value(float param_value) {

}

/// <summary>
/// Gets the input value
/// </summary>
/// <returns></returns>
float Input::Get_Value() {
	return Test_Return_Data;
}

/// <summary>
/// destructor for input object
/// </summary>
Input::~Input()
{
}

