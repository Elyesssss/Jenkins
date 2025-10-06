pipeline {
    agent any
    
    stages {
        stage('Vérification environnement') {
            steps {
                echo '=== Vérification des outils ==='
                bat 'gcc --version'
            }
        }
        
        stage('Compilation') {
            steps {
                echo '=== Compilation avec Makefile ==='
                bat 'mingw32-make'
            }
        }
        
        stage('Tests') {
            steps {
                echo '=== Exécution des tests ==='
                bat 'mingw32-make test'
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
            bat 'mingw32-make clean || exit 0'
        }
    }
}
