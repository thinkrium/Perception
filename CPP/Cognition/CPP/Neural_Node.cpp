#include "Neural_Node.h"

Cognition::Layer::Neural_Node::Neural_Node()
{
}

Cognition::Layer::Neural_Node::Neural_Node(short param_input)
{
	this->input = param_input;
}

void Cognition::Layer::Neural_Node::Set_Input(short param_input) {
	this->input = param_input;
}

short Cognition::Layer::Neural_Node::Get_Input() {
	return this->input;
}

Cognition::Layer::Neural_Node::~Neural_Node()
{
}
