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
                sh '''
                    gcc --version
                    make --version
                '''
            }
        }
        
        stage('Compilation') {
            steps {
                echo '=== Compilation du programme ==='
                sh '''
                    make clean
                    make
                '''
            }
        }
        
        stage('Tests') {
            steps {
                echo '=== Exécution des tests unitaires ==='
                sh 'make test'
            }
        }
        
        stage('Exécution') {
            steps {
                echo '=== Exécution du programme ==='
                sh 'make run'
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
            sh 'make clean || true'
        }
    }
}