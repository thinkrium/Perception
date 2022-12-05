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
    this->Set_Node_Count (param_node_count);
    this->Set_Weight_Count(param_node_count);
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

vector<float> Layer::Get_Neural_Nodes_Values() {
    vector<float> node_values;

    for (int node_value_index = 0; node_value_index < this->Get_Node_Count(); node_value_index++) {
        node_values.push_back(this->neuralNodes[node_value_index].Get_Input().Get_Value());
    }

    return node_values;
}

void Layer::Set_Weight_Count(int param_node_count) {
    this->weightCount = param_node_count;
}

int Layer::Get_Weight_Count() {
    return this->weightCount;
}

vector<vector<float>> Layer::Get_Weights() {
    return this->weights;
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
    // create a temp matrix of weights to avoid the new * operator and protect memory
    vector<vector<float>> weight_matrix(this->neuralNodeCount, std::vector<float>(this->neuralNodeCount, 0));

    this->weights = weight_matrix;

    for (int node_index = 0; node_index < this->neuralNodeCount; node_index++) {
        this->weights[node_index] = vector<float>(this->neuralNodeCount);
        for (int weight_index = 0; weight_index < this->weightCount; weight_index++) {
             this->weights[node_index][weight_index] = this->Generate_Random_Numerical_Value();
        }
    }
}

void Layer::Initialize_Weights_By_Count(int param_node_count) {
    // create a temp matrix of weights to avoid the new * operator and protect memory
    vector<vector<float>> weight_matrix(this->neuralNodeCount, std::vector<float>(this->neuralNodeCount, 0));

    this->weights = weight_matrix;

    for (int node_index = 0; node_index < this->neuralNodeCount; node_index++) {
        for (int weight_index = 0; weight_index < this->weightCount; weight_index++) {
            weights[node_index][weight_index] = this->Generate_Random_Numerical_Value();
        }
    }
}

void Layer::Initialize_Bias( ) {
    for (int node_index = 0; node_index < this->neuralNodeCount; node_index++) {

        this->biases.push_back(this->Generate_Random_Numerical_Value());
    }
}

vector<float> Layer::Get_Biases() {
    return this->biases;
}

vector<float> Layer::Get_Outputs() {
    return this->outputs;
}

float Layer::Generate_Random_Numerical_Value() {
    
    random_device random_generator; // obtain a random number from hardware
    
    mt19937 generator(random_generator()); // seed the generator
    
    uniform_int_distribution<> distributor(-100, 100);

    float random_number = distributor(generator) ;

    random_number /= 100;

    return random_number;
}
void Layer::Dot_Product(vector<Neural_Node> param_inputs, vector<vector<float>> param_weights) {
    vector<float> result_matrix;
    float results = 0;

    for (int weight_row_index = 0; weight_row_index < param_weights.size(); weight_row_index++) {
         for (int neural_node_index = 0; neural_node_index < param_inputs.size(); neural_node_index++) {

                results += param_inputs[neural_node_index].Get_Input().Get_Value() * param_weights[weight_row_index][neural_node_index];
                 
          }
         this->predictions.push_back(results);
         results = 0;
  
     }
}

vector<float> Layer::Get_Prediction_Without_Bias() {
    return this->predictions;
}

vector<float> Layer::Get_Prediction_With_Bias() {
    return this->predictions_with_bias;
}

void Layer::Add_Bias_To_Prediction(vector<float> param_prediction, vector<float> param_biases) {
    for (int node_index = 0; node_index < param_prediction.size(); node_index++) {
        float prediction_with_bias = param_prediction[node_index] + param_biases[node_index];
        this->predictions_with_bias.push_back(prediction_with_bias);
    }
}

// able to call this method and defaults to ReLu for now 
// 11-26-2022
void Layer::Activate_Neural_Nodes() {
    this->Activate_Neural_Node_By(Neural_Node_Activation_Method::ReLu);
}

// allows you to call the method with an explicit method
void Layer::Activate_Neural_Node_By(Utilities::Neural_Node_Activation_Method param_method) {
     for (int output_index = 0; output_index < this->Get_Outputs().size(); output_index++) {
        if (param_method == Neural_Node_Activation_Method::ReLu) {
            this->Activate_Neural_Node_By_ReLu(this->neuralNodes[output_index]);
        }
        else if (param_method == Neural_Node_Activation_Method::Sigmoid) {
            this->Activate_Neural_Node_By_Sigmoid(this->neuralNodes[output_index]);
        }
     }
}


void Layer::Activate_Neural_Node_By_ReLu(Neural_Node& param_current_node) {
    if (param_current_node.Get_Input().Get_Value() <= 0) {
        param_current_node.Set_Input(0);
    }
}

void Layer::Activate_Neural_Node_By_Sigmoid(Neural_Node& param_current_node) {

    float current_sigmoid_value = (1 / (1 + exp(-param_current_node.Get_Input().Get_Value())));

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
    float loss = -log(param_current_node.Get_Input().Get_Value());
    losses.push_back(loss);
}



vector<float> Layer::Feed_Forward_Pass() {

    //this->Dot_Product(this->neuralNodes, this->weights);
    //this->Add_Bias_To_Prediction(
    //    this->predictions,
    //    this->biases
    //);
    //this->Activate_Neural_Nodes();

    return this->Get_Outputs();
}
 
Layer::~Layer()
{
}


