# Redis Sentinel Docker Setup

This guide provides commands to manage the Docker environment for a Redis setup with Sentinel for high availability.

## Building and Running the Containers
```bash
# Build and run your containers in detached mode
$ docker compose up --build -d
# Stop and remove containers, networks, volumes, and images
$ docker compose down -v
```

## Debug

### Docker Network and Container Management
```bash
# List all networks
$ docker network ls

# Build the Docker image for the app with the tag 'app'
app$ docker build -t app .

# Run the 'app' container on the 'sentinel_default' network
app$ docker run --network sentinel_default app

# Run the 'app' container on the 'sentinel_default' network in interactive mode
app$ docker run --network sentinel_default -it app bash

# Inside the container, execute the built application
./build/app
```

### Interactive Mode and Logs
```bash
# Follow the log output of the 'sentinel-sentinel-1-1' container
$ docker container logs --follow sentinel-sentinel-1-1

# Inspect containers and retrieve their IP addresses within the network
$ docker inspect -f '{{.Name}} - {{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' $(docker ps -aq)
```

## Additional Resources
https://redis.io/docs/management/sentinel/