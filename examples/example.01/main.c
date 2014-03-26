#include <Matrix.h>

int main( int argc, char ** argv ) {
	mat2_t mat = {
		{ 1.0f, 0.0f },
		{ 0.0f, 1.0f }
	};

	vec2_t vec = { 5.0f, 6.0f };

	Vector_MulMatrix( &vec, &vec, &mat, VEC2 );

	const float len = Vector_Length( &vec, VEC2 );
	vec2_t fl = { 0.0f, 0.0f };

	Vector_Mul( &vec, &vec, &vec );
	Vector_Div( &vec, &vec, &fl );

	return 1;
}