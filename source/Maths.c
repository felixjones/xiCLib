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
	size_t index = RAD2DEG( radian ) * ( LOOKUP_LEN * INV_360 );
	while ( index >= LOOKUP_LEN ) {
		index -= LOOKUP_LEN;
	}
	while ( index < 0 ) {
		index += LOOKUP_LEN;
	}

	return index;
}

inline static size_t ArcIndex( const float arc ) {
	const size_t index = ( arc + 1.0f ) * ( LOOKUP_LEN >> 1 );
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
	const size_t index = TableIndex( radian );
	float * const val = &sinTable[index];

	if ( *val ) {
		return *val;
	}

	*val = sinf( radian );
	if ( !*val ) {
		*val = TINY_NUM;
	}

	return *val;
}

float Maths_Cos( const float radian ) {
	const size_t index = TableIndex( radian );
	float * const val = &cosTable[index];

	if ( *val ) {
		return *val;
	}

	*val = cosf( radian );
	if ( !*val ) {
		*val = TINY_NUM;
	}

	return *val;
}

float Maths_Tan( const float radian ) {
	const size_t index = TableIndex( radian );
	float * const val = &tanTable[index];

	if ( *val ) {
		return *val;
	}

	*val = tanf( radian );
	if ( !*val ) {
		*val = TINY_NUM;
	}

	return *val;
}

float Maths_ASin( const float arc ) {
	if ( arc > 1.0f ) {
		return 0.0f;
	} else if ( arc < -1.0f ) {
		return 0.0f;
	}

	const size_t index = ArcIndex( arc );
	float * const val = &asinTable[index];

	if ( *val ) {
		return *val;
	}

	*val = asinf( arc );
	if ( !*val ) {
		*val = TINY_NUM;
	}

	return *val;
}

float Maths_ACos( const float arc ) {
	if ( arc > 1.0f ) {
		return 0.0f;
	} else if ( arc < -1.0f ) {
		return 0.0f;
	}

	const size_t index = ArcIndex( arc );
	float * const val = &acosTable[index];

	if ( *val ) {
		return *val;
	}

	*val = acosf( arc );
	if ( !*val ) {
		*val = TINY_NUM;
	}

	return *val;
}

float Maths_ATan( const float arc ) {
	if ( arc > 1.0f ) {
		return 0.0f;
	} else if ( arc < -1.0f ) {
		return 0.0f;
	}

	const size_t index = ArcIndex( arc );
	float * const val = &atanTable[index];

	if ( *val ) {
		return *val;
	}

	*val = atanf( arc );
	if ( !*val ) {
		*val = TINY_NUM;
	}

	return *val;
}

float Maths_Pow( const float number, const float power ) {
	return powf( number, power );
}