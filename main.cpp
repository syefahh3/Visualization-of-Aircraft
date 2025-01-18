#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>>
#include <mmsystem.h>

#include<cstdio>

#include <GL/gl.h>


# define PI           3.14159265358979323846

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

bool flag = false;
bool flag1 = false;

GLfloat i = 0.0f;

GLfloat s3BigP1 = -2.5f;  //x
GLfloat s3BigP1Speed1 = 0.03f;

GLfloat s3BigP1Y = 1.0f; //y
GLfloat s3BigP1SpeedY = 0.02f;

GLfloat runway1 = 0.0f;
GLfloat runSpeed1 = 0.02f;

GLfloat runway22 = 0.2f;
GLfloat runSpeed2 = 0.02f;

GLfloat p3Cloud = 0.0f;
GLfloat p3CloudSpeed = 0.015f;

GLfloat p3Cloudfly = 0.0f;
GLfloat p3CloudflySpeed = 0.01f;

GLfloat p2Cloud = 0.0f;
GLfloat p2CloudSpeed = 0.015f;

GLfloat rotation = 0.0f;

GLfloat s3smallp2 = 1.6f;
GLfloat s3smallp2Speed2 = 0.025f;
//s3smallp2

GLfloat p2Plane1 = 0.0f;
GLfloat p2Plane1Sp1 = 0.03f;

GLfloat p2Plane2 = 2.0f;
GLfloat p2Plane1Sp2 = 0.03f;

GLfloat p1Pane1 = 0.0f;
GLfloat p1PlaneSp1 = 0.025f;

GLfloat bus1 = 0.0f;
GLfloat busSpeed1 = 0.02f;

GLfloat pickupPosition = -0.5f;
GLfloat pickupSpeed = 0.012f;

GLfloat thunderposition = 0.5f;
GLfloat thunderSpeed = 0.15f;

GLfloat thunderposition1 = 3.0f;
GLfloat thunderSpeed1 = 0.15f;

//peoples
GLfloat peoplePosi1 = 0.0f;
GLfloat peopleSpe1 = 0.01f;
GLfloat peoplePosiY1 = 0.0f;
GLfloat peopleSpeY1 = 0.01f;

GLfloat peoplePosiX2 = 0.0f;
GLfloat peopleSpeX2 = 0.005f;
GLfloat peoplePosi2 = 0.0f;
GLfloat peopleSpe2 = 0.005f;
GLfloat peoplePosiY2 = 0.0f;
GLfloat peopleSpeY2 = 0.005f;

GLfloat peoplePosiX3 = 0.0f;
GLfloat peopleSpeX3 = 0.004f;
GLfloat peoplePosi3 = 0.1f;
GLfloat peopleSpe3 = 0.004f;
GLfloat peoplePosiY3 = 0.0f;
GLfloat peopleSpeY3 = 0.004f;

void update2(int value)
{
    if(p2Cloud <-2.0)
        p2Cloud =2.1;
    /*else if(p2Cloud >-0.1)
        p2Cloud = -0.1;*/
    p2Cloud -= p2CloudSpeed;

    if(p2Plane1 >2.6)
        p2Plane1 =-3.0f;
    p2Plane1 += p2Plane1Sp1;

    if(p2Plane2 <-2.6)
        p2Plane2 =5.0;
    p2Plane2 -= p2Plane1Sp2;

    if(thunderposition<0.09)
        thunderposition =8.0f;
    thunderposition -= thunderSpeed;

    if(thunderposition1<-0.1)
        thunderposition1 =9.0f;
    thunderposition1 -= thunderSpeed1;


    glutPostRedisplay();
    glutTimerFunc(60, update2, 0);
}

void update1(int value){

    flag1 = true;

    if(p1Pane1 >2.6)
        p1Pane1 =-2.5f;
    p1Pane1 += p1PlaneSp1;

    if(bus1 >2.6)
        bus1 =-2.0f;
    bus1 += busSpeed1;

    if(pickupPosition>1.4)
        pickupPosition =-1.4f;
    pickupPosition += pickupSpeed;

    //peoples
     if(peoplePosi1 >0.14)
        peoplePosi1 =0.14f;
    peoplePosi1 += peopleSpe1;

    if(peoplePosiY1 >0.12)
        peoplePosiY1 =0.12;
    //else if(peoplePosiY >0.7)
    // peoplePosiY = 0.7;
    peoplePosiY1 += peopleSpeY1;


    //2nd
    if(peoplePosiX2 >0.035)
        peoplePosiX2 =0.035f;
    peoplePosiX2 += peopleSpeX2;

    if(peoplePosi2 >0.19)
        peoplePosi2 =0.19f;
    peoplePosi2 += peopleSpe2;

    if(peoplePosiY2 >0.12)
        peoplePosiY2 =0.12;
    peoplePosiY2 += peopleSpeY2;

    //3rd
    if(peoplePosiX3 >0.1)
        peoplePosiX3 =0.1f;
    peoplePosiX3 += peopleSpeX3;

    if(peoplePosi3 >0.23)
        peoplePosi3 =0.23f;
    peoplePosi3 += peopleSpe3;

    if(peoplePosiY3 >0.12)
        peoplePosiY3 =0.12;
    peoplePosiY3 += peopleSpeY3;

    glutPostRedisplay();
    glutTimerFunc(60, update1, 0);

}

void update3(int value){

    flag = true;

    if(s3smallp2 <-2.6)
        s3smallp2 =2.5f;
    s3smallp2 -= s3smallp2Speed2;

    if(s3BigP1 >2.6)
        s3BigP1 =-3.0f;
    else if(s3BigP1 >0.0)
        s3BigP1 = 0.0;
    s3BigP1 += s3BigP1Speed1;

    if(s3BigP1Y <-2.6)
        s3BigP1Y =1.0;
    else if(s3BigP1Y <-0.7)
        s3BigP1Y = -0.7;
    s3BigP1Y -= s3BigP1SpeedY;

    if(runway1 <-2.6)
        runway1 =2.0;
    //else if(runway1 <-2.0)
        //runway1 = -2.0;
    //runway1 -= runSpeed1;
    runway1 -= runSpeed1;

    if(runway22 <-4.6)
        runway22 =2.0;
    //else if(runway22 <-2.3)
        //runway22 = -2.3;
    //runway22 -= runSpeed2;
    runway22 -= runSpeed2;

    if(p3Cloud <-2.6)
        p3Cloud =2.0;
    else if(p3Cloud >-0.1)
        p3Cloud = -0.1;
    //else if(p3Cloud <-1.8)
        //p3Cloud = -1.8;
    //p3Cloud -= p3CloudSpeed;
    p3Cloud -= p3CloudSpeed;

    if(p3Cloudfly <-3.6)
        p3Cloudfly =1.5;
    //else if(p3Cloudfly >-0.1)
        //p3Cloudfly = -0.1;
    //else if(p3Cloudfly <-1.8)
        //p3Cloudfly = -1.8;
    //p3Cloud -= p3CloudSpeed;
    p3Cloudfly -= p3CloudflySpeed;

    glutPostRedisplay();
    glutTimerFunc(60, update3, 0);
}

void displayCover() {
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    //page border
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(-0.4, 0.9);
    glVertex2f(0.4, 0.9);
    glVertex2f(0.4, -0.9);
    glVertex2f(-0.4, -0.9);

    glEnd();



    //uni name
    glPushMatrix();
    glTranslatef(-0.01f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.347826713588f, 0.8116267414833f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University -Bangladesh (AIUB)");
    glPopMatrix();



    //course name
    glPushMatrix();
    glTranslatef(+0.01f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1690949430827f, 0.6779878488577f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Course : Computer Graphics");
    glPopMatrix();

    //section
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0707104822541f, 0.6173174313468f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Section : F");

    //project name
    glPushMatrix();
    glTranslatef(+0.01f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.2150076914694f, 0.5402496036977f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Project Name : Visualization of Aircraft");
    glPopMatrix();

    //group number
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0682508707334f, 0.4877778912557f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Group : 1");

    //Submitted to
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0790214813468f, 0.4127290449519f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Submitted to :");

    //MAHFUJUR RAHMAN
    glPushMatrix();
    glTranslatef(+0.03f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1612865259168f, 0.3559436165065f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MAHFUJUR RAHMAN");
    glPopMatrix();

    //ASSISTANT PROFESSOR
    glPushMatrix();
    glTranslatef(+0.02f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1351389049429f, 0.2976143081801f, 0.0f, GLUT_BITMAP_HELVETICA_12, "ASSISTANT PROFESSOR");
    glPopMatrix();

    //FACULTY
    glPushMatrix();
    glTranslatef(-0.09f, 0.0f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0798266298058f, 0.2483360994216f, 0.0f, GLUT_BITMAP_HELVETICA_12, "FACULTY OF SCIENCE AND TECHNOLOGY");
    glPopMatrix();

    //DEPARTMENT OF COMPUTER SCIENCE
    glPushMatrix();
    glTranslatef(+0.045f, 0.02f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1995022796479f, 0.1859840801762f, 0.0f, GLUT_BITMAP_HELVETICA_12, "DEPARTMENT OF COMPUTER SCIENCE");
    glPopMatrix();

    //Submitted by:
    glPushMatrix();
    glTranslatef(0.0f, -0.1f, 0.0f);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0793856994797f, 0.1328747868973f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Submitted by:");

    //table

    //border
    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.86f, 0.86f);
    glVertex2f(-0.3, 0.1);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.3, -0.3);
    glVertex2f(-0.3, -0.3);
    glEnd();

    //2nd row
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.83f, 0.83f);
    glVertex2f(-0.3, 0.05);
    glVertex2f(0.3, 0.05);
    glVertex2f(0.3, -0.03);
    glVertex2f(-0.3, -0.03);
    glEnd();

    //4th row
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.83f, 0.83f);
    glVertex2f(-0.3, -0.1);
    glVertex2f(0.3, -0.1);
    glVertex2f(0.3, -0.17);
    glVertex2f(-0.3, -0.17);
    glEnd();

    //6th row
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.83f, 0.83f);
    glVertex2f(-0.3, -0.24);
    glVertex2f(0.3, -0.24);
    glVertex2f(0.3, -0.3);
    glVertex2f(-0.3, -0.3);
    glEnd();


    //serial
    glPushMatrix();
    glTranslatef(-0.01,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.28f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_12, "SERIAL NO.");
    glPopMatrix();

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_12, "NAME");
    glPopMatrix();


    //id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_12, "ID");

    //Contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_12, "CONTRIBUTION");




    //ASHRAFUL ISLAM OPU

    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f, 0.02f, 0.0f, GLUT_BITMAP_HELVETICA_12, "13");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, 0.02f, 0.0f, GLUT_BITMAP_HELVETICA_12, "ASHRAFUL ISLAM OPU");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, 0.02f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-47433-2");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, 0.02f, 0.0f, GLUT_BITMAP_HELVETICA_12, "25%");



    //SYEDA FAHMIDA SHARMIN 22-49720-3
    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_12, "39");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_12, "SYEDA FAHMIDA SHARMIN");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-49720-3");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_12, "25%");



    //ESTIAK RAHMAN AYON 22-4953-3
    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f, -0.13f, 0.0f, GLUT_BITMAP_HELVETICA_12, "41");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, -0.13f, 0.0f, GLUT_BITMAP_HELVETICA_12, "ESTIAK RAHMAN AYON");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, -0.13f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-49753-3");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, -0.13f, 0.0f, GLUT_BITMAP_HELVETICA_12, "25%");



    //TATHAPI MONDAL 22-4930-3
    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "40");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "TATHAPI MONDAL");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-49730-3");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "15%");



    //REFAT HASAN 22-468255-1
    //serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.27f,  -0.275f, 0.0f, GLUT_BITMAP_HELVETICA_12, "9");

    //name
    glPushMatrix();
    glTranslatef(-0.03,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.15f,  -0.275f, 0.0f, GLUT_BITMAP_HELVETICA_12, "REFAT HASAN");
    glPopMatrix();

    //Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.04f,  -0.275f, 0.0f, GLUT_BITMAP_HELVETICA_12, "22-46825-1");

    //contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.18f,  -0.275f, 0.0f, GLUT_BITMAP_HELVETICA_12, "10%");

    glPopMatrix();




    //Click the right button of your mouse to continue
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.35f, -0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "[ Click the LEFT mouse button (LMB) to continue ]"); //-0.25



     glFlush(); // Render now
}

void displayNavigation() {
    glClearColor(0.64f, 0.57f, 0.33f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


    //Navigation
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.0f, 0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Navigation");



    //Click "1" to view page 1
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.05f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Click '1' to view Scene 1");

    //Click "2" to view page 2
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.05f, 0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Click '2' to view Scene 2");

    //Click "3" to view page 3
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.05f, 0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Click '3' to view Scene 3");

    //Click the right button of your mouse to visit cover page
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.25f, -0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "[ Click the RIGHT mouse button to view Cover Page ]");


    //plane
    glPushMatrix();
    glScalef(0.4,0.5,0.0);
    glTranslatef(0.05,-0.05,0.0);

    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.8375889660587f, 0.2912098678332f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.928861465027f, 0.2556290631507f);
    glVertex2f(-0.9041096009f, 0.2378386608094f);
    glVertex2f(-0.8731697707412f, 0.2277832160078f);
    glVertex2f(-0.8453239235984f, 0.2192747627141f);
    glVertex2f(-0.8143840934396f, 0.2107663094205f);
    glVertex2f(-0.7842177590348f, 0.2068988306506f);
    glVertex2f(-0.7439959798284f, 0.2076723264046f);
    glVertex2f(-0.3897349245107f, 0.2092193179125f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.4043823800643f, 0.2892785841354f);
    glVertex2f(-0.3831964687035f, 0.2802549552225f);
    glVertex2f(-0.3545562551972f, 0.2671118435449f);
    glVertex2f(-0.3380783241388f, 0.2622076973966f);
    glVertex2f(-0.3237582173856f, 0.2573035512482f);
    glVertex2f(-0.3176770761617f, 0.2518109075621f);
    glVertex2f(-0.3121844324755f, 0.2463182638759f);
    glVertex2f(-0.31f, 0.24f);
    glVertex2f(-0.3098304423243f, 0.2357253081955f);
    glVertex2f(-0.31f, 0.23f);
    glVertex2f(-0.313753759243f, 0.2259170158989f);
    glVertex2f(-0.3204233980047f, 0.2227783623639f);
    glVertex2f(-0.3280738659961f, 0.2190512112912f);
    glVertex2f(-0.3378821582928f, 0.2157163919103f);
    glVertex2f(-0.3500444407407f, 0.2127739042213f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head window
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3819451920869f, 0.2758911800548f);
    glVertex2f(-0.3881479557192f, 0.2728587178345f);
    glVertex2f(-0.3771897399688f, 0.2608667081453f);
    glVertex2f(-0.370504539165f, 0.2634167331942f);
    glVertex2f(-0.3660936850265f, 0.2658289190512f);
    glVertex2f(-0.360855795737f, 0.2696194968265f);
    glVertex2f(-0.3786950838177f, 0.2781892511995f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.398899412682f, 0.2686546224837f);
    glVertex2f(-0.4098576284324f, 0.2679654265246f);
    glVertex2f(-0.40854815611f, 0.262727537235f);
    glVertex2f(-0.4031035080328f, 0.2555598992599f);
    glVertex2f(-0.3925588098578f, 0.2561801756231f);
    glVertex2f(-0.3804978805727f, 0.2588680398638f);
    glVertex2f(-0.39f, 0.27f);
    glVertex2f(-0.39f, 0.27f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4127657925046f, 0.2602777634305f);
    glVertex2f(-0.4148377327393f, 0.2667761214393f);
    glVertex2f(-0.4317899710231f, 0.2668703005408f);
    glVertex2f(-0.432260866531f, 0.260371942532f);
    glVertex2f(-0.4296238516869f, 0.2515191069838f);
    glVertex2f(-0.4077743001211f, 0.2526492562027f);

    glEnd();

    //front door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4695704482148f, 0.2425964533209f);
    glVertex2f(-0.4727942748017f, 0.2424499157487f);
    glVertex2f(-0.4726477372296f, 0.2379072510126f);
    glVertex2f(-0.4692773730705f, 0.2380537885847f);

    glEnd();

    //upper wing
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.5498485455822f, 0.2873423890634f);
    glVertex2f(-0.6217836507013f, 0.3770678965238f);
    glVertex2f(-0.6565909596299f, 0.3778413922778f);
    glVertex2f(-0.6488595295804f, 0.2915606660423f);

    glEnd();

    //lower wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8512841908058f, 0.1241487992192f);
    glVertex2f(-0.8652666039946f, 0.1246309513981f);
    glVertex2f(-0.8522484951637f, 0.1101663860304f);
    glVertex2f(-0.8291051905754f, 0.1111306903883f);
    glVertex2f(-0.5055818995018f, 0.2087134359257f);
    glVertex2f(-0.7114611649165f, 0.2078143998322f);

    glEnd();

    //lower wing back
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.847900370437f, 0.2811701757442f);
    glVertex2f(-0.9292604039938f, 0.2448081495735f);
    glVertex2f(-0.9792581899784f, 0.2452626749007f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);

    glEnd();

    //upper wing back
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8228925467333f, 0.3035857998967f);
    glVertex2f(-0.8414564448285f, 0.3120942531904f);
    glVertex2f(-0.8561528641539f, 0.3283376640237f);
    glVertex2f(-0.9056565924079f, 0.3909908200952f);
    glVertex2f(-0.9427843885984f, 0.3894438285873f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.7617837686202f, 0.2913507696872f);
    glVertex2f(-0.7934997080824f, 0.2958508423571f);
    glVertex2f(-0.8097431189158f, 0.2989448253729f);

    glEnd();

    //back door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7678874563725f, 0.2510951983408f);
    glVertex2f(-0.7708790248524f, 0.2509192237244f);
    glVertex2f(-0.7707910375442f, 0.2473997313951f);
    glVertex2f(-0.7677114817561f, 0.2476636933198f);

    glEnd();

    //windows from left
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7151099662305f, 0.266868589599f);
    glVertex2f(-0.714460252525f, 0.2434788962022f);
    glVertex2f(-0.6962682687719f, 0.2434788962022f);
    glVertex2f(-0.6975676961829f, 0.266868589599f);

    glVertex2f(-0.6819745672516f, 0.26816801701f);
    glVertex2f(-0.6813248535462f, 0.2441286099077f);
    glVertex2f(-0.6637825834985f, 0.2444534667604f);
    glVertex2f(-0.6641074403513f, 0.2678431601572f);

    glVertex2f(-0.6501385956837f, 0.266868589599f);
    glVertex2f(-0.6491640251255f, 0.2447783236131f);
    glVertex2f(-0.6316217550779f, 0.2444534667604f);
    glVertex2f(-0.6329211824888f, 0.2671934464518f);

    glVertex2f(-0.6196020515268f, 0.2671934464518f);
    glVertex2f(-0.6183026241158f, 0.2451031804659f);
    glVertex2f(-0.6014100677737f, 0.2447783236131f);
    glVertex2f(-0.6030343520373f, 0.266868589599f);

    glVertex2f(-0.5858169388425f, 0.2662188758936f);
    glVertex2f(-0.585167225137f, 0.2457528941713f);
    glVertex2f(-0.5702238099112f, 0.2454280373186f);
    glVertex2f(-0.5711983804694f, 0.266868589599f);

    glVertex2f(-0.5533312535691f, 0.266868589599f);
    glVertex2f(-0.5520318261581f, 0.2454280373186f);
    glVertex2f(-0.5370884109324f, 0.2447783236131f);
    glVertex2f(-0.5393624089015f, 0.266868589599f);

    glVertex2f(-0.5227947094121f, 0.2665437327463f);
    glVertex2f(-0.5208455682957f, 0.2431540393495f);
    glVertex2f(-0.5039530119536f, 0.2434788962022f);
    glVertex2f(-0.5055772962172f, 0.266868589599f);

    glEnd();

    glPopMatrix();



     glFlush(); // Render now
}

void thunder(){

    // thunder left side
    glPushMatrix();
    glTranslatef(0.0f, thunderposition, 0.0f);
    glTranslatef(0.0f, -0.3f, 0.0f);
    glScalef(1,1.3,0); // increase x right and y
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.4937144610804, 0.9283295884196);
    glVertex2f(-0.4405552527926, 1.0390779390192);
    glVertex2f(-0.4922378164058, 1.0331713603205);
    glVertex2f(-0.5704999841628, 0.8736937354571);
    glVertex2f(-0.4745180803098, 0.8973200502517);
    glVertex2f(-0.5704999841628, 0.7614687401828);
    glVertex2f(-0.3873960445048, 0.9224230097209);

    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0f, thunderposition1, 0.0f);
    glTranslatef(0.0f, -0.3f, 0.0f);
    glScalef(0.8,1.4,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.1966154557543, 0.8686510182521);
    glVertex2f(0.2861179291954, 0.8542864237492);
    glVertex2f(0.1502067658218, 1.0498659027502);
    glVertex2f(0.082803668539, 1.0763851541402);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.122582545624, 0.9040100201054);
    glVertex2f(0.1855657676751, 0.8156125154722);
    glVertex2f(0.1203726080081, 0.8156125154722);
    glVertex2f(0.2982725860825, 0.6343976309742);
    glVertex2f(0.2098750814492, 0.779148544811);
    glVertex2f(0.3082173053537, 0.7736237007714);
    glEnd();

    glPopMatrix();

}

void s2Clouds(float r, float s){

    glPushMatrix();
    glTranslatef(p2Cloud,0.0f, 0.0f);

    glTranslatef(r,s, 0.0f);

    //cloud
    int i;

    GLfloat x=2.0664666559629f;
    GLfloat y=0.384679318014f;
    GLfloat radius =0.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.85, 0.86, 0.84);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x1=2.1249747089483f;
    GLfloat y1=0.3731062965444f;
    GLfloat radius1 =0.04f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.85, 0.86, 0.84);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x2=2.0086015486148f;
    GLfloat y2=0.362176220712f;
    GLfloat radius2 =0.045f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.85, 0.86, 0.84);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=1.9610235714619f;
    GLfloat y3=0.3512461448795f;
    GLfloat radius3 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.85, 0.86, 0.84);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=2.1641943928175f;
    GLfloat y4=0.3692486227212f;
    GLfloat radius4 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.85, 0.86, 0.84);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

}

void clouds1(float r, float s)
{

    glPushMatrix();
    //glTranslatef(p3Cloud,0.0f, 0.0f);

    glTranslatef(r,s, 0.0f);

    //cloud
    int i;

    GLfloat x=2.0664666559629f;
    GLfloat y=0.384679318014f;
    GLfloat radius =0.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x1=2.1249747089483f;
    GLfloat y1=0.3731062965444f;
    GLfloat radius1 =0.04f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x2=2.0086015486148f;
    GLfloat y2=0.362176220712f;
    GLfloat radius2 =0.045f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=1.9610235714619f;
    GLfloat y3=0.3512461448795f;
    GLfloat radius3 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=2.1641943928175f;
    GLfloat y4=0.3692486227212f;
    GLfloat radius4 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

}

