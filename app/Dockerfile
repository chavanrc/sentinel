FROM ubuntu:jammy-20240227 AS builder-base
WORKDIR /usr/src/app

# Install dependencies
RUN apt-get update && apt upgrade -y && apt install -y \
    build-essential cmake libtool autoconf pkg-config python3 python3-pip wget unzip git vim gdb openssl libssl-dev \
    && apt clean \
    && rm -rf /var/lib/apt/lists/*

# Install hiredis
RUN wget -q https://github.com/redis/hiredis/archive/refs/tags/v1.2.0.tar.gz                                  \
    && tar -zxf v1.2.0.tar.gz                                                                                 \
    && rm v1.2.0.tar.gz                                                                                       \
    && cd hiredis-1.2.0                                                                                       \
    && mkdir build                                                                                            \
    && cd build                                                                                               \
    && cmake -DCMAKE_BUILD_TYPE=Release -DENABLE_SSL=ON -DCMAKE_CXX_STANDARD=20 .. > /dev/null                \
    && make -j2 > /dev/null                                                                                   \
    && make install > /dev/null                                                                               \
    && cd ../..                                                                                               \
    && rm -rf hiredis-1.2.0                                                                                   \
    && ldconfig

# Install redis-plus-plus
RUN wget -q https://github.com/sewenew/redis-plus-plus/archive/refs/tags/1.3.12.tar.gz                        \
    && tar -zxf 1.3.12.tar.gz                                                                                 \
    && rm 1.3.12.tar.gz                                                                                       \
    && cd redis-plus-plus-1.3.12                                                                              \
    && mkdir build                                                                                            \
    && cd build                                                                                               \
    && cmake -DCMAKE_BUILD_TYPE=Release -DREDIS_PLUS_PLUS_BUILD_TEST=OFF -DREDIS_PLUS_PLUS_BUILD_STATIC=ON -DREDIS_PLUS_PLUS_USE_TLS=ON -DCMAKE_CXX_STANDARD=20 .. > /dev/null \
    && make -j2 > /dev/null                                                                               \
    && make install > /dev/null                                                                               \
    && cd ../..                                                                                               \
    && rm -rf redis-plus-plus-1.3.12                                                                          \
    && ldconfig

COPY .. .

RUN mkdir -p build \
    && cd build \
    && cmake -DCMAKE_BUILD_TYPE=Debug .. \
    && make -j2

CMD ["./build/app"]
