package CognitionMap;

import CognitionMap.Elements.Bias;
import CognitionMap.Elements.Neuron;

public class Layer {

    private Neuron[][] neurons;
    private Neuron[][] weights;

    private Bias [] biases;

    public Layer(int input_count, int neuron_count) {

    }


    public void Forward(float [][] inputs) {
//        CognitionMap.Math.Math.DotProduct(this.weights, inputs);
    }
}