void pickup()
{

    // pickup body
    glPushMatrix();
    glTranslatef(pickupPosition, 0.6, 0.0f);
    glScalef(1,1.65,0); // increase x right and y
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.339165193542, -0.8847715896556);
    glVertex2f(0.3297084007393, -0.8464715788044);
    glVertex2f(0.270603445722, -0.8464715788044);
    glVertex2f(0.2710762853621, -0.8871357878563);
    glVertex2f(0.2619747439794, -0.8873709642964);
    glVertex2f(0.2626852468196, -0.9211198492048);
    glVertex2f(0.3809839697092, -0.9228961063053);
    glVertex2f(0.3809839697092, -0.9228961063053);
    glVertex2f(0.3803022422341, -0.886190108576);

    glEnd();

    // pickup window and handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.3215668412371, -0.8506717528616);
    glVertex2f(0.2765400522031, -0.8522010737076);
    glVertex2f(0.2776487297447, -0.8853694873557);
    glVertex2f(0.3295740107358, -0.8851268458557);

    glVertex2f(0.285013693269, -0.8902082638051);
    glVertex2f(0.28, -0.89);
    glVertex2f(0.2799025350623, -0.8924798896747);
    glVertex2f(0.285013693269, -0.8924798896747);

    glEnd();

    // luggages
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.1350086827282, -0.878465617679);
    glVertex2f(0.1353554995014, -0.9107195775849);
    glVertex2f(0.1514824794543, -0.9105461691983);
    glVertex2f(0.1511356626811, -0.8782922092924);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.1774937374429, -0.8656333970713);
    glVertex2f(0.1776897955555, -0.8957799460236);
    glVertex2f(0.2108530687236, -0.8951031445304);
    glVertex2f(0.2104018677281, -0.8646470773352);

    glEnd();


    // van 1
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.2479532223318, -0.905659705168);
    glVertex2f(0.1335291269281, -0.906722467664);
    glVertex2f(0.1335291269281, -0.9240809217654);
    glVertex2f(0.2561010681345, -0.9223096509388);
    glVertex2f(0.2561010681345, -0.8872384885705);
    glVertex2f(0.2475989681664, -0.8872384885705);

    glEnd();

    // van 2
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.1275068061174, -0.9070767218293);
    glVertex2f(0.0074146440684, -0.905659705168);
    glVertex2f(0.0074146440684, -0.9237266676001);
    glVertex2f(0.1271525519521, -0.9233724134348);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.2658819878464, -0.9102971067691);
    glVertex2f(0.2524000554261, -0.9116018099066);
    glVertex2f(0.251820187365, -0.917690424548);
    glVertex2f(0.2657370208312, -0.9163857214106);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.1402602946264, -0.912649108032);
    glVertex2f(0.1235393149123, -0.911922108914);
    glVertex2f(0.1224488162353, -0.9193738498735);
    glVertex2f(0.14, -0.92);

    glEnd();

    //wheel

    int i;

    GLfloat x=0.3580643093089f;
    GLfloat y=-0.9211174250007f;
    GLfloat radius =0.02f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //wheel inner

    int j;

    GLfloat x1=0.3580643093089f;
    GLfloat y1=-0.9211174250007f;
    GLfloat radius1 =0.01f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(j = 0; j <= triangleAmount; j++)
    {
        glVertex2f( x1 + (radius1 * cos(j *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(j * twicePi / triangleAmount)) );
    }
    glEnd();

    int k;

    GLfloat x2=0.2834720472102f;
    GLfloat y2=-0.9198775399146f;
    GLfloat radius2 =0.02f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(k = 0; k <= triangleAmount2; k++)
    {
        glVertex2f( x2 + (radius2 * cos(k *  twicePi2 / triangleAmount2)),
                    y2 + (radius2 * sin(k * twicePi2 / triangleAmount2)) );
    }
    glEnd();

    // wheel inner

    int l;

    GLfloat x3=0.2834720472102f;
    GLfloat y3=-0.9198775399146f;
    GLfloat radius3 =0.01f;
    int triangleAmount3 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi3 = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(l = 0; l <= triangleAmount3; l++)
    {
        glVertex2f( x3 + (radius3 * cos(l *  twicePi3 / triangleAmount3)),
                    y3 + (radius3 * sin(l * twicePi3 / triangleAmount3)) );
    }
    glEnd();

    //wheel

    int n;

    GLfloat x5=0.2312207567058f;
    GLfloat y5=-0.9245803808935f;
    GLfloat radius5 =0.02f;
    int triangleAmount5 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi5 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(n = 0; n <= triangleAmount5; n++)
    {
        glVertex2f( x5 + (radius5 * cos(n *  twicePi5 / triangleAmount5)),
                    y5 + (radius5 * sin(n * twicePi5 / triangleAmount5)) );
    }
    glEnd();

    // wheel inner

    int m;

    GLfloat x4=0.2312207567058f;
    GLfloat y4=-0.9245803808935f;
    GLfloat radius4 =0.01f;
    int triangleAmount4 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi4 = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(m = 0; m <= triangleAmount4; m++)
    {
        glVertex2f( x4 + (radius4 * cos(m *  twicePi4 / triangleAmount4)),
                    y4 + (radius4 * sin(m * twicePi4 / triangleAmount4)) );
    }
    glEnd();

    //wheel

    int o;

    GLfloat x6=0.1567489581264f;
    GLfloat y6=-0.9251902942675f;
    GLfloat radius6 =0.02f;
    int triangleAmount6 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi6 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(o = 0; o <= triangleAmount6; o++)
    {
        glVertex2f( x6 + (radius6 * cos(o *  twicePi6 / triangleAmount6)),
                    y6 + (radius6 * sin(o * twicePi6 / triangleAmount6)) );
    }
    glEnd();

    // wheel inner

    int p;

    GLfloat x7=0.1567489581264f;
    GLfloat y7=-0.9251902942675f;
    GLfloat radius7 =0.01f;
    int triangleAmount7 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi7 = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(p = 0; p <= triangleAmount4; p++)
    {
        glVertex2f( x7 + (radius7 * cos(p *  twicePi7 / triangleAmount7)),
                    y7 + (radius7 * sin(p * twicePi7 / triangleAmount7)) );
    }
    glEnd();

    //wheel

    int q;

    GLfloat x8=0.1041316780472f;
    GLfloat y8=-0.9251902942675f;
    GLfloat radius8 =0.02f;
    int triangleAmount8 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi8 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(q = 0; q <= triangleAmount8; q++)
    {
        glVertex2f( x8 + (radius8 * cos(q *  twicePi8 / triangleAmount8)),
                    y8 + (radius8 * sin(q * twicePi8 / triangleAmount8)) );
    }
    glEnd();

    // wheel inner

    int r;

    GLfloat x9=0.1041316780472f;
    GLfloat y9=-0.9251902942675f;
    GLfloat radius9 =0.01f;
    int triangleAmount9 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi9= 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9, y9); // center of circle
    for(r = 0; r <= triangleAmount9; r++)
    {
        glVertex2f( x9 + (radius9 * cos(r *  twicePi9 / triangleAmount9)),
                    y9 + (radius9 * sin(r * twicePi9 / triangleAmount9)) );
    }
    glEnd();

    //wheel

    int s;

    GLfloat x10=0.0276071314925f;
    GLfloat y10=-0.9251436842615f;
    GLfloat radius10 =0.02f;
    int triangleAmount10 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi10 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x10, y10); // center of circle
    for(s = 0; s <= triangleAmount10; s++)
    {
        glVertex2f( x10 + (radius10 * cos(s *  twicePi10 / triangleAmount10)),
                    y10 + (radius10 * sin(s * twicePi10 / triangleAmount10)) );
    }
    glEnd();

    // wheel inner

    int t;

    GLfloat x11=0.0276071314925f;
    GLfloat y11=-0.9251436842615f;
    GLfloat radius11 =0.01f;
    int triangleAmount11 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi11= 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x11, y11); // center of circle
    for(t = 0; t <= triangleAmount11; t++)
    {
        glVertex2f( x11 + (radius11 * cos(t *  twicePi11 / triangleAmount11)),
                    y11 + (radius11 * sin(t * twicePi11 / triangleAmount11)) );
    }
    glEnd();
    glPopMatrix();


}

//people
void people()
{


    //glPushMatrix();
    //glTranslatef(peoplePosi, 0 , 0);
    //male 1
    //male 1 head
    glPushMatrix();
    glTranslatef(peoplePosi1, peoplePosiY1, 0);
    glTranslatef(0.6, 0.17, 0);
    glScalef(0.6, 0.8, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05, -0.82);
    glVertex2f(0.07, -0.82);
    glVertex2f(0.07, -0.84);
    glVertex2f(0.05, -0.84);
    glEnd();

    //male 1 body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.04, -0.9);
    glEnd();

    //male 1 right hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.1118827862726, -0.8790484298183);
    glVertex2f(0.1, -0.88);
    glVertex2f(0.08, -0.86);
    glEnd();

    //male 1 left hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.0047344834095, -0.8798540561556);
    glVertex2f(0.02, -0.88);
    glVertex2f(0.04, -0.86);
    glEnd();


    //male 1 right leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.07, -0.9);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.08, -0.94);
    glVertex2f(0.07, -0.94);
    glEnd();

    //male 1 left leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.04, -0.9);
    glVertex2f(0.05, -0.9);
    glVertex2f(0.05, -0.94);
    glVertex2f(0.04, -0.94);
    glEnd();
    glPopMatrix();


    //male 2
    //male 2 head
    glPushMatrix();
    //glTranslatef(peoplePosiX2, 0, 0);
    glTranslatef(peoplePosi2, peoplePosiY2, 0);
    glTranslatef(0.55, 0.17, 0);
    glScalef(0.6, 0.8, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.33f, 0.33f, 0.33f);
    glVertex2f(0.05, -0.82);
    glVertex2f(0.07, -0.82);
    glVertex2f(0.07, -0.84);
    glVertex2f(0.05, -0.84);
    glEnd();

    //male 2 body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.04, -0.9);
    glEnd();

    //male 2 right hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.1118827862726, -0.8790484298183);
    glVertex2f(0.1, -0.88);
    glVertex2f(0.08, -0.86);
    glEnd();

    //male 2 left hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.0047344834095, -0.8798540561556);
    glVertex2f(0.02, -0.88);
    glVertex2f(0.04, -0.86);
    glEnd();


    //male 2 right leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.07, -0.9);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.08, -0.94);
    glVertex2f(0.07, -0.94);
    glEnd();

    //male 2 left leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.04, -0.9);
    glVertex2f(0.05, -0.9);
    glVertex2f(0.05, -0.94);
    glVertex2f(0.04, -0.94);
    glEnd();
    glPopMatrix();

    //male 3
    //male 3 head
    glPushMatrix();
    glTranslatef(0.45, 0.17, 0);
    glScalef(0.6, 0.8, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05, -0.82);
    glVertex2f(0.07, -0.82);
    glVertex2f(0.07, -0.84);
    glVertex2f(0.05, -0.84);
    glEnd();

    //male 3 body
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.04, -0.9);
    glEnd();

    //male 3 right hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.1118827862726, -0.8790484298183);
    glVertex2f(0.1, -0.88);
    glVertex2f(0.08, -0.86);
    glEnd();

    //male 3 left hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.0047344834095, -0.8798540561556);
    glVertex2f(0.02, -0.88);
    glVertex2f(0.04, -0.86);
    glEnd();


    //male 3 right leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.07, -0.9);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.08, -0.94);
    glVertex2f(0.07, -0.94);
    glEnd();

    //male 3 left leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.04, -0.9);
    glVertex2f(0.05, -0.9);
    glVertex2f(0.05, -0.94);
    glVertex2f(0.04, -0.94);
    glEnd();
    glPopMatrix();

    //male 4
    //male 4 head
    glPushMatrix();
    //glTranslatef(peoplePosiX3, 0, 0);
    glTranslatef(peoplePosi3, peoplePosiY3, 0);
    glTranslatef(0.5, 0.17, 0);
    glScalef(0.6, 0.8, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05, -0.82);
    glVertex2f(0.07, -0.82);
    glVertex2f(0.07, -0.84);
    glVertex2f(0.05, -0.84);
    glEnd();

    //male 4 body
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.04, -0.9);
    glEnd();

    //male 4 right hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.1118827862726, -0.8790484298183);
    glVertex2f(0.1, -0.88);
    glVertex2f(0.08, -0.86);
    glEnd();

    //male 4 left hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.0047344834095, -0.8798540561556);
    glVertex2f(0.02, -0.88);
    glVertex2f(0.04, -0.86);
    glEnd();


    //male 4 right leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.07, -0.9);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.08, -0.94);
    glVertex2f(0.07, -0.94);
    glEnd();

    //male 4 left leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.04, -0.9);
    glVertex2f(0.05, -0.9);
    glVertex2f(0.05, -0.94);
    glVertex2f(0.04, -0.94);
    glEnd();
    glPopMatrix();


    //male
    //male 5 head
    glPushMatrix();
    glTranslatef(0.40, 0.17, 0);
    glScalef(0.6, 0.8, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05, -0.82);
    glVertex2f(0.07, -0.82);
    glVertex2f(0.07, -0.84);
    glVertex2f(0.05, -0.84);
    glEnd();

    //male 5 body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.04, -0.9);
    glEnd();

    //male 5 right hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.08, -0.84);
    glVertex2f(0.1118827862726, -0.8790484298183);
    glVertex2f(0.1, -0.88);
    glVertex2f(0.08, -0.86);
    glEnd();

    //male 5 left hand
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.69f, 0.42f);
    glVertex2f(0.04, -0.84);
    glVertex2f(0.0047344834095, -0.8798540561556);
    glVertex2f(0.02, -0.88);
    glVertex2f(0.04, -0.86);
    glEnd();


    //male 5 right leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.07, -0.9);
    glVertex2f(0.08, -0.9);
    glVertex2f(0.08, -0.94);
    glVertex2f(0.07, -0.94);
    glEnd();

    //male 5 left leg
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.04, -0.9);
    glVertex2f(0.05, -0.9);
    glVertex2f(0.05, -0.94);
    glVertex2f(0.04, -0.94);
    glEnd();
    glPopMatrix();

}

void planeStairs()
{
    glPushMatrix();
    // plane stairs
    glTranslatef(-0.75, 0.9, 0);
    glScalef(1.8, 2.8, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.5f, 0.7f);
    glVertex2f(0.8480169338707, -0.4779398902398);
    glVertex2f(0.8768457725925, -0.4782068239317);
    glVertex2f(0.8768457725925, -0.4568521285822);
    glVertex2f(0.8416105252658, -0.4565851948904);
    glVertex2f(0.7676698926183, -0.5299919601542);
    glVertex2f(0.8005027367181, -0.5329282307647);

    glEnd();
    glPopMatrix();
}
void s1Guard()
{
    glPushMatrix();

    //left hand

    glTranslatef(-0.15, -0.43, 0);
    glScalef(1.2, 1.2, 0);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_QUADS);
    glVertex2f(0.8118581612677, -0.0756386435841);
    glVertex2f(0.812, -0.084);
    glVertex2f(0.8027520682014, -0.0985304997389);
    glVertex2f(0.7978399333599, -0.0915002884061);
    glEnd();

    //stick
    glPushMatrix();
    glBegin(GL_POLYGON);
    glPushMatrix();
//    glRotatef(degree,0.0,0.0,1.0);//i=how many degree you want to rotate around an axis
    glColor3f(1, 0.61, 0);
    glVertex2f(0.804, -0.096);
    glVertex2f(0.7933333876338, -0.0948351322434);
    glVertex2f(0.796, -0.102);
    glVertex2f(0.7656966949229, -0.103144337336);
    glVertex2f(0.7654918112239, -0.0971002682156);
    glEnd();
    glPopMatrix();
    //degree -= 0.2f;

    /*glBegin(GL_POLYGON);
    glColor3f(1, 0.61, 0);
    glVertex2f(0.804, -0.096);
    glVertex2f(0.7738920428827, -0.0964856171186);
    glVertex2f(0.7744042521302, -0.102734569938);
    glVertex2f(0.7656966949229, -0.103144337336);
    glVertex2f(0.7654918112239, -0.0971002682156);
    glEnd();*/

    //left hand circle
    int i;

    GLfloat x=0.7978399333599;
    GLfloat y= -0.0969081432775;
    GLfloat radius =0.002f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    //Right Hand
    glBegin(GL_QUADS);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8362251551818, -0.0791617200516);
    glVertex2f(0.8375151533557, -0.0761064612185);
    glVertex2f(0.8459751143056, -0.0810051620434);
    glVertex2f(0.8436478435659, -0.0832711888162);
    //glVertex2f(0.8473837255428, -0.0947238106142);
    //glVertex2f(0.845, -0.095);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8459751143056, -0.0810051620434);
    glVertex2f(0.8436478435659, -0.0832711888162);
    glVertex2f(0.845, -0.095);
    glVertex2f(0.8473837255428, -0.0947238106142);
    glEnd();

    //Body
   // glPushMatrix();
    glBegin(GL_QUADS);
    //glScalef(0.3, 0, 0);
    glColor3f(0.28, 0.52, 0.65); //light blue
    glVertex2f(0.8118581612677, -0.0756386435841);
    glVertex2f(0.8117385908965, -0.1099553401166);
    glVertex2f(0.8380644720962, -0.1099228224276);
    glVertex2f(0.8380265710055, -0.0755940804963);
    glEnd();
   // glPopMatrix();

   //left shoe
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.8176906865971, -0.1346758609227);
    glVertex2f(0.8175897701719, -0.1363914401522);
    glVertex2f(0.8163445800508, -0.1375346516958);
    glVertex2f(0.820806099552, -0.1375218753116);
    glVertex2f(0.8209266193456, -0.1346294002655);
    glEnd();

    //right shoe
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.8308310868295, -0.1346843959931);
    glVertex2f(0.8307828957453, -0.1366025057886);
    glVertex2f(0.8290616769213, -0.1375969877758);
    glVertex2f(0.8337663417071, -0.1375587384686);
    glVertex2f(0.8336709145036, -0.1345927886488);
    glEnd();

   // leg
    glBegin(GL_POLYGON);
    glColor3f(0.14, 0.21, 0.26);
    glVertex2f(0.8136096854927, -0.1092036769419);
    glVertex2f(0.8169861587784, -0.1350433641005);
    glVertex2f(0.8217312285756, -0.135002077581);
    glVertex2f(0.8264919664211, -0.1120757558407);
    glVertex2f(0.83, -0.135);
    glVertex2f(0.8342675070304, -0.134949870833);
    glVertex2f(0.836789311689, -0.1092036769419);
    glEnd();

    //neck
        glBegin(GL_POLYGON);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8200366649169, -0.0757349548833);
    glVertex2f(0.8299160650001, -0.0757022054908);
    glVertex2f(0.8287759601759, -0.0686275255472);
    glVertex2f(0.82089785532, -0.0684772920997);
    glEnd();

   // glPopMatrix();

    //cap
   // glPushMatrix();
    int i1;

    GLfloat x1=0.8254555075085;
    GLfloat y1=-0.0554485732379;
    GLfloat radius1 =0.012f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0, 0, 0); //
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f( x1 + (radius1 * cos(i1 *  twicePi / triangleAmount1)),
                    y1 + (radius1 * sin(i1 * twicePi / triangleAmount1)));
    }

    glEnd();


    //face
   // glPushMatrix();
    int i2;

    GLfloat x2=0.8253346412721;
    GLfloat y2=-0.0600414902199;
    GLfloat radius2 =0.01f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f( x2 + (radius2 * cos(i2 *  twicePi / triangleAmount2)),
                    y2 + (radius2 * sin(i2 * twicePi / triangleAmount2)));
    }
    glEnd();


    glPopMatrix();
}

void bus()
{

    glPushMatrix();
    glTranslatef(bus1,0.0f, 0.0f);

    //glScalef(0.3,0.4,0);
    // Bus body
    glBegin(GL_POLYGON);
    glColor3f(0.01, 0.42, 0.19); //0.8f, 0.0f, 0.0f
    glVertex2f(-0.4695045723211f, -0.6600614181347f);
    glVertex2f(-0.4808187212447f, -0.6495952501527f);
    glVertex2f(-0.5f, -0.65f);
    glVertex2f(-0.85f, -0.65f);
    glVertex2f(-0.9f, -0.65f);
    glVertex2f(-0.9102422040561f, -0.659403056459f);
    glVertex2f(-0.9110041118201f, -0.8296508337166f);
    glVertex2f(-0.4495830653098f, -0.8287892763058f);
    glVertex2f(-0.4504050980276f, -0.7401200092675f);

    glEnd();

    // Bus window
    glBegin(GL_POLYGON);
    glColor3f(0, 0.72, 0.81);
    glVertex2f(-0.9000036361888f, -0.6594183505483f);
    glVertex2f(-0.9000347245076f, -0.7399424101709f);
    glVertex2f(-0.4504050980276f, -0.7401200092675f);
    glVertex2f(-0.4695045723211f, -0.6600614181347f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.14, 0.16, 0.16);
    glVertex2f(-0.6f, -0.65f);
    glVertex2f(-0.5995552526659f, -0.8290693017845f);
    glVertex2f(-0.5495099585867f, -0.8289758580755f);
    glVertex2f(-0.55, -0.65);

    glEnd();

    //bus back wheel

    int k;

    GLfloat x2=-0.8497885367983f;
    GLfloat y2=-0.8295365330519f;
    GLfloat radius2 =0.04f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(k = 0; k <= triangleAmount2; k++)
    {
        glVertex2f( x2 + (radius2 * cos(k *  twicePi2 / triangleAmount2)),
                    y2 + (radius2 * sin(k * twicePi2 / triangleAmount2)) );
    }
    glEnd();

    //bus back wheel inner

    int l;

    GLfloat x3=-0.8497885367983f;
    GLfloat y3=-0.8295365330519f;
    GLfloat radius3 =0.02f;
    int triangleAmount3 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi3 = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(l = 0; l <= triangleAmount3; l++)
    {
        glVertex2f( x3 + (radius3 * cos(l *  twicePi3 / triangleAmount3)),
                    y3 + (radius3 * sin(l * twicePi3 / triangleAmount3)) );
    }
    glEnd();

    //bus front wheel

    int n;

    GLfloat x5=-0.4999850064027f;
    GLfloat y5=-0.8288833859399f;
    GLfloat radius5 =0.04f;
    int triangleAmount5 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi5 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(n = 0; n <= triangleAmount5; n++)
    {
        glVertex2f( x5 + (radius5 * cos(n *  twicePi5 / triangleAmount5)),
                    y5 + (radius5 * sin(n * twicePi5 / triangleAmount5)) );
    }
    glEnd();

    //bus front wheel inner

    int m;

    GLfloat x4=-0.4999850064027f;
    GLfloat y4=-0.8288833859399f;
    GLfloat radius4 =0.02f;
    int triangleAmount4 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi4 = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(m = 0; m <= triangleAmount4; m++)
    {
        glVertex2f( x4 + (radius4 * cos(m *  twicePi4 / triangleAmount4)),
                    y4 + (radius4 * sin(m * twicePi4 / triangleAmount4)) );
    }
    glEnd();

    glPopMatrix();
}

