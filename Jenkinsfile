pipeline {
    agent any
    
    stages {
        stage('Checkout') {
            steps {
                echo '=== Récupération du code source ==='
                git branch: 'windows-pipeline',
                    url: 'https://github.com/Elyesssss/Jenkins.git'
            }
        }
        
        stage('Vérification environnement') {
            steps {
                echo '=== Vérification des outils ==='
                bat 'gcc --version'
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
                bat 'gcc -o build/tri_bulles.exe main.c'
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
