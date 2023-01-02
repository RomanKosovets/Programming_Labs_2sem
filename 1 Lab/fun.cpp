#include "fun.h"
#include "cmath"

namespace fun
{

    void swap1(int *ta, int *tb) {
        int tmp = *ta;
        *ta = *tb;
        *tb = tmp;
    }
    void swap2(int &ta, int &tb) {
        int tmp = ta;
        ta = tb;
        tb = tmp;
    }

    void rounding1(float *tn, int *tx) {
        *tx = std::round(*tn);
    }
    void rounding2(float &tn, int &tx) {
        tx = std::round(tn);
    }

    void complexnumber1(float *tz_im , float *tz_re, float *tnum) {
        *tz_im = (*tz_im) * (*tnum);
        *tz_re = (*tz_re) * (*tnum);
    }
    void complexnumber2(float &tz_im , float &tz_re, float &tnum) {
        tz_im = tz_im * tnum;
        tz_re = tz_re * tnum;
    }

    void trans_matrix1(int tmatrix[3][3]) {
        int temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = i; j < 3; j++)
            {
                temp = tmatrix[i][j];
                tmatrix[i][j] = tmatrix[j][i];
                tmatrix[j][i] = temp;
            }
        }
    }
    void trans_matrix2(int (&tmatrix)[3][3]) {
        int temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = i; j < 3; j++)
            {
                temp = tmatrix[i][j];
                tmatrix[i][j] = tmatrix[j][i];
                tmatrix[j][i] = temp;
            }
        }
    }
}

