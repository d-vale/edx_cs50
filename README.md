# CS50x - Harvard Computer Science Course

[![CS50x](https://img.shields.io/badge/CS50x-Harvard-crimson)](https://cs50.harvard.edu/x/2025/)
[![edX](https://img.shields.io/badge/Platform-edX-blue)](https://learning.edx.org/course/course-v1:HarvardX+CS50+X/home)
[![Progress](https://img.shields.io/badge/Progress-75%25-green)](#progression)

## 📖 À propos

Ce repository documente mon parcours d'apprentissage du cours **CS50x** de Harvard, une introduction complète à l'informatique suivie par plus d'un million d'étudiants dans le monde. Ce cours gratuit via edX couvre les fondamentaux de la programmation, des algorithmes et du développement web.

### 🎯 Mes objectifs

- Maîtriser les bases du langage **C** et de la gestion mémoire
- Apprendre **Python** et ses applications pratiques
- Comprendre les structures de données et algorithmes fondamentaux
- Renforcer mes compétences en bases de données avec **SQL** et des technologies web (HTML, CSS, JavaScript, Flask)
- Préparer mon Master en Computer Science

## 📚 Programme du cours

### **Week 0 - Scratch** 🧩

Introduction à la pensée computationnelle avec Scratch, blocs visuels, concepts de base de la programmation.

### **Week 1 - Langage C** ⚙️

Syntaxe C, compilation, types de données, fonctions, bibliothèques standards, debugging avec `printf`.

### **Week 2 - Tableaux** 📊

Arrays, chaînes de caractères, manipulation de caractères, arguments en ligne de commande, cryptographie basique.

### **Week 3 - Algorithmes** 🔍

Algorithmes de tri (bubble, selection, merge), recherche (linéaire, binaire), analyse de complexité (Big O), récursivité.

### **Week 4 - Mémoire** 🧠

Pointeurs, allocation dynamique, gestion heap/stack, manipulation de fichiers, formats d'images (BMP, JPEG).

### **Week 5 - Structures de données** 🌳

Listes chaînées, arbres binaires, tables de hachage, piles, files, optimisation des accès mémoire.

### **Week 6 - Python** 🐍

Transition vers Python, syntaxe haut niveau, bibliothèques, programmation orientée objet, parsing de données.

### **Week 7 - SQL** 🗄️

Bases de données relationnelles, requêtes SQL, joins, indexation, conception de schémas, SQLite.

### **Week 8 - Web Frontend** 🎨

HTML5, CSS3, JavaScript, DOM manipulation, responsive design, frameworks CSS, interfaces utilisateur.

### **Week 9 - Web Backend** 🚀

Flask, sessions, cookies, APIs REST, sécurité web, authentification, déploiement d'applications.

### **Week 10 - Projet final** 🏆

Développement d'un projet personnel intégrant les compétences acquises, présentation et documentation.

## 📈 Progression

### ✅ Semaines terminées

| Semaine    | Sujet                 | Exercices réalisés                                                                                                                                 | Statut     |
| ---------- | --------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| **Week 0** | Scratch               | Projet Scratch (non inclus dans le repo)                                                                                                           | ✅ Terminé |
| **Week 1** | Langage C             | [`hello.c`](week1/hello.c), [`mario.c`](week1/mario.c), [`credit.c`](week1/credit.c)                                                               | ✅ Terminé |
| **Week 2** | Arrays                | [`scrabble.c`](week2/scrabble.c), [`readability.c`](week2/readability.c), [`substitution.c`](week2/substitution.c)                                 | ✅ Terminé |
| **Week 3** | Algorithmes           | [`sort/answers.txt`](week3/sort/answers.txt), [`plurality.c`](week3/plurality.c), [`runoff.c`](week3/runoff.c)                                     | ✅ Terminé |
| **Week 4** | Mémoire               | [`filter-less/helpers.c`](week4/filter-less/helpers.c), [`recover/recover.c`](week4/recover/recover.c), [`volume/volume.c`](week4/volume/volume.c) | ✅ Terminé |
| **Week 5** | Structures de données | [`inheritance/inheritance.c`](week5/inheritance/inheritance.c), [`speller/dictionary.c`](week5/speller/dictionary.c)                               | ✅ Terminé |
| **Week 6** | Python                | [`sentimental-hello/hello.py`](week6/sentimental-hello/hello.py), [`sentimental-mario-more/mario.py`](week6/sentimental-mario-more/mario.py), [`sentimental-credit/credit.py`](week6/sentimental-credit/credit.py), [`sentimental-readability/readability.py`](week6/sentimental-readability/readability.py), [`dna/dna.py`](week6/dna/dna.py) | ✅ Terminé |

### 🔄 En cours / À venir

| Semaine       | Sujet              | Prévision |
| ------------- | ------------------ | --------- |
| **Week 7**    | SQL                | À venir   |
| **Week 8-10** | Web & Projet final | À venir   |

## 🛠️ Détail des exercices

### Week 0 - Scratch

**📝 Problem Set :** [https://cs50.harvard.edu/x/2025/psets/0/](https://cs50.harvard.edu/x/2025/psets/0/)

| Exercice            | Description                                                  | Fichier                   | Difficulté |
| ------------------- | ------------------------------------------------------------ | ------------------------- | ---------- |
| **Scratch Project** | Création d'un projet interactif avec Scratch (blocs visuels) | _Non inclus dans le repo_ | ⭐         |

### Week 1 - Langage C

**📝 Problem Set :** [https://cs50.harvard.edu/x/2025/psets/1/](https://cs50.harvard.edu/x/2025/psets/1/)

| Exercice   | Description                                                 | Fichier                      | Difficulté |
| ---------- | ----------------------------------------------------------- | ---------------------------- | ---------- |
| **Hello**  | Programme interactif de salutation personnalisée            | [`hello.c`](week1/hello.c)   | ⭐         |
| **Mario**  | Génération de pyramides adjacentes avec validation d'entrée | [`mario.c`](week1/mario.c)   | ⭐⭐       |
| **Credit** | Validation de cartes de crédit avec algorithme de Luhn      | [`credit.c`](week1/credit.c) | ⭐⭐⭐     |

### Week 2 - Arrays

**📝 Problem Set :** [https://cs50.harvard.edu/x/2025/psets/2/](https://cs50.harvard.edu/x/2025/psets/2/)

| Exercice         | Description                                                      | Fichier                                  | Difficulté |
| ---------------- | ---------------------------------------------------------------- | ---------------------------------------- | ---------- |
| **Scrabble**     | Calcul des points d'un mot selon les règles du Scrabble          | [`scrabble.c`](week2/scrabble.c)         | ⭐         |
| **Readability**  | Calcul du niveau de lecture d'un texte avec l'index Coleman-Liau | [`readability.c`](week2/readability.c)   | ⭐⭐       |
| **Substitution** | Chiffrement par substitution avec validation complète de clé     | [`substitution.c`](week2/substitution.c) | ⭐⭐⭐     |

### Week 3 - Algorithmes

**📝 Problem Set :** [https://cs50.harvard.edu/x/2025/psets/3/](https://cs50.harvard.edu/x/2025/psets/3/)

| Exercice      | Description                                                           | Fichier                                      | Difficulté |
| ------------- | --------------------------------------------------------------------- | -------------------------------------------- | ---------- |
| **Sort**      | Analyse et identification d'algorithmes de tri par leurs performances | [`sort/answers.txt`](week3/sort/answers.txt) | ⭐         |
| **Plurality** | Système de vote majoritaire simple avec structures de données         | [`plurality.c`](week3/plurality.c)           | ⭐⭐       |
| **Runoff**    | Système de vote à tours multiples avec élimination progressive        | [`runoff.c`](week3/runoff.c)                 | ⭐⭐⭐     |

### Week 4 - Mémoire

**📝 Problem Set :** [https://cs50.harvard.edu/x/2025/psets/4/](https://cs50.harvard.edu/x/2025/psets/4/)

| Exercice        | Description                                                             | Fichier                                                | Difficulté |
| --------------- | ----------------------------------------------------------------------- | ------------------------------------------------------ | ---------- |
| **Volume**      | Modification du volume d'un fichier audio WAV avec manipulation binaire | [`volume/volume.c`](week4/volume/volume.c)             | ⭐⭐⭐     |
| **Filter-less** | Application de filtres d'images (grayscale, sepia, reflect, blur)       | [`filter-less/helpers.c`](week4/filter-less/helpers.c) | ⭐⭐⭐     |
| **Recover**     | Récupération de fichiers JPEG supprimés depuis une carte mémoire        | [`recover/recover.c`](week4/recover/recover.c)         | ⭐⭐⭐     |

### Week 5 - Structures de données

**📝 Problem Set :** [https://cs50.harvard.edu/x/2025/psets/5/](https://cs50.harvard.edu/x/2025/psets/5/)

| Exercice        | Description                                                                    | Fichier                                                        | Difficulté |
| --------------- | ------------------------------------------------------------------------------ | -------------------------------------------------------------- | ---------- |
| **Inheritance** | Simulation de l'hérédité génétique avec arbres familiaux et allocation mémoire | [`inheritance/inheritance.c`](week5/inheritance/inheritance.c) | ⭐⭐⭐     |
| **Speller**     | Correcteur orthographique avec table de hachage optimisée                      | [`speller/dictionary.c`](week5/speller/dictionary.c)           | ⭐⭐⭐     |

### Week 6 - Python

**📝 Problem Set :** [https://cs50.harvard.edu/x/2025/psets/6/](https://cs50.harvard.edu/x/2025/psets/6/)

| Exercice              | Description                                                              | Fichier                                                                     | Difficulté |
| --------------------- | ------------------------------------------------------------------------ | --------------------------------------------------------------------------- | ---------- |
| **Hello (Python)**   | Version Python du programme de salutation avec syntaxe simplifiée        | [`sentimental-hello/hello.py`](week6/sentimental-hello/hello.py)           | ⭐         |
| **Mario (Python)**   | Pyramides adjacentes en Python avec validation d'entrée et fonctions     | [`sentimental-mario-more/mario.py`](week6/sentimental-mario-more/mario.py) | ⭐⭐       |
| **Credit (Python)**  | Validation de cartes de crédit en Python avec algorithme de Luhn          | [`sentimental-credit/credit.py`](week6/sentimental-credit/credit.py)       | ⭐⭐       |
| **Readability**      | Index de lisibilité Coleman-Liau en Python avec manipulation de chaînes   | [`sentimental-readability/readability.py`](week6/sentimental-readability/readability.py) | ⭐⭐       |
| **DNA**              | Profilage génétique avec séquences STR et analyse de fichiers CSV         | [`dna/dna.py`](week6/dna/dna.py)                                           | ⭐⭐⭐     |

## 🔗 Ressources

- [**Cours CS50x 2025**](https://cs50.harvard.edu/x/2025/) - Site officiel
- [**edX Platform**](https://learning.edx.org/course/course-v1:HarvardX+CS50+X/home) - Plateforme d'apprentissage
- [**CS50 IDE**](https://ide.cs50.io/) - Environnement de développement
- [**Documentation CS50**](https://cs50.readthedocs.io/) - Référence technique

## 💡 Compétences développées

### Programmation fondamentale

- **Programmation en C** : Syntaxe, pointeurs, gestion mémoire
- **Programmation en Python** : Syntaxe haut niveau, gestion des types dynamiques, fonctions
- **Manipulation d'arrays** : Chaînes de caractères, arguments de ligne de commande
- **Structures de données** : `struct`, tableaux multidimensionnels, listes chaînées, tables de hachage
- **Cryptographie basique** : Chiffrement par substitution

### Algorithmes et complexité

- **Algorithmes de tri** : Bubble sort, selection sort, merge sort
- **Analyse de complexité** : Notation Big O, temps d'exécution
- **Optimisation** : Détection de tri précoce, efficacité algorithmique, fonctions de hachage
- **Systèmes de vote** : Logique électorale, algorithmes de décision

### Gestion de la mémoire et manipulation de fichiers

- **Pointeurs et mémoire** : Allocation dynamique, heap/stack, structures récursives
- **Manipulation de fichiers** : Lecture/écriture CSV, parsing de données
- **Traitement d'images** : Formats BMP, manipulation de pixels, filtres graphiques
- **Forensique numérique** : Récupération de données, analyse de signatures de fichiers

### Structures de données avancées

- **Listes chaînées** : Insertion, suppression, traversée de listes dynamiques
- **Tables de hachage** : Fonctions de hachage, gestion des collisions, optimisation des performances
- **Arbres de données** : Structures hiérarchiques, récursivité, héritage génétique
- **Gestion mémoire avancée** : Libération récursive, prévention des fuites mémoire

### Développement logiciel et Python

- **Transition C vers Python** : Migration de code, adaptation des algorithmes
- **Validation d'entrées** : Vérification robuste des données utilisateur en Python
- **Modularité Python** : Fonctions spécialisées, importation de modules
- **Parsing de données** : Analyse de fichiers CSV, manipulation de chaînes avancée
- **Profilage génétique** : Algorithmes de correspondance, analyse STR
- **Debugging Python** : Gestion d'erreurs, optimisation de performance

---

_Dernière mise à jour : Septembre 2025_