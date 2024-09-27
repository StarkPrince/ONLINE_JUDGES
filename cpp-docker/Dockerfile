# Use the official Ubuntu image as the base image
FROM ubuntu:20.04

# Install necessary packages
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    gdb \
    && apt-get clean

# Set the working directory inside the container
WORKDIR /app

# Copy the C++ source code into the container
COPY dijkstra.cpp /app/

# Compile the C++ program
RUN g++ -g -o graph_program dijkstra.cpp

# Command to run the compiled program
CMD ["./graph_program"]
