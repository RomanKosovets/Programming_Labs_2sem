#ifndef PROJECT_C___2_FUN_H
#define PROJECT_C___2_FUN_H

namespace fun
{
    void swap1 (int *, int *);
    void swap2 (int &, int &);

    void rounding1 (float *, int *);
    void rounding2 (float &, int &);

    void complexnumber1 (float *, float *, float *);
    void complexnumber2 (float &, float &, float &);

    void trans_matrix1(int array[3][3]);
    void trans_matrix2(int (&array)[3][3]);
}
#endif
