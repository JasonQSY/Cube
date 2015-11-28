#include <stdio.h>
#define LENGTH 10000
#define WIDTH 50
char img[LENGTH][WIDTH];

void draw(int x, int y){
    int i;
    
    for(i=0;i<4;i++){
        img[x-i][y]='|';
        img[x-i][y+10]='|';
        img[x-3-i][y+13]='|';
    }
    for(i=1;i<=9;i++){
        img[x][y+i]='_';
        img[x-1][y+i]=' ';
        img[x-2][y+i]=' ';
        img[x-3][y+i]=' ';
        img[x-4][y+i]='_';
        img[x-5][y+1+i]=' ';
        img[x-6][y+2+i]=' ';
        img[x-7][y+3+i]='_';
    }
    for(i=0;i<3;i++){
        img[x-4-i][y+i]='/';
        img[x-4-i][y+10+i]='/';
        img[x-i][y+11+i]='/';
    }
    img[x-1][y+11]=' ';
    img[x-2][y+11]=' ';
    img[x-2][y+12]=' ';
    img[x-3][y+11]=' ';
    img[x-3][y+12]=' ';
    img[x-4][y+11]=' ';
    img[x-4][y+12]=' ';
    img[x-5][y+12]=' ';
}

int main()
{
    int A[3][3]={10,-1,0,
                 1,2,-1,
                 0,1,0};
    FILE *fp =NULL ;
    int i,j,m;
    int max=0,min=0,start;
    
    /* initialize and get the initial position */
    for (i=0;i<3;i++){
        for (j=0; j<3; j++){
            if(A[i][j]>max){
                max=A[i][j];
            }
        }
    }
    for (i=0;i<3;i++){
        for (j=0; j<3; j++){
            if(A[i][j]<min){
                min=A[i][j];
            }
        }
    }
    start=6*max+5; //remain some space for safety and beauty
    for (i=0; i<start+20; i++) {
        for (j=0; j<WIDTH; j++) {
            img[i][j]=' ';
        }
    }
    /* start drawing */
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (A[i][j]<0) {
                for (m=A[i][j]; m<0; m++) {
                    draw(start-6+3*i-4*m,6-3*i+10*j);
                }
            }
            for (m=0; m<A[i][j]; m++) {
                draw(start-6+3*i-4*m,6-3*i+10*j);
            }
        }
    }
    /* output the cube */
    /* command window */
    for (i=0; i<start+20; i++) {
        for (j=0; j<WIDTH; j++) {
            printf("%c",img[i][j]);
        }
        printf("\n");
    }
    /* txt file */
    /*
    fp=fopen("cube.txt" , "w" );
    for (i=0; i<start+1; i++) {
        for (j=0; j<WIDTH; j++) {
            fprintf(fp,"%c",img[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("Success\n");*/
    return 0;
}
