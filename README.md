# Projet CI/CD - Tri à Bulles avec Jenkins

## Vue d'ensemble

Ce projet implémente deux algorithmes de tri à bulles en C avec une intégration CI/CD Jenkins :
- **Tri d'entiers** avec optimisation
- **Tri de chaînes alphabétiques** avec statistiques

## Structure du Projet

```
Jenkins/
├── src/                      # Code source des algorithmes
│   ├── tri_bulles.c/h        # Tri d'entiers
│   ├── tri_chaines.c/h       # Tri de chaînes
│   ├── main_bulles.c         # Programme principal entiers
│   └── main_chaines.c        # Programme principal chaînes
├── tests/                    # Tests unitaires (11 tests)
│   ├── test_tri_bulles.c
│   └── test_tri_chaines.c
├── build/                    # Dossier de compilation (auto-généré)
├── Makefile.windows          # Makefile pour Windows
├── Dockerfile                # Configuration Docker
└── Jenkinsfile.*.windows     # Pipelines Jenkins
```

---

## Prérequis

Installez les outils suivants sur votre machine Windows :

1. **Git for Windows**
   - Télécharger : https://git-scm.com/download/win
   - Inclut Git Bash

2. **GCC (MinGW)**
   - Télécharger MinGW : https://sourceforge.net/projects/mingw/
   - OU MSYS2 : https://www.msys2.org/
   - Ajouter `C:\MinGW\bin` au PATH Windows
   - Vérifier : `gcc --version`

3. **GNU Make**
   - Inclus avec MinGW ou MSYS2
   - Vérifier : `make --version`

4. **Java JDK 11+** (pour Jenkins - optionnel)
   - Télécharger : https://adoptium.net/
   - Vérifier : `java -version`

5. **Docker Desktop** (pour pipeline OPS - optionnel)
   - Télécharger : https://www.docker.com/products/docker-desktop

---

## Installation

### 1. Cloner le repository

```bash
# Ouvrir Git Bash ou PowerShell
cd C:\Users\VotreNom\Documents
git clone https://github.com/Elyesssss/Jenkins.git
cd Jenkins
```

### 2. Vérifier l'environnement

```bash
# Vérifier GCC
gcc --version

# Vérifier Make
make --version

# Vérifier la structure du projet
ls -la
```

---

## Compilation et Tests

### Compiler les programmes

```bash
# Compiler tous les programmes
make -f Makefile.windows all

# Vérifier les binaires créés
dir build
```

Vous devriez voir :
- `build/tri_bulles.exe`
- `build/tri_chaines.exe`
- `build/test_tri_bulles.exe`
- `build/test_tri_chaines.exe`

### Exécuter les tests

```bash
# Lancer tous les tests (11 tests)
make -f Makefile.windows test

# Tests tri d'entiers uniquement (5 tests)
make -f Makefile.windows test_bulles

# Tests tri de chaînes uniquement (6 tests)
make -f Makefile.windows test_chaines
```

Résultat attendu :
```
=== Tests tri d'entiers ===
Test 1: Tableau vide - OK
Test 2: Tableau un élément - OK
Test 3: Tableau déjà trié - OK
Test 4: Tableau ordre inverse - OK
Test 5: Tableau avec doublons - OK
Tous les tests sont passés (5/5)

=== Tests tri de chaînes ===
Test 1: Tableau vide - OK
Test 2: Tableau un élément - OK
Test 3: Tri ascendant - OK
Test 4: Tri descendant - OK
Test 5: Chaînes identiques - OK
Test 6: Statistiques correctes - OK
Tous les tests sont passés (6/6)
```

### Exécuter les programmes

```bash
# Les deux programmes
make -f Makefile.windows run

# Tri d'entiers seulement
build\tri_bulles.exe

# Tri de chaînes seulement
build\tri_chaines.exe
```

### Nettoyer les fichiers compilés

```bash
make -f Makefile.windows clean
```

---

## Configuration Jenkins (Optionnel)

Si vous souhaitez tester les pipelines Jenkins avec déclenchement automatique, suivez ces étapes.

### 1. Installer Jenkins

1. Télécharger Jenkins LTS : https://www.jenkins.io/download/
2. Exécuter l'installeur `.msi`
3. Ouvrir `http://localhost:8080`
4. Récupérer le mot de passe initial :
   ```
   C:\Program Files\Jenkins\secrets\initialAdminPassword
   ```
5. Choisir "Install suggested plugins"
6. Créer un compte administrateur

### 2. Configurer ngrok (pour déclenchement automatique)

Ngrok permet d'exposer Jenkins sur Internet pour recevoir les webhooks GitHub.

1. Créer un compte gratuit sur https://ngrok.com/
2. Télécharger `ngrok.exe` et l'extraire dans `C:\ngrok\`
3. Récupérer votre authtoken sur https://dashboard.ngrok.com/
4. Configurer le token :
   ```bash
   cd C:\ngrok
   .\ngrok config add-authtoken VOTRE_TOKEN_ICI
   ```
