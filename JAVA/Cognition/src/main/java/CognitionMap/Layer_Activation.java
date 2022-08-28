package CognitionMap;

import CognitionMap.Elements.Cognition_Element;

public class Layer_Activation {


    public static Cognition_Element[][] Activate_By_ReLU(Cognition_Element [][] outputs) {

        for(int output_row_index = 0; output_row_index < outputs.length; output_row_index++) {
            for(int output_col_index = 0; output_col_index < outputs[output_row_index].length; output_col_index++) {
                if(outputs[output_row_index][output_col_index].value <= 0) {
                    outputs[output_row_index][output_col_index].value = 0;
                }
            }
        }
        return outputs;
    }

    /**
     * For every output index by row and column
     * Exponentiate the index
     *
     * For Every Row Sum the Exponentiated Value
     *
     * For every column in Each Row Divide that exponentiated value by the sum
     *
     * Set the new output index value ot the normalized value of the exponentiated output
     *
     * @param outputs
     * @return outputs
     */
    public static Cognition_Element[][] Activate_By_Softmax(Cognition_Element[][] outputs) {

        boolean output_row_has_been_summated = false;

        for(int output_row_index = 0; output_row_index < outputs.length; output_row_index++) {

            float exponentiated_sum = 0;

            for(int output_col_index = 0; output_col_index < outputs[output_row_index].length; output_col_index++) {

                if(output_row_has_been_summated) {
                    for (int normalizing_index = 0; normalizing_index < outputs[output_row_index].length; normalizing_index++) {

                        float output_value = outputs[output_row_index][output_col_index].value;

                        output_value =
                                (float) Math.pow(
                                        Math.E,
                                        output_value
                                );

                        exponentiated_sum += output_col_index;
                    }
                    output_row_has_been_summated = true;
                }
//                outputs[output_row_index][output_col_index].value = output_value;
            }
        }
        return outputs;
    }
}
