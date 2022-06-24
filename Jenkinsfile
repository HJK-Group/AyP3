pipeline {

    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building source code'
                cmakeBuild buildDir: 'cmake-build-debug', buildType: 'Debug', generator: 'Ninja', cleanBuild: true, installation: 'InSearchPath', cmakeArgs: '-DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++',
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
