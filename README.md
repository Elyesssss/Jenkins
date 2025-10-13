#  Projet Tri à Bulles - C avec CI/CD Jenkins

##  Structure du Projet

```
.
├── src/
│   ├── tri_bulles.c          
│   ├── tri_bulles.h
│   ├── main.c
│   ├── tri_chaines.c         
│   ├── tri_chaines.h
│   └── main_chaines.c
├── tests/
│   ├── test_tri_bulles.c
│   └── test_tri_chaines.c   
├── Makefile
├── Dockerfile
├── Jenkinsfile.dev           # 🔵 Pipeline DEV
└── Jenkinsfile.ops           # 🟢 Pipeline OPS
```

##  Fonctionnalités

### 1️ Tri d'entiers (existant)
- Tri à bulles classique pour les entiers
- Optimisation avec détection de tableau trié

### 2️ Tri de chaînes alphanumériques ✨ NOUVEAU
- **Fonction swap** : `swap_chaines(char*, char*)`
- **Ordre ascendant** et **descendant**
- **Compteurs** : nombre de comparaisons et d'échanges
- **Statistiques** affichées après chaque tri

#### Exemple d'utilisation :
```c
char mots[6][MAX_LONGUEUR] = {
    "bonjour", "hello", "world", 
    "apple", "banana", "cherry"
};

StatsTri stats;
tri_bulles_chaines(mots, 6, 1, &stats);  // 1 = ascendant, 0 = descendant
afficher_statistiques(stats);
```

**Sortie attendue (ascendant)** :
```
[ "apple", "banana", "bonjour", "cherry", "hello", "world" ]

=== Statistiques du tri ===
Nombre de comparaisons : 15
Nombre d'échanges      : 8
===========================
```

##  Compilation et Exécution

### Compilation locale

```bash
# Compiler tous les programmes
make all

# Compiler uniquement le tri d'entiers
make tri_bulles

# Compiler uniquement le tri de chaînes
make tri_chaines

# Nettoyer
make clean
```

### Tests

```bash
# Exécuter tous les tests
make test

# Tests tri d'entiers uniquement
make test_bulles

# Tests tri de chaînes uniquement
make test_chaines
```

### Exécution

```bash
# Exécuter le tri d'entiers
make run

# Exécuter le tri de chaînes
make run_chaines

# Exécuter les deux programmes
make run_all
```

## 🐳 Docker

### Build et exécution

```bash
# Construire l'image
docker build -t tri-bulles-app .

# Exécuter le tri d'entiers (défaut)
docker run --rm tri-bulles-app

# Exécuter le tri de chaînes
docker run --rm tri-bulles-app ./build/tri_chaines

# Exécuter les deux programmes
docker run --rm tri-bulles-app ./run_all.sh
```

##  Pipelines Jenkins

### 🔵 Pipeline DEV (`Jenkinsfile.dev`)

**Objectif** : Développement et validation jusqu'aux tests

**Stages** :
1. ✅ **Checkout** - Récupération du code
2. ✅ **Vérification environnement** - GCC, Make
3. ✅ **Compilation** - Build des programmes
4. ✅ **Tests unitaires** - Exécution de tous les tests
5. ✅ **Rapport de tests** - Archivage des artefacts

**Utilisation dans Jenkins** :
```groovy
// Dans Jenkins, créer un nouveau pipeline
// Source: SCM → Git
// Script Path: Jenkinsfile.dev
```

**Artefacts générés** :
- `rapport_dev.txt`
- Binaires dans `build/`

---

### 🟢 Pipeline OPS (`Jenkinsfile.ops`)

**Objectif** : Déploiement complet avec Docker

**Stages** :
1. ✅ **Checkout** - Récupération du code
2. ✅ **Vérification environnement** - GCC, Make, Docker
3. ✅ **Compilation** - Build des programmes
4. ✅ **Tests unitaires** - Validation complète
5. 🐳 **Build Docker Image** - Construction de l'image
6. 🐳 **Test Docker Image** - Validation de l'image
7. 🚀 **DEPLOY** - Déploiement
8. ✅ **Rapport de déploiement** - Documentation

**Utilisation dans Jenkins** :
```groovy
// Dans Jenkins, créer un nouveau pipeline
// Source: SCM → Git
// Script Path: Jenkinsfile.ops
```

**Artefacts générés** :
- `rapport_ops.txt`
- Image Docker : `tri-bulles-app:${BUILD_NUMBER}`
- Image Docker : `tri-bulles-app:latest`

**Commandes de déploiement** :
```bash
# Tag pour registry
docker tag tri-bulles-app:latest localhost:5000/tri-bulles-app:latest

# Push vers registry (décommenter dans le Jenkinsfile)
docker push localhost:5000/tri-bulles-app:latest
```

##  Différences entre les Pipelines

| Aspect | Pipeline DEV 🔵 | Pipeline OPS 🟢 |
|--------|----------------|----------------|
| **Objectif** | Validation code | Déploiement complet |
| **Stages** | Jusqu'aux tests | Jusqu'au déploiement |
| **Docker** | ❌ Non | ✅ Oui |
| **Deploy** | ❌ Non | ✅ Oui |
| **Durée** | ~2-3 min | ~5-7 min |
| **Utilisation** | Développement | Production |

##  Statistiques de Tri

### Exemple de sortie des statistiques

```
=== Programme de tri de chaînes ===

Tableau original : [ "bonjour", "hello", "world", "apple", "banana", "cherry" ]

--- Tri par ordre alphabétique ASCENDANT ---
Tableau trié (ascendant) : [ "apple", "banana", "bonjour", "cherry", "hello", "world" ]

=== Statistiques du tri ===
Nombre de comparaisons : 15
Nombre d'échanges      : 8
===========================

--- Tri par ordre alphabétique DESCENDANT ---
Tableau trié (descendant) : [ "world", "hello", "cherry", "bonjour", "banana", "apple" ]

=== Statistiques du tri ===
Nombre de comparaisons : 15
Nombre d'échanges      : 13
===========================
```

## 🔧 Configuration Jenkins

### Prérequis sur Jenkins

```bash
# Installer les plugins nécessaires
- Git plugin
- Pipeline plugin
- Docker Pipeline plugin (pour OPS)

# S'assurer que Jenkins a accès à :
- gcc
- make
- docker (pour pipeline OPS)
```

### Créer les jobs Jenkins

```bash
# Job 1: DEV
Nom: tri-bulles-dev
Type: Pipeline
Script Path: Jenkinsfile.dev

# Job 2: OPS
Nom: tri-bulles-ops
Type: Pipeline
Script Path: Jenkinsfile.ops
```

##  Points Clés du Projet

✅ **Fonction swap** pour les chaînes de caractères  
✅ **Compteurs** de comparaisons et d'échanges  
✅ **Tri ascendant et descendant**  
✅ **Tests unitaires complets**  
✅ **2 Pipelines Jenkins distincts** (DEV et OPS)  
✅ **Intégration Docker** dans le pipeline OPS  
✅ **Rapports automatisés**  

##  Support

Pour toute question sur :
- Les algorithmes de tri → Voir `src/tri_*.c`
- Les tests → Voir `tests/test_*.c`
- Les pipelines → Voir `Jenkinsfile.dev` et `Jenkinsfile.ops`
- Docker → Voir `Dockerfile`

---

**Auteur** : Votre nom  
**Projet** : CI/CD avec Jenkins - Tri à Bulles  
**Date** : Octobre 2025
