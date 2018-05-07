// v.1.3.1
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include<stdalign.h>//untuk random
#include<time.h>
#include<math.h>

using namespace std;

bool menang=false;
int ganjil=1;
int genap=0;
int kotak=2;
int turn=1;
int dx1=0;
int dy1=0;
int dx2=0;
int dy2=0;
float dx_ob = 0;
float dy_ob = 0;

void box(float x1, float y1, float z1, float x2, float y2, float z2){
    //kiri bawah belakang ----- kanan atas depan
    glBegin(GL_QUADS);
        //belakang
//        glColor3f(1,0,0);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y2, z1);
        glVertex3f(x1, y2, z1);

        //depan
//        glColor3f(1,1,0);
        glVertex3f(x1, y1, z2);
        glVertex3f(x1, y2, z2);
        glVertex3f(x2, y2, z2);
        glVertex3f(x2, y1, z2);

        //bottom
//        glColor3f(1,0,1);
        glVertex3f(x1,y1,z1);
        glVertex3f(x2,y1,z1);
        glVertex3f(x2,y1,z2);
        glVertex3f(x1,y1,z2);

        //top
//        glColor3f(0,1,0);
        glVertex3f(x1,y2,z1);
        glVertex3f(x1,y2,z2);
        glVertex3f(x2,y2,z2);
        glVertex3f(x2,y2,z1);

        //left
//        glColor3f(0,1,1);
        glVertex3f(x1,y1,z1);
        glVertex3f(x1,y1,z2);
        glVertex3f(x1,y2,z2);
        glVertex3f(x1,y2,z1);

        //right
//        glColor3f(1,1,1);
        glVertex3f(x2,y1,z1);
        glVertex3f(x2,y1,z2);
        glVertex3f(x2,y2,z2);
        glVertex3f(x2,y2,z1);
    glEnd();
}
void box24(float x1, float y1, float z1, float x2, float y2, float z2,
           float x3, float y3, float z3, float x4, float y4, float z4,
           float x5, float y5, float z5, float x6, float y6, float z6,
           float x7, float y7, float z7, float x8, float y8, float z8 ){
    /*
        x1 = pojok kiri bawah depan
        x2 = pojok kanan bawah depan
        x3 = pojok kanan atas depan
        x4 = pojok kiri atas depan
        x5 = pojok kiri bawah belakang
        x6 = pojok kanan bawah belakang
        x7 = pojok kanan atas belakang
        x8 = pojok kiri atas belakang
    */
    //kiri bawah belakang ----- kanan atas depan
    glBegin(GL_QUADS);
        //belakang
//        glColor3f(1,0,0);
        glVertex3f(x5, y5, z5);
        glVertex3f(x8, y8, z8);
        glVertex3f(x7, y7, z7);
        glVertex3f(x6, y6, z6);

        //depan
//        glColor3f(1,1,0);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x3, y3, z3);
        glVertex3f(x4, y4, z4);

        //bottom
//        glColor3f(1,0,1);
        glVertex3f(x1,y1,z1);
        glVertex3f(x5,y5,z5);
        glVertex3f(x6,y6,z6);
        glVertex3f(x2,y2,z2);

        //top
//        glColor3f(0,1,0);
        glVertex3f(x4,y4,z4);
        glVertex3f(x3,y3,z3);
        glVertex3f(x7,y7,z7);
        glVertex3f(x8,y8,z8);

        //left
//        glColor3f(0,1,1);
        glVertex3f(x1,y1,z1);
        glVertex3f(x4,y4,z4);
        glVertex3f(x8,y8,z8);
        glVertex3f(x5,y5,z5);

        //right
//        glColor3f(1,1,1);
        glVertex3f(x3,y3,z3);
        glVertex3f(x2,y2,z2);
        glVertex3f(x6,y6,z6);
        glVertex3f(x7,y7,z7);
    glEnd();
}

