#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>


#define MAX 1000
#define L 4  //4 lignes
#define C 4  //4 colonnes

int tableau[L][C];
int plateau[L][C];

int score = 0;
int score2 = 0;
int i, j;

// intialisation des tableau
void initgrill() {
    for (int i=0; i<L; i++) {
        for (int j=0; j<C; j++) {
            tableau[i][j]=0;
        }
    }
}
void initgrill2() {
    for (int i=0; i<L; i++) {
        for (int j=0; j<C; j++) {
            plateau[i][j]=0;
        }
    }
}

// Gestion de l'affichage
void afficheGrille() {
    for (int i=0; i<L; i++) {
        printf("\n\t|");
        for (int j=0; j<C; j++) {
                if(tableau[i][j]==0){
                    printf("|   |",tableau[i][j]);}

         else{   printf("| %d |",tableau[i][j]);}
        }
        printf("| \n\n");
    }
}
void afficheGrille2() {
    for (int i=0; i<L; i++) {
        printf("\n\t|");
        for (int j=0; j<C; j++) {
                if(plateau[i][j]==0){
                    printf("|   |",plateau[i][j]);}

         else{   printf("| %d |",plateau[i][j]);}
        }
        printf("| \n\n");
    }
}
// Brouillon affichage des grilles cote à cotes
/*void afficheGrille(){
    for(int i =0; i<L;i++){
        for (int j=0;j<C;j++ ){
            printf("%d",tableau[i][j])
        }
        printf("\t");
        for(int j= 0;j<C;j++){
            printf("%d",plateau[i][j])
        }

    }
}
*/

//Fonction qui genere un nombre aleatoire entre a et b
int aleatoire2(int a, int b){
    srand(time(NULL));
    return rand()%(b-a) + a ;
}

/*int aleatoire1(int a, int b){
    int res;
    srand(time(NULL));
    res = rand()%(b-a) + a;
    if (res == 2 || res == 4){
        return res;
    }
    else {
        return aleatoire1(a, b);
    }
}*/

//Fonction qui genere un 2 ou 4
int ValeurAleatoire(void){
    int a;
    srand(time(NULL));
    a=rand()%6;
    if (a==0){
        return 4;
    }
    else{
        return 2;
    }
}
//Gestion de sauvegarde dans un fichier appelé 2048.txt
/*void sauvegardeEcriture (){

    FILE* ecriture;

    char ligne[MAXCHAR];
    char* nomFichier = "2048.txt";
    ecriture = fopen(nomFichier, "w");
    for (int i = 0; i<L;i++){
        for(int j = 0; j<C; j++){
            fprintf(ecriture, "%d",tableau[i][j]);
        }
    }
    fclose(ecriture);
}

void sauvegardeLecture(){
    FILE* lecture;
    char ligne[MAXCHAR];
    //char* nomfichier2 = "2048.txt";
    lecture = fopen(nomFichier, "r");
    while(fgets(ligne, MAXCHAR, lecture) != NULL) {
        printf("%s \n", ligne)
    }
    fclose(lecture);
}
*/

//------------------------Gestion des choix de l'utilisateur----------------------------------------------//

void choixJeu(){
    int choix;
    printf("Choissisez : \n 1. Module 1 joueur\n 2. Module 2 joueurs\n");
    scanf("%d",&choix);
    switch(choix){
        case 1 : Module1();
        break;
        case 2 : Module2();
        break;
    }
}

//---------------------------Gestion des modules 1 et 2 joueurs-------------------------------------//

void Module1(){
    int defaite = Defaite();
    int defaite2 = Defaite2();
    initgrill();
    initialisation();
    afficheGrille();
    while(score != 2048 || (defaite != 0 && defaite2 ==0)){ /*tant que le score est different de 2048 ou (tant que defaite != 0
                                                            (cad que toutes les cases sont remplies)et que defaite2 == 0(cad si une
                                                                                                                         case est differente de la case du dessus dessous gauche et droite.  */
    coup();
    afficheGrille();
    }
    if (score == 2048){
        printf("Vous avez gagné !");
    }
}

