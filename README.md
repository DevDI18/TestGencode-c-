# TestGencode

This console mode program in c ++ allows you to check the validity of an EAN13 Gencode. A Gencode EAN13 is composed of 12 digits (country code of origin, rerefence, ....) and a validation key which is the result of a calculation on the first 12: The sum of the even positions (multiplied by 3) is added to the sum of the odd positions. The verification key will be the difference between the rest of the division of this number by 10, and 10.

EX:
If the sum found is 101, the rest of the division by 10 is 1, so the key is 10-1 = 9

--------------------------------------------------------------------------------------------------------------------------------------------

Ce programme console en c ++ permet de vérifier la validité d'un Gencode EAN13. Un Gencode EAN13 est composé de 12 chiffres (code pays d'origine, réréfence, ....) et d'une clé de validation qui est le résultat d'un calcul sur les 12 premiers: La somme des positions paires (multipliée par 3) est ajouté à la somme des position impaires. La clé de vérification sera la différence entre le reste de la division de ce nombre par 10, et 10.

EX:
Si la somme trouvee est 101, le reste de la division par 10 est 1, la clé vaut donc 10-1 = 9
