#include <stdio.h>        // Pour la manipulation des flux de caractères
#include "gd.h"           // Pour la création du graphique et de l'image
#include <string.h>       // Pour les chaîne de caractères
#include <float.h>        // pour les float
#include <gdfontl.h>      // Pour le fontptr lors de l'écriture sur l'image


//Fonction main avec le programme

int main() {

  // Valeurs déjà initialisées pour travaillé sur le projet, en commentaire si non utilisées*/

/*   float w=20;
   float a=20;
   float b=20;
   float u=20;
   float z=20;
   char *s = "PROJET C";
   char *s1="Valeur 1";
   char *s2="Valeur 2";
   char *s3="Valeur 3";
   char *s4="Valeur 4";
   char *s5="valeur 5";
*/

//Variables textes pour le titre puis des 5 variables, on peut enlever ou rajouter des variables à la main mais il faut modifié aussi pour l'appel et le graphique.
   char s[20];
    char s1[20];
    char s2[20];
    char s3[20];
    char s4[20];
    char s5[20];

//Appel du titre,des variables et leurs valeurs en %. On appelle tout en 1 mot (ou relié par un -) sans espace puis touche entrée pour passer à la suivante.
//On peut modifié la taille si on souhaite plus de caractère pour une châine de caractère donnée dans les [].

    printf("Donner le titre du Pie Chart:\n");
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

//Variables de conversion pour que les % puissent être adaptés à un cercle

   float convw=(w/100)*360;
   float conva=(a/100)*360;
   float convb=(b/100)*360;
   float convu=(u/100)*360;
   float convz=(z/100)*360;
   float total=convw+conva+convb+convu+convz;

//Ne continue pas si le total est supérieur à 100%
   if(total != 360)
   {printf("\n Le total est supérieur à 100 pourcents le Pie Chart ne peut être remplit correctement\n");}

//Exécute le programme si on est à 100% ou moins (il restera une partie blanche dans ce cas).
   else if(total <= 360)
   {
  /* tout ce qui concerne le graphique */

  // Création de l'image et du d'un fichier png.
  gdImagePtr im;
  FILE *pngout;

  //Choix de la taille de l'image (x,y)
  im = gdImageCreate(500, 500);


  // Allocation sur des variables pour la couleurs définie selon un code R,V,B tel que gdImageColorAllocate(im,rouge,vert,bleu)

  int black,white,red,green,blue,orange,gris,marron,grisclair,grisfonce;

  //Appel choix couleur d'arrière plan
  printf("\nQuelle couleur d'arrière plan souhaitez vous entre le 1= blanc/2=grisclair/3=grisfoncé (taper le numéro)\n");
  int colo;
  scanf("%d",&colo);

  if(colo==1)
  {int white;
  white = gdImageColorAllocate(im, 255, 255, 255);
  }

  if(colo==2)
  {int grisclair;
   grisclair=gdImageColorAllocate(im, 230, 230, 230);
  }

  if(colo==3)
  {int grisfonce;
  grisfonce=gdImageColorAllocate(im, 100, 100, 100);
  }


// Liste couleurs réutilisées par la suite ou pouvant servir
  white = gdImageColorAllocate(im, 255, 255, 255);
  black = gdImageColorAllocate(im, 0, 0, 0);
  red = gdImageColorAllocate(im, 255, 0, 0);
  green = gdImageColorAllocate(im, 0, 255, 0);
  blue = gdImageColorAllocate(im, 0, 0, 255);
  orange= gdImageColorAllocate(im, 255, 128, 0);
  gris=gdImageColorAllocate(im, 128, 128, 128);
  marron=gdImageColorAllocate(im, 88, 41, 0);

  // Ecriture du titre et des légendes:


  // Préparation du FontPtr ( nécéssite la librairie <gdfontl.h>) et des foreground pour le titre les chaînes de caractères des variables.
      int foreground,foreground1,foreground2,foreground3,foreground4,foreground5;
      foreground=foreground1=foreground2=foreground3=foreground4=foreground5=0;
      gdFontPtr fontptr = gdFontGetLarge();

  //Choix des couleurs pour l'écriture des variables dans la légende
      foreground = gdImageColorAllocate(im, 0, 0, 0);
      foreground1 =gdImageColorAllocate(im, 255, 0, 0);
      foreground2 =gdImageColorAllocate(im, 0, 0, 255);
      foreground3=gdImageColorAllocate(im, 255, 128, 0);
      foreground4=gdImageColorAllocate(im, 0, 255, 0);
      foreground5=gdImageColorAllocate(im, 88, 41, 0);

  //Ecriture du titre avec syntaxe gdImageString (im,fontptr,x,y,unsigned char*,foreground); on peut modifié son emplacement en changeant les valeurs x et y.
      gdImageString(im, fontptr,
              225,
              40,
              (unsigned char*)s, foreground);
  //Barre pour souligné le titre avec gdImageLine de syntaxe(im,x1,y1,x2,y2,color) donc on peut changer taille et positionnement.
      gdImageLine(im,215,60,310,60,black);

  //Un gdImageString pour le placement des légendes et un gdImageLine pour le trait de couleur devant le nom
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
      gdImageLine(im,370,460,380,460,marron);

  /* Création des arcs de cercles et du contour:*/

  //Initialisation du rayon
  int cor_rad = 150;

  //Création cercle blanc en fond pour exemple
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, 360, 360, white, gdPie);

  //Création des arcs de cercles qui se mettent à la suite en rajoutant à chaque fois un % définit plus haut avec les variables conv
  //Syntaxe gdImageFilledArc(im,xcentre,ycentre,largeur,hauteur,angle initial,angle où va l'arc,color,style)
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, 360, convw, red, gdPie);
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, convw, conva+convw, blue, gdPie);
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, conva+convw, convw+conva+convb, orange, gdPie);
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, convw+conva+convb,convw+conva+convb+convu , green, gdPie);
  gdImageFilledArc (im,100 + cor_rad, 400 - cor_rad, cor_rad *2, cor_rad *2, convw+conva+convb+convu,convw+conva+convb+convu+convz , marron, gdPie);

  //Contour du cercle, gdImageEllipse(im,xcentre,ycentre,largeur,hauteur,color)
  gdImageEllipse(im,250,250,300,300,black);

  //Lecture du png avec choix du titre dans fopen

  pngout = fopen("test.png", "wb");
  gdImagePng(im, pngout);

  //Fermeture et nettoyage mémoire
  fclose(pngout);
  gdImageDestroy(im);
 }
}

