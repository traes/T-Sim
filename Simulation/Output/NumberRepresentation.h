#ifndef NUMBER_REPRESENTATION_H
#define NUMBER_REPRESENTATION_H

/*
             ^ Y (+)
             :
             :
             :
	+--- UH ---+
	|          |
	|          |
       LUV        RUV 
	|          |
	|          |          X (+)
 ...... +--- MH ---+ .........>
	|          |
	|          |
       LLV        RLV
	|          |
	|          |
	+--- LH ---+
             :
             :
             :

UH: Upper Horizontal
MH: Middle Horizontal
LH: Lower Horizontal
LUV: Left Upper Vertical
RUV: Right Upper Vertical
LLV: Left Lower Vertical
RLV: Right Lower Vertical

 */

class NumberRepresentation {
	public:
		NumberRepresentation();
		void show(int number,float size);
	private:	
		void show_horizontal_line(float length,float line_width);
		void show_vertical_line(float length,float line_width);
		void show_UH(float length, float line_width);
		void show_MH(float length, float line_width);
		void show_LH(float length, float line_width);
		void show_LUV(float length, float line_width);
		void show_LLV(float length, float line_width);
		void show_RUV(float length, float line_width);
		void show_RLV(float length, float line_width);
		void show_digit(int digit,float horizontal_length, float vertical_length, float line_width);
};

#endif
