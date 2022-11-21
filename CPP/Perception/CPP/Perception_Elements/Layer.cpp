#include <Layer.h>
// tempoorary test for random # generation value
#include <iostream>

using namespace std;

Perception::Layer::Layer::Layer()
{
}


Perception::Layer::Layer::Layer(int param_node_count) {
    this->neuralNodeCount = param_node_count;
    this->Create_Layer_Nodes();
}

void Perception::Layer::Layer::Set_Node_Count(int param_node_count) { 
    this->neuralNodeCount = param_node_count;
}

int Perception::Layer::Layer::Get_Node_Count() {
    return this->neuralNodeCount;
}

void Perception::Layer::Layer::Create_Layer_Nodes() {
    this->Create_Nodes_By_Count();
}

void Perception::Layer::Layer::Create_Nodes_By_Count() {
    for (int index = 0; index < this->neuralNodeCount; index++) {
        neuralNodes.push_back(
            Neural_Node(
                this->Generate_Random_Numerical_Value() // input 
            )
        );
    }
}
 
void Perception::Layer::Layer::Create_Nodes_By_Count(int param_node_count) {
    for (int index = 0; index < param_node_count; index++) {
        neuralNodes.push_back(
            Neural_Node(
                this->Generate_Random_Numerical_Value() // input value
            )
        );
    }
}

float Perception::Layer::Layer::Generate_Random_Numerical_Value() {
    
    random_device random_generator; // obtain a random number from hardware
    
    mt19937 generator(random_generator()); // seed the generator
    
    uniform_int_distribution<> distributor(-100, 100);

    float random_number = distributor(generator) ;

    random_number /= 100;

    return random_number;
}

float Perception::Layer::Layer::Feed_Forward_Pass() {
    return Test_Return_Data;
}
 
Perception::Layer::Layer::~Layer()
{
}