void nol(int x,int y, bool puluhan){
    float x1=0;
    float y1=y+0.1;
    if (puluhan){
        x1=x+0.1;
    }else{
        x1=x+0.5;
    }
    box(x1,     y1,     0,x1+0.1, y1+0.5,0.5);
    box(x1+0.2, y1,     0,x1+0.3, y1+0.5,0.5);
    box(x1,     y1,     0,x1+0.3, y1+0.1,0.5);
    box(x1,     y1+0.4, 0,x1+0.3, y1+0.5,0.5);
}
void dua(int x,int y, bool puluhan){
    float x1=0;
    float y1=y+0.1;
    if (puluhan){
        x1=x+0.1;
    }else{
        x1=x+0.5;
    }
    box(x1,    y1,     0,x1+0.1, y1+0.3,0.5);
    box(x1+0.2,y1+0.2, 0,x1+0.3, y1+0.5,0.5);
    box(x1,    y1,     0,x1+0.3, y1+0.1,0.5);
    box(x1,    y1+0.2, 0,x1+0.3, y1+0.3,0.5);
    box(x1,    y1+0.4, 0,x1+0.3, y1+0.5,0.5);
}
void tiga(int x,int y, bool puluhan){
    float x1=0;
    float y1=y+0.1;
    if (puluhan){
        x1=x+0.1;
    }else{
        x1=x+0.5;
    }
    box(x1+0.2,y1,     0,x1+0.3, y1+0.5,0.5);
    box(x1,    y1,     0,x1+0.3, y1+0.1,0.5);
    box(x1,    y1+0.2, 0,x1+0.3, y1+0.3,0.5);
    box(x1,    y1+0.4, 0,x1+0.3, y1+0.5,0.5);
}
void angka(int x, int y, int counter){
     int puluhan= counter/10;
     int satuan= counter%10;
     glColor4f(1,0,0, 1.0);
     if (satuan==0){
        nol(x*kotak +1, y*kotak+1, false);
     }else if(satuan==2){
        dua(x*kotak+1, y*kotak+1, false);
     }else if(satuan==3){
        tiga(x*kotak+1, y*kotak+1, false);
     }
     if(puluhan==2){
        dua(x*kotak+1, y*kotak+1, true);
     }else if(puluhan==3){
        tiga(x*kotak+1, y*kotak+1, true);
     }
}

void tangga(float x1, float y1, float x2, float y2){
 glColor4f(0.84, 0.46, 0.04, 1.0);
 if (y1==y2){
     for (float x=x1; x<x2-1; x+=1){
         box(x,     y1-0.6,0, x+2,   y1-0.4,0.5);
         box(x,     y1+0.6,0, x+2,   y1+0.4,0.5);
         box(x+0.9, y1-0.6,0, x+1.1, y1+0.6,0.5);
     }
 } else{
    float derajat;
    if (x1<x2){
        derajat=0.25;
    }else if (x1==x2){
        derajat=0;
    }else{
        derajat=-0.25;
    }

    for (float i=0.5; i<5; i+=0.5){
        box24(x1+((x2-x1)*i/5)-0.4,  y1+((y2-y1)*i/5)+0.1 +derajat, 0,          x1+((x2-x1)*i/5)-0.55, y1+((y2-y1)*i/5)-0.1 +derajat, 0,
              x1+((x2-x1)*i/5)+0.4,  y1+((y2-y1)*i/5)-0.1 -derajat, 0,          x1+((x2-x1)*i/5)+0.55, y1+((y2-y1)*i/5)+0.1 -derajat, 0,
              x1+((x2-x1)*i/5)-0.4,  y1+((y2-y1)*i/5)+0.1 +derajat, 1,          x1+((x2-x1)*i/5)-0.55, y1+((y2-y1)*i/5)-0.1 +derajat, 1,
              x1+((x2-x1)*i/5)+0.4,  y1+((y2-y1)*i/5)-0.1 -derajat, 1,          x1+((x2-x1)*i/5)+0.55, y1+((y2-y1)*i/5)+0.1 -derajat, 1);
    }

    box24(x1-0.6, y1+derajat, 1,    x1-0.4, y1+derajat, 1,
          x2-0.4, y2+derajat, 1,    x2-0.6, y2+derajat, 1,
          x1-0.6, y1+derajat, 0,    x1-0.4, y1+derajat, 0,
          x2-0.4, y2+derajat, 0,    x2-0.6, y2+derajat, 0);

    box24(x1+0.4, y1-derajat, 1,    x1+0.6, y1-derajat, 1,
          x2+0.6, y2-derajat, 1,    x2+0.4, y2-derajat, 1,
          x1+0.4, y1-derajat, 0,    x1+0.6, y1-derajat, 0,
          x2+0.6, y2-derajat, 0,    x2+0.4, y2-derajat, 0);

 }
}

