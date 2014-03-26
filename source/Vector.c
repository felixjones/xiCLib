#include "Vector.h"

#include <string.h>
#include "Maths.h"

#define VEC4_CAST( X )	( ( vec4_t * )X )

void Vector_Clear( void * const vector ) {
	memset( vector, 0, sizeof( vec4_t ) );
}

void Vector_Add( void * const vector, const void * const left, const void * const right ) {
	VEC4_CAST( vector )->x = VEC4_CAST( left )->x + VEC4_CAST( right )->x;
	VEC4_CAST( vector )->y = VEC4_CAST( left )->y + VEC4_CAST( right )->y;
	VEC4_CAST( vector )->z = VEC4_CAST( left )->z + VEC4_CAST( right )->z;
	VEC4_CAST( vector )->w = VEC4_CAST( left )->w + VEC4_CAST( right )->w;
}

void Vector_Sub( void * const vector, const void * const left, const void * const right ) {
	VEC4_CAST( vector )->x = VEC4_CAST( left )->x - VEC4_CAST( right )->x;
	VEC4_CAST( vector )->y = VEC4_CAST( left )->y - VEC4_CAST( right )->y;
	VEC4_CAST( vector )->z = VEC4_CAST( left )->z - VEC4_CAST( right )->z;
	VEC4_CAST( vector )->w = VEC4_CAST( left )->w - VEC4_CAST( right )->w;
}

void Vector_Mul( void * const vector, const void * const left, const void * const right ) {
	VEC4_CAST( vector )->x = VEC4_CAST( left )->x * VEC4_CAST( right )->x;
	VEC4_CAST( vector )->y = VEC4_CAST( left )->y * VEC4_CAST( right )->y;
	VEC4_CAST( vector )->z = VEC4_CAST( left )->z * VEC4_CAST( right )->z;
	VEC4_CAST( vector )->w = VEC4_CAST( left )->w * VEC4_CAST( right )->w;
}

void Vector_Div( void * const vector, const void * const left, const void * const right ) {
	VEC4_CAST( vector )->x = ( VEC4_CAST( right )->x == 0.0f ? 0.0f : VEC4_CAST( left )->x / VEC4_CAST( right )->x );
	VEC4_CAST( vector )->y = ( VEC4_CAST( right )->x == 0.0f ? 0.0f : VEC4_CAST( left )->y / VEC4_CAST( right )->y );
	VEC4_CAST( vector )->z = ( VEC4_CAST( right )->x == 0.0f ? 0.0f : VEC4_CAST( left )->z / VEC4_CAST( right )->z );
	VEC4_CAST( vector )->w = ( VEC4_CAST( right )->x == 0.0f ? 0.0f : VEC4_CAST( left )->w / VEC4_CAST( right )->w );
}

void Vector_MulMatrix( void * const vector, const void * const input, const void * const matrix, const size_t length ) {
	const float * const vecFloat = ( const float * )input;
	const float * const matFloat = ( const float * )matrix;

	vec4_t resVec;
	Vector_Clear( &resVec );
	float * const resFloat = ( float * )&resVec;

	size_t ii = length - 1;
	do {
		float sum = 0.0f;
		size_t kk = length - 1;

		do {
			sum += matFloat[ii * VEC4 + kk] * vecFloat[kk];
		} while ( kk-- );

		resFloat[ii] = sum;
	} while ( ii-- );

	memcpy( vector, &resVec, sizeof( vec4_t ) );
}

void Vector_ToFloatPtr( const void * const vector, float * const floatPtr, const size_t length ) {
	memcpy( floatPtr, vector, sizeof( float ) * length );
}

void Vector_Min( void * const vector, const void * const left, const void * const right ) {
	VEC4_CAST( vector )->x = ( ( VEC4_CAST( left )->x < VEC4_CAST( right )->x ) ? VEC4_CAST( left )->x : VEC4_CAST( right )->x );
	VEC4_CAST( vector )->y = ( ( VEC4_CAST( left )->y < VEC4_CAST( right )->y ) ? VEC4_CAST( left )->y : VEC4_CAST( right )->y );
	VEC4_CAST( vector )->z = ( ( VEC4_CAST( left )->z < VEC4_CAST( right )->z ) ? VEC4_CAST( left )->z : VEC4_CAST( right )->z );
	VEC4_CAST( vector )->w = ( ( VEC4_CAST( left )->w < VEC4_CAST( right )->w ) ? VEC4_CAST( left )->w : VEC4_CAST( right )->w );
}

