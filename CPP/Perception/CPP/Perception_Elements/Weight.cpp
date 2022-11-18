#include <Weight.h>

/// <summary>
/// Instantiate an empty Input for a Neural Node 
/// </summary>
Perception::Layer::Weight::Weight()
{
}

/// <summary>
/// Instantiate an Input for a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_value">float</param>
Perception::Layer::Weight::Weight(float param_value)
{
}

/// <summary>
/// Assigns the input a value
/// </summary>
/// <param name="param_value">float</param>
void Perception::Layer::Weight::Set_Value(float param_value) {

}

/// <summary>
/// Gets the input value
/// </summary>
/// <returns></returns>
float Perception::Layer::Weight::Get_Value() {
	return Test_Return_Data;
}

/// <summary>
/// destructor for input object
/// </summary>
Perception::Layer::Weight::~Weight()
{
}