void ular(float x1, float y1, float x2, float y2){
    glColor4f(0.49, 0.49, 0.67, 1.0);
    box24(x1-0.25, y1+ 0*(y2-y1)/3, 1,                  x1+0.25, y1+ 0*(y2-y1)/3, 1,
              x1+ (x2-x1)/2+0.25, y1+ 1*(y2-y1)/3, 1,   x1+ (x2-x1)/2-0.25, y1+ 1*(y2-y1)/3, 1,
              x1-0.25, y1+ 0*(y2-y1)/3, 0,              x1+0.25, y1+ 0*(y2-y1)/3, 0,
              x1+ (x2-x1)/2+0.25, y1+ 1*(y2-y1)/3, 0,   x1+ (x2-x1)/2-0.25, y1+ 1*(y2-y1)/3, 0);
    glColor4f(0.35, 0.25,0.29, 1.0);
    box24(x1+ (x2-x1)/2+0.25, y1+ 1*(y2-y1)/3,1,        x1+ (x2-x1)/2-0.25, y1+ 1*(y2-y1)/3,1,
          x1+ (x2-x1)/2-0.25, y1+ 2*(y2-y1)/3,1,        x1+ (x2-x1)/2+0.25, y1+ 2*(y2-y1)/3,1,
          x1+ (x2-x1)/2+0.25, y1+ 1*(y2-y1)/3,0,        x1+ (x2-x1)/2-0.25, y1+ 1*(y2-y1)/3,0,
          x1+ (x2-x1)/2-0.25, y1+ 2*(y2-y1)/3,0,        x1+ (x2-x1)/2+0.25, y1+ 2*(y2-y1)/3,0);
    glColor4f(0.49, 0.49, 0.67, 1.0);
    box24(x1+ (x2-x1)/2-0.25, y1+ 2*(y2-y1)/3,1,        x1+ (x2-x1)/2+0.25, y1+ 2*(y2-y1)/3,1,
          x2+0.25, y1+ 3*(y2-y1)/3,1,                   x2-0.25, y1+ 3*(y2-y1)/3,1,
          x1+ (x2-x1)/2-0.25, y1+ 2*(y2-y1)/3,0,        x1+ (x2-x1)/2+0.25, y1+ 2*(y2-y1)/3,0,
          x2+0.25, y1+ 3*(y2-y1)/3,0,                   x2-0.25, y1+ 3*(y2-y1)/3,0);
}

void papan(){
 glColor4f(1,0,0, 1.0); //warna border luar
 box(-0.15,-0.15,-0.2,      42.15,0,0.5);
 box(-0.15,8,-0.2,          42.15,8.15,0.5);
 box(-0.15,-0.15,-0.2,      0,8.15,0.5);
 box(42,-0.15,-0.2,         42.15,8.15,0.5);
 int counter=1;
 int max_kolom=20;
 for (int y=0; y<4; y++){
     for (int x=0; x<21; x++){
         if (y%2==ganjil ){
            angka(max_kolom-x, y,counter);
         }else {
            angka(x,y,counter);
         }
         counter++;
     }
     //border
     if (y%2==ganjil){
        box(0*kotak, y*kotak-0.05, 0,     20*kotak, y*kotak+0.05, 0.5);
     }else if (y!=0){
        box(1*kotak, y*kotak-0.05,0,      21*kotak, y*kotak+0.05, 0.5);
     }

     for (int x=0; x<21; x++){
         if (x%2==genap && y%2==ganjil ||
             x%2==ganjil && y%2==genap){
            glColor4f(0.56, 0.77, 0.77, 0.5);
         } else {
            glColor4f(0.2, 0.4, 0.6, 0.5);
         }
//         glBegin(GL_POLYGON);
            box(x*kotak, y*kotak, -0.2, x*kotak+2, y*kotak+2, 0);
//             glVertex2f(x*kotak,    y*kotak);
//             glVertex2f(x*kotak+2,  y*kotak);
//             glVertex2f(x*kotak+2,  y*kotak+2);
//             glVertex2f(x*kotak,    y*kotak+2);
//         glEnd();
     }
 }
}

