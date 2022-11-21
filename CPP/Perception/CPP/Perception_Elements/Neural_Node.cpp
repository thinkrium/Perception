#include "Neural_Node.h"


Perception::Layer::Neural_Node::Neural_Node()
{
}

Perception::Layer::Neural_Node::Neural_Node(float param_input)
{
	this->input = param_input;
}

void Perception::Layer::Neural_Node::Set_Input(float param_input) {
	this->input = param_input;
}


float Perception::Layer::Neural_Node::Get_Input() {
	return this->input;
}

Perception::Layer::Neural_Node::~Neural_Node()
{
}
