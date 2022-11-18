#include "Neural_Node.h"

/// <summary>
/// Instantiates an empty Neural Node which can be populated with
/// content later
/// </summary>
Perception::Layer::Neural_Node::Neural_Node()
{
}

/// <summary>
/// Instantiate a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_input">Short</param>
Perception::Layer::Neural_Node::Neural_Node(short param_input)
{
	this->input = param_input;
}

/// <summary>
/// Instantiate a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_input">Short</param>
/// <param name="param_weight">Short</param>
Perception::Layer::Neural_Node::Neural_Node(short param_input, short param_weight)
{
	this->input = param_input;
	this->weight = param_weight;
}


/// <summary>
/// Sets the input value of a Neural Node
/// </summary>
/// <param name="param_input">short</param>
void Perception::Layer::Neural_Node::Set_Input(short param_input) {
	this->input = param_input;
}

/// <summary>
/// Gets the input value of the Neural Node
/// </summary>
/// <returns>short value of input from Neural Node</returns>
short Perception::Layer::Neural_Node::Get_Input() {
	return this->input;
}

/// <summary>
/// Sets the input value of a Neural Node
/// </summary>
/// <param name="param_weight">short</param>
void Perception::Layer::Neural_Node::Set_Weight(short param_weight) {
	this->weight = param_weight;
}

/// <summary>
/// Gets the Weight value of the Neural Node
/// </summary>
/// <returns>short value of weight from Neural Node</returns>
short Perception::Layer::Neural_Node::Get_Weight() {
	return this->weight;
}

Perception::Layer::Neural_Node::~Neural_Node()
{
}