void p1plane() //big
{

    glPushMatrix();
    glTranslatef(-0.3f,0.8f, 0.0f);

    glScalef(1.3,2.6,0);

    // plane back wing upper
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.453834565904, -0.4150203911111);
    glVertex2f(0.4413132868054, -0.4037512399224);
    glVertex2f(0.384967530862, -0.3330060130156);
    glVertex2f(0.3492818854311, -0.3305017571959);
    glVertex2f(0.3812111471324, -0.4363065655786);
    glVertex2f(0.4857638276052, -0.4356805016237);
    glVertex2f(0.4682340368673, -0.4250374143899);

    glEnd();

    // plane body
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(0.8977139099473f, -0.4344283737138f);
    glVertex2f(0.3624292284846f, -0.4312980539392f);
    glVertex2f(0.3567946528902f, -0.4425672051279f);
    glVertex2f(0.3661856122141f, -0.4544624202715f);
    glVertex2f(0.4087579611492f, -0.4744964668292f);
    glVertex2f(0.4744946764166f, -0.4926523215221f);
    glVertex2f(0.53084043236f, -0.4976608331615f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.9127394448656f, -0.4989129610713f);

    glEnd();

    // plane back wing lower
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.4125527117245, -0.4423089322181);
    glVertex2f(0.3288780371959, -0.4271718051677);
    glVertex2f(0.3322418432071, -0.4368427474499);
    glVertex2f(0.3789146516125, -0.4456727382293);

    glEnd();

    // plane head
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(0.8977139099473f, -0.4344283737138f);
    glVertex2f(0.9247857386493f, -0.4479683942438f);
    glVertex2f(0.9433514513941f, -0.4586264885973f);
    glVertex2f(0.9526343077665f, -0.4651588690075f);
    glVertex2f(0.9574476407003f, -0.4710036304272f);
    glVertex2f(0.957103831205f, -0.479598867809f);
    glVertex2f(0.9509152602901f, -0.4864750577145f);
    glVertex2f(0.9402571659366f, -0.4936950571152f);
    glVertex2f(0.9127394448656f, -0.4989129610713f);

    glEnd();

    // plane windows
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.9256744934873, -0.450591394366);
    glVertex2f(0.9276482207513, -0.4508874534555);
    glVertex2f(0.9405761343301, -0.4579928716057);
    glVertex2f(0.9275495343881, -0.4581902443321);

    glVertex2f(0.9237469764796, -0.4501353634441);
    glVertex2f(0.9255491562447, -0.4583144869934);
    glVertex2f(0.918059109292, -0.4585160168402);
    glVertex2f(0.9168155158445, -0.4501353634441);

    glVertex2f(0.9143935040751, -0.4501353634441);
    glVertex2f(0.9157174026592, -0.4590243967944);
    glVertex2f(0.9068283693088, -0.4592135251636);
    glVertex2f(0.905882727463, -0.4495679783366);

    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);

    glEnd();

    glPushMatrix();
    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glPopMatrix();

    // plane front wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.7788006755522, -0.4645848791358);
    glVertex2f(0.6378106843029, -0.4645848791358);
    glVertex2f(0.4, -0.5);
    glVertex2f(0.4326572097441, -0.5114129933393);

    glEnd();

   /* // plane stairs
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.5f, 0.7f);
    glVertex2f(0.8480169338707, -0.4779398902398);
    glVertex2f(0.8768457725925, -0.4782068239317);
    glVertex2f(0.8768457725925, -0.4568521285822);
    glVertex2f(0.8416105252658, -0.4565851948904);
    glVertex2f(0.7676698926183, -0.5299919601542);
    glVertex2f(0.8005027367181, -0.5329282307647);

    glEnd();*/

    // plane stand
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.760904537895, -0.4819130852586);
    glVertex2f(0.7180717940161, -0.4813708986272);
    glVertex2f(0.7180717940161, -0.518239589561);
    glVertex2f(0.7603623512636, -0.5209505227179);

    glEnd();

    //wheel

    int i;

    GLfloat x=0.6533695054314f;
    GLfloat y=-0.5108629079308f;
    GLfloat radius =0.012f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //wheel inner

    int j;

    GLfloat x1=0.6533695054314f;
    GLfloat y1=-0.5108629079308f;
    GLfloat radius1 =0.007f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(j = 0; j <= triangleAmount; j++)
    {
        glVertex2f( x1 + (radius1 * cos(j *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(j * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();
}

void p1plane2() //small
{
    //Plane
    //plane body
    glPushMatrix();
    glTranslatef(p1Pane1,0.6f, 0.0f);

    glScalef(0.3,0.4,0);

    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.8375889660587f, 0.2912098678332f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.928861465027f, 0.2556290631507f);
    glVertex2f(-0.9041096009f, 0.2378386608094f);
    glVertex2f(-0.8731697707412f, 0.2277832160078f);
    glVertex2f(-0.8453239235984f, 0.2192747627141f);
    glVertex2f(-0.8143840934396f, 0.2107663094205f);
    glVertex2f(-0.7842177590348f, 0.2068988306506f);
    glVertex2f(-0.7439959798284f, 0.2076723264046f);
    glVertex2f(-0.3897349245107f, 0.2092193179125f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.4043823800643f, 0.2892785841354f);
    glVertex2f(-0.3831964687035f, 0.2802549552225f);
    glVertex2f(-0.3545562551972f, 0.2671118435449f);
    glVertex2f(-0.3380783241388f, 0.2622076973966f);
    glVertex2f(-0.3237582173856f, 0.2573035512482f);
    glVertex2f(-0.3176770761617f, 0.2518109075621f);
    glVertex2f(-0.3121844324755f, 0.2463182638759f);
    glVertex2f(-0.31f, 0.24f);
    glVertex2f(-0.3098304423243f, 0.2357253081955f);
    glVertex2f(-0.31f, 0.23f);
    glVertex2f(-0.313753759243f, 0.2259170158989f);
    glVertex2f(-0.3204233980047f, 0.2227783623639f);
    glVertex2f(-0.3280738659961f, 0.2190512112912f);
    glVertex2f(-0.3378821582928f, 0.2157163919103f);
    glVertex2f(-0.3500444407407f, 0.2127739042213f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head window
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3819451920869f, 0.2758911800548f);
    glVertex2f(-0.3881479557192f, 0.2728587178345f);
    glVertex2f(-0.3771897399688f, 0.2608667081453f);
    glVertex2f(-0.370504539165f, 0.2634167331942f);
    glVertex2f(-0.3660936850265f, 0.2658289190512f);
    glVertex2f(-0.360855795737f, 0.2696194968265f);
    glVertex2f(-0.3786950838177f, 0.2781892511995f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.398899412682f, 0.2686546224837f);
    glVertex2f(-0.4098576284324f, 0.2679654265246f);
    glVertex2f(-0.40854815611f, 0.262727537235f);
    glVertex2f(-0.4031035080328f, 0.2555598992599f);
    glVertex2f(-0.3925588098578f, 0.2561801756231f);
    glVertex2f(-0.3804978805727f, 0.2588680398638f);
    glVertex2f(-0.39f, 0.27f);
    glVertex2f(-0.39f, 0.27f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4127657925046f, 0.2602777634305f);
    glVertex2f(-0.4148377327393f, 0.2667761214393f);
    glVertex2f(-0.4317899710231f, 0.2668703005408f);
    glVertex2f(-0.432260866531f, 0.260371942532f);
    glVertex2f(-0.4296238516869f, 0.2515191069838f);
    glVertex2f(-0.4077743001211f, 0.2526492562027f);

    glEnd();

    //front door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4695704482148f, 0.2425964533209f);
    glVertex2f(-0.4727942748017f, 0.2424499157487f);
    glVertex2f(-0.4726477372296f, 0.2379072510126f);
    glVertex2f(-0.4692773730705f, 0.2380537885847f);

    glEnd();

    //upper wing
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.5498485455822f, 0.2873423890634f);
    glVertex2f(-0.6217836507013f, 0.3770678965238f);
    glVertex2f(-0.6565909596299f, 0.3778413922778f);
    glVertex2f(-0.6488595295804f, 0.2915606660423f);

    glEnd();

    //lower wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8512841908058f, 0.1241487992192f);
    glVertex2f(-0.8652666039946f, 0.1246309513981f);
    glVertex2f(-0.8522484951637f, 0.1101663860304f);
    glVertex2f(-0.8291051905754f, 0.1111306903883f);
    glVertex2f(-0.5055818995018f, 0.2087134359257f);
    glVertex2f(-0.7114611649165f, 0.2078143998322f);

    glEnd();

    //lower wing back
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.847900370437f, 0.2811701757442f);
    glVertex2f(-0.9292604039938f, 0.2448081495735f);
    glVertex2f(-0.9792581899784f, 0.2452626749007f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);

    glEnd();

    //upper wing back
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8228925467333f, 0.3035857998967f);
    glVertex2f(-0.8414564448285f, 0.3120942531904f);
    glVertex2f(-0.8561528641539f, 0.3283376640237f);
    glVertex2f(-0.9056565924079f, 0.3909908200952f);
    glVertex2f(-0.9427843885984f, 0.3894438285873f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.7617837686202f, 0.2913507696872f);
    glVertex2f(-0.7934997080824f, 0.2958508423571f);
    glVertex2f(-0.8097431189158f, 0.2989448253729f);

    glEnd();

    //back door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7678874563725f, 0.2510951983408f);
    glVertex2f(-0.7708790248524f, 0.2509192237244f);
    glVertex2f(-0.7707910375442f, 0.2473997313951f);
    glVertex2f(-0.7677114817561f, 0.2476636933198f);

    glEnd();

    //windows from left
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7151099662305f, 0.266868589599f);
    glVertex2f(-0.714460252525f, 0.2434788962022f);
    glVertex2f(-0.6962682687719f, 0.2434788962022f);
    glVertex2f(-0.6975676961829f, 0.266868589599f);

    glVertex2f(-0.6819745672516f, 0.26816801701f);
    glVertex2f(-0.6813248535462f, 0.2441286099077f);
    glVertex2f(-0.6637825834985f, 0.2444534667604f);
    glVertex2f(-0.6641074403513f, 0.2678431601572f);

    glVertex2f(-0.6501385956837f, 0.266868589599f);
    glVertex2f(-0.6491640251255f, 0.2447783236131f);
    glVertex2f(-0.6316217550779f, 0.2444534667604f);
    glVertex2f(-0.6329211824888f, 0.2671934464518f);

    glVertex2f(-0.6196020515268f, 0.2671934464518f);
    glVertex2f(-0.6183026241158f, 0.2451031804659f);
    glVertex2f(-0.6014100677737f, 0.2447783236131f);
    glVertex2f(-0.6030343520373f, 0.266868589599f);

    glVertex2f(-0.5858169388425f, 0.2662188758936f);
    glVertex2f(-0.585167225137f, 0.2457528941713f);
    glVertex2f(-0.5702238099112f, 0.2454280373186f);
    glVertex2f(-0.5711983804694f, 0.266868589599f);

    glVertex2f(-0.5533312535691f, 0.266868589599f);
    glVertex2f(-0.5520318261581f, 0.2454280373186f);
    glVertex2f(-0.5370884109324f, 0.2447783236131f);
    glVertex2f(-0.5393624089015f, 0.266868589599f);

    glVertex2f(-0.5227947094121f, 0.2665437327463f);
    glVertex2f(-0.5208455682957f, 0.2431540393495f);
    glVertex2f(-0.5039530119536f, 0.2434788962022f);
    glVertex2f(-0.5055772962172f, 0.266868589599f);

    glEnd();
    glPopMatrix();
}
//Static useless plane
void p1plane3()
{
    //Plane
    //plane body
    glPushMatrix();
    glTranslatef(-0.95f,0.1f, 0.0f);

    glScalef(0.7,1.4,0);

    // plane back wing upper
    glBegin(GL_POLYGON);
    glColor3f(0.57, 0.63, 0.6);
    glVertex2f(0.453834565904, -0.4150203911111);
    glVertex2f(0.4413132868054, -0.4037512399224);
    glVertex2f(0.384967530862, -0.3330060130156);
    glVertex2f(0.3492818854311, -0.3305017571959);
    glVertex2f(0.3812111471324, -0.4363065655786);
    glVertex2f(0.4857638276052, -0.4356805016237);
    glVertex2f(0.4682340368673, -0.4250374143899);

    glEnd();

    // plane body
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(0.8977139099473f, -0.4344283737138f);
    glVertex2f(0.3624292284846f, -0.4312980539392f);
    glVertex2f(0.3567946528902f, -0.4425672051279f);
    glVertex2f(0.3661856122141f, -0.4544624202715f);
    glVertex2f(0.4087579611492f, -0.4744964668292f);
    glVertex2f(0.4744946764166f, -0.4926523215221f);
    glVertex2f(0.53084043236f, -0.4976608331615f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.9127394448656f, -0.4989129610713f);

    glEnd();

    // plane back wing lower
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.4125527117245, -0.4423089322181);
    glVertex2f(0.3288780371959, -0.4271718051677);
    glVertex2f(0.3322418432071, -0.4368427474499);
    glVertex2f(0.3789146516125, -0.4456727382293);

    glEnd();

    // plane head
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(0.8977139099473f, -0.4344283737138f);
    glVertex2f(0.9247857386493f, -0.4479683942438f);
    glVertex2f(0.9433514513941f, -0.4586264885973f);
    glVertex2f(0.9526343077665f, -0.4651588690075f);
    glVertex2f(0.9574476407003f, -0.4710036304272f);
    glVertex2f(0.957103831205f, -0.479598867809f);
    glVertex2f(0.9509152602901f, -0.4864750577145f);
    glVertex2f(0.9402571659366f, -0.4936950571152f);
    glVertex2f(0.9127394448656f, -0.4989129610713f);

    glEnd();

    // plane windows
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.9256744934873, -0.450591394366);
    glVertex2f(0.9276482207513, -0.4508874534555);
    glVertex2f(0.9405761343301, -0.4579928716057);
    glVertex2f(0.9275495343881, -0.4581902443321);

    glVertex2f(0.9237469764796, -0.4501353634441);
    glVertex2f(0.9255491562447, -0.4583144869934);
    glVertex2f(0.918059109292, -0.4585160168402);
    glVertex2f(0.9168155158445, -0.4501353634441);

    glVertex2f(0.9143935040751, -0.4501353634441);
    glVertex2f(0.9157174026592, -0.4590243967944);
    glVertex2f(0.9068283693088, -0.4592135251636);
    glVertex2f(0.905882727463, -0.4495679783366);

    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);

    glEnd();

    glPushMatrix();
    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glTranslatef(0.03f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4959488218617, -0.448614230922);
    glVertex2f(0.5054700735676, -0.448614230922);
    glVertex2f(0.5057274046948, -0.4637967674261);
    glVertex2f(0.4962061529889, -0.4637967674261);
    glEnd();

    glPopMatrix();

    // plane front wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.7788006755522, -0.4645848791358);
    glVertex2f(0.6378106843029, -0.4645848791358);
    glVertex2f(0.4, -0.5);
    glVertex2f(0.4326572097441, -0.5114129933393);

    glEnd();

    // plane stairs
    glBegin(GL_QUADS);
    glColor3f(0.15, 0.29, 0.22);
    glVertex2f(0.8480169338707, -0.4779398902398);
    glVertex2f(0.8768457725925, -0.4782068239317);
    glVertex2f(0.8768457725925, -0.4568521285822);
    glVertex2f(0.8416105252658, -0.4565851948904);
    /* glVertex2f(0.7676698926183, -0.5299919601542);
     glVertex2f(0.8005027367181, -0.5329282307647); */

    glEnd();

    // plane stand
    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.17, 0.16);
    glVertex2f(0.760904537895, -0.4819130852586);
    glVertex2f(0.7180717940161, -0.4813708986272);
    glVertex2f(0.7180717940161, -0.518239589561);
    glVertex2f(0.7603623512636, -0.5209505227179);

    glEnd();

    //wheel

    int i;

    GLfloat x=0.6533695054314f;
    GLfloat y=-0.5108629079308f;
    GLfloat radius =0.012f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //wheel inner

    int j;

    GLfloat x1=0.6533695054314f;
    GLfloat y1=-0.5108629079308f;
    GLfloat radius1 =0.007f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(j = 0; j <= triangleAmount; j++)
    {
        glVertex2f( x1 + (radius1 * cos(j *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(j * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
}

void display1()
{
    glClearColor(0.7f, 0.93f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.43f, 0.72f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.56f, 0.76f, 0.89f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.43f, 0.72f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.9f, 0.9f, 0.89f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();

//airport circle 1

    int i;

    GLfloat x=-0.583856058564953f;
    GLfloat y=-0.23614373518506945f;
    GLfloat radius =0.3611f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.02f, 0.1f, 0.42f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

//airport circle 2

    int j;

    GLfloat x1=-0.5859643178082;
    GLfloat y1=-0.256620191719f;
    GLfloat radius1 =0.359f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.07f, 0.48f, 0.66f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(j = 0; j <= triangleAmount; j++)
    {
        glVertex2f( x1 + (radius * cos(j *  twicePi / triangleAmount)),
                    y1 + (radius * sin(j * twicePi / triangleAmount)) );
    }
    glEnd();


    // watch tower
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.38, 0.38);
    glVertex2f(-0.1102995485303f,-0.0612215736412f);
    glVertex2f(-0.0337373771478f,-0.0615044573022f);
    glVertex2f(-0.0356210868922f,0.2287086516216f);
    glVertex2f(-0.1105527785138f,0.2293659471621f);

    glEnd();

    // watch tower top strip line
    glBegin(GL_QUADS);
    glColor3f(0.07f, 0.48f, 0.66f);
    glVertex2f(-0.125f,0.22f);
    glVertex2f(-0.025f,0.22f);
    glVertex2f(-0.025f,0.21f);
    glVertex2f(-0.125f,0.21f);

    glEnd();

    // watch tower office
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.35f, 0.37f);
    glVertex2f(-0.16f,0.12f);
    glVertex2f(0.0134240711927f,0.1192875328006f);
    glVertex2f(-0.003165852062f,0.0f);
    glVertex2f(-0.14f,0.0f);

    glEnd();

    // watch tower office glass
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.86f, 0.88f);
    glVertex2f(-0.14f,0.1f);
    glVertex2f(-0.0071825104591f,0.0999776622934f);
    glVertex2f(-0.0237509158983f,0.0401697597321f);
    glVertex2f(-0.1239695634332f,0.040371813457f);

    glEnd();



    // Airport upper right office
    glBegin(GL_POLYGON);
    glColor3f(0.07f, 0.48f, 0.66f);
    glVertex2f(-0.2682895933982f,-0.0606378284119f);
    glVertex2f(0.1099072498738f,-0.0620351987537f);
    glVertex2f(0.1118009194931f,-0.2093890785101f);
    glVertex2f(-0.3160241842725f,-0.208327875731f);

    glEnd();

    // Airport upper right office glass
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.92f, 0.92f);
    glVertex2f(-0.24f,-0.08f);
    glVertex2f(0.08f,-0.08f);
    glVertex2f(0.08f,-0.18f);
    glVertex2f(-0.24f,-0.18f);

    glEnd();

    // Airport upper right office window 1
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.22f,-0.1f);
    glVertex2f(-0.18f,-0.1f);
    glVertex2f(-0.18f, -0.16f);
    glVertex2f(-0.22f, -0.16f);

    glEnd();


    // Airport upper right office window 2
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.16f, -0.1f);
    glVertex2f(-0.12f, -0.1f);
    glVertex2f(-0.12f, -0.16f);
    glVertex2f(-0.16f, -0.16f);

    glEnd();

    // Airport upper right office window 3
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(-0.06f, -0.1f);
    glVertex2f(-0.06f, -0.16f);
    glVertex2f(-0.1f, -0.16f);

    glEnd();

    // Airport upper right office window 4
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.04f, -0.1f);
    glVertex2f(0.0f, -0.1f);
    glVertex2f(0.0f, -0.16f);
    glVertex2f(-0.04f, -0.16f);

    glEnd();

    // Airport upper right office window 5
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(0.02f, -0.1f);
    glVertex2f(0.06f, -0.1f);
    glVertex2f(0.06f, -0.16f);
    glVertex2f(0.02f, -0.16f);

    glEnd();


    // Airport upper left office
    glBegin(GL_POLYGON);
    glColor3f(0.07f, 0.48f, 0.66f);
    glVertex2f(-1.0f,-0.066622938344f);
    glVertex2f(-0.9026003999755f,-0.0664777042041f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-1.0f,-0.2f);

    glEnd();

    // Airport upper left office glass
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.92f, 0.92f);
    glVertex2f(-0.92f, -0.09f);
    glVertex2f(-0.92f, -0.18f);
    glVertex2f(-1.0f,-0.18f);
    glVertex2f(-1.0f,-0.09f);

    glEnd();

    // Airport upper left office window 1
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.98f, -0.1f);
    glVertex2f(-0.94f, -0.1f);
    glVertex2f(-0.94f, -0.16f);
    glVertex2f(-0.98f, -0.16f);

    glEnd();


    //Airport bottom building
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.23f, 0.37f);
    glVertex2f(-1.0f,-0.2f);
    glVertex2f(0.3277225656001f,-0.2002190647208f);
    glVertex2f(0.3282424667374f,-0.4f);
    glVertex2f(-1.0f,-0.4f);

    glEnd();

    //Airport entrance gate
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.92f, 0.92f);
    glVertex2f(-0.8001023261902f, -0.2365646163888f);
    glVertex2f(-0.4004081986305f, -0.2360186653851f);
    glVertex2f(-0.4f,-0.4f);
    glVertex2f(-0.8f,-0.4f);

    glEnd();

    //Airport entrance gate door 1
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.78f, -0.26f);
    glVertex2f(-0.72f, -0.26f);
    glVertex2f(-0.72f,-0.4f);
    glVertex2f(-0.78f,-0.4f);

    glEnd();

    //Airport entrance gate door 2
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.7f, -0.26f);
    glVertex2f(-0.64f, -0.26f);
    glVertex2f(-0.64f,-0.4f);
    glVertex2f(-0.7f,-0.4f);

    glEnd();

    //Airport entrance gate door 3
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.62f, -0.26f);
    glVertex2f(-0.56f, -0.26f);
    glVertex2f(-0.56f,-0.4f);
    glVertex2f(-0.62f,-0.4f);

    glEnd();

    //Airport entrance gate door 4
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.54f, -0.26f);
    glVertex2f(-0.48f, -0.26f);
    glVertex2f(-0.48f,-0.4f);
    glVertex2f(-0.54f,-0.4f);

    glEnd();

    //Airport entrance gate door 5
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.46f, -0.26f);
    glVertex2f(-0.4086779264935f, -0.2596154234035f);
    glVertex2f(-0.4090586441357f,-0.4f);
    glVertex2f(-0.46f,-0.4f);

    glEnd();


    //Airport bottom right glass
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.92f, 0.92f);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(0.3f, -0.25f);
    glVertex2f(0.3f, -0.35f);
    glVertex2f(-0.3f, -0.35f);

    glEnd();


    // Airport bottom right window 1
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.28f, -0.26f);
    glVertex2f(-0.24f, -0.26f);
    glVertex2f(-0.24f, -0.34f);
    glVertex2f(-0.28f, -0.34f);

    glEnd();

    // Airport bottom right window 2
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.22f, -0.26f);
    glVertex2f(-0.18f, -0.26f);
    glVertex2f(-0.18f, -0.34f);
    glVertex2f(-0.22f, -0.34f);

    glEnd();

    // Airport bottom right window 3
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.16f, -0.26f);
    glVertex2f(-0.12f, -0.26f);
    glVertex2f(-0.12f, -0.34f);
    glVertex2f(-0.16f, -0.34f);

    glEnd();

    // Airport bottom right window 4
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.1f, -0.26f);
    glVertex2f(-0.06f, -0.26f);
    glVertex2f(-0.06f, -0.34f);
    glVertex2f(-0.1f, -0.34f);

    glEnd();

    // Airport bottom right window 5
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.04f, -0.26f);
    glVertex2f(0.0f, -0.26f);
    glVertex2f(0.0f, -0.34f);
    glVertex2f(-0.04f, -0.34f);

    glEnd();

    // Airport bottom right window 6
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(0.02f, -0.26f);
    glVertex2f(0.06f, -0.26f);
    glVertex2f(0.06f, -0.34f);
    glVertex2f(0.02f, -0.34f);

    glEnd();

    // Airport bottom right window 7
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(0.08f, -0.26f);
    glVertex2f(0.12f, -0.26f);
    glVertex2f(0.12f, -0.34f);
    glVertex2f(0.08f, -0.34f);

    glEnd();

    // Airport bottom right window 8
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(0.14f, -0.26f);
    glVertex2f(0.18f, -0.26f);
    glVertex2f(0.18f, -0.34f);
    glVertex2f(0.14f, -0.34f);

    glEnd();

    // Airport bottom right window 9
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(0.2f, -0.26f);
    glVertex2f(0.24f, -0.26f);
    glVertex2f(0.24f, -0.34f);
    glVertex2f(0.2f, -0.34f);

    glEnd();

    // Airport bottom right window 10
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(0.26f, -0.26f);
    glVertex2f(0.3f,-0.26f);
    glVertex2f(0.3f, -0.34f);
    glVertex2f(0.26f, -0.34f);

    glEnd();

    //Airport bottom left glass
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.92f, 0.92f);
    glVertex2f(-1.0f, -0.25f);
    glVertex2f(-0.9f, -0.25f);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-1.0f, -0.35f);

    glEnd();

    // Airport bottom left window 1
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-0.96f, -0.26f);
    glVertex2f(-0.92f, -0.26f);
    glVertex2f(-0.92f, -0.34f);
    glVertex2f(-0.96f, -0.34f);

    glEnd();

    // Airport bottom left window 2
    glBegin(GL_QUADS);
    glColor3f(0.29f, 0.84f, 1.0f);
    glVertex2f(-1.0f, -0.26f);
    glVertex2f(-0.98f, -0.26f);
    glVertex2f(-0.98f, -0.34f);
    glVertex2f(-1.0f, -0.34f);

    glEnd();

    //Lamp post 1

    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.45f, 0.45f);
    glVertex2f(0.2f, -0.165f);
    glVertex2f(0.205f, -0.165f);
    glVertex2f(0.205f, -0.41f);
    glVertex2f(0.2f, -0.41f);

    glEnd();

    //Light 1

    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.1830005402448f, -0.1500494702811f);
    glVertex2f(0.1989460030809f, -0.1499929260866f);
    glVertex2f(0.1989460030809f, -0.1598881601161f);
    glVertex2f(0.1831136286337f, -0.1598881601161f);

    glEnd();

    //Light 2

    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.2060140273877f, -0.1499929260866f);
    glVertex2f(0.2219594902237f, -0.1500494702811f);
    glVertex2f(0.2220160344182f, -0.160001248505f);
    glVertex2f(0.2059009389987f, -0.1598881601161f);

    glEnd();

    //Light 3

    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.2059225026114f, -0.1698869116111f);
    glVertex2f(0.2219225026114f, -0.1698869116111f);
    glVertex2f(0.2219225026114f, -0.1798869116111f);
    glVertex2f(0.2059225026114f, -0.1798869116111f);

    glEnd();

    //Light 4

    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.1830005402448f, -0.1700095709234f);
    glVertex2f(0.1990025472753f, -0.1698964825345f);
    glVertex2f(0.1990025472753f, -0.1800178933418f);
    glVertex2f(0.1829439960503f, -0.1800178933418f);

    glEnd();


    //Lamp post 2

    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.45f, 0.45f);
    glVertex2f(0.73f, -0.165f);
    glVertex2f(0.735f, -0.165f);
    glVertex2f(0.735f, -0.41f);
    glVertex2f(0.73f, -0.41f);

    glEnd();

    //Light 1

    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.7130945034847f, -0.1501120403377f);
    glVertex2f(0.7290399663208f, -0.1500554961432f);
    glVertex2f(0.7290399663208f, -0.1599507301727f);
    glVertex2f(0.7132075918736f, -0.1599507301727f);

    glEnd();

    //Light 2

    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.7361079906276f, -0.1500554961432f);
    glVertex2f(0.7520534534637f, -0.1501120403377f);
    glVertex2f(0.7521099976581f, -0.1600638185616f);
    glVertex2f(0.7359949022387f, -0.1599507301727f);

    glEnd();

    //Light 3

    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.7360164658514f, -0.1699494816677f);
    glVertex2f(0.7520164658514f, -0.1699494816677f);
    glVertex2f(0.7520164658514f, -0.1799494816677f);
    glVertex2f(0.7360164658514f, -0.1799494816677f);

    glEnd();

    //Light 4

    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.7130945034847f, -0.17007214098f);
    glVertex2f(0.7290965105153f, -0.1699590525911f);
    glVertex2f(0.7290965105153f, -0.1800804633984f);
    glVertex2f(0.7130379592903f, -0.1800804633984f);

    glEnd();

    /*/text trial
    glColor3ub(1,1,1);
    glRasterPos2f(-0.7438960498561f, -0.0396076187924f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
    glColor3ub(1,1,1);
    glRasterPos2f(-0.71f, -0.04f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
    glColor3ub(1,1,1);
    glRasterPos2f(-0.68f, -0.04f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
    glColor3ub(1,1,1);
    glRasterPos2f(-0.63f, -0.04f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'P');
    glColor3ub(1,1,1);
    glRasterPos2f(-0.58f, -0.04f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
    glColor3ub(1,1,1);
    glRasterPos2f(-0.53f, -0.04f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
    glColor3ub(1,1,1);
    glRasterPos2f(-0.48f, -0.04f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'T');*/

    //Airport
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.77f, -0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "A  I  R  P  O  R  T");






    //Road
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-1.0f,-0.4f);
    glVertex2f(1.0f,-0.4f);
    glVertex2f(1.0f,-1.0f);
    glVertex2f(-1.0f,-1.0f);

    glEnd();

    //Road strip
    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.14f, 0.14f);
    glVertex2f(-1.0f,-0.4396478851608f);
    glVertex2f(1.0f,-0.4396478851608f);
    glVertex2f(1.0f,-0.46f);
    glVertex2f(-1.0f,-0.46f);

    glEnd();

    //Road divider 1
    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(-0.94f,-0.7000733757035f);
    glVertex2f(-0.24f,-0.6997968828742f);
    glVertex2f(-0.24f,-0.7402031171258f);
    glVertex2f(-0.94f,-0.7399266242965f);

    glEnd();

    //Road divider 2
    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(0.25f,-0.7005740707988f);
    glVertex2f(0.88f,-0.7005740707988f);
    glVertex2f(0.88f,-0.739573630499f);
    glVertex2f(0.25f,-0.739573630499f);


    glEnd();

    clouds1(-1.3, 0.0);
    clouds1(-2.3, 0.53);
    clouds1(-1.8, 0.4);
    clouds1(-2.8, 0.3);
    p1plane3();
    bus();
    pickup();
    p1plane();
    p1plane2();
    people();
    planeStairs();
    s1Guard();

    glFlush(); // Render now

}

