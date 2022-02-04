# Push_swap
#Summary:
#This project will make you sort data on a stack,
#with a limited set of instructions, using the lowest possible number of actions.
#To succeed you’ll have to manipulate various types of algorithms
#and choose the one (of many) most appropriate solution for an optimized data sorting.


# Explication de l'algorithme de mon Push swap, fonctionne avec tous les nombre au dessus de 5, et optimisé, validé à 98%:
  Pour faire Push Swap:
    
  1) Savoir manier les listes chaînées (pour cette algo on va utiliser les liste chainées circulaires) et implémenté les actions
 	(ra,  rb, rr, rra, rrb, pa, pb, sa, sb)
    
  2) Parsing —> ne pas laisser passer autres choses que les ints,”1 6 -9 bonjour”,  “0-23”, “0 --42”, les doublons , …         
    
  3)  Faire l’algorithme qui se départage en deux grands parties:
    Pour cette algorithme on stock chaque nombre dans un maillon, la stucture est: 
        typedef struct s_stack
          {
            	int				nbr;        // le nombre en lui même
            	int				int_trie;   // le nombre de nombre déjà trié
             	int				index;      // l'index dans ma liste chainée 
	       	int				is_sorted;  // savoir si le nombre fait partie de l'enchaînement de nombre déjà tiré (le booléen)
              	int       			nb_move;    // le nombre de movement à faire pour une action
              	int				nb_calcule  // int calculator utile dans la stack B
		int       			all_number; // le nombre de nombre au total, n nombre 
             	struct s_stack	*next;
          }				t_stack;
		    
   4) L'algorithme:

I) Première partie de l'algo:
				
 a. L-> Pour chaque nombre calculer le nombre de de nombre "déjà" trier
                    	Exemple la liste est : 3 2 5 7 0 1 6
           	 Pour calculer le int_trie de chaque nombre il faut faire une boucle qui a pour condition arrêt tant qu'on ne retombe pas sur le nombre, ici 3.                           
          	  Pour 3 son int_trie vaut 3 car on acrémente le int_trie a chaque fois qu'on parcours la liste et qu'on trouve un nombre supérieur à lui même
                  	  Premierement on est sur 3, le prochain nombre est 2 -> 2 < 3 donc on accrémente pas le int_trie
                  	  Aprés 2 il y a 5 et 5 > 3 donc le int_trie++ du maillon de 3,(une fois qu'on trouve un nombre plus grand que lui on se on
                  	      prends celui ci comme nombre à différencier)
                  	  Après on a 7 et 7 > 5 donc int_trie++;
                   	 Apres il y a 0 et 0 < 7 donc on accrement pas int_trie, on continue jusqu'à retomber sur 3
                	Le int_trie pour 2 il vaut 3 
               		Le int_trie pour 5 il vaut 2 
                	Le int_trie pour 7 il vaut 1 car c'est le plus grand nombre il n'y a pas plus grand que lui
                	Le int trie pour 0 il vaut 4
                	Le int_trie pour 1 il vaut 3
                	Le int_trie pour 6 il vaut 2
	
  b. Une fois que le int_trie a été calculer pour tous les nombres dans chaque maillon,
		le maillon qui a le int_trie le plus grand sera notre reference pour commencer notre alogorithme.
		Ici c'est 0 et si on a pluisieurs int_trie superieur aux autres mais egaux entre eux cela ne changera rien à l'algorithme. 

  c. Donc 0 est notre maillon de reference, pour 0 on a 0 < 1 < 6 < 7 qui sont deja trier du coup 3, 2 et 5 sont mal placé 
	et ceux sont ces nombres là qu'il va falloir envoyé sur la stack B, pour faire ca, on crée un bool dans chaque maillon 
	pour qu'on "active" s'il faut l'envoyer sur la stack B.
        
  d. Une fois la valleur du booléen changer dans les bons maillons, on peut les envoyer sur la stack B, 
	tout en optimisant les mouvements pour obtenir un bon score lors de la correction ;). 
	Pour optimiser les mouvements avant d'envoyer sur la stack B; on va se servir du int index présent dans chaque maillon
	(c'est un int à initier au debut du code, on fait un index simple quoi de 0 a n nombre). Du coup on se place sur chaque maillon qu'on va envoyer
	et on calcule le nombre de mouvement à faire pour l'envoyer sur la stack B. Si son index est supérieur a la moitié du all_number
	alors le nb_move sera negatif et correspondra aux rra, sinon il sera positif et correspondra au ra. 
	On accrémente le nb_move jusqu'à que le nombre se situe au dessus de la stack A.
        
   e. Une fois le nb_move calculer pour chaque nombre qu'on va envoyer sur la stack B,
	on choisit celui qui a le moins de mouvement (faire une fonction absolute pour comparer les nb_move entre eux,
	sinon ca sera compliqué vu qu'il y en a qui sont négatif)
        Pour notre exemple: on envoie 3, 2 et 5. 
        Le nb_move de 3 est 0 il est deja au dessus de la stack
        Le nb_move de 2 est 1
        Le nb_move de 5 est 2
        Si on aurait du envoyer le nombre 1 son nb_move aurait été -2 pour qu'il soit au dessus de la stack A.
	(hypothése pour expliquer comment faire le nb_move en negatif)
        
   f. Une fois qu'on a trouvé le nb_move le plus petit on fait les fait les action et on envoie sur B,
	du coup dans notre exemple ca equivaut à prendre le nombre 2 car son nb_move est à 0 et qu'il est le plus petit.
	Vu que son nb_move equivaut a 0 on a pas besoin de faire de ra ou rra si son nb_move aurait été positif ou négatif
	on aurait du accrementer ou decrementait nb_move respectivement tout en faisant l'action ra ou rra.
        
   h. Dernière étape de la Première partie, on réitère les schemas d. e. et f. jusqu'à qu'il n'y est plus de nombre a envoyer sur la stack B.
        
II) Deuxième partie de l'algo:
        
   a. Une fois la première partie fini, dans nos deux liste chainées on a:
              A     B
              _     _
              7     5
              0     2
              1     3
              6
   b. Maintenant on va re-push sur la stack A dans le bonne ordre, du coup on va calculer le nombre de mouvement à faire pour envoyer dans la stack A
	pour chaque maillon de la stack B. Par conséquent on se resert des int déjà present dans notre structure, on a besoin de l'index,
	le nb_move sera le nombre total de mouvement pour push dans la stack A, le int_trie nous servira a caluculer le nombre de mouvement
	pour mettre les nombre au dessus de la stack B (on est obliger de mettre en haut de la stack B pour push dans la stack A)
	et le nb_calcule servira a calculer le nombre de mouvement pour mettre le bon nombre au dessus de la stack A pour que l'ordre reste croissant. 
