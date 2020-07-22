#include <iostream>
using namespace std;

/* Le but de cet exercice est de permettre
   à un service de location de vélos (online,
   tournant 24 heures sur 24) de facturer ses clients. */

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // Calcul et enregistrement de la durée
  int duree(fin - debut);

  // Contrôle que les valeurs entrées ont du sens
  if ((debut < 0) or (debut > 24) or (fin < 0) or (fin > 24))
  {
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
  }
  else if (debut == fin)
  {
	  cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
  }
  else if (debut > fin)
  {
    cout << "Bizarre, le début de la location est après la fin ..." << endl;
  }
  else if (duree > 0)
  {
    /* Les valeurs entrées sonts valides.
       Calcul du prix de la location selon les différents tarifs horaires
       définis comme suit :
       — 1 franc par heure si le vélo est loué entre 0h et 7h ou entre 17h et 24h ;
       — 2 francs par heure si le vélo est loué entre 7h et 17h. */
    int tarif1;  // tarif1 : 1 franc par heure
    int tarif2;  // tarif2 : 2 francs par heure
    int montant;  // Représentera le total à payer

    if (fin < 8)
    {
      montant = duree;
      cout << "Vous avez loué votre vélo pendant" << endl;
      cout << duree << " heure(s) au tarif horaire de 1"
           << " franc(s)" << endl;
      cout << "Le montant total à payer est de "
           << montant << " franc(s)." << endl;
    }
    else if (fin < 18)
    {
      if (debut >= 7)
      {
        montant = (duree * 2);
        cout << "Vous avez loué votre vélo pendant" << endl;
        cout << duree << " heure(s) au tarif horaire de 2"
             << " franc(s)" << endl;
        cout << "Le montant total à payer est de "
             << montant << " franc(s)." << endl;
      }
      else
      {
        tarif2 = (fin - 7);
        tarif1 = (duree - tarif2);
        cout << "Vous avez loué votre vélo pendant" << endl;
        cout << tarif1 << " heure(s) au tarif horaire de 1"
             << " franc(s)" << endl;
        cout << tarif2 << " heure(s) au tarif horaire de 2"
             << " franc(s)" << endl;
        montant = (tarif2 * 2) + tarif1;
        cout << "Le montant total à payer est de "
             << montant << " franc(s)." << endl;
      }
    }
    else if ( fin >= 18)
    {
      if (debut >= 17)
      {
        montant = duree;
        cout << "Vous avez loué votre vélo pendant" << endl;
        cout << duree << " heure(s) au tarif horaire de 1"
             << " franc(s)" << endl;
        cout << "Le montant total à payer est de "
             << montant << " franc(s)." << endl;
      }
      else if (debut >= 7)
      {
        tarif1 = (fin - 17);
        tarif2 = (duree - tarif1);
        cout << "Vous avez loué votre vélo pendant" << endl;
        cout << tarif1 << " heure(s) au tarif horaire de 1"
             << " franc(s)" << endl;
        cout << tarif2 << " heure(s) au tarif horaire de 2"
             << " franc(s)" << endl;
        montant = (tarif2 * 2) + tarif1;
        cout << "Le montant total à payer est de "
             << montant << " franc(s)." << endl;
      }
      else if (debut < 7)
      {
        tarif1 = ((fin - 17) + (7 - debut));
        tarif2 = duree - tarif1;
        cout << "Vous avez loué votre vélo pendant" << endl;
        cout << tarif1 << " heure(s) au tarif horaire de 1"
             << " franc(s)" << endl;
        cout << tarif2 << " heure(s) au tarif horaire de 2"
             << " franc(s)" << endl;
        montant = (tarif2 * 2) + tarif1;
        cout << "Le montant total à payer est de "
             << montant << " franc(s)." << endl;
      }
    }
  }


  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