//Scene 2
void stars()
{
    // Stars
    //glLoadIdentity();                // Reset the model-view matrix
    glPushMatrix();
    // glTranslatef(position,0.0f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(0.1f, -0.1f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(0.19f, -0.25f, 0.0f);
    glColor3f(1, 0.98, 0.91);//1, 0.98, 0.91
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(+0.25f, -0.1f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(+0.4f, -0.25f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(0.2f, 0.2f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(-0.5f, 0.2f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(0.3f, 0.14f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(0.2f, 0.1f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(0.1f, -0.3f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(-0.1f, -0.5f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glTranslatef(-0.3f, 0.34f, 0.0f);
    glColor3f(1, 0.98, 0.91);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9587822253225f, 0.96f);
    glVertex2f(-0.9499977712368f, 0.976162988322f);
    glVertex2f(-0.9412149485386f, 0.96f);
    glVertex2f(-0.92f, 0.96f);
    glVertex2f(-0.936551442214f, 0.9514177707038f);
    glVertex2f(-0.926f, 0.932f);
    glVertex2f(-0.95f, 0.9444444444444f);
    glVertex2f(-0.974f, 0.932f);
    glVertex2f(-0.9634470287737f,0.9514169778827f);
    glVertex2f(-0.98f, 0.96f);
    glEnd();

    glPopMatrix();
    // glLoadIdentity();                // Reset the model-view matrix
}

void p2plane()
{
    //Plane
    //plane body
    glPushMatrix();
    glTranslatef(p2Plane1,0.0f, 0.0f);

    glScalef(1,1.3,0);

    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.8375889660587f, 0.2912098678332f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.928861465027f, 0.2556290631507f);
    glVertex2f(-0.9041096009f, 0.2378386608094f);
    glVertex2f(-0.8731697707412f, 0.2277832160078f);
    glVertex2f(-0.8453239235984f, 0.2192747627141f);
    glVertex2f(-0.8143840934396f, 0.2107663094205f);
    glVertex2f(-0.7842177590348f, 0.2068988306506f);
    glVertex2f(-0.7439959798284f, 0.2076723264046f);
    glVertex2f(-0.3897349245107f, 0.2092193179125f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.4043823800643f, 0.2892785841354f);
    glVertex2f(-0.3831964687035f, 0.2802549552225f);
    glVertex2f(-0.3545562551972f, 0.2671118435449f);
    glVertex2f(-0.3380783241388f, 0.2622076973966f);
    glVertex2f(-0.3237582173856f, 0.2573035512482f);
    glVertex2f(-0.3176770761617f, 0.2518109075621f);
    glVertex2f(-0.3121844324755f, 0.2463182638759f);
    glVertex2f(-0.31f, 0.24f);
    glVertex2f(-0.3098304423243f, 0.2357253081955f);
    glVertex2f(-0.31f, 0.23f);
    glVertex2f(-0.313753759243f, 0.2259170158989f);
    glVertex2f(-0.3204233980047f, 0.2227783623639f);
    glVertex2f(-0.3280738659961f, 0.2190512112912f);
    glVertex2f(-0.3378821582928f, 0.2157163919103f);
    glVertex2f(-0.3500444407407f, 0.2127739042213f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head window
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3819451920869f, 0.2758911800548f);
    glVertex2f(-0.3881479557192f, 0.2728587178345f);
    glVertex2f(-0.3771897399688f, 0.2608667081453f);
    glVertex2f(-0.370504539165f, 0.2634167331942f);
    glVertex2f(-0.3660936850265f, 0.2658289190512f);
    glVertex2f(-0.360855795737f, 0.2696194968265f);
    glVertex2f(-0.3786950838177f, 0.2781892511995f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.398899412682f, 0.2686546224837f);
    glVertex2f(-0.4098576284324f, 0.2679654265246f);
    glVertex2f(-0.40854815611f, 0.262727537235f);
    glVertex2f(-0.4031035080328f, 0.2555598992599f);
    glVertex2f(-0.3925588098578f, 0.2561801756231f);
    glVertex2f(-0.3804978805727f, 0.2588680398638f);
    glVertex2f(-0.39f, 0.27f);
    glVertex2f(-0.39f, 0.27f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4127657925046f, 0.2602777634305f);
    glVertex2f(-0.4148377327393f, 0.2667761214393f);
    glVertex2f(-0.4317899710231f, 0.2668703005408f);
    glVertex2f(-0.432260866531f, 0.260371942532f);
    glVertex2f(-0.4296238516869f, 0.2515191069838f);
    glVertex2f(-0.4077743001211f, 0.2526492562027f);

    glEnd();

    //front door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4695704482148f, 0.2425964533209f);
    glVertex2f(-0.4727942748017f, 0.2424499157487f);
    glVertex2f(-0.4726477372296f, 0.2379072510126f);
    glVertex2f(-0.4692773730705f, 0.2380537885847f);

    glEnd();

    //upper wing
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.5498485455822f, 0.2873423890634f);
    glVertex2f(-0.6217836507013f, 0.3770678965238f);
    glVertex2f(-0.6565909596299f, 0.3778413922778f);
    glVertex2f(-0.6488595295804f, 0.2915606660423f);

    glEnd();

    //lower wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8512841908058f, 0.1241487992192f);
    glVertex2f(-0.8652666039946f, 0.1246309513981f);
    glVertex2f(-0.8522484951637f, 0.1101663860304f);
    glVertex2f(-0.8291051905754f, 0.1111306903883f);
    glVertex2f(-0.5055818995018f, 0.2087134359257f);
    glVertex2f(-0.7114611649165f, 0.2078143998322f);

    glEnd();

    //lower wing back
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.847900370437f, 0.2811701757442f);
    glVertex2f(-0.9292604039938f, 0.2448081495735f);
    glVertex2f(-0.9792581899784f, 0.2452626749007f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);

    glEnd();

    //upper wing back
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8228925467333f, 0.3035857998967f);
    glVertex2f(-0.8414564448285f, 0.3120942531904f);
    glVertex2f(-0.8561528641539f, 0.3283376640237f);
    glVertex2f(-0.9056565924079f, 0.3909908200952f);
    glVertex2f(-0.9427843885984f, 0.3894438285873f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.7617837686202f, 0.2913507696872f);
    glVertex2f(-0.7934997080824f, 0.2958508423571f);
    glVertex2f(-0.8097431189158f, 0.2989448253729f);

    glEnd();

    //back door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7678874563725f, 0.2510951983408f);
    glVertex2f(-0.7708790248524f, 0.2509192237244f);
    glVertex2f(-0.7707910375442f, 0.2473997313951f);
    glVertex2f(-0.7677114817561f, 0.2476636933198f);

    glEnd();

    //windows from left
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7151099662305f, 0.266868589599f);
    glVertex2f(-0.714460252525f, 0.2434788962022f);
    glVertex2f(-0.6962682687719f, 0.2434788962022f);
    glVertex2f(-0.6975676961829f, 0.266868589599f);

    glVertex2f(-0.6819745672516f, 0.26816801701f);
    glVertex2f(-0.6813248535462f, 0.2441286099077f);
    glVertex2f(-0.6637825834985f, 0.2444534667604f);
    glVertex2f(-0.6641074403513f, 0.2678431601572f);

    glVertex2f(-0.6501385956837f, 0.266868589599f);
    glVertex2f(-0.6491640251255f, 0.2447783236131f);
    glVertex2f(-0.6316217550779f, 0.2444534667604f);
    glVertex2f(-0.6329211824888f, 0.2671934464518f);

    glVertex2f(-0.6196020515268f, 0.2671934464518f);
    glVertex2f(-0.6183026241158f, 0.2451031804659f);
    glVertex2f(-0.6014100677737f, 0.2447783236131f);
    glVertex2f(-0.6030343520373f, 0.266868589599f);

    glVertex2f(-0.5858169388425f, 0.2662188758936f);
    glVertex2f(-0.585167225137f, 0.2457528941713f);
    glVertex2f(-0.5702238099112f, 0.2454280373186f);
    glVertex2f(-0.5711983804694f, 0.266868589599f);

    glVertex2f(-0.5533312535691f, 0.266868589599f);
    glVertex2f(-0.5520318261581f, 0.2454280373186f);
    glVertex2f(-0.5370884109324f, 0.2447783236131f);
    glVertex2f(-0.5393624089015f, 0.266868589599f);

    glVertex2f(-0.5227947094121f, 0.2665437327463f);
    glVertex2f(-0.5208455682957f, 0.2431540393495f);
    glVertex2f(-0.5039530119536f, 0.2434788962022f);
    glVertex2f(-0.5055772962172f, 0.266868589599f);

    glEnd();
    glPopMatrix();
}

void p2plane1()
{
    //Plane
    //plane body
    glPushMatrix();
    glTranslatef(p2Plane2,-0.8f, 0.0f);

    glScalef(-1,2,0);

    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.8375889660587f, 0.2912098678332f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.928861465027f, 0.2556290631507f);
    glVertex2f(-0.9041096009f, 0.2378386608094f);
    glVertex2f(-0.8731697707412f, 0.2277832160078f);
    glVertex2f(-0.8453239235984f, 0.2192747627141f);
    glVertex2f(-0.8143840934396f, 0.2107663094205f);
    glVertex2f(-0.7842177590348f, 0.2068988306506f);
    glVertex2f(-0.7439959798284f, 0.2076723264046f);
    glVertex2f(-0.3897349245107f, 0.2092193179125f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.4043823800643f, 0.2892785841354f);
    glVertex2f(-0.3831964687035f, 0.2802549552225f);
    glVertex2f(-0.3545562551972f, 0.2671118435449f);
    glVertex2f(-0.3380783241388f, 0.2622076973966f);
    glVertex2f(-0.3237582173856f, 0.2573035512482f);
    glVertex2f(-0.3176770761617f, 0.2518109075621f);
    glVertex2f(-0.3121844324755f, 0.2463182638759f);
    glVertex2f(-0.31f, 0.24f);
    glVertex2f(-0.3098304423243f, 0.2357253081955f);
    glVertex2f(-0.31f, 0.23f);
    glVertex2f(-0.313753759243f, 0.2259170158989f);
    glVertex2f(-0.3204233980047f, 0.2227783623639f);
    glVertex2f(-0.3280738659961f, 0.2190512112912f);
    glVertex2f(-0.3378821582928f, 0.2157163919103f);
    glVertex2f(-0.3500444407407f, 0.2127739042213f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head window
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3819451920869f, 0.2758911800548f);
    glVertex2f(-0.3881479557192f, 0.2728587178345f);
    glVertex2f(-0.3771897399688f, 0.2608667081453f);
    glVertex2f(-0.370504539165f, 0.2634167331942f);
    glVertex2f(-0.3660936850265f, 0.2658289190512f);
    glVertex2f(-0.360855795737f, 0.2696194968265f);
    glVertex2f(-0.3786950838177f, 0.2781892511995f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.398899412682f, 0.2686546224837f);
    glVertex2f(-0.4098576284324f, 0.2679654265246f);
    glVertex2f(-0.40854815611f, 0.262727537235f);
    glVertex2f(-0.4031035080328f, 0.2555598992599f);
    glVertex2f(-0.3925588098578f, 0.2561801756231f);
    glVertex2f(-0.3804978805727f, 0.2588680398638f);
    glVertex2f(-0.39f, 0.27f);
    glVertex2f(-0.39f, 0.27f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4127657925046f, 0.2602777634305f);
    glVertex2f(-0.4148377327393f, 0.2667761214393f);
    glVertex2f(-0.4317899710231f, 0.2668703005408f);
    glVertex2f(-0.432260866531f, 0.260371942532f);
    glVertex2f(-0.4296238516869f, 0.2515191069838f);
    glVertex2f(-0.4077743001211f, 0.2526492562027f);

    glEnd();

    //front door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4695704482148f, 0.2425964533209f);
    glVertex2f(-0.4727942748017f, 0.2424499157487f);
    glVertex2f(-0.4726477372296f, 0.2379072510126f);
    glVertex2f(-0.4692773730705f, 0.2380537885847f);

    glEnd();

    //upper wing
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.5498485455822f, 0.2873423890634f);
    glVertex2f(-0.6217836507013f, 0.3770678965238f);
    glVertex2f(-0.6565909596299f, 0.3778413922778f);
    glVertex2f(-0.6488595295804f, 0.2915606660423f);

    glEnd();

    //lower wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8512841908058f, 0.1241487992192f);
    glVertex2f(-0.8652666039946f, 0.1246309513981f);
    glVertex2f(-0.8522484951637f, 0.1101663860304f);
    glVertex2f(-0.8291051905754f, 0.1111306903883f);
    glVertex2f(-0.5055818995018f, 0.2087134359257f);
    glVertex2f(-0.7114611649165f, 0.2078143998322f);

    glEnd();

    //lower wing back
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.847900370437f, 0.2811701757442f);
    glVertex2f(-0.9292604039938f, 0.2448081495735f);
    glVertex2f(-0.9792581899784f, 0.2452626749007f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);

    glEnd();

    //upper wing back
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8228925467333f, 0.3035857998967f);
    glVertex2f(-0.8414564448285f, 0.3120942531904f);
    glVertex2f(-0.8561528641539f, 0.3283376640237f);
    glVertex2f(-0.9056565924079f, 0.3909908200952f);
    glVertex2f(-0.9427843885984f, 0.3894438285873f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.7617837686202f, 0.2913507696872f);
    glVertex2f(-0.7934997080824f, 0.2958508423571f);
    glVertex2f(-0.8097431189158f, 0.2989448253729f);

    glEnd();

    //back door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7678874563725f, 0.2510951983408f);
    glVertex2f(-0.7708790248524f, 0.2509192237244f);
    glVertex2f(-0.7707910375442f, 0.2473997313951f);
    glVertex2f(-0.7677114817561f, 0.2476636933198f);

    glEnd();

    //windows from left
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7151099662305f, 0.266868589599f);
    glVertex2f(-0.714460252525f, 0.2434788962022f);
    glVertex2f(-0.6962682687719f, 0.2434788962022f);
    glVertex2f(-0.6975676961829f, 0.266868589599f);

    glVertex2f(-0.6819745672516f, 0.26816801701f);
    glVertex2f(-0.6813248535462f, 0.2441286099077f);
    glVertex2f(-0.6637825834985f, 0.2444534667604f);
    glVertex2f(-0.6641074403513f, 0.2678431601572f);

    glVertex2f(-0.6501385956837f, 0.266868589599f);
    glVertex2f(-0.6491640251255f, 0.2447783236131f);
    glVertex2f(-0.6316217550779f, 0.2444534667604f);
    glVertex2f(-0.6329211824888f, 0.2671934464518f);

    glVertex2f(-0.6196020515268f, 0.2671934464518f);
    glVertex2f(-0.6183026241158f, 0.2451031804659f);
    glVertex2f(-0.6014100677737f, 0.2447783236131f);
    glVertex2f(-0.6030343520373f, 0.266868589599f);

    glVertex2f(-0.5858169388425f, 0.2662188758936f);
    glVertex2f(-0.585167225137f, 0.2457528941713f);
    glVertex2f(-0.5702238099112f, 0.2454280373186f);
    glVertex2f(-0.5711983804694f, 0.266868589599f);

    glVertex2f(-0.5533312535691f, 0.266868589599f);
    glVertex2f(-0.5520318261581f, 0.2454280373186f);
    glVertex2f(-0.5370884109324f, 0.2447783236131f);
    glVertex2f(-0.5393624089015f, 0.266868589599f);

    glVertex2f(-0.5227947094121f, 0.2665437327463f);
    glVertex2f(-0.5208455682957f, 0.2431540393495f);
    glVertex2f(-0.5039530119536f, 0.2434788962022f);
    glVertex2f(-0.5055772962172f, 0.266868589599f);

    glEnd();
    glPopMatrix();
}

