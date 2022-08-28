package CognitionMap.Math;

import CognitionMap.Elements.Bias;
import CognitionMap.Elements.Cognition_Element;

public class Math {

    /**    List1                         List2
     //
     //    Example : [x0[a,b,c]            Example : [x0[r,s,t]
     //               x1[d,e,f]                       x1[u,v,w]
     //               x2[g,h,i]]                      x2[x,y,z]]
     //
     //
     //
     //        [ [L1r0c0 * L2r0c0, L1r0c0 * L2r0c0
     **/

     /**   Inputs = i           Weights = w
     //
     //    Example : [[1,2,3]            Example : [[6,5,4]
     //               [2,3,4]                       [5,4,3]
     //               [3,4,5]]                      [4,3,2]]
     //
     **/

     /**
     *   For every "Inputs" column index;
     *   each individual column in the weights is indexed in that row
     *   and the output column index increments +1
     *
     * @param inputs
     * @param weights
     * @return output
     */
    public static Cognition_Element[][] GenerateOutputPrediction(Cognition_Element[][] inputs, Cognition_Element[][] weights, Bias[] biases) {
        Cognition_Element [][] outputs = new Cognition_Element[inputs.length][weights.length];

        System.out.println("Generating predictions here");

        for(int input_row_index = 0; input_row_index < inputs.length; input_row_index++) {
            System.out.println("");

            float input_specific_prediction = 0;

             for (int input_column_index = 0; input_column_index < weights[input_row_index].length; input_column_index++) {

                 for(int weight_column_index = 0; weight_column_index < weights[input_row_index].length; weight_column_index++) {

                     input_specific_prediction += inputs[input_row_index][input_column_index].value
                                                  *
                                                  weights[input_row_index][weight_column_index].value;

                     System.out.print(" (" + inputs[input_row_index][input_column_index].value + " * " + weights[input_row_index][weight_column_index].value + ") ");
                     outputs[input_row_index][input_column_index] = new Cognition_Element(input_specific_prediction);
                 }
                 System.out.println("");
             }
             System.out.println("");
        }


        return outputs;
    }
}
