#ifndef csh_tiro_cc_fft_int16FFT
#define csh_tiro_cc_fft_int16FFT

typedef unsigned char   uint8_t;           /* unsigned 8 bits */
typedef signed char     int8_t;            /* signed 8 bits */
typedef unsigned short  uint16_t;          /* unsigned 16 bits */
typedef short           int16_t;           /* signed 16 bits */
typedef int             int32_t;           /* signed 32 bits */
typedef unsigned int    uint32_t;          /* unsigned 32 bits */

#define NUM_FFT 128
/*
 *   FFT的大小可以取 2^n 次方,最大可以设置到1024,可以取值为
 *   4,8，16，32，64，128，256，512，1024中的一个
 *   给数据时.按照设定的长度给数据.三个函数都一样.
 */
#define WINDOW_TYPE 3
/* FFT 加窗口类型.可以定义如下类型
 *  0:不加窗口
 *  1:三角窗
 *  2:汉宁窗
 *  3:汉明窗
 *  4:布莱克曼窗
 *  这几种窗口的函数定义和特性可以在百度百科上面找到
 */

extern void int16FFT_WindowCalc(int16_t * Win_Arrayref, int8_t SE_data);
extern void int16FFT_Bit_Reverse(int16_t * BR_Arrayref);
extern void int16FFT_FFT(int16_t *  ReArrayref, int16_t * ImArrayref);

#endif
