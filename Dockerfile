FROM ubuntu:latest

RUN apt-get update && apt-get install -y g++ cmake

COPY include ./include
COPY src ./src
COPY test ./test
COPY CMakeLists.txt .

RUN cmake -B bin .
RUN cmake --build bin --config Release

EXPOSE 8080

CMD ["./bin/gradient_descent"]
