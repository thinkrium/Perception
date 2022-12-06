#include <gtest/gtest.h>
#include <Layer.h>


using namespace Perception::Layer::Element;
//Perception_Test

/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_The_Node_Value_Setters_And_Getters_By_Constructor) {

    float test_node_value = 4;
    Neural_Node test_node(test_node_value);
    EXPECT_EQ(test_node_value, test_node.Get_Input().Get_Value());
}

/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_The_Node_Value_Setters_And_Getters_By_Method) {

    float test_node_value = 4;
    Neural_Node test_node;
    test_node.Set_Input(test_node_value);
    EXPECT_EQ(test_node_value, test_node.Get_Input().Get_Value());
}

/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_Layer_Node_Count_From_Constructor) {
    int test_node_count = 3;
    Layer test_layer(test_node_count);
    EXPECT_EQ(test_node_count, test_layer.Get_Node_Count());
}

TEST(Perception_Test, Test_Layer_Weight_Count_From_Constructor) {
    int test_node_count = 3;
    Layer test_layer(test_node_count);
    EXPECT_EQ(test_node_count, test_layer.Get_Weight_Count());
}


/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_Layer_Node_Count_From_Method) {
    int test_node_count = 3;
    Layer test_layer(test_node_count);
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
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_Setting_Weight_Count_By_Method) {
    int test_node_count = 3;
    Layer test_layer;
    test_layer.Set_Weight_Count(3);
    EXPECT_EQ(test_node_count, test_layer.Get_Weight_Count());
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
TEST(Perception_Test, Test_Layer_Prediction_without_bias) {
    Layer test_layer;
    Neural_Node node1(1);
    Neural_Node node2(2);
    Neural_Node node3(3);
    Neural_Node node4(4);
    vector<Neural_Node> test_inputs = { node1, node2, node3, node4 };
    vector<vector<float>> test_weights = {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
    };

    vector<float> comparison = { 30, 30, 30, 30 };
    test_layer.Dot_Product(test_inputs, test_weights);
    EXPECT_EQ(test_layer.Get_Prediction_Without_Bias(), comparison);

}

TEST(Perception_Test, Test_Layer_Prediction_with_bias) {
    Layer test_layer;
    vector<float> test_predictions = { 30, 30, 30, 30 };
    vector<float> test_biases = { 1, 1, 1, 1 };
    vector<float> comparison = { 31, 31, 31, 31 };
    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    EXPECT_EQ(test_layer.Get_Prediction_With_Bias(), comparison);

}


TEST(Perception_Test, Test_Layer_Activation_By_ReLu_GT_zero) {
    Layer test_layer(4);
    vector<float> test_predictions = { .30, .30, .30, .30 };
    vector<float> test_biases = { .1, .1, .1, .1 };
    vector<float> comparison = { .4, .4, .4, .4 };
    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Nodes();
    EXPECT_EQ(test_layer.Get_Outputs(), comparison);

}

TEST(Perception_Test, Test_Layer_Activation_By_ReLu_EQ_zero) {
    Layer test_layer(4);
    vector<float> test_predictions = { -.30, -.30, -.30, -.30 };
    vector<float> test_biases = { -.1, -.1, -.1, -.1 };
    vector<float> comparison = { 0, 0, 0, 0 };
    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Nodes();
    EXPECT_EQ(test_layer.Get_Outputs(), comparison);

}


TEST(Perception_Test, Test_Layer_Activation_By_Sigmoid) {

    float sigmoid_value =  1 / (1 + exp(-.4)) ;
    Layer test_layer(4);
    vector<float> test_predictions = { .30, .30, .30, .30 };
    vector<float> test_biases = { .1, .1, .1, .1 };

    vector<float> comparison = { sigmoid_value, sigmoid_value, sigmoid_value, sigmoid_value };
    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Node_By(Utilities::Neural_Node_Activation_Method::Sigmoid);
    EXPECT_EQ(test_layer.Get_Outputs(), comparison);

}


TEST(Perception_Test, Test_Layer_Forward_Pass) {
    Layer test_layer(4);
    vector<float> test_predictions = { .30, .30, .30, .30 };
    vector<float> test_biases = { .1, .1, .1, .1 };
    vector<float> comparison = { .4, .4, .4, .4 };
    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Nodes();
    EXPECT_EQ(test_layer.Get_Outputs(), comparison);

}