pipeline {

    agent any

    stages {
        stage('Build') {
            steps {
                sh 'echo "Building source code"'
                cmakeBuild buildDir: 'cmake-build-debug', buildType: 'Debug', cleanBuild: true, generator: 'Ninja', installation: 'Cmake 3.22', steps: [[withCmake: true]]
                sh 'echo "Build complete"'
            }
        }
    }
}
