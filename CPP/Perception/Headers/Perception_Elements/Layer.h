#ifndef LAYER_H
#define LAYER_H

#include <Perception_Element.h>
#include <Neural_Node.h>
#include <vector>
#include <random>
#include <Enums.h>

using namespace Utilities;
using namespace std;

namespace Perception {
    namespace Layer {
		namespace Element {

			class Layer : public Perception_Element
			{
				public:

					/*************************************************************************************************************
					 *************************************************************************************************************
					   NOTE: 
					         THERE ARE AS MANY WEIGHT COLUMNS AS THERE ARE OUTPUTS FROM THE PREVIOUS LAYER TO THE CURRENT LAYER
							 THERE ARE AS MANY WEIGHT ROWS AS THERE ARE NODES IN THE CURRENT LAYER

                             AND EACH CURRENT LAYERS INPUT HAS ITS OWN WEIGHT FROM THE PREVIOUS LAYER

							 SO
							 L = LAYER
							 I = INPUT
							 W = WEIGHT
							 B = BIAS
							 O = OUTPUT
							 N = NODE

							 THERE IS 1 BIAS PER NODE SO THE PREVIOUS LAYER IS MULTIPLIED AND ADDED AND THEN BROUGHT IN AS INPUT TO
							 THE CURRENT NODE WHICH HAS A BIAS TO ITS RELIABILITY.

							 ALL THIS LAYERS INPUTS AND WEIGHTS ARE MULTIPLIED AND A BIAS IS ADDED TO THAT FOR EACH OUTPUT TO
							 THE NEXT LAYERS INPUT
					 *************************************************************************************************************
					 **************************************************************************************************************/


					 /*
					   Initializes an Empty Layer without any Neural Nodes
					 */
					Layer();

					/*
					  Initializes an Layer of Neural Nodes by the count of param_node_count
					*/
					Layer(int param_node_count);

					/*
					  Sets the node count
					  param name="param_node_count"
					*/
					void Set_Node_Count(int param_node_count);

					/*
					   Initializes the all new nodes for this layer and initializes their value with random number between -1 and 1
					*/
					int Get_Node_Count();

					/*
					    Gets the list of neural nodes for the layer
					*/
					vector<Neural_Node> Get_Neural_Nodes();

					/*
						Gets the list of neural nodes for the layer
					*/
					vector<float> Get_Neural_Nodes_Values();

					/*
					* Sets the weight count for the incoming weights
					*/
					void Set_Weight_Count(int param_node_count);

					/*
					   Initializes the all new nodes for this layer and initializes their value with random number between -1 and 1
					*/
					int Get_Weight_Count();

					/*
					   Gets the list of weights for the layer
					*/
					vector<vector<float>> Get_Weights();

					/*
					  Gets the bias for the layer
					*/
					vector<float> Get_Biases();

					/*
					   Initializes the all new nodes for this layer by the size of the previously defined
					   node count
					   and initializes their value with random number between -1 and 1
					*/
					void Initialize_Layer_Nodes();

					/*
					   Initializes the all new nodes for this layer by the size of the previously defined
					   node count
					   and initializes their value with random number between -1 and 1
					*/
					void Initialize_Layer_Weights();

					/*
						Initializes the all new nodes for this layer by the size of the internal objects node_count
						and initializes their value with random number between -1 and 1
					*/
					void Initialize_Nodes_By_Count();

					/*
						Initializes the all new nodes for this layer by the size of the param_node_count
						and initializes their value with random number between -1 and 1
					*/
					void Initialize_Nodes_By_Count(int param_node_count);

					/*
					Initializes the all new weights for this layer by the size of the internal objects node_count
					and initializes their value with random number between -1 and 1
					*/
					void Initialize_Weights_By_Count();

					/*
					Initializes the all new weights for this layer by the size of the internal objects node_count
					and initializes their value with random number between -1 and 1
					*/
					void Initialize_Weights_By_Count(int param_node_count);
					/*

					  Generates a random number between -1 and 1 from the hardware

					  returns random float value between -1 and 1
					*/

