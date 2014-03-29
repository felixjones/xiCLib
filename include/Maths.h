#ifndef __MATHS_H__
#define __MATHS_H__

/*
================================================================================

	Maths utilities
	Full of helpful maths!
	Generally, float operations are all here

================================================================================
*/

#define MIN( X, Y )				( X < Y ? X : Y )
#define MAX( X, Y )				( X > Y ? X : Y )
#define AVG_WEIGHT( X, Y, Z )	( X * ( 1.0f - Z ) + Y * Z )
#define AVG( X, Y )				( ( X + Y ) * 0.5f )
#define SAFE_DIV( X, Y )		( Y == 0.0f ? 0.0f : X / Y )
#define FLOOR( X )				( ( int32_t )X )
#define CEIL( X )				( X - FLOOR( X ) == 0.0f ? X : FLOOR( X ) + 1.0f )
#define ROUND( X )				( X - FLOOR( X ) < 0.5 ? FLOOR( X ) : FLOOR( X ) + 1.0f )
#define DEG2RAD( X )			( X * 0.0174532925f )
#define RAD2DEG( X )			( X * 57.2957795f )

float	Maths_InvSqrt( const float number );
float	Maths_Sqrt( const float number );

float	Maths_Sin( const float radian );
float	Maths_Cos( const float radian );
float	Maths_Tan( const float radian );
float	Maths_ASin( const float arc );
float	Maths_ACos( const float arc );
float	Maths_ATan( const float arc );

float	Maths_Pow( const float number, const float power );

#endif