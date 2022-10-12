/*
 * BITS.h
 *
 * Created: 10/12/2022 1:04:48 PM
 *  Author: prote
 */ 


#ifndef BITS_H_
#define BITS_H_

#define BIT_SET(byte,bit)   ((byte) |=  (1<<(bit)))
#define BIT_CLEAR(byte,bit) ((byte) &= ~(1<<(bit)))
#define READ_BIT(byte,bit) (((byte) & 1<<(bit)) >> (bit))
#define TOGGLE_BIT(byte,bit)  ((byte) ^=  (1<<(bit)))



#endif /* BITS_H_ */