					/*
					* Initializes the bias of the output
					*/
					void Initialize_Bias( );

					/*
					* Sets the size of the inputs and initializes the values to 0
					*/
					void Initialize_Outputs();

					/*
					 * Gets The outputs from the current layer 
					 */
					vector<float> Get_Outputs();

					/*
					*  Initializes the losslayer to the size of node count to
					*  an initial value of negativ 1 so that it can be iteratedt
					*  through later by index
					*/
					void Initialize_Losses();

					/*
					*  Returns the losses created in the final layer
					*/
					vector<float> Get_Losses();

					/*
					 Generates a random real number between -1 and 1
					*/
					float Generate_Random_Numerical_Value();

					/*
					   Performs a Dot product operation on the incoming weights and parameters
					*/
					void Dot_Product(vector<Neural_Node> param_inputs, vector<vector<float>> param_weights);

					/*
					* returns the prediction without the bias
					*/
					vector<float> Get_Prediction_Without_Bias();

					/*
					 * returns the prediction with the bias
					 */
					vector<float> Get_Prediction_With_Bias();

					/*
					* Determines the trust of the prediction by adding abias to the prediction
					*/
					void Add_Bias_To_Prediction(vector<float> param_prediction, vector<float> param_biases);

					/*
					  Activates the current node, defaults to Rectified Linear Unit 
					*/
					void Activate_Neural_Nodes();

					/*
					* Iterates through the layers nodes predictions and adds to gether the values of the
					* nodes value
					*/
					void Set_Layers_Exponential_Sum();
					/*
					  Activates the current node by a specifict activation method 
					  overloaded jsut sending method
					*/
					void Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method  param_method);
					 
					/*
					  Activates the current node by a specific by Rectified Linear Unit
					*/
					void Activate_Neural_Node_By_ReLu(float param_prediction_with_bias, float param_prediction_index);

					/*
					  Activates the current node by a Sigmoid
					*/
					void Activate_Neural_Node_By_Sigmoid(float param_prediction_with_bias, float param_prediction_index);

					/*
                      Activates the current node by a Sigmoid
                    */
					void Activate_Neural_Node_By_Softmax(float param_prediction_with_bias, float param_prediction_index);

					/*
					Calculating Loss for each Node
					cant happen without predicted value
					*/
					void Calculate_Loss();

					/*
					Calculating Loss for each Node with method option
					cant happen without predicted value
					*/
					void Calculate_Loss_By(Utilities::Loss_Calculation_Method param_method);

					/*
					Calculating Loss for each Node with method option and overloaded neural_node
					cant happen without predicted value
					*/
					void Calculate_Loss_By_Cross_Entropy(float param_output, int param_index);

					/*
					  Passes the full matrix multiplacation value of the this layer to the
					  next
					*/
					vector<float> Feed_Forward_Pass();

					/*Destructor*/
					~Layer();

				private:

					/*
					   The number of Neural Nodes in this layer
					*/
					int neuralNodeCount;

					/*
					  The Vector/list of Neural Nodes
					*/
					vector<Neural_Node> neuralNodes;

					/*
					   The number of Weights in this layer
					*/
					int weightCount;

					/*
					  The Vector/list of weights {prediction importance} is the weighted value of each of
					  the previous llayers predictions for each current node
					*/
					vector<vector<float>> weights;
					
					/*
					   The preditions without bias
					*/
					vector<float> predictions;

					/*
					   The preditions with bias
					*/
					vector<float> predictions_with_bias;

					/*
					*  The exponential sum of the layers predictions
					*/
					float prediction_with_bias_exponential_sum;

					/*
					  the vector/list of losses on the output layer
					*/
					vector<float> losses;

					/*
					  The bias of the predictoin
					*/
					vector<float> biases;

					/*
					* The outputs after prediction, bias, and activation
					*/
					vector<float> outputs;

			};
		}
    }
}

#endif // !LAYER_H
