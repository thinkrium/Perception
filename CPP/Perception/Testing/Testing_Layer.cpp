#include <gtest/gtest.h>

#include <Layer.h>


using namespace Perception::Layer::Element;
//Perception_Test

/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_Layer_Node_Count_From_Constructor) {
    int test_node_count = 3;
    Layer test_layer(test_node_count);  
    EXPECT_EQ(test_node_count, test_layer.Get_Node_Count());
}

/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_Layer_Node_Count_From_Method) {
    int test_node_count = 3;
    Layer test_layer;
    test_layer.Initialize_Nodes_By_Count(3);
    EXPECT_EQ(test_node_count, test_layer.Get_Node_Count());
}

/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_Setting_Node_Count_By_Method) {
    int test_node_count = 3;
    Layer test_layer;
    test_layer.Set_Node_Count(3);
    EXPECT_EQ(test_node_count, test_layer.Get_Node_Count());
}

/// <summary>
/// Tests the random value generator
/// </summary>
TEST(Perception_Test, Test_Random_Value_In_Range) {
    Layer test_layer;
    float test_random_value = test_layer.Generate_Random_Numerical_Value();
    EXPECT_TRUE(((test_random_value >= -1) && (test_random_value <= 1))) << " by the value of " << test_random_value;
}

/// <summary>
/// Tests the dot product from the layer
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(Perception_Test, Test_Layer_Dot_Product) {
    Layer test_layer;
    vector<float> test_inputs = { 1,2,3,4 };
    vector<float> test_weights = { 1,2,3,4 };

//    EXPECT_EQ(test_layer.Dot_Product(test_inputs, test_weights), 39);
}