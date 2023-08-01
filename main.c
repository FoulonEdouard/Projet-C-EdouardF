#include <stdio.h>
#include "gd.h"
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <gd.h>
#include <gdfontl.h>
#include <math.h>


int main() {

  /* Calcul et transformation des pourcentages pour l'exemple */
   float w=20;
   float a=20;
   float b=20;
   float u=20;
   float z=20;
   char *s1="Valeur 1";
   char *s2="Valeur 2";
   char *s3="Valeur 3";
   char *s4="Valeur 4";
   char *s5="valeur 5";

   /*
    char s[20]
    char s1[20];
    char s2[20];
    char s3[20];
    char s4[20];
    char s5[20];


    printf("Donner le titre du Pie Chart:\n")
    scanf("%s",s);
    printf("Entrer le nom de la première valeur et son pourcentage:\n");
    char w1[10];
    scanf("%s %s",s1,w1);
    float w=atof(w1);
    printf("Entrer le nom deuxième valeur et son pourcentage:\n");
    char a1[10];
    scanf("%s %s",s2,a1);
    float a=atof(a1);
    printf("Entrer le nom de la troisième valeur et son pourcentage:\n");
    char b1[10];
    scanf("%s %s",s3,b1);
    float b=atof(b1);
    printf("Entrer le nom de la quatrième valeur et son pourcentage:\n");
    char u1[10];
    scanf("%s %s",s4,u1);
    float u=atof(u1);
    printf("Entrer le nom de la cinquième valeur et son pourcentage:\n");
    char z1[10];
    scanf("%s %s",s5,z1);
    float z=atof(z1);
 */

   float convw=(w/100)*360;
   float convx=(a/100)*360;
   float convy=(b/100)*360;
   float convu=(u/100)*360;
   float convz=(z/100)*360;
   printf("les pourcentage sont rouge:%f bleu:%f orange:%f vert:%f et gris:%f\n",convw,convx,convy,convz,convu);

  /* tout ce qui concerne le graphique */

  gdImagePtr im;
  FILE *pngout;
  int cor_rad = 150;

  int black,white,red,green,blue,orange,gris;

  im = gdImageCreate(500, 500);

  white = gdImageColorAllocate(im, 255, 255, 255);
  black = gdImageColorAllocate(im, 0, 0, 0);
  red = gdImageColorAllocate(im, 255, 0, 0);
  green = gdImageColorAllocate(im, 0, 255, 0);
  blue = gdImageColorAllocate(im, 0, 0, 255);
  orange= gdImageColorAllocate(im, 255, 128, 0);
  gris=gdImageColorAllocate(im, 128, 128, 128);

  // Ecriture du titre et des légendes:

      char *s = "PROJET C";

      int foreground,foreground1,foreground2,foreground3,foreground4,foreground5;
      foreground=foreground1=foreground2=foreground3=foreground4=foreground5=0;

      gdFontPtr fontptr = gdFontGetLarge();
      foreground = gdImageColorAllocate(im, 0, 0, 0);
      foreground1 = gdImageColorAllocate(im, 255, 0, 0);
      foreground2 = gdImageColorAllocate(im, 0, 0, 255);
      foreground3=gdImageColorAllocate(im, 255, 128, 0);
      foreground4=gdImageColorAllocate(im, 0, 255, 0);
      foreground5=gdImageColorAllocate(im, 128,128,128);


      gdImageString(im, fontptr,
              225,
              40,
              (unsigned char*)s, foreground);
      gdImageLine(im,215,60,310,60,black);

      gdImageString(im, fontptr,
              390 ,
              370 ,
              (unsigned char*)s1, foreground1);
      gdImageLine(im,370,380,380,380,red);

      gdImageString(im, fontptr,
              390 ,
              390,
              (unsigned char*)s2, foreground2);
      gdImageLine(im,370,400,380,400,blue);

      gdImageString(im, fontptr,
              390,
              410 ,
              (unsigned char*)s3, foreground3);
      gdImageLine(im,370,420,380,420,orange);

      gdImageString(im, fontptr,
              390 ,
              430 ,
              (unsigned char*)s4, foreground4);
      gdImageLine(im,370,440,380,440,green);

      gdImageString(im, fontptr,
              390,
              450 ,
              (unsigned char*)s5, foreground5);
      gdImageLine(im,370,460,380,460,gris);

  // Création des arcs de cercles et du contour:

  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, 360, convw, red, gdPie);
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, convw, convx+convw, blue, gdPie);
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, convx+convw, convw+convx+convy, orange, gdPie);
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, convw+convx+convy,convw+convx+convy+convu , green, gdPie);
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, convw+convx+convy+convu, 360, gris, gdPie);
  gdImageEllipse(im,250,250,300,300,black);

  //Lecture du png

  pngout = fopen("test.png", "wb");
  gdImagePng(im, pngout);
  fclose(pngout);
  gdImageDestroy(im);

}

