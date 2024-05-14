# Push_Swap 📚
Sorted algorithm in a stack 

## Description 🔍

This project aims to sort data (Int) on a stack using an additional video stack available as support, with a limited instruction set, in as few moves as possible.
Its only print the instruction set, there are defined on the subject file.
Coded in C, I appreciated playing with linked list and implemented the sorted algorithm. 🔗

## Getting started 🏁

### Dependencies 🛠️
* Bash
* Terminal
* Python optional for the visual
    

### Installation 📦
* Commande make for the Makefile 

### Running the program 💻
* How to run the program
* First clone it
  ```
  git clone https://github.com/balkisous/push_swap.git  ```
* Change directory and make to compile
  ```
  ~ cd push_swap && make
  ~ ./push_swap 1 2 3 5 6 4 
  ```
If there a double Int, its an error
Test with many Int as you want.
Example of test :
```
	 ~ ./push_swap "2 4 5 7"
  	No movement is printed because the stack is already sorted 
  	~ ./push_swap "4 5 6 2 6"
  	Error because double is present
	~ ./push_swap "2 5 6 1 78 43 67 32 57"
  	Actions are displayed
```

## Help 🛟
* You can use an Visualizer to be more clear
  L-> https://github.com/xbeheydt/push_swap_visualizer.git
## Authors 👩‍💻
Names of contributors :
@balkisous
Some help of @ttranche for the theoretical explanation of the algorithm
## Version history ✅
* Made at 42Paris 

## Subject 📝
You will find the subject in the repo


## Tuto for the algorithm (in French)
# Explication de l'algorithme de mon Push swap, fonctionne avec tous les nombre au dessus de 5, et optimisé, validé à 98%:
  Pour faire Push Swap:
    
  1) Savoir manier les listes chaînées (pour cette algo on va utiliser les liste chainées circulaires) et implémenté les actions
 	(ra,  rb, rr, rra, rrb, rrr, pa, pb, sa, sb)
    
  2) Parsing —> ne pas laisser passer autres choses que les ints,”1 6 -9 bonjour”,  “0-23”, “0 --42”, les doublons, ...         
    
  3)  Faire l’algorithme qui se départage en deux grands parties:
  
    		Pour cette algorithme on stock chaque nombre dans un maillon, la stucture est:
        	typedef struct s_stack
          {
            	int				nbr;        // le nombre en lui même
            	int				int_trie;   // le nombre de nombre déjà trié
             	int				index;      // l'index dans ma liste chainée 
	       	int				is_sorted;  // savoir si le nombre fait partie de l'enchaînement de nombre déjà tiré (le booléen)
              	int       			nb_move;    // le nombre de movement à faire pour mettre le nombre au dessus de la stack
              	int				nb_calcule  // int calculator utile dans la stack B
			int       		all_number; // le nombre de nombre au total, n nombre, le nombre d'arguments total
             	struct s_stack	*next;
       		 }				t_stack;


   4) L'algorithme:
   	Cette algorithme consiste à calculer tout les mouvements à faire pour chaque maillon,
		une fois qu'on a touver le maillon ayant le nombre de mouvement le plus petit
		il suffira de faire les actions pour bouger le maillon au bonne endroit
		et on réitère les calcules et les actions jusqu'à que les maillons sont rangés 
		dans l'ordre croissant.