void display2()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Set background color to gray and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


    //full sky
    glColor3f(0.03, 0.07, 0.29); // 0.03, 0.07, 0.29
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    //Moon 1
    int i;
    GLfloat x=0.5938604499014;
    GLfloat y=0.7113489360865;
    GLfloat radius =.2f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.95, 0.86, 0.47);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //Moon 2
    int j;
    GLfloat x1=0.7114065611706;
    GLfloat y1=0.7666647531543;
    GLfloat radiu =.2f;
    int triangleAmounts = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePii = 2.0f * PI;

    glColor3f(0.03, 0.07, 0.29);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(j = 0; j <= triangleAmount; j++)
    {
        glVertex2f( x1 + (radiu * cos(j *  twicePi / triangleAmounts)),
                    y1 + (radiu * sin(j * twicePi / triangleAmounts)) );
    }
    glEnd();

    //Stars
    stars();

    //clouds
    //rectangle
    glColor3f(0.24, 0.3, 0.67);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.3305796741814);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, -0.3305796741814);
    glEnd();

    //mid circle 1
    int mci;
    GLfloat mcx1=0.0;
    GLfloat mcy1=-0.4428131927424;
    GLfloat radiusMC1 =.23f;
    int triangleAmountMC1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiMC1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(mcx1, mcy1); // center of circle
    for(mci = 0; mci <= triangleAmountMC1; mci++)
    {
        glVertex2f( mcx1 + (radiusMC1 * cos(mci *  twicePi / triangleAmountMC1)),
                    mcy1 + (radiusMC1 * sin(mci * twicePi / triangleAmountMC1)) );
    }
    glEnd();

    //mid circle 2
    int mcj;
    GLfloat mcx2=0.0;
    GLfloat mcy2=-0.5381807704272;
    GLfloat radiusMC2 =.25f;
    int triangleAmountMC2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiMC2 = 2.0f * PI;

    glColor3f(0.24, 0.3, 0.67);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(mcx2, mcy2); // center of circle
    for(mcj = 0; mcj <= triangleAmountMC2; mcj++)
    {
        glVertex2f( mcx2 + (radiusMC2 * cos(mcj *  twicePi / triangleAmountMC2)),
                    mcy2 + (radiusMC2 * sin(mcj * twicePi / triangleAmountMC2)) );
    }
    glEnd();

    //Right Circle 1.1
    int rci;
    GLfloat rcx1=0.4121971732043;
    GLfloat rcy1=-0.2733624654376;
    GLfloat radiusRC1 =.26f;
    int triangleAmountRC1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiRC1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(rcx1, rcy1); // center of circle
    for(rci = 0; rci <= triangleAmountRC1; rci++)
    {
        glVertex2f( rcx1 + (radiusRC1 * cos(rci *  twicePi / triangleAmountRC1)),
                    rcy1 + (radiusRC1 * sin(rci * twicePi / triangleAmountRC1)) );
    }
    glEnd();

    //Right Circle 1.2
    int rcj;
    GLfloat rcx2=0.4131167454774;
    GLfloat rcy2=-0.34867599287228;
    GLfloat radiusRC2 =.26f;
    int triangleAmountRC2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiRC2 = 2.0f * PI;

    glColor3f(0.24, 0.3, 0.67);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(rcx2, rcy2); // center of circle
    for(rcj = 0; rcj <= triangleAmountRC2; rcj++)
    {
        glVertex2f( rcx2 + (radiusRC2 * cos(rcj *  twicePi / triangleAmountRC2)),
                    rcy2 + (radiusRC2 * sin(rcj * twicePi / triangleAmountRC2)) );
    }
    glEnd();

    //Right Circle 2.1
    int rrci;
    GLfloat rrcx1=0.6976418890543;
    GLfloat rrcy1=-0.1167679831145;
    GLfloat radiusRRC1 =.31f;
    int triangleAmountRRC1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiRRC1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(rrcx1, rrcy1); // center of circle
    for(rrci = 0; rrci <= triangleAmountRRC1; rrci++)
    {
        glVertex2f( rrcx1 + (radiusRRC1 * cos(rrci *  twicePi / triangleAmountRRC1)),
                    rrcy1 + (radiusRRC1 * sin(rrci * twicePi / triangleAmountRRC1)) );
    }
    glEnd();

    //Right Circle 2.2
    int rrcj;
    GLfloat rrcx2=0.7193089146659;
    GLfloat rrcy2=-0.1617994246617;
    GLfloat radiusRRC2 =.31f;
    int triangleAmountRRC2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiRRC2 = 2.0f * PI;

    glColor3f(0.24, 0.3, 0.67);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(rrcx2, rrcy2); // center of circle
    for(rrcj = 0; rrcj <= triangleAmountRRC2; rrcj++)
    {
        glVertex2f( rrcx2 + (radiusRRC2 * cos(rrcj *  twicePi / triangleAmountRRC2)),
                    rrcy2 + (radiusRRC2 * sin(rrcj * twicePi / triangleAmountRRC2)) );
    }
    glEnd();

    //Left Circle 1.1
    int lci;
    GLfloat lcx1=-0.4424070112929;
    GLfloat lcy1=-0.3874383103148;
    GLfloat radiusLC1 =.28f;
    int triangleAmountLC1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiLC1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(lcx1, lcy1); // center of circle
    for(lci = 0; lci <= triangleAmountLC1; lci++)
    {
        glVertex2f( lcx1 + (radiusLC1 * cos(lci *  twicePi / triangleAmountLC1)),
                    lcy1 + (radiusLC1 * sin(lci * twicePi / triangleAmountLC1)) );
    }
    glEnd();

    //Left Circle 1.2
    int lcj;
    GLfloat lcx2=-0.4385306152305;
    GLfloat lcy2=-0.4714346559457;
    GLfloat radiusLC2 =.28f;
    int triangleAmountLC2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiLC2 = 2.0f * PI;

    glColor3f(0.24, 0.3, 0.67);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(lcx2, lcy2); // center of circle
    for(lcj = 0; lcj <= triangleAmountLC2; lcj++)
    {
        glVertex2f( lcx2 + (radiusLC2 * cos(lcj *  twicePi / triangleAmountLC2)),
                    lcy2 + (radiusLC2 * sin(lcj * twicePi / triangleAmountLC2)) );
    }
    glEnd();

    //Left Circle 2.1
    int llci;
    GLfloat llcx1=-0.7185775296556;
    GLfloat llcy1=-0.2209237330668;
    GLfloat radiusLLC1 =.3f;
    int triangleAmountLLC1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiLLC1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(llcx1, llcy1); // center of circle
    for(llci = 0; llci <= triangleAmountLLC1; llci++)
    {
        glVertex2f( llcx1 + (radiusLLC1 * cos(llci *  twicePi / triangleAmountLLC1)),
                    llcy1 + (radiusLLC1 * sin(llci * twicePi / triangleAmountLLC1)) );
    }
    glEnd();

    //Left Circle 2.2
    int llcj;
    GLfloat llcx2=-0.7173290672394;
    GLfloat llcy2= -0.2626421451141;
    GLfloat radiusLLC2 =.28f;
    int triangleAmountLLC2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiLLC2 = 2.0f * PI;

    glColor3f(0.24, 0.3, 0.67);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(llcx2, llcy2); // center of circle
    for(llcj = 0; llcj <= triangleAmountLLC2; llcj++)
    {
        glVertex2f( llcx2 + (radiusLLC2 * cos(llcj *  twicePi / triangleAmountLLC2)),
                    llcy2 + (radiusLLC2 * sin(llcj * twicePi / triangleAmountLLC2)) );
    }
    glEnd();

    //Bottom Circle
    //Bottom Left 1.1
    int bli;
    GLfloat blx1=-0.943272015663;
    GLfloat bly1=-0.805615294947;
    GLfloat radiusBL1 =.3f;
    int triangleAmountBL1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiBL1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41); //0.17, 0.24, 0.64
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(blx1, bly1); // center of circle
    for(bli = 0; bli <= triangleAmountBL1; bli++)
    {
        glVertex2f( blx1 + (radiusBL1 * cos(bli *  twicePi / triangleAmountBL1)),
                    bly1 + (radiusBL1 * sin(bli * twicePi / triangleAmountBL1)) );
    }
    glEnd();

    //Bottom Left 1.2
    int blj;
    GLfloat blx2=-0.9490923786234;
    GLfloat bly2=-0.8638189245511;
    GLfloat radiusBL2 =.28f;
    int triangleAmountsBL2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiiBL2 = 2.0f * PI;

    glColor3f(0.11, 0.29, 0.52);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(blx2, bly2); // center of circle
    for(blj = 0; blj <= triangleAmountsBL2; blj++)
    {
        glVertex2f( blx2 + (radiusBL2 * cos(blj *  twicePi / triangleAmountsBL2)),
                    bly2 + (radiusBL2 * sin(blj * twicePi / triangleAmountsBL2)) );
    }
    glEnd();

    //Bottom Left 2.1
    int blli;
    GLfloat bllx1=-0.6131531316035;
    GLfloat blly1=-0.7990676041448;
    GLfloat radiusBLL1 =.21f;
    int triangleAmountBLL1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiBLL1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41); //0.17, 0.24, 0.64
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(bllx1, blly1); // center of circle
    for(blli = 0; blli <= triangleAmountBLL1; blli++)
    {
        glVertex2f( bllx1 + (radiusBLL1 * cos(blli *  twicePi / triangleAmountBLL1)),
                    blly1 + (radiusBLL1 * sin(blli * twicePi / triangleAmountBLL1)) );
    }
    glEnd();

    //Bottom Left 2.2
    int bllj;
    GLfloat bllx2=-0.6390416223305;
    GLfloat blly2=-0.8710429969411;
    GLfloat radiusBLL2 =.2f;
    int triangleAmountsBLL2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiiBLL2 = 2.0f * PI;

    glColor3f(0.11, 0.29, 0.52);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(bllx2, blly2); // center of circle
    for(bllj = 0; bllj <= triangleAmountsBLL2; bllj++)
    {
        glVertex2f( bllx2 + (radiusBLL2 * cos(bllj *  twicePi / triangleAmountsBLL2)),
                    blly2 + (radiusBLL2 * sin(bllj * twicePi / triangleAmountsBLL2)) );
    }
    glEnd();

    //Bottom Mid 1.1
    int bmi;
    GLfloat bmx1=-0.2270716137823;
    GLfloat bmy1=-0.9295079688632;
    GLfloat radiusBM1 =.24f;
    int triangleAmountBM1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiBM1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41); //0.17, 0.24, 0.64
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(bmx1, bmy1); // center of circle
    for(bmi = 0; bmi <= triangleAmountBM1; bmi++)
    {
        glVertex2f( bmx1 + (radiusBM1 * cos(bmi *  twicePi / triangleAmountBM1)),
                    bmy1 + (radiusBM1 * sin(bmi * twicePi / triangleAmountBM1)) );
    }
    glEnd();

    //Bottom Mid 1.2
    int bmj;
    GLfloat bmx2=-0.2527954642748;
    GLfloat bmy2=-0.9815864226619;
    GLfloat radiusBM2 =.24f;
    int triangleAmountsBM2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiiBM2 = 2.0f * PI;

    glColor3f(0.11, 0.29, 0.52);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(bmx2, bmy2); // center of circle
    for(bmj = 0; bmj <= triangleAmountsBM2; bmj++)
    {
        glVertex2f( bmx2 + (radiusBM2 * cos(bmj *  twicePi / triangleAmountsBM2)),
                    bmy2 + (radiusBM2 * sin(bmj * twicePi / triangleAmountsBM2)) );
    }
    glEnd();

    //Bottom Right 1.1
    int bri;
    GLfloat brx1=1.0092141810925;
    GLfloat bry1=-0.6657938863184;
    GLfloat radiusBR1 =.25f;
    int triangleAmountBR1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiBR1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41); //0.17, 0.24, 0.64
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(brx1, bry1); // center of circle
    for(bri = 0; bri <= triangleAmountBR1; bri++)
    {
        glVertex2f( brx1 + (radiusBR1 * cos(bri *  twicePi / triangleAmountBR1)),
                    bry1 + (radiusBR1 * sin(bri * twicePi / triangleAmountBR1)) );
    }
    glEnd();

    //Bottom Right 1.2
    int brj;
    GLfloat brx2=1.0261352646879;
    GLfloat bry2=-0.7921885969478;
    GLfloat radiusBR2 =.25f;
    int triangleAmountsBR2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiiBR2 = 2.0f * PI;

    glColor3f(0.11, 0.29, 0.52);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(brx2, bry2); // center of circle
    for(brj = 0; brj <= triangleAmountsBR2; brj++)
    {
        glVertex2f( brx2 + (radiusBR2 * cos(brj *  twicePi / triangleAmountsBR2)),
                    bry2 + (radiusBR2 * sin(brj * twicePi / triangleAmountsBR2)) );
    }
    glEnd();

    //Bottom Right 2.1
    int brri;
    GLfloat brrx1=0.6399954512404;
    GLfloat brry1=-0.9076958127733;
    GLfloat radiusBRR1 =.28f;
    int triangleAmountBRR1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiBRR1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41); //0.17, 0.24, 0.64
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(brrx1, brry1); // center of circle
    for(brri = 0; brri <= triangleAmountBRR1; brri++)
    {
        glVertex2f( brrx1 + (radiusBRR1 * cos(brri *  twicePi / triangleAmountBRR1)),
                    brry1 + (radiusBRR1 * sin(brri * twicePi / triangleAmountBRR1)) );
    }
    glEnd();

    //Bottom Right 2.2
    int brrj;
    GLfloat brrx2=0.6527271315801;
    GLfloat brry2=-0.9560761980643;
    GLfloat radiusBRR2 =.26f;
    int triangleAmountsBRR2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiiBRR2 = 2.0f * PI;

    glColor3f(0.11, 0.29, 0.52);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(brrx2, brry2); // center of circle
    for(brrj = 0; brrj <= triangleAmountsBRR2; brrj++)
    {
        glVertex2f( brrx2 + (radiusBRR2 * cos(brrj *  twicePi / triangleAmountsBRR2)),
                    brry2 + (radiusBRR2 * sin(brrj * twicePi / triangleAmountsBRR2)) );
    }
    glEnd();

    //Bottom Mid 2.1
    int bmmi;
    GLfloat bmmx1=0.2167614961836;
    GLfloat bmmy1=-0.93790670541;
    GLfloat radiusBMM1 =.24f;
    int triangleAmountBMM1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiBMM1 = 2.0f * PI;

    glColor3f(0.12, 0.1, 0.41); //0.17, 0.24, 0.64
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(bmmx1, bmmy1); // center of circle
    for(bmmi = 0; bmmi <= triangleAmountBMM1; bmmi++)
    {
        glVertex2f( bmmx1 + (radiusBMM1 * cos(bmmi *  twicePi / triangleAmountBMM1)),
                    bmmy1 + (radiusBMM1 * sin(bmmi * twicePi / triangleAmountBMM1)) );
    }
    glEnd();

    //Bottom Mid 2.2
    int bmmj;
    GLfloat bmmx2=0.2261214355948;
    GLfloat bmmy2=-0.9737864731527;
    GLfloat radiusBMM2 =.22f;
    int triangleAmountsBMM2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePiiBMM2 = 2.0f * PI;

    glColor3f(0.11, 0.29, 0.52);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(bmmx2, bmmy2); // center of circle
    for(bmmj = 0; bmmj <= triangleAmountsBMM2; bmmj++)
    {
        glVertex2f( bmmx2 + (radiusBMM2 * cos(bmmj *  twicePi / triangleAmountsBMM2)),
                    bmmy2 + (radiusBMM2 * sin(bmmj * twicePi / triangleAmountsBMM2)) );
    }
    glEnd();

    thunder();
    //Plane
    s2Clouds(-1.9,0.3);
    s2Clouds(-1.1,0.4);
    s2Clouds(-2.3,-0.35);
    s2Clouds(-3.0,-0.2);
    p2plane();
    p2plane1();
    //sound2();
    //  glutTimerFunc(500, p2update, 0);
    glFlush();  // Render now
}

//3rd scene
//Security Guard
void guard()
{
    glPushMatrix();

    //left hand
    glTranslatef(runway1,0.0f, 0.0f);
    glTranslatef(-0.45, -0.25, 0);
    glScalef(1.5, 1.5, 0);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_QUADS);
    glVertex2f(0.8118581612677, -0.0756386435841);
    glVertex2f(0.812, -0.084);
    glVertex2f(0.8027520682014, -0.0985304997389);
    glVertex2f(0.7978399333599, -0.0915002884061);
    glEnd();

    //stick
    glPushMatrix();
    glBegin(GL_POLYGON);
    glPushMatrix();
//    glRotatef(degree,0.0,0.0,1.0);//i=how many degree you want to rotate around an axis
    glColor3f(1, 0.61, 0);
    glVertex2f(0.804, -0.096);
    glVertex2f(0.7933333876338, -0.0948351322434);
    glVertex2f(0.796, -0.102);
    glVertex2f(0.7656966949229, -0.103144337336);
    glVertex2f(0.7654918112239, -0.0971002682156);
    glEnd();
    glPopMatrix();
   // degree -= 0.2f;

    /*glBegin(GL_POLYGON);
    glColor3f(1, 0.61, 0);
    glVertex2f(0.804, -0.096);
    glVertex2f(0.7738920428827, -0.0964856171186);
    glVertex2f(0.7744042521302, -0.102734569938);
    glVertex2f(0.7656966949229, -0.103144337336);
    glVertex2f(0.7654918112239, -0.0971002682156);
    glEnd();*/

    //left hand circle
    int i;

    GLfloat x=0.7978399333599;
    GLfloat y= -0.0969081432775;
    GLfloat radius =0.002f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    //Right Hand
    glBegin(GL_QUADS);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8362251551818, -0.0791617200516);
    glVertex2f(0.8375151533557, -0.0761064612185);
    glVertex2f(0.8459751143056, -0.0810051620434);
    glVertex2f(0.8436478435659, -0.0832711888162);
    //glVertex2f(0.8473837255428, -0.0947238106142);
    //glVertex2f(0.845, -0.095);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8459751143056, -0.0810051620434);
    glVertex2f(0.8436478435659, -0.0832711888162);
    glVertex2f(0.845, -0.095);
    glVertex2f(0.8473837255428, -0.0947238106142);
    glEnd();

    //Body
   // glPushMatrix();
    glBegin(GL_QUADS);
    //glScalef(0.3, 0, 0);
    glColor3f(0.28, 0.52, 0.65); //light blue
    glVertex2f(0.8118581612677, -0.0756386435841);
    glVertex2f(0.8117385908965, -0.1099553401166);
    glVertex2f(0.8380644720962, -0.1099228224276);
    glVertex2f(0.8380265710055, -0.0755940804963);
    glEnd();
   // glPopMatrix();

   //left shoe
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.8176906865971, -0.1346758609227);
    glVertex2f(0.8175897701719, -0.1363914401522);
    glVertex2f(0.8163445800508, -0.1375346516958);
    glVertex2f(0.820806099552, -0.1375218753116);
    glVertex2f(0.8209266193456, -0.1346294002655);
    glEnd();

    //right shoe
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.8308310868295, -0.1346843959931);
    glVertex2f(0.8307828957453, -0.1366025057886);
    glVertex2f(0.8290616769213, -0.1375969877758);
    glVertex2f(0.8337663417071, -0.1375587384686);
    glVertex2f(0.8336709145036, -0.1345927886488);
    glEnd();

   // leg
    glBegin(GL_POLYGON);
    glColor3f(0.14, 0.21, 0.26);
    glVertex2f(0.8136096854927, -0.1092036769419);
    glVertex2f(0.8169861587784, -0.1350433641005);
    glVertex2f(0.8217312285756, -0.135002077581);
    glVertex2f(0.8264919664211, -0.1120757558407);
    glVertex2f(0.83, -0.135);
    glVertex2f(0.8342675070304, -0.134949870833);
    glVertex2f(0.836789311689, -0.1092036769419);
    glEnd();

    //neck
        glBegin(GL_POLYGON);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8200366649169, -0.0757349548833);
    glVertex2f(0.8299160650001, -0.0757022054908);
    glVertex2f(0.8287759601759, -0.0686275255472);
    glVertex2f(0.82089785532, -0.0684772920997);
    glEnd();

   // glPopMatrix();

    //cap
   // glPushMatrix();
    int i1;

    GLfloat x1=0.8254555075085;
    GLfloat y1=-0.0554485732379;
    GLfloat radius1 =0.012f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0, 0, 0); //
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f( x1 + (radius1 * cos(i1 *  twicePi / triangleAmount1)),
                    y1 + (radius1 * sin(i1 * twicePi / triangleAmount1)));
    }

    glEnd();


    //face
   // glPushMatrix();
    int i2;

    GLfloat x2=0.8253346412721;
    GLfloat y2=-0.0600414902199;
    GLfloat radius2 =0.01f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f( x2 + (radius2 * cos(i2 *  twicePi / triangleAmount2)),
                    y2 + (radius2 * sin(i2 * twicePi / triangleAmount2)));
    }
    glEnd();


    glPopMatrix();
}

