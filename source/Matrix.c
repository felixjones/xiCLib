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
