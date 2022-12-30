#include <gtest/gtest.h>
#include <Layer.h>


using namespace Perception::Layer::Element;
//Perception_Test

//<summary>
 //Tests the Node count is correct
 //</summary>
TEST(Perception_Test, Test_The_Node_Value_Setters_And_Getters_By_Constructor) {

    float test_node_value = 4;
    Neural_Node test_node(test_node_value);
    EXPECT_EQ(test_node_value, test_node.Get_Value());
}

/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_The_Node_Value_Setters_And_Getters_By_Method) {

    float test_node_value = 4;
    Neural_Node test_node;
    test_node.Set_Value(test_node_value);
    EXPECT_EQ(test_node_value, test_node.Get_Value());
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
    Neural_Node node1(1);
    Neural_Node node2(2);
    Neural_Node node3(3);
    Neural_Node node4(4);

    Weight weight1(1);
    Weight weight2(2);
    Weight weight3(3);
    Weight weight4(4);

    Prediction prediction30(30);

    Layer test_layer(4);


    vector<vector<Neural_Node>> test_inputs = { 
        { node1, node2, node3, node4 },
        { node1, node2, node3, node4 },
        { node1, node2, node3, node4 },
        { node1, node2, node3, node4 }
    };

    vector<vector<Weight>> test_weights = {
        {weight1,weight2,weight3,weight4},
        {weight1,weight2,weight3,weight4},
        {weight1,weight2,weight3,weight4},
        {weight1,weight2,weight3,weight4}
    };

    vector<vector<Prediction>> comparison = { 
        {prediction30, prediction30, prediction30, prediction30},
        {prediction30, prediction30, prediction30, prediction30},
        {prediction30, prediction30, prediction30, prediction30},
        {prediction30, prediction30, prediction30, prediction30}
    };


    test_layer.Dot_Product(test_inputs, test_weights);
    
    vector<vector<Prediction>> prediction_without_bias =
                         test_layer.Get_Prediction_Without_Bias();

     
    EXPECT_EQ(prediction_without_bias, comparison);
}

TEST(Perception_Test, Test_Layer_Prediction_with_bias) {
    Neural_Node node1(1);
    Neural_Node node2(2);
    Neural_Node node3(3);
    Neural_Node node4(4);

    Weight weight1(1);
    Weight weight2(2);
    Weight weight3(3);
    Weight weight4(4);

    Prediction prediction30(30);
    Prediction prediction31(31);

    Bias bias1(1);

    Layer test_layer(4);


    vector<vector<Neural_Node>> test_inputs = {
        { node1, node2, node3, node4 },
        { node1, node2, node3, node4 },
        { node1, node2, node3, node4 },
        { node1, node2, node3, node4 }
    };

    vector<vector<Weight>> test_weights = {
        {weight1,weight2,weight3,weight4},
        {weight1,weight2,weight3,weight4},
        {weight1,weight2,weight3,weight4},
        {weight1,weight2,weight3,weight4}
    };

    vector<Bias> test_biases = { bias1, bias1, bias1, bias1 };

    vector<vector<Prediction>> test_predictions = {
        {prediction30, prediction30, prediction30, prediction30},
        {prediction30, prediction30, prediction30, prediction30},
        {prediction30, prediction30, prediction30, prediction30},
        {prediction30, prediction30, prediction30, prediction30}
    };


    vector<vector<Prediction>> comparison = {
        {prediction31, prediction31, prediction31, prediction31},
        {prediction31, prediction31, prediction31, prediction31},
        {prediction31, prediction31, prediction31, prediction31},
        {prediction31, prediction31, prediction31, prediction31}
    };

    
    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    
    vector<vector<Prediction>> predictions_with_bias = test_layer.Get_Prediction_With_Bias();

    EXPECT_EQ(test_layer.Get_Prediction_With_Bias(), comparison);

}

