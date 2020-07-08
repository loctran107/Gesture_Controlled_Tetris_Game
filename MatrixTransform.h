#ifndef _MATRIXTRANSFORM_H_
#define _MATRIXTRANSFORM_H_
#define DEFAULT_SIZE 2
#include <cstdlib>
#include <cmath>

using namespace std;
class MatrixTransform {
	
	public:
		MatrixTransform(int angle) : angle_(angle) { 
			
			//Define the matrix to transform
			transform[0][0] = cos(angle);
			transform[0][1] = -sin(angle);
			transform[1][0] = sin(angle);
			transform[1][1] = cos(angle);
		}

		//Accessor
		int getAngle() { return angle_; }
	
		//Mutator
		void setAngle(const int angle);
		
		//Transform
		void matrixTransform(const int& x_tile, const int& y_tile);

	private:
		int angle_;
		int transform[DEFAULT_SIZE][DEFAULT_SIZE];
}; 

#endif //_MATRIXTRANSFORM_H_
