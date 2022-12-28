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
    this->Initialize_Predictions();
    this->Initialize_Predictions_With_Biases();
    this->Initialize_Outputs();
    this->Initialize_Losses();
}

void Layer::Set_Node_Count(int param_node_count) {
    this->neuralNodeCount = param_node_count;
}

int Layer::Get_Node_Count() {
    return this->neuralNodeCount;
}

vector<vector<Neural_Node>> Layer::Get_Neural_Nodes() {
    return this->neuralNodes;
}

vector<vector<float>> Layer::Get_Neural_Nodes_Values() {
    vector<vector<float>> node_values;

    for (int node_value_row_index = 0; node_value_row_index < this->Get_Node_Count(); node_value_row_index++) {
        for (int node_value_column_index = 0; node_value_column_index < this->Get_Node_Count(); node_value_column_index++) {

            node_values[node_value_row_index][node_value_column_index] =  
                this->neuralNodes[node_value_row_index][node_value_column_index].Get_Value();
        }
    }

    return node_values;
}

void Layer::Set_Weight_Count(int param_node_count) {
    this->weightCount = param_node_count;
}

int Layer::Get_Weight_Count() {
    return this->weightCount;
}

vector<vector<Weight>> Layer::Get_Weights() {
    return this->weights;
}
 
void Layer::Initialize_Layer_Nodes() {
    this->Initialize_Nodes_By_Count();
}

void Layer::Initialize_Layer_Weights() {
    this->Initialize_Weights_By_Count();
}


void Layer::Initialize_Nodes_By_Count() {

    this->neuralNodes.resize(this->Get_Node_Count());

    for (int row_index = 0; row_index < this->neuralNodeCount; row_index++) {
        for (int column_index = 0; column_index < this->neuralNodeCount; column_index++) {
            this->Get_Neural_Nodes()[row_index].push_back(
                Neural_Node(this->Generate_Random_Numerical_Value())
            ); // input value

        }
    }

}
 
void Layer::Initialize_Nodes_By_Count(int param_node_count) {

    this->neuralNodes.resize(this->Get_Node_Count());

    for (int row_index = 0; row_index < param_node_count; row_index++) {
        for (int column_index = 0; column_index < param_node_count; column_index++) {
            this->Get_Neural_Nodes()[row_index].push_back(  
                 Neural_Node(this->Generate_Random_Numerical_Value())
             ); // input value
  
        }
    }
}

void Layer::Initialize_Weights_By_Count() {
    // create a temp matrix of weights to avoid the new * operator and protect memory
    vector<vector<Weight>> weight_matrix(this->neuralNodeCount, std::vector<Weight>(this->neuralNodeCount, 0));

    this->weights = weight_matrix;

    for (int node_index = 0; node_index < this->neuralNodeCount; node_index++) {
        this->weights[node_index] = vector<Weight>(this->neuralNodeCount);
        for (int weight_index = 0; weight_index < this->weightCount; weight_index++) {
             this->weights[node_index][weight_index] = this->Generate_Random_Numerical_Value();
        }
    }
}