//
//TEST(Perception_Test, Test_Layer_Activation_By_ReLu_GT_zero) {
//    Layer test_layer(4);
//    Prediction test_predict_20(.20);
//    Prediction test_predict_30(.30);
//    Prediction test_predict_40(.40);
//    Prediction test_predict_50(.50);
//    Prediction test_predict_60(.60);
//
//
//    Bias bias_1(1);
//    vector<vector<Prediction>> test_predictions = {{ test_predict_20, test_predict_30, test_predict_40, test_predict_50 }};
//    vector<Bias> test_biases = { bias_1, bias_1, bias_1, bias_1 };
//    vector<Prediction> comparison = { test_predict_30, test_predict_40, test_predict_50 , test_predict_60 };
//    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
//    test_layer.Activate_Neural_Nodes();
//    //EXPECT_EQ(test_layer.Get_Outputs(), comparison);
//
//}
////
////TEST(Perception_Test, Test_Layer_Activation_By_ReLu_EQ_zero) {
////    Layer test_layer(4);
////    vector<vector<float>> test_predictions = { { -.30, -.30, -.30, -.30 } };
////    vector<float> test_biases = { -.1, -.1, -.1, -.1 };
////    vector<float> comparison = { 0, 0, 0, 0 };
////    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
////    test_layer.Activate_Neural_Nodes();
////    EXPECT_EQ(test_layer.Get_Outputs(), comparison);
////
////}
////
////
////TEST(Perception_Test, Test_Layer_Activation_By_Sigmoid) {
////
////    float sigmoid_value =  1 / (1 + exp(-.4)) ;
////    Layer test_layer(4);
////    vector<vector<float>> test_predictions = { { .30, .30, .30, .30 } };
////    vector<float> test_biases = { .1, .1, .1, .1 };
////
////    vector<float> comparison = { sigmoid_value, sigmoid_value, sigmoid_value, sigmoid_value };
////    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
////    test_layer.Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method::Sigmoid);
////    EXPECT_EQ(test_layer.Get_Outputs(), comparison);
////
////}
////
////TEST(Perception_Test, Test_Layer_Activation_By_Softmax) {
////
////    float sum_of_exponents = exp(.4) + exp(.4) + exp(.4) + exp(.4);
////    float activated_node_value1 = exp(.4);
////    float activated_node_value2 = exp(.4);
////    float activated_node_value3 = exp(.4);
////    float activated_node_value4 = exp(.4);
////    Layer test_layer(4);
////    vector<vector<float>> test_predictions = { {  .3, .3, .3, .3 } };
////    vector<float> test_biases = { .1, .1, .1, .1 };
////
////    vector<float> comparison = { 
////        (activated_node_value1 / sum_of_exponents), 
////        (activated_node_value2 / sum_of_exponents),
////        (activated_node_value3 / sum_of_exponents),
////        (activated_node_value4 / sum_of_exponents)
////    };
////    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
////    test_layer.Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method::Softmax);
////    EXPECT_EQ(test_layer.Get_Outputs(), comparison);
////
////}
////
////TEST(Perception_Test, Test_Layer_Activation_By_Softplus) {
////
////    Layer test_layer(4);
////    vector<vector<float>> test_predictions = { { .2, .3, .4, .5 } };
////    vector<float> test_biases = { .1, .1, .1, .1 };
////
////    float test_softplus_value_1 = log(1 + exp(.3));
////    float test_softplus_value_2 = log(1 + exp(.4));
////    float test_softplus_value_3 = log(1 + exp(.5));
////    float test_softplus_value_4 = log(1 + exp(.6));
////
////    vector<float> comparison = { test_softplus_value_1, test_softplus_value_2 , test_softplus_value_3 , test_softplus_value_4 };
////
////    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
////    test_layer.Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method::Softplus);
////    EXPECT_EQ(test_layer.Get_Outputs(), comparison);
////
////}
////
////
////TEST(Perception_Test, Test_Layer_Forward_Pass) {
////    Layer test_layer(4);
////    vector<vector<float>> test_predictions = { { .30, .30, .30, .30 } };
////    vector<float> test_biases = { .1, .1, .1, .1 };
////    vector<float> comparison = { .4, .4, .4, .4 };
////    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
////    test_layer.Activate_Neural_Nodes();
////    EXPECT_EQ(test_layer.Get_Outputs(), comparison);
////
////}
////
////
////TEST(Perception_Test, Test_Output_Loss) {
////    Layer test_layer(4);
////    vector<vector<float>> test_predictions = { { .30, .30, .30, .30 } };
////    vector<float> test_biases = { .1, .1, .1, .1 };
////    vector<int> test_expected_results = { 0, 1, 0, 0 };
////    vector<float> comparison = { .4, .4, .4, .4 };
////
////    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
////    test_layer.Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method::Softmax);
////    test_layer.Set_Expected_Results(test_expected_results);
////    EXPECT_EQ(test_layer.Get_Outputs(), comparison);
////
////    test_layer.Calculate_Loss();
////    EXPECT_EQ(test_layer.Get_Losses(), comparison);
////
////}
//
// 