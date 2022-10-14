#include <iostream>
#include <cstring>
#include <time.h>

#define __M__ 12
#define __N__ 24
#define __ITER_NUM__ 1024
#define __ELE_SIZE__ 64
#define __THREAD__ 4

using namespace std;

char src[__ITER_NUM__][__M__][__N__][__ELE_SIZE__];
char org[__ITER_NUM__][__M__][__N__][__ELE_SIZE__];
char transpose[__ITER_NUM__][__N__][__M__][__ELE_SIZE__];


void use_array()
{


    for(int iter = 0; iter < __ITER_NUM__; ++iter)
        for(int i = 0; i < __M__; ++i)
            for(int j = 0; j < __N__; ++j)
                memcpy(src[iter][i][j], "shit", __ELE_SIZE__);

    clock_t start = clock();
    #pragma omp parallel for num_threads(__THREAD__)
    for(int iter = 0; iter < __ITER_NUM__; ++iter)
        for(int i = 0; i < __M__; ++i)
        {
            for(int j = 0; j < __N__; ++j)
            {
                memcpy(transpose[iter][j][i], src[iter][i][j], __ELE_SIZE__);
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