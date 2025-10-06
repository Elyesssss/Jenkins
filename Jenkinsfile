pipeline {
    agent any
    
    stages {
        stage('Checkout') {
            steps {
                echo '=== Récupération du code source ==='
                git branch: 'main',
                    url: 'https://github.com/Elyesssss/Jenkins.git'
            }
        }
        
        stage('Vérification environnement') {
            steps {
                echo '=== Vérification des outils ==='
                bat '''
                    gcc --version
                    mingw32-make --version
                '''
            }
        }
        
        stage('Compilation') {
            steps {
                echo '=== Compilation du programme ==='
                bat '''
                    mingw32-make clean
                    mingw32-make
                '''
            }
        }
        
        stage('Tests') {
            steps {
                echo '=== Exécution des tests unitaires ==='
                bat 'mingw32-make test'
            }
        }
        
        stage('Exécution') {
            steps {
                echo '=== Exécution du programme ==='
                bat 'mingw32-make run'
            }
        }
        
        stage('Archive') {
            steps {
                echo '=== Archivage des artefacts ==='
                archiveArtifacts artifacts: 'build/*',
                                fingerprint: true
            }
        }
    }
    
    post {
        success {
            echo '✅ Pipeline exécuté avec succès !'
        }
        failure {
            echo '❌ Le pipeline a échoué.'
        }
        always {
            bat 'mingw32-make clean || exit 0'
        }
    }
}
