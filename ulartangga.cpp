// v.1.2

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
     glColor3f(1,0,0);
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
 glColor3f(0.84, 0.46, 0.04);
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
        box24(x1+((x2-x1)*i/5)-0.4,  y1+((y2-y1)*i/5)+0.1 +derajat, 0,   

       x1+((x2-x1)*i/5)-0.55, y1+((y2-y1)*i/5)-0.1 +derajat, 0,
              x1+((x2-x1)*i/5)+0.4,  y1+((y2-y1)*i/5)-0.1 -derajat, 0,   

       x1+((x2-x1)*i/5)+0.55, y1+((y2-y1)*i/5)+0.1 -derajat, 0,
              x1+((x2-x1)*i/5)-0.4,  y1+((y2-y1)*i/5)+0.1 +derajat, 1,   

       x1+((x2-x1)*i/5)-0.55, y1+((y2-y1)*i/5)-0.1 +derajat, 1,
              x1+((x2-x1)*i/5)+0.4,  y1+((y2-y1)*i/5)-0.1 -derajat, 1,   

       x1+((x2-x1)*i/5)+0.55, y1+((y2-y1)*i/5)+0.1 -derajat, 1);
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
    glColor3f(0.49, 0.49, 0.67);
    box24(x1-0.25, y1+ 0*(y2-y1)/3, 1,                  x1+0.25, y1+ 0*

(y2-y1)/3, 1,
              x1+ (x2-x1)/2+0.25, y1+ 1*(y2-y1)/3, 1,   x1+ (x2-x1)/2-

0.25, y1+ 1*(y2-y1)/3, 1,
              x1-0.25, y1+ 0*(y2-y1)/3, 0,              x1+0.25, y1+ 0*

(y2-y1)/3, 0,
              x1+ (x2-x1)/2+0.25, y1+ 1*(y2-y1)/3, 0,   x1+ (x2-x1)/2-

0.25, y1+ 1*(y2-y1)/3, 0);
    glColor3f(0.35, 0.25,0.29);
    box24(x1+ (x2-x1)/2+0.25, y1+ 1*(y2-y1)/3,1,        x1+ (x2-x1)/2-

0.25, y1+ 1*(y2-y1)/3,1,
          x1+ (x2-x1)/2-0.25, y1+ 2*(y2-y1)/3,1,        x1+ (x2-

x1)/2+0.25, y1+ 2*(y2-y1)/3,1,
          x1+ (x2-x1)/2+0.25, y1+ 1*(y2-y1)/3,0,        x1+ (x2-x1)/2-

0.25, y1+ 1*(y2-y1)/3,0,
          x1+ (x2-x1)/2-0.25, y1+ 2*(y2-y1)/3,0,        x1+ (x2-

x1)/2+0.25, y1+ 2*(y2-y1)/3,0);
    glColor3f(0.49, 0.49, 0.67);
    box24(x1+ (x2-x1)/2-0.25, y1+ 2*(y2-y1)/3,1,        x1+ (x2-

x1)/2+0.25, y1+ 2*(y2-y1)/3,1,
          x2+0.25, y1+ 3*(y2-y1)/3,1,                   x2-0.25, y1+ 3*

(y2-y1)/3,1,
          x1+ (x2-x1)/2-0.25, y1+ 2*(y2-y1)/3,0,        x1+ (x2-

x1)/2+0.25, y1+ 2*(y2-y1)/3,0,
          x2+0.25, y1+ 3*(y2-y1)/3,0,                   x2-0.25, y1+ 3*

(y2-y1)/3,0);
}

void papan(){
 glColor3f(1,0,0); //warna border luar
 box(1.85,-0.15,0, 44.15,0,0.5);
 box(1.85,8,0, 44.15,8.15,0.5);
 box(1.85,-0.15,0, 2,8.15,0.5);
 box(44,-0.15,0, 44.15,8.15,0.5);
 int counter=1;
 int max_kolom=22;
 for (int y=0; y<4; y++){
     for (int x=1; x<=21; x++){
         if (x%2==genap && y%2==ganjil ||
             x%2==ganjil && y%2==genap){
            glColor3f(0.56, 0.77, 0.77);
         } else {
            glColor3f(0.2, 0.4, 0.6);
         }
         glBegin(GL_POLYGON);
            box(x*kotak, y*kotak, -0.2, x*kotak+2, y*kotak+2, -0.1);
//             glVertex2f(x*kotak,    y*kotak);
//             glVertex2f(x*kotak+2,  y*kotak);
//             glVertex2f(x*kotak+2,  y*kotak+2);
//             glVertex2f(x*kotak,    y*kotak+2);
         glEnd();
     }for (int x=1; x<=21; x++){
         if (y%2==ganjil ){
            angka(max_kolom-x, y,counter);
         }else {
            angka(x,y,counter);
         }
         counter++;
     }
     //border
     if (y%2==ganjil){
        glRectf(1*kotak, y*kotak-0.05, 21*kotak, y*kotak+0.05);
     }else if (y!=0){
        glRectf(2*kotak, y*kotak-0.05, 22*kotak, y*kotak+0.05);
     }
 }
}

void pemain1(){
    glColor3f(1, 0.5, 0.5);
    box24(2.75+dx1,1.15+dy1,1,           3.25+dx1,1.15+dy1,1,
            3.25+dx1,1.5+dy1,1,            2.75+dx1,1.5+dy1,1,
            2.75+dx1,1.15+dy1,0,           3.25+dx1,1.15+dy1,0,
            3.25+dx1,1.5+dy1,0,            2.75+dx1,1.5+dy1,0);

}

