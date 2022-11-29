#include <Layer.h>
// tempoorary test for random # generation value
#include <iostream>
#include <cmath>

using namespace std;
using namespace Perception::Layer::Element;

Layer::Layer()
{
}


Layer::Layer(int param_node_count) {
    this->neuralNodeCount = param_node_count;
    this->Initialize_Layer_Nodes();
    this->Initialize_Layer_Weights();
    this->Initialize_Bias();
}

void Layer::Set_Node_Count(int param_node_count) { 
    this->neuralNodeCount = param_node_count;
}

int Layer::Get_Node_Count() {
    return this->neuralNodeCount;
}

vector<Neural_Node> Layer::Get_Neural_Nodes() {
    return this->neuralNodes;
}

vector<float> Layer::Get_Weights() {
    return this->weights;
}

float Layer::Get_Bias() {
    return this->bias;
}

void Layer::Initialize_Layer_Nodes() {
    this->Initialize_Nodes_By_Count();
}

void Layer::Initialize_Layer_Weights() {
    this->Initialize_Weights_By_Count();
}


void Layer::Initialize_Nodes_By_Count() {
    for (int index = 0; index < this->neuralNodeCount; index++) {
        neuralNodes.push_back(
            Neural_Node(
                this->Generate_Random_Numerical_Value() // input 
            )
        );
    }
}
 
void Layer::Initialize_Nodes_By_Count(int param_node_count) {
    for (int index = 0; index < param_node_count; index++) {
        neuralNodes.push_back(
            Neural_Node(
                this->Generate_Random_Numerical_Value() // input value
            )
        );
    }
}

void Layer::Initialize_Weights_By_Count() {
    for (int index = 0; index < this->neuralNodeCount; index++) {
        weights.push_back(
            this->Generate_Random_Numerical_Value()
        );
    }
}

void Layer::Initialize_Weights_By_Count(int param_node_count) {
    for (int index = 0; index < param_node_count; index++) {
        weights.push_back(            
            this->Generate_Random_Numerical_Value()   
        );
    }
}

void Layer::Initialize_Bias( ) {
    this->bias = this->Generate_Random_Numerical_Value();
}

float Layer::Generate_Random_Numerical_Value() {
    
    random_device random_generator; // obtain a random number from hardware
    
    mt19937 generator(random_generator()); // seed the generator
    
    uniform_int_distribution<> distributor(-100, 100);

    float random_number = distributor(generator) ;

    random_number /= 100;

    return random_number;
}

float Layer::Dot_Product(vector<Neural_Node> param_inputs, vector<float> param_weights) {
    float results = 0;
    for (int index = 0; index < param_inputs.size(); index++) {
        results += param_inputs[index].Get_Input() * param_weights[index];
    }

    return results;
}

float Layer::Add_Bias_To_Prediction(float param_prediction) {
    return param_prediction + this->bias;
}

// able to call this method and defaults to ReLu for now 
// 11-26-2022
void Layer::Activate_Neural_Nodes() {
    this->Activate_Neural_Node_By(Neural_Node_Activation_Method::ReLu);
}

// allows you to call the method with an explicit method
void Layer::Activate_Neural_Node_By(Utilities::Neural_Node_Activation_Method param_method) {
    for (int index = 0; index < this->Get_Node_Count(); index++) {
        if (param_method == Neural_Node_Activation_Method::ReLu) {
            this->Activate_Neural_Node_By_ReLu(this->neuralNodes[index]);
        }
        else if (param_method == Neural_Node_Activation_Method::Sigmoid) {
            this->Activate_Neural_Node_By_Sigmoid(this->neuralNodes[index]);
        }
    }
}


void Layer::Activate_Neural_Node_By_ReLu(Neural_Node& param_current_node) {
    if (param_current_node.Get_Input() <= 0) {
        param_current_node.Set_Input(0);
    }
}

void Layer::Activate_Neural_Node_By_Sigmoid(Neural_Node& param_current_node) {

    float current_sigmoid_value = (1 / (1 + exp(-param_current_node.Get_Input())));

    param_current_node.Set_Input(current_sigmoid_value);
  
}

void Layer::Calculate_Loss() {
        this->Calculate_Loss_By(Loss_Calculation_Method::CrossEntropy);
}
     

void Layer::Calculate_Loss_By(Utilities::Loss_Calculation_Method param_method) {
    for (int index = 0; index < this->Get_Node_Count(); index++) {
        if (param_method == Utilities::Loss_Calculation_Method::CrossEntropy) {
            this->Calculate_Loss_By_Cross_Entropy(this->neuralNodes[index], index);
        }
    }
}

void Layer::Calculate_Loss_By_Cross_Entropy(Neural_Node& param_current_node, int param_index) {
    float loss = -log(param_current_node.Get_Input());
    losses.push_back(loss);
}



float Layer::Feed_Forward_Pass() {
    float prediction = this->Add_Bias_To_Prediction(
        this->Dot_Product(this->neuralNodes, this->weights));
    return Test_Return_Data;
}
 
Layer::~Layer()
{
}


