pipeline {

    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building source code'
                cmakeBuild buildDir: 'cmake-build-debug', buildType: 'Debug', cleanBuild: true, installation: 'InSearchPath'
                echo 'Build complete'
            }
        }
        stage('Test') {
            steps {
                echo 'Running Tests'
            }
        }
    }
}
