$ docker compose up --build -d

$ docker network ls
app$ docker build -t app .
app$ docker run --network sentinel_default app

app$ docker run --network sentinel_default -it app bash
./build/app