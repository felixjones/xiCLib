#include "Matrix.h"

#include <string.h>

#define MAT4_CAST( X )	( ( mat4_t * )X )

void Matrix_Clear( void * const matrix ) {
	memset( matrix, 0, sizeof( mat4_t ) );
}

void Matrix_ToFloatPtr( const void * const matrix, float * const floatPtr, const size_t length ) {
	size_t index = length - 1;
	do {
		Vector_ToFloatPtr( ( &MAT4_CAST( matrix )->x + index ), &floatPtr[length * index], length );
	} while ( index-- );
}

void Matrix_Mul( void * const matrix, const void * const left, const void * const right, const size_t length ) {
	const float * const leftFloat = ( const float * )left;
	const float * const rightFloat = ( const float * )right;

	mat4_t resMat;
	Matrix_Clear( &resMat );
	float * const resFloat = ( float * )&resMat;

	size_t ii = length - 1;
	do {
		size_t jj = length - 1;

		do {
			float sum = 0.0f;
			size_t kk = length - 1;
			
			do {
				sum += rightFloat[kk * MAT4 + ii] * leftFloat[jj * MAT4 + kk];
			} while ( kk-- );

			resFloat[jj * MAT4 + ii] = sum;
		} while ( jj-- );
	} while ( ii-- );
	
	memcpy( matrix, &resMat, sizeof( mat4_t ) );
}