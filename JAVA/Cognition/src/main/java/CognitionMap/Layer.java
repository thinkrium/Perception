package CognitionMap;

import CognitionMap.Elements.Bias;
import CognitionMap.Elements.Neural_Node;
import CognitionMap.Elements.Weight;
import CognitionMap.Math.Math;
import Utilities.Enums;

import java.util.Random;

public class Layer {

    private Neural_Node[][] inputs;
    private Weight[][] weights;

    private Bias [] biases;

    private int neuron_count;

    private int input_count;

    private float [][] outputs;
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

        Random random = new Random();

        this.input_count = input_count;
        this.neuron_count = neuron_count;
        this.weights = new Weight[neuron_count][input_count];


        this.biases = new Bias[neuron_count];

        for( int neuron_index = 0; neuron_index < neuron_count; neuron_index++ ) {
            for( int input_index = 0; input_index < input_count; input_index++ ) {
                    this.weights[neuron_index][input_index] = new Weight(random.nextFloat());
            }
        }

        for(int bias_index = 0;bias_index < neuron_count; bias_index++) {
            this.biases[bias_index] = new Bias(0);
        }
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