//Guard 2
//Security Guard 2
void guard2()
{
    glPushMatrix();

    //left hand
    glTranslatef(runway1,0.0f, 0.0f);
    glTranslatef(-1.8, -0.25, 0);
    glScalef(1.5, 1.5, 0);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_QUADS);
    glVertex2f(0.8118581612677, -0.0756386435841);
    glVertex2f(0.812, -0.084);
    glVertex2f(0.8035310340263, -0.0965333156863);
    glVertex2f(0.8013690962862, -0.0944750324954);
    glEnd();

    //stick
    glBegin(GL_POLYGON);
    glColor3f(1, 0.61, 0);
    glVertex2f(0.804, -0.096);
    glVertex2f(0.8003346781398, -0.0950148129442);
    glVertex2f(0.8013695145475, -0.0979576289789);
    glVertex2f(0.7719239381211, -0.1028450794268);
    glVertex2f(0.7713767928155, -0.0983897533672);
    glEnd();

    //left hand circle
    int i;

    GLfloat x=0.8044152659904;
    GLfloat y=-0.0947113880037;
    GLfloat radius =0.002f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //Right Hand
    glBegin(GL_QUADS);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8362251551818, -0.0791617200516);
    glVertex2f(0.8375151533557, -0.0761064612185);
    glVertex2f(0.8459751143056, -0.0810051620434);
    glVertex2f(0.8436478435659, -0.0832711888162);
    //glVertex2f(0.8473837255428, -0.0947238106142);
    //glVertex2f(0.845, -0.095);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8459751143056, -0.0810051620434);
    glVertex2f(0.8436478435659, -0.0832711888162);
    glVertex2f(0.845, -0.095);
    glVertex2f(0.8473837255428, -0.0947238106142);
    glEnd();

    //Body
   // glPushMatrix();
    glBegin(GL_QUADS);
    //glScalef(0.3, 0, 0);
    glColor3f(0.28, 0.52, 0.65); //light blue
    glVertex2f(0.8118581612677, -0.0756386435841);
    glVertex2f(0.8117385908965, -0.1099553401166);
    glVertex2f(0.8380644720962, -0.1099228224276);
    glVertex2f(0.8380265710055, -0.0755940804963);
    glEnd();
   // glPopMatrix();

   //left shoe
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.8176906865971, -0.1346758609227);
    glVertex2f(0.8175897701719, -0.1363914401522);
    glVertex2f(0.8163445800508, -0.1375346516958);
    glVertex2f(0.820806099552, -0.1375218753116);
    glVertex2f(0.8209266193456, -0.1346294002655);
    glEnd();

    //right shoe
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.8308310868295, -0.1346843959931);
    glVertex2f(0.8307828957453, -0.1366025057886);
    glVertex2f(0.8290616769213, -0.1375969877758);
    glVertex2f(0.8337663417071, -0.1375587384686);
    glVertex2f(0.8336709145036, -0.1345927886488);
    glEnd();

   // leg
    glBegin(GL_POLYGON);
    glColor3f(0.14, 0.21, 0.26);
    glVertex2f(0.8136096854927, -0.1092036769419);
    glVertex2f(0.8169861587784, -0.1350433641005);
    glVertex2f(0.8217312285756, -0.135002077581);
    glVertex2f(0.8264919664211, -0.1120757558407);
    glVertex2f(0.83, -0.135);
    glVertex2f(0.8342675070304, -0.134949870833);
    glVertex2f(0.836789311689, -0.1092036769419);
    glEnd();

    //neck
        glBegin(GL_POLYGON);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8200366649169, -0.0757349548833);
    glVertex2f(0.8299160650001, -0.0757022054908);
    glVertex2f(0.8287759601759, -0.0686275255472);
    glVertex2f(0.82089785532, -0.0684772920997);
    glEnd();

   // glPopMatrix();

    //cap
   // glPushMatrix();
    int i1;

    GLfloat x1=0.8254555075085;
    GLfloat y1=-0.0554485732379;
    GLfloat radius1 =0.012f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0, 0, 0); //
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f( x1 + (radius1 * cos(i1 *  twicePi / triangleAmount1)),
                    y1 + (radius1 * sin(i1 * twicePi / triangleAmount1)));
    }

    glEnd();


    //face
   // glPushMatrix();
    int i2;

    GLfloat x2=0.8253346412721;
    GLfloat y2=-0.0600414902199;
    GLfloat radius2 =0.01f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f( x2 + (radius2 * cos(i2 *  twicePi / triangleAmount2)),
                    y2 + (radius2 * sin(i2 * twicePi / triangleAmount2)));
    }
    glEnd();


    glPopMatrix();
}

//Guard 3
void guard3()
{
    glPushMatrix();

    //left hand
    glTranslatef(runway1,0.0f, 0.0f);
    glTranslatef(1.2, -0.25, 0);
    glScalef(1.5, 1.5, 0);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_QUADS);
    glVertex2f(0.8118581612677, -0.0756386435841);
    glVertex2f(0.812, -0.084);
    glVertex2f(0.8035310340263, -0.0965333156863);
    glVertex2f(0.8013690962862, -0.0944750324954);
    glEnd();

    //stick
    glBegin(GL_POLYGON);
    glColor3f(1, 0.61, 0);
    glVertex2f(0.804, -0.096);
    glVertex2f(0.8003346781398, -0.0950148129442);
    glVertex2f(0.8013695145475, -0.0979576289789);
    glVertex2f(0.7719239381211, -0.1028450794268);
    glVertex2f(0.7713767928155, -0.0983897533672);
    glEnd();

    //left hand circle
    int i;

    GLfloat x=0.8044152659904;
    GLfloat y=-0.0947113880037;
    GLfloat radius =0.002f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //Right Hand
    glBegin(GL_QUADS);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8362251551818, -0.0791617200516);
    glVertex2f(0.8375151533557, -0.0761064612185);
    glVertex2f(0.8459751143056, -0.0810051620434);
    glVertex2f(0.8436478435659, -0.0832711888162);
    //glVertex2f(0.8473837255428, -0.0947238106142);
    //glVertex2f(0.845, -0.095);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8459751143056, -0.0810051620434);
    glVertex2f(0.8436478435659, -0.0832711888162);
    glVertex2f(0.845, -0.095);
    glVertex2f(0.8473837255428, -0.0947238106142);
    glEnd();

    //Body
   // glPushMatrix();
    glBegin(GL_QUADS);
    //glScalef(0.3, 0, 0);
    glColor3f(0.28, 0.52, 0.65); //light blue
    glVertex2f(0.8118581612677, -0.0756386435841);
    glVertex2f(0.8117385908965, -0.1099553401166);
    glVertex2f(0.8380644720962, -0.1099228224276);
    glVertex2f(0.8380265710055, -0.0755940804963);
    glEnd();
   // glPopMatrix();

   //left shoe
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.8176906865971, -0.1346758609227);
    glVertex2f(0.8175897701719, -0.1363914401522);
    glVertex2f(0.8163445800508, -0.1375346516958);
    glVertex2f(0.820806099552, -0.1375218753116);
    glVertex2f(0.8209266193456, -0.1346294002655);
    glEnd();

    //right shoe
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(0.8308310868295, -0.1346843959931);
    glVertex2f(0.8307828957453, -0.1366025057886);
    glVertex2f(0.8290616769213, -0.1375969877758);
    glVertex2f(0.8337663417071, -0.1375587384686);
    glVertex2f(0.8336709145036, -0.1345927886488);
    glEnd();

   // leg
    glBegin(GL_POLYGON);
    glColor3f(0.14, 0.21, 0.26);
    glVertex2f(0.8136096854927, -0.1092036769419);
    glVertex2f(0.8169861587784, -0.1350433641005);
    glVertex2f(0.8217312285756, -0.135002077581);
    glVertex2f(0.8264919664211, -0.1120757558407);
    glVertex2f(0.83, -0.135);
    glVertex2f(0.8342675070304, -0.134949870833);
    glVertex2f(0.836789311689, -0.1092036769419);
    glEnd();

    //neck
        glBegin(GL_POLYGON);
    glColor3f(0.88, 0.85, 0.51); //skin color
    glVertex2f(0.8200366649169, -0.0757349548833);
    glVertex2f(0.8299160650001, -0.0757022054908);
    glVertex2f(0.8287759601759, -0.0686275255472);
    glVertex2f(0.82089785532, -0.0684772920997);
    glEnd();

   // glPopMatrix();

    //cap
   // glPushMatrix();
    int i1;

    GLfloat x1=0.8254555075085;
    GLfloat y1=-0.0554485732379;
    GLfloat radius1 =0.012f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0, 0, 0); //
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f( x1 + (radius1 * cos(i1 *  twicePi / triangleAmount1)),
                    y1 + (radius1 * sin(i1 * twicePi / triangleAmount1)));
    }

    glEnd();


    //face
   // glPushMatrix();
    int i2;

    GLfloat x2=0.8253346412721;
    GLfloat y2=-0.0600414902199;
    GLfloat radius2 =0.01f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.88, 0.85, 0.51); //skin color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f( x2 + (radius2 * cos(i2 *  twicePi / triangleAmount2)),
                    y2 + (radius2 * sin(i2 * twicePi / triangleAmount2)));
    }
    glEnd();


    glPopMatrix();
}


void clouds(float p, float p1)
{

    glPushMatrix();
    glTranslatef(p3Cloud,0.0f, 0.0f);

    glTranslatef(p,p1, 0.0f);

    //cloud
    int i;

    GLfloat x=2.0664666559629f;
    GLfloat y=0.384679318014f;
    GLfloat radius =0.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x1=2.1249747089483f;
    GLfloat y1=0.3731062965444f;
    GLfloat radius1 =0.04f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x2=2.0086015486148f;
    GLfloat y2=0.362176220712f;
    GLfloat radius2 =0.045f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=1.9610235714619f;
    GLfloat y3=0.3512461448795f;
    GLfloat radius3 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=2.1641943928175f;
    GLfloat y4=0.3692486227212f;
    GLfloat radius4 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

}


void buildings()
{

    glPushMatrix();
    glTranslatef(p3Cloud,0.0f, 0.0f);

    //outside building 1
    glBegin(GL_POLYGON);
    glColor3f(0.32f, 0.14f, 0.05f);
    glVertex2f(2.5052392914906, -0.0873145496797);
    glVertex2f(3.0064008476205, -0.0873145496797);
    glVertex2f(3.0064008476205, -0.3241466478862);
    glVertex2f(2.5025782566793, -0.32503365949);

    glEnd();

    //outside building 2
    glBegin(GL_POLYGON);
    glColor3f(0.68f, 0.36f, 0.2f);
    glVertex2f(2.4839856407212, 0.3302674900268);
    glVertex2f(2.4834222584246, 0.4142114522174);
    glVertex2f(2.3938444732682, 0.4130846876242);
    glVertex2f(2.3966613847511, 0.3297041077302);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.69f, 0.43f, 0.29f);
    glVertex2f(2.5161856718456, 0.3387663872012);
    glVertex2f(2.1077198411145, 0.3367505969413);
    glVertex2f(2.1077198411145, -0.3451745894677);
    glVertex2f(2.5197424188891, -0.3334588040066);

    glEnd();

    //windows
    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.0f);

    //windows down
    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.4f, 0.0f);

    //windows down 2
    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);

    //door
    glBegin(GL_POLYGON);
    glColor3f(0.43, 0.23, 0);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.0276823093388);
    glVertex2f(2.2424845752272, 0.0276823093388);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.69, 0.37);
    glVertex2f(2.2424845752272, 0.2340375301809);
    glVertex2f(2.1762838765397, 0.2334949015031);
    glVertex2f(2.177911762573, 0.1276823093388);
    glVertex2f(2.2424845752272, 0.1276823093388);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(2.2418962550008, 0.1911995993124);
    glVertex2f(2.1772666483105, 0.1904252528981);
    glVertex2f(2.1773467197489, 0.1809031685945);
    glVertex2f(2.2421540950084, 0.1817239790332);

    glEnd();

    glPopMatrix();

    glPopMatrix();

    //outside building 3
    glBegin(GL_POLYGON);
    glColor3f(0.27, 0.42, 0.36);
    glVertex2f(2.1164372365763, 0.0836921310177);
    glVertex2f(1.6830307269187, 0.085464754779);
    glVertex2f(1.6723949843504, -0.3142619034124);
    glVertex2f(2.1164372365763, -0.3178071509351);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.41, 0.63, 0.51);
    glVertex2f(2.1091483555903, 0.0518647690943);
    glVertex2f(1.6718629906373, 0.0559276825799);
    glVertex2f(1.6723418186648, -0.0016060226348);
    glVertex2f(2.1091483555903, 0.0000711422815);

    glEnd();

    glPushMatrix();
    glTranslatef(0.035f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(2.0439384580487, -0.0220003025443);
    glVertex2f(1.7126865194035, -0.0218966596596);
    glVertex2f(1.7126865194035, -0.1747677554869);
    glVertex2f(2.0439384580487, -0.1729629698979);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.69, 0.63);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.69, 0.63);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.16f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.69, 0.63);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.24f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.69, 0.63);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.71, 0.82, 0.76);
    glVertex2f(2.0421066212766, -0.1845469483218);
    glVertex2f(1.7159203616344, -0.1845469483218);
    glVertex2f(1.7159203616344, -0.3243908979676);
    glVertex2f(2.0421066212766, -0.3077202938813);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.04f, -0.17f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.17, 0.24, 0.2);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.17, 0.24, 0.2);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.16f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.17, 0.24, 0.2);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.24f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.17, 0.24, 0.2);
    glVertex2f(1.78, -0.04);
    glVertex2f(1.7380598566245, -0.0400540756942);
    glVertex2f(1.738829229869, -0.1393032242356);
    glVertex2f(1.78, -0.1393032242356);
    glEnd();

    glPopMatrix();

    glPopMatrix();

    //outside building 4 upper
    glBegin(GL_POLYGON);
    glColor3f(0.44f, 0.65f, 0.72f);
    glVertex2f(1.586454465712, 0.2214850289479);
    glVertex2f(1.3580673518243, 0.2214850289479);
    glVertex2f(1.3611398242084, 0.1170209678872);
    glVertex2f(1.5874786231734, 0.113948495503);

    glEnd();

    //window left
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.4648153291931, 0.1849529650144);
    glVertex2f(1.4229109846961, 0.1851794749847);
    glVertex2f(1.4242700445176, 0.1407835208149);
    glVertex2f(1.4654948591039, 0.1410100307851);

    glEnd();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.0f);
    //window left
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.4648153291931, 0.1849529650144);
    glVertex2f(1.4229109846961, 0.1851794749847);
    glVertex2f(1.4242700445176, 0.1407835208149);
    glVertex2f(1.4654948591039, 0.1410100307851);

    glEnd();
    glPopMatrix();


    //lower
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.67f, 0.38f);
    glVertex2f(1.6950151566183, 0.1293108574237);
    glVertex2f(1.2341442989973, 0.1303350148851);
    glVertex2f(1.2249268818449, -0.3336083151201);
    glVertex2f(1.6950151566183, -0.3243908979676);

    glEnd();

    //window left
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.4367467413409, 0.0721655944815);
    glVertex2f(1.3235934117274, 0.0721655944815);
    glVertex2f(1.3221730770461, -0.036726731088);
    glVertex2f(1.438640520916, -0.0372001759818);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.055f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.18f, 0.0f, 0.0f);
    //window right
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.4367467413409, 0.0721655944815);
    glVertex2f(1.3235934117274, 0.0721655944815);
    glVertex2f(1.3221730770461, -0.036726731088);
    glVertex2f(1.438640520916, -0.0372001759818);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.055f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    //lower window set
    glPushMatrix();
    glTranslatef(0.0f, -0.15f, 0.0f);

    //window left
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.4367467413409, 0.0721655944815);
    glVertex2f(1.3235934117274, 0.0721655944815);
    glVertex2f(1.3221730770461, -0.036726731088);
    glVertex2f(1.438640520916, -0.0372001759818);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.055f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.18f, 0.0f, 0.0f);
    //window right
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.4367467413409, 0.0721655944815);
    glVertex2f(1.3235934117274, 0.0721655944815);
    glVertex2f(1.3221730770461, -0.036726731088);
    glVertex2f(1.438640520916, -0.0372001759818);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.055f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();

    glPushMatrix();
    glTranslatef(0.055f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.34f, 0.56f, 0.7f);
    glVertex2f(1.3740669086207, 0.0651204654481);
    glVertex2f(1.3314789606784, 0.0651204654481);
    glVertex2f(1.3310462884412, 0.023899620414);
    glVertex2f(1.374776707753, 0.0232423166383);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    //door
    glBegin(GL_POLYGON);
    glColor3f(0.47, 0.46, 0.48);
    glVertex2f(1.5836547658145, -0.2032075233223);
    glVertex2f(1.3588049950672, -0.2032075233223);
    glVertex2f(1.3605412867332, -0.3507923149325);
    glVertex2f(1.5888636408125, -0.3481878774335);

    glEnd();

    //outside building 5
    glBegin(GL_POLYGON);
    glColor3f(0.49, 0.39, 0.64);
    glVertex2f(1.2454357137285, 0.2484939878635);
    glVertex2f(1.2597513275161, 0.2784266348739);
    glVertex2f(1.2571484886456, 0.3213734762368);
    glVertex2f(0.9819800094641, 0.3193025876967);
    glVertex2f(0.9799461489401, -0.3215277247703);
    glVertex2f(1.2506413914694, -0.3202263053351);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.64, 0.51, 0.76);
    glVertex2f(1.2454357137285, 0.2484939878635);
    glVertex2f(1.2554955734245, 0.2695282399551);
    glVertex2f(0.9864532461163, 0.2693166988273);
    glVertex2f(0.9865353972053, 0.2462361437231);

    glEnd();

    //window upper
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1389882460371, 0.0873535679951);
    glVertex2f(1.1381607145674, 0.2127245856557);
    glVertex2f(1.0621939281718, 0.2111541364441);
    glVertex2f(1.0636828822939, 0.0873535679951);
    glVertex2f(1.0545800361271, 0.0865260365254);
    glVertex2f(1.0554075675968, 0.0650102183131);
    glVertex2f(1.1489186236736, 0.0654239840479);
    glVertex2f(1.1476773264691, 0.08776733373);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.59, 0.76);
    glVertex2f(1.1302991656052, 0.2015529108147);
    glVertex2f(1.0711306655212, 0.2015529108147);
    glVertex2f(1.0733697449682, 0.0877605621442);
    glVertex2f(1.1311266970749, 0.0885948651997);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1027278458891, 0.2059880507902);
    glVertex2f(1.097899618681, 0.2062562856351);
    glVertex2f(1.0997772625953, 0.084477666054);
    glVertex2f(1.1059466640278, 0.084477666054);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1343795575864, 0.141611688016);
    glVertex2f(1.0689302554327, 0.141611688016);
    glVertex2f(1.0681826603238, 0.1373026182134);
    glVertex2f(1.1346477924313, 0.136783460808);

    glEnd();

    glPushMatrix();
    glTranslatef(0.0f, -0.18f, 0.0f);
    //window down
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1389882460371, 0.0873535679951);
    glVertex2f(1.1381607145674, 0.2127245856557);
    glVertex2f(1.0621939281718, 0.2111541364441);
    glVertex2f(1.0636828822939, 0.0873535679951);
    glVertex2f(1.0545800361271, 0.0865260365254);
    glVertex2f(1.0554075675968, 0.0650102183131);
    glVertex2f(1.1489186236736, 0.0654239840479);
    glVertex2f(1.1476773264691, 0.08776733373);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.59, 0.76);
    glVertex2f(1.1302991656052, 0.2015529108147);
    glVertex2f(1.0711306655212, 0.2015529108147);
    glVertex2f(1.0733697449682, 0.0877605621442);
    glVertex2f(1.1311266970749, 0.0885948651997);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1027278458891, 0.2059880507902);
    glVertex2f(1.097899618681, 0.2062562856351);
    glVertex2f(1.0997772625953, 0.084477666054);
    glVertex2f(1.1059466640278, 0.084477666054);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1343795575864, 0.141611688016);
    glVertex2f(1.0689302554327, 0.141611688016);
    glVertex2f(1.0681826603238, 0.1373026182134);
    glVertex2f(1.1346477924313, 0.136783460808);

    glEnd();
    glPopMatrix();


    //door
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(1.1492149316986, -0.1375369036204);
    glVertex2f(1.0522232313853, -0.1374843759905);
    glVertex2f(1.0555625714527, -0.3139923509808);
    glVertex2f(1.1519284988326, -0.3121097225721);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.4, 0.55);
    glVertex2f(1.136660830232, -0.1665843394349);
    glVertex2f(1.0679658345601, -0.167538436597);
    glVertex2f(1.0693483085018, -0.3242565715984);
    glVertex2f(1.1382449043843, -0.3236386649088);

    glEnd();


    // 1st building
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.78f, 0.2f);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.1003671436968f, -0.2916575248458f);
    glVertex2f(-0.78f, -0.29f);

    glEnd();

    // 1st building building block 1
    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.18f, 0.18f);
    glVertex2f(-0.78f, 0.1502218989579f);
    glVertex2f(-0.1f, 0.15f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.78f, 0.099958670257f);

    glEnd();

    // 1st building building block 2
    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.18f, 0.18f);
    glVertex2f(-0.78f, 0.0497783022499f);
    glVertex2f(-0.1001120119616f, 0.0500000836446f);
    glVertex2f(-0.1001493492822f, 0.0f);
    glVertex2f(-0.78f, 0.0f);

    glEnd();

    // 1st building building block 3
    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.18f, 0.18f);
    glVertex2f(-0.78f, -0.0495230296536f);
    glVertex2f(-0.1f, -0.05f);
    glVertex2f(-0.1002240239233f, -0.0999998327108f);
    glVertex2f(-0.78f, -0.1001619491857f);

    glEnd();

    // 1st building building block 4
    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.18f, 0.18f);
    glVertex2f(-0.78f, -0.1502994932769f);
    glVertex2f(-0.1002613612438f, -0.1499998048293f);
    glVertex2f(-0.1002986987309f, -0.2f);
    glVertex2f(-0.78f, -0.1999356619272f);

    glEnd();



    // 1st building line strip 1
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.765f, 0.2f);
    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.7650000892196f, -0.2900365825822f);
    glVertex2f(-0.7600001189594f, -0.2900487767762f);

    glEnd();

    // 1st building line strip 2
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.705f, 0.2f);
    glVertex2f(-0.7f, 0.2f);
    glVertex2f(-0.7050392374281f, -0.2901828183044f);
    glVertex2f(-0.6999914142481f, -0.2901951292047f);

    glEnd();


    // 1st building line strip 3
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.645f, -0.29f);
    glVertex2f(-0.64f, -0.29f);

    glEnd();


    // 1st building line strip 4
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.585f, 0.2f);
    glVertex2f(-0.58f, 0.2f);
    glVertex2f(-0.585f, -0.29f);
    glVertex2f(-0.58f, -0.29f);

    glEnd();


    // 1st building line strip 5
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.525f, 0.2f);
    glVertex2f(-0.52f, 0.2f);
    glVertex2f(-0.525f, -0.29f);
    glVertex2f(-0.52f, -0.29f);

    glEnd();


    // 1st building line strip 6
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.465f, 0.2f);
    glVertex2f(-0.46f, 0.2f);
    glVertex2f(-0.465f, -0.29f);
    glVertex2f(-0.46f, -0.29f);

    glEnd();


    // 1st building line strip 7
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.405f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.405f, -0.29f);
    glVertex2f(-0.4f, -0.29f);

    glEnd();


    // 1st building line strip 8
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.345f, 0.2f);
    glVertex2f(-0.34f, 0.2f);
    glVertex2f(-0.345f, -0.29f);
    glVertex2f(-0.34f, -0.29f);

    glEnd();


    // 1st building line strip 9
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.285f, 0.2f);
    glVertex2f(-0.28f, 0.2f);
    glVertex2f(-0.285f, -0.29f);
    glVertex2f(-0.28f, -0.29f);

    glEnd();


    // 1st building line strip 10
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.225f, 0.2f);
    glVertex2f(-0.22f, 0.2f);
    glVertex2f(-0.225f, -0.29f);
    glVertex2f(-0.22f, -0.29f);

    glEnd();


    // 1st building line strip 11
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.61f, 0.61f);
    glVertex2f(-0.165f, 0.2f);
    glVertex2f(-0.16f, 0.2f);
    glVertex2f(-0.165f, -0.29f);
    glVertex2f(-0.16f, -0.29f);

    glEnd();


    //2nd building
    glBegin(GL_QUADS);
    glColor3f(0.11f, 0.25f, 0.25f);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(-0.1002986987309f, -0.2f);

    glEnd();

    //2nd building middle part
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.41f, 0.41f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.1f,0.5f);
    glVertex2f(0.1f, -0.2f);
    glVertex2f(0.0f, -0.2f);

    glEnd();

    //2nd building top part
    glBegin(GL_QUADS);
    glColor3f(0.52f, 0.53f, 0.53f);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.2f, 0.4606340559496f);
    glVertex2f(-0.1f, 0.4627838753471f);

    glEnd();


    //2nd building bottom part
    glBegin(GL_QUADS);
    glColor3f(0.52f, 0.53f, 0.53f);
    glVertex2f(-0.1002240239233f, -0.0999998327108f);
    glVertex2f(0.2f,-0.1f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(-0.1002986987309f, -0.2f);

    glEnd();


    //2nd building top antina
    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.27f, 0.27f);
    glVertex2f(-0.09f, 0.64f);
    glVertex2f(-0.08f, 0.64f);
    glVertex2f(-0.08f, 0.5f);
    glVertex2f(-0.09f, 0.5f);

    glEnd();


    //3rd building
    glBegin(GL_QUADS);
    glColor3f(0.33f, 0.49f, 0.53f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.6f, -0.2f);
    glVertex2f(0.2f, -0.2f);

    glEnd();

    //4th building
    glBegin(GL_QUADS);
    glColor3f(0.33f, 0.49f, 0.53f);
    glVertex2f(0.64f, 0.0f);
    glVertex2f(0.98f, 0.0f);
    glVertex2f(0.98f, -0.2f);
    glVertex2f(0.64f, -0.2f);

    glEnd();

    //5th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.72f);
    glVertex2f(0.24f, 0.18f);
    glVertex2f(0.32f, 0.18f);
    glVertex2f(0.32f, 0.1f);
    glVertex2f(0.24f, 0.1f);

    glEnd();

    //6th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.72f);
    glVertex2f(0.34f, 0.24f);
    glVertex2f(0.42f, 0.24f);
    glVertex2f(0.42f, 0.1f);
    glVertex2f(0.34f, 0.1f);

    glEnd();

    //7th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.72f);
    glVertex2f(0.44f, 0.2f);
    glVertex2f(0.52f, 0.2f);
    glVertex2f(0.52f, 0.1f);
    glVertex2f(0.44f, 0.1f);

    glEnd();

    //8th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.72f);
    glVertex2f(0.54f, 0.28f);
    glVertex2f(0.58f, 0.28f);
    glVertex2f(0.58f, 0.1f);
    glVertex2f(0.54f, 0.1f);

    glEnd();

    //9th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.72f);
    glVertex2f(0.7f, 0.05f);
    glVertex2f(0.8f, 0.2f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.7f, 0.0f);

    glEnd();

    //10th building
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.65f, 0.72f);
    glVertex2f(0.85f, 0.3f);
    glVertex2f(0.95f, 0.2f);
    glVertex2f(0.95f, 0.0f);
    glVertex2f(0.85f, 0.0f);

    glEnd();