void Layer::Initialize_Weights_By_Count(int param_node_count) {
    // create a temp matrix of weights to avoid the new * operator and protect memory
    vector<vector<Weight>> weight_matrix(this->neuralNodeCount, std::vector<Weight>(this->neuralNodeCount, 0));

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

void Layer::Initialize_Predictions() {
    this->Initialize_Predictions_By_Count(this->Get_Node_Count());

}

void Layer::Initialize_Predictions_By_Count(int param_node_count) {
    vector<vector<Prediction>> prediction_matrix(param_node_count, vector<Prediction>(param_node_count, 0));

    this->predictions = prediction_matrix;

}

void Layer::Initialize_Predictions_With_Biases() {
    this->Initialize_Predictions_With_Biases_By_Count(this->Get_Node_Count());

}

void Layer::Initialize_Predictions_With_Biases_By_Count(int param_node_count) {
    vector<vector<Prediction>> prediction_matrix(param_node_count, vector<Prediction>(param_node_count, 0));

    this->predictions_with_bias = prediction_matrix;

}


void Layer::Initialize_Outputs() {
    this->Initialize_Outputs_By_Count(this->Get_Node_Count());
}

void Layer::Initialize_Outputs_By_Count(int param_node_count) {
    vector<vector<Output>> ouptut_matrix(param_node_count, vector<Output>(param_node_count, 0));

    this->outputs = ouptut_matrix;

}

vector<Bias> Layer::Get_Biases() {
    return this->biases;
}

vector<vector<Output>> Layer::Get_Outputs() {
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

void Layer::Dot_Product(vector<vector<Neural_Node>> param_inputs, vector<vector<float>> param_weights) {
    float results = 0;

    // iterate through the inputs rows to get the row index for the inputs and the outputs matrix
    for (int neural_node_row_index = 0; neural_node_row_index < param_inputs.size(); neural_node_row_index++) {
            // iterate through the inputs columns to get the column index for the input and the output matrix
            for (int result_matrix_index = 0; result_matrix_index < param_inputs[neural_node_row_index].size(); result_matrix_index++) {
                // iterate through the inputs columns to get the column index for the output matrix
                for (int neural_node_column_index = 0; neural_node_column_index < param_inputs[neural_node_row_index].size(); neural_node_column_index++) {


                    /*
                      {    INPUT             {     OUTPUT            {        RESULT
                          {1, 2, 3, 4 }          {1, 2, 3, 4 }               {(INROW0, OUTROW0), (INROW0, OUTROW1), (INROW0, OUTROW2)}
                          {1, 2, 3, 4 }          {1, 2, 3, 4 }               {(INROW1, OUTROW0), (INROW1, OUTROW1), (INROW1, OUTROW2)}
                          {1, 2, 3, 4 }          {1, 2, 3, 4 }               {(INROW2, OUTROW0), (INROW2, OUTROW1), (INROW2, OUTROW2)}
                      }                      }                       }
                    */


                results +=
                    param_inputs[neural_node_row_index][neural_node_column_index].Get_Value()
                    *
                    param_weights[neural_node_row_index][neural_node_column_index];
            }
            this->predictions[neural_node_row_index][result_matrix_index] = results;
            results = 0;

        }
     }
}

vector<vector<Prediction>> Layer::Get_Prediction_Without_Bias() {
    return this->predictions;
}

vector<vector<Prediction>> Layer::Get_Prediction_With_Bias() {
    return this->predictions_with_bias;
}

void Layer::Add_Bias_To_Prediction(vector<vector<float>> param_prediction, vector<float> param_biases) {
    for (int node_row_index = 0; node_row_index < param_prediction.size(); node_row_index++) {
        for (int node_column_index = 0; node_column_index < param_prediction[node_row_index].size(); node_column_index++) {
            float prediction_with_bias = param_prediction[node_row_index][node_column_index] + param_biases[node_column_index];
            this->predictions_with_bias[node_row_index][node_column_index] = prediction_with_bias ;
        }
    }
}

void Layer::Set_Layers_Exponential_Sum() {
    this->prediction_with_bias_exponential_sum = 0;
    for (int exponential_sum_row_index = 0; exponential_sum_row_index < this->Get_Prediction_With_Bias().size(); exponential_sum_row_index++) {
        for (int exponential_sum_column_index = 0; exponential_sum_column_index < this->Get_Prediction_With_Bias()[exponential_sum_row_index].size(); exponential_sum_column_index++) {
            this->prediction_with_bias_exponential_sum += exp(this->Get_Prediction_With_Bias()[exponential_sum_row_index][exponential_sum_column_index].Get_Value());
        }
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

    for (int output_row_index = 0; output_row_index < this->Get_Prediction_With_Bias().size(); output_row_index++) {
        for (int output_column_index = 0; output_column_index < this->Get_Prediction_With_Bias()[output_row_index].size(); output_column_index++) {
            if (param_method == Neural_Node_Activation_Method::ReLu) {
                this->Activate_Neural_Node_By_ReLu(this->Get_Prediction_With_Bias()[output_row_index][output_column_index].Get_Value(), output_row_index, output_column_index);
            }
            else if (param_method == Neural_Node_Activation_Method::Sigmoid) {
                this->Activate_Neural_Node_By_Sigmoid(this->Get_Prediction_With_Bias()[output_row_index][output_column_index].Get_Value(), output_row_index, output_column_index);
            }
            else if (param_method == Neural_Node_Activation_Method::Softmax) {
                this->Activate_Neural_Node_By_Softmax(this->Get_Prediction_With_Bias()[output_row_index][output_column_index].Get_Value(), output_row_index, output_column_index);
            }
            else if (param_method == Neural_Node_Activation_Method::Softplus) {
                this->Activate_Neural_Node_By_Softplus(this->Get_Prediction_With_Bias()[output_row_index][output_column_index].Get_Value(), output_row_index, output_column_index);
            }
        }
     }
}


void Layer::Activate_Neural_Node_By_ReLu(float param_prediction_with_bias, float param_prediction_row_index, float param_prediction_column_index) {
    if ( this->Get_Prediction_With_Bias()[param_prediction_row_index][param_prediction_column_index].Get_Value() <= 0) {
        this->outputs[param_prediction_row_index][param_prediction_column_index] = 0 ;
    }
    else {
        this->outputs[param_prediction_row_index][param_prediction_column_index] = param_prediction_with_bias;
    }
}

void Layer::Activate_Neural_Node_By_Sigmoid(float param_prediction_with_bias, float param_prediction_row_index, float param_prediction_column_index) {

    float current_sigmoid_value = (1 / (1 + exp(-this->Get_Prediction_With_Bias()[param_prediction_row_index][param_prediction_column_index].Get_Value())));

    this->outputs[param_prediction_row_index][param_prediction_column_index] = current_sigmoid_value;
}

void Layer::Activate_Neural_Node_By_Softmax(float param_prediction_with_bias, float param_prediction_row_index, float param_prediction_column_index) {

    float normalized_exponential_sum = exp(this->Get_Prediction_With_Bias()[param_prediction_row_index][param_prediction_column_index].Get_Value()) / this->prediction_with_bias_exponential_sum;

    this->outputs[param_prediction_row_index][param_prediction_column_index] = normalized_exponential_sum;
}

void Layer::Activate_Neural_Node_By_Softplus(float param_prediction_with_bias, float param_prediction_row_index, float param_prediction_column_index) {
    float current_softplus_value = log(1 + exp(param_prediction_with_bias));

    this->outputs[param_prediction_row_index][param_prediction_column_index] = current_softplus_value;
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

    for (int losses_row_index = 0; losses_row_index < this->outputs.size(); losses_row_index++) {
        for (int losses_column_index = 0; losses_column_index < this->outputs[losses_row_index].size(); losses_column_index ++) {
            if (this->Get_Expected_Results()[losses_row_index] == 1) {
                if (param_method == Utilities::Loss_Calculation_Method::CrossEntropy) {
                    this->Calculate_Loss_By_Cross_Entropy(this->Clip_Output_For_Negative_Log_Loss(this->outputs[losses_row_index][losses_column_index].Get_Value()), losses_row_index);
                }
            }
        }
    }
}

void Layer::Calculate_Loss_By_Cross_Entropy(float param_output, int param_index) {

    float loss = -log(param_output);
    this->losses[param_index] = loss;
}


vector<vector<Output>> Layer::Feed_Forward_Pass() {

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


