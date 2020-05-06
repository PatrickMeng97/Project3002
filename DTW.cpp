#include"DTW.h"
#include"distance.h"
#include"bmp_image.h"
#include"zncc.h"

DTW::DTW() {
    Ymax = Ymax = X = NULL;
}
DTW::DTW(int Ymin, int Ymax, int X){
	this->Ymax = Ymax;
	this->Ymin = Ymin;
	this->X = X;
}

double DTW::cosDTW(BMP_Image **data1, BMP_Image**data2){

    Distance dist;
    float P_XY[100][100];   // Path matrix
    float p_xy[100][100];  // matrix of item to item distance

    int dtw[100][100];
    int tmp_dtw0[100], tmp_dtw1[100];
    int dtw0[100], dtw1[100];
    float BIG = 100000;

    int w = abs(Ymax - X) + 1;  // add 1 here for equal length dtw (otherwise performing linear mapping)

    for (int x = 0; x < 1; x++) // num of clips
        for (int i = 0; i <= X; i++) // num of i frames
            for (int j = 0; j <= Ymax; j++)  // num of j frames
            {
                p_xy[i][j] = dist.Cosine2d(data1[x][i].b_data, data2[x][j].b_data,300, 300);
            }

    // init
    for (int i = 0; i <= X; i++)
        for (int j = 0; j <= Ymax; j++) P_XY[i][j] = BIG;

    P_XY[0][0] = p_xy[0][0]; dtw[0][0] = 0; // null
    for (int i = 1; i <= w; i++)
    {
        P_XY[i][0] = P_XY[i - 1][0] + p_xy[i][0]; dtw[i][0] = 1;
    } // horizontal
    for (int j = 1; j <= w; j++)
    {
        P_XY[0][j] = P_XY[0][j - 1] + p_xy[0][j]; dtw[0][j] = 2;
    } // vertical

// recursion
    for (int j = 1; j <= Ymax; j++) {
        int i0 = j - w; if (i0 < 1) i0 = 1;
        int i1 = j + w; if (i1 > X) i1 = X;
        for (int i = i0; i <= i1; i++) {
            float h = P_XY[i - 1][j] + p_xy[i][j];
            float d = P_XY[i - 1][j - 1] + p_xy[i][j];
            float v = P_XY[i][j - 1] + p_xy[i][j];
            if (d < h && d < v)
            {
                P_XY[i][j] = d; dtw[i][j] = 3;
            } // diagonal
            else if (h < v)
            {
                P_XY[i][j] = h; dtw[i][j] = 1;
            }
            else { P_XY[i][j] = v; dtw[i][j] = 2; }
            if ((h == d) && (d == v))
            {
                P_XY[i][j] = d; dtw[i][j] = 3;
            }
        }
    }

    // best path, normalization, best warp within u+rmin ~ u+rmax
    float Q = BIG; int J, L;
    for (int j0 = Ymin; j0 <= Ymax; j0++) {
        // path backtracking
        int i = X, j = j0, l = 0;
        tmp_dtw0[l] = i; tmp_dtw1[l] = j;
        while (i > 0 || j > 0) {
            l++;
            if (dtw[i][j] == 1)
            {
                i -= 1;
            }
            else if (dtw[i][j] == 2)
            {
                j -= 1;
            }
            else if (dtw[i][j] == 3)
            {
                i -= 1; j -= 1;
            }

            tmp_dtw0[l] = i; tmp_dtw1[l] = j;
        }

        // number-of-local-distances based normalization
        P_XY[X][j0] *= (float)(X + 1) / (float)(l + 1);

        // best warp
        if (P_XY[X][j0] <= Q) {

            Q = P_XY[X][j0];
            J = j0;
            L = l;

            ofstream of("Result.txt", ios::app);
            of << "The warping distance is " << Q << endl;
            cout << "The warping distance is " << Q << endl;
            of << endl;
            of.close();
        }
    }
    return Q;
}

