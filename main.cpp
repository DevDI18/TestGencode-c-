#include <iostream>
#include <string>

using namespace std;

/*
Ce programme permet de verifier la validite d'un Gencode EAN13

Un Gencode EAN13 est compose de 12 chiffres (pays d'origine, reference,...)
et d'une cle de verification resultant d'un calcul effectue sur les 12 premiers.
On fait la somme des chiffres en position paire que l'on multiplie par 3 et on
ajoute le tout a la somme des chiffres en position impaire. La cle de verification
sera la difference entre le reste de la division de ce nombre par 10, et 10.

EX:
Si la somme trouvee est 101, le reste de la division par 10 est 1, la cle vaut donc 10-1 = 9



*/

int main()

{

    string genCode; // Declaration de la variable genCode

    char posImp1; // Declaration des varaiables des chiffres du gencode
    char posImp2;
    char posImp3;
    char posImp4;
    char posImp5;
    char posImp6;
    char posImp7;

    char posPair1;
    char posPair2;
    char posPair3;
    char posPair4;
    char posPair5;
    char posPair6;

    int longGencode; // Variable longueur du Gencode
    int somPair; // Somme de chiffres paires
    int somImp; // Somme des chiffres impaires
    int totSom; // Total des sommes paires multipliees par 3 et impaires
    int unites; // Variable unites de la somme
    int cleVerif; // Cle de verification du Gencode
    int cleVerifZero; // Cle de verification du Gencode si egale a 0
    int dernChiffre; // Dernier chiffre du Gencode
    int conditNum; // Variable pour verifier la saisie numerique
    int erreurSaisie; // Variable pour verifier les erreurs de saisie

    do{

    cout << "Entrez votre Gencode EAN13: " << endl << endl; // Demande du gencode
    cin >> genCode;



    conditNum = 0;
    erreurSaisie = 0;
    longGencode = genCode.size();

    for (int i = 0;i < longGencode;++i) // Verification que la saisie est uniquement numerique
        {
            if (!(isdigit(genCode[i])))
                {
                    conditNum = conditNum + 1;
                }

        }

    if (conditNum != 0)
        {
            cout << endl << "Merci de ne taper que des chiffres" << endl << endl;
            erreurSaisie = 1;
        }

    else

        if (longGencode!=13) // Verification de la longueur de la saisie

            {

            cout << endl << "Un gencode EAN13 est compose de 13 chiffres" << endl;

                if (longGencode < 13)

                    {

                        cout << "Il manque " << 13-longGencode << " chiffre(s)" << endl << endl;

                    }

                else

                    {

                        cout << "Il y a " << longGencode-13 << " chiffre(s) en trop" << endl << endl;

                    }


            erreurSaisie = 1;

            }

    }while (erreurSaisie !=0);

        posImp1 = genCode[0]; // Extraction des chiffres du gencode pour calcul
        posImp2 = genCode[2];
        posImp3 = genCode[4];
        posImp4 = genCode[6];
        posImp5 = genCode[8];
        posImp6 = genCode[10];
        posImp7 = genCode[12];

        posPair1 = genCode[1];
        posPair2 = genCode[3];
        posPair3 = genCode[5];
        posPair4 = genCode[7];
        posPair5 = genCode[9];
        posPair6 = genCode[11];

        somPair = (posPair1 -48) + (posPair2 -48) + (posPair3 -48) + (posPair4 -48) + (posPair5 -48) + (posPair6 -48); // Somme des chiffres en position paire
        somImp = (posImp1 -48) + (posImp2 -48) + (posImp3 -48) + (posImp4 -48) + (posImp5 -48) + (posImp6 -48); // Somme des chiffres en position impaire

        totSom = somPair*3 + somImp;

        unites = totSom%10;

        cleVerif = (10 - unites);

        cleVerifZero = totSom%10;

        dernChiffre = posImp7-48;

        if ((posImp7 != 0 && cleVerif == dernChiffre) || (posImp7 == 0 && cleVerifZero == dernChiffre)) // Comparaison de la cle de verification et du dernier chiffre

                    {

                        cout << endl << "Gencode valide !" << endl;

                    }

                else

                    {

                        cout << endl << "Ce n'est pas un Gencode valide !" << endl;

                    }



        return 0;



}