5. Démarrer le tunnel (laisser ce terminal ouvert) :
   ```bash
   ngrok http 8080
   ```
6. Noter l'URL publique affichée : `https://abc123xyz.ngrok-free.app`

### 3. Configurer le webhook GitHub

1. Aller sur votre fork GitHub → **Settings** → **Webhooks** → **Add webhook**
2. Remplir :
   - **Payload URL** : `https://abc123xyz.ngrok-free.app/github-webhook/` (ne pas oublier le `/` final)
   - **Content type** : `application/json`
   - **Events** : Just the push event
3. **Add webhook**
4. Vérifier le tick vert (connexion OK)

### 4. Créer le pipeline DEV

1. Dashboard Jenkins → **New Item**
2. Nom : `tri-bulles-et-chaines-dev`
3. Type : **Pipeline**
4. Configuration :
   - **Build Triggers** : Cocher **GitHub hook trigger for GITScm polling**
   - **Pipeline** → Definition : **Pipeline script from SCM**
   - SCM : **Git**
   - Repository URL : `https://github.com/Elyesssss/Jenkins.git`
   - Branch : `*/main`
   - Script Path : `Jenkinsfile.dev.windows`
5. **Save**

### 5. Créer le pipeline OPS

1. Dashboard Jenkins → **New Item**
2. Nom : `tri-bulles-et-chaines-ops`
3. Type : **Pipeline**
4. Configuration :
   - **Pipeline** → Definition : **Pipeline script from SCM**
   - SCM : **Git**
   - Repository URL : `https://github.com/Elyesssss/Jenkins.git`
   - Branch : `*/main`
   - Script Path : `Jenkinsfile.ops.windows`
5. **Save**

### 6. Tester le workflow automatique

Le pipeline DEV déclenche automatiquement le pipeline OPS en cas de succès.

**Faire un commit pour tester** :
```bash
echo "// Test" >> src/tri_bulles.c
git add .
git commit -m "Test workflow CI/CD"
git push origin main
```

**Résultat attendu** :
1. GitHub envoie un webhook à Jenkins (via ngrok)
2. Le pipeline **DEV** se lance automatiquement
3. Si DEV réussit → Le pipeline **OPS** se lance automatiquement
4. Les deux pipelines s'affichent dans le dashboard Jenkins

### 7. Lancer manuellement (pour démo sans commit)

Si les profs veulent voir le pipeline sans faire de commit :

1. Dashboard Jenkins → Sélectionner `tri-bulles-et-chaines-dev`
2. Cliquer sur **Build Now**
3. Observer l'exécution dans **Console Output**

**Stages du pipeline DEV** :
- Checkout → Vérification → Compilation → Tests (11 tests) → Exécution → Rapport → **Trigger OPS**

**Stages du pipeline OPS** (lance automatiquement après DEV) :
- Checkout → Vérification → Compilation → Tests → Build Docker → Test Docker → Déploiement

**Vérifier l'image Docker créée** :
```bash
docker images | findstr tri-bulles
docker run --rm tri-bulles-et-chaines-app:latest
```

---

## Docker (Optionnel)

### Construire l'image manuellement

```bash
docker build -t tri-bulles-et-chaines-app .
```

### Exécuter l'image

```bash
# Les deux programmes (défaut)
docker run --rm tri-bulles-et-chaines-app:latest

# Tri d'entiers seulement
docker run --rm tri-bulles-et-chaines-app:latest ./build/tri_bulles

# Tri de chaînes seulement
docker run --rm tri-bulles-et-chaines-app:latest ./build/tri_chaines
```

---

## Dépannage

### Erreur : `gcc: command not found`

**Solution** :
1. Vérifier l'installation : `gcc --version`
2. Ajouter MinGW au PATH :
   - Système → Paramètres avancés → Variables d'environnement
   - Ajouter `C:\MinGW\bin` au PATH
3. Redémarrer le terminal

### Erreur : `make: command not found`

**Solution** :
- Make est inclus avec MinGW
- Vérifier le PATH comme ci-dessus

### Erreur de compilation dans Jenkins

**Solution** :
1. Dashboard Jenkins → Manage Jenkins → Global Tool Configuration
2. Section **Git** : Path to Git executable : `C:\Program Files\Git\bin\git.exe`
3. Redémarrer Jenkins après modification du PATH système

### Docker build échoue

**Solution** :
1. Démarrer Docker Desktop
2. Vérifier : `docker ps`
3. Nettoyer l'espace disque : `docker system prune -a -f`

### Tests échouent

**Solution** :
1. Exécuter les tests localement : `make -f Makefile.windows test`
2. Vérifier les logs pour identifier le test en échec
3. Déboguer manuellement :
   ```bash
   gcc -I src tests/test_tri_bulles.c src/tri_bulles.c -o test.exe
   .\test.exe
   ```

---

## Auteurs

- **Elyes Hamani**
- **Daouda Kone**
- **Dylan Franc Ekie**

**Repository** : https://github.com/Elyesssss/Jenkins.git
**Date** : Octobre 2025

---

## Licence

Projet étudiant à but pédagogique.
