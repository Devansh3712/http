FROM ubuntu:bionic
FROM gcc:latest

ADD . /usr/src
WORKDIR /usr/src

EXPOSE 8080
RUN g++ docs/main.cpp src/*.cpp -o docs
CMD [ "./docs" ]
