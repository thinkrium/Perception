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
Weight::Weight(float param_value) : Perception_Element(param_value)
{
}



/// <summary>
/// destructor for input object
/// </summary>
Weight::~Weight()
{
}

