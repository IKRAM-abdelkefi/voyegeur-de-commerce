#include "class.h"
#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <bits/stdc++.h>
using namespace std;

int main()
{

    srand(time(NULL));
    graphe G(5);
    //cout<<"OK";
    G.tab[0][0]=-1;
    G.tab[0][1]=10;
    G.tab[0][2]=15;
    G.tab[0][3]=20;
    G.tab[0][4]=10;

    G.tab[1][0]=10;
    G.tab[1][1]=-1;
    G.tab[1][2]=35;
    G.tab[1][3]=25;
    G.tab[1][4]=10;

    G.tab[2][0]=15;
    G.tab[2][1]=35;
    G.tab[2][2]=-1;
    G.tab[2][3]=30;
    G.tab[2][4]=10;

    G.tab[3][0]=20;
    G.tab[3][1]=25;
    G.tab[3][2]=30;
    G.tab[3][3]=-1;
    G.tab[3][4]=10;

    G.tab[0][4]=10;
    G.tab[1][4]=10;
    G.tab[2][4]=10;
    G.tab[3][4]=10;
    G.tab[4][4]=-1;

population pop_init=gen_init(G,6,0);
cout<<"ok1\n";
/*
pop_init.affiche();


cout<<"la population apres tri"<<"\n";


sort(pop_init.pop.begin(), pop_init.pop.end(), [&](const chemin& A, const chemin& B ) {
        return compare_by_adapt_asc(A, B, G);
    });



pop_init.affiche();

for (int i=0;i<5;i++)
    cout<<"adapt"<<pop_init.pop[i].adapt(G)<<"\n";

*/



//chemin ch= selec_roulette(pop_init,G);
//cout<<"\n"; cout<<"la selection par roulette donne "<<"\n";
//ch.affiche();

population prod=selec_reproducteurs(pop_init,G,"selec_tournoi");
cout<<"ok2 "<<"\n";
population pop_next=selection_nextgen(prod,pop_init,2,G);
//pop_next.affiche();
cout<<"ok3"<<"\n";

pop_init=pop_next;
cout<<"ok4"<<"\n";
//population prod1=selec_reproducteurs(pop_init,G,"selec_tournoi");
 //cout<<"ok4.2"<<"\n";

for (int i=0; i<10;i++)
{
    cout<<"ieration"<<i<<"\n";

    //prod=selec_reproducteurs(pop_init,G,"selec_tournoi");
    //cout<<"okk prod "<<i<<"\n";
    pop_next=selection_nextgen(prod,pop_init,2,G);
    cout<<"okk next gen "<<i<<"\n";
    pop_init=pop_next;
    cout<<"okk "<<i<<"\n";

}
cout<<"ok5"<<"\n";


sort(pop_init.pop.begin(), pop_init.pop.end(), [&](const chemin& A, const chemin& B) {
        return compare_by_adapt_asc(A, B, G);
});
cout<<"ok6"<<"\n";
chemin chemin_meilleur(pop_init.pop[0]);
cout<<"ok7"<<"\n";
chemin_meilleur.affiche();
cout<<"ok8"<<"\n";

    return 0;
}