double DTW::euDTW(BMP_Image** data1, BMP_Image** data2) {
    Distance dist;
    float P_XY[100][100];   // Path matrix
    float p_xy[100][100];  // matrix of item to item distance

    int dtw[100][100];
    int tmp_dtw0[100], tmp_dtw1[100];
    int dtw0[100], dtw1[100];
    float BIG = 100000;

    int w = abs(Ymax - X) + 1;  // add 1 here for equal length dtw (otherwise performing linear mapping)

    for (int x = 0; x < 1; x++) // num of clips
        for (int i = 0; i <= X; i++) // num of i frames
            for (int j = 0; j <= Ymax; j++)  // num of j frames
            {
                p_xy[i][j] = dist.Euclidean2d(data1[x][i].b_data, data2[x][j].b_data,300, 300);
            }

    // init
    for (int i = 0; i <= X; i++)
        for (int j = 0; j <= Ymax; j++) P_XY[i][j] = BIG;

    P_XY[0][0] = p_xy[0][0]; dtw[0][0] = 0; // null
    for (int i = 1; i <= w; i++)
    {
        P_XY[i][0] = P_XY[i - 1][0] + p_xy[i][0]; dtw[i][0] = 1;
    } // horizontal
    for (int j = 1; j <= w; j++)
    {
        P_XY[0][j] = P_XY[0][j - 1] + p_xy[0][j]; dtw[0][j] = 2;
    } // vertical

// recursion
    for (int j = 1; j <= Ymax; j++) {
        int i0 = j - w; if (i0 < 1) i0 = 1;
        int i1 = j + w; if (i1 > X) i1 = X;
        for (int i = i0; i <= i1; i++) {
            float h = P_XY[i - 1][j] + p_xy[i][j];
            float d = P_XY[i - 1][j - 1] + p_xy[i][j];
            float v = P_XY[i][j - 1] + p_xy[i][j];
            if (d < h && d < v)
            {
                P_XY[i][j] = d; dtw[i][j] = 3;
            } // diagonal
            else if (h < v)
            {
                P_XY[i][j] = h; dtw[i][j] = 1;
            }
            else { P_XY[i][j] = v; dtw[i][j] = 2; }
            if ((h == d) && (d == v))
            {
                P_XY[i][j] = d; dtw[i][j] = 3;
            }
        }
    }

    // best path, normalization, best warp within u+rmin ~ u+rmax
    float Q = BIG; int J, L;
    for (int j0 = Ymin; j0 <= Ymax; j0++) {
        // path backtracking
        int i = X, j = j0, l = 0;
        tmp_dtw0[l] = i; tmp_dtw1[l] = j;
        while (i > 0 || j > 0) {
            l++;
            if (dtw[i][j] == 1)
            {
                i -= 1;
            }
            else if (dtw[i][j] == 2)
            {
                j -= 1;
            }
            else if (dtw[i][j] == 3)
            {
                i -= 1; j -= 1;
            }

            tmp_dtw0[l] = i; tmp_dtw1[l] = j;
        }

        // number-of-local-distances based normalization
        P_XY[X][j0] *= (float)(X + 1) / (float)(l + 1);

        // best warp
        if (P_XY[X][j0] <= Q) {

            Q = P_XY[X][j0];
            J = j0;
            L = l;

            ofstream of("Result.txt", ios::app);
            of << "The warping distance is " << Q << endl;
            cout << "The warping distance is " << Q << endl;
            of << endl;
            of.close();
        }
    }
    return Q;
}

double DTW::znccDTW(BMP_Image** data1, BMP_Image** data2) {


    Zncc zn;

    float P_XY[100][100];   // Path matrix
    float p_xy[100][100];  // matrix of item to item distance

    int dtw[100][100];
    int tmp_dtw0[100], tmp_dtw1[100];
    int dtw0[100], dtw1[100];
    float BIG = 100000;

    int w = abs(Ymax - X) + 1;  // add 1 here for equal length dtw (otherwise performing linear mapping)

    for (int x = 0; x < 1; x++) // num of clips
        for (int i = 0; i <= X; i++) // num of i frames
            for (int j = 0; j <= Ymax; j++)  // num of j frames
            {
                p_xy[i][j] = zn.calZncc(data1[x][i].b_data, data2[x][j].b_data, 300, 300);
            }

    // init
    for (int i = 0; i <= X; i++)
        for (int j = 0; j <= Ymax; j++) P_XY[i][j] = BIG;

    P_XY[0][0] = p_xy[0][0]; dtw[0][0] = 0; // null
    for (int i = 1; i <= w; i++)
    {
        P_XY[i][0] = P_XY[i - 1][0] + p_xy[i][0]; dtw[i][0] = 1;
    } // horizontal
    for (int j = 1; j <= w; j++)
    {
        P_XY[0][j] = P_XY[0][j - 1] + p_xy[0][j]; dtw[0][j] = 2;
    } // vertical

// recursion
    for (int j = 1; j <= Ymax; j++) {
        int i0 = j - w; if (i0 < 1) i0 = 1;
        int i1 = j + w; if (i1 > X) i1 = X;
        for (int i = i0; i <= i1; i++) {
            float h = P_XY[i - 1][j] + p_xy[i][j];
            float d = P_XY[i - 1][j - 1] + p_xy[i][j];
            float v = P_XY[i][j - 1] + p_xy[i][j];
            if (d < h && d < v)
            {
                P_XY[i][j] = d; dtw[i][j] = 3;
            } // diagonal
            else if (h < v)
            {
                P_XY[i][j] = h; dtw[i][j] = 1;
            }
            else { P_XY[i][j] = v; dtw[i][j] = 2; }
            if ((h == d) && (d == v))
            {
                P_XY[i][j] = d; dtw[i][j] = 3;
            }
        }
    }


    // best path, normalization, best warp within u+rmin ~ u+rmax
    float Q = BIG; int J, L;
    for (int j0 = Ymin; j0 <= Ymax; j0++) {
        // path backtracking
        int i = X, j = j0, l = 0;
        tmp_dtw0[l] = i; tmp_dtw1[l] = j;
        while (i > 0 || j > 0) {
            l++;
            if (dtw[i][j] == 1)
            {
                i -= 1;
            }
            else if (dtw[i][j] == 2)
            {
                j -= 1;
            }
            else if (dtw[i][j] == 3)
            {
                i -= 1; j -= 1;
            }

            tmp_dtw0[l] = i; tmp_dtw1[l] = j;
        }

        // number-of-local-distances based normalization
        P_XY[X][j0] *= (float)(X + 1) / (float)(l + 1);


        // best warp
        if (P_XY[X][j0] <= Q) {

            Q = P_XY[X][j0];
            J = j0;
            L = l;

            ofstream of("Result.txt", ios::app);

            of << "The warping distance is " << Q << endl;
            of << "The traing data set has " << X << " image"<< endl;
            of << "The maximum detection image number is " << Ymax << endl;
            of << endl;
            cout << "The warping distance is " << Q << endl;
            of.close();
        }

    }
    return Q;
}