void Vector_Max( void * const vector, const void * const left, const void * const right ) {
	VEC4_CAST( vector )->x = ( ( VEC4_CAST( left )->x > VEC4_CAST( right )->x ) ? VEC4_CAST( left )->x : VEC4_CAST( right )->x );
	VEC4_CAST( vector )->y = ( ( VEC4_CAST( left )->y > VEC4_CAST( right )->y ) ? VEC4_CAST( left )->y : VEC4_CAST( right )->y );
	VEC4_CAST( vector )->z = ( ( VEC4_CAST( left )->z > VEC4_CAST( right )->z ) ? VEC4_CAST( left )->z : VEC4_CAST( right )->z );
	VEC4_CAST( vector )->w = ( ( VEC4_CAST( left )->w > VEC4_CAST( right )->w ) ? VEC4_CAST( left )->w : VEC4_CAST( right )->w );
}

void Vector_Clamp( void * const vector, const void * const input, const void * const min, const void * const max ) {
	Vector_Max( vector, input, min );
	Vector_Min( vector, input, max );
}

void Vector_Mix( void * const vector, const void * const left, const void * const right, const void * const mixer ) {
	VEC4_CAST( vector )->x = VEC4_CAST( left )->x * ( 1.0f - VEC4_CAST( mixer )->x ) + VEC4_CAST( right )->x * VEC4_CAST( mixer )->x;
	VEC4_CAST( vector )->y = VEC4_CAST( left )->y * ( 1.0f - VEC4_CAST( mixer )->y ) + VEC4_CAST( right )->y * VEC4_CAST( mixer )->y;
	VEC4_CAST( vector )->z = VEC4_CAST( left )->z * ( 1.0f - VEC4_CAST( mixer )->z ) + VEC4_CAST( right )->z * VEC4_CAST( mixer )->z;
	VEC4_CAST( vector )->w = VEC4_CAST( left )->w * ( 1.0f - VEC4_CAST( mixer )->w ) + VEC4_CAST( right )->w * VEC4_CAST( mixer )->w;
}

void Vector_MinFloat( void * const vector, const void * const left, const float right ) {
	const vec4_t rightVec = { right, right, right, right };
	Vector_Min( vector, left, &rightVec );
}

void Vector_MaxFloat( void * const vector, const void * const left, const float right ) {
	const vec4_t rightVec = { right, right, right, right };
	Vector_Max( vector, left, &rightVec );
}

void Vector_ClampFloat( void * const vector, const void * const input, const float min, const float max ) {
	const vec4_t minVec = { min, min, min, min };
	const vec4_t maxVec = { max, max, max, max };
	Vector_Clamp( vector, input, &minVec, &maxVec );
}

void Vector_MixFloat( void * const vector, const void * const left, const void * const right, const float mixer ) {
	const vec4_t mixVec = { mixer, mixer, mixer, mixer };
	Vector_Mix( vector, left, right, &mixVec );
}

void Vector_Cross( void * const vector, const void * const left, const void * const right ) {
	vec4_t temp;

	temp.x = ( VEC4_CAST( left )->y * VEC4_CAST( right )->z ) - ( VEC4_CAST( left )->z * VEC4_CAST( right )->y );
	temp.y = ( VEC4_CAST( left )->z * VEC4_CAST( right )->x ) - ( VEC4_CAST( left )->x * VEC4_CAST( right )->z );
	temp.z = ( VEC4_CAST( left )->x * VEC4_CAST( right )->y ) - ( VEC4_CAST( left )->y * VEC4_CAST( right )->x );
	
	VEC4_CAST( vector )->x = temp.x;
	VEC4_CAST( vector )->y = temp.y;
	VEC4_CAST( vector )->z = temp.z;
}

float Vector_Dot( const void * const left, const void * const right, const size_t length ) {
	float val = ( VEC4_CAST( left )->x * VEC4_CAST( right )->x );

	val += ( length < VEC2 ? 0.0f : VEC4_CAST( left )->y * VEC4_CAST( right )->y );
	val += ( length < VEC3 ? 0.0f : VEC4_CAST( left )->z * VEC4_CAST( right )->z );
	val += ( length < VEC4 ? 0.0f : VEC4_CAST( left )->w * VEC4_CAST( right )->w );

	return val;
}

