#include "Neural_Node.h"

using namespace Perception::Layer::Element;

Neural_Node::Neural_Node()
{
}

Neural_Node::Neural_Node(float param_input)
{
	this->input.Set_Value(param_input);
}

void Neural_Node::Set_Input(float param_input) {
	this->input.Set_Value(param_input);
}


Input Neural_Node::Get_Input() {
	return this->input.Get_Value();
}

Neural_Node::~Neural_Node()
{
}