void Module2(){
    int defaite = Defaite();
    int defaite2 = Defaite2();
    int lose = Lose();
    int lose2 = Lose2();
    initgrill();
    initgrill2();
    initialisation();
    initialisation2();
    afficheGrille();
    afficheGrille2();
    while(score != 2048 || score2 != 2048 ||(defaite != 0 && defaite2 == 0) ||(lose != 0 && lose2 == 0)){
        coup();
        afficheGrille();
        printf("\n");
        afficheGrille2();
        coup2();
        afficheGrille();
        printf("\n");
        afficheGrille2();
    }
    if (score == 2048){
        printf ("Le joueur 1 a gagné !");
    }
    else if (score2 == 2048){
        printf("Le joueur 2 a gagné !");
    }
    else if (defaite != 0 && defaite2 == 0){
        printf("Le joueur 1 est bloqué !");
    }
    else if (lose!= 0 && lose2 == 0){
        printf("Le joueur 2 est bloqué !");
    }
}
//--------------------------choix des déplacements des joueurs------------------------------
/*void coup(){
    int z;
    printf("Vous etes le Joueur 1 et votre grille est celle de gauche.\n Choissisez un deplacement : \n \n 1. A gauche\n 2. A droite\n 3. En haut\n 4. En bas\n");
    scanf("%d",&z);
    switch(z){
        case 1: gauche();
        break;
        case 2: droite();
        break;
        case 3: haut();
        break;
        case 4: bas();
        break;
    }
}*/
void coup(){
    int k1,k2;
    printf("Vous etes le Joueur 1.\nAppuyez sur une fleche du clavier pour deplacer vos cases ! \n");
    k1 = getch();
    k2 = getch();
    if(k1 == 224){
        if (k2 == 72){
            haut();
        }
        else if(k2 == 80 ){
            bas();
        }
        else if (k2 == 77){
            droite();
        }
        else if(k2 == 75){
                gauche();
        }
    }

}

/*void coup2(){
    int z;
    printf("Vous etes le Joueur 2 et votre grille est celle de droite.\nChoissisez un deplacement : \n \n 1. A gauche\n 2. A droite\n 3. En haut\n 4. En bas\n");
    scanf("%d",&z);
    switch(z){
        case 1: gauche2();
        break;
        case 2: droite2();
        break;
        case 3: haut2();
        break;
        case 4: bas2();
        break;
    }
}*/
void coup2(){
    int k1,k2;
    printf("Vous etes le Joueur 2 et votre grille est celle de droite.\nAppuyez sur une fleche du clavier pour deplacer vos cases ! \n");
    k1 = getch();
    k2 = getch();
    if(k1 == 224){
        if (k2 == 72){
            haut2();
        }
        else if(k2 == 80 ){
            bas2();
        }
        else if (k2 == 77){
            droite2();
        }
        else if(k2 == 75){
                gauche2();
        }
    }

}


//--------------------------------------DEPLACEMENTS-------------------------------------------------


void gauche(){ //deplacement a gauche
    int compteur = -1;
    int compteur2 = 0;
    for (int i=0;i<L;i++){
        for(int j= 0; j<C; j++){
            if (tableau[i][j] !=0){ //verifie si la case est une puissance de 2 et non pas un 0
                 //et que la colonne est differente de 0
                    while(tableau[i][j + compteur] == 0 && j+compteur >= 0 && j+compteur2 >=0 ){ //on crée un compteur qui s'arrete lorsque la colonne-compteur<0
                        tableau[i][j+compteur] = tableau[i][j + compteur2]; // la case à gauche de celle choisie prendre la valeur de celle choisie
                        tableau[i][j + compteur2] = 0; //la case choisie = 0.
                        //compteur2 = compteur2 + 1;
                        //compteur = compteur + 1;
                        j=j+compteur; //On enleve -1 à j à chaque tour de la boucle afin de savoir si la case encore plus à gauche est = 0 et donc pouvoir encore se deplacer
                    }

                    if (tableau[i][j-1] == tableau[i][j]){
                        tableau [i][j-1] = tableau [i][j-1] + tableau[i][j];
                        tableau[i][j] = 0;
                        score = score + tableau[i][j-1]; // On ajoute la valeur de la case fusionnée au score
                    }


            }
        }
    }
    ajout();
}
void gauche2(){ //deplacement a gauche
    int compteur = -1;
    int compteur2 = 0;
    for (int i=0;i<L;i++){
        for(int j= 0; j<C; j++){
            if (plateau[i][j] !=0){ //verifie si la case est une puissance de 2 et non pas un 0
                    while(plateau[i][j + compteur] == 0 && j+compteur >= 0 && j+compteur2 >=0 ){ //on crée un compteur qui s'arrete lorsque la colonne-compteur<0
                        plateau[i][j+compteur] = plateau[i][j + compteur2]; // la case à gauche de celle choisie prendre la valeur de celle choisie
                        plateau[i][j + compteur2] = 0; //la case choisie = 0.
                        //compteur2 = compteur2 + 1;
                        //compteur = compteur + 1;
                        j=j+compteur; //On enleve -1 à j à chaque tour de la boucle afin de savoir si la case encore plus à gauche est = 0 et donc pouvoir encore se deplacer
                    }

                    if (plateau[i][j-1] == plateau[i][j]){
                        plateau [i][j-1] = plateau [i][j-1] + plateau[i][j];
                        plateau[i][j] = 0;
                        score2 = score2 + plateau[i][j-1]; // On ajoute la valeur de la case fusionnée au score
                    }
            }
        }
    }
    ajout2();
}

