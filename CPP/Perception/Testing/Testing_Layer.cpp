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
    int test_row_count = 4;
    Layer test_layer(test_node_count, test_row_count);
    EXPECT_EQ(test_node_count, test_layer.Get_Node_Count());
}

TEST(Perception_Test, Test_Layer_Weight_Count_From_Constructor) {
    int test_node_count = 3;
    int test_row_count = 4;
    Layer test_layer(test_node_count, test_row_count);
    EXPECT_EQ(test_node_count, test_layer.Get_Weight_Count());
}

/// <summary>
/// Tests the Node count is correct
/// </summary>
TEST(Perception_Test, Test_Layer_Node_Count_From_Method) {
    int test_node_count = 3;
    int test_row_count = 4;
    Layer test_layer(test_node_count, test_row_count);
    test_layer.Initialize_Nodes_By_Count(test_node_count, test_row_count);
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

    Layer test_layer(4, 4);


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

/// <summary>
/// Tests the dot product from the layer
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(Perception_Test, Test_Layer_With_Different_Node_vs_Row_Sizes) {
    Neural_Node node1(1);
    Prediction predict4(4);
    Prediction predict5(5);
    Bias bias1(1);
    Weight weight1(1);


    int node_count = 4;
    int row_count = 3;
    Layer test_layer(node_count, row_count);

    vector<vector<Neural_Node>> test_neural_nodes = {
        {node1, node1, node1, node1},
        {node1, node1, node1, node1},
        {node1, node1, node1, node1}
    };

    vector<vector<Weight>> test_weights = {
        {weight1, weight1, weight1, weight1},
        {weight1, weight1, weight1, weight1},
        {weight1, weight1, weight1, weight1}
    };

    vector<Bias> test_biases = {bias1, bias1, bias1, bias1};

    vector<vector<Prediction>> test_predictions_without_bias = {
        {predict4, predict4, predict4, predict4},
        {predict4, predict4, predict4, predict4},
        {predict4, predict4, predict4, predict4}
    };


    vector<vector<Prediction>> test_predictions_with_bias = {
        {predict5, predict5, predict5, predict5},
        {predict5, predict5, predict5, predict5},
        {predict5, predict5, predict5, predict5}
    };

    test_layer.Dot_Product(test_neural_nodes, test_weights);

 
    EXPECT_EQ(test_layer.Get_Prediction_Without_Bias(), test_predictions_without_bias);

    test_layer.Add_Bias_To_Prediction(test_predictions_without_bias, test_biases);

    EXPECT_EQ(test_layer.Get_Prediction_With_Bias(), test_predictions_with_bias);

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

    Layer test_layer(4 , 4);


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


TEST(Perception_Test, Test_Layer_Activation_By_ReLu_GT_zero) {
    Layer test_layer(4,1);

    float test = float(.2 * 100) / 100;

    Prediction test_predict_20(0.2f);
    Prediction test_predict_30(0.3f);
    Prediction test_predict_40(0.4f);
    Prediction test_predict_50(0.5f);

    Output test_output_30(1.2f);
    Output test_output_40(1.3f);
    Output test_output_50(1.4f);
    Output test_output_60(1.5f);

    Bias bias_1(1.0f);
    vector<vector<Prediction>> test_predictions = {{ test_predict_20, test_predict_30, test_predict_40, test_predict_50 }};
    vector<Bias> test_biases = { bias_1, bias_1, bias_1, bias_1 };
    vector<vector<Output>> output_comparison = { {test_output_30, test_output_40, test_output_50 , test_output_60 } };
    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Nodes();
    vector<vector<Output>> test_outputs = test_layer.Get_Outputs();
    EXPECT_EQ( test_outputs, output_comparison);

}

TEST(Perception_Test, Test_Layer_Overloaded_EQ_Operator) {
    Prediction test_1(.1f);
    Prediction test_2(.1f);
 
    EXPECT_EQ(test_1, test_2);

}


TEST(Perception_Test, Test_Layer_Overloaded_Not_EQ_Operator) {

    Prediction test_3(.1f);
    Prediction test_4(.15f);

     EXPECT_NE(test_3, test_4);
}


TEST(Perception_Test, Test_Layer_Activation_By_ReLu_EQ_zero) {
    Layer test_layer( 4, 1 );
    Prediction test_prediction(-.3f);
    Bias test_bias(-.1f);
    Output test_output(0);

    vector<vector<Prediction>> test_predictions = { { test_prediction, test_prediction, test_prediction,test_prediction} };
    vector<Bias> test_biases = { test_bias, test_bias, test_bias, test_bias };
    vector<vector<Output>> comparison = { {test_output,test_output,test_output,test_output} };
    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Nodes();
    EXPECT_EQ(test_layer.Get_Outputs(), comparison);

}


TEST(Perception_Test, Test_Layer_Activation_By_Sigmoid) {

    float sigmoid_value =  1 / (1 + exp(-.4)) ;

    Layer test_layer(4, 1);
    Prediction test_prediction(.3f);
    Bias test_bias(.1f);
    Output test_output(sigmoid_value);

    vector<vector<Prediction>> test_predictions = { { test_prediction, test_prediction, test_prediction,test_prediction} };
    vector<Bias> test_biases = { test_bias, test_bias, test_bias, test_bias };
    vector<vector<Output>> comparison = { {test_output,test_output,test_output,test_output} };

    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method::Sigmoid);

    vector<vector<Output>> layer_outputs = test_layer.Get_Outputs();

    EXPECT_EQ(layer_outputs, comparison);

}

TEST(Perception_Test, Test_Layer_Activation_By_Softmax) {

    float sum_of_exponents = exp(.4) + exp(.4) + exp(.4) + exp(.4);
    float activated_node_value = exp(.4);
    float comparison_value = (activated_node_value / sum_of_exponents);
    Layer test_layer(4, 1);

    Prediction test_prediction(.3f);
    Bias test_bias(.1f);
    Output test_output(comparison_value);

    vector<vector<Prediction>> test_predictions = { {  test_prediction, test_prediction, test_prediction, test_prediction } };
    vector<Bias> test_biases = { test_bias, test_bias, test_bias, test_bias };

    vector<vector<Output>> comparison = { {comparison_value,comparison_value,comparison_value,comparison_value} };

    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method::Softmax);
    EXPECT_EQ(test_layer.Get_Outputs(), comparison);

}

