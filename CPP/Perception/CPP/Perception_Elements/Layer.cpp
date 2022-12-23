#include <Layer.h>
#include <cmath>
#include <Perception_Logger.h>

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
    this->Initialize_Outputs();
    this->Initialize_Losses();
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

void Layer::Initialize_Outputs() {
    this->outputs = vector<float>(this->Get_Node_Count(), 0);
}

vector<float> Layer::Get_Biases() {
    return this->biases;
}

vector<float> Layer::Get_Outputs() {
    return this->outputs;
}

vector<float> Layer::Get_Losses() {
    return this->losses;
}

void Layer::Initialize_Losses() {
    this->losses = vector<float>(this->Get_Node_Count(), -1);
}

float Layer::Generate_Random_Numerical_Value() {
    
    random_device random_generator; // obtain a random number from hardware
    
    mt19937 generator(random_generator()); // seed the generator
    
    uniform_int_distribution<> distributor(-100, 100);

    float random_number = distributor(generator) ;

    random_number /= 100;
     
    return this->Limit_Precision(random_number); 
}

float Layer::Limit_Precision(float param_value_to_limit) {
    float ten = 10;
    float precision_limit_amount = 2;
    float precision_multiplier = pow(ten, precision_limit_amount);
    float step_1 = param_value_to_limit * precision_multiplier;
    int step_2   = floor(step_1);
    float step_3 = step_2 / precision_multiplier;
    return step_3;
}

void Layer::Dot_Product(vector<Neural_Node> param_inputs, vector<vector<float>> param_weights) {
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

void Layer::Set_Layers_Exponential_Sum() {
    this->prediction_with_bias_exponential_sum = 0;
    for (int exponential_sum_index = 0; exponential_sum_index < this->Get_Prediction_With_Bias().size(); exponential_sum_index++) {
        this->prediction_with_bias_exponential_sum += exp(this->Get_Prediction_With_Bias()[exponential_sum_index]);
    }
}

// able to call this method and defaults to ReLu for now 
// 11-26-2022
void Layer::Activate_Neural_Nodes() {
    this->Activate_Neural_Nodes_By(Neural_Node_Activation_Method::ReLu);
}

// allows you to call the method with an explicit method
void Layer::Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method param_method) {
    if (param_method == Neural_Node_Activation_Method::Softmax) {
         this->Set_Layers_Exponential_Sum();
     }

     for (int output_index = 0; output_index < this->Get_Prediction_With_Bias().size(); output_index++) {
        if (param_method == Neural_Node_Activation_Method::ReLu) {
            this->Activate_Neural_Node_By_ReLu(this->Get_Prediction_With_Bias()[output_index], output_index);
        }
        else if (param_method == Neural_Node_Activation_Method::Sigmoid) {
            this->Activate_Neural_Node_By_Sigmoid(this->Get_Prediction_With_Bias()[output_index], output_index);
        }
        else if (param_method == Neural_Node_Activation_Method::Softmax) {
            this->Activate_Neural_Node_By_Softmax(this->Get_Prediction_With_Bias()[output_index], output_index);
        }
        else if (param_method == Neural_Node_Activation_Method::Softplus) {
            this->Activate_Neural_Node_By_Softplus(this->Get_Prediction_With_Bias()[output_index], output_index);
        }
     }
}


void Layer::Activate_Neural_Node_By_ReLu(float param_prediction_with_bias, float param_prediction_index) {
    if ( this->Get_Prediction_With_Bias()[param_prediction_index] <= 0) {
        this->outputs[param_prediction_index] = 0 ;
    }
    else {
        this->outputs[param_prediction_index] = param_prediction_with_bias;
    }
}

void Layer::Activate_Neural_Node_By_Sigmoid(float param_prediction_with_bias, float param_prediction_index) {

    float current_sigmoid_value = (1 / (1 + exp(-this->Get_Prediction_With_Bias()[param_prediction_index])));

    this->outputs[param_prediction_index] = current_sigmoid_value;
}

void Layer::Activate_Neural_Node_By_Softmax(float param_prediction_with_bias, float param_prediction_index) {

    float normalized_exponential_sum = exp(this->Get_Prediction_With_Bias()[param_prediction_index]) / this->prediction_with_bias_exponential_sum;

    this->outputs[param_prediction_index] = normalized_exponential_sum;
}

void Layer::Activate_Neural_Node_By_Softplus(float param_prediction_with_bias, float param_prediction_index) {
    float current_softplus_value = log(1 + exp(param_prediction_with_bias));

    this->outputs[param_prediction_index] = current_softplus_value;
}

void Layer::Set_Expected_Results(vector<int> param_expected_results) {
    this->expected_results = param_expected_results;
}

vector<int> Layer::Get_Expected_Results() {
    return this->expected_results;
}

float Layer::Clip_Output_For_Negative_Log_Loss(float param_output) {
    float output_lowest_value = 0.0000001;
    float output_highest_value = 1 - output_lowest_value;

    if (param_output < output_lowest_value) {
        return output_lowest_value;
    }
    else if (param_output > output_highest_value) {
        return output_highest_value;
    }
    else {
        return param_output;
    }
}

void Layer::Calculate_Loss() {
        this->Calculate_Loss_By(Loss_Calculation_Method::CrossEntropy);
}
     

void Layer::Calculate_Loss_By(Utilities::Loss_Calculation_Method param_method) {
    if (this->Get_Expected_Results().size() == 0) {
        logger.Error("There are no expected results to compare losses against");
        return;
    }

    for (int losses_index = 0; losses_index < this->outputs.size(); losses_index++) {
        if (this->Get_Expected_Results()[losses_index] == 1) {
            if (param_method == Utilities::Loss_Calculation_Method::CrossEntropy) {
                this->Calculate_Loss_By_Cross_Entropy(this->Clip_Output_For_Negative_Log_Loss(this->outputs[losses_index]), losses_index);
            }
        }
    }
}

void Layer::Calculate_Loss_By_Cross_Entropy(float param_output, int param_index) {

    float loss = -log(param_output);
    this->losses[param_index] = loss;
}


vector<float> Layer::Feed_Forward_Pass() {

    this->Dot_Product(this->neuralNodes, this->weights);
    this->Add_Bias_To_Prediction(
        this->predictions,
        this->biases
    );
    this->Activate_Neural_Nodes();

    return this->Get_Outputs();
}
 
Layer::~Layer()
{
}