float Vector_Length( const void * const vector, const size_t length ) {
	return Maths_Sqrt( Vector_Dot( vector, vector, length ) );
}

float Vector_Distance( const void * const left, const void * const right, const size_t length ) {
	vec4_t vector;
	Vector_Sub( &vector, left, right );

	return Vector_Length( &vector, length );
}

void Vector_Normalise( void * const vector, const void * const input, const size_t length ) {
	const float invLen = Maths_InvSqrt( Vector_Dot( input, input, length ) );
	
	VEC4_CAST( vector )->x = VEC4_CAST( input )->x * invLen;
	VEC4_CAST( vector )->y = ( length < VEC2 ? 0.0f : VEC4_CAST( input )->y * invLen );
	VEC4_CAST( vector )->z = ( length < VEC3 ? 0.0f : VEC4_CAST( input )->z * invLen );
	VEC4_CAST( vector )->w = ( length < VEC4 ? 0.0f : VEC4_CAST( input )->w * invLen );
}

void Vector_FaceForward( void * const vector, const void * const n, const void * const i, const void * const nRef, const size_t length ) {
	if ( Vector_Dot( nRef, i, length ) < 0.0f ) {
		memcpy( vector, n, sizeof( float ) * length );
	} else {
		VEC4_CAST( vector )->x = -VEC4_CAST( n )->x;
		VEC4_CAST( vector )->y = ( length < VEC2 ? 0.0f : -VEC4_CAST( n )->y );
		VEC4_CAST( vector )->z = ( length < VEC2 ? 0.0f : -VEC4_CAST( n )->z );
		VEC4_CAST( vector )->w = ( length < VEC2 ? 0.0f : -VEC4_CAST( n )->w );
	}
}

void Vector_Reflect( void * const vector, const void * const i, const void * const n, const size_t length ) {
	const float doubleDot = 2.0f * Vector_Dot( n, i, length );
	
	vec4_t doubleVec;
	doubleVec.x = VEC4_CAST( n )->x * doubleDot;
	doubleVec.y = ( length < VEC2 ? 0.0f : VEC4_CAST( n )->y * doubleDot );
	doubleVec.z = ( length < VEC3 ? 0.0f : VEC4_CAST( n )->z * doubleDot );
	doubleVec.w = ( length < VEC4 ? 0.0f : VEC4_CAST( n )->w * doubleDot );

	Vector_Sub( vector, i, &doubleVec );
}

void Vector_Refract( void * const vector, const void * const i, const void * const n, const float r, const size_t length ) {
	const float nDi = Vector_Dot( n, i, length );
	const float d = 1.0f - r * r * ( 1.0f - nDi * nDi );

	if ( d < 0.0f ) {
		Vector_Clear( vector );
	} else {
		const float rVS = ( r * nDi + Maths_Sqrt( d ) );
		
		vec4_t riVec;
		riVec.x = VEC4_CAST( i )->x * r;
		riVec.y = ( length < VEC2 ? 0.0f : VEC4_CAST( i )->y * r );
		riVec.z = ( length < VEC3 ? 0.0f : VEC4_CAST( i )->z * r );
		riVec.w = ( length < VEC4 ? 0.0f : VEC4_CAST( i )->w * r );
		
		vec4_t rVSVec;
		rVSVec.x = VEC4_CAST( n )->x * rVS;
		rVSVec.y = ( length < VEC2 ? 0.0f : VEC4_CAST( n )->y * rVS );
		rVSVec.z = ( length < VEC3 ? 0.0f : VEC4_CAST( n )->z * rVS );
		rVSVec.w = ( length < VEC4 ? 0.0f : VEC4_CAST( n )->w * rVS );

		Vector_Sub( vector, &riVec, &rVSVec );

		VEC4_CAST( vector )->x = ( riVec.x - rVSVec.x );
		VEC4_CAST( vector )->y = ( length < VEC2 ? 0.0f : riVec.y - rVSVec.y );
		VEC4_CAST( vector )->z = ( length < VEC3 ? 0.0f : riVec.z - rVSVec.z );
		VEC4_CAST( vector )->w = ( length < VEC4 ? 0.0f : riVec.w - rVSVec.w );
	}
}