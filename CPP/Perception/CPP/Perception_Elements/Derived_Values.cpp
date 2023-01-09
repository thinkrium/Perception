#include <Derived_Values.h>

using namespace Perception::Layer::Element;
/// <summary>
/// Instantiate an empty Input for a Neural Node 
/// </summary>
Derived_Values::Derived_Values()
{
}

/// <summary>
/// Instantiate an Input for a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_value">float</param>
Derived_Values::Derived_Values(float param_value) : Perception_Element(param_value)
{
}



/// <summary>
/// destructor for input object
/// </summary>
Derived_Values::~Derived_Values()
{
}