void droite(){
    int compteur = 1;
    int compteur2 = 0;
    for (int i=0; i<L;i++){
        for(int j=C-1;j>=0;j--){
            if(tableau[i][j] != 0){
               while(tableau[i][j + compteur] == 0 && j+compteur <= 3 && j+compteur2 <= 3 ){
                    tableau[i][j+compteur] = tableau[i][j + compteur2];
                    tableau[i][j + compteur2] = 0;
                    //compteur2 = compteur2 + 1;
                    //compteur = compteur + 1;
                    j=j+compteur;
                    }
                if (tableau[i][j+1] == tableau[i][j]){
                    tableau [i][j+1] = tableau [i][j+1] + tableau[i][j];
                    tableau[i][j] = 0;
                    score = score + tableau[i][j+1];
                    }
               }
        }
    }
    ajout();
}

void droite2(){
    int compteur = 1;
    int compteur2 = 0;
    for (int i=0; i<L;i++){
        for(int j=C-1;j>=0;j--){
            if(plateau[i][j] != 0){
               while(plateau[i][j + compteur] == 0 && j+compteur <= 3 && j+compteur2 <= 3 ){
                    plateau[i][j+compteur] = plateau[i][j + compteur2];
                    plateau[i][j + compteur2] = 0;
                    //compteur2 = compteur2 + 1;
                    //compteur = compteur + 1;
                    j=j+compteur;
                    }
                if (plateau[i][j+1] == plateau[i][j]){
                    plateau[i][j+1] = plateau[i][j+1] + plateau[i][j];
                    plateau[i][j] = 0;
                    score2 = score2 + plateau[i][j+1];
                    }
               }
        }
    }
    ajout2();
}
//for(int j=C-1;j>=0;j--)
void haut(){
    int compteur = -1;
    int compteur2 = 0;
    for (int i=0; i<L;i++){
        for(int j= 0; j<C; j++){
            if(tableau[i][j] != 0){
               while(tableau[i + compteur][j] == 0 && i + compteur >= 0 && i+compteur2 >= 0 ){
                    tableau[i+compteur][j] = tableau[i+ compteur2][j];
                    tableau[i+ compteur2][j] = 0;
                    //compteur2 = compteur2 + 1;
                    //compteur = compteur + 1;
                    i=i+compteur;
                    }
                if (tableau[i-1][j] == tableau[i][j]){
                    tableau [i-1][j] = tableau [i-1][j] + tableau[i][j];
                    tableau[i][j] = 0;
                    score = score + tableau[i-1][j];
                    }

               }
        }
    }
    ajout();
}
void haut2(){
    int compteur = -1;
    int compteur2 = 0;
    for (int i=0; i<L;i++){
        for(int j= 0; j<C; j++){
            if(plateau[i][j] != 0){
               while(plateau[i + compteur][j] == 0 && i + compteur >= 0 && i+compteur2 >= 0 ){
                    plateau[i+compteur][j] = plateau[i+ compteur2][j];
                    plateau[i+ compteur2][j] = 0;
                    //compteur2 = compteur2 + 1;
                    //compteur = compteur + 1;
                    i=i+compteur;
                    }
                if (plateau[i-1][j] == plateau[i][j]){
                    plateau[i-1][j] = plateau [i-1][j] + plateau[i][j];
                    plateau[i][j] = 0;
                    score2 = score2 + tableau[i-1][j];
                    }

               }
        }
    }
    ajout2();
}

void bas(){
    int compteur = 1;
    int compteur2 = 0;
    for (int i=L-1; i>=0;i--){
        for(int j= 0; j<C; j++){
            if(tableau[i][j] != 0){
                while(tableau[i + compteur][j] == 0 && i + compteur <= 3 && i+compteur2 <= 3 ){
                            tableau[i+compteur][j] = tableau[i+ compteur2][j];
                            tableau[i+ compteur2][j] = 0;
                            //compteur2 = compteur2 + 1;
                            //compteur = compteur + 1;
                            i=i+compteur;
                            }
                if (tableau[i+1][j] == tableau[i][j]){
                    tableau [i+1][j] = tableau [i+1][j] + tableau[i][j];
                    tableau[i][j] = 0;
                    score = score + tableau[i+1][j];
                    }
               }
        }
    }
    ajout();
}

