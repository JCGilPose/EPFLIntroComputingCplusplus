#include <iostream>
using namespace std;

/* Le programme offre une sélection de six champignons,
   puis pose une série de questions pour déterminer
   le champignon que les utilisateurs ont choisi. */
int main()
{
    int n; // n enregistrera les réponses des utilisateurs

    // La liste des champignons
    cout << "Pensez à un champignon : "
         << "amanite tue-mouches, pied bleu, girolle," << endl
         << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant."
         << endl << endl;

    // Première question
    cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
    cin >> n;

    if (n == 1)
    {
        // Deuxième question
        cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
	      cin >> n;
	      if (n == 1)
        {
            // Première solution
		        cout << "==> Le champignon auquel vous pensez est ";
		        cout << "l'amanite tue-mouches";
  	    }
	      else
        {
            // Troisième question
			      cout << "Est-ce que votre champignon a un chapeau convexe "
                 << "(1 : oui, 0 : non) ? ";
			      cin >> n;
			      if (n == 1)
            {
                // Deuxième solution
				        cout << "==> Le champignon auquel vous pensez est ";
				        cout << "l'agaric jaunissant";
			      }
			      else
            {
                // Troisième solution
				        cout << "==> Le champignon auquel vous pensez est ";
				        cout << "le coprin chevelu";
			      }
		    }
    }
    else
    {
        // Quatrième question
		    cout << "Est-ce que votre champignon a des lamelles "
             << "(1 : oui, 0 : non) ? ";
		    cin >> n;
		    if (n == 1)
        {
            // Cinquième question
			      cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
            cin >> n;
            if (n == 1)
            {
                // Quatrième solution
				        cout << "==> Le champignon auquel vous pensez est ";
				        cout << "le pied bleu";
			      }
			      else
            {
                // Cinquième solution
				        cout << "==> Le champignon auquel vous pensez est ";
				        cout << "la girolle";
			      }
		    }
		    else
        {
            // Sixième et dernière solution
			      cout << "==> Le champignon auquel vous pensez est ";
			      cout << "le cèpe de Bordeaux";
		    }
	  }

    return 0;
}
