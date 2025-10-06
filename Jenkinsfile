pipeline {
    agent any
    
    stages {
        stage('Vérification environnement') {
            steps {
                echo '=== Vérification des outils ==='
                bat 'gcc --version'
            }
        }
        
        stage('Liste des fichiers') {
            steps {
                echo '=== Vérification des fichiers présents ==='
                bat '''
                    dir
                    echo.
                    echo === Contenu du dossier src ===
                    dir src
                '''
            }
        }
        
        stage('Nettoyage') {
            steps {
                echo '=== Nettoyage des anciens builds ==='
                bat '''
                    if exist build rmdir /s /q build
                    mkdir build
                '''
            }
        }
        
        stage('Compilation') {
            steps {
                echo '=== Compilation du programme ==='
                bat 'gcc -o build/tri_bulles.exe src/main.c'
            }
        }
        
        stage('Tests') {
            steps {
                echo '=== Exécution des tests ==='
                bat 'build\\tri_bulles.exe'
            }
        }
        
        stage('Archive') {
            steps {
                echo '=== Archivage des artefacts ==='
                archiveArtifacts artifacts: 'build/*.exe',
                                fingerprint: true,
                                allowEmptyArchive: false
            }
        }
    }
    
    post {
        success {
            echo '✅ Pipeline Windows exécuté avec succès !'
        }
        failure {
            echo '❌ Le pipeline a échoué.'
        }
        always {
            echo '=== Nettoyage final ==='
            bat 'if exist build rmdir /s /q build || exit 0'
        }
    }
}
