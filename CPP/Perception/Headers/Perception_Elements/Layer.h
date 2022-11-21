#ifndef LAYER_H
#define LAYER_H

#include <Root.h>
#include <Neural_Node.h>
#include <vector>
#include <random>

using namespace Utilities;
using namespace std;

namespace Perception {
    namespace Layer {
		class Layer
		{
			public:

				/************************************************************************************************************* 
				 ************************************************************************************************************* 
				   NOTE: THERE ARE AS MANY WEIGHTS AS THERE ARE INPUTS IN A LAYER SO THE SIZE OF THE NEURAL NODE VECTOR
				         SHOULD BE THE SAME


						 AND FOR EACH OUTPUT OF THE WHOLE LAYER THERE SHOULD BE 1 BIAS.

						 ALL THIS LAYERS INPUTS AND WEIGHTS ARE MULTIPLIED AND A BIAS IS ADDED TO THAT FOR EACH OUTPUT TO
						 THE NEXT LAYERS INPUT
				 ************************************************************************************************************* 
				 **************************************************************************************************************/


				/*
				  Creates an Empty Layer without any Neural Nodes
				*/
				Layer();
				
				/*
				  Creates an Layer of Neural Nodes by the count of param_node_count
				*/
				Layer(int param_node_count);

				/*
                  Sets the node count
				  param name="param_node_count"
                */
				void Set_Node_Count(int param_node_count);

				/*
				   Creates the all new nodes for this layer and initializes their value with random number between -1 and 1
				*/
				int Get_Node_Count();

				/*
				   Creates the all new nodes for this layer by the size of the previously defined
				   node count
				   and initializes their value with random number between -1 and 1
				*/
				void Create_Layer_Nodes();

				/*
					Creates the all new nodes for this layer by the size of the internal objects node_count
					and initializes their value with random number between -1 and 1
				*/
				void Create_Nodes_By_Count();

				/*
					Creates the all new nodes for this layer by the size of the param_node_count
					and initializes their value with random number between -1 and 1
				*/
				void Create_Nodes_By_Count(int param_node_count);

				/*

				  Generates a random number between -1 and 1 from the hardware

				  returns random float value between -1 and 1
				*/

				float Generate_Random_Numerical_Value();

				/*
				  Passes the full matrix multiplacation value of the this layer to the
				  next 
				*/
				float Feed_Forward_Pass();
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
				  The Vector/list of weights
				*/
				vector<float> weights;

				/*
				  The Vector/list of biases
				*/
				vector<Neural_Node> biases;

			};    
    }
}

#endif // !LAYER_H