void bas2(){
    int compteur = 1;
    int compteur2 = 0;
    for (int i=L-1; i>=0;i--){
        for(int j= 0; j<C; j++){
            if(plateau[i][j] != 0){
                while(plateau[i + compteur][j] == 0 && i + compteur <= 3 && i+compteur2 <= 3 ){
                            plateau[i+compteur][j] = plateau[i+ compteur2][j];
                            plateau[i+ compteur2][j] = 0;
                            //compteur2 = compteur2 + 1;
                            //compteur = compteur + 1;
                            i=i+compteur;
                            }
                if (plateau[i+1][j] == plateau[i][j]){
                    plateau [i+1][j] = plateau[i+1][j] + plateau[i][j];
                    plateau[i][j] = 0;
                    score2 = score2 + plateau[i+1][j];
                    }
               }
        }
    }
    ajout2();
}

//-------------------------------Generations de cases aléatoires à l'initialisation------------------------------

void initialisation(){
    srand(time(NULL));
    int res = aleatoire2(0,4);
    int res2 = aleatoire2(0,4);
    int res4 = aleatoire2(0,4);
    int res5 = aleatoire2(0,4);
    while (res4 == res && res5 == res2){   // si les valeurs aleatoires des 2 cases d'initialisation sont les memes
        res4 = (aleatoire2(0,4) + 1)% 2;
        res5 = (aleatoire2(0,4) + 1)% 2;
    }
    int res3 = ValeurAleatoire();
    tableau[res][res2] = res3;
    tableau[res4][res5] = res3;
}

void initialisation2(){
    srand(time(NULL));
    int res = aleatoire2(0,4);
    int res2 = aleatoire2(0,4);
    int res4 = aleatoire2(0,4);
    int res5 = aleatoire2(0,4);
    while (res4 == res && res5 == res2){   // si les valeurs aleatoires des 2 cases d'initialisation sont les memes
        res4 = (aleatoire2(0,4) + 1)% 2;
        res5 = (aleatoire2(0,4) + 1)% 2;
    }
    int res3 = ValeurAleatoire();
    plateau[res][res2] = res3;
    plateau[res4][res5] = res3;
}

//------------------------------Genere des nombres aleatoires et les ajoutent apres chaque coup-----------------------------------
void ajout(){ //ajout d'une case aleatoire apres chaque coup
    srand(time(NULL));
    int res = aleatoire2(0,4);
    int res2 = aleatoire2(0,4);
    int res3 = ValeurAleatoire();
    while(tableau[res][res2] != 0){ //tant que la case n'est pas vide on regenere des nombres aleatoires
        res = aleatoire2(0,4);
        res2 = aleatoire2(0,4);
    }
    tableau[res][res2] = res3;
}
void ajout2(){ //ajout d'une case aleatoire apres chaque coup
    srand(time(NULL));
    int res = aleatoire2(0,4);
    int res2 = aleatoire2(0,4);
    int res3 = ValeurAleatoire();
    while(plateau[res][res2] != 0){ //tant que la case n'est pas vide on regenere des nombres aleatoires
        res = aleatoire2(0,4);
        res2 = aleatoire2(0,4);
    }
    plateau[res][res2] = res3;
}
//------------------------Conditions de defaite------------------------------
int Defaite(){ //sert a savoir si toutes les cases sont remplies de 0 (cad vides) on retourne 0.
    for (int i=0; i<L;i++){
        for(int j= 0; j<C; j++){
            if (tableau[i][j] = 0){
                return 0;
            }
        }
    }
}
int Lose(){ //sert a savoir si toutes les cases sont remplies de 0 (cad vides) on retourne 0
    for (int i=0; i<L;i++){
        for(int j= 0; j<C; j++){
            if (plateau[i][j] = 0){
                return 0;
            }
        }
    }
}
int Defaite2(){ //sert à savoir si une case est differente de la case du dessus dessous gauche et droite.
    for (int i=0; i<L;i++){
        for(int j= 0; j<C; j++){
                if (tableau[i][j] != tableau[i+1][j] != tableau[i-1][j] != tableau[i][j+1] != tableau[i][j-1]){
                    return 0;
                }
        }
}
}
int Lose2(){
    for (int i=0; i<L;i++){
        for(int j= 0; j<C; j++){
                if (plateau[i][j] != plateau[i+1][j] != plateau[i-1][j] != plateau[i][j+1] != plateau[i][j-1]){
                    return 0;
                }
        }
}
}


int main(void) {

    //int plateau[L][C];
    /*initgrill();
    initialisation();
    afficheGrille();
    while(score != 2048 ){
    coup();
    afficheGrille();
    }*/
    choixJeu();
    return 0;
}

/*int main(void)
{
    int k1,k2;

    printf("appuyer sur la fleche du haut\n");
    k1 = getch();
    k2 = getch();
    printf("%d %d\n",k1,k2);

    return 0;
}*/
