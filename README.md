$ docker compose up --build -d
$ docker compose down -v

$ docker network ls
app$ docker build -t app .
app$ docker run --network sentinel_default app

app$ docker run --network sentinel_default -it app bash
./build/app

$ docker container logs --follow sentinel-sentinel-1-1
$ docker inspect -f '{{.Name}} - {{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' $(docker ps -aq)

https://redis.io/docs/management/sentinel/