//airport circle 1

    int e;

    GLfloat x5=-1.1326898425755f;
    GLfloat y5= -0.2935784992873f;
    GLfloat radius5 =0.461f;
    int triangleAmount5 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi5 = 2.0f * PI;

    glColor3f(0.02f, 0.1f, 0.42f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(e = 0; e <= triangleAmount5; e++)
    {
        glVertex2f( x5 + (radius5 * cos(e *  twicePi5 / triangleAmount5)),
                    y5 + (radius5 * sin(e * twicePi5 / triangleAmount5)) );
    }
    glEnd();

//airport circle 2

    int d;

    GLfloat x6=-1.1536890443764;
    GLfloat y6=-0.3119528008631f;
    GLfloat radius6 =0.4621f;
    int triangleAmount6 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi6 = 2.0f * PI;

    glColor3f(0.07f, 0.48f, 0.66f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(d = 0; d <= triangleAmount6; d++)
    {
        glVertex2f( x6 + (radius6 * cos(d *  twicePi6 / triangleAmount6)),
                    y6 + (radius6 * sin(d * twicePi6 / triangleAmount6)) );
    }
    glEnd();


    // Airport window bar v1
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-0.9606162289803f, 0.1078561833019f);
    glVertex2f(-0.95f, 0.1f);
    glVertex2f(-0.95f, -0.3f);
    glVertex2f(-0.9599746940333f, -0.3f);

    glEnd();

    // Airport window bar v2
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-0.9097650027526f, 0.0804981605939f);
    glVertex2f(-0.9002293018899f, 0.0744082403526f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.91f, -0.3f);

    glEnd();

    // Airport window bar v3
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-0.8601043860089f, 0.0448731281301f);
    glVertex2f(-0.8500743783898f, 0.0363786933037f);
    glVertex2f(-0.85f, -0.3f);
    glVertex2f(-0.86f, -0.3f);

    glEnd();

    // Airport window bar v4
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-0.8100323302338f, -0.0030567697211f);
    glVertex2f(-0.7999410061433f, -0.01466670856f);
    glVertex2f(-0.8f, -0.29f);
    glVertex2f(-0.81f, -0.29f);

    glEnd();

    // Airport window bar h1
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-1.0f, -0.0402407102493f);
    glVertex2f(-0.78f,-0.0401565658935f);
    glVertex2f(-0.7731411859559f, -0.0498459091525f);
    glVertex2f(-1.0f, -0.05f);

    glEnd();

    // Airport window bar h2
    glBegin(GL_POLYGON);
    glColor3f(0.24f, 0.24f, 0.24f);
    glVertex2f(-1.0f, -0.140510115229f);
    glVertex2f(-0.7247969177398f, -0.1399986240026f);
    glVertex2f(-0.72088190096966f, -0.1502734011025f);//
    glVertex2f(-1.0f, -0.15f);

    glEnd();


    // ramp
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.2f, -0.3f);

    glEnd();

    // ramp block
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(-0.2, -0.2);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-0.2f, -0.3f);

    glEnd();


    //ramp piller 1 top
    glBegin(GL_POLYGON);
    glColor3f(0.68f, 0.68f, 0.68f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.46f, -0.2f);
    glVertex2f(0.46f, -0.22f);
    glVertex2f(0.4f, -0.22f);

    glEnd();

    //ramp piller 1 stand
    glBegin(GL_POLYGON);
    glColor3f(0.53f, 0.53f, 0.53f);
    glVertex2f(0.42f, -0.22f);
    glVertex2f(0.44f, -0.22f);
    glVertex2f(0.44f, -0.3f);
    glVertex2f(0.42f, -0.3f);

    glEnd();

    //ramp piller 2 top
    glBegin(GL_POLYGON);
    glColor3f(0.68f, 0.68f, 0.68f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.76f, -0.2f);
    glVertex2f(0.76f, -0.22f);
    glVertex2f(0.7f, -0.22f);

    glEnd();

    //ramp piller 2 stand
    glBegin(GL_POLYGON);
    glColor3f(0.53f, 0.53f, 0.53f);
    glVertex2f(0.72f, -0.22f);
    glVertex2f(0.74f, -0.22f);
    glVertex2f(0.74f, -0.3f);
    glVertex2f(0.72f, -0.3f);

    glEnd();


    glPopMatrix();

}

void runway()
{
    glPushMatrix();
    glTranslatef(runway1,0.0f, 0.0f);

    // road lines 1
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.78f, -0.5f);
    glVertex2f(-0.9f, -1.0f);
    glVertex2f(-0.92f, -1.0f);

    glEnd();

    // road lines 2
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(-0.52f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.56f, -1.0f);
    glVertex2f(-0.58f, -1.0f);

    glEnd();

    // road lines 3
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(-0.22f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(-0.22f, -1.0f);

    glEnd();

    // road lines 4
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.12f, -0.5f);
    glVertex2f(0.12f, -1.0f);
    glVertex2f(0.1f, -1.0f);

    glEnd();

    // road lines 5
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(0.38f, -0.5f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.46f, -1.0f);
    glVertex2f(0.44f, -1.0f);

    glEnd();

    // road lines 6
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(0.68f, -0.5f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.82f, -1.0f);
    glVertex2f(0.8f, -1.0f);

    glEnd();


    // road light 1
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.7, -0.68);
    glVertex2f(-0.66, -0.68);
    glVertex2f(-0.66, -0.7);
    glVertex2f(-0.7, -0.7);

    glEnd();

    // road light 2
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.72, -0.82);
    glVertex2f(-0.68, -0.82);
    glVertex2f(-0.68, -0.84);
    glVertex2f(-0.72, -0.84);

    glEnd();

    // road light 3
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.42, -0.68);
    glVertex2f(-0.38, -0.68);
    glVertex2f(-0.38, -0.7);
    glVertex2f(-0.42, -0.7);

    glEnd();

    // road light 4
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.43, -0.82);
    glVertex2f(-0.39, -0.82);
    glVertex2f(-0.39, -0.84);
    glVertex2f(-0.43, -0.84);

    glEnd();

    // road light 5
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.08, -0.68);
    glVertex2f(-0.04, -0.68);
    glVertex2f(-0.04, -0.7);
    glVertex2f(-0.08, -0.7);

    glEnd();

    // road light 6
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.08, -0.82);
    glVertex2f(-0.04, -0.82);
    glVertex2f(-0.04, -0.84);
    glVertex2f(-0.08, -0.84);

    glEnd();

    // road light 7
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.26, -0.68);
    glVertex2f(0.3, -0.68);
    glVertex2f(0.3, -0.7);
    glVertex2f(0.26, -0.7);

    glEnd();

    // road light 8
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.275, -0.8);
    glVertex2f(0.315, -0.8);
    glVertex2f(0.315, -0.82);
    glVertex2f(0.275, -0.82);

    glEnd();

    // road light 9
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.54, -0.68);
    glVertex2f(0.58, -0.68);
    glVertex2f(0.58, -0.7);
    glVertex2f(0.54, -0.7);

    glEnd();

    // road light 10
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.58, -0.8);
    glVertex2f(0.62, -0.8);
    glVertex2f(0.62, -0.82);
    glVertex2f(0.58, -0.82);

    glEnd();

    // road light 11
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.86, -0.68);
    glVertex2f(0.9, -0.68);
    glVertex2f(0.9, -0.7);
    glVertex2f(0.86, -0.7);

    glEnd();

    // road light 12
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.88, -0.8);
    glVertex2f(0.92, -0.8);
    glVertex2f(0.92, -0.82);
    glVertex2f(0.88, -0.82);

    glEnd();

    glPopMatrix();
}

void runway2()
{
    glPushMatrix();
    glTranslatef(runway22,0.0f, 0.0f);

    glTranslatef(2.3f,0.0f, 0.0f);
    //glScalef(-1.0f, 1.0f, 0.0f);

    // road lines 1
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.78f, -0.5f);
    glVertex2f(-0.9f, -1.0f);
    glVertex2f(-0.92f, -1.0f);

    glEnd();

    // road lines 2
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(-0.52f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.56f, -1.0f);
    glVertex2f(-0.58f, -1.0f);

    glEnd();

    // road lines 3
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(-0.22f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(-0.22f, -1.0f);

    glEnd();

    // road lines 4
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.12f, -0.5f);
    glVertex2f(0.12f, -1.0f);
    glVertex2f(0.1f, -1.0f);

    glEnd();

    // road lines 5
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(0.38f, -0.5f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.46f, -1.0f);
    glVertex2f(0.44f, -1.0f);

    glEnd();

    // road lines 6
    glBegin(GL_POLYGON);
    glColor3f(0.63f, 0.62f, 0.0f);
    glVertex2f(0.68f, -0.5f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.82f, -1.0f);
    glVertex2f(0.8f, -1.0f);

    glEnd();


    // road light 1
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.7, -0.68);
    glVertex2f(-0.66, -0.68);
    glVertex2f(-0.66, -0.7);
    glVertex2f(-0.7, -0.7);

    glEnd();

    // road light 2
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.72, -0.82);
    glVertex2f(-0.68, -0.82);
    glVertex2f(-0.68, -0.84);
    glVertex2f(-0.72, -0.84);

    glEnd();

    // road light 3
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.42, -0.68);
    glVertex2f(-0.38, -0.68);
    glVertex2f(-0.38, -0.7);
    glVertex2f(-0.42, -0.7);

    glEnd();

    // road light 4
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.43, -0.82);
    glVertex2f(-0.39, -0.82);
    glVertex2f(-0.39, -0.84);
    glVertex2f(-0.43, -0.84);

    glEnd();

    // road light 5
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.08, -0.68);
    glVertex2f(-0.04, -0.68);
    glVertex2f(-0.04, -0.7);
    glVertex2f(-0.08, -0.7);

    glEnd();

    // road light 6
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(-0.08, -0.82);
    glVertex2f(-0.04, -0.82);
    glVertex2f(-0.04, -0.84);
    glVertex2f(-0.08, -0.84);

    glEnd();

    // road light 7
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.26, -0.68);
    glVertex2f(0.3, -0.68);
    glVertex2f(0.3, -0.7);
    glVertex2f(0.26, -0.7);

    glEnd();

    // road light 8
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.275, -0.8);
    glVertex2f(0.315, -0.8);
    glVertex2f(0.315, -0.82);
    glVertex2f(0.275, -0.82);

    glEnd();

    // road light 9
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.54, -0.68);
    glVertex2f(0.58, -0.68);
    glVertex2f(0.58, -0.7);
    glVertex2f(0.54, -0.7);

    glEnd();

    // road light 10
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.58, -0.8);
    glVertex2f(0.62, -0.8);
    glVertex2f(0.62, -0.82);
    glVertex2f(0.58, -0.82);

    glEnd();

    // road light 11
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.86, -0.68);
    glVertex2f(0.9, -0.68);
    glVertex2f(0.9, -0.7);
    glVertex2f(0.86, -0.7);

    glEnd();

    // road light 12
    glBegin(GL_POLYGON);
    glColor3f(0.94f, 0.93f, 0.0f);
    glVertex2f(0.88, -0.8);
    glVertex2f(0.92, -0.8);
    glVertex2f(0.92, -0.82);
    glVertex2f(0.88, -0.82);

    glEnd();

    glPopMatrix();
}