void pemain1(){
    glColor4f(1, 0.5, 0.5, 1.0);
    box24(0.75+dx1,1.15+dy1,1,           1.25+dx1,1.15+dy1,1,
            1.25+dx1,1.5+dy1,1,            0.75+dx1,1.5+dy1,1,
            0.75+dx1,1.15+dy1,0,           1.25+dx1,1.15+dy1,0,
            1.25+dx1,1.5+dy1,0,            0.75+dx1,1.5+dy1,0);

}

void pemain2(){
    glColor4f(0.5,1,0.5, 1.0);
    box24(0.75+dx2,0.5+dy2,1,        1.00+dx2,0.5+dy2,1,
          1.25+dx2,1.00+dy2,1,       0.75+dx2,1.00+dy2,1,
          0.75+dx2,0.5+dy2,0,        1.00+dx2,0.5+dy2,0,
          1.25+dx2,1.00+dy2,0,       0.75+dx2,1.00+dy2,0);

}

void observer(){
    glColor4f(1,1,1, 1.0);
    box(0+dx_ob,0+dy_ob,0,  0.5+dx_ob, 0.5+dy_ob, 0.5);
}

void display(){
 glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
// glTranslated(21.25, 4.25,0);
// glRotated(45, 1,1,1);
// glTranslated(-21.25, -4.25,0);

// box24(5-0.6, 0+0.25, 1,        5-0.4, 0+0.25,1,
//       11-0.4, 7+0.25,1,        11-0.6, 7+0.25,1,
//       5-0.6, 0+0.25, 0,        5-0.4, 0+0.25,0,
//       11-0.4, 7+0.25,0,        11-0.6, 7+0.25,0);


 ular(3*kotak+1,    1*kotak+1, 1*kotak+1,   3*kotak+1);
 ular(9*kotak+1,   0*kotak+1, 14*kotak+1,  3*kotak+1);
 ular(18*kotak+1,   0*kotak+1, 16*kotak+1,  2*kotak+1);
 ular(9*kotak+1,    1*kotak+1, 5*kotak+1,   3*kotak+1);

 tangga(1*kotak+1,  0*kotak+1, 4*kotak+1,   3*kotak+1);
 tangga(4*kotak+1,  1*kotak+1, 8*kotak+1,   1*kotak+1);
 tangga(15*kotak+1, 0*kotak+1, 15*kotak+1,  3*kotak+1);
 tangga(9*kotak+1, 2*kotak+1, 14*kotak+1,  2*kotak+1);
 tangga(20*kotak+1, 0*kotak+1, 17*kotak+1,  3*kotak+1);

 pemain1();
 pemain2();
 observer();
 papan();
// glutSwapBuffers();
 glFlush();
}

