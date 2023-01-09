#include <Expected_Results.h>

using namespace Perception::Layer::Element;
/// <summary>
/// Instantiate an empty Input for a Neural Node 
/// </summary>
Expected_Results::Expected_Results()
{
}

/// <summary>
/// Instantiate an Input for a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_value">float</param>
Expected_Results::Expected_Results(float param_value) : Perception_Element(param_value)
{
}



/// <summary>
/// destructor for input object
/// </summary>
Expected_Results::~Expected_Results()
{
}

