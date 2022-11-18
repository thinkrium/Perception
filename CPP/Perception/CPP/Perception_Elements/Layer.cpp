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

void Perception::Layer::Layer::Create_Layer_Nodes() {
    this->Create_Nodes_By_Count();
}

void Perception::Layer::Layer::Create_Nodes_By_Count() {
    Neural_Nodes.push_back(
        this->Generate_Random_Numerical_Value()
    );
}


void Perception::Layer::Layer::Create_Nodes_By_Count(int param_node_count) {

}


short Perception::Layer::Layer::Generate_Random_Numerical_Value() {
    return Test_Return_Data;
}


/// <summary>
/// Destructor
/// </summary>
Perception::Layer::Layer::~Layer()
{
}


