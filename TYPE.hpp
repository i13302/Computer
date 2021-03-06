#pragma once

typedef struct {
	unsigned int b : 2;
} bit2;

typedef struct {
	// bit filed http://wisdom.sakura.ne.jp/programming/c/c38.html , 2021/12/14
	unsigned int b : 4;
} bit4;

typedef struct {
	unsigned int b : 8;
} bit8;

typedef bit4 WORD;
typedef bit4 DATA;
typedef bit4 ADDR;
typedef bit4 OPRATE;
typedef bit4 OPRAND;
typedef bit2 PORT;

#define GET_WORD(v) v.b
#define SET_WORD(v, x) v.b = x
#define GET_DATA(v) v.b
#define SET_DATA(v, x) v.b = x
#define GET_OPRATE(v) GET_WORD(v)
#define SET_OPRATE(v, b) SET_WORD(v, b)
#define GET_OPRAND(v) GET_WORD(v)
#define SET_OPRAND(v, b) SET_WORD(v, b)

#define PTR_GET_WORD(v) v->b
#define PTR_SET_WORD(v, x) v->b = x
#define PTR_GET_DATA(v) v->b
#define PTR_SET_DATA(v, x) v->b = x

#define COPY_WORD(d, s) d.b = s.b
#define COPY_DATA(d, s) COPY_WORD(d, s)
#define INC_WORD(d) d.b++
#define INC_DATA(d) INC_WORD(d)
#define DEC_DATA(d) d.b--

#define WORD_SIZE 16
#define DATA_SIZE 16
#define OPRATE_SIZE 16
#define OPRAND_SIZE 16

#define PORT_SIZE 4
