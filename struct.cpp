#include <iostream>
#include <cstring>
#include <time.h>

#define __M__ 12
#define __N__ 24
#define __ITER_NUM__ 1024
#define __ELE_SIZE__ 64


using namespace std;

// order ? transpose read and write
// memcpy or =
// multithread

struct ele
{
    char _[__ELE_SIZE__];
};

ele src[__ITER_NUM__][__M__][__N__];
ele transpose[__ITER_NUM__][__N__][__M__];

void use_array()
{
    ele empty;
    for(int iter = 0; iter < __ITER_NUM__; ++iter)
        for(int i = 0; i < __M__; ++i)
            for(int j = 0; j < __N__; ++j)
                src[iter][i][j] = empty;

    clock_t start = clock();
    for(int iter = 0; iter < __ITER_NUM__; ++iter)
        for(int i = 0; i < __M__; ++i)
        {
            for(int j = 0; j < __N__; ++j)
            {
                transpose[iter][j][i] = src[iter][i][j];
            }
        }
    clock_t end = clock();
    cout<<"transpose copy costs "<<
        (double)(end - start) / CLOCKS_PER_SEC<<" s"<<endl;


}

int main()
{
    use_array();
    return 0;
}