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
/// <param name="param_input">float</param>
Perception::Layer::Neural_Node::Neural_Node(float param_input)
{
	this->input = param_input;
}

/// <summary>
/// Instantiate a Neural Node and assigns it a value for input
/// </summary>
/// <param name="param_input">float</param>
/// <param name="param_weight">float</param>
Perception::Layer::Neural_Node::Neural_Node(float param_input, float param_weight)
{
	this->input = param_input;
	this->weight = param_weight;
}


/// <summary>
/// Sets the input value of a Neural Node
/// </summary>
/// <param name="param_input">float</param>
void Perception::Layer::Neural_Node::Set_Input(float param_input) {
	this->input = param_input;
}

/// <summary>
/// Gets the input value of the Neural Node
/// </summary>
/// <returns>float value of input from Neural Node</returns>
float Perception::Layer::Neural_Node::Get_Input() {
	return this->input;
}

/// <summary>
/// Sets the input value of a Neural Node
/// </summary>
/// <param name="param_weight">float</param>
void Perception::Layer::Neural_Node::Set_Weight(float param_weight) {
	this->weight = param_weight;
}

/// <summary>
/// Gets the Weight value of the Neural Node
/// </summary>
/// <returns>float value of weight from Neural Node</returns>
float Perception::Layer::Neural_Node::Get_Weight() {
	return this->weight;
}

/// <summary>
/// Sets the Bias value of a Neural Node
/// </summary>
/// <param name="param_bias">float</param>
void Perception::Layer::Neural_Node::Set_Bias(float param_bias) {

}

/// <summary>
/// Gets the Bias value of the Neural Node
/// </summary>
/// <returns>float value of bias from Neural Node</returns>
float Perception::Layer::Neural_Node::Get_Bias() {

}


Perception::Layer::Neural_Node::~Neural_Node()
{
}
