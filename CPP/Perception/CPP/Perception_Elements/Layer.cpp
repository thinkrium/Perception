#include <Layer.h>
// tempoorary test for random # generation value
#include <iostream>

using namespace std;
using namespace Perception::Layer::Element;

Layer::Layer()
{
}


Layer::Layer(int param_node_count) {
    this->neuralNodeCount = param_node_count;
    this->Create_Layer_Nodes();
    this->Create_Layer_Weights();
}

void Layer::Set_Node_Count(int param_node_count) { 
    this->neuralNodeCount = param_node_count;
}

int Layer::Get_Node_Count() {
    return this->neuralNodeCount;
}

void Layer::Create_Layer_Nodes() {
    this->Create_Nodes_By_Count();
}

void Layer::Create_Layer_Weights() {
    this->Create_Weights_By_Count();
}


void Layer::Create_Nodes_By_Count() {
    for (int index = 0; index < this->neuralNodeCount; index++) {
        neuralNodes.push_back(
            Neural_Node(
                this->Generate_Random_Numerical_Value() // input 
            )
        );
    }
}
 
void Layer::Create_Nodes_By_Count(int param_node_count) {
    for (int index = 0; index < param_node_count; index++) {
        neuralNodes.push_back(
            Neural_Node(
                this->Generate_Random_Numerical_Value() // input value
            )
        );
    }
}

void Layer::Create_Weights_By_Count() {
    for (int index = 0; index < this->neuralNodeCount; index++) {
        weights.push_back(
            this->Generate_Random_Numerical_Value()
        );
    }
}

void Layer::Create_Weights_By_Count(int param_node_count) {
    for (int index = 0; index < param_node_count; index++) {
        weights.push_back(            
            this->Generate_Random_Numerical_Value()   
        );
    }
}

float Layer::Generate_Random_Numerical_Value() {
    
    random_device random_generator; // obtain a random number from hardware
    
    mt19937 generator(random_generator()); // seed the generator
    
    uniform_int_distribution<> distributor(-100, 100);

    float random_number = distributor(generator) ;

    random_number /= 100;

    return random_number;
}

float Layer::Dot_Product(vector<Input> inputs, vector<Weight> weights) {
    float results = 0;
    for (int index = 0; index < inputs.size(); index++) {
        results += inputs[index].Get_Value() * weights[index].Get_Value();
    }

    return results;
}

float Layer::Feed_Forward_Pass() {

     return Test_Return_Data;
}
 
Layer::~Layer()
{
}


