package CognitionMap;

import CognitionMap.Elements.Bias;
import CognitionMap.Elements.Cognition_Element;
import CognitionMap.Elements.Neural_Node;
import CognitionMap.Elements.Weight;
import CognitionMap.Math.Math;
import Utilities.Enums;

import java.util.Random;

public class Layer {

    private Neural_Node[][] inputs;

    private Neural_Node[][] outputs;

    private Weight[][] weights;

    private Bias [] biases;

    private int neuron_count;

    private int input_count;

    /**
     * The constructor initiiates the layer of neurons and weights
     * For every neuron there is a bias
     *
     * For every output there is a weight
     *
     * Each of the previous layers neuron is an input to the current layer
     * except for the 1st layer which is the raw data as a batch
     *
     *
     * @param input_count the out put of the previaus layer's neuron
     * @param neuron_count the number of neurons
     */
    public Layer(int input_count, int neuron_count) {


        this.input_count = input_count;
        this.neuron_count = neuron_count;
        this.weights = new Weight[neuron_count][input_count];
        this.biases = new Bias[neuron_count];

        Define_Weights_Initial_Value();
        Define_Biases_Initial_Value();
    }

    public void Define_Biases_Initial_Value() {
        for(int bias_index = 0; bias_index < this.neuron_count; bias_index++) {
            this.biases[bias_index] = new Bias(0);
        }
    }
    public void Define_Weights_Initial_Value(  ) {
        Random random = new Random();

        for( int neuron_index = 0; neuron_index < this.neuron_count; neuron_index++ ) {
            for( int input_index = 0; input_index < this.input_count; input_index++ ) {
                this.weights[neuron_index][input_index] = new Weight(random.nextFloat());
            }
        }
    }
    public void Set_Activation_Values_By_Method(Enums.Layer_Activation_Method activation_method) {

        if(activation_method == Enums.Layer_Activation_Method.ReLU) {
            this.outputs =
                    (Neural_Node[][]) Layer_Activation.Activate_By_ReLU((Cognition_Element[][]) this.outputs);
        }
        if(activation_method == Enums.Layer_Activation_Method.SoftMax) {
            this.outputs =
                    (Neural_Node[][]) Layer_Activation.Activate_By_Softmax((Cognition_Element[][]) this.outputs);
        }

    }

    public void Activate_Layer() {

        Set_Activation_Values_By_Method(Enums.Layer_Activation_Method.SoftMax);
    }


    public Cognition_Element[][] Forward_Pass() {
        return  null;
    }

    /**
     * This function sets the value of 'the inputs' * 'the weights' + 'the bias'
     * which is recieved by the next layer
     *
     * @param inputs a Neural_Node object that holds the input values
     */
    public void Generate_Layer_Specific_Prediction(Neural_Node[][] inputs) {

        this.inputs = inputs;

        Math.GenerateOutputPrediction(inputs, weights, biases);
    }

    /**
     *
     *
     * Displays the Cognition element level selected by the parameter to the console
     *
     * @param display_level From Enums Display_Level ; Options include ALL, Neural_Nodes, Weights,
     *                      and Biases
     *
     *
     */
    public void Display_To_Console(Enums.Display_Level display_level) {

        if(display_level == Enums.Display_Level.All) {

            Display_Neural_Nodes_To_Console();
            Display_Weights_To_Console();
            Display_Biases_To_Console();
            Display_Generated_Predictions_To_Console();
        }
        else if (display_level == Enums.Display_Level.Nerual_Nodes) {
            Display_Neural_Nodes_To_Console();
        }
        else if (display_level == Enums.Display_Level.Weights) {
            Display_Weights_To_Console();
        }
        else if (display_level == Enums.Display_Level.Biases) {
            Display_Biases_To_Console();
        }
        else if (display_level == Enums.Display_Level.Generated_Predictions) {
            Display_Generated_Predictions_To_Console();
        }
    }

    /**
     *  Displays the Generated Predictions to the console
     *
     **/
    public void Display_Generated_Predictions_To_Console() {

        System.out.println("Generating predictions here");

        for(int input_row_index = 0; input_row_index < inputs.length; input_row_index++) {
            System.out.println("");


            for (int input_column_index = 0; input_column_index < weights[input_row_index].length; input_column_index++) {

                for(int weight_column_index = 0; weight_column_index < weights[input_row_index].length; weight_column_index++) {
                    System.out.print(" (" + inputs[input_row_index][input_column_index].value + " * " + weights[input_row_index][weight_column_index].value + ") ");
                }
                System.out.println("");
            }
            System.out.println("");
        }
    }

    /**
     *  Displays the Weights to the console
     *
     **/
    public void Display_Weights_To_Console() {
        System.out.println("These are the weights");
        for( int neuron_index = 0; neuron_index < this.neuron_count; neuron_index++ ) {
            int input_index = 0;
            System.out.print( " ");
            while (input_index < this.input_count) {
                System.out.print(weights[neuron_index][input_index].value);
                System.out.print( " ");
                input_index++;
            }
            System.out.println( " ");
        }

        System.out.println();

    }

    /**
     *  Displays the Biases to the console
     *
     **/
    public void Display_Biases_To_Console() {

        System.out.println("These are the biases");
        for (Bias bias : this.biases) {
            System.out.print(bias.value + " ");
        }
        System.out.println("");

    }

    /**
     *  Displays the Neural_Nodes to the console
     *
     **/
    public void Display_Neural_Nodes_To_Console() {


        System.out.println("These are the inputs");
        for( int inputs_row_index = 0; inputs_row_index < this.inputs.length; inputs_row_index++ ) {
            int inputs_column_index = 0;
            System.out.print( " ");
            while (inputs_column_index < this.input_count) {
                System.out.print(this.inputs[inputs_row_index][inputs_column_index].value);
                System.out.print( " ");
                inputs_column_index++;
            }
            System.out.println( " ");
        }

        System.out.println();

    }
}

