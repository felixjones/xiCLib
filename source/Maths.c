#include "Maths.h"

#define THREE_HALVES	( 1.5f )
#define INV_SQRT		( 0x5f375a86 )
//( 0x5f3759df )

float Maths_InvSqrt( const float number ) {
	const float x2 = number * 0.5f;
	float y = number;

	long i = *( long * )&y;	// evil floating point bit level hacking
	i = INV_SQRT - ( i >> 1 );	// what the fuck?
	y = *( float * )&i;

	y = y * ( THREE_HALVES - ( x2 * y * y ) );	// 1st iteration
	//y = y * ( THREE_HALVES - ( x2 * y * y ) );	// 2nd iteration, this can be removed
 
	return y;
}

float Maths_Sqrt( const float number ) {
	return 1.0f / Maths_InvSqrt( number );
}