#include <Weight.h>

using namespace Perception::Layer::Element;
/// <summary>
/// Instantiate an empty Input for a Neural Node 
/// </summary>
Weight::Weight()
{
}

/// <summary>
/// Instantiate an Input for a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_value">float</param>
Weight::Weight(float param_value)
{
}

/// <summary>
/// Assigns the input a value
/// </summary>
/// <param name="param_value">float</param>
void Weight::Set_Value(float param_value) {

}

/// <summary>
/// Gets the input value
/// </summary>
/// <returns></returns>
float Weight::Get_Value() {
	return Test_Return_Data;
}

/// <summary>
/// destructor for input object
/// </summary>
Weight::~Weight()
{
}

