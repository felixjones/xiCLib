#include <Matrix.h>

int main( int argc, char ** argv ) {
	mat4_t mat = {
		{ 0.0f, 3.0f, 2.0f, 5.0f },
		{ 9.0f, 4.0f, 1.0f, 6.0f },
		{ 8.0f, 5.0f, 0.0f, 7.0f },
		{ 7.0f, 6.0f, 9.0f, 8.0f }
	};

	Matrix_Inverse( &mat, &mat, MAT3 );
	Matrix_Inverse( &mat, &mat, MAT3 );

	return 1;
}
