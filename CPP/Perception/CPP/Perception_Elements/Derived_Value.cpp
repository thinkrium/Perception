#include <Derived_Value.h>

using namespace Perception::Layer::Element;
/// <summary>
/// Instantiate an empty Input for a Neural Node 
/// </summary>
Derived_Value::Derived_Value()
{
}

/// <summary>
/// Instantiate an Input for a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_value">float</param>
Derived_Value::Derived_Value(float param_value) : Perception_Element(param_value)
{
}



/// <summary>
/// destructor for input object
/// </summary>
Derived_Value::~Derived_Value()
{
}

