#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARY_PRINT(ary,size,max,msg,...) \
    do{\
        for( int _ary_i = 0 ; _ary_i < size ; _ary_i++) { \
            printf(msg,__VA_ARGS__);\
            if ( (_ary_i + 1 ) % max == 0 ) {\
                printf("\n");\
            }\
        }\
        printf("\n");\
    }while(0);
typedef struct _tmp_element_t {
	int rand_num ;
	int idx;
} tmp_element_t;
/*
 * Random Index Generation
 * For generating random indexing, we create a this function to produce index randomly.
 * It first generates random numbers according to the input of array, 
 * idx[] size and store those numbers in an size-equal array of the tmp_element_t. 
 * The tmp_element_t contains two member: rand_num and idx, when generating random number, 
 * the rand_num holds the random number and idx is initialized sequecely from zero.
 * After got all random numbers, we sort the array of the tmp_element_t descendingly. 
 * Those sorted numbers comply with pre-defined index, we assign those index into idx[], and finally the random ordered index was got.
 */

void randomOrderIndexTest(int idx[], int size) {
    srand(time(NULL));
    tmp_element_t *tmp = (tmp_element_t*) calloc(sizeof(tmp_element_t), size);
    int max = size * 100;
    int i = 0 , j = 0 ;
    for ( i = 0 ; i < size ; i++ ) {
        tmp[i].rand_num = rand()%max;
        tmp[i].idx = i;
    }
    //ARY_PRINT(tmp, size, 16,"%d(%d) ",tmp[_ary_i].rand_num, tmp[_ary_i].idx);
    tmp_element_t x;
    for ( i = 0 ; i < size ; i++ ) {
        for ( j = 0 ; j < size ; j++ ) { 
            if ( tmp[i].rand_num > tmp[j].rand_num ) {
                memmove( &x, &tmp[i], sizeof(tmp_element_t));
                memmove( &tmp[i], &tmp[j], sizeof(tmp_element_t));
                memmove( &tmp[j], &x, sizeof(tmp_element_t));
            }
        }
    }
    //ARY_PRINT(tmp, size, 16,"%d(%d) ",tmp[_ary_i].rand_num, tmp[_ary_i].idx);
    for ( i = 0 ; i < size ; i++ ){
        idx[i] = tmp[i].idx;
    } 
    //ARY_PRINT(idx, size, 16,"%d:%d ",_ary_i,idx[_ary_i]);
	free(tmp);
}