int* cek(int dx, int dy){
    //Cek kotak ular or tangga
    //Kotak x_gambar-1
    if (dx==1*kotak && dy==0*kotak){
        dx=4*kotak;
        dy=3*kotak;
    } else if (dx==8*kotak && dy==1*kotak){
        dx=4*kotak;
        dy=1*kotak;
    } else if (dx==15*kotak && dy==0*kotak){
        dx=15*kotak;
        dy=3*kotak;
    } else if (dx==9*kotak && dy==2*kotak){
        dx=14*kotak;
        dy=2*kotak;
    } else if (dx==20*kotak && dy==0*kotak){
        dx=17*kotak;
        dy=3*kotak;
    }
    //Ini ular
    else if (dx==1*kotak && dy==3*kotak){
        dx=3*kotak;
        dy=1*kotak;
    } else if (dx==14*kotak && dy==3*kotak){
        dx=9*kotak;
        dy=0*kotak;
    } else if (dx==16*kotak && dy==2*kotak){
        dx=18*kotak;
        dy=0*kotak;
    } else if (dx==5*kotak && dy==3*kotak){
        dx=9*kotak;
        dy=1*kotak;
    }
    int d[] = {dx, dy};
    return d;
}
void input(unsigned char key, int x, int y){
    if (key=='q' || key=='Q') {
        exit(0);
    } else if(key=='j' || key=='J'){
         glTranslated(21, 4.25,0);
         glRotated(1, 0,1,0);
         glTranslated(-21, -4.25,0);
         glutPostRedisplay();
//         display();
    } else if(key=='l' || key=='L'){
         glTranslated(21, 4.25,0);
         glRotated(-1, 0,1,0);
         glTranslated(-21, -4.25,0);
         glutPostRedisplay();
//         display();
    } else if(key=='i' || key=='I' ){
         glTranslated(21, 4.0,0);
         glRotated(1, 1,0,0);
         glTranslated(-21, -4.0,0);
         glutPostRedisplay();
//         display();
    } else if(key=='k' || key=='K' ){
         glTranslated(21, 4.0,0);
         glRotated(-1, 1,0,0);
         glTranslated(-21, -4.0,0);
         glutPostRedisplay();
//         display();
    } else if(key=='d'|| key=='D'){
        if (dx_ob < 41.49)
            dx_ob += 0.1;
        glutPostRedisplay();
    } else if(key=='a'|| key=='A'){
        if (dx_ob > 0.1)
            dx_ob -= 0.1;
        glutPostRedisplay();
    } else if(key=='w'|| key=='W'){
        if (dy_ob < 7.49)
            dy_ob += 0.1;
        glutPostRedisplay();
    } else if(key=='s'|| key=='S'){
        if (dy_ob > 0.1)
            dy_ob -= 0.1;
        glutPostRedisplay();
    } else if(key=='r'|| key=='R'){
        kotak=2;

        turn=1; menang=false;
        ganjil=1; genap=0;

        dx1=0; dy1=0;
        dx2=0; dy2=0;

        display();
        cout<<"-----------------------------------------------"<<endl;
        cout<<"----------------GAME RESET---------------------"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Tekan [Spasi] untuk bermain"<<endl;
    }else if (!menang && key == ' '){
        int dadu = rand() % 6 +1;
        cout << "Giliran Pemain "<<turn<<endl;
        cout << "Angka Hasil Dadu: "<<dadu << endl;
        int * d;
        if (turn==1){
            for (int i=0; i<dadu; i++){
                if (dy1%4 == 0){
                    if (dx1 == 40){
                        dy1 += kotak;
                    }else{
                        dx1 += kotak;
                    }
                } else if (dy1%4 == 2){
                    if (dx1 == 0){
                        dy1 += kotak;
                    }else{
                        dx1 -= kotak;
                    }
                }

                if(dx1==0 && dy1==6){
                    cout<<"Player 1 menang"<<endl;
                    menang=true;
                    break;
                }
                display();
                Sleep(100);
            }
            d = cek(dx1, dy1);
            dx1= d[0]; dy1=d[1];
            turn=2;
            //Player 2----------------------------------------------------------------------------
        }else if(turn==2){
            for (int i=0; i<dadu; i++){
                if (dy2%4 == 0){
                    if (dx2 == 40){
                        dy2 += kotak;
                    }else{
                        dx2 += kotak;
                    }
                } else if (dy2%4 == 2){
                    if (dx2 == 0){
                        dy2 += kotak;
                    }else{
                        dx2 -= kotak;
                    }
                }

                if(dx2==0 && dy2==6){
                    cout<<"Player 2 menang"<<endl;
                    menang=true;
                    break;
                }

                display();
                Sleep(100);
            }
            d = cek(dx2, dy2);
            dx2 = d[0]; dy2=d[1];
            turn=1;
        }
        display();
    }
}


void myinit(){
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-0.25,42.25,-0.25,8.25, -50, 50);
// glOrtho(0,20,0,10, -50, 50);
 glMatrixMode(GL_MODELVIEW);
 glClearColor(0.5,0.5,0.5,1.0);
 glColor4f(0.0,0.0,1.0, 1.0);

 glShadeModel(GL_FLAT);
 glEnable(GL_DEPTH_TEST);

 glEnable(GL_BLEND);
 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

 srand(time(NULL));
 cout<<"Tekan [Spasi] untuk bermain"<<endl;
}

int main(int argc, char* argv[]){
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
 glutInitWindowSize(1000,200);
 //glutInitWindowPosition(100,100);
 glutCreateWindow("Segitiga Warna");
 myinit();
 glutKeyboardFunc(input);
 glutDisplayFunc(display);

 glutMainLoop();
 return 0;
}
