#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdint.h>

#define VEC_X		( 0 )
#define VEC_Y		( 1 )
#define VEC_Z		( 2 )
#define VEC_W		( 3 )
#define VEC_NULL	( 4 )
#define VEC2		( 2 )
#define VEC3		( 3 )
#define VEC4		( 4 )

typedef struct vec4_s {
	float	x;
	float	y;
	float	z;
	float	w;
} vec4_t;

typedef struct vec3_s {
	float	x;
	float	y;
	float	z;

	struct {
		float	w;
	} _padding;
} vec3_t;

typedef struct vec2_s {
	float	x;
	float	y;

	struct {
		float	z;
		float	w;
	} _padding;
} vec2_t;

void	Vector_Clear( void * const vector );
void	Vector_ToFloatPtr( const void * const vector, float * const floatPtr, const size_t length );

void	Vector_Swizzle( void * const vector, const void * const input, const size_t x, const size_t y, const size_t z, const size_t w );

void	Vector_Add( void * const vector, const void * const left, const void * const right );
void	Vector_Sub( void * const vector, const void * const left, const void * const right );
void	Vector_Mul( void * const vector, const void * const left, const void * const right );
void	Vector_Div( void * const vector, const void * const left, const void * const right );

void	Vector_Min( void * const vector, const void * const left, const void * const right );
void	Vector_Max( void * const vector, const void * const left, const void * const right );
void	Vector_Clamp( void * const vector, const void * const input, const void * const min, const void * const max );
void	Vector_Mix( void * const vector, const void * const left, const void * const right, const void * const mixer );
void	Vector_MinFloat( void * const vector, const void * const left, const float right );
void	Vector_MaxFloat( void * const vector, const void * const left, const float right );
void	Vector_ClampFloat( void * const vector, const void * const input, const float min, const float max );
void	Vector_MixFloat( void * const vector, const void * const left, const void * const right, const float mixer );

void	Vector_Cross( void * const vector, const void * const left, const void * const right );
float	Vector_Dot( const void * const left, const void * const right, const size_t length );
float	Vector_Length( const void * const vector, const size_t length );
float	Vector_Distance( const void * const left, const void * const right, const size_t length );
void	Vector_Normalise( void * const vector, const void * const input, const size_t length );
void	Vector_FaceForward( void * const vector, const void * const n, const void * const i, const void * const nRef, const size_t length );
void	Vector_Reflect( void * const vector, const void * const i, const void * const n, const size_t length );
void	Vector_Refract( void * const vector, const void * const i, const void * const n, const float r, const size_t length );

#endif