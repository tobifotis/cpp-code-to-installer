# Start with the official Jenkins image
FROM jenkins/jenkins:lts

# Switch to root so we can install stuff
USER root

# Install GCC, CMake, and Python (for Conan)
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    python3 \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Install Conan
RUN pip3 install conan --break-system-packages

# Set up a Conan profile for this environment
RUN conan profile detect --force

# Switch back to the Jenkins user
USER jenkins