TEST(Perception_Test, Test_Layer_Activation_By_Softplus) {

    Layer test_layer( 4, 1 );
    Prediction prediction_2(.2f);
    Prediction prediction_3(.3f);
    Prediction prediction_4(.4f);
    Prediction prediction_5(.5f);

    Bias test_bias(.1f);

    vector<vector<Prediction>> test_predictions = { { prediction_2, prediction_3, prediction_4, prediction_5 } };
    vector<Bias> test_biases = { test_bias, test_bias, test_bias, test_bias };


    float test_softplus_value_1 = log(1 + exp(.3));
    float test_softplus_value_2 = log(1 + exp(.4));
    float test_softplus_value_3 = log(1 + exp(.5));
    float test_softplus_value_4 = log(1 + exp(.6));

    Output test_output_1(test_softplus_value_1);
    Output test_output_2(test_softplus_value_2);
    Output test_output_3(test_softplus_value_3);
    Output test_output_4(test_softplus_value_4);
     
    vector<vector<Output>> comparison = { { test_output_1, test_output_2 , test_output_3 , test_output_4 } };

    test_layer.Add_Bias_To_Prediction(test_predictions, test_biases);
    test_layer.Activate_Neural_Nodes_By(Utilities::Neural_Node_Activation_Method::Softplus);
    EXPECT_EQ(test_layer.Get_Outputs(), comparison);

}


TEST(Perception_Test, Test_Layer_ReLu_LT_Zero_Derivative) {
    Layer test_layer(1, 1);
    Output output_2(.2f);
    Derived_Value zero(0);

    vector<vector<Derived_Value>> test_derived_values = { {zero} };
    test_layer.Initialize_Derived_Values();
    test_layer.Calculate_Derivative_Of_ReLu(output_2.Get_Value(), 0, 0);

 }

TEST(Perception_Test, Test_Layer_ReLu_GT_Zero_Derivative) {
    Layer test_layer(1, 1);
    Output output_2(.2f);
    Derived_Value one(1);

    vector<vector<Derived_Value>> test_derived_values = { {one} };
    test_layer.Initialize_Derived_Values();
    test_layer.Calculate_Derivative_Of_ReLu(output_2.Get_Value(), 0, 0);

    vector<vector<Derived_Value>> derived_values_to_compare = test_layer.Get_Derived_Values();


    EXPECT_EQ(derived_values_to_compare, test_derived_values);

}

TEST(Perception_Test, Test_Layer_Sigmoid_Derivative) {
    Layer test_layer(1, 1);
    Output output_2(.2f);
    
    float sigmoid_derivative = exp(output_2.Get_Value()) / pow((exp(output_2.Get_Value()) + 1), 2);

    Derived_Value sigmoid(sigmoid_derivative);


    vector<vector<Derived_Value>> test_derived_values = { {sigmoid} };
    test_layer.Initialize_Derived_Values();
    test_layer.Calculate_Derivative_Of_Sigmoid(output_2.Get_Value(), 0, 0);

    vector<vector<Derived_Value>> derived_values_to_compare = test_layer.Get_Derived_Values();


    EXPECT_EQ(derived_values_to_compare, test_derived_values);

}


TEST(Perception_Test, Test_Layer_Softmax_Derivative) {
    Layer test_layer(1, 1);
    Output output_2(.2f);

    float softmax_derivative = output_2.Get_Value() * (1 - output_2.Get_Value());

    Derived_Value softmax(softmax_derivative);


    vector<vector<Derived_Value>> test_derived_values = { {softmax} };
    test_layer.Initialize_Derived_Values();
    test_layer.Calculate_Derivative_Of_Softmax(output_2.Get_Value(), 0, 0);

    EXPECT_EQ(test_layer.Get_Derived_Values(), test_derived_values);

}

TEST(Perception_Test, Test_Layer_Softplus_Derivative) {
    

    Layer test_layer(1, 1);
    Output output_2(.2f);

    float softplus_derivative = 1 / (1 + exp(-output_2.Get_Value()));

    Derived_Value softplus(softplus_derivative);

    vector<vector<Derived_Value>> test_derived_values = { {softplus} };
    test_layer.Initialize_Derived_Values();
    test_layer.Calculate_Derivative_Of_Softplus(output_2.Get_Value(), 0, 0);

    EXPECT_EQ(test_layer.Get_Derived_Values(), test_derived_values);

}



TEST(Perception_Test, Test_Layer_Learning_Rate_Accuracy) {
    Layer test_layer;

    float test_learning_rate = .1f;

    test_layer.Set_Learning_Rate(test_learning_rate);

    EXPECT_EQ(test_layer.Get_Learning_Rate(), test_learning_rate);
}


TEST(Perception_Test, Test_Layer_Cross_Entropy_Derivative) {

}

 