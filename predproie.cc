#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  do {
    cout << "Combien de renards au départ (>= 2) ? ";
    cin >> renards_i;
  } while ( renards_i < 2);

  do {
    cout << "Combien de lapins au départ  (>= 5) ? ";
    cin >> lapins_i;
  } while (lapins_i < 5);

  // ===== PARTIE 2 =====
  // Première simulation
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;

  double nb_renards(renards_i);
  double nb_lapins(lapins_i);

  // Calcul de l'évolutoin des populations:
  for (int i(1); i <= duree; ++i) {
    double lapins_preced(nb_lapins); // Cette variable permet d'assurer que le nombre de renards est calculé avec le bon nombre de lapins

    nb_lapins *= (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);
    nb_renards *= (1.0 + taux_attaque * lapins_preced * taux_croissance_renards - taux_mortalite);

    if (nb_lapins < 0) {
      nb_lapins = 0;
    }

    if (nb_renards < 0) {
      nb_renards = 0;
    }

    cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
  }

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  cout << endl;

  // Saisie des taux d'attaque initial et final:
  do {
    cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
    cin >> taux_attaque;
  } while ((taux_attaque < 0.5) || (taux_attaque > 6));


  double taux_final(0.0);
  do {
    cout << "taux d'attaque à la fin  en % (entre " << taux_attaque << " et 6) ? ";
    cin >> taux_final;
  } while ((taux_final < taux_attaque) || (taux_final > 6));

  // Ajustement du taux en pourcent
  taux_attaque /= 100;
  // Ajustement du taux en pourcent
  taux_final /= 100;

  // Mise en marche de la simulation
  // du taux initial jusqu'au taux final

  while (taux_attaque < taux_final) {
    cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;

    //Les deux variables qui vont enregistrer l'évolution des populations remises à jour:
    nb_renards = renards_i;
    nb_lapins = lapins_i;

    // Deux variables qui vont permettre d'enregistrer
    // les mois de danger d'extinction:
    int danger_lapins(0);
    int danger_renards(0);

    // Une variable qui enregistre la véritable durée des boucles
    // en cas d'extinction des deux espèces:
    int mois(0);

    // Calcul de l'évolutoin des populations:
    for (int i(1); i <= duree; ++i) {
      double lapins_preced(nb_lapins); // Cette variable permet d'assurer que le nombre de renards est calculé avec le bon nombre de lapins

      nb_lapins *= (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);
      nb_renards *= (1.0 + taux_attaque * lapins_preced * taux_croissance_renards - taux_mortalite);

      if (nb_lapins < 5) {
        danger_lapins += 1;
      }

      if (nb_renards < 5) {
      danger_renards += 1;
      }

      if (nb_lapins < 2) {
        nb_lapins = 0;
      }

      if (nb_renards < 2) {
        nb_renards = 0;
      }

      mois += 1;

      // Si les deux espèces périssent,
      // la simulation est terminée:
      if ((nb_lapins == 0) && (nb_renards == 0)) {
        break;
      }
    }

    // Affichage des résultats

    cout << "Après " << mois << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;

    if (danger_renards > 0) {
      if (nb_renards > 0) {
      cout << "Les renards ont été en voie d'extinction" << endl;
      cout << "mais la population est remontée ! Ouf !" << endl;
      }
      else {
        cout << "Les renards ont été en voie d'extinction" << endl;
        cout << "et les renards ont disparu :-(" << endl;
      }
    }

    if (danger_lapins > 0) {
      if (nb_lapins > 0) {
        cout << "Les lapins ont été en voie d'extinction" << endl;
        cout << "mais la population est remontée ! Ouf !" << endl;
      }
      else {
        cout << "Les lapins ont été en voie d'extinction" << endl;
        cout << "et les lapins ont disparu :-(" << endl;
      }
    }

    if ((danger_lapins == 0) && (danger_renards == 0)) {
      cout << "Les lapins et les renards ont des populations stables." << endl;
    }

    // Ajustement du taux d'attaque pour la prochaine boucle:
    taux_attaque += 0.01;
  }

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