void plane()
{

    glPushMatrix();
    glTranslatef(s3BigP1,s3BigP1Y, 0.0f);

    glScalef(0.8,1.5,0);
    glRotatef(rotation,0.0,0.0,1.0);// i=how many degree you want to rotate around an axis
    // plane front wheel handle 1
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.5245190570464f, 0.099469824529f);
    glVertex2f(0.6156019104277f, 0.0962609435155f);
    glVertex2f(0.6153580810611f, 0.116320088294f);
    glVertex2f(0.5235134188893f, 0.1205472484777f);
    glVertex2f(0.5151392510071f, 0.0876216484794f);
    glVertex2f(0.4874935068914f, 0.0871279744773f);
    glVertex2f(0.4872466698904f, 0.0644189703823f);
    glVertex2f(0.4926770839131f, 0.0641721333812f);
    glVertex2f(0.4929239209142f, 0.0814507234536f);
    glVertex2f(0.52f, 0.08f);

    glEnd();

    //glPushMatrix();
    //glRotatef(i,0.0,0.0,1.0);
    //front wheel 1
    int h;

    GLfloat x0=0.4940803976506f;
    GLfloat y0=0.0483447077868f;
    GLfloat radius0 =0.02f;
    int triangleAmount0 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi0 = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x0, y0); // center of circle
    for(h = 0; h <= triangleAmount0; h++)
    {
        glVertex2f( x0 + (radius0 * cos(h *  twicePi0 / triangleAmount0)),
                    y0 + (radius0 * sin(h * twicePi0 / triangleAmount0)) );
    }
    glEnd();

    //front wheel inner 1

    int g;

    GLfloat x4=0.4940803976506f;
    GLfloat y4=0.0483447077868f;
    GLfloat radius4 =0.01f;
    int triangleAmount4 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi4 = 2.0f * PI;

    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(g = 0; g <= triangleAmount4; g++)
    {
        glVertex2f( x4 + (radius4 * cos(g *  twicePi4 / triangleAmount4)),
                    y4 + (radius4 * sin(g * twicePi4 / triangleAmount4)) );
    }
    glEnd();
    //i+=0.2f;
    //glPopMatrix();

    // plane back wheel handle 1
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.0681899902642f, 0.1519549983379f);
    glVertex2f(-0.0524334107819f, 0.1492692177443f);
    glVertex2f(-0.0467037455156f, 0.1127426016718f);
    glVertex2f(-0.0578049719691f, 0.1025366354162f);

    glEnd();

    // plane back wheel handle 2
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.0567076282201f, 0.0906151074325f);
    glVertex2f(-0.0490448663273f, 0.0825692074451f);
    glVertex2f(-0.062071561545f, 0.0714582027006f);
    glVertex2f(-0.0678186329646f, 0.0808450860192f);

    glEnd();

    //back wheel 1
    int i;

    GLfloat x=-0.039274844914f;
    GLfloat y=0.0963621788521f;
    GLfloat radius =0.02f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //back wheel inner 1

    int j;

    GLfloat x1=-0.039274844914f;
    GLfloat y1=0.0963621788521f;
    GLfloat radius1 =0.01f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(j = 0; j <= triangleAmount; j++)
    {
        glVertex2f( x1 + (radius1 * cos(j *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(j * twicePi / triangleAmount)) );
    }
    glEnd();

    //back wheel 2
    int k;

    GLfloat x2=-0.0783549305672f;
    GLfloat y2=0.0666689765176f;
    GLfloat radius2 =0.02f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(k = 0; k <= triangleAmount2; k++)
    {
        glVertex2f( x2 + (radius2 * cos(k *  twicePi2 / triangleAmount2)),
                    y2 + (radius2 * sin(k * twicePi2 / triangleAmount2)) );
    }
    glEnd();

    //back wheel inner 2

    int l;

    GLfloat x3=-0.0783549305672f;
    GLfloat y3=0.0666689765176f;
    GLfloat radius3 =0.01f;
    int triangleAmount3 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi3 = 2.0f * PI;

    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(l = 0; l <= triangleAmount3; l++)
    {
        glVertex2f( x3 + (radius3 * cos(l *  twicePi3 / triangleAmount3)),
                    y3 + (radius3 * sin(l * twicePi3 / triangleAmount3)) );
    }
    glEnd();

    // plane back wing black
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.8090204799838f, 0.5755043164711f);
    glVertex2f(-0.7456890174596f, 0.5674194489148f);
    glVertex2f(-0.6055513131507f, 0.4259342666799f);
    glVertex2f(-0.5745593208516f, 0.4030271419371f);
    glVertex2f(-0.4869339446724f, 0.3617065720574f);
    glVertex2f(-0.7336440825104f, 0.3616009351106f);

    glEnd();

    // plane body
    glBegin(GL_POLYGON);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(0.5236351888768f, 0.2736692610366f);
    glVertex2f(0.6220010774782f, 0.1160143436891f);
    glVertex2f(0.2999538531529f, 0.1308366008756f);
    glVertex2f(0.2514446478152f, 0.1079294761328f);
    glVertex2f(-0.3818699774269f, 0.1631760711007f);
    glVertex2f(-0.4290317048386f, 0.1914731075477f);
    glVertex2f(-0.5637794974433f, 0.2116852764384f);
    glVertex2f(-0.8319276047266f, 0.3262209001524f);
    glVertex2f(-0.8238427371704f, 0.3572128924515f);
    glVertex2f(-0.7336440825104f, 0.3616009351106f);
    glVertex2f(-0.5745593208516f, 0.3693401937859f);
    glVertex2f(-0.5745593208516f, 0.3693401937859f);

    glEnd();

    // plane head
    glBegin(GL_POLYGON);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(0.5236351888768f, 0.2736692610366f);
    glVertex2f(0.5706609137126f, 0.2590951391016f);
    glVertex2f(0.6327815279829f, 0.2288245007919f);
    glVertex2f(0.6975343716714f, 0.1767063583109f);
    glVertex2f(0.7043781681588f, 0.1703890077072f);
    glVertex2f(0.7080632893443f, 0.1635452112198f);
    glVertex2f(0.708589735228f, 0.1585439753251f);
    glVertex2f(0.7075368434607f, 0.1524898476632f);
    glVertex2f(0.7070103975771f, 0.1474886117685f);
    glVertex2f(0.7049046140425f, 0.1403815923393f);
    glVertex2f(0.7020091616824f, 0.134853910561f);
    glVertex2f(0.6975343716714f, 0.13037912055f);
    glVertex2f(0.6917434669513f, 0.1269572223063f);
    glVertex2f(0.6838467786966f, 0.1251146617135f);
    glVertex2f(0.6643682810017f, 0.1198502028771f);
    glVertex2f(0.641467885063f, 0.1166915275752f);
    glVertex2f(0.6153580810611f, 0.116320088294f);

    glEnd();

    // plane head windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6241364630655f, 0.2282065313095f);
    glVertex2f(0.6325980888564f, 0.2273411377627f);
    glVertex2f(0.6628868629945f, 0.2026293442596f);
    glVertex2f(0.6379827598143f, 0.2038793571605f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6060593534211f, 0.2282065313095f);
    glVertex2f(0.61990565017f, 0.2282065313095f);
    glVertex2f(0.6326942436949f, 0.2047447507073f);
    glVertex2f(0.6122132630873f, 0.2055139894156f);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6006746824633f, 0.2289757700178f);
    glVertex2f(0.5822129534648f, 0.2300334732416f);
    glVertex2f(0.5812514050795f, 0.2272449829242f);
    glVertex2f(0.5816360244336f, 0.2248411119608f);
    glVertex2f(0.5825975728189f, 0.2216680022892f);
    glVertex2f(0.5839437405584f, 0.2189756668103f);
    glVertex2f(0.5857706824905f, 0.2158987119772f);
    glVertex2f(0.5924053663494f, 0.2110909700505f);
    glVertex2f(0.5954823211824f, 0.2089755636028f);
    glVertex2f(0.598463121177f, 0.2078217055404f);
    glVertex2f(0.6017323856871f, 0.2071486216706f);
    glVertex2f(0.6046170308431f, 0.206860157155f);
    glVertex2f(0.6073093663221f, 0.2067640023165f);

    glEnd();

    // plane main wing
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.3622896100725f, 0.3551724823639f);
    glVertex2f(-0.3953672810171f, 0.3781243356724f);
    glVertex2f(-0.4203442978528f, 0.4085017885806f);
    glVertex2f(-0.4648978954516f, 0.4145772791623f);
    glVertex2f(-0.4358653242707f, 0.3572576492985f);
    glVertex2f(-0.4196692433437f, 0.3362709561099f);
    glVertex2f(-0.0396135547359f, 0.1627819472782f);
    glVertex2f(0.2378338484929f, 0.1810084190232f);

    glEnd();

    // plane back engine
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(0.1800998239982f, 0.1910319311585f);
    glVertex2f(0.1314973631666f, 0.1999624061909f);
    glVertex2f(0.0657838771167f, 0.2025143862317f);
    glVertex2f(0.0233572089389f, 0.200281403696f);
    glVertex2f(0.0255901914745f, 0.1147900723301f);
    glVertex2f(0.08f, 0.1f);
    glVertex2f(0.1133145053761f, 0.0962882170345f);
    glVertex2f(0.1480852334316f, 0.0956502220243f);
    glVertex2f(0.1752667746638f, 0.0958418725289f);

    glEnd();

    // plane back engine front
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.1890851624739f, 0.1116490411534f);
    glVertex2f(0.1894731598771f, 0.1310489113146f);
    glVertex2f(0.1894731598771f, 0.145792812637f);
    glVertex2f(0.19102514949f, 0.163252695782f);
    glVertex2f(0.194517126119f, 0.1869205373786f);
    glVertex2f(0.1800998239982f, 0.1910319311585f);
    glVertex2f(0.1766692455708f, 0.1791605893141f);
    glVertex2f(0.1751172559579f, 0.1531647632982f);
    glVertex2f(0.1739532637482f, 0.1329888983307f);
    glVertex2f(0.173565266345f, 0.117856999605f);
    glVertex2f(0.1743412611515f, 0.1062170775083f);
    glVertex2f(0.1914131468932f, 0.096905139831f);

    glEnd();

    // plane front engine back black
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.1161956386842f, 0.2033128222786f);
    glVertex2f(-0.1117143521201f, 0.1976453128004f);
    glVertex2f(-0.1040446787375f, 0.1966186418419f);
    glVertex2f(-0.103610908584f, 0.2086090542575f);

    glEnd();

    // plane front engine back white
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.0758271039242f, 0.2233020392264f);
    glVertex2f(-0.0980103772117f, 0.2230415504432f);
    glVertex2f(-0.1035011878185f, 0.2121727970232f);
    glVertex2f(-0.1044121930099f, 0.188486662047f);
    glVertex2f(-0.1024535087865f, 0.1766663646318f);
    glVertex2f(-0.0781032001338f, 0.1732283301649f);

    glEnd();

    // plane front engine
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(0.0608517127137f, 0.2284586868956f);
    glVertex2f(-0.0008168740142f, 0.2374817280611f);
    glVertex2f(-0.0749616321677f, 0.2330385964864f);
    glVertex2f(-0.0782939808488f, 0.1955496738244f);
    glVertex2f(-0.0780162851254f, 0.1630592741841f);
    glVertex2f(-0.0188670960366f, 0.1500075751833f);
    glVertex2f(0.0564398427306f, 0.1435950701622f);

    glEnd();

    // plane front engine front
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.0727897138444f, 0.1386641566517f);
    glVertex2f(0.0717516267896f, 0.156311636584f);
    glVertex2f(0.0720111485533f, 0.1744781600438f);
    glVertex2f(0.0727897138444f, 0.187713769993f);
    glVertex2f(0.0730492356081f, 0.1999112928875f);
    glVertex2f(0.0730492356081f, 0.2152230769464f);
    glVertex2f(0.074087322663f, 0.2243063386763f);
    glVertex2f(0.0608517127137f, 0.2284586868956f);
    glVertex2f(0.0574779297855f, 0.2191159034021f);
    glVertex2f(0.0561803209669f, 0.2063993369802f);
    glVertex2f(0.0554017556758f, 0.189530422339f);
    glVertex2f(0.0554017556758f, 0.1736995947527f);
    glVertex2f(0.0561803209669f, 0.15812828893f);
    glVertex2f(0.0564398427306f, 0.1435950701622f);
    glVertex2f(0.0574278399895f, 0.1248543466027f);
    glVertex2f(0.0751254097178f, 0.1254285467025f);

    glEnd();

    // plane back wing white
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.9570295201674f, 0.4040138687843f);
    glVertex2f(-0.8915633555276f, 0.4019465162167f);
    glVertex2f(-0.5793931178241f, 0.3233871186489f);
    glVertex2f(-0.7247969150767f, 0.3316565289192f);

    glEnd();

    // plane door
    glBegin(GL_POLYGON);
    glColor3f(0.91f, 0.91f, 0.91f);
    glVertex2f(-0.4952071172999f, 0.300477330771f);
    glVertex2f(-0.48923080062f, 0.3412721881081f);
    glVertex2f(-0.5261280601223f, 0.3443902663759f);
    glVertex2f(-0.5336634159361f, 0.3103512452857f);
    glVertex2f(-0.5388602130491f, 0.263320231413f);
    glVertex2f(-0.5f, 0.26f);

    glEnd();

    //door lining black
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4952071172999f, 0.300477330771f);
    glVertex2f(-0.48923080062f, 0.3412721881081f);
    glVertex2f(-0.5261280601223f, 0.3443902663759f);
    glVertex2f(-0.5336634159361f, 0.3103512452857f);
    glVertex2f(-0.5388602130491f, 0.263320231413f);
    glVertex2f(-0.5f, 0.26f);

    glEnd();

    // plane door handle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.5280969155672f, 0.309743167321f);
    glVertex2f(-0.5236446209512f, 0.3093721427697f);
    glVertex2f(-0.5234962111306f, 0.3032873401278f);
    glVertex2f(-0.5283937352083f, 0.3035841597688f);

    glEnd();

    // windows from left
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.4317507015787f, 0.3059640036878f);
    glVertex2f(-0.41980263077f, 0.3058512860386f);
    glVertex2f(-0.4201407837174f, 0.2884927680712f);
    glVertex2f(-0.4322015721753f, 0.2888309210186f);
    glVertex2f(-0.4083103967184f, 0.304733234731f);
    glVertex2f(-0.3954994229691f, 0.3045601134641f);
    glVertex2f(-0.3958456655029f, 0.2869017442421f);
    glVertex2f(-0.4084835179853f, 0.2872479867759f);
    glVertex2f(-0.3854583894899f, 0.3021364157278f);
    glVertex2f(-0.3728205370075f, 0.301790173194f);
    glVertex2f(-0.3735130220751f, 0.2846511677727f);
    glVertex2f(-0.3863239958243f, 0.2848242890396f);
    glVertex2f(-0.3629526247952f, 0.3005783243258f);
    glVertex2f(-0.35f, 0.3f);
    glVertex2f(-0.3511803786473f, 0.2825737125701f);
    glVertex2f(-0.3639913523965f, 0.2832661976376f);
    glVertex2f(-0.339754375033f, 0.2962502926538f);
    glVertex2f(-0.330490590684f, 0.2955624059615f);
    glVertex2f(-0.3302327053545107f, 0.2815349849687969f);
    glVertex2f(-0.3399274962999f, 0.2815349849688f);
    glVertex2f(-0.0023704839348f, 0.2713523698652f);
    glVertex2f(0.0126727368111f, 0.2697688729446f);
    glVertex2f(0.0126727368111f, 0.2505689727821f);
    glVertex2f(-0.0019746097046f, 0.2525483439329f);
    glVertex2f(0.0223716554498f, 0.2701647471747f);
    glVertex2f(0.0368210648505f, 0.268383313139f);
    glVertex2f(0.0364251906203f, 0.2483916645163f);
    glVertex2f(0.0221737183348f, 0.2507669098972f);
    glVertex2f(0.0483918318285f, 0.2683231111313f);
    glVertex2f(0.0651481138587f, 0.2666474829283f);
    glVertex2f(0.0651481138587f, 0.2463005690344f);
    glVertex2f(0.0495887091163f, 0.2477368217799f);
    glVertex2f(0.0766381358223f, 0.265689981098f);
    glVertex2f(0.0910006632769f, 0.2642537283525f);
    glVertex2f(0.0912400387344f, 0.2446249408314f);
    glVertex2f(0.0771168867375f, 0.2458218181193f);
    glVertex2f(0.1017559937361f, 0.2633079581596f);
    glVertex2f(0.1160084556224f, 0.2620316182892f);
    glVertex2f(0.1153702856872f, 0.242886520233f);
    glVertex2f(0.1013305471127f, 0.24373741348f);
    glVertex2f(0.1264318978974f, 0.2616061716657);
    glVertex2f(0.14f, 0.26f);
    glVertex2f(0.14f, 0.24f);
    glVertex2f(0.1268858928591f, 0.2418022452715f);
    glVertex2f(0.1521714186172f, 0.2603298317953f);
    glVertex2f(0.1655729872565f, 0.2590534919249f);
    glVertex2f(0.1657857105683f, 0.2375684374397f);
    glVertex2f(0.1526405630745f, 0.2391682449085f);
    glVertex2f(0.1757837062198f, 0.2579898753662f);
    glVertex2f(0.1891852748591f, 0.2571389821193f);
    glVertex2f(0.1898234447943f, 0.2354412043223f);
    glVertex2f(0.1760538996339f, 0.2368269112526f);
    glVertex2f(0.1987578238871f, 0.2565008121841f);
    glVertex2f(0.2134357323968f, 0.2550117490019f);
    glVertex2f(0.2134357323968f, 0.2331012478933f);
    glVertex2f(0.1985451005754f, 0.2352284810106f);
    glVertex2f(0.2252303092545f, 0.2543425048199f);
    glVertex2f(0.2398830608291f, 0.2528772296624f);
    glVertex2f(0.2405110358966f, 0.2306887772779f);
    glVertex2f(0.225439634277f, 0.2321540524354f);
    glVertex2f(0.2502516780386f, 0.2522293475f);
    glVertex2f(0.2657918808745f, 0.2505296378148f);
    glVertex2f(0.2655490652052f, 0.2291618589155f);
    glVertex2f(0.2497660467f, 0.230375937262f);
    glVertex2f(0.2764055146919f, 0.2508339324349f);
    glVertex2f(0.2919491298378f, 0.2494619418215f);
    glVertex2f(0.2922288349323f, 0.2286204251743f);
    glVertex2f(0.2764055146919f, 0.2298376036543f);
    glVertex2f(0.3040682472035f, 0.2487051826409f);
    glVertex2f(0.3197138283048f, 0.2476335674969f);
    glVertex2f(0.3197138283048f, 0.2272728797624f);
    glVertex2f(0.3040682472035f, 0.2285588179351f);
    glVertex2f(0.3306443027728f, 0.2467762753818f);
    glVertex2f(0.3469328529604f, 0.2448473681227f);
    glVertex2f(0.3460755608453f, 0.2240580343306f);
    glVertex2f(0.330429979744f, 0.2262012646185f);
    glVertex2f(0.3585062965148f, 0.2444187220652f);
    glVertex2f(0.3730802624721f, 0.2427041378349f);
    glVertex2f(0.3728659394433f, 0.2227720961579f);
    glVertex2f(0.3578633274284f, 0.2251296494746f);
    glVertex2f(0.3855109981416f, 0.2418468457198f);
    glVertex2f(0.4f, 0.24f);
    glVertex2f(0.4f, 0.22f);
    glVertex2f(0.3846537060264f, 0.2219148040428f);
    glVertex2f(0.4120870537108f, 0.2373460621153f);
    glVertex2f(0.4260180505818f, 0.2364887700001f);
    glVertex2f(0.4255894045243f, 0.2161280822656f);
    glVertex2f(0.4112297615957f, 0.2171996974095f);
    glVertex2f(0.4373771711074f, 0.2358458009138f);
    glVertex2f(0.4523797831223f, 0.2349885087987f);
    glVertex2f(0.4515224910072f, 0.2135562059202f);
    glVertex2f(0.4365198789923f, 0.2148421440929f);

    glEnd();

    // plane front door
    glBegin(GL_POLYGON);
    glColor3f(0.91f, 0.91f, 0.91f);
    glVertex2f(0.4941688680944f, 0.2584221776184f);
    glVertex2f(0.5318260515611f, 0.256941277145f);
    glVertex2f(0.5309798227191f, 0.1718952785293f);
    glVertex2f(0.4912070671476f, 0.1746455222656f);

    glEnd();

    //door lining black
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.4941688680944f, 0.2584221776184f);
    glVertex2f(0.5318260515611f, 0.256941277145f);
    glVertex2f(0.5309798227191f, 0.1718952785293f);
    glVertex2f(0.4912070671476f, 0.1746455222656f);

    glEnd();

    // plane door handle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.5012664477161f, 0.2250812660463f);
    glVertex2f(0.507821425438f, 0.2250812660463f);
    glVertex2f(0.5073844269232f, 0.2167782942652f);
    glVertex2f(0.5013097320512f, 0.2171638975459f);

    glEnd();
    glPopMatrix();
    rotation=4.0f;

}

void plane2()
{
    //Plane
    //plane body
    glPushMatrix();
    glTranslatef(s3smallp2,0.6f, 0.0f);

    glScalef(-0.3,0.4,0);

    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.8375889660587f, 0.2912098678332f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.928861465027f, 0.2556290631507f);
    glVertex2f(-0.9041096009f, 0.2378386608094f);
    glVertex2f(-0.8731697707412f, 0.2277832160078f);
    glVertex2f(-0.8453239235984f, 0.2192747627141f);
    glVertex2f(-0.8143840934396f, 0.2107663094205f);
    glVertex2f(-0.7842177590348f, 0.2068988306506f);
    glVertex2f(-0.7439959798284f, 0.2076723264046f);
    glVertex2f(-0.3897349245107f, 0.2092193179125f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.4043823800643f, 0.2892785841354f);
    glVertex2f(-0.3831964687035f, 0.2802549552225f);
    glVertex2f(-0.3545562551972f, 0.2671118435449f);
    glVertex2f(-0.3380783241388f, 0.2622076973966f);
    glVertex2f(-0.3237582173856f, 0.2573035512482f);
    glVertex2f(-0.3176770761617f, 0.2518109075621f);
    glVertex2f(-0.3121844324755f, 0.2463182638759f);
    glVertex2f(-0.31f, 0.24f);
    glVertex2f(-0.3098304423243f, 0.2357253081955f);
    glVertex2f(-0.31f, 0.23f);
    glVertex2f(-0.313753759243f, 0.2259170158989f);
    glVertex2f(-0.3204233980047f, 0.2227783623639f);
    glVertex2f(-0.3280738659961f, 0.2190512112912f);
    glVertex2f(-0.3378821582928f, 0.2157163919103f);
    glVertex2f(-0.3500444407407f, 0.2127739042213f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);

    glEnd();

    //plane head window
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3819451920869f, 0.2758911800548f);
    glVertex2f(-0.3881479557192f, 0.2728587178345f);
    glVertex2f(-0.3771897399688f, 0.2608667081453f);
    glVertex2f(-0.370504539165f, 0.2634167331942f);
    glVertex2f(-0.3660936850265f, 0.2658289190512f);
    glVertex2f(-0.360855795737f, 0.2696194968265f);
    glVertex2f(-0.3786950838177f, 0.2781892511995f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.398899412682f, 0.2686546224837f);
    glVertex2f(-0.4098576284324f, 0.2679654265246f);
    glVertex2f(-0.40854815611f, 0.262727537235f);
    glVertex2f(-0.4031035080328f, 0.2555598992599f);
    glVertex2f(-0.3925588098578f, 0.2561801756231f);
    glVertex2f(-0.3804978805727f, 0.2588680398638f);
    glVertex2f(-0.39f, 0.27f);
    glVertex2f(-0.39f, 0.27f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4127657925046f, 0.2602777634305f);
    glVertex2f(-0.4148377327393f, 0.2667761214393f);
    glVertex2f(-0.4317899710231f, 0.2668703005408f);
    glVertex2f(-0.432260866531f, 0.260371942532f);
    glVertex2f(-0.4296238516869f, 0.2515191069838f);
    glVertex2f(-0.4077743001211f, 0.2526492562027f);

    glEnd();

    //front door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4695704482148f, 0.2425964533209f);
    glVertex2f(-0.4727942748017f, 0.2424499157487f);
    glVertex2f(-0.4726477372296f, 0.2379072510126f);
    glVertex2f(-0.4692773730705f, 0.2380537885847f);

    glEnd();

    //upper wing
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.5498485455822f, 0.2873423890634f);
    glVertex2f(-0.6217836507013f, 0.3770678965238f);
    glVertex2f(-0.6565909596299f, 0.3778413922778f);
    glVertex2f(-0.6488595295804f, 0.2915606660423f);

    glEnd();

    //lower wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8512841908058f, 0.1241487992192f);
    glVertex2f(-0.8652666039946f, 0.1246309513981f);
    glVertex2f(-0.8522484951637f, 0.1101663860304f);
    glVertex2f(-0.8291051905754f, 0.1111306903883f);
    glVertex2f(-0.5055818995018f, 0.2087134359257f);
    glVertex2f(-0.7114611649165f, 0.2078143998322f);

    glEnd();

    //lower wing back
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.847900370437f, 0.2811701757442f);
    glVertex2f(-0.9292604039938f, 0.2448081495735f);
    glVertex2f(-0.9792581899784f, 0.2452626749007f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);

    glEnd();

    //upper wing back
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8228925467333f, 0.3035857998967f);
    glVertex2f(-0.8414564448285f, 0.3120942531904f);
    glVertex2f(-0.8561528641539f, 0.3283376640237f);
    glVertex2f(-0.9056565924079f, 0.3909908200952f);
    glVertex2f(-0.9427843885984f, 0.3894438285873f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.7617837686202f, 0.2913507696872f);
    glVertex2f(-0.7934997080824f, 0.2958508423571f);
    glVertex2f(-0.8097431189158f, 0.2989448253729f);

    glEnd();

    //back door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7678874563725f, 0.2510951983408f);
    glVertex2f(-0.7708790248524f, 0.2509192237244f);
    glVertex2f(-0.7707910375442f, 0.2473997313951f);
    glVertex2f(-0.7677114817561f, 0.2476636933198f);

    glEnd();

    //windows from left
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7151099662305f, 0.266868589599f);
    glVertex2f(-0.714460252525f, 0.2434788962022f);
    glVertex2f(-0.6962682687719f, 0.2434788962022f);
    glVertex2f(-0.6975676961829f, 0.266868589599f);

    glVertex2f(-0.6819745672516f, 0.26816801701f);
    glVertex2f(-0.6813248535462f, 0.2441286099077f);
    glVertex2f(-0.6637825834985f, 0.2444534667604f);
    glVertex2f(-0.6641074403513f, 0.2678431601572f);

    glVertex2f(-0.6501385956837f, 0.266868589599f);
    glVertex2f(-0.6491640251255f, 0.2447783236131f);
    glVertex2f(-0.6316217550779f, 0.2444534667604f);
    glVertex2f(-0.6329211824888f, 0.2671934464518f);

    glVertex2f(-0.6196020515268f, 0.2671934464518f);
    glVertex2f(-0.6183026241158f, 0.2451031804659f);
    glVertex2f(-0.6014100677737f, 0.2447783236131f);
    glVertex2f(-0.6030343520373f, 0.266868589599f);

    glVertex2f(-0.5858169388425f, 0.2662188758936f);
    glVertex2f(-0.585167225137f, 0.2457528941713f);
    glVertex2f(-0.5702238099112f, 0.2454280373186f);
    glVertex2f(-0.5711983804694f, 0.266868589599f);

    glVertex2f(-0.5533312535691f, 0.266868589599f);
    glVertex2f(-0.5520318261581f, 0.2454280373186f);
    glVertex2f(-0.5370884109324f, 0.2447783236131f);
    glVertex2f(-0.5393624089015f, 0.266868589599f);

    glVertex2f(-0.5227947094121f, 0.2665437327463f);
    glVertex2f(-0.5208455682957f, 0.2431540393495f);
    glVertex2f(-0.5039530119536f, 0.2434788962022f);
    glVertex2f(-0.5055772962172f, 0.266868589599f);

    glEnd();
    glPopMatrix();
}
void display3()
{
    glClearColor(0.54f, 0.82f, 0.91f, .0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.15, 0.18, 0.42);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.28, 0.32, 0.69);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);

    glEnd();

    clouds(-1.3, 0.0);
    clouds(-2.3, 0.6);
    clouds(-0.9, 0.4);
    clouds(0.3, 0.3);
    clouds(0.0, 0.0);

    buildings();
    // road
    glBegin(GL_POLYGON);
    glColor3f(0.29f, 0.29f, 0.29f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();


    //upper road
    glBegin(GL_POLYGON);
    glColor3f(0.62f, 0.62f, 0.62f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);

    glEnd();

    //upper road line 1
    glBegin(GL_POLYGON);
    glColor3f(0.84f, 0.84f, 0.84f);
    glVertex2f(-1.0f, -0.335f);
    glVertex2f(1.0f, -0.335f);
    glVertex2f(1.0f, -0.345f);
    glVertex2f(-1.0f, -0.345f);

    glEnd();

    //upper road line 2
    glBegin(GL_POLYGON);
    glColor3f(0.84f, 0.84f, 0.84f);
    glVertex2f(-1.0f, -0.36f);
    glVertex2f(1.0f, -0.36f);
    glVertex2f(1.0f, -0.37f);
    glVertex2f(-1.0f, -0.37f);

    glEnd();




    runway();
    runway2();
    guard();
    guard2();
    guard3();
    plane();
    plane2();

    glFlush(); // Render now

}


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '2':
        PlaySound("page2.wav", NULL, SND_ASYNC|SND_LOOP);
        glutDisplayFunc(display2);//
        break;
    case '3':
        if(!flag){
            glutTimerFunc(500, update3, 0);
        }
        PlaySound("page3.wav", NULL, SND_ASYNC|SND_LOOP);
        glutDisplayFunc(display3);//
        break;
    case '1':
        if(!flag1){
            glutTimerFunc(500, update1, 0);
        }
        PlaySound("page1.wav", NULL, SND_ASYNC|SND_LOOP);
        glutDisplayFunc(display1);//
        break;

        glutPostRedisplay();
    }
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		glutDisplayFunc(displayNavigation);
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		glutDisplayFunc(displayCover);
	}
	glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);  // Set the window's initial position according to the monitor
    glutCreateWindow("Airport"); // Create a window with the given title
    glutDisplayFunc(displayCover); // Register display callback handler for window re-paint
    //glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(500, update2, 0);
    //PlaySound("page1.wav", NULL, SND_ASYNC|SND_LOOP);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}