void pemain2(){
    glColor3f(1,1,1);
    box24(2.75+dx2,0.5+dy2,1,        3.00+dx2,0.5+dy2,1,
          3.25+dx2,1.00+dy2,1,       2.75+dx2,1.00+dy2,1,
          2.75+dx2,0.5+dy2,0,        3.00+dx2,0.5+dy2,0,
          3.25+dx2,1.00+dy2,0,       2.75+dx2,1.00+dy2,0);

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

 papan();
 ular(4*kotak+1,    1*kotak+1, 2*kotak+1,   3*kotak+1);
 ular(10*kotak+1,   0*kotak+1, 15*kotak+1,  3*kotak+1);
 ular(19*kotak+1,   0*kotak+1, 17*kotak+1,  2*kotak+1);
 ular(10*kotak+1,    1*kotak+1, 6*kotak+1,   3*kotak+1);

 tangga(2*kotak+1,  0*kotak+1, 5*kotak+1,   3*kotak+1);
 tangga(5*kotak+1,  1*kotak+1, 9*kotak+1,   1*kotak+1);
 tangga(16*kotak+1, 0*kotak+1, 16*kotak+1,  3*kotak+1);
 tangga(10*kotak+1, 2*kotak+1, 15*kotak+1,  2*kotak+1);
 tangga(21*kotak+1, 0*kotak+1, 18*kotak+1,  3*kotak+1);

 pemain1();
 pemain2();
 glutSwapBuffers();
// glFlush();
}

void input(unsigned char key, int x, int y){
    if (key=='q' || key=='Q') {
        exit(0);
    } else if(key=='a' || key=='A'){
         glTranslated(23, 4.25,0);
         glRotated(1, 0,1,0);
         glTranslated(-23, -4.25,0);
         display();
    } else if(key=='d' || key=='D'){
         glTranslated(23, 4.25,0);
         glRotated(-1, 0,1,0);
         glTranslated(-23, -4.25,0);
         display();
    } else if(key=='w' ){
         glTranslated(23, 4.0,0);
         glRotated(1, 1,0,0);
         glTranslated(-23, -4.0,0);
         display();
    } else if(key=='s' ){
         glTranslated(21.25, 4.0,0);
         glRotated(-1, 1,0,0);
         glTranslated(-21.25, -4.0,0);
         display();
    }else if(key=='r'|| key=='R'){
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
            //Cek kotak ular or tangga
            //Kotak x_gambar-1
            if (dx1==1*kotak && dy1==0*kotak){
                dx1=4*kotak;
                dy1=3*kotak;
            } else if (dx1==8*kotak && dy1==1*kotak){
                dx1=4*kotak;
                dy1=1*kotak;
            } else if (dx1==15*kotak && dy1==0*kotak){
                dx1=15*kotak;
                dy1=3*kotak;
            } else if (dx1==9*kotak && dy1==2*kotak){
                dx1=14*kotak;
                dy1=2*kotak;
            } else if (dx1==20*kotak && dy1==0*kotak){
                dx1=17*kotak;
                dy1=3*kotak;
            }
            //Ini ular
            else if (dx1==1*kotak && dy1==3*kotak){
                dx1=3*kotak;
                dy1=1*kotak;
            } else if (dx1==14*kotak && dy1==3*kotak){
                dx1=9*kotak;
                dy1=0*kotak;
            } else if (dx1==16*kotak && dy1==2*kotak){
                dx1=18*kotak;
                dy1=0*kotak;
            } else if (dx1==5*kotak && dy1==3*kotak){
                dx1=9*kotak;
                dy1=1*kotak;
            }
            turn=2;
            //Player 2

------------------------------------------------------------------------

----
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
            //cek ular tangga
            //Kotak gambar-1
            if (dx2==1*kotak && dy2==0*kotak){
                dx2=4*kotak;
                dy2=3*kotak;
            } else if (dx2==8*kotak && dy2==1*kotak){
                dx2=4*kotak;
                dy2=1*kotak;
            } else if (dx2==15*kotak && dy2==0*kotak){
                dx2=15*kotak;
                dy2=3*kotak;
            } else if (dx2==9*kotak && dy2==2*kotak){
                dx2=14*kotak;
                dy2=2*kotak;
            } else if (dx2==20*kotak && dy2==0*kotak){
                dx2=17*kotak;
                dy2=3*kotak;
            }
            //Ini ular
            else if (dx2==1*kotak && dy2==3*kotak){
                dx2=3*kotak;
                dy2=1*kotak;
            } else if (dx2==14*kotak && dy2==3*kotak){
                dx2=9*kotak;
                dy2=0*kotak;
            } else if (dx2==16*kotak && dy2==2*kotak){
                dx2=18*kotak;
                dy2=0*kotak;
            } else if (dx2==5*kotak && dy2==3*kotak){
                dx2=9*kotak;
                dy2=1*kotak;
            }
            turn=1;
        }
        display();
    }
}


void myinit(){
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(1.75,44.25,-0.25,8.25, 50, -50);
// glOrtho(0,20,0,10, -50, 50);
 glMatrixMode(GL_MODELVIEW);
 glClearColor(0.5,0.5,0.5,1.0);
 glColor3f(0.0,0.0,1.0);
 glShadeModel(GL_FLAT);
 glEnable(GL_DEPTH);
 srand(time(NULL));
 cout<<"Tekan [Spasi] untuk bermain"<<endl;
}

int main(int argc, char* argv[]){
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
 glutInitWindowSize(1000,200);
 //glutInitWindowPosition(100,100);
 glutCreateWindow("Segitiga Warna");
 myinit();
 glutKeyboardFunc(input);
 glutDisplayFunc(display);

 glutMainLoop();
 return 0;
}