I) Première partie de l'algo:
				
 
 	A. L-> Pour chaque nombre calculer le nombre de de nombre "déjà" trier    
		Exemple la liste est : 3 2 5 7 0 1 6
        Pour calculer le int_trie de chaque nombre il faut faire une boucle qui a pour condition 
	d'arrêt tant qu'on ne retombe pas sur le nombre, ici 3.                           
        Pour 3 son int_trie vaut 3 car on acrémente le int_trie à chaque fois qu'on parcours la liste
	et qu'on trouve un nombre supérieur à lui même.
	Premierement on est sur 3, le prochain nombre est 2 -> 2 < 3 donc on accrémente pas le int_trie
        Aprés 2 il y a 5 et 5 > 3 donc le int_trie++ du maillon de 3,
	(une fois qu'on trouve un nombre plus grand que lui on se on
        prends celui ci comme nombre à différencier, a stocker dans un temp)
        Après on a 7 et 7 > 5 donc int_trie++;
        Apres il y a 0 et 0 < 7 donc on accrement pas int_trie, on continue jusqu'à retomber sur 3,
		d'où le principe de la liste chainée circulaire
            Le int_trie pour 2 il vaut 3 
            Le int_trie pour 5 il vaut 2 
            Le int_trie pour 7 il vaut 1 car c'est le plus grand nombre il n'y a pas plus grand que lui
            Le int trie pour 0 il vaut 4
            Le int_trie pour 1 il vaut 3
            Le int_trie pour 6 il vaut 2
	
 	B. Une fois que le int_trie a été calculer pour tous les nombres dans chaque maillon
		le maillon qui a le int_trie le plus grand sera notre reference pour commencer notre alogorithme.
		Ici c'est 0 et si on a pluisieurs int_trie superieur aux autres
		mais egaux entre eux (par expample, le plus grand int_trie est de 6 et il y a deux maillon qui ont ce nombre)
		cela ne changera rien à l'algorithme. 

 	C. Donc 0 est notre maillon de reference, pour 0 on a 0 < 1 < 6 < 7 qui sont deja trier,
		du coup 3, 2 et 5 qui sont mal placé et ceux sont ces nombres là qu'il va falloir envoyé sur la stack B,
		pour faire ca, on crée un bool dans chaque maillon 
		pour qu'on "active" s'il faut l'envoyer sur la stack B, 
		par exemple, on les met à 1.
        
  	D. Une fois la valleur du booléen changer dans les bons maillons,
		on peut les envoyer sur la stack B, tout en optimisant les mouvements
		pour obtenir un bon score lors de la correction ;). 
		Pour optimiser les mouvements avant d'envoyer sur la stack B;
		on va se servir du int index présent dans chaque maillon
		(c'est un int à initier au debut du code, on fait un index simple quoi de 0 a n nombre).
		Du coup on se place sur chaque maillon qu'on va envoyer et on calcule le nombre de mouvement à faire
		pour l'envoyer sur la stack B. Si son index est supérieur a la moitié du all_number(nombre total d'arguments),
		alors le nb_move sera negatif et correspondra aux rra, sinon il sera positif et correspondra au ra. 
		On accrémente le nb_move jusqu'à que le nombre se situe au dessus de la stack A.
        
  	E. Une fois le nb_move calculer pour chaque nombre qu'on va envoyer sur la stack B,
		on choisit celui qui a le moins de mouvement (faire une fonction valeur absolut d'un nombre
		pour comparer les nb_move entre eux, sinon ca sera compliqué vu qu'il y en a qui sont négatif)
       		Pour notre exemple: on envoie 3, 2 et 5. 
       		Le nb_move de 3 est 0 il est deja au dessus de la stack
        	Le nb_move de 2 est 1
        	Le nb_move de 5 est 2
        	Si on aurait du envoyer le nombre 1 son nb_move aurait été -2
			pour qu'il soit au dessus de la stack A.
			(hypothése pour expliquer comment faire le nb_move en negatif)
        
   	F. Une fois qu'on a trouvé le nb_move le plus petit on fait les actions
		et on envoie sur B, du coup dans notre exemple ça équivaut à prendre le nombre 2
		car son nb_move est à 0 et qu'il est le plus petit. Vu que son nb_move equivaut a 0;
		On a pas besoin de faire de ra ou rra si son nb_move aurait été positif ou négatif
		on aurait du accrémenter ou décrémenter nb_move respectivement tout en faisant l'action ra ou rra.
        
  	H. Dernière étape de la Première partie, on réitère les schemas D. E. et F.
		Jusqu'à qu'il n'y est plus de nombre a envoyer sur la stack B.
        
II) Deuxième partie de l'algo:
        
   	A. Une fois la première partie fini, dans nos deux liste chainées on a:
              A     B
              _     _
              7     5
              0     2
              1     3
              6
   	
	B. Maintenant on va re-push sur la stack A dans le bonne ordre, du coup on va calculer le nombre de mouvement
		à faire pour envoyer dans la stack A pour chaque maillon de la stack B.
		Par conséquent on se resert des variables déjà présentes dans notre structure, on a besoin de:
			o l'index, fonction de index à faire dans la stack B,
			o Le nb_move sera le nombre total de mouvement pour push dans la stack A,
			o Le int_trie nous servira a calculer le nombre de mouvement pour mettre les nombres
		  		au dessus de la stack B (on est obligé de mettre en haut de la stack B
				pour push dans la stack A)
			o Le nb_calcule servira a calculer le nombre de mouvement pour mettre
		    		le bon nombre au dessus de la stack A pour que l'ordre reste croissant.
				Donc on va calculer pour chaque maillon présent dans la stack B le nb_move.
		
		Pour caluculer le nb_move = int_trie + nb_calcule + 1 (-> le 1 ça équivaut à l'action pb)
		
		Pour calculer int_trie on se ressert de la fonction pour qu'on a utilisé
		    dans la premiére partie pour calculer le nombre de mouvement à faire pour mettre
		    un nombre au dessus de la stack en fonction de son idex (si son index est dans apres la motié
		    du all_number ou au dessus, comme expliqué à la fin du point D).
		
		Enfin pour calculer le nb_calcule, il faut parcouriir la stack A et savoir où placer le nombre,
			une fois trouvé il faut calculer le nombre de ra ou rra à faire dans la stack A,
			pour mettre le bon nombre au dessus de la stack A
	
	C. Une fois que tout les nb_move de chaque maillon dans la stack B sont calculé,
		on va prendre le petit et faire l'action correspondantes
			Dans notre exemple:
		Le maillon 5	o a pour int_trie 0 car il est déja au dessus de la stack B
			 	o a pour nb_calcule -1 car il suffirait de faire un rra
					et mettre le 6 au dessus de la stack A et comme ça
					5 est bien compris entre 1 et 6 (1 < 5 < 6)
				o donc son nb_move équivaut à |0| + |-1| + 1 = 2
		
		Le maillon 2	o a pour int_trie 1 car il faut faire un rb pour qu'il soit au dessus de la stack B
				o a pour nb_calcule -1 car il suffirait de faire un rra
					et mettre le 6 au dessus de la stack A et comme ça
					2 est bien compris entre 1 et 6 (1 < 2 < 6)
				o donc son nb_move équivaut à |1| + |-1| + 1 = 3
		
		Le maillon 3	o a pour int_trie -1 car il faut faire un rrb pourqu'il soit au dessus de la stack B
				o a pour nb_calcule -1 car il suffirait de faire un rra
					et mettre le 6 au dessus de la stack A et comme ça
					3 est bien compris entre 1 et 6 (1 < 3 < 6)
				o donc son nb_move équivaut à |-1| + |-1| + 1 = 3
		
		Donc ici on va push le maillon 5 en premier car son nb_move est le plus petit,
			on fait les actions nécessaire qu'on a déjà calculer
			on va aussi faire une fonction qui va encore plus optimiser les actions quand on push sur la stack B,
			cette fonction a pour but de savoir si on va faire des ra et rb ou rra
			et rrb comme ca on fait des rr ou rrr. Vu que rr = ra + rb et rrr = rra + rrb
			(C'est la fonction ft_optimise_r dans le fichier ft_absolute.c)
			
				-> Dans notre exemple on va faire rra (car int_trie vaut -1)
					et pb, pour mettre 5 entre 1 et 6
	
	D. Dans notre exemple, on a :
		A     B
		_     _
		5     2
		6     3
		7
		0     
		1
	      
	      Donc maintenant on réitère les schémas B. et C. jusqu'à que la stack B est vide,
	      	et que tout soit dans la stack A presque trié.
	
	E. Enfin, on a :
		A     B
		_     _
		3     
		5     
		6
		7     
		0
		1
		2
	  
	 La dérnière étape consiste à trouver le nombre le plus petit et le mettre au dessus de la stack A,
	 	et que la liste soit bien dans l'odre croissant.
	 	Donc on regarde si son index est supérieur ou inférieur à la moitié du all_number (nombre total d'arguments),
		s'il est supérieur on fait des ra jusqu'à que le maillon soit en haut de la stack A;
		s'il est inférieur on fait des rra jusqu'à que le maillon soit en haut de la stack A.
	Dans notre exemple, c'est 0 le nombre le plus petit vu que sonn index est en dessous de la moitié du all number,
	c'est plus optimisé de faire 3 rra que 5 ra.
	
	F. Finalement, on a :
		A     B
		_     _
		0     
		1     
		2
		3     
		5
		6
		7
	      
	La stack A est enfin triée!! L'algorithme fonctionne et est optimisé
		à partir de plus de 5 arguments (il fonctionne aussi pour 500 arguments).
	
	Je remercie @ttranche et @malaltini pour m'avoir aidée durant ce projet et du temps qui m'ont accordé pour
		m'expliquer cette algorithme!!
