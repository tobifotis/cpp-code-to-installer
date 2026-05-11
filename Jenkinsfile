pipeline {
    // Run on any available Jenkins agent
    agent any

    stages {
        // Stage 1: Fetch zlib using Conan
        stage('Conan Install') {
            steps {
                sh 'conan install . --output-folder=build --build=missing'
            }
        }

        // Stage 2: Configure the build using CMake
        stage('CMake Configure') {
            steps {
                sh 'cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release'
            }
        }

        // Stage 3: Compile everything
        stage('CMake Build') {
            steps {
                sh 'cmake --build build'
            }
        }

        // Stage 4: Run the program and verify it works
        stage('Test') {
            steps {
                sh './build/compression-demo.exe'
            }
        }
    }
}