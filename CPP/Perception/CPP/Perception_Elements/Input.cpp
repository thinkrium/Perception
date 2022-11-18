#include <Input.h>

/// <summary>
/// Instantiate an empty Input for a Neural Node 
/// </summary>
Perception::Layer::Input::Input()
{
}

/// <summary>
/// Instantiate an Input for a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_value">Short</param>
Perception::Layer::Input::Input(short param_value)
{
}

/// <summary>
/// Assigns the input a value
/// </summary>
/// <param name="param_value">Short</param>
void Perception::Layer::Input::Set_Value(short param_value) {

}

/// <summary>
/// Gets the input value
/// </summary>
/// <returns></returns>
short Perception::Layer::Input::Get_Value() {
	return Test_Return_Data;
}

/// <summary>
/// destructor for input object
/// </summary>
Perception::Layer::Input::~Input()
{
}

