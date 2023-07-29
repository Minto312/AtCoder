FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt -y upgrade && \
    apt install -y git && \
    apt install -y build-essential && \
    apt install -y gdb

