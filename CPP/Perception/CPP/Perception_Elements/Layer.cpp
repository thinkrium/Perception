#include <Layer.h>


/// <summary>
/// Creates an Empty Layer of Neural Nodes
/// </summary>
Perception::Layer::Layer::Layer()
{
}


/// <summary>
/// Creates an Layer of Neural Nodes by the count of param_node_count
/// </summary>
Perception::Layer::Layer::Layer(int param_node_count) {
    this->Neural_Node_Count = param_node_count;
}

/// <summary>
/// Sets the node count
/// </summary>
/// <param name="param_node_count"></param>
void Perception::Layer::Layer::Set_Node_Count(int param_node_count) { 
    this->Neural_Node_Count = param_node_count;
}

int Perception::Layer::Layer::Get_Node_Count() {
    return this->Neural_Node_Count;
}

/// <summary>
/// Creates the all new nodes for this layer
/// </summary>
void Perception::Layer::Layer::Create_Layer_Nodes() {
    this->Create_Nodes_By_Count();
}

/// <summary>
/// Creates the all new nodes for this layer by the size of the previously defined
/// node count
/// </summary>
void Perception::Layer::Layer::Create_Nodes_By_Count() {
    for (int index = 0; index < this->Neural_Node_Count; index++) {
        Neural_Nodes.push_back(
            this->Generate_Random_Numerical_Value()
        );
    }
}


/// <summary>
/// Creates the all new nodes for this layer by the size of the param_node_count
/// </summary>
void Perception::Layer::Layer::Create_Nodes_By_Count(int param_node_count) {
    for (int index = 0; index < param_node_count; index++) {
        Neural_Nodes.push_back(
            this->Generate_Random_Numerical_Value()
        );
    }
}

/// <summary>
/// Generates a random number between -1 and 1 from the hardware
/// </summary>
/// <returns>random short value between -1 and 1</returns>
short Perception::Layer::Layer::Generate_Random_Numerical_Value() {
    
    random_device random_generator; // obtain a random number from hardware
    
    mt19937 generator(random_generator()); // seed the generator
    
    uniform_int_distribution<> distributor(-100, 100);

    return distributor(generator) / 100;
}


/// <summary>
/// Destructor
/// </summary>
Perception::Layer::Layer::~Layer()
{
}


