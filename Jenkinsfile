pipeline {
    // Run on any available Jenkins agent
    agent any

    stages {
        // Stage 1: Set up Conan profile
        stage('Setup Conan') {
            steps {
                sh 'conan profile detect --force'
            }
        }

        // Stage 2: Fetch zlib using Conan
        stage('Conan Install') {
            steps {
                sh 'conan install . --output-folder=build --build=missing'
            }
        }

        // Stage 3: Configure the build using CMake
        stage('CMake Configure') {
            steps {
                sh 'cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release'
            }
        }

        // Stage 4: Compile everything
        stage('CMake Build') {
            steps {
                sh 'cmake --build build'
            }
        }

        // Stage 5: Run the program and verify it works
        stage('Test') {
            steps {
                sh './build/compression-demo'
            }
        }
    }
}