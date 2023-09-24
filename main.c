#include <stdlib.h>
#include <stdio.h>
#include <string.h>

  int index = 0;
// int star=0;
int ident = 0;
int complet = 0;
int incomplet = 0;
struct tache
{
    int id;
    char titre[10];
    char description[100];
    int jour,mois,anne;
    char statut[14];
};

// struct tache task1;

struct tache task1[100];
struct tache temp;
void ajouter()
{
    // task1[index].id=ident;
    // ident++;
    printf("intrer id ");
    scanf("%d",&task1[index].id);
    printf("entrer le titre ");
    scanf("%s",task1[index].titre);
    printf("entrer le description ");
    scanf(" %[^\n]s",task1[index].description);
    printf("entrer le dedline DD/MM/YYYY ");
    scanf("%d/%d/%d",&task1[index].jour,&task1[index].mois,&task1[index].anne);
    printf("entrer le status de ce titre \n");

    int c;
    printf("1- a realise 2-en cours de realisation,  3-finalisee ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        strcpy(task1[index].statut, "realiser");
        break;
    case 2:
        strcpy(task1[index].statut, " en cours de realisation");
        break;
    case 3:
        strcpy(task1[index].statut, "finalisee ");
        break;
    default:

        printf("not value");
        index++;
        break;
    }
    // task1[index].id=index+1;&df
       index++;
}
void afichage() // string = "kdgfjkdgfkds"
{

    int v;
    printf("[1]-Trier les tâches par ordre alphabétique\n");
    printf("[2]-Trier les tâches par deadline\n");
    printf("[3]-Afficher les tâches dont le deadline est dans 3 jours ou moins");
    printf("_______");
    printf("choiser un nombre : ");
    scanf("%d", &v);
    switch (v)
    {
    case 1:
        for (int i = 0; i<index;i++)
        {
            for (int j = i + 1; j<index;j++)
            {
                if (strcmp(task1[i].titre,task1[j].titre) > 0)
                {
                    temp=task1[i];
                    task1[i]=task1[j];
                   task1[j]=temp ;
                }
            }
            printf("le %d tach est : \n id : %d \n titre : %s \n description : %s \n le dead line : %d/%d/%d \n statut : %s : ", i + 1,task1[i].id,task1[i].titre,task1[i].description,task1[i].jour,task1[i].mois,task1[i].anne,task1[i].statut);
        }
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

// task1[num_task1++]=tache;
void ajouter_plusieu()
{
    int d;
    printf("enter the nomber of task you wanna apend :");
    scanf("%d", &d);
    for (int i = 1; i <= d; i++)
    {
        ajouter();
        index++;
    }
}
void statistique()
{
    int k;
    printf("[1]-Afficher le nombre total des tâches.\n2[2]Afficher le nombre de tâches complètes et incomplètes.\n[3]Afficher le nombre de jours restants jusqu'au délai de chaque tâche.");
    scanf("%d", &k);
    switch (k)
    {
    case 1:
        printf("%d \n",index);
        break;
    case 2:

        for (int i = 0; i < index; i++)
        {
            if (strcmp(task1[i].statut, "finalisee") == 0)
            {
                complet++;
            }
            else
                incomplet++;
        }
        printf("le nommber des tach complet est %d\n", complet);
        printf("le nommber des tach incomplet est %d\n", incomplet);
         break;

    default:
        printf("try again");
        break;
    }
}
void recherch()
{
    int q,newid;
    char new_titre[50];
    printf("[1]_Rechercher une tâche par son Identifiant \n");
    printf("[2]-Rechercher une tâche par son Titre \n");
    printf("choisir 1 ou 2: \n");
    scanf("%d",&q);
    switch (q)
    {
    case 1:
        printf("entre le id");
        scanf("%d", &newid);
        for (int i = 0; i < index; i++)
        {
            if (newid == task1[i].id)
            {
             printf("le %d tach est : \n id : %d \n titre : %s \n description : %s \n le dead line : %d/%d/%d \n statut : %s : ", i + 1, task1[i].id, task1[i].titre, task1[i].description, task1[i].jour,task1[i].mois,task1[i].anne, task1[i].statut);

            }
        }
    case 2:
        printf("entre le titre ");
        scanf("%s",new_titre);
        for (int i = 0; i < index; i++)
        {
            if (strcmp(new_titre, task1[i].titre) == 0)
            {
            printf("le %d tach est : \n id : %d \n titre : %s \n description : %s \n le dead line : %d/%d/%d \n statut : %s : ", i + 1, task1[i].id, task1[i].titre, task1[i].description, task1[i].jour,task1[i].mois,task1[i].anne, task1[i].statut);
            }
        }
    }
}
void modification(){
    int w,new_id,m;
    char newdescription[200];
    int new_jour,new_moi,new_anee;
    printf("[1]Modifier la description d'une tâche\n");
    printf("[2]Modifier le statut d’une tâche\n");
    printf("[3]Modifier le deadline d’une tâche\n");
    printf("choisir un nomber:\n");
    scanf("%d",&w);
    switch(w){
case 1:
    printf("enter the id of your tach you wanna modifie : ");
    scanf("%d",&new_id);
    printf("type the new description : ");
    scanf(" %[^\n]s",newdescription);
    for(int i=0;i<index;i++){
        if(new_id == task1[i].id){
            strcpy(task1[i].description,newdescription);
        }
    }
    break;
case 2:
    printf("entrer le id de tach you wanna modifie : ");
    scanf("%d",&new_id);
    printf("1- a realise 2-en cours de realisation,  3-finalisee ");
    scanf("%d",&m);
    for(int i=0;i<index;i++){
        if(new_id == task1[i].id){
            switch (m){
    case 1:
        strcpy(task1[i].statut, "realiser");
        break;
    case 2:
        strcpy(task1[i].statut, " en cours de realisation");
        break;
    case 3:
        strcpy(task1[i].statut, "finalisee ");
        break;

                }

    }

    }
    case 3:
    printf("enter id the tach you wanna modifie");
    scanf("%d",&new_id);
    printf("enter the new dealine\n");
    scanf("%d/%d/%d",&new_jour,&new_moi,&new_anee);
    for(int i=0;i<index;i++){
        if(new_id == task1[i].id){
            task1[i].jour = new_jour;
            task1[i].mois = new_moi;
            task1[i].anne = new_anee;

        }
    }
};
};
void menu()
{
    printf("===================       MENU        =======================\n\n");
    printf("1-ajouter une nouvelle tache\n");
    printf("2-ajouter une plusieurs taches\n");
    printf("3-afficher la liste de tout les tache\n");
    printf("4-modifier une tache \n");
    printf("5-Statistiques\n");
    printf("6-recherche");
}
int main()
{
    int choice;


    do
    {
        menu();
        printf("entrer votre choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ajouter();
            break;
        case 2:
            ajouter_plusieu();
            break;
        case 3:
            afichage();

            break;
        case 4:
            modification();
            break;
        case 5:
            statistique();

            break;
        case 6:
            recherch();

                break;



    }
        }while (choice != 0);
    return 0;

}
