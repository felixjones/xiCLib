#include <Maths.h>
#include <Matrix.h>

void Maths() {

	float f = 0.0f;
	int i = 0;

	f = MIN( 1.0f, 2.0f ); // f = ( 1.0f < 2.0f ? 1.0f : 2.0f ) = 1.0f
	f = MAX( 1.0f, 2.0f ); // f = ( 1.0f > 2.0f ? 1.0f : 2.0f ) = 2.0f
	f = AVG_WEIGHT( 0.0f, 10.0f, 0.75f ); // f = ( 0.0f * ( 1.0f - 0.75f ) + 10.0f * 0.75f ) = 7.5f
	f = AVG( 0.0f, 10.0f ); // f = ( ( 0.0f + 10.0f ) * 0.5f ) = 5.0f
	f = SAFE_DIV( 10.0f, 2.0f ); // f = ( 2.0f * 2.0f > 0.0f ? 10.0f / 2.0f : 0.0f ) = 5.0f
	f = SAFE_DIV( 10.0f, 0.0f ); // f = ( 0.0f * 0.0f > 0.0f ? 10.0f / 0.0f : 0.0f ) = 0.0f
	i = FLOOR2INT( 2.5f ); // i = ( ( int )2.5f ) = 2
	f = FLOOR( 2.5f ); // f = ( ( float )FLOOR2INT( 2.5f ) ) = 2.0f
	f = CEIL( 2.5f ); // f = ( 2.5f == FLOOR2INT( 2.5f ) ? 2.5f : FLOOR2INT( 2.5f ) + 1.0f ) = 3.0f
	f = ROUND( 2.5f ); // f = ( 2.5f - FLOOR2INT( 2.5f ) < 0.5 ? FLOOR2INT( 2.5f ) : FLOOR2INT( 2.5f ) + 1.0f ) = 3.0f
	f = DEG2RAD( 90.0f ); // f = ( 90.0f * 0.0174532925f ) = 1.57079633f
	f = RAD2DEG( 1.57079633f ); // f = ( 1.57079633f * 57.2957795f ) = 90.0000001631f
	f = FRACT( 7.5f ); // f = ( 7.5f - FLOOR2INT( 7.5f ) ) = 0.5f

	f = Maths_InvSqrt( 2.0f ); // f = 0.706929624f
	f = Maths_Sqrt( 2.0f ); // f = 1.41385925f
	f = Maths_Sin( 2.0f ); // f = 0.909297407f
	f = Maths_Cos( 2.0f ); // f = -0.416146845f
	f = Maths_Tan( 2.0f ); // f = -2.18503976f
	f = Maths_ASin( 1.0f ); // f = 1.57079637f
	f = Maths_ACos( 1.0f ); // f = 1.00000002e-016f
	f = Maths_ATan( 1.0f ); // f = 0.785398185f
	f = Maths_Pow( 2.0f, 3.0f ); // f = 8.0f
	f = Maths_Exp( 7.5f ); // f = 1808.04236f
	f = Maths_Log( 2.0f ); // f = 0.693147182f

}

void Matrix() {

	float f;
	float * fptr;
	mat4_t m1, m2;

	mat4_t m = {
		{ 1.0f,  2.0f,  3.0f,  4.0f },
		{ 5.0f,  8.0f,  9.0f, 10.0f },
		{ 6.0f, 11.0f, 13.0f, 14.0f },
		{ 7.0f, 12.0f, 15.0f, 16.0f }
	};

	Matrix_Clear( &m ); // m = { 0.0f, 0.0f ...
	Matrix_ToFloatPtr( &m, fptr, MAT4 ); // fptr[] = { m.x.x, m.x.y ...
	Matrix_Mul( &m, &m1, &m2, MAT4 ); // m = m1 * m2
	Matrix_Inverse( &m, &m1, MAT4 ); // m = inverse( m1 )
	f = Matrix_Determinant( &m, MAT4 ); // f = determinant( m )

}

/*

void	Vector_Mix( void * const vector, const void * const left, const void * const right, const void * const mixer );
void	Vector_MinFloat( void * const vector, const void * const left, const float right );
void	Vector_MaxFloat( void * const vector, const void * const left, const float right );
void	Vector_ClampFloat( void * const vector, const void * const input, const float min, const float max );
void	Vector_MixFloat( void * const vector, const void * const left, const void * const right, const float mixer );
void	Vector_Cross( void * const vector, const void * const left, const void * const right );
void	Vector_Normalise( void * const vector, const void * const input, const size_t length );
void	Vector_FaceForward( void * const vector, const void * const n, const void * const i, const void * const nRef, const size_t length );
void	Vector_Reflect( void * const vector, const void * const i, const void * const n, const size_t length );
void	Vector_Refract( void * const vector, const void * const i, const void * const n, const float r, const size_t length );
void	Vector_Ceil( void * const vector, const void * const input );
void	Vector_Floor( void * const vector, const void * const input );
void	Vector_Round( void * const vector, const void * const input );
void	Vector_Radians( void * const vector, const void * const input );
void	Vector_Sin( void * const vector, const void * const input );
void	Vector_Cos( void * const vector, const void * const input );
void	Vector_Tan( void * const vector, const void * const input );
void	Vector_ASin( void * const vector, const void * const input );
void	Vector_ACos( void * const vector, const void * const input );
void	Vector_ATan( void * const vector, const void * const input );
void	Vector_Pow( void * const vector, const void * const input, const void * const powerof );
void	Vector_Exp( void * const vector, const void * const input );
void	Vector_FMA( void * const vector, const void * const a, const void * const b, const void * const c );
void	Vector_Fract( void * const vector, const void * const input );
void	Vector_Sqrt( void * const vector, const void * const input );
void	Vector_InverseSqrt( void * const vector, const void * const input );
void	Vector_Log( void * const vector, const void * const input );
float	Vector_Dot( const void * const left, const void * const right, const size_t length );
float	Vector_Length( const void * const vector, const size_t length );
float	Vector_Distance( const void * const left, const void * const right, const size_t length );
int		Vector_Equal( const void * const left, const void * const right, const size_t length );
int		Vector_GreaterThan( const void * const left, const void * const right, const size_t length );
int		Vector_GreaterThanEqual( const void * const left, const void * const right, const size_t length );
int		Vector_LessThan( const void * const left, const void * const right, const size_t length );
int		Vector_LessThanEqual( const void * const left, const void * const right, const size_t length );

*/

void Vector() {
	
	float * fptr;
	vec4_t v1, v2, v3;
	mat4_t m;

	vec4_t v = { 1.0f, 2.0f, 3.0f, 4.0f };

	Vector_Clear( &v ); // memset( &v, 0.0f, sizeof( vec4_t ) )
	Vector_ToFloatPtr( &v, fptr, VEC4 ); // fptr[] = { v.x, v.y ...
	Vector_Add( &v, &v1, &v2 ); // v = v1 + v2
	Vector_Sub( &v, &v1, &v2 ); // v = v1 - v2
	Vector_Mul( &v, &v1, &v2 ); // v = v1 * v2
	Vector_Div( &v, &v1, &v2 ); // v = v1 / v2
	Vector_MulMatrix( &v, &v1, &m, VEC4 ); // v = v1 * m
	Vector_Min( &v, &v1, &v2 ); // v = min( v1, v2 )
	Vector_Max( &v, &v1, &v2 ); // v = max( v1, v2 )
	Vector_Clamp( &v, &v1, &v2, &v3 ); // v = clamp( v1, v2, v3 )

}

int main( int argc, char ** argv ) {
	Maths();
	Matrix();
	Vector();

	return 1;
}
