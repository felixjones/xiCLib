#include "Maths.h"

#include <stdint.h>
#include <math.h>

#ifdef _MSC_VER
	#define inline __forceinline
#endif

#define THREE_HALVES	( 1.5f )
#define INV_SQRT		( 0x5f375a86 )
#define LOOKUP_LEN		( 1024 )
#define INV_360			( 0.00277777777f )
#define TINY_NUM		( 0.0000000000000001f )

static float sinTable[LOOKUP_LEN];
static float cosTable[LOOKUP_LEN];
static float tanTable[LOOKUP_LEN];
static float asinTable[LOOKUP_LEN];
static float acosTable[LOOKUP_LEN];
static float atanTable[LOOKUP_LEN];

typedef enum trigFunc_e {
	TRIG_SIN,
	TRIG_COS,
	TRIG_TAN,
	TRIG_ASIN,
	TRIG_ACOS,
	TRIG_ATAN
} trigFunc_t;

inline static float Trig( const float number, const size_t index, const trigFunc_t trigFunc, float * const table ) {
	float * const val = &table[index];

	if ( *val ) {
		return *val;
	}

	switch ( trigFunc ) {
	case TRIG_SIN:
		*val = sinf( number );
		break;
	case TRIG_COS:
		*val = cosf( number );
		break;
	case TRIG_TAN:
		*val = tanf( number );
		break;
	case TRIG_ASIN:
		*val = asinf( number );
		break;
	case TRIG_ACOS:
		*val = acosf( number );
		break;
	case TRIG_ATAN:
		*val = atanf( number );
		break;
	}

	if ( ( *val ) * ( *val ) > 0.0f ) {
		return *val;
	}

	return TINY_NUM;
}

/*
====================
QSqrt

	Fast-inverse square root from Quake 3
	This can be replaced with 1.0f / sqrtf() on modern systems
====================
*/
inline static float QSqrt( const float number ) {
	const float x2 = number * 0.5f;
	float y = number;

	long i = *( long * )&y;	// evil floating point bit level hacking
	i = INV_SQRT - ( i >> 1 );	// what the fuck?
	y = *( float * )&i;

	y = y * ( THREE_HALVES - ( x2 * y * y ) );	// 1st iteration
	//y = y * ( THREE_HALVES - ( x2 * y * y ) );	// 2nd iteration, this can be removed
 
	return y;
}

inline static size_t TableIndex( const float radian ) {
	size_t index = ( size_t )( RAD2DEG( radian ) * ( LOOKUP_LEN * INV_360 ) );
	while ( index >= LOOKUP_LEN ) {
		index -= LOOKUP_LEN;
	}

	return index;
}

inline static size_t ArcIndex( const float arc ) {
	const size_t index = ( size_t )( ( arc + 1.0f ) * ( LOOKUP_LEN >> 1 ) );
	if ( index == LOOKUP_LEN ) {
		return 0;
	}

	return index;
}

/*
====================
Maths_InvSqrt

	Calls the standard inverse square root function
====================
*/
float Maths_InvSqrt( const float number ) {
	return QSqrt( number );
}

/*
====================
Maths_Sqrt

	Calls the standard inverse square root function
	Multiplies the answer by number to get the real result
====================
*/
float Maths_Sqrt( const float number ) {
	return number * QSqrt( number );
}

float Maths_Sin( const float radian ) {
	return Trig( radian, TableIndex( radian ), TRIG_SIN, &sinTable[0] );
}

float Maths_Cos( const float radian ) {
	return Trig( radian, TableIndex( radian ), TRIG_COS, &cosTable[0] );
}

float Maths_Tan( const float radian ) {
	return Trig( radian, TableIndex( radian ), TRIG_TAN, &tanTable[0] );
}

float Maths_ASin( const float arc ) {
	return Trig( arc, ArcIndex( arc ), TRIG_ASIN, &asinTable[0] );
}

float Maths_ACos( const float arc ) {
	return Trig( arc, ArcIndex( arc ), TRIG_ACOS, &acosTable[0] );
}

float Maths_ATan( const float arc ) {
	return Trig( arc, ArcIndex( arc ), TRIG_ATAN, &atanTable[0] );
}

float Maths_SinH( const float radian ) {
	return sinhf( radian );
	//return Trig( radian, TableIndex( radian ), &sinhf, &sinhTable[0] );
}

float Maths_CosH( const float radian ) {
	return coshf( radian );
	//return Trig( radian, TableIndex( radian ), &coshf, &coshTable[0] );
}

float Maths_TanH( const float radian ) {
	return tanhf( radian );
	//return Trig( radian, TableIndex( radian ), &tanhf, &tanhTable[0] );
}

float Maths_Pow( const float number, const float power ) {
	return powf( number, power );
}

float Maths_Exp( const float number ) {
	return expf( number );
}

float Maths_Log( const float number ) {
	return logf( number );
}
