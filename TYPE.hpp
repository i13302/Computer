#pragma once

typedef struct {
	// bit filed http://wisdom.sakura.ne.jp/programming/c/c38.html , 2021/12/14
	unsigned int b : 4;
} bit4;

typedef struct {
	unsigned int b : 8;
} bit8;

typedef bit8 WORD;
typedef bit4 DATA;
typedef bit4 OPRATE;
typedef bit4 OPRAND;

#define GET_WORD(v) v.b
#define SET_WORD(v, x) v.b = x
#define GET_DATA(v) v.b
#define SET_DATA(v, x) v.b = x
#define GET_OPRATE(v) GET_WORD(v)
#define SET_OPRATE(v, b) SET_WORD(v, b)
#define GET_OPRAND(v) GET_WORD(v)
#define SET_OPRAND(v, b) SET_WORD(v, b)

#define COPY_DATA(d, s) d.b = s.b
#define INC_DATA(d) d.b++
#define DEC_DATA(d) d.b--
#define RESET_DATA(d) d.b = 0

#define WORD_SIZE sizeof(WORD)
#define DATA_SIZE sizeof(DATA)
#define OPRATE_SIZE sizeof(OPRATE)
#define OPRAND_SIZE sizeof(OPRAND)
