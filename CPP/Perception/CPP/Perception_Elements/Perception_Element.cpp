#include <Perception_Element.h>

using namespace Perception::Layer::Element;

Perception_Element::Perception_Element() {}

Perception_Element::Perception_Element(float param_value) {
	this->value = this->Limit_Precision(param_value);
}

void Perception_Element::Set_Value(float param_value) {
	this->value = this->Limit_Precision(param_value);
}

float Perception_Element::Get_Value() {
	return this->value;
}


float Perception_Element::Limit_Precision(float param_value_to_limit) {
	float ten = 10;
	float precision_limit_amount = 2;
	float precision_multiplier = pow(ten, precision_limit_amount);
	float step_1 = param_value_to_limit * precision_multiplier;
	int step_2 = floor(step_1);
	float step_3 = step_2 / precision_multiplier;
	return step_3;
}
  
bool Perception_Element::operator==(const Perception_Element element) const {

	int current_whole_number = abs(floor(value));
	float current_difference = abs(value - current_whole_number);

	int incoming_whole_number = abs(floor(value));
	float incoming_difference = abs(value - incoming_whole_number);

	float difference_threshold = 0.0000001f;

	bool should_be_equal = false;

	if (
		(current_difference < difference_threshold)
		&&
		(incoming_difference < difference_threshold)
		&&
		(value == element.value)
		)
	{
	    should_be_equal = true;
	}
	else if (value == element.value)
	{
		should_be_equal = true;
	}
	return should_be_equal;
}

Perception_Element Perception_Element::operator*(const Perception_Element element) const {

	Perception_Element temporary_element;
	temporary_element.Set_Value((value * element.value));
	return  temporary_element;
}

Perception_Element Perception_Element::operator+(const Perception_Element element) const {
	Perception_Element temporary_element;
	temporary_element.Set_Value((value + element.value));
	return  temporary_element;

}


Perception_Element::~Perception_Element() {}

