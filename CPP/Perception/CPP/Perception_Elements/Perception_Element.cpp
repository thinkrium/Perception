#include <Perception_Element.h>

using namespace Perception::Layer::Element;

Perception_Element::Perception_Element() {}

Perception_Element::Perception_Element(float param_value) {
	this->value = param_value;
}

void Perception_Element::Set_Value(float param_value) {
	this->value = param_value;
}

float Perception_Element::Get_Value() {
	return this->value;
}

bool Perception_Element::operator==(const Perception_Element element) const {
	return (value == element.value);
}


Perception_Element::~Perception_Element() {}

