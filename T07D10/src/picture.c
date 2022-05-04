#include <stdio.h>
#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void output(int **a, int n1, int n2);

int main() {
   int picture_data[N][M];
   int *picture[N];
   transform(picture_data, picture, N, M);
   reset_picture(picture, N, M);
   make_picture(picture, N, M);
   output(picture_data, N, M);
   return 0;
}

void make_picture(int **picture, int n, int m) {
   int frame_w[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int frame_h[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int tree_trunk[] = { 7, 7, 7, 7 };
   int tree_foliage[] = { 3, 3, 3, 3 };
   int sun_data[3][3] = { { 6, 6, 6 }, { 0, 6, 6 }, { 6, 0, 6 } };

   reset_picture(picture, n, m);

   int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
   //int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

   for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
   }
}

void reset_picture(int **picture, int n, int m) {
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         picture[i][j] = 0;
      }  
   }
}

void transform(int *buf, int **matr, int n, int m) {  
   for(int i = 0; i < n; i++) {
      matr[i] = buf + i * m;
   }
}

void output(int **a, int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (j != n2 - 1)
                printf("%d ", a[i][j]);
            else
                printf("%d", a[i][j]);
        }
        printf("\n");
    }
}