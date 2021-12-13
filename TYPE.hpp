#pragma once

typedef struct {
	// bit filed http://wisdom.sakura.ne.jp/programming/c/c38.html , 2021/12/14
	unsigned int b : 4;
} byte4;

typedef struct {
	unsigned int b : 8;
} byte8;

typedef byte8 WORD;
typedef byte4 DATA;
typedef byte4 OPRATE;
typedef byte4 OPRAND;

#define GET_WORD(v) v.b
#define SET_WORD(v, x) v.b = x
#define GET_DATA(v) GET_WORD(v)
#define SET_DATA(v, x) SET_WORD(v, x)
#define GET_OPRATE(v) GET_WORD(v)
#define SET_OPRATE(v, b) SET_WORD(v, b)
#define GET_OPRAND(v) GET_WORD(v)
#define SET_OPRAND(v, b) SET_WORD(v, b)

#define WORD_SIZE sizeof(WORD)
#define DATA_SIZE sizeof(DATA)
#define OPRATE_SIZE sizeof(OPRATE)
#define OPRAND_SIZE sizeof(OPRAND)
