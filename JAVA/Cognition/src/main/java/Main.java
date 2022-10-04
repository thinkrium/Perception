import CognitionMap.Elements.Neural_Node;
import CognitionMap.Layers.Layer;
import Utilities.Enums;

public class Main {

    public static void main(String[] args) {
        Layer layer = new Layer(3, 3);


        Neural_Node[][] inputs = new Neural_Node[2][3];


        for( int neural_node_row_index = 0; neural_node_row_index < 2; neural_node_row_index++ ) {
            for( int neural_node_col_index = 0; neural_node_col_index < 3; neural_node_col_index++ ) {
                float input_value = (float) ((neural_node_row_index + 1) * (neural_node_col_index + 1));
                inputs[neural_node_row_index][neural_node_col_index] = new Neural_Node(input_value);
            }
        }

        layer.Generate_Layer_Specific_Prediction( inputs );

        layer.Display_To_Console(Enums.Display_Level.Nerual_Nodes);

        layer.Display_To_Console(Enums.Display_Level.Generated_Predictions);

        layer.Activate_Layer_Using_Softmax();
        layer.Display_To_Console(Enums.Display_Level.Outputs);

    